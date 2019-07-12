#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Spinarray
{
public:

    //暴力法 每次挪动一步 挪k次 超时
    void rotate(vector<int> & nums,int k)
    {
        int previous,temp ;

        for(int i = 0 ;i < k ; i++)
        {
            previous = nums[nums.size()-1];

            for(size_t j = 0 ; j < nums.size() ; j++)
            {
                temp = nums[j];
                nums[j] = previous;
                previous = temp ;
            }    
        }
    }
    
    //反转数组 reverse
    
    void rotate_2(vector<int> & nums,int k)
    {
        if(size_t(k) > nums.size())  k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    

};


int main()
{
    vector<int> nums{1,2,3,4,5,6,7};
    Spinarray test ;
    int k = 3;
   // test.rotate(nums,k);
   test.rotate_2(nums,k);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    return 0;
}

