#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

// 用这个struct存储键值对
// 比如 username:"xiaodushe"
typedef struct {
  // 实际上个人倾向于在struct的字符串成员中不使用指针方式
  char * key;
  char * value;
} hashtable_item;
// 将每个键值对存储到hash-table中去
typedef struct {
  // 当前一共有多少个键值对item
  int counter; 
  // hashtable的容量有多大
  int size;
  // 知道这里为什么用二级指针么？
  hashtable_item ** item; 
} hashtable;

// 这个函数用来为每个键值对 hashtable-item 分配内存
// return : 指向hashtable-item的指针
hashtable_item * allocate_new_item( char * key, char * item ) {
  hashtable_item * pt_ht_item = ( hashtable_item * )malloc( sizeof( hashtable_item ) );
  // strdup函数原型位于 string.h 文件中
  pt_ht_item->key   = strdup( key );
  pt_ht_item->value = strdup( item );
  return pt_ht_item;
}

// 为整个hash-table分配空间.
// return : 指向hashtable的指针
hashtable * allocate_hashtable( int size ) {
  hashtable * pt_ht = ( hashtable * )malloc( sizeof( hashtable ) ); 
  pt_ht->size       = size;
  pt_ht->counter    = 0;
  pt_ht->item       = calloc( pt_ht->size, sizeof( hashtable_item * ) );
  return pt_ht;
}

// 释放键值对hashtable-item的内存空间
void free_hashtable_item( hashtable_item * pt_item ) {
  // 释放清空key 和 item指针指向的空间
  free( pt_item->key );
  free( pt_item->value );
  // 最后再释放item自己
  // 如果key和item并不是指针方式的话，就只需要free item即可
  free( pt_item );
}

// 释放整个hashtable
void free_hashtable( hashtable * pt_ht ) {
  // 释放掉hashtable中所有的hashtable-item键值对
  for( int i = 1; i < pt_ht->size; i++ ) {
    hashtable_item * pt_ht_item = pt_ht->item[ i ]; 
    // 如果不为空指针，说明该位置是有hashtable-item键值对
    if( NULL != pt_ht_item ) {
      free_hashtable_item( pt_ht_item );
    }
  }
  // 清空item成员指针指向的内存空间
  free( pt_ht->item );
  // 清空hashtable自己本身
  free( pt_ht );
}

// 网上广为流传的time33 hash算法...反正能用
uint time33( char * str, const int size ) {
  uint hash = 5381;
  while( *str ){
    hash += ( hash << 5 ) + ( *str++ );
  }
  hash = ( hash & 0x7FFFFFFF );
  // 此处沙雕地改了一下，凑合看...正式用千万别这么搞，可能会被人打死
  hash = hash % size;
  return hash;
}

// 插入数据
// param : hashtable_item *
void insert_item_hashtable( hashtable_item * pt_ht_item, hashtable * pt_hashtable ) {
  // 检测hashtable容量是否已经满了
  if ( pt_hashtable->counter == pt_hashtable->size ) {
    printf( "hashtable容量已经满了.\n" );
    return;
  }
  // 计算这个item键值对在hashtable中的位置。
  uint index = time33( pt_ht_item->key, pt_hashtable->size );
  //printf( "%u\n", index );
  // 检测index位置上是否已经有元素
  // 如果有元素，则查找下一个元素位置
  // item键值对的指针就存在这里:pt_hashtable->item
  // 偏移量从0开始 
   
}

// 删除数据
void delete_item_hashtable() {
}

int main( int argc, char * argv[] ) {
  // 初始化一个hashtable，容量为可以存储20个item键值对
  int size = 20;
  hashtable * pt_hashtable = allocate_hashtable( size ); 
  // 初始化一个item键值对.
  char * key  = "username";
  char * item = "xiaodushe";
  hashtable_item * pt_ht_item = allocate_new_item( key, item );
  // 将item键值对插入到hashtable中去
  insert_item_hashtable( pt_ht_item, pt_hashtable );
  // 清空这个hashtable-item
  free_hashtable_item( new_ht_item );
  // 清空这个hashtable
  free_hashtable( pt_hashtable ); 
}
