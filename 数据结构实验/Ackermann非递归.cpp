//#include "stdio.h"
//#include <stdlib.h>
//
//typedef int ElemType;
//typedef struct node
//{
//	ElemType data, data1;
//	struct node* next;
//} LinkStNode;
//
//void Show(LinkStNode* p)
//{
//	printf("m:%d    n:%d\n", p->data, p->data1);
//}
//
//ElemType Akm(ElemType m, ElemType n)
//{
//	printf("以下模拟进出栈过程：");
//	LinkStNode* Top = (LinkStNode*)malloc(sizeof(LinkStNode));
//	Top->data = m;
//	Top->data1 = n;
//	Top->next = NULL;
//	Show(Top);
//	ElemType result = 0;
//	while (Top != NULL)
//	{
//		//akm(m,n)=n+1
//		if (Top->data == 0 && Top->data1 >= 0)
//		{
//			ElemType x = Top->data1 + 1;
//			while (Top != NULL && Top->data1 >= 0)
//			{
//				//出栈
//				LinkStNode* p = Top;
//				Top = Top->next;
//				free(p);
//				printf("pop\n");
//			}
//			if (Top == NULL)
//			{
//				result = x;
//				break;
//			}
//			else if (Top->data1 < 0)
//			{
//				Top->data1 = x;
//			}
//		}
//		//akm(m,n)=akm(m-1,1)
//		else if (Top->data > 0 && Top->data1 == 0)
//		{
//			LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
//			p->data = Top->data - 1;
//			p->data1 = 1;
//			p->next = Top;
//			Top = p;
//			Show(Top);
//		}
//		//akm(m,n)=akm(m-1,akm(m,n-1))
//		else if (Top->data > 0 && Top->data1 > 0)
//		{
//			LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
//			LinkStNode* q = (LinkStNode*)malloc(sizeof(LinkStNode));
//			p->data = Top->data - 1;
//			p->data1 = -1;
//			q->data = Top->data;
//			q->data1 = Top->data1 - 1;
//			p->next = Top;
//			Top = p;
//			Show(Top);
//			q->next = Top;
//			Top = q;
//			Show(Top);
//		}
//	}
//	return result;
//}
//
//void main()
//{
//	ElemType r = Akm(2, 1);
//	printf("结果为：%d\n", r);
//}