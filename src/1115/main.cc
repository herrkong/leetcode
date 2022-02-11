#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <thread>

using namespace std;

// 1  互斥锁

class FooBar {
public:
    FooBar(int n) {
        this->n = n;
        mutex2.lock();
    }

    void foo() {
        
        for (int i = 0; i < n; i++) {
            mutex1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mutex2.unlock();

        }
    }

    void bar() {
        
        for (int i = 0; i < n; i++) {
            mutex2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mutex1.unlock();
        }
    }

    void printFoo(){
        printf("foo");
    }

     void printBar(){
        printf("bar");
    }


private:
    int n;
    mutex mutex1,mutex2;

};

// 2  信号量


// 3  条件变量


int main() {
    FooBar * obj = new FooBar(5);

    // 开启两个线程 
    thread t1(obj->foo());

    t1.join();


    return 0;
}


 update user set password=password('darwin') where user='root' and host='localhost'; 


