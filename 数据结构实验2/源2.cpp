//#include<iostream>
//using namespace std;
//typedef int ElemType;
//int Search(ElemType r[], int low, int high, ElemType key) {
//	//在数组r[1ow..high]中查找关键字值等于key的记录
//	while (low < high)
//	{
//		if (r[low] > key && r[high] < key)
//		{
//			low++;
//			high--;
//		}
//		while (low <= high && r[high] > key) 
//			high--;	//从右侧开始找到第一个不大于关键字的记录，其位置为high
//		if (r[high] == key) 
//			return high;
//		while (low <= high && r[low] < key) low++;		//从左侧开始找到第一个不小于关键字的记录，其位置为low
//		if (r[low] == key) 
//			return low;
//	}
//	cout << "Not find";		//查找失败
//	return 0;
//}
//
//int main() {
//	int a[10] = { 0,1,2,9,5,6,7,8,3,4 };//令n=10
//	int key;
//	cout << "输入key值：";
//	cin >> key;
//	cout << "输出位置：";
//	cout << Search(a, 0, 9, key);
//}
//
