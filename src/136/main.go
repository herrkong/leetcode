package main

import (
	"fmt"
)

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

//[2,2,1]
// 1

// 异或 XOR  0 0 = 0   1 1 = 0  相同的数异或得0 一个数与0异或 总是这个数本身 存在交换律
// 或 OR    1 0 = 1   1 1 = 1
// 与 AND    1 1 = 1

func main() {
	nums := []int{2,2,1,1,3,5,6,7,7,5,4,4,3,}
	ret := 0
	for i:= 0 ; i< len(nums) ;i++{
		ret = nums[i]^ret
	}
	fmt.Println(ret)
}