/**
 * 插入类排序之希尔排序
 */
#include<stdio.h>

/* 排序算法 */
void shellSort(int arr[], int length) {
	int i, j, key, gap;
	for(gap=length/2; gap>0; gap=gap/2) {
		for(i=0; i<gap; i++) {
			for(j=i+gap; j<length; j+=gap) {
				if(arr[j] < arr[j-gap]) {
					key = arr[j];
					int k = j-gap;
					while(k >=0 && arr[k] > key) {
						arr[k+gap] = arr[k];
						k-=gap;
					}
					arr[k+gap] = key;
				}
			}
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
	shellSort(arr, length);
	printf("排序后数组：");
	show(arr, length);
	return 0;
}

/** 
 * 空间复杂度：只需要一个辅助空间存储当前元素，即空间复杂度为O(1)
 * 时间复杂度：希尔排序能迅速减少逆转数，尽管当间隔为1时，它相当于直接插入排序，但此时的关键字序列的逆转数已经很小，序列已经基本有序，使用的恰好是直接插入排序的
 * 最佳性质，所以一般认为它的时间复杂度为O(n^1.5)
 */
