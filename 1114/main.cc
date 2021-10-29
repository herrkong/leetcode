#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <pthread.h>
#include <unistd.h>
#include <thread>

using namespace std;

#define Max  100
#define ThreadsNum 5


// 多线程 有序打印
void PrintOrderMultiThreads(){
    // 条件变量
    std::condition_variable cond;
    // mutex
    std::mutex lock;

    bool flag = false;

    int count = 0;

    for (int i = 0 ; i < ThreadsNum ; i++){
        std::unique_lock<std::mutex> lk(lock);
        count = count + 1;
        flag = true;
        printf("count=%d\n",count);
        while(!flag){
            cond.wait(lk);
        }
        cond.notify_one();
    }
}


int main() {
    std::thread  t1(PrintOrderMultiThreads);
    std::thread  t2(PrintOrderMultiThreads);
    t1.join();
    t2.join();

   // PrintOrderMultiThreads(Max,ThreadsNum);
    return 0;
}
