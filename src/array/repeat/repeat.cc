#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Repeat
{
public:

    //超出时间限制
   // 暴力法  一个元素从头比较到尾部  n次 时间复杂度n^2
    bool repeat(vector<int> & nums)
    {
        for(size_t i = 0 ;i<nums.size();i++)
        {
            for(size_t j = i+1 ; j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                    return true;
                else
                    continue ;
            }
        }  
        return false ;
    }

    //排序法 排序之后重复元素会相邻
    bool repeat_2(vector<int> & nums)
    {
        //考虑只有一个数
        if(nums.size()<=1) return false ;
        sort(nums.begin(),nums.end());
        for(size_t i = 1 ;i <nums.size();i++)
        {
            //if(nums[i] == nums[i+1]) 数组越界
            if(nums[i-1]==nums[i])
                return true ;
        } 
        return false ;
    }

};


int main()
{
    vector<int> nums{3,1};
    Repeat test;
    auto ret = test.repeat_2(nums);
    if(ret)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}

