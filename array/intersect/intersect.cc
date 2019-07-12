#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> & nums1,vector<int> & nums2)
    {
       //暴力法 
       for(size_t i = 0;i<nums1.size();i++)
       {
           for(size_t j = 0 ;j<nums2.size();j++)
           {
               if(nums1[i]==nums2[j])
                   
           }
       }

    }


};




int main()
{
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    Solution test;
    auto vec = test.intersect(nums1,nums2);
    for(auto num:vec)
    {
        cout<<num<<" ";
    }
    return 0;
}

