// class FooBar {
// 	public void foo() {
//       for (int i = 0; i < n; i++) {
//         print("foo");
//       }
// 	}

// 	public void bar() {
//       for (int i = 0; i < n; i++) {
//         print("bar");
//       }
// 	}
//   }
//   两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。

//   请设计修改程序，以确保 "foobar" 被输出 n 次。

package main

import (
	//"fmt"
	"fmt"
	"sync"
)

type FooBar struct{
	n int 
}


func(f * FooBar) foo(){
	for i:=0;i<f.n;i++{
		fmt.Print("foo")
	}
}

func(f * FooBar) bar(){
	for i:=0;i<f.n;i++{
		fmt.Print("bar")
	}
}

func main() {
	defer func(){
		if errs:=recover();errs!=nil{
			fmt.Println(errs)
		}
	}()

	f := new(FooBar)

	f.n = 10
	
	wg := sync.WaitGroup{}

	wg.Add(f.n)

	Lock := sync.Mutex{}

	for i:=0 ;i<f.n;i++{
		go func(f * FooBar){
			Lock.Lock()
			f.foo()
			f.bar()
			fmt.Print("\n")
			defer Lock.Unlock()
			wg.Done()
		}(f)
	}
	wg.Wait()

}