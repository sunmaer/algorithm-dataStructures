/**
 * 顺序栈的实现
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 20
#define ElemType int

/* 存储结构定义 */ 
typedef struct SqStack 
{
	ElemType elem[MaxSize]; // 栈元素的存储空间
	int top; // 栈顶指针
} SqStack;

/* 顺序栈初始化 */
void Init_SqStack(SqStack *s) {
	s->top = -1;
}

/* 入栈 */
void Push(SqStack *s, ElemType x) {
	if(s->top < MaxSize-1) {
		s->top = s->top+1;
		s->elem[s->top] = x;
	} else {
		printf("栈已满，不能入栈！\n");
	}
}

/* 出栈 */
int Pop(SqStack *s) {
	ElemType x;
	if(s->top != -1) {
		x = s->elem[s->top];
		s->top = s->top-1;
		return x;
	} else {
		printf("栈为空，不能出栈！\n");
		return 0;
	}
}

/* 读栈顶元素 */
int Get_Top(SqStack *s) {
	if(s->top != -1) {
		return s->elem[s->top];
	} else {
		printf("栈为空！\n");
		return 0;
	}
}

/* 顺序栈的显示 */
void Display_SqStack(SqStack *s) {
	int m;
	if(s->top == -1) {
		printf("顺序栈为空！\n");
	} else {
		for(m = s->top; m>=0; m--) {
			printf("%2d\n", s->elem[m]);
		}
		printf("\n");
	}
}

/* 主程序 */
int main() {
	SqStack s;
	int x, y, cord;
	ElemType a;
	Init_SqStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	printf("初始化\n依次进栈元素为 1 2 3 4：\n");
	printf("从栈顶到栈底元素为：\n");
	Display_SqStack(&s);
	do {
		printf("\n			  主菜单	 			\n");
		printf("			1 入栈				\n");
		printf("			2 出栈				\n");
		printf("			3 读栈顶元素			\n");
		printf("			0 结束程序			\n");
		printf("--------------------------------\n");
		printf("请输入您选择的菜单号<1, 2, 3, 0>：");
		scanf("%d", &cord);
		switch(cord)
		{
			case 1:
				printf("请输入入栈元素：");
				scanf("%d", &a);
				Push(&s, a);
				printf("由栈顶到栈底元素为：\n");
				Display_SqStack(&s);
				break;
			case 2:
				x = Pop(&s);
				printf("出栈元素为：%d\n", x);
				printf("由栈顶到栈底元素为：\n");
				Display_SqStack(&s);
                break;
			case 3:
				y = Get_Top(&s);
				printf("栈顶元素为%d：\n", y);
				printf("由栈顶到栈底元素为：\n");
				Display_SqStack(&s);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("输入有误!");
		}
	}while(cord <= 3 && cord >=0);
	return 0;
}