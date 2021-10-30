#include <iostream>
#include <stdio.h>
#include <stack>
#include <set>
#include <string>
using namespace std;

//很明显用栈
//不指定容器的类型 默认就是双端队列deque
// 有效的括号


string get() //这里返回引用会出错 因为函数调用结束 局部变量会被清除
{
    cout<<"Please Enter char in the range of"<<endl 
        <<"{'('，')','{'，'}'，'['，']'}"<<endl;
    string str;
    getline(cin,str);
    //cout<<"---------------"<<endl;
   // cout<<str<<endl;
    return str;
}


bool test0()
{   

    stack<char> mystack;
    string str=get();
    for(auto & c:str)
    {
        // cout<<c<<"enter into stack"<<endl;

        if(isspace(c)) continue;
        if(c=='(' || c=='[' || c=='{')//左括号进栈
        {
            mystack.push(c);
        }
        if(c==')')//右括号 看栈顶元素是否匹配
        {
            if(mystack.top()=='('){
                mystack.pop();
                continue;
            }
            else
                return false;
        }
        if(c==']')
        {
            if(mystack.top()=='['){
                mystack.pop();
                continue;
            }
            else
                return false;
        }
        if(c=='}')
        {
            if(mystack.top()=='{'){
                mystack.pop();
                continue;
            }
            else
                return false;
        }
    }//for
    
     return true;
}

int main()
{
    while(1){ 
    if(test0()) 
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    }
}

