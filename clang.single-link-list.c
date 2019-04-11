#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define ERROR -1

typedef struct node {
  int    element; 
  struct node * next;  
} node;
//有些童鞋有疑问：下面这句的意思就是将"node *"定义为快捷类型link_list，以后link_list就是node类型指针变量
typedef node * link_list;

/*
 * @desc : 世间一切皆为增删改查！你看看我函数命名方式就是curd!多么的接地气
 */
int  create_node( link_list, int, int );
int  update_node( link_list, int, int );
int  read_node( link_list, int );
int  delete_node( link_list, int );
int  range_link_list();
void destroy_link_list();

int main( void ) {
  // 初始化单链表头节点
  link_list head, first; 
  head = ( link_list )malloc( sizeof( link_list ) );  
  head->element = 0;
  head->next    = NULL; 
  // 初始化单链条第一个节点
  first = ( link_list )malloc( sizeof( link_list ) ); 
  first->element = 1;
  first->next    = NULL;
  head->next     = first;
  // 创建一个节点
  create_node( head, 1, 2 );
  create_node( head, 1, 3 );
  create_node( head, 1, 4 );
  create_node( head, 1, 5 );
  // 读取一个节点
  int temp = read_node( head, 1 );
  printf( "%d\n", temp );
  temp = read_node( head, 2 );
  printf( "%d\n", temp );
  temp = read_node( head, 3 );
  printf( "%d\n", temp );
  temp = read_node( head, 4 );
  printf( "%d\n", temp );
  temp = read_node( head, 5 );
  printf( "%d\n", temp );
  printf( "===================\n" );
  // 更新一个节点
  update_node( head, 1, 11 );
  update_node( head, 2, 22 );
  temp = read_node( head, 1 );
  printf( "%d\n", temp );
  temp = read_node( head, 2 );
  printf( "%d\n", temp );
  temp = read_node( head, 3 );
  printf( "%d\n", temp );
  temp = read_node( head, 4 );
  printf( "%d\n", temp );
  temp = read_node( head, 5 );
  printf( "%d\n", temp );
  printf( "===================\n" );
  // 删除一个节点
  delete_node( head, 2 );
  temp = read_node( head, 1 );
  printf( "%d\n", temp );
  temp = read_node( head, 2 );
  printf( "%d\n", temp );
  temp = read_node( head, 3 );
  printf( "%d\n", temp );
  temp = read_node( head, 4 );
  printf( "%d\n", temp );
  return 0;
}

/*
 * @desc  : 向某个位置插入一个元素
 * @param : 头指针
   @param : index是位置
   @parma : element是要节点的元素内容
 */
int create_node( link_list node, int index, int element ) {
  if ( index < 1 ) {
    return ERROR;
  } 
  int    counter = 1;
  while ( node && counter < index ) {
    node = node->next;
    counter++;
  } 
  // 判断index位置是否存在或合法
  if ( NULL == node || counter > index ) {
    printf( "位置不存在\n" );
    return ERROR;
  }
  // 此时的ll，就是index位置上的节点了
  // 证明一个指向node的指针类型变量
  // 并为之分配内存
  // 然后往内存中存储数据
  link_list new_node;
  new_node = ( link_list )malloc( sizeof( link_list ) ); 
  new_node->element = element;
  new_node->next    = node->next;
  node->next = new_node;
  // 创建新的节点  
  return TRUE;
}

/*
 * @desc  : 更新某个位置上元素
 */
int update_node( link_list node, int index, int element ) {
  // 位置不能小于第一个吧
  if ( index < 1 ) {
    return ERROR;
  }   
  node = node->next;
  int counter = 1;
  while ( node && counter < index ) {
    node = node->next;
    counter++;  
  } 
  // 位置超过了最后一个了，也就是index位置不存在节点了
  if ( NULL == node ) {
    return ERROR;
  }
  // 执行更新操作
  node->element = element;
  return TRUE;
}

/*
 * @desc  : 读取链表某个位置上的元素
 * @param : index表示位置,自然长度，不是数组那种傻屌似的0表示第一个，1就是第一个
 * @param : ll就是链表的入口节点
 */
int read_node( link_list node, int index ) {
  // 位置不能小于第一个吧
  if ( index < 1 ) {
    return ERROR;
  }   
  node = node->next;
  int counter = 1;
  while ( node && counter < index ) {
    node = node->next;
    counter++;  
  } 
  // 位置超过了最后一个了，也就是index位置不存在节点了
  if ( NULL == node ) {
    return ERROR;
  }
  // 此时的ll表示index位置的节点
  return node->element;
}

int delete_node( link_list node, int index ) {
  // 位置不能小于第一个吧
  if ( index < 1 ) {
    return ERROR;
  }   
  //node = node->next;
  int counter = 1;
  while ( node && counter < index ) {
    node = node->next;
    counter++;  
  } 
  // 位置超过了最后一个了，也就是index位置不存在节点了
  if ( NULL == node ) {
    return ERROR;
  }
  link_list temp = node->next;
  node->next = node->next->next;  
  free( temp );
  return TRUE;   
}
