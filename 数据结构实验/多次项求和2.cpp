//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//#define OK 1
//#define ERROR 0
//
//typedef int Status;
//
//typedef struct
//{
//    int coef;//系数
//    int expn;//指数
//}term, ElemType;
//
//typedef struct Node
//{
//    ElemType elem;
//    struct Node* next;
//}Node, * LinkList;
//
//typedef LinkList polynomial;
//
//Status InitList(polynomial*);//0_1、初始化链表
//Status push_node_head(polynomial*, ElemType);//0_2_1、头插法插入多项式的项
//Status sameExpn_list_addCoef(polynomial*, ElemType);//0_2_2、将要插入的相同，链表中有相同项
//Status find_list_by_expn(polynomial, int);//0_3、从链表中查找是否有相同的指数项
//Status sort_by_expn(polynomial*);//0_4、对已经创建好的一元多项式按指数大小进行排序进行
//
////0_5、比较指数值的大小
///*
//    a < b,返回 -1
//    a = b,返回 0
//    a > b,返回 1
//*/
//int cmp(term, term);
//
////声明函数
//Status CreatPolyn(polynomial*, int);//1、输入m项的系数和指数，建立表示一元多项式的有序链表P
//
//Status DestoryPolyn(polynomial*);//2、销毁一元多项式P
//
//Status PrintPolyn(polynomial);//3、打印输出一元多项式P
//
//int PolynLength(polynomial);//4、返回一元多项式P中的项数
//
//Status AddPolyn(polynomial*, polynomial*);//5、完成多项式相加运算，即：Pa=Pa+Pb,并销毁Pb
//
////0_1、初始化链表
//Status InitList(polynomial* P)
//{
//    *P = (polynomial)malloc(sizeof(Node));
//    if (!P) {
//        printf("初始化失败,请重新操作.\n");
//        return ERROR;
//    }
//    (*P)->next = NULL;
//    return OK;
//}
//
////0_2_1、头插法插入多项式的项(没有相同项)
//Status push_node_head(polynomial* P, ElemType e)
//{
//    polynomial p;
//    p = *P;
//    polynomial s;
//    s = (polynomial)malloc(sizeof(Node));
//    s->elem = e;
//    s->next = p->next;
//    p->next = s;
//    return OK;
//}
//
////0_2_2、将要插入的相同，链表中有相同项，对应系数相加
//Status sameExpn_list_addCoef(polynomial* P, ElemType e)
//{
//    polynomial p;
//    p = (*P)->next;
//    while (p) {
//        if (p->elem.expn == e.expn) {
//            p->elem.coef += e.coef;
//        }
//        p = p->next;
//    }
//    return OK;
//}
//
////0_3、从链表中查找是否有相同的指数项
//Status find_list_by_expn(polynomial P, int expn)
//{
//    if (!P->next) {
//        return OK;
//    }
//    polynomial p;
//    p = P->next;
//    int i;
//    i = 0;
//    while (p) {
//        if (p->elem.expn == expn) {
//            return ERROR;//有相同项
//        }
//        i++;
//        p = p->next;
//    }
//    if (i == PolynLength(P)) {
//        return OK;//没有相同项
//    }
//    return OK;
//}
//
////0_4、对已经创建好的一元多项式按指数大小进行排序进行(采用冒泡排序)
//Status sort_by_expn(polynomial* P)
//{
//    polynomial s;
//    polynomial p;
//    polynomial q;
//    int length;//结点个数
//    length = PolynLength(*P);
//    int i, j;
//    for (i = 0; i < length - 1; i++) {//外层循环
//        j = length - 1 - i;
//        s = *P;//指向表头
//        p = (*P)->next;
//        q = p->next;
//        while (j--) {//内层循环
//            if (q->elem.expn < p->elem.expn) {
//                //交换结点
//                p->next = q->next;
//                s->next = q;
//                q->next = p;
//            }
//            s = s->next;
//            p = s->next;
//            q = p->next;
//        }
//    }
//    return OK;
//}
//
////0_5、比较指数值的大小
///*
//    a < b,返回 -1
//    a = b,返回 0
//    a > b,返回 1
//*/
//int cmp(term pa, term pb)
//{
//    if (pa.expn < pb.expn) {
//        return -1;
//    }
//    if (pa.expn == pb.expn) {
//        return 0;
//    }
//    if (pa.expn > pb.expn) {
//        return 1;
//    }
//    return -1;
//}
//
////1、输入m项的系数和指数，建立表示一元多项式的有序链表P
//Status CreatPolyn(polynomial* P, int m)
//{
//    //初始化链表
//    InitList(P);
//    int flag;
//    int i;
//    for (i = 1; i <= m; i++) {
//        //当前要插入的结点
//        ElemType cur_elem;
//        printf("请输入第%d项的系数和指数(用逗号隔开):", i);
//        scanf("%d,%d", &(cur_elem.coef), &(cur_elem.expn));
//        //查找功能
//        flag = find_list_by_expn(*P, cur_elem.expn);
//        //插入功能
//        /*如果链表中有这一项，系数相加*/
//        if (flag == 0) {
//            sameExpn_list_addCoef(P, cur_elem);
//        }
//        /*如果链表中没有这一项，插入新节点*/
//        if (flag == 1) {
//            push_node_head(P, cur_elem);
//        }
//    }
//    sort_by_expn(P);
//    return OK;
//}
//
////2、销毁一元多项式P
//Status DestoryPolyn(polynomial* P)
//{
//    polynomial p;
//    p = *P;
//    polynomial q;
//    while (p->next) {
//        q = p->next;
//        p->next = q->next;
//        free(q);
//    }
//    free(P);
//    P = NULL;
//    return OK;
//}
//
////3、打印输出一元多项式P
//Status PrintPolyn(polynomial P)
//{
//    printf("一元多项式 P = ");
//    Node* p;
//    p = P->next;
//    while (p) {
//        if (!p->next) {
//            printf("%d*X^%d", p->elem.coef, p->elem.expn);
//        }
//        else
//        {
//            printf("%d*X^%d+", p->elem.coef, p->elem.expn);
//        }
//        p = p->next;
//    }
//    return OK;
//}
//
////4、返回一元多项式P中的项数
//int PolynLength(polynomial P)
//{
//    Node* p;
//    p = P->next;
//    int length;
//    length = 0;
//    while (p) {
//        length++;
//        p = p->next;
//    }
//    return length;
//}
//
////5、完成多项式相加运算，即：Pa=Pa+Pb,并销毁Pb
//Status AddPolyn(polynomial* Pa, polynomial* Pb)
//{
//    /*
//        a < b,返回 -1
//        a = b,返回 0
//        a > b,返回 1
//    */
//    Node* pa;//Pa的工作结点
//    Node* pb;//Pb的工作结点
//    Node* pa_prior;//始终是pa的直接前驱
//    Node* temp;//需要释放的结点
//    pa = (*Pa)->next;
//    pb = (*Pb)->next;
//    pa_prior = (*Pa);
//    int flag;//记录cmp的结果
//    int e;//记录指数相同时，系数的和
//    while (pa && pb) {//有一个为空就跳出循环
//        flag = cmp(pa->elem, pb->elem);
//        if (flag == -1) {//pa小
//            pa = pa->next;
//            pa_prior = pa_prior->next;
//        }
//        if (flag == 0) {//指数相同的项
//            e = pa->elem.coef + pb->elem.coef;
//            temp = pb;
//            (*Pb)->next = pb->next;
//            pb = (*Pb)->next;
//            free(temp);
//            if (e == 0) {
//                //释放pa
//                temp = pa;
//                (*Pa)->next = pa->next;
//                pa = (*Pa)->next;
//                free(temp);
//            }
//            if (e != 0) {
//                pa->elem.coef = e;
//            }
//        }
//        if (flag == 1) {//pb小
//            (*Pb)->next = pb->next;
//            pb->next = pa;
//            pa_prior->next = pb;
//            pa_prior = pb;
//            pb = (*Pb)->next;
//        }
//    }
//    if (pb) {
//        pa_prior->next = pb;
//        (*Pb)->next = NULL;
//    }
//    return OK;
//}
//
//int main()
//{
//    while (1) {
//        polynomial P=NULL;
//        polynomial Pa;
//        polynomial Pb;
//        int input;
//        int m;//项数
//        int ma, mb;
//        int length;//项数
//        printf("\n==========================\n");
//        printf("1、建立有序多项式链表.\n");
//        printf("2、销毁多项式.\n");
//        printf("3、打印多项式.\n");
//        printf("4、返回项数.\n");
//        printf("5、两个多项式相加.\n");
//        printf("\n==========================\n");
//        printf("请输入对应操作的序号:\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case 1:
//            printf("请输入需要创建的多项式项数(m):");
//            scanf("%d", &m);
//            CreatPolyn(&P, m);
//            break;
//        case 2:
//            DestoryPolyn(&P);
//            printf("成功销毁一元多项式P.\n");
//            break;
//        case 3:
//            PrintPolyn(P);
//            break;
//        case 4:
//            length = PolynLength(P);
//            printf("该一元多项式的项数为 %d.\n", length);
//            break;
//        case 5:
//            printf("请创建第1个一元多项式Pa:\n");
//            printf("请输入需要创建的多项式项数(m):");
//            scanf("%d", &ma);
//            CreatPolyn(&Pa, ma);
//            printf("请创建第2个一元多项式Pa:\n");
//            printf("请输入需要创建的多项式项数(m):");
//            scanf("%d", &mb);
//            CreatPolyn(&Pb, mb);
//            AddPolyn(&Pa, &Pb);
//            printf("相加之后,");
//            PrintPolyn(Pa);
//            break;
//        default:
//            printf("输入的序号有误,请重新输入...\n");
//            break;
//        }
//    }
//    return 0;
//}