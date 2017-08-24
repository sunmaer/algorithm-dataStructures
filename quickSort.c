/**
 * 交换类排序之快速排序
 */
#include<stdio.h>

/* 排序算法 */
void quickSort(int arr[], int low, int high) {
	if(low < high) {
		int i=low, j=high, x=arr[low];
		while(i<j) {
			while(i < j && arr[j] >= x) {
				j--;
			}
			if(i < j) { 
				arr[i++] = arr[j];
			}
			while(i < j && arr[i] <= x) {
				i++;
			}
			if(i < j) {
				arr[j--] = arr[i];
			}	
		}
		arr[i] = x;
		quickSort(arr, low, i-1);
		quickSort(arr, i+1, high);
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
	int length = 8;
	printf("排序前数组：");
	show(arr, length);
	quickSort(arr, 0, length);
	printf("排序后数组：");
	show(arr, length);
	return 0;
}

/** 
 * 空间复杂度：只需要一个辅助空间存储当前元素，即空间复杂度为O(1)
 * 时间复杂度：所有语句的执行频度之和，双重循环，即时间复杂度为O(n^2)
 */
