//#include<stdio.h>
//#include<iostream>
//using namespace std;
//
//int get_kBig(int* arr, int begin, int end, int k) {
//	if (begin < end) {
//		int temp = arr[begin];//随机选一个数为基准
//		int i = begin;
//		int j = end;//i，j指针移动
//		while (i < j) {//从序列左边开始对比
//			while (i<j && arr[j]>temp)//大于temp则j左移
//				j--;
//			arr[i] = arr[j];//找到小于temp值则将此值填到arr【i】
//			while (i < j && arr[i] <= temp)
//				i++;
//			arr[j] = arr[i];
//		}
//		arr[i] = temp;//将临时的值填在特定位置
//		if (i == k - 1)
//			return arr[i];
//		else if (i > k - 1)//第k小值在temp的右边
//			return get_kBig(arr, begin, i, k);
//		else//第k小值在temp的左边且问题规模减小
//			return get_kBig(arr, i + 1, end,k-i-1);
//	}
//}
//
//int main() {
//	int arr[100] = { 0 };
//	int k = 0;
//	int i = 0;
//	int output;
//	cout << "请输入要求解的数组：";
//	for (i = 0; i < 100; i++) {
//		cin >> arr[i];
//		if (getchar() == '\n')
//			break;
//	}
//	cout << "请输入求其几最小的数：";
//	cin >> k;
//
//	output = get_kBig(arr, 0, i, k);
//	cout << output << endl;
//	system("pause");
//	return 0;
//}