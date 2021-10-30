#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord,string endWord,
                     vector<string> & wordList);
    bool compare(string word1,string word2) const;


};

int Solution::ladderLength(string beginWord,string endWord,
                           vector<string> & wordList)
{

    int count=0;
    while(beginWord!=endWord)
    {
        for(auto it=wordList.begin();it!=wordList.end();it++)
        {
            cout<<"*it="<<*it<<endl; 
            if(!compare(beginWord,*it))
            {
              continue;  
            } 
            if(compare(beginWord,*it))
            { 
                beginWord=*it;
                cout<<"beginWord="<<beginWord<<endl;
                *it="###";
                ++count;
                cout<<"count="<<count<<endl;
            }
            if(beginWord==endWord) break;        
        }//for
        if(beginWord==endWord) break;        
    }//while
    return count;
}


bool Solution::compare(string word1,string word2) const
{
    int count=0;
    for(size_t idx=0;idx<word1.size();idx++)
    {
        if(word1[idx]==word2[idx]) continue;
        if(word1[idx]!=word2[idx]) ++count;
    }
    //if(count!=1)
    if(count>1)
        return false;
    else 
        return true;

}



int main()
{
    //测试compare()
#if 0
    Solution solution;
    string str1="hit";
    string str2="hot";
    int ret=solution.compare(str1,str2);
    cout<<"ret="<<ret<<endl;
#endif

#if 0
    string beginWord="hot", endWord="dog";
    vector<string>  wordList=
    {"hot","dog","dot"};
    Solution solution;
    int ret=solution.ladderLength(beginWord,endWord,wordList);
    cout<<"ret="<<ret<<endl;
#endif


#if 0
    string beginWord="hit", endWord="cog";
    vector<string>  wordList=
    {"hot","dot","dog","lot","log","cog"};
    Solution solution;
    int ret=solution.ladderLength(beginWord,endWord,wordList);
    cout<<"ret="<<ret<<endl;
#endif


#if 1
    string beginWord="hit", endWord="cog";
    vector<string>  wordList=
    {"hot","dot","dog","lot","log"};
    Solution solution;
    int ret=solution.ladderLength(beginWord,endWord,wordList);
    cout<<"ret="<<ret<<endl;
#endif

    return 0;
}

