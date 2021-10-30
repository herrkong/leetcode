package main

import (
	//"fmt"
	"log"
)

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
//nums = [1,2,1,3,2,5]
//[3,5]


// 136是 只有1个元素出现1次 

// 全部做异或运算 最后只会剩下 x = x1^x2 

// x&-x  求出x的二进制表示中最低位的那个1  设为第l位 
// 分为两类 一类是 l位为1的 一类是 l位为0的  x1  x2 

// 出现了两次的会在一个类中  只出现了一次的 x1 x2不会在一类

//分别对两类做异或 找到x1 x2 


func main() {
	defer func(){
		if errs := recover();errs!=nil{
			log.Println(errs)
		}
	}()

	nums := []int{1,2,1,3,2,5}
	x1 :=0
	x2 :=0
	x := 0
	// x = x1^x2
	for i:= 0 ; i< len(nums) ; i++{
		x = x^nums[i]
	}

	log.Println(x)
	
	lsb := x&(-x)

	log.Println(lsb)

	for i:= 0; i<len(nums);i++{
		if lsb&nums[i] > 0{
			x1 = x1^nums[i]
		}else{
			x2 = x2^nums[i]
		}
	}

	log.Println(x1,x2)
	

	// x := 5

	// y := x&(-x)

	// log.Println(y)





}