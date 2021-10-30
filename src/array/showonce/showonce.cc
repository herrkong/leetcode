#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class SingleNumber
{
public:
    int showonce(vector<int> & nums)
    { 
        //先排序 如果在开头和中间找不到 那就是最后一个
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        //注意数组的下标 越界问题
        for(size_t i =1 ;i < nums.size()-1; i++)
        {
            if(nums[i-1] != nums[i] && nums[i]!=nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};


int main()
{
    vector<int> nums{4,1,2,1,2};
    SingleNumber test ;
    int ret = test.showonce(nums);
    cout<<"ret = "<<ret <<endl;
    return 0;
}

