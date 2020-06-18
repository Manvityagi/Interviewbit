
#include <bits/stdc++.h>

int cap;
unordered_map<int, int> mp;
list<int> lst;

LRUCache::LRUCache(int capacity)
{
    mp.clear();
    lst.clear();
    cap = capacity;
}

int LRUCache::get(int key)
{
    if (mp.find(key) != mp.end())
    {
        //key ko list ke end me leke jaao
        auto it = find(lst.begin(), lst.end(), key);
        lst.splice(lst.end(), lst, it);
        return mp[key];
    }
    return -1;
}

void LRUCache::set(int key, int value)
{

    if (mp.find(key) != mp.end())
    {
        //ye key list me jaha bhi hai, usey bas front me rakhna hai
        lst.remove(key);
        lst.push_back(key);
    }
    else
    {
        if (lst.size() >= cap)
        {
            //remove the first elt from list
            int eltTobeRemoved = lst.front();
            lst.pop_front();

            //also delete this elt from mp
            mp.erase(eltTobeRemoved);
        }

        lst.push_back(key);
    }

    mp[key] = value;
}