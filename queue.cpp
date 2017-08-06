/**
 * 循环队列的实现
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 10

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

/* 主程序 */
int main() {
	ElemType e;
	SqQueue *q;
	int i, k;
	q = Init_SqQueue();
	En_SqQueue(q, 1);
	En_SqQueue(q, 2);
	En_SqQueue(q, 3);
	En_SqQueue(q, 4);
	printf("初始化\n建立循环对列如下：\n");
	Display_SqQueue(q);
	do {
		printf("\n			  主菜单	 			\n");
		printf("			1 入队				\n");
		printf("			2 出队				\n");
		printf("			3 结束程序			\n");
		printf("--------------------------------\n");
		printf("请输入您选择的菜单号<1, 2, 3>：");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				printf("请输入入队元素：");
				scanf("%d", &k);
				En_SqQueue(q, k);
				printf("该元素入队后得到的新队列如下：\n");
				Display_SqQueue(q);
				break;
			case 2:
				if(De_SqQueue(q, e)) {
					printf("出队元素为：%d\n", e);
					printf("出队后得到的新对列如下：\n");
					Display_SqQueue(q);
				} else {
					printf("循环对列为空！\n");
				}
                break;
			case 3:
				printf("程序执行结束\n");
				exit(0);
				break;
			default:
				printf("输入有误!");
		}
	}while(i<=3 && i>0);
}
