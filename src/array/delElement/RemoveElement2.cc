//删除数组中重复的元素
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class RemoveElement
{
public:
    int delElement(vector<int> & nums)
    {
        //如果vector中存储的是自定义的结构体或者类
        //就需要重载运算符
       
        //首先将数组排序
        sort(nums.begin(),nums.end());
        //再去除重复元素
        //unique返回指向被删除元素的迭代器
        auto it = unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        
        for(auto & num:nums)
        {
            cout << num <<" ";
        }

        return nums.size();
    }
};


int main()
{
    vector<int> nums{1,2,3,1,2,3,3,4,5,4,5,6,7};
    RemoveElement test;
    int ret = test.delElement(nums);
    cout<<endl<<"ret= "<<ret<<endl;
    return 0;
}

