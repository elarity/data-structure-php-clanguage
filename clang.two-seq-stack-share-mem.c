#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/*
 * @desc : 两stack共享空间的demo
           就是两个stack的顶对着顶，当栈1满了后，可以向栈2中存数据
   我在注释里画个图简单表示一下

-1   0 1 2 3 4     5 6 7 8 9   10
     -----------  -----------
栈1  | | | | | |  | | | | | |  栈2
     -----------  -----------
     栈1的栈顶方向是从左往右的，栈2的栈顶方向是从右往左的
     我们暂且给这种栈起个名字叫做“双栈”,往双栈里push元素的时候，是从栈
     两侧向中间方向前进的。也就是说往栈1里push，就是从左右往右；往栈2
     里push，就是从右往左
     双栈什么时候满栈呢？就是 栈1的栈顶位置和栈2的栈顶位置差1的时候
 */
typedef struct double_stack {
  int element[ SIZE ];
  // 栈1的栈顶位置
  int pre_stack_top;
  // 栈2的栈顶位置
  int suf_stack_top;
} double_stack;
// 再说最后一遍：double_stack * = double_stack_p
typedef double_stack * double_stack_p;

// 依然还是要实现两个功能，push和pop
// 不过，由于是两个栈的栈顶对栈顶，所以，参数需要表明是操作那个栈
void push( double_stack_p, int, int );
int  pop( double_stack_p, int );

int main( int argc, char * argv[] ) {
  // 初始化一个双栈
  double_stack_p s = ( double_stack_p )malloc( sizeof( double_stack ) ); 
  // -1表示栈1是空栈
  s->pre_stack_top = -1;
  // 10表示栈2是空栈
  s->suf_stack_top = 10;
  // push内容
  push( s, 1, 1 );
  push( s, 2, 1 );
  push( s, 10, 2 );
  printf( "栈1顶部：%d，栈2顶部：%d\n", s->pre_stack_top, s->suf_stack_top );
  push( s, 3, 1 );
  printf( "栈1顶部：%d，栈2顶部：%d\n", s->pre_stack_top, s->suf_stack_top );
  push( s, 9, 2 );
  printf( "栈1顶部：%d，栈2顶部：%d\n", s->pre_stack_top, s->suf_stack_top );
  // pop
  int temp = pop( s, 1 );
  printf( "pop : %d\n", temp );
  temp = pop( s, 2 );
  printf( "pop : %d\n", temp );
  printf( "栈1顶部：%d，栈2顶部：%d\n", s->pre_stack_top, s->suf_stack_top );
  return 0;
}

/*
 * @param : s 双栈结构体指针
 * @param : element 要push的元素
 * @param : stack_flag 栈的标记 1表示栈1，2表示栈2
 */
void push( double_stack_p s, int element, int stack_flag ) {
  // 先判断是否栈满了
  if ( s->suf_stack_top - s->pre_stack_top == 1 ) {
    printf( "栈满了\n" );
    exit( -1 );
  } 
  // 栈1
  if ( 1 == stack_flag ) {
    s->element[ ++s->pre_stack_top ] = element;   
  } 
  // 栈2
  else if ( 2 == stack_flag ) {
    s->element[ --s->suf_stack_top ] = element;   
  }
  else {
    printf( "错误栈号\n" ); 
    exit( -1 );
  }
}

/*
 * @param : s 双栈结构体指针
 */
int pop( double_stack_p s, int stack_flag ) {
  int temp;
  if ( 1 == stack_flag ) {
    if ( -1 == s->pre_stack_top ) {
      printf( "栈1是空的\n" );
      exit( -1 );
    }
    temp = s->element[ s->pre_stack_top ];
    s->element[ s->pre_stack_top ] = 0;
    s->pre_stack_top--;  
  } 
  else if ( 2 == stack_flag ) {
    if ( 10 == s->suf_stack_top ) {
      printf( "栈2是空的\n" );
      exit( -1 );
    }
    temp = s->element[ s->suf_stack_top ]; 
    s->element[ s->suf_stack_top ] = 0;
    s->suf_stack_top++;
  }
  return temp;
}
