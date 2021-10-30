#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int>  twoSum(vector<int> & nums,int target)
    {
        vector<int> vec;
        for(size_t i = 0 ;i < nums.size();i++)
        {
            for(size_t j = i+1 ; j < nums.size();j++)
            {
                if(nums[i] == target - nums[j])
                {
                    if(i!=j)
                    {
                        vec.push_back(i);
                        vec.push_back(j);
                        break;
                    }
                }
            }
        } 
        return vec;
    }
};

int main()
{
    Solution test;
    vector<int> nums{2,7,11,15};
    int target = 9;
    auto vec =  test.twoSum(nums,target);
    for(auto num:vec)
    {
        cout<<num<<",";
    }
    return 0;
}

