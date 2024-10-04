//#include <iostream>
//using namespace std;
//# define OK 1;
//typedef int ElemType;
//
//typedef struct node
//{
//	ElemType data;
//	struct node* prior, * next;
//}node, * DLinkedList;
//
//void CreateDlink(DLinkedList& L)
//{
//	int i, n;
//	DLinkedList rear, p;
//	L = new node;
//	L->next = NULL;
//	rear = L;
//	cin >> n;
//	for (i = 1; i <= n; i++)
//	{
//		p = new node;
//		cin >> p->data;
//		p->next = NULL;
//		rear->next = p;
//		p->prior = rear;
//		rear = p;
//	}
//}
//
//void TwoWayBubbleSort(DLinkedList L)
////对存储在带头结点的双向链表la中的元素进行双向起泡排序。
//{
//	DLinkedList p, q;
//	p = L->next;
//
//	while (p->next)
//	{
//		q = p->next;
//		while (q)
//		{
//			if (q->data < p->data)
//			{
//				ElemType t = p->data;
//				p->data = q->data;
//				q->data = t;
//			}
//
//			q = q->next;
//		}
//
//		p = p->next;
//	}
//} //算法结束 
//
//void DlinkOut(DLinkedList& L)
//{
//	DLinkedList p;
//	p = L->next;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//int main()
//{
//	DLinkedList L;
//	CreateDlink(L);
//	TwoWayBubbleSort(L);
//	cout << "双向冒泡排序:" << endl;
//	DlinkOut(L);
//	return 0;
//}