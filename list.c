/**
 * 链表的实现
 */
#include<stdio.h>
#include<stdlib.h>
#define flag 0

typedef int ElemType;
typedef struct Lnode
{ // 链式存储结构定义
	int data; // 数据域
	struct Lnode *next; // 指针域
}Lnode, *LinkList; // 结点和头指针类型名

/* 在带头结点单链表中查找第i个数据元素，找到返回其指针，否则返回空 */
Lnode *Get_LinkList(LinkList L, int i) {
	Lnode *p = L;
	int j = 0;
	while(p != NULL && j<i) { p = p->next; j++; }
	return p;
}

/* 在带头结点单链表中查找值等于给定值的节点 */
int Locate_LinkList(LinkList L, int x) {
	LinkList p;
	int j;
	p = L->next;
	while(p != NULL && p->data != x) {
		p = p->next;
		j++;
	}
	if(p) {
		printf("%d在链表中，是第%d个元素。\n", p->data, j);
		return j;
	} else {
		printf("该数值不在链表里。\n");
		return 0;
	}
}

/* 在带头结点单链表的第i个位置之后插入值为x的元素 */
int Insert_LinkList(LinkList L, int i, int x) {
	Lnode *p, *s;
	p = Get_LinkList(L, i);
	if(p == NULL) {
		printf("参数i输入有误!\n");
		return 0;
	} else {
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

/* 删除带头结点单链表的第i个数据结点 */
int Delete_LinkList(LinkList L, int i) {
	LinkList p, s;
	p = Get_LinkList(L, i-1);
	if(p == NULL) {
		printf("待删除结点前结点不存在!\n");
		return -1;
	} else {
		s = p->next;
		p->next = s->next;
		free(s);
		return 1;
	}
}

/* 前插法创建带头结点单链表 */
void Create_LinkList(LinkList L, int n) {
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	for(i=n; i>0; i--) {
		p = (LinkList)malloc(sizeof(Lnode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
}

/* 单链表的显示 */
void Display_LinkList(LinkList L) {
	LinkList p;
	p = L;
	while(p->next) {
		printf("%d	", p->next->data);
		p = p->next;
	}
}

/* 主程序 */
int main() {
	printf("初始化\n建立单链表如下：\n");
	LinkList L;
	int x, y, cord, i;
	printf("1111111");
	Create_LinkList(L, 4);
	printf("2222222");
	Display_LinkList(L);
	printf("3333333");
	do {
		printf("\n			主菜单			\n");
		printf("	1 尾插法插入元素到指定位置	\n");
		printf("	2 删除某一指定元素			\n");
		printf("	3 查找指定元素				\n");
		printf("	0 结束程序					\n");
		printf("----------------------------------\n");
		printf("请输入您选择的菜单号<1, 2, 3, 0>：");
		scanf("%d", &cord);
		switch(cord)
		{
			case 1:
				printf("请输入插入元素的位置前序号i：");
				scanf("%d", &x);
				printf("请输入插入的数据y：");
				scanf("%d", &y);
				Insert_LinkList(L, x, y);
				printf("单链表输出如下：\n");
				Display_LinkList(L);
				break;
			case 2:
				printf("请输入删除元素序号x=?");    
				scanf("%d", &x);
                Delete_LinkList(L, x);
                printf("单链表输出如下：\n");   
                Display_LinkList(L);
                break;
			case 3:
				printf("请输入查找元素值x：");
				scanf("%d", &x);
				i = Locate_LinkList(L, x);
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
