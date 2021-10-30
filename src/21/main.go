package main

import (
	"fmt"
)

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 // 

 func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	prehead := new(ListNode)
	pre := prehead
	for ;l1 != nil && l2 != nil;{
		if l1.Val < l2.Val{
			pre.Next = l1
			l1 = l1.Next
		}else{
			pre.Next = l2
			l2 = l2.Next
		}
		pre = pre.Next
	}

	//最后剩余直接连接
	if l1 == nil{
		pre.Next = l2
	}else{
		pre.Next = l1
	}

	return prehead.Next
}


// func CompareNode(node1 * ListNode,node2 *ListNode) *ListNode{
// 	if node1 == nil || node2 == nil{
// 		return nil
// 	}
// 	if node1.Val >= node2.Val{
// 		return node1
// 	}
// 	return node2
// }

// func findNthMin(head * ListNode,lenList int,n int) (int,bool){
// 	if lenList < n{
// 		return -1,false
// 	}
// 	pcnt := head
// 	nth_min := 0
// 	count := 0
// 	for ;pcnt != nil;pcnt = pcnt.Next{
// 		if count == n{
// 			return pcnt.Val,true
// 		}
// 		count++
// 	}
// 	return -1,false
// }


// 尾插法链表
func createLinkListtail(head *ListNode) *ListNode{
	tail := head
	elems := []int{2,4}
	for i:=0;i<len(elems);i++{
		node := new(ListNode)
		node.Val = elems[i]
		tail.Next = node
		tail = node
	}
	tail.Next = nil
	return head
}

func createLinkListtail2(head *ListNode) *ListNode{
	tail := head
	elems := []int{7}
	for i:=0;i<len(elems);i++{
		node := new(ListNode)
		node.Val = elems[i]
		tail.Next = node
		tail = node
	}
	tail.Next = nil
	return head
}

func Print(head * ListNode){
	for ;head!= nil;head = head.Next{
		fmt.Printf("head.Val=%v\n",head.Val)
	}
}

func main(){
	L := new(ListNode)
	L.Val = 1

	L1 := createLinkListtail(L)

	L2 := new(ListNode)
	L2.Val = 3
	L3 := createLinkListtail2(L2)

	Print(L1)
	Print(L3)

	L4 := mergeTwoLists(L1,L3)
	Print(L4)


	// Print(L1)
	// Print(L3)

}