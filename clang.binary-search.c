#include <stdio.h>
#include <unistd.h>
/*
 * 折半查找本质上是【有序查找】
 * 查找的基本前提是数据整体有序
 */
int main( int argc, char * argv[] ) {
  int target = 3;
  int arr[] = { 1, 3, 4, 5, 66, 666, 999, 1000, 2032, 3030, 4040, 5050, 7676 };  
  int arr_length = sizeof( arr ) / sizeof( int );
  int left_limit_index  = 0; 
  int right_limit_index = arr_length - 1;
  while( left_limit_index <= right_limit_index ) {
    sleep( 1 );
    int middle = ( left_limit_index + right_limit_index ) / 2; 
    printf( "left:%d，right:%d，middle:%d\n", left_limit_index, right_limit_index, middle );
    if ( target < arr[ middle ] ) {
      right_limit_index = middle - 1;
    } 
    else if ( target > arr[ middle ] ) {
      left_limit_index = middle + 1;
    }
    else {
      printf( "%d bingo\n", middle );
      return middle;
    }
  }
  printf( "没有找到\n" );
  return 0;
}
