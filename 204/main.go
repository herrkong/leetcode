package main

import (
	"fmt"
)

// 查找所有素数n

func PrintSlice(data []int){
	for _,d := range data{
		fmt.Printf("%v,",d)
	}
	fmt.Printf("\n")
}


func countPrimes(n int) int {
	if n < 3{
		return 0
	}
	var (
		is_prime  bool
		count  int
	)
	count = 1
	for i:=3 ; i < n ; i++{
		if i % 2 == 0{
			continue
		}
		is_prime = true 
		// 减少循环次数 j++ --> j = j + 2 不用检查偶数
		for j:= 3 ; j * j <= i  ;j++{
			if  i%j == 0 {
				is_prime = false
				break
			}
		}
		if is_prime{
			count++
		}
	}
	return count
}

func main() {
	
	fmt.Printf("countPrimes=%d\n",countPrimes(688843))
	
}