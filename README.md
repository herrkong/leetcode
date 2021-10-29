#### leetcode 

19 删除链表的倒数第N个节点
头插法 尾插法建立链表 

20 括号匹配 栈的应用

21 合并两个有序链表

27 就地删除数组元素 vector 双指针法

72 最小编辑距离    

88 合并两个有序数组 合并两个vector  STL vector

121 买卖股票的最佳时机

124 二叉树的最大路径和


127 单词接龙 BFS广度优先搜索

141 判断链表是否有环

146 LRUCache list unordered_map<>

204 查找所有素数n

206 反转链表

1114  线程同步 协程同步

c++ go
waitgroup + mutex
waitgroup wg.Wait() wg.Add() wg.Done() 
mutex lock.Lock()  defer lock.UnLock()



#### c++
##### array

26 就地删除重复元素 
直接用STL sort() unique() erase()做的

122 买卖股票的最佳时机  
利润最大化就是每次波谷买入波峰卖出

189 旋转数组
暴力法 一次挪一步 挪k次 超时
STL　reverse()

217 判断是否存在重复元素
方法一 暴力法 
时间复杂度 : O(n^2)
方法二 排序 

136 找到只出现了一次的数字 
先排序 如果在开头和中间找不到 那就是最后一个
这道题也可以用异或来做 详见具体的代码

350 两个数组的交集 
unordered_map 存储其中一个nums作为字典
遍历另外一个nums 如果字典中有 就push到vector res
同时字典中的dict[val]--   

66 加一  测试用例越来越大了 逼得转变思路

283 移动零  联系之前写的删除指定的元素

1 两数之和  暴力法  再补充更好的解决方法

36 有效的数独  二维数组 

48 旋转图像  二维数组 先求装置矩阵 再翻转每一行

###### string

344 反转字符串  注意字符串处理的一些细节
strlen() sizeof() str.size()/str.length()

7  整数反转  特殊情况最后来处理  stoi()/stol()   to_string()

387 字符串中第一个唯一字符 借助了一个map 判断是不是已经找过了的
if( n == string::npos )
{
    if(mymap[ch]<1)
        return i ;
}

242 有效的字母异位词  

8 字符串转换整数 (atoi) 利用stringstream来读取数字

28 实现strStr() 
int ret = haystack.find(needle);//hahahahahahahha






