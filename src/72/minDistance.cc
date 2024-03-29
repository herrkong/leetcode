#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 最小编辑距离
class Solution
{
public:
    int minDistance(string word1,string word2)
    {
        int m = word1.length();
        int n = word2.length();
        
        //m+1行 n+1列
        vector<vector<int>>  cost(m+1,vector<int>(n+1));

        for(int i=0;i<=m;++i)
        {
            cost[i][0] = i;
        }

        for(int j=0;j<=n;++j)
        {
            cost[0][j]= j;
        }

        for(int i=1; i<=m ;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1] == word2[j-1])
                {
                    cost[i][j] = cost[i-1][j-1];
                }
                else
                {
                    cost[i][j] = 1 + min(cost[i-1][j-1],min(cost[i][j-1],cost[i-1][j]));
                }
            }
        }
        return cost[m][n];
    }
}; 


int main()
{
    Solution solution;
    string word1="herrkong";
    string word2 ="hongkong";
    int ret = solution.minDistance(word1,word2);
    cout<<"从"<<word1<<"到"<<word2<<"最少需要"<<ret<<"次变换."<<endl;
    return 0;
}















