#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std ;


class Addone
{
public:
    vector<int> plusone(vector<int> & digits)
    {
       //把原来的数字拼成实际的数字再加1
       int k = digits.size();
       //改成了long
       //测试用例不断加大数字 目前的写法不适合了
       //[6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3]
       long num = 0 ;
       for(int i = 0 ;i<k;i++)
       {
           //从个位加到最高位
            num += digits.back() * pow(10,i);
            cout<<"num = "<<num<<endl;
            digits.pop_back();
       }
       //加1之后可能进位
       num++;
       cout<<"num="<<num<<endl;
       vector<int>  res ;
       while(num>=10)
       {
           int val = num % 10 ;//余数
           res.push_back(val);
           num /= 10 ;//商
       }
       res.push_back(num);
       reverse(res.begin(),res.end());
       return res ;
    }

    vector<int> plusone_2(vector<int> & digits)
    {
       int k = digits.size();
       for(int i = k -1 ;i>=0 ;i--)
       {
           if(9 == digits[i])
           {
               digits[i] = 0 ;
               if(k==0)
                   digits.insert(digits.begin(),1);
           }
           else
           {
               digits[i]++ ;
               break;
           }
       } 
       if(digits.front() == 0)
           digits.insert(digits.begin(),1);
       return digits;
    }
};



int main()
{
    Addone test;
    vector<int> digits{9,9};
    auto vec = test.plusone_2(digits);
    for(auto num:vec)
    {
        cout<<num<<",";
    }
    return 0;
}

