package main

import (
	"fmt"
)

//删除链表的倒数第 n 个结点，并且返回链表的头结点。
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */


type ListNode struct {
	Val  int
	Next *ListNode
}

//增加pre指针
//删除倒数第n个节点 先搞删除正数第n个节点
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	//正数是第几个
	pcnt := head
	len := 0
	for ; pcnt != nil;pcnt = pcnt.Next{ 	
		len++
	}
	m := len - n 

	//正数删除
	old_head := head
	temp := head
	pre := temp
	count := 0
	for ;head != nil; head = head.Next{
		if n == 0 || len == 1 || m == 0{	
			return head.Next
		}

		if count == m && m != 0{
			pre.Next = temp.Next
			return old_head
		}
		pre = temp
		temp = temp.Next
		count++
	}
	return old_head

}


//逆序遍历链表
func reversePrint(head * ListNode){
	
}

func Print(head * ListNode){
	for ;head!= nil;head = head.Next{
		fmt.Printf("head.Val=%v\n",head.Val)
	}
}

//头插法建立链表 
func insertListhead(head * ListNode) *ListNode{
	temp := head
	for i:= 1 ; i < 10 ; i++{
		node := new(ListNode)
		node.Val = i
		node.Next = temp 
		temp = node 
	}
	return temp
}

//尾插法建立链表
func insertListtail(head * ListNode) *ListNode{
	tail := head
	for i:= 2 ; i < 3 ; i++{
		node := new(ListNode)
		node.Val = i
		tail.Next = node
		tail = node 
	}
	return head
}





func main() {


	L := new(ListNode)
	L.Val = 1
	L.Next = nil
	L = insertListtail(L)
	Print(L)

	
	L1 := removeNthFromEnd(L,2)
	Print(L1)	

}
