#include <iostream>
#include <map>
using namespace std ;

class Solution
{
public:
    bool isAnagram(string s,string t)
    {
        int len1=s.size();
        int len2=t.size();
        if(len1!=len2)
            return false ;
        map<char,int> smap ;
        map<char,int> tmap ;
        for(int i = 0 ;i<len1;i++)
        {
            char ch = s[i];
            ++smap[ch];
        }
        for(int j = 0 ;j<len2;j++)
        {
            char ch = t[j];
            ++tmap[ch];
        }
        for(int k = 0 ; k<len1;k++ )
        {
            char ch = s[k];
            if(smap[ch]!=tmap[ch])
                return false ;
        }
        return true ;
    }
};


int main()
{
    Solution test;
    string s = "hongkong";
    string t = "konghong";
    bool flag = test.isAnagram(s,t);
    cout<<"flag ="<<flag<<endl;
    return 0;
}

