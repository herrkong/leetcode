#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> & nums1,vector<int> & nums2)
    { 
        unordered_map<int,int> dict;
        vector<int> res;
        
        //遍历num1 存储到词典
        for(auto num:nums1)
        {
            dict[num]++;
        }

        //遍历nums2 
        for(auto val:nums2)
        {
            //字典中有这个数
            if(dict.count(val))
            {
                res.push_back(val);
                //res中push一个 dict中相应--一个
                dict[val]--;
                if(dict[val]==0)
                    dict.erase(val);
            }
        }
        return res ;
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

