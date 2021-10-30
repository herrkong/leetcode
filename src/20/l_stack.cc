#include <iostream>
#include <stdio.h>
#include <stack>
#include <set>
#include <string>
using namespace std;

//很明显用栈
//不指定容器的类型 默认就是双端队列deque
//

class Solution
{
public:
    bool isValid(string & s);
};

bool Solution::isValid(string & s)
{   

    stack<char> mystack;
    mystack.push('#');
    for(auto & c:s)
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
    
    mystack.pop();
    if(!mystack.empty())
        return false;
    return true;
}


int main()
{
    Solution solution;
    string s;
    getline(cin,s);
    if(solution.isValid(s))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

