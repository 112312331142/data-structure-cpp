//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//#define MaxSize 100
//typedef int ElemType;
//typedef struct SqQueue{
//	ElemType data[MaxSize];//存放队中的元素
//	int front, rear;//队头和队尾指针
//}SqQueue;//顺序队类型
//
//void InitQueue(SqQueue*& q) {//初始化队列
//	q = new SqQueue;
//	q->front = q->rear =-1;
//}
//
//bool EnQueue(SqQueue*& q, ElemType e) {//进队列
//	if (q->rear == MaxSize - 1)//堆满上溢出
//		return 0;
//	q->data[q->rear] = e;
//	q->rear++;
//	return 1;
//}
//
//bool DeQueue(SqQueue*&q, ElemType& e) {//出队列
//	if (q->front == q->rear)//堆满下溢出
//		return 0;
//	e = q->data[q->front];
//	q->front++;
//	return 1;
//}
//
//bool GetFront(SqQueue* q, ElemType& num) {//获取队头元素
//	if (q->front == q->rear)
//		return false;
//	num = q->data[q->front];
//	return true;
//}
//
//bool GetRear(SqQueue* q, ElemType& num) {//获取队尾元素
//	if (q->front == q->rear)
//		return false;
//	num = q->data[q->rear-1];
//	return true;
//}
//
//int main() {
//	SqQueue* h1, * h2, * h3;//创建队列，相当于三条铁轨
//	InitQueue(h1);
//	InitQueue(h2);
//	InitQueue(h3);
//	SqQueue* Array[] = { h1,h2,h3 };//指向结构体的指针数组
//	cout << "输入车厢号，输入0停止" << endl;
//	while (1) {//先将元素入队h3
//		int n;
//		cin >> n;
//		if (n == 0)
//			break;
//		EnQueue(h3, n);
//	}
//	int nowOut = 1;//下一个输出的车厢编号，最开始为1
//	cout << "排序后" << endl;
//	while (h1->front < h1->rear || h2->front < h2->rear || h3->front < h3->rear) {
//		//所有队列全为空时，退出循环
//		int flag = 0;//为0时，表示入轨和缓冲轨对头都没有编号为nowOut的车厢
//		//为1，表示在入轨和缓冲轨队头找到编号为nowOut的车厢
//		int num;
//		GetFront(h3,num);//获取入轨的队头元素
//		if (num == nowOut) {//与nowOut一样时，直接出队列
//			DeQueue(h3, num);
//			nowOut++;
//			cout << num<<" ";
//			flag = 1;
//		}
//		else {
//			for (int i = 0; i < 2; i++) {//在缓冲队列中找
//				GetFront(Array[i], num);
//				if (num == nowOut) {
//					DeQueue(Array[i], num);
//					nowOut++;
//					cout << num<<" ";
//					flag = 1;
//				}
//			}
//		}
//		if (flag == 0) {//入轨和缓冲轨中都没有
//			int a;
//			for (int i = 0; i < 2; i++) {//求小于入轨中第一个车厢编号的最大队尾元素所在队列编号
//				GetFront(h3, num);
//				GetRear(Array[i], a);
//				if (num > a || Array[i]->rear == -1) {
//					//如果存在，则把入轨中的第一个车厢移至缓冲轨
//					DeQueue(h3, num);
//					EnQueue(Array[i], num);
//					break;
//				}
//				else if(i==1){//轨道数量太少，没有解决的办法
//					cout << "没有解决的办法" << endl;
//					return 0;
//				}
//			}
//		}
//	}
//	return 0;
//
//}
