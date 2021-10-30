// 我们提供了一个类：

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// 三个不同的线程 A、B、C 将会共用一个 Foo 实例。

// 一个将会调用 first() 方法
// 一个将会调用 second() 方法
// 还有一个将会调用 third() 方法
// 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。

// 线程同步 协程同步


// 	每一个线程在完成之后 通知下一个线程 waitgroup 

//  多线程共享一个变量 每个线程争夺锁 mutex 

package main

import (
	//"fmt"
	"sync"
	"log"
)

// mutex 
var (
	Max int
	GoCount int
)

//有序打印
func PrintSyncMutex(goCount int , Max int ){
	
	lock := sync.Mutex{}
	// wg 等待协程退出
	wg := sync.WaitGroup{}
	count := 0
	result := make([]int,0,Max)

	wg.Add(goCount)
	for i:= 0;i < goCount ; i++{
		go func(i int){
			lock.Lock()
			count = count + 1 
			result = append(result, count)
			log.Printf("worker=%d,now=%d\n",i,count)
			defer lock.Unlock()
			wg.Done()
		}(i)
	}
	wg.Wait()
}


func main() {
	PrintSyncMutex(5,100)
}
