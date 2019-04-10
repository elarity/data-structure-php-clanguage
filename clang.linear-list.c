#include <stdio.h>
#define TRUE  1
#define FALSE 0
#define ERROR -1
#define SQ_SIZE 6

typedef struct seq_list {
  int element_array[ SQ_SIZE ];
  int length;
} seq_list;

int  create_element( int, int, seq_list * );
int  update_element( int, int, seq_list * );
int  read_element( int, seq_list * );
int  delete_element( int, seq_list * );
int  get_sq_length( seq_list * );
void range_sq( seq_list * );

int main( void ) {
  // 声明一个线性表
  seq_list sq; 
  sq.length = 0;
  create_element( 1, 1, &sq );
  create_element( 2, 2, &sq );
  create_element( 3, 3, &sq );
  create_element( 4, 4, &sq );
  create_element( 5, 5, &sq );
  create_element( 6, 6, &sq );
  range_sq( &sq );
  int sq_length = get_sq_length( &sq );
  printf( "sq length : %d\n", sq_length );
  // 寻找一个节点
  int element = read_element( 3, &sq );
  printf( "ele in 3 : %d\n", element );
  // 更新一个节点
  update_element( 3, 33, &sq );
  range_sq( &sq );
  // 删除一个节点
  delete_element( 3, &sq );
  range_sq( &sq );
  // 删除一个节点
  delete_element( 3, &sq );
  range_sq( &sq );
  // 添加一个元素
  create_element( 1, 11, &sq );
  range_sq( &sq );
  return 0;
}

void range_sq( seq_list * sq ) {
  int array_right = sq->length - 1; 
  for ( int index = 0; index <= array_right; index++ ) {
    printf( "%d,", sq->element_array[ index ] );
  }
  printf( "\n" );
}

/*
 @desc : 删除元素
 */
int delete_element( int index, seq_list * sq ) {
  if ( index < 1 || index > SQ_SIZE ) {
    return ERROR;
  }
  if ( 0 == sq->length ) {
    return ERROR;
  }
  int array_index = index - 1; 
  // 线性表的右侧边界
  int array_right = sq->length - 1;
  // 如果删除的是最后一个元素，那就省点儿力气 
  if ( array_index == ( sq->length - 1 ) ) {
    sq->length--; 
    return TRUE;
  } else {
    // 如果删除的元素不是最后一个，恶心开始到家了 
    // 从当前位置开始一直到最后一个元素，统统往前挪一位
    for ( ; array_index < array_right; array_index++ ) {
      int temp = sq->element_array[ array_index + 1 ]; 
      sq->element_array[ array_index ] = temp; 
    } 
    sq->length--;
    return TRUE;
  }
}

int update_element( int index, int element, seq_list * sq ) {
  if ( index < 1 || index > sq->length ) {
    return ERROR;
  }
  int array_index = index - 1;
  sq->element_array[ array_index ] = element;
  return TRUE;
}

/*
 @desc : index依然为自然位置长度 
         element就是你要打算搞个啥值进去
         sq为线性表元素指针类型变量
 */
int create_element( int index, int element, seq_list * sq ) {
  if ( index > SQ_SIZE || index < 0 ) {
    return ERROR;
  }  
  // 如果线性表已经满了,错误 
  if ( SQ_SIZE == sq->length ) {
    return ERROR;
  }
  int array_index = index - 1;
  if ( 0 == sq->length ) {
    sq->element_array[ array_index ] = element;
    sq->length++;
  } else {
    // 线性表当前最右侧元素位置
    int array_right = sq->length - 1; 
    // 最恶心来了！
    for ( ; array_right >= array_index; array_right-- ) {
      int temp = sq->element_array[ array_right ];
      sq->element_array[ array_right + 1 ] = temp;
    }
    // 知道这里如何把 添加元素和长度加一 做成原子性操作吗？
    sq->element_array[ array_index ] = element;
    sq->length++;
  }
  return TRUE;
}

/*
 @desc : index为自然位置，
         不指数组中从0开始的那种反人类位置
         1就是第一位,不接受杠精反驳
         谁杠打死谁
 */
int read_element( int index, seq_list * sq ) {
  // 位置不能超过线性表的长度,也不能小于1
  if ( index > SQ_SIZE || index < 1 ) {
    return ERROR;
  }
  // 转换为数组位置
  int ret;
  int array_index;
  array_index = index - 1; 
  // sq为线性表的指针类型变量，所以用->
  ret = sq->element_array[ array_index ]; 
  return ret;
}

int get_sq_length( seq_list * sq ) {
  return sq->length;  
}
