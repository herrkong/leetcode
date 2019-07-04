#include <iostream>
#include <vector>
using namespace std ;


class Solution
{
public:
    int removeElement(vector<int> & nums,int val)
    {
    
        //双指针法
        //一个快指针 一个慢指针 遇到相等元素 慢指针就跳过
        //快指针继续++  
        int i = 0 ;
        for(size_t j = 0 ;j < nums.size();j++)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++ ;
            }
        }

        return i ;
        
        
#if 0    
   
        //真！面向测试用例编程。。。。
        int total = nums.size();
        int count = 0 ;

        for(auto it = nums.begin();it!=nums.end();it++)
        {
            if(*it == val)
            {
                nums.erase(it);
                ++ count ;
                if(nums.size()==0)
                    return total - count ;
                it = nums.begin();
                //否则迭代器会失效
            }
        }

        return total - count ;
#endif

    
    
    }

};

int main()
{
    //测试用例1
   // vector<int>  nums = {3,2,2,3} ;
   // int val = 3 ;
  
   //测试用例2
   // vector<int> nums = {1};
   // int val = 1 ;
   
  // 测试用例3 
    vector<int>  nums = {3,3};
    int val = 3 ;

    Solution solution;
   
    int ret = solution.removeElement(nums,val);

    cout<<ret<<endl;

    return 0 ;

}
