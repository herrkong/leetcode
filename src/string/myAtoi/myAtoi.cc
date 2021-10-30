#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
#if 0
    int myAtoi(string str)
    {
        //字符串判空
        int len = str.length();
        string newstr;
        if(0 == len)
            return 0 ;
        for(int i = 0 ;i<len;i++)
        {
            char ch = str[i];
            //如果是负号
            if(ch == '-')
            {
                while(isdigit(str[i+1]) && i<len)
                {
                    newstr.push_back(str[i+1]);
                    i++;
                }
            }
            //如果是数字
            else if(isdigit(ch))
            {
                while(isdigit(str[i+1]) && i <len)
                {
                    newstr.push_back(str[i+1]);
                    i++;
                }
            }
            

        } 
        
    }
#endif

    int myAtoi(string str)
    {
        //使用stringstream来读取数字
        //erase(index,count)
        //erase(str.begin(),str.end())
        //while(str.front()==' ') str.erase(0,1);
        while(*str.begin()==' ') str.erase(str.begin());
        if(str.size()==0) return 0;
        stringstream ss;
        ss<<str;
        int n ;
        ss>>n;
        printf("%d\n",n);
        return n;
    }

};









int main()
{
#if 0 //sb
    string str1="  ";//2个空格
    string str2=" ";//一个空格
    cout<<"str1.size()="<<str1.size()<<endl
        <<"str2.size()="<<str2.size()<<endl;
    if(str1==str2)
        cout<<"nb"<<endl;
    else
        cout<<"sb"<<endl;
#endif

#if 1
    Solution test;
    string str = "  04shal ke04";
    int ret = test.myAtoi(str);
    cout<<"ret="<<ret<<endl;
#endif
    return 0;
}

