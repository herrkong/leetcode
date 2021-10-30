#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <math.h>

using namespace std ;

class Solution
{
public:
        int reverse(int x)
        {
           //考虑-号和最后一位为0 
           //先反转 最后再排除
           //数字转字符串
           if(x==0) return 0;
           string str = to_string(x);
           int len = str.size();
           for(int i = 0 ;i < len/2 ;i++)
           {
                char temp = str[i];
                str[i] = str[len-1-i];
                str[len-1-i]=temp;
           }
           cout<<"str="<<str<<endl;
           char ch = str[len-1];
           cout<<"ch="<<ch<<endl;
           char headch = str[0];
           cout<<"headch="<<headch<<endl;
           while(headch=='0')
           {
               str.erase(0,1);
               headch=str[0];
           }
           if(ch == '-')
           {
               str.pop_back();
               str.insert(0,1,'-');
           }
           cout<<"str="<<str<<endl;
           long y=stol(str);
           cout<<"y="<<y<<endl;
           long max = pow(2,31)-1;
           long min = -pow(2,31);
           if( y>max || y<min)
               return 0 ;
           return y ; 
        }



#if 0 
    int reverse(int x)
    {
        //数字转字符串
        string str = to_string(x);
        if(str.front() == '-')
        {
            str = str.substr(1,str.size());
            auto vec = turnVec(str);
            reverseString(vec);
            turnint(vec);

        }
        else
        {

        }
    
    }

    int turnint(vector<char> & s)
    {
        
    }

    vector<char>  turnVec(string str)
    {
        vector<char> vec ;
        for(auto & ch:str)
        {
            vec.push_back(ch);
        }
        return vec ;
    }

    //利用刚写好的反转字符串    
    void reverseString(vector<char> & s)
    {
        int len = s.size();
        cout<<"s.size()="<<len<<endl;
        for(int i = 0 ;i < len/2 ;i++)
        {
            char temp = s[i];
            s[i] = s[len -1 - i];
            s[len -1 - i] = temp ;
        }
    }

#endif

};



int main()
{
    Solution test ;
    int x= 1534236469;
    int y = test.reverse(x);
    cout<<"y = "<<y<<endl;
    return 0;
}

