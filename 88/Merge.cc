#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std ;

class Solution
{

   static  bool cmp(int a,int b)
    {
        if(a >= b) //由小到大排序
            return false ;    
        else
            return true ;
    }

public:
    void merge(vector<int> & nums1,vector<int> & nums2 )
    {
        //STL vector insert() 连接两个vector
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        //algorithm 的sort() 自定义比较规则 默认就是由小到大
        sort(nums1.begin(),nums1.end(),cmp);    
        //去掉所有指定范围元素 这里去掉0
        auto it = nums1.begin();
        for(;it!=nums1.end();)
        {
            if(*it == 0)
                nums1.erase(it);
            else
                it++;
         }
    }
};


int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution solution ;
    solution.merge(nums1,nums2);
    for(auto & num : nums1)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

