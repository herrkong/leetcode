#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rotate
{
public:
    void rotate(vector< vector<int> > & matrix )
    {
        //旋转矩阵

        //先求转置矩阵 再翻转每一行
        int len = matrix.size();
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = i ; j < len ; j++)
            {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j] ;
                matrix[i][j] = temp ;                
            }
        }
        
        for(int i = 0 ;i < len ; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }    

    }
};




int main()
{
    Rotate test ;
    //二维数组初始化
    vector<vector<int>> nums = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
#if 0
    for(int i = 0;i<3;i++)
    {
        for(int j = 0; j<3 ;j++)
        {
            nums[i][j]= i+j;
            cout<<"nums["<<i<<"]"<<"["<<j<<"]="<<nums[i][j]<<endl;
        }
    }
#endif
    test.rotate(nums);
    cout<<"After rotate"<<endl;
    for(int i = 0 ;i<3;i++)
    {
        for(int j = 0 ;j<3;j++)
        {
             cout<<"nums["<<i<<"]"<<"["<<j<<"]="<<nums[i][j]<<endl;
        }
    }
    return 0;
}

