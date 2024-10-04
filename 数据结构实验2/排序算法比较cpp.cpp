//#include <iostream>
//#include<iomanip>
//using namespace std;
//void ShellSort(int r[], int n)
//{
//    int d, i, j;
//    int tmp;
//    d = n / 2;          //增量置初值
//    while (d > 0) {
//        for (i = d; i < n; i++) {       //对所有组采用直接插入排序
//            tmp = r[i];                 //对相隔d个位置的一组采用直接插入排序
//            j = i - d;
//            while (j >= 0 && tmp < r[j]) {
//                r[j + d] = r[j];
//                j = j - d;
//            }
//            r[j + d] = tmp;
//        }
//        d = d / 2;
//    }
//}
//void swap(int& x, int& y)
//{
//    int tmp = x;
//    x = y;
//    y = tmp;
//}
//int Partition(int r[], int first, int end)
//{
//    int i, j;
//    i = first; j = end;         //初始化
//    while (i < j)
//    {
//        while (i < j && r[i] <= r[j]) j--;  //右侧扫描
//        if (i < j) {
//            swap(r[i], r[j]);            //将较小记录交换到前面
//            i++;
//        }
//        while (i < j && r[i] <= r[j]) i++;  //左侧扫描
//        if (i < j) {
//            swap(r[j], r[i]);            //将较大记录交换到后面
//            j--;
//        }
//    }
//    return i;    //i为轴值记录的最终位置
//}
//void QuickSort(int r[], int first, int end)
//{
//    if (first < end) {      //递归结束
//        int pivot = Partition(r, first, end);  //一次划分
//        QuickSort(r, first, pivot - 1);  //递归地对左侧子序列进行快速排序
//        QuickSort(r, pivot + 1, end);   //递归地对右侧子序列进行快速排序
//    }
//}
//void print(int a[]) {
//    for (int i = 0; i < 10; i++) {
//        cout<<setw(2) << a[i];
//    }
//}
//int main() {
//    int a[10];
//    for (int i = 0; i < 10; i++)
//        cin >> a[i];
//    cout<<"排序前:";
//    print(a);
//    cout << endl;;
//    cout<<"快速排序后:";
//    QuickSort(a, 0, 9);
//    print(a);
//    cout<<endl;
//    cout<<"希尔排序后:";
//    ShellSort(a, 10);
//    print(a);
//
//
//}