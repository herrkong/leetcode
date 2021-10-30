#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    int firstUniqChar(string s)
    {
        map<char,int> mymap;
        int len = s.size();
        for(int i = 0 ; i < len ;i++)
        {
            char ch = s[i];
            size_t n = s.find(ch,i+1);
            if( n == string::npos )
            {
                //判断是不是找过的 map中大于1
                if(mymap[ch] < 1)
                    return i;
            }
            else
            {
               ++mymap[ch];
            }
        } 
        return -1 ;
    }
};



int main()
{
    Solution test ;
    string s = "aadadaad";
    int index = test.firstUniqChar(s);
    cout<<"index ="<<index<<endl;
    return 0;
}

