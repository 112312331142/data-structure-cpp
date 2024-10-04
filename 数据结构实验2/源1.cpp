//#include<iostream>
//using namespace std;
//
//void QuickSort(int arr[], int low, int high)
//{
//	int i = 1, j = 1, k = high, temp;
//	while (k != j)
//	{//1表示红色，2表示白色，3表示蓝色
//		while (arr[k] == 3) k--;    //k指的是蓝色，故直接后移
//		if (arr[k] == 1)        //k指的是红色
//			if (i >= j)     //i左侧全部是红色，直接将k所指红色与i交换即可
//			{
//				temp = arr[k];
//				arr[k] = arr[i];
//				arr[i] = temp;
//				i++;
//			}
//			else            //i<j时表示i所指为白色，此时应当将未处理的j所指与i交换，再将k所指红色与未处理交换
//			{
//				temp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp;
//				j++;
//				temp = arr[k];
//				arr[k] = arr[i];
//				arr[i] = temp;
//				i++;
//			}
//		if (arr[k] == 2)     //k指的是白色
//			if (i <= j)   //j左侧为白色，直接将k所指交换即可
//			{
//				temp = arr[k];
//				arr[k] = arr[j];
//				arr[j] = temp;
//				j++;
//			}
//			else         //j指的是红色，i的左侧是红色，故应当将k与i交换
//			{
//				temp = arr[k];
//				arr[k] = arr[i];
//				arr[i] = temp;
//				j = i + 1;
//			}
//	}
//	if (arr[k] == 2) j++; //此时k=j且j所指为白色
//	else if (arr[k] == 1)  //j=k且j所指为红色，故应当和j所指调换位置
//	{
//		temp = arr[j];
//		arr[j] = arr[i];
//		arr[i] = temp;
//		i++;
//		j++;
//	}
//}
//
//int main() {
//	int arr[100],n;
//	cout << "输入桶的数量：" << endl;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cout << "1表示红色，2表示白色，3表示蓝色。"<<endl;
//		cout << "输入第" << i+1 << "个桶中砾石的颜色:";
//		cin >> arr[i];
//	}
//	arr[n] = '\0';
//	cout << "排列后：";
//	QuickSort(arr, 0, n-1);
//	for (int i = 0; i < n; i++) {
//		cout << arr[i]<<" ";
//	}
//}