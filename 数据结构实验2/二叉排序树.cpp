//#include<iostream>
//using namespace std;
//
//#define MaxSize 100
//typedef int KeyType;//关键字类型
//typedef char InfoType;
//typedef struct BiTNode {
//	KeyType key;//关键字项
//	InfoType data;//其他类型，在实验中并没有用到
//	struct BiTNode* lchild, *rchild;//左右孩子指针
//}BSTNode;
//
//BSTNode* InsertBST(BSTNode* root, KeyType s) {//插入关键字为k的结点
//	if (root == NULL) {//原数为空时，新建结点
//		root = new BSTNode;
//		root->key = s;
//		root->lchild = root->rchild = NULL;
//	}
//	else if (s < root->key)//插入左子树
//		root->lchild = InsertBST(root->lchild, s);
//	else if (s > root->key)//插入右子树
//		root->rchild = InsertBST(root->rchild, s);
//	return root;
//}
//
//BSTNode* CreateBST(KeyType a[], int n) {//创建二叉排序树
//	BSTNode* bt = nullptr;
//	int i = 0;
//	while (i < n) {
//		bt = InsertBST(bt, a[i]);//将关键字a[i]插入二叉排序数中
//		i++;
//	}
//	return bt;
//}
//
//BSTNode* f;//全局结点f，用于指向p的双亲结点
//BSTNode* SearchBST(BSTNode* bt, KeyType k) {//非递归查找
//	BSTNode* p = bt;
//	cout << p->key << " ";
//	while (p != NULL) {
//		if (p->key == k)
//			break;
//	    f = p;
//		if (k < p->key) {
//			p = p->lchild;
//			cout << p->key << " ";
//		}
//		else {
//			p = p->rchild;
//			cout << p->key << " ";
//		}
//	}
//	return p;//返回查找到的结点
//}
//
//void DeleteBST(BSTNode*&p) {//删除查找到的结点p
//	BSTNode* q;
//	if (p->lchild == NULL && p->rchild == NULL) {//p为叶子结点时
//		if (f->lchild == p)
//			f->lchild = NULL;
//		else
//			f->rchild = NULL;
//		free(p);
//	}
//	else if (p->lchild == NULL) {//p只有右孩子时
//		if (f->lchild == p)
//			f->lchild = p->rchild;
//		else
//			f->rchild = p->rchild;
//		free(p);
//	}
//	else if (p->rchild == NULL) {//p只有左孩子时
//		if (f->lchild == p)
//			f->lchild = p->lchild;
//		else
//			f->rchild = p->lchild;
//		free(p);
//	}
//	else {//p左右孩子都有时
//        BSTNode *s = p->rchild;//指向p的右孩子结点
//		BSTNode *par = p;//指向s的双亲结点
//		while (s->lchild != NULL) {
//			//查找结点p的右子树上的最左下结点s以及结点s的双亲结点par
//			par = s;
//			s = s->lchild;
//		}
//		p->key = s->key;//将结点s数据域替换到被删结点p的数据域
//		if (p->rchild->lchild == NULL) {
//			//若结点p的右孩子无左子树，则将s的右子树接到par的右子树上
//			par->rchild = s->rchild;
//		}
//		else {//将s的右子树接到结点par的左子树上
//			par->rchild = s->rchild;
//		}
//		free(s);
//	}
//}
//
//void DispBST(BSTNode* bt) {//以括号表示法输出二叉排序树
//	if (bt != NULL) {
//		cout<< bt->key;
//		if (bt->lchild != NULL || bt->rchild != NULL) {
//			cout<<"(";
//			DispBST(bt->lchild);
//			if (bt->rchild != NULL)
//				cout << ",";
//			DispBST(bt->rchild);
//			cout<<")";
//		}
//	}
//}
//
//int main() {
//	BSTNode* bt,*p;
//	KeyType k ;
//	cout << "输入想要查找删除的结点关键字的值(根结点4除外)：" ;
//	cin >> k;
//	int path[MaxSize];
//	int a[] = { 4,9,0,1,8,6,3,5,2,7 }, n = 10;
//	cout << "(1)创建一颗BST树：";
//	bt=CreateBST(a, n);
//	DispBST(bt);
//	cout << endl;
//	cout << "(2)查找" << k << "关键字顺序：";
//	p=SearchBST(bt, k);
//	cout << endl;
//	cout << "(3)删除" << k << "关键字：";
//	DeleteBST(p);
//	DispBST(bt);
//	cout << endl;
//	return 0;
//}