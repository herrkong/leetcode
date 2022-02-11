#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <list>
#include<semaphore.h>

using namespace std;

class H2O {
public:
    H2O():cntH(0) {
        sem_init(&H_done,0,0);
        sem_init(&O_done,0,2);
    }
    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&O_done);
        cntH++;
        releaseHydrogen();
        if(cntH==2){
            sem_post(&H_done);
        }
    }
    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&H_done);
        releaseOxygen();
        cntH=0;
        sem_post(&O_done);
        sem_post(&O_done);
    }

public:
    sem_t H_done,O_done;
    int cntH;
};

int main() {

    return 0;
}