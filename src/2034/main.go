package main

import (
	//"log"
	"fmt"
)

/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */

type  StockPrice struct {
}


func (p *StockPrice) update(timestamp int ,price int ){

	fmt.Printf("update timestamp=%d,price=%d\n",timestamp,price)
}

func (p * StockPrice) current() (current int){

	fmt.Printf("current=%d\n",current)
	return current
}

func (p * StockPrice) maximum() (highest int){

	fmt.Printf("highest=%d\n",highest)
	return highest
}

func (p * StockPrice) minium() (lowest int){

	fmt.Printf("lowest=%d\n",lowest)
	return lowest
}


func main() {
	p := new(StockPrice)
	p.update(1,10)
	p.update(2,5)
	p.maximum()
	p.minium()
	p.current()


}