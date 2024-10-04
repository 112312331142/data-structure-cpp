// #pragma warning(disable:4996)
//#include <stdio.h>
//#define MAXSIZE 100
//#define ERROR 0
//#define OK 1
//typedef int SElemType;
//typedef int Status;
//
//typedef struct Queue {
//	SElemType data[MAXSIZE];
//	int front;
//	int rear;
//} Queue;
//
////初始化队列 
//void InitQueue(Queue* q) {
//	q->data[0] = 0;
//	q->front = 0;
//	q->rear = 0;
//}
//
////入队
//Status EnQueue(Queue* q, SElemType num) {
//	if (q->rear >= MAXSIZE - 1) {
//		return ERROR;
//	}
//	q->data[q->rear] = num;
//	q->rear++;
//	return OK;
//}
//
////出队
//Status DeQueue(Queue* q, SElemType* num) {
//	if (q->front >= q->rear) {
//		return ERROR;
//	}
//	*num = q->data[q->front];
//	q->front++;
//	return OK;
//}
//
////获取头元素 
//Status GetHead(Queue* q, SElemType* num) {
//	if (q->front >= q->rear) {
//		return ERROR;
//	}
//	*num = q->data[q->front];
//	return OK;
//}
//
////获取尾元素 
//Status GetRear(Queue* q, SElemType* num) {
//	if (q->front >= q->rear) {
//		return ERROR;
//	}
//	*num = q->data[q->rear - 1];
//	return OK;
//}
//
//int main() {
//	Queue H1;
//	InitQueue(&H1);
//	Queue H2;
//	InitQueue(&H2);
//	Queue H3;
//	InitQueue(&H3);
//	Queue* QArray[] = { &H1, &H2, &H3 };//指向结构体的指针数组,将H1,H2,H3放入数组 
//	printf("请输入火车车厢,输入0停止输入\n");
//	while (true) {//元素全部入队进H3 
//		int num;
//		scanf("%d", &num);
//		if (num == 0) {
//			break;
//		}
//		EnQueue(&H3, num);
//	}
//	//	int num;
//	//	GetRear(&H3, &num);
//	//	printf("%d\n", num);
//
//	int nowOut = 1;//火车车厢排序的关键 
//	printf("\n出队序列为:");
//	//遍历H3队列 
//	while (H3.front < H3.rear || H1.front < H1.rear || H2.front < H2.rear) {
//		int flag = 0;
//		int num;
//		GetHead(&H3, &num);
//		//如果当前遍历元素等于nowOut就H3对头元素出队 
//		if (num == nowOut) {
//			DeQueue(&H3, &num);
//			printf("%d", num);
//			nowOut++;
//			flag = 1;
//		}
//		else {
//			//否则去寻找H1和H2对头元素是否等于nowOut,等于就出队 
//			for (int i = 0; i < 2; i++) {
//				GetHead(QArray[i], &num);
//				if (num == nowOut) {
//					DeQueue(QArray[i], &num);
//					printf("%d", num);
//					nowOut++;
//					flag = 1;
//				}
//			}
//		}
//		/*
//		如果H1,H2,H3的对头都没有等于nowOut的元素,
//		那么就将该元素入队至H1或H2,条件是小于队尾元素
//		*/
//		if (flag == 0) {
//			int container;
//			for (int i = 0; i < 2; i++) {
//				GetHead(&H3, &num);
//				GetRear(QArray[i], &container);
//				if (num > container || QArray[i]->rear == 0) {
//					DeQueue(&H3, &num);
//					EnQueue(QArray[i], num);
//					break;
//				}
//			}
//		}
//
//	}
//	printf("\n\n2062011002-吴奇\n");
//	return 0;
//}