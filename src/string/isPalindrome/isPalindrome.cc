#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
       //去掉空格标点符号 全部变为小写
       //正序=逆序
       vector<char> vec;
       int len = s.size();
       char ch ;
       int i = 0 ;
       while(i<len)
       {
           ch = s[i];
           //如果是大写字母变小写
           if(isupper(ch))
           {
               ch = tolower(ch);
           }
           if(isalnum(ch))
           {
               vec.push_back(ch);
           }
           i++;
       }//while
       auto vec2 = vec ;
       reverse(vec2.begin(),vec2.end());
       if(vec == vec2)
           return true;
       else
           return false ;

    }
};






int main()
{
    Solution test ;
    string str = "A man, a plan, a canal: Panama";
    bool flag = test.isPalindrome(str);
    cout<<"flag = "<<flag<<endl;
    return 0;
}

