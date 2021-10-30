#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

class Solution
{
public:
    char * reverseString(char * str)
    {
        int len = strlen(str);
        for(int i = 0 ;i <len/2 ;i++)
        {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
        return str ;
    }

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
};

int main()
{
   // Solution test ;
   // vector<char> s{"HONGKONG"}; //Error
   // 下面没有\0 只能当作字符数组处理 
   //如果有\0 可以当作字符串处理 可以直接打印
    //vector<char> s = {'H','O','N','G','K','O','N','G'};
   // test.reverseString(s);
   // for(auto ch:s)
   // {
       // cout<<ch;
   // }
    
    //测试
    char  str1[9] = {'H','O','N','G','K','O','N','G','\0'};
    char  str2[8] = {'H','O','N','G','K','O','N','G'};
    cout<<"str1="<<str1<<endl;
    //下面会发生错误 找到\0 它才停止
    cout<<"str2="<<str2<<endl;
    
    
    return 0 ;




#if 0   
    char str[] = "FcSchalke04";
    int len = strlen(str);//11
    cout<<"strlen(str)="<<len<<endl;
    for(int i = 0 ;i < len;i++)
    {
        cout<<"str["<<i<<"]="<<str[i]<<",";
    }
    cout<<endl;
    char * p =  test.reverseString(str);
    cout<<p<<endl;
    return 0;
#endif
}

