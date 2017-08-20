/**
 * 插入类排序之折半插入排序
 */
#include<stdio.h>

/* 排序算法 */
void binSort(int arr[], int length) {
	int i, j, low, high, mid, key;
	for(i=1; i<length; i++) {
		key = arr[i];
		low = 0;
		high = i - 1;
		while(low <= high) {
			mid = (low + high) / 2;
			if(key < arr[mid]) {
				high = mid - 1; 		
			} else {
				low = mid + 1;
			}
		}
		for(j=i-1; j>=low; j--) {
			arr[j+1] = arr[j];
		}
		arr[low] = key;
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
	binSort(arr, length);
	printf("排序后数组：");
	show(arr, length);
	return 0;
}

/** 
 * 空间复杂度：只需要一个辅助空间存储当前元素，即空间复杂度为O(1)
 * 时间复杂度：所有语句的执行频度之和，双重循环，即时间复杂度为O(n^2)
 */
