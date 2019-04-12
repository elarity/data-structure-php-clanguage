#include <stdio.h>
#include <stdlib.h>

/*
 * @desc : 链式存储实现堆栈比较屌的一个地方就是不用关心容量问题了。主要内存够用，你就卯着劲malloc
           又不是不能用。每个节点由“数据和指向下一个节点的指针”组成！
 */

// 这个就是每个节点的struct结构
typedef struct link_stack_node {
  int                      element;
  struct link_stack_node * next;
} link_stack_node;
typedef link_stack_node * link_stack_node_p;

// 这个栈的struct结构
// top_pointer是栈顶指针,!!!注意！！！如果是空栈，该指针内容为NULL即可！
// length是栈中元素个数
typedef struct link_stack {
  link_stack_node_p top_pointer; 
  int               length;
} link_stack;
typedef link_stack * link_stack_p;

// 依然还要重点实现push和pop
void push( link_stack_p, int );
int  pop( link_stack_p );

int main( int argc, char * argv[] ) {
  // malloc分配栈信息结构
  link_stack_p s = ( link_stack_p )malloc( sizeof( link_stack ) ); 
  s->top_pointer = NULL;
  s->length      = 0;
  // push一个元素
  push( s, 1 );
  push( s, 2 );
  push( s, 19 );
  push( s, 29 );
  printf( "length : %d\n", s->length );
  // pop 一个元素
  int temp = pop( s );
  printf( "pop : %d\n", temp ); 
  printf( "length : %d\n", s->length );
  return 0;
}

void push( link_stack_p s, int element ) {
  // 注意！此时push就不需要判断栈容量是否够或者栈是否满了，你自己看下你内存，自己看着办 
  // malloc一个新节点
  link_stack_node_p s_node = ( link_stack_node_p )malloc( sizeof( link_stack_node ) );  
  s_node->element = element;  
  s_node->next    = NULL;
  // 将栈s的 元素数量加1并将栈顶指针指向该新节点
  s->length++;
  s->top_pointer = s_node;
}

int pop( link_stack_p s ) {
  // 这个。。。好像得判断下是不是空栈，是吧...
  if ( NULL == s->top_pointer ) {
    printf( "空栈\n" );
    exit( -1 );
  }
  // 然后。。开始pop,这个由于节点的内存都是通过malloc过来的，所以，pop后要free下
  // 不然内存就炸裂了
  int temp;
  // 我比较记不住 *,->,. 的优先级，我比较怂，不整高端的，直接加括弧表明优先
  // 希望编译器比较屌，能优化了..
  temp = ( *( s->top_pointer ) ).element;
  // free内存 并将长度减1
  free( s->top_pointer );
  s->length--; 
  return temp;
}
