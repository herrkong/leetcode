#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    :_capacity(capacity)
    {
        cout<<"LRUCache()"<<endl;
    }

    int get(int key) ;
    void put(int key,int value);

    ~LRUCache()
    {
        cout<<"~LRUCache()"<<endl;
    }
private:
    size_t _capacity;//缓冲区容量
    list<pair<int,int>> _list;
    unordered_map<int,list<pair<int,int>>::iterator>  _m;
    //没有直接存键值对 存的指向它的迭代器
};

//hash查找
int LRUCache::get(int key)  
{
    auto it=_m.find(key);
    if(it==_m.end()) return -1;

    int val=it->second->second;
    _list.erase(it->second);
    _list.push_front(make_pair(key,val));
    _m[key] = _list.begin();
    return it->second->second;
}

//先查找key是否存在 存在则将其移动到首部 不存在，插入新的结点
//容量超过了 删除最后的节点
void LRUCache::put(int key,int value)
{
    auto it =_m.find(key);
    if(it!=_m.find(key))
    {
        _list.erase(it->second);
    }
    
    _list.push_front(make_pair(key,value));
    _m[key]= _list.begin();

    if(_list.size()>_capacity)
    {
        int key=_list.back().first;
        _m.erase(key);
        _list.pop_back();
    }
}



void test0()
{
    size_t capacity=5;
    LRUCache * obj=new LRUCache(capacity);
    obj->put(4,1);
    obj->put(5,4);
    obj->put(3,2);
    cout<<"get(4)="<<obj->get(4)<<endl;
    cout<<"get(3)="<<obj->get(3)<<endl;
}

int main()
{
    test0();
    return 0;
}

