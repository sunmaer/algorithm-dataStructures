/**
 * 二分查找
 */
#include<stdio.h>

/* 二分查找算法,要求数组是有序 */
void binSearch(int arr[], int length, int key) {
	int low = 0, high = length - 1, mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if(arr[mid] == key) {
			printf("%d 是数组的第 %d 个元素\n", key, mid + 1);
			break;
		} else if(arr[mid] < key) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	if(low > high) {
		printf("数组中不存在该元素\n");
	}
}

int main() {
	int arr[] ={ 1, 2, 3, 4, 5, 6, 7, 8 };
	int length = 8, key, i;
	for(i=0; i<length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n请输入查找元素：");
	scanf("%d", &key);
	binSearch(arr, length, key);
	return 0;
}

