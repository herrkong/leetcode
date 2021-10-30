#include <stdlib.h>
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};

//  prehead pre 
ListNode * mergeTwoList(ListNode * l1, ListNode * l2){
    // 保存原头节点 好返回
    ListNode * prehead = new ListNode(-1);
    ListNode * pre = prehead;
    while(l1 != NULL && l2 != NULL){
        if (l1->val < l2->val){
            pre->next = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    // 还有一条链有剩余
    pre->next = l1 == NULL ? l2 : l1;
    return prehead->next;
}



// 尾插法建立单链表
ListNode * CrateLinkListTail1(ListNode* head){
    head->val = 2;
    ListNode * tail = head;
    for (int i= 3; i < 6 ; i++){
        ListNode * node = new ListNode;
        node->val = i;
        tail->next = node;
        tail = node;
    }
    return head;
}

ListNode * CrateLinkListTail2(ListNode* head){
    head->val = 1;
    ListNode * tail = head;
    for (int i= 2; i < 3 ; i++){
        ListNode * node = new ListNode;
        node->val = i;
        tail->next = node;
        tail = node;
    }
    return head;
}

void Print(ListNode * head){
    for (;head != NULL ; head = head->next){
        std::cout << "head.val=" << head->val << std::endl;
    }
}

int main(){
    ListNode * L1 = new ListNode;
    L1->val = 2;
    ListNode * L2 = new ListNode;
    L2->val = 1;
    L1 = CrateLinkListTail1(L1);
    L2 = CrateLinkListTail2(L2);

    Print(L1);
    Print(L2);

    // Solution * obj = new Solution;
    // ListNode * L3 = obj->mergeTwoLists(L1,L2);
    ListNode * L3 = mergeTwoList(L1,L2);
    Print(L3);
    return 0;
}