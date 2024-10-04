//#include<iostream>
//using namespace std;
//
//#define M 6
//#define N 6
//#define MaxSize 100//矩阵中非0元素的最大个数
//typedef int ElemType;
//typedef struct {
//	int r;//行号
//	int c;//列号
//	ElemType d;//元素值
//}TupNode;//三元组的定义
//typedef struct {
//	int rows;//总行数
//	int cols;//总列数
//	int nums;//非零元素的个数
//	TupNode data[MaxSize];
//}TSMatrix;
//
//int num[N] = {};//表示矩阵中某列非零元素的个数
//int cpot[N] = {};//矩阵A中某列的第一个非零元素在B中的位置
//void CreateMat(TSMatrix& t, ElemType A[M][N]) {//产生矩阵的三元组表示
//	int i, j;
//	t.rows = M;
//	t.cols = N;
//	t.nums = 0;
//	for (i = 0; i < M; i++) {
//		for (j = 0; j < N; j++) {
//			if (A[i][j] != 0) {//只存储非零元素
//				num[j]++;
//				t.data[t.nums].r = i;
//				t.data[t.nums].c = j;
//				t.data[t.nums].d = A[i][j];
//				t.nums++;
//			}
//		}
//	}
//}
//
//void DispMat(TSMatrix t) {//输出三元组
//	int k;
//	if (t.nums <= 0)
//		return;
//	for (k = 0; k < t.nums; k++) {
//		cout << t.data[k].r <<" " << t.data[k].c<<" "<< t.data[k].d << endl;
//	}
//}
//
//
//void TranMat(TSMatrix A, TSMatrix& B) {//求转置矩阵
//	B.rows = A.cols;
//	B.cols = B.rows;
//	B.nums = A.nums;//矩阵B的行数、列数、非零元素个数
//	cpot[0] = 0;//初始值为0
//	for (int i = 0; i < MaxSize; i++) {
//		cpot[i] = cpot[i - 1] + num[i - 1];//两者的递推关系
//	}
//	for (int i = 0; i < A.nums; i++) {//依次取A中每一个元素对应的三元组
//		int pb = A.data[i].c;//该元素在B中的下标j
//		int k = cpot[pb];
//		B.data[k].r = A.data[i].c;
//		B.data[k].c = A.data[i].r;
//		B.data[k].d = A.data[i].d;
//		//将该元素的行号列号交换后存入B中pb的位置
//		cpot[pb]++;//该元素所在列下一个元素的存放位置
//	}
//}
//
//int main() {
//	ElemType a[M][N] = { {1,0,0,0,0,0},{5,2,4,0,0,0},{0,0,3,0,0,0},
//		{8,0,0,0,0,0},{0,0,6,0,0,0},{0,0,0,0,0,0} };//矩阵的赋值
//	TSMatrix T,T1;//T表示原矩阵，T1表示转置后的矩阵
//	CreateMat(T, a);
//	cout << "——————————原矩阵三元组—————————————" << endl;
//	DispMat(T);
//	cout << "————————转制后的矩阵三元组————————————" << endl;
//	TranMat(T, T1);
//	DispMat(T1);
//}
//
//
//
//
