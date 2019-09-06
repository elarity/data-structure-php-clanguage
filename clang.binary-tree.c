#include <stdio.h>
#include <stdlib.h>

typedef struct binary_node_struct {
  int    data;
  struct binary_node_struct * left_child; 
  struct binary_node_struct * right_child;
} binary_node_struct;

// 初始化一个tree
void init_binary_tree( binary_node_struct ** );
// 前序遍历
void pre_order( binary_node_struct * );
// 中序遍历
void in_order( binary_node_struct * );
// 后序遍历
void post_order( binary_node_struct * );
// 树的深度
int get_depth( binary_node_struct * );
// 叶子节点个数
int get_leaf_number( binary_node_struct * );

int main( int argc, char * argv[] ) {
  printf( "开始初始化一个binary tree\r\n" );
  printf( "输入根节点的数值：" ); 
  binary_node_struct * t_node;
  init_binary_tree( &t_node );
  //pre_order( t_node ); 
  int depth = get_depth( t_node );
  printf( "depth:%d\n", depth );
  int leaf_number = get_leaf_number( t_node );
  printf( "leaf number:%d\n", leaf_number );
  return 0;
}

int get_leaf_number( binary_node_struct * t ) {
  static int number = 0;
  if ( t != NULL ) {
    if ( NULL == t->left_child && NULL == t->right_child ) {
      number++;
    }  
    get_leaf_number( t->left_child );
    get_leaf_number( t->right_child );
  }
  return number;
}

int get_depth( binary_node_struct * t ) {
  int depth = 0;
  if ( NULL != t ) {
    // 这里...你们慢慢琢磨哈
    int left_child_depth = get_depth( t->left_child );
    left_child_depth++;
    int right_child_depth = get_depth( t->right_child );
    right_child_depth++;
    depth = left_child_depth > right_child_depth ? left_child_depth : right_child_depth ;
  }
  return depth;
}

void post_order( binary_node_struct * t ) {
  if ( NULL == t ) {
    return;
  } 
  else {
    pre_order( t->left_child );
    pre_order( t->right_child );
    printf( "%d\n", t->data );
  }
}

void in_order( binary_node_struct * t ) {
  if ( NULL == t ) {
    return;
  } 
  else {
    pre_order( t->left_child );
    printf( "%d\n", t->data );
    pre_order( t->right_child );
  }
}

void pre_order( binary_node_struct * t ) {
  if ( NULL == t ) {
    return;
  } 
  else {
    printf( "%d\n", t->data );
    pre_order( t->left_child );
    pre_order( t->right_child );
  }
}

/*
 * @desc : 初始化一个tree
 */
void init_binary_tree( binary_node_struct ** t ) {
  int data;
  scanf( "%d", &data );  
  if ( -1 == data ) {
    *t = NULL;
    return;
  }
  else {
    *t = ( binary_node_struct * )malloc( sizeof( binary_node_struct ) ); 
    ( *t )->data = data;
    printf( "输入%d的左子树：", data );
    init_binary_tree( &( ( *t )->left_child ) );
    printf( "输入%d的右子树：", data );
    init_binary_tree( &( ( *t )->right_child ) );
    return;
  }
}
