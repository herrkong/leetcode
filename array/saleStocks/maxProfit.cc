#include <iostream>
#include <vector>

using namespace std;

class SaleStock
{
public:
    int maxProfit(vector<int> & price )
    {
        if(!price.size()) 
            return 0 ;
        //找波峰peak和波谷valley
        int count = 0 ;
        size_t i = 0 ;
        int total = 0 ;
        int peak = price[0];
        int valley = price[0];
        while(i  < price.size()-1)
        {
            while(i < price.size()-1 && price[i+1]<=price[i])
                i++;
            valley = price[i];
            count++ ;
            cout<<"valley"<<count<<"="<<valley<<endl ;
            while(i < price.size()-1 && price[i+1]>price[i])
                i++;
            peak = price[i];
            cout<<"peak"<<count<<"="<<peak<<endl;
            total += (peak - valley) ;
        }
        return total ;
    }
};


int main()
{
    vector<int>  price{7,1,5,3,6,4,2,3,2,6,3} ;    
    SaleStock test;
    int ret = test.maxProfit(price);
    cout<<"ret = "<<ret<<endl;
    return 0;
}

