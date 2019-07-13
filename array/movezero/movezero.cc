#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //暴力的方法
    void moveZero(vector<int> & nums)
    {
        int count = 0 ;
        if(nums.size()==1) return ;
        for(auto it = nums.begin() ; it != nums.end() ; it++)
        {
            if(*it == 0)
            {
                nums.erase(it);
                count++ ;
            }
        }

        for(int i = 0 ;i < count ; i++)
        {
            nums.push_back(0);
        }
    }

    //双指针
    void moveZero_2(vector<int> & nums)
    {
        int i = 0 ;
        int count = 0 ;
        //删除指定元素 删除所有的零元素 并记录删了几个
        for(size_t j = 0 ; j<nums.size() ; j++)
        {
            if(nums[j]!=0)
            {
                nums[i] = nums[j];
                i++;
            }
            else
            {
                count++;
            }

        }
        //在末尾加上零
        for(int idx =0 ; idx<count;idx++)
        {
            nums[i+idx] = 0 ;
        }
    }
};


int main()
{
    vector<int>  nums{0,1,0,3,12};
    Solution test;
    test.moveZero_2(nums);
    for(auto & num:nums)
    {
        cout<<num<<",";
    }
    return 0;
}

