/**
 * 循环队列打印杨辉三角
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 200

typedef int ElemType;

/* 队列存储结构 */
typedef struct SqQueue
{
	ElemType elem[MaxSize];
	int front, rear; // 队首和队尾指针
} SqQueue;

/* 循环队列初始化 */
SqQueue *Init_SqQueue() {
	SqQueue *q;
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
	return q;
}

/* 入队 */
int En_SqQueue(SqQueue *q, ElemType e) {
	if((q->rear+1)%MaxSize == 0) return 0; // 队满
	q->elem[q->rear] = e;
	q->rear = (q->rear+1)%MaxSize;
	return 1;
}

/* 出队 */
int De_SqQueue(SqQueue *q, ElemType &e) {
	if(q->front == q->rear) return 0; // 队空
	e = q->elem[q->front];
	q->front = (q->front+1)%MaxSize;
	return 1;
}

/* 循环队列的显示 */
void Display_SqQueue(SqQueue *q) {
	int i, Q;
	Q = q->front;
	for(i=q->front; i != q->rear; i=(i+1)%MaxSize) {
		printf("%d ", q->elem[i]);
	}
	printf("\n");
}

/* 杨辉三角 */
void YangHuiTriangle(int n) {
	SqQueue *q;
	int i, j, x;
	q = Init_SqQueue();
	En_SqQueue(q, 1); // 第一行元素入队
	for(i=2; i<=n; i++) { // 产生第n行元素并入队，同时打印第n-1行的元素
		En_SqQueue(q, 1); // 第n行的第一个元素入队
		for(j=1; j<=i-2; j++) { // 利用队中第n-1行元素产生第n行的中间n-2个元素并入队
			En_SqQueue(q, q->elem[q->front] + q->elem[(q->front+1)%MaxSize]);
			De_SqQueue(q, x);
			if(j == 1) {
				for(int k=1; k<=n-i+1; k++) {
					printf(" ");
				}
			} 
			printf("%d ", x); // 打印第n-1行元素
		}
		De_SqQueue(q, x); // 第n-1行最后一个元素出队
		if(i == 2) {
			for(int k=1; k<=n-i+1; k++) {
				printf(" ");
			}
		}
		printf("%d ", x);
		En_SqQueue(q, 1); // 第n行的最后一个元素入队
		printf("\n");
	}
	Display_SqQueue(q); // 打印最后一行元素
}

/* 主程序 */
int main() {
	int n;
	printf("请输入行数n：");
	scanf("%d", &n);
	YangHuiTriangle(n);
	return 0;
}