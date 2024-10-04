//#include <iostream>
//using namespace std;
//
//// 定义链表节点
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//// 快速选择算法
//ListNode* quickSelect(ListNode* head, int k) {
//    if (!head)
//        return nullptr;
//    if (!head->next)
//        return head;
//
//    // 将链表分成小于和大于pivot的两部分
//    ListNode* pivot = head;
//    ListNode* smaller = new ListNode(0); // 头节点
//    ListNode* larger = new ListNode(0); // 头节点
//    ListNode* smallerTail = smaller;
//    ListNode* largerTail = larger;
//
//    ListNode* current = head->next;
//    while (current) {
//        if (current->val < pivot->val) {
//            smallerTail->next = current;
//            smallerTail = smallerTail->next;
//        }
//        else {
//            largerTail->next = current;
//            largerTail = largerTail->next;
//        }
//        current = current->next;
//    }
//
//    // 将左右两部分连接起来
//    smallerTail->next = nullptr;
//    largerTail->next = nullptr;
//
//    // 计算左边部分的长度
//    int smallerLength = 0;
//    ListNode* temp = smaller->next;
//    while (temp) {
//        smallerLength++;
//        temp = temp->next;
//    }
//
//    // 根据k与左边部分的长度关系决定继续查找的位置
//    if (k <= smallerLength) {
//        return quickSelect(smaller->next, k);
//    }
//    else if (k == smallerLength + 1) {
//        return pivot;
//    }
//    else {
//        return quickSelect(larger->next, k - smallerLength - 1);
//    }
//}
//
//// 示例用法
//int main() {
//    ListNode* head = new ListNode(3);
//    head->next = new ListNode(1);
//    head->next->next = new ListNode(4);
//    head->next->next->next = new ListNode(2);
//    head->next->next->next->next = new ListNode(5);
//
//    int k = 3;
//    ListNode* result = quickSelect(head, k);
//    if (result)
//        cout << result->val << endl;  // 输出: 3
//
//    // 释放链表内存
//    while (head) {
//        ListNode* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    return 0;
//}