/**
 * 交换类排序之冒泡排序
 */
#include<stdio.h>

/* 排序算法 */
void bubbleSort(int arr[], int length) {
	int i, j, temp, flag;
	for(i=0; i<length-1; i++) {
		flag = 0;
		for(j=0; j<length-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0) { // 如果一趟中没有交换则表明数组已经有序，提前退出循环
			break;
		}
	}	
}

/* 打印数组 */
void show(int arr[], int length) {
	int i;
	for(i=0; i<length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] ={ 48, 62, 35, 77, 55, 14, 35, 98 };
	int length = 8, i;
	printf("排序前数组：");
	show(arr, length);
	bubbleSort(arr, length);
	printf("排序后数组：");
	show(arr, length);
	return 0;
}

/** 
 * 空间复杂度：只需要一个辅助空间存储当前元素，即空间复杂度为O(1)
 * 时间复杂度：所有语句的执行频度之和，双重循环。第i次比较次数为n-i次，移动次数为3*(n-i)次，所以总的移动次数为3n*(n-1)/2次，即时间复杂度为O(n^2)
 */
