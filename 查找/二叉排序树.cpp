#include"bst.cpp"
int main() {
	BSTNode* bt;
	int path[MaxSize];
	KeyType k = 6;
	int a[] = { 4,9,0,1,8,6,3,5,2,7 },n=10;
	printf("(1)创建一颗BST树：");
	printf("\n");
	bt = CreateBST(a, n);
	printf("(2)BST:"); DispBST(bt); printf("\n");
	printf("(3)bt%s\n", (JudgeBST(bt) ? "是一颗BST" : "不是一颗BST"));
	printf("(4)查找%d关键字（递归，顺序）：", k); SearchBST1(bt, k, path, -1);
	printf("(5)查找%d关键字（非递归，逆序）：", k); SearchBST2(bt, k);
	printf("\n(6)删除操作：\n");
	printf("   原BST："); DispBST(bt); printf("\n");
	printf("   删除结点4：");
	DeleteBST(bt, 4); DispBST(bt); printf("\n");
	printf("   删除结点5：");
	DeleteBST(bt, 5); DispBST(bt); printf("\n");
	printf("(7)销毁BST\n"); DestroyBST(bt);
	return 0;
}