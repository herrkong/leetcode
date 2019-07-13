#include <iostream>
#include <vector>

using namespace std;



class SuDO
{
public:
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

};



