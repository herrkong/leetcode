#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 利用map有序 


// unordered_map






class StockPrice {
public:

    StockPrice():currtime(0) {}

public:
    void update(int timestamp, int price) {
        currtime=max(currtime,timestamp);
        // 该时间撮已有数据
        if(hash.count(timestamp)){
            int old_price=hash[timestamp];
            // 删除错误数据
            if(prices[old_price]==1){
                prices.erase(old_price);
            }else {
                prices[old_price]--;
            }
        }
        hash[timestamp]=price;
        prices[price]++;

    }
    
    int current() {
        printf("current=%d\n",hash[currtime]);
        return hash[currtime];
    }
    
    int maximum() {
        printf("highest=%d\n",(--prices.end())->first);
        return (--prices.end())->first;
    }
    
    int minimum() {
        printf("lowest=%d\n",prices.begin()->first);
        return prices.begin()->first;
    }

public:
    map<int,int> prices;
    unordered_map<int,int> hash;
    int currtime;
};


int main() {
    StockPrice * p = new StockPrice;
	p->update(1,10);
	p->update(2,5);
	p->maximum();
	p->minimum();
	p->current();
    return 0;
}

