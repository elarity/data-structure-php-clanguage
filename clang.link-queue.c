#include <stdio.h>
#include <stdlib.h>

/*
 * @desc : 队列的链式存储实现方案,两个指针：头指针指向头节点,头节点指向队列第一个节点；尾巴指针
           指向最后队列最后一个节点

           PS:头节点不是队列的第一个节点！
 
            --------    ---------     ---------     ---------
  头指针--->|头节点|--->|第一节点|--->|第二节点|--->|尾巴节点| <---尾巴指针
            --------    ---------     ---------     ---------

            当队列为空的时候,头指针和尾巴指针都指向 头节点 ～～

 */

typedef struct queue_node {
  int                 element; 
  struct queue_node * next;
} queue_node;
typedef queue_node * queue_node_p;

typedef struct queue {
  queue_node_p head;
  queue_node_p tail;
} queue;
typedef queue * queue_p;

void add( queue_p, int );
int  del( queue_p );

int main( int argc, char * argv[] ) {
  // 初始化一个空队列
  queue_p q = ( queue_p )malloc( sizeof( queue ) ); 
  // 初始化一个头节点
  queue_node_p head_node = ( queue_node_p )malloc( sizeof( queue_node ) );
  head_node->element     = 0;
  head_node->next        = NULL;
  q->head = head_node;
  q->tail = head_node;
  //
  add( q, 1 );
  add( q, 2 );
  add( q, 3 );
  add( q, 4 );
  //
  int temp = del( q );
  printf( "%d\n", temp );
  temp = del( q );
  printf( "%d\n", temp );
  temp = del( q );
  printf( "%d\n", temp );
  temp = del( q );
  printf( "%d\n", temp );
  temp = del( q );
  printf( "%d\n", temp );
  return 0;
}

void add( queue_p q, int element ) {
  // 开辟新节点
  queue_node_p node = ( queue_node_p )malloc( sizeof( queue_node ) );  
  node->element = element; 
  node->next    = NULL;
  q->tail->next = node;
  q->tail       = node;
}

int del( queue_p q ) {
  if ( q->head == q->tail ) {
    printf( "队列是空的\n" );
    exit( -1 );
  }
  int temp;
  temp = ( *( q->head->next ) ).element;
  q->head = q->head->next;
  free( q->head );
  return temp;
}
