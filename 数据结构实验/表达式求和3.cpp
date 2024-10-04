//#pragma warning(disable:4996)
//#include<iostream>
//#include<queue> 
//using namespace std;
//queue<int> q[100];//此数组大小取决于车厢数
//int cnt = 0;//记录总队列数 
//int num[1000];//储存车厢初始排列
//
//int main()
//{
//	int x, size = 0;//车厢数量 
//
//	while (scanf("%d", &x) != EOF)
//		num[size++] = x;
//
//	int newout = 1;//当前可以直接出去的车厢编号 
//	for (int i = size - 1; i >= 0; i--)//倒序遍历
//	{
//
//		for (int j = 0; j < cnt; j++)
//		{
//			if (!q[j].empty())//如果第j个队列不为空 
//			{
//				if (q[j].front() == newout)
//				{
//					newout++;
//					q[j].pop();//队首出队
//					j = 0;//有一个能出去的话整个缓冲轨道上的队列的队首元素都要重判
//				}
//			}
//		}
//
//		if (num[i] == newout)//如果能直接出去 
//		{
//			newout++;
//			continue;
//		}
//
//		if (cnt == 0)//特判无车在列的情况 
//		{
//			q[cnt++].push(num[i]);
//			continue;
//		}
//
//
//		//如果已有队列和当前车厢都不能出去
//		int Max = 0, index = 0;
//		bool flag = 0;//记录是否有小于当前车厢编号的队列末尾车厢
//
//		for (int j = 0; j < cnt; j++)//求取小于当前车厢编号的队列末尾车厢 
//		{
//			if (q[j].back() < num[i])
//			{
//				if (q[j].back() > Max)
//				{
//					Max = q[j].back();
//					index = j;
//				}
//
//				flag = 1;
//			}
//		}
//
//		if (flag == 1)
//		{
//			q[index].push(num[i]);
//		}
//		else
//		{
//			q[cnt++].push(num[i]);
//		}
//
//	}
//
//	cout << (cnt + 1);
//	return 0;
//}
