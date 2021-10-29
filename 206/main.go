// 反转链表
package main

import (
	"fmt"
)

// class Solution {
// 	public:
// 		ListNode* reverseList(ListNode* head) {
// 			ListNode* cur = NULL, *pre = head;
// 			while (pre != NULL) {
// 				ListNode* t = pre->next;
// 				pre->next = cur;
// 				cur = pre;
// 				pre = t;
// 			}
// 			return cur;
// 		}
// 	};

type Node struct {
	Val  int
	Next *Node
}

func PrintLinkList(head *Node) {
	for ;head != nil;head = head.Next {
		fmt.Printf("head.Val=%d\n", head.Val)
	}
}

// 初始化链表
// 尾插法
func GetNewList(head *Node) *Node {
	temp := head
	for i := 2; i < 5; i++ {
		node := new(Node)
		node.Val = i
		node.Next = nil
		temp.Next = node
		temp = node
	}
	temp.Next = nil
	return head
}

// 反转链表
func ReverseLinkList(head *Node) *Node {

	return head
}

func main() {
	head := new(Node)
	head.Val = 1
	head = GetNewList(head)
	PrintLinkList(head)


}
