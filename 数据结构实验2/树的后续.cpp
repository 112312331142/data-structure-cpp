//#include <stdio.h>
//#include <stdlib.h>
//
//
//typedef struct TreeNode									//树的结构
//{
//	char data;											//数据域char类型
//	struct TreeNode* Lchild;							//左孩子
//	struct TreeNode* Rchild;							//右孩子
//	int flag;
//}TreeNode;
//
//typedef struct stackNode								//队列的结构
//{
//	TreeNode* data;										//data使用指针更好指向树的节点
//	struct stackNode* next;								//next下一指针域
//}stackNode;
//
//void creatTree(TreeNode** node, char* data, int* index)
//{
//	char temp;
//	temp = data[*index];
//	*index += 1;
//	if (temp == '#')
//	{
//		*node = NULL;
//	}
//	else
//	{
//		*node = (TreeNode*)malloc(sizeof(TreeNode));
//		(*node)->data = temp;
//		(*node)->flag = 0;
//		creatTree(&((*node)->Lchild), data, index);
//		creatTree(&((*node)->Rchild), data, index);
//	}
//}
//
//stackNode* initStack(void)
//{
//	stackNode* stack = (stackNode*)malloc(sizeof(stackNode));	//开辟对stack空间
//	stack->data = NULL;											//data指向的节点为NULL
//	stack->next = NULL;											//next下一指针域也是nULL
//	return stack;
//}
//
//void push(TreeNode* treedata, stackNode* stack)
//{
//	stackNode* node = (stackNode*)malloc(sizeof(stackNode));	//开创一个node节点
//	node->data = treedata;										//队列node的data指针指向树的节点
//	node->next = stack->next;									//node的next指向stack的next
//	stack->next = node;											//stack的next指向node
//}
//
//int isEmplt(stackNode* stack)
//{
//	if (stack->next == NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//stackNode* pop(stackNode* stack)
//{
//	if (isEmplt(stack))
//	{
//		return NULL;
//	}
//	else
//	{
//		stackNode* node = stack->next;						//进栈前判断不为空，创建node，node指向stack的next
//		stack->next = node->next;							//stack的next指向node的next，即指向node的next的next
//		return node;
//	}
//}
//
//stackNode* getTop(stackNode* stack)
//{
//	if (isEmplt(stack))
//	{
//		return NULL;
//	}
//	else
//	{
//		stackNode* node = stack->next;						//进栈前判断不为空，创建node，node指向stack的next
//		return node;
//	}
//}
//
//void lastOrder(TreeNode* tree)								//后序遍历
//{
//	TreeNode* node = tree;									//node获取tree
//	stackNode* stack = initStack();							//初始化队列stack
//	while (node || !isEmplt(stack))							//判断node是否为空或队列是否为空
//	{
//		if (node)											//如果node不为空
//		{
//			push(node, stack);								//入栈
//			node = node->Lchild;							//node指向node的左孩子
//		}
//		else
//		{
//			TreeNode* top = getTop(stack)->data;			//初始化top节点获取栈顶部data指向的树的节点位置
//			if (top->Rchild && top->Rchild->flag == 0)		//如果此时的top节点的右孩子不为空并且top的右孩子节点的状态没有被访问过
//			{
//				top = top->Rchild;							//top指向top的右孩子
//				push(top, stack);							//入栈
//				top = top->Lchild;							//top指向top的左孩子
//			}
//			else
//			{
//				top = pop(stack)->data;						//如果top的右孩子为NULL，则出栈
//				printf("%c", top->data);					//打印出栈节点的data
//				top->flag = 1;								//并且对此节点的flag值置一
//			}
//		}
//	}
//}
//
//void main(void)
//{
//	char data[] = "ABD#F##E##C##";
//	int index = 0;
//	TreeNode* tree;
//	creatTree(&tree, data, &index);
//	lastOrder(tree);
//	printf("\n");
//}
//
