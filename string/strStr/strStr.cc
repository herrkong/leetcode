#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack,string needle)
    {
        int ret = haystack.find(needle);
        return ret ;
    }



#if 0
    int strStr(string haystack,string needle)
    {
        //寻找指定子串
        //KMP算法——字符串模式匹配
        //这里先写简单模式匹配
        int len1=haystack.size();
        int len2=needle.size();
        int i = 0;
        int j = 0;
        if(len2==0) return 0 ;
        if(len2>len1) return -1 ;
        while( i < len1 && j < len2 )
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
                j=0;
            }
        }
        if(i==len1 && j==0) return -1;
        return i - j;
    }
#endif 


};



int main()
{
    Solution test;
    string haystack ="mississippi";
    string needle = "issip";
    int ret = test.strStr(haystack,needle);
    cout<<"ret = "<< ret <<endl;
    return 0;
}

