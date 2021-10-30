package main

import (
	//"fmt"
	"sync"
	"log"
)

// 按序打印
var(
	Max int = 10 // 协程数
	Count int = 0  // 计数器
)

func main() {
	defer func(){
		if errs := recover();errs != nil{
			log.Println(errs)
		}
	}()
	wg := sync.WaitGroup{}
	//result := []int{}
	Mutex  := sync.Mutex{}
	wg.Add(Max)
	for i:=0;i< Max;i++{
		go func(){
			Mutex.Lock()
			Count = Count + 1
			//result = append(result, Count)
			log.Println(Count)
			defer Mutex.Unlock()
			wg.Done()
		}()
	}
	wg.Wait()

	//log.Println(result)
	
}