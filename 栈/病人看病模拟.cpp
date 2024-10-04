//#include<stdio.h>
//#include<malloc.h>
//typedef struct qnode {
//	int data;
//	struct qnode* next;
//}QNode;
//typedef struct {
//	QNode* front, * rear;
//}QuType;
//
//void Destroyqueue(QuType*& qu) {
//	QNode* pre, * p;
//	pre = qu->front;
//	if (pre != NULL) {
//		p = pre->next;
//		while (p != NULL) {
//			free(pre);
//			pre = p;
//			p = p->next;
//		}
//		free(pre);
//	}
//	free(qu);//释放链队节点
//}
//
//bool exist(QuType* qu, int no) {
//	bool find = false;
//	QNode* p = qu->front;
//	while (p != NULL && !find) {
//		if (p->data == no)
//			find = true;
//		else
//			p = p->next;
//	}
//	return find;
//}
//
//void SeeDoctor() {
//	int sel,no;
//	bool flag = true;
//	QuType* qu;
//	QNode* p;
//	qu = (QuType*)malloc(sizeof(QuType));
//	qu->front = qu->rear = NULL;
//	while (flag) {
//		printf(">1：排队 2：就诊 3：查看排队 4：不在排队，余下就诊 5：下班 请选择：");
//		scanf_s("%d", &sel);
//		switch (sel) {
//		case 1:
//			printf(" 输入病历号：");
//			while (true) {
//				scanf_s("%d", &no);
//				if (exist(qu, no))
//					printf("error");
//				else
//					break;
//			}
//			p = (QNode*)malloc(sizeof(QNode));
//			p->data = no;
//			p->next = NULL;
//			if (qu->rear == NULL)
//				qu->front = qu->rear = p;
//			else {
//				qu->rear->next = p;
//				qu->rear = p;
//			}
//			break;
//		case 2:
//			if (qu->front == NULL)
//				printf("no patient\n");
//			else {
//				p = qu->front;
//				printf("number %d visit a doctor\n", p->data);
//				if (qu->rear == p)
//					qu->front = qu->rear = NULL;
//				else
//					qu->front = p->next;
//				free(p);
//			}
//			break;
//		case 3:
//			if (qu->front == NULL)
//				printf("no patients in the line");
//			else {
//				p = qu->front;
//				printf(">>patients:");
//				while (p != NULL) {
//					printf("%4d", p->data);
//					p = p->next;
//				}
//				printf("\n");
//			}
//			break;
//		case 4:
//			if (qu->front == NULL)
//				printf(">>no queue!\n");
//			else {
//				p = qu->front;
//				printf("  >>patients are presented in the following order:");
//				while (p != NULL) {
//					printf("%4d", p->data);
//					p = p->next;
//				}
//				printf("\n");
//			}
//			Destroyqueue(qu);
//			flag = false;
//			break;
//		case 5:
//			if (qu->front != NULL)
//				printf("please tommorrow visit a doctor\n");
//			flag = false;
//			Destroyqueue(qu);
//			break;
//		}
//	}
//}
//int main() {
//	SeeDoctor();
//}