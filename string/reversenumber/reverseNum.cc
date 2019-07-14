#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std ;

class Solution
{
public:
        int reverse(int x)
        {
            
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
    return 0;
}

