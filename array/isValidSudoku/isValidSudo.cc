#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SuDO
{
public:
#if 0
    bool isValidSudoku(vector<vector<char>> & board)
    {
        int row[9][9] = {{0}};//行记录
        int col[9][9] = {{0}};//列记录
        int squ[3][3][9] = {{{0}}};//九宫格记录
        int temp ;
        for(int i = 0 ;i <9 ;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    temp = int(board[i][j]-'1');
                    if(++row[i][temp]>1) return false ;
                    if(++col[temp][j]>1) return false ;
                    if(++squ[i/3][i/3][temp]>1) return false ;
                }
            }
        }
        return true;
    }
#endif
    //每一行 每一列 每一3X3子块都不能有相同的元素
    bool isValidSudoku(vector<vector<char>> & board)
    {
        vector< map<char,int> > block(9);
        for(int i = 0 ;i < 9 ; i++)
        {
            map<char,int> row ,col ;
            for(int j = 0 ; j < 9 ; j++)
            {
                //检测行
                if(board[i][j] != '.' && ++row[board[i][j]] > 1)
                    return false ;
                //检测列
                if(board[j][i] != '.' && ++ col[board[j][i]]> 1)
                    return false ;
                //检测子块
                if(board[i][j] != '.' && ++block[i/3*3+j/3][board[i][j]] > 1)
                   return  false ; 
            }
        }
        return true ;
    }
};



