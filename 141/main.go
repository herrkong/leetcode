package main

import (
	"fmt"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

//  给定一个链表，判断链表中是否有环。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 如果链表中存在环，则返回 true 。 否则，返回 false 。

// 判断值和指向

//  双指针 pre pcnt  有环 会有两个pre 
 func hasCycle(head *ListNode) bool {
	// 慢指针步长为1 快指针步长为2
	slow := head 
	fast := head
	if slow == nil || slow.Next == nil || slow.Next.Next == nil{
		return false
	}

	for ;fast != nil;{
		slow = slow.Next
		if fast.Next == nil || fast.Next.Next == nil{
			return false
		}

		fast = fast.Next.Next
		if fast == slow {
			return true
		} 
	}

	return false
}


type ListNode struct {
	Val  int
	Next *ListNode
}

//尾插法创建链表 且让尾结点连接到第三个节点成环
func creatListtail(head * ListNode) *ListNode{
	tail := head 

	tag_node := new(ListNode)

	for i:=2 ; i < 6;i++{
		node := new(ListNode)
		node.Val = i
		tail.Next = node
		tail = node

		if i == 3 {
			tag_node = node
		}
	}

	tail.Next = tag_node

	return head
}

func Print(head * ListNode){
	count := 0
	for ;head!= nil;head = head.Next{
		if head.Val == 3{
			count++
		}
		if count == 3{
			break
		}
		fmt.Printf("head.Val=%v\n",head.Val)
	}
}


func main(){

	L := new(ListNode)
	L.Val = 1
	L1 := creatListtail(L)
	Print(L1)

	flag := hasCycle(L1)
	fmt.Printf("flag=%v\n",flag)


}