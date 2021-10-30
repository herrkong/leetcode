// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

package main

import(
	"fmt"
	
)

// dp dynamic program
// 动态规划


//  决定在哪一天卖 找出今天之前的最小买价格 则是今天卖出的最大差价
//  比较所有最大差价
// [     ]
func maxProfit(prices []int) int {
	if len(prices) < 2{
		return 0
	}
	min := prices[0]
	max := 0
	for pos := 1 ;pos < len(prices);pos++{
		max = Max(max,prices[pos] - min)
		min = Min(prices[pos],min)
	}
	return max
}

func Min(x int , y int) int{
	if x <= y {
		return x
	}
	return y
}

func Max(x int,y int) int{
	if x >= y{
		return x
	}
	return y
}


func main(){
	prices := []int{7,1,5,3,6,4}
	max := maxProfit(prices)
	fmt.Printf("maxprofit=%d\n",max)
}