#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/*
 * @desc : 顺序结构存储的队列。队列就是那种队头出，队尾进的玩意，跟地铁安检一样：
   先来先检往前走，后来后排往前走.
   大概如下图：
   -----------
<- |0|1|2|3|4|  <-
   -----------
   下面我们说的这个队列是顺序存储方式实现队列中比较合理的一种队列：循环队列...意思大概就是如果你的队列是
   基于顺序存储实现的，那么搞成循环队列是可以满足你绝大多数场景的，别的都是辣鸡
   1,队尾（yi）巴上来一个很容易操作，直接尾巴上怼个元素就行 
   2,头上出一个就比较恶心了，比如0出去后，后面1 2 3 4都要分别往前挪一位，你要用for循环操作么？多恶心...
   3,所以为了避免2中沙雕移动操作，索性就懒惰一点儿吧，0出去就出去了，后面一个元素都不用动
   4,但是真的如果如3所做了。。。也比较恶心，比如极端的情况，0 1 2 3都滚蛋出去了，5也不动，再来新的，就可能要GG
   5,当然了，我可是看到了昂，前面4个位置都是空的，但是新来的就是没地儿放，这就是传说中的“假溢出”...
   6,那按理说，想办法把新来的往前面的空坑里怼就行了吧。。。
   7,所以，不知道哪个大佬又想了一个办法，就是弄俩指针，一个指头，一个指尾
   
   -----------
   | | |2|3|4| 
   -----------
    |   |
    t   h
     
   假设头指针叫head，尾指针叫做tail。当队列如上图所示时候，head指向2，tail指向第一个空坑（也就是原来0的位置）
   如果此时新来一个5，就把5往0的位置怼,tail位置往后挪到原来1的位置；
   -----------
   |5| |2|3|4| 
   -----------
      | |
      t h
   如果出队列，就是从head指向的2中出。
   然后妈蛋又来一个6，此时tail指向原来1的位置，head依然指向2，6来后占了原来1的位置，tail指针指向2，此时head和tail指向同一个位置！
   -----------
   |5|6|2|3|4| 
   -----------
       ||
       th
   这会儿最大的问题就是：如果开始队列开始出数据，一直出一直爽一直出完都没有进来的，head最终也将落到2的位置，head和tail
   的位置又是相同的。
   -----------
   | | | | | | 
   -----------
       ||
       th
   ” 队列满着的时候，head=tail；队列空的时候，head=tail “
   ？？？？？？
   到底是空着的还是满着的？  
   这个其实上是有很多解决方案的，不要把思维限制死了：
   1·比如你额外搞个变量去记录当前队列有几个元素,通过占据一个空间来解决这个问题
   2·还有一个办法是让tail指针指向的尾巴始终为空，就是说虽然数组SIZE=5，但是当存了4个元素时，计算满了，这样head和tail
     绝对不会重合,位置绝对值为1;而队列空的时候呢，就让head=tail，你们自己琢磨琢磨；这个是可以实现的。
   假如我们就用第二个办法.
   1,队列为空时，tail=head
   2,队列满着的时候：( tail + 1 )%5 = head ，(5是队列长度)别问我为什么，你自己算下然后背过，人类就是在复读和背诵中进化的
   3,队列长度: （ tail - head + 5 )%5 ，别问我为什么。。。爱背不背,要不然你就用方法1去实现
 */

typedef struct seq_queue {
  int element[ SIZE ];
  int head; 
  int tail;
} seq_queue;
typedef seq_queue * seq_queue_q;

// 添加元素
void add_to_q( seq_queue_q, int );
// 删除元素
int  del_from_q( seq_queue_q );
// 获取队列长度
int  get_length( seq_queue_q );

int main( int argc, char * argv[] ) {
  int length;
  // 初始化一个空队列吧 
  // 根据此前定义，当head=tail时，就是空队列
  seq_queue_q q = ( seq_queue_q )malloc( sizeof( seq_queue ) );
  q->head = 0;
  q->tail = 0;

  // 获取长度
  length = get_length( q );
  printf( "length : %d\n", length );

  // 入列
  add_to_q( q, 1 );
  add_to_q( q, 2 );
  add_to_q( q, 3 );

  // 获取长度
  length = get_length( q );
  printf( "length : %d\n", length );
    
  // 出列
  int temp = del_from_q( q );
  printf( "del : %d\n", temp );
  length = get_length( q );
  printf( "length : %d\n", length );

  return 0;
}

void add_to_q( seq_queue_q q, int element ) {
  // 先判断队列是不是满了
  if ( q->head == ( q->tail + 1 ) % SIZE ) {
    printf( "队列满着呢\n" );
    exit( -1 );
  }
  q->element[ q->tail ] = element; 
  q->tail = ( q->tail + 1 ) % SIZE;
}

int del_from_q( seq_queue_q q ) {
  // 判断队列是不是空的
  if ( q->head == q->tail ) {
    printf( "队列空着呢\n" );
    exit( -1 );
  }
  int temp = q->element[ q->head ];
  q->head = ( q->head + 1 ) % SIZE;
  return temp;
}

int get_length( seq_queue_q q ) {
  printf( "%d %d\n", q->tail, q->head);
  return ( q->tail - q->head + SIZE ) % SIZE; 
}
