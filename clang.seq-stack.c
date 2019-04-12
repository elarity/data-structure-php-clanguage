#include <stdio.h>
/* @desc : exit原型在stdlib.h中 */
#include <stdlib.h>
#define SIZE 5

/*
 * @desc : 顺序存储实现栈,使用数组是很自然的
 *         top-pointer则是表明当前栈的位置
           -1表示空栈，0表示有一个元素
 */
typedef struct stack {
  int element[ SIZE ];
  int top_pointer;
} stack;
// 下面这句你可以这么理解: 令( stack * ) = stack_pointer
typedef stack * stack_pointer;

/*
 * @desc : 一般说来，栈有两个重要操作需要实现，一个是push，一个是pop
 */
void push( stack_pointer, int );
int  pop( stack_pointer );

int main( int argc, char * argv[] ) {
  // 给栈结构体分配一个内存吧
  stack_pointer s = ( stack_pointer )malloc( sizeof( stack_pointer ) );  
  // 记住了哈，初始化空栈，-1时为空，当然这个不是定死的，只是本案例中-1代表空
  s->top_pointer  = -1;
  // 入栈
  push( s, 1 );
  push( s, 2 );
  push( s, 3 );
  push( s, 4 );
  push( s, 5 );
  printf( "栈顶为：%d\n", s->top_pointer );
  // 出栈
  int temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  temp = pop( s );
  printf( "栈顶为：%d , 弹出元素为：%d\n", s->top_pointer, temp );
  return 0;
}

/*
 * @param : s ，栈的指针
 * @param : element , 要入栈的元素
 */
void push( stack_pointer s, int element ) {
  // 判断一下栈是不是满了 ·
  if ( SIZE - 1 == s->top_pointer ) {
    printf( "stack满了\n" );
    exit( -1 );
  } 
  s->element[ ++( s->top_pointer ) ] = element;  
}

/*
 * @desc : s 栈的指针
 */
int pop( stack_pointer s ) {
  if ( -1 == s->top_pointer ) {
    printf( "stack是空的\n" );
    exit( -1 );
  } 
  int temp = s->element[ s->top_pointer ];
  s->element[ s->top_pointer ] = 0;
  s->top_pointer--; 
  return temp;
}
