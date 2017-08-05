/**
 * 汉诺塔问题
 */
#include<stdio.h>
static count = 0; // 移动步骤总数

/* 移动圆盘函数 */
void move(int n, char x, char y) {
	printf("圆盘：%d %c --> %c\n", n, x, y);
	count++;
}

/* 汉诺塔递归调用函数
 * 将x上编号为1至n的圆盘移到z,y作辅助塔
 */
void hanoi(int n, char x, char y, char z) {
	if(n == 1) {
		move(1, x, z);
	} else {
		hanoi(n-1, x, z, y); // 将x上编号为1至n-1的圆盘移到y,z作辅助塔
		move(n, x, z);
		hanoi(n-1, y, x, z); // 将y上编号为1至n-1的圆盘移到z,x作辅助塔
	}
}

int main() {
	int n;
	printf("请输入圆盘个数：");
	scanf("%d", &n);
	printf("\n移动步骤如下\n");
	hanoi(n, 'A', 'B', 'C');
	printf("\n移动步骤总数为：%d\n", count);
	return 0;
}
