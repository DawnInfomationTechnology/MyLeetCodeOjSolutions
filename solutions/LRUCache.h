//
//  LRUCache.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 30/6/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_LRUCache_h
#define MyLeetCodeOjSolutions_LRUCache_h

#include <List>
#include <unordered_map>

struct LRUCacheNode
{
    int key;
    int value;
    LRUCacheNode( int k, int v):key(k), value(v){}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }
    
    int get(int key)
    {
        if( map_.find(key) == map_.end())
            return -1;
        else
        {
            list_.splice( list_.begin(), list_, map_[key]);
            map_[key] = list_.begin();
            return map_[key]->value;
        }
    }
    
    void set(int key, int value)
    {
        if( map_.find( key) == map_.end())
        {
            if( list_.size() == capacity_) // lru one item
            {
                map_.erase( list_.back().key);
                list_.pop_back();
            }
            
            LRUCacheNode node( key, value);
            list_.push_front(node);
            map_[key] = list_.begin();
        }
        else
        {
            map_[key]->value = value;
            list_.splice( list_.begin(), list_, map_[key]);
            map_[key] = list_.begin();
        }
    }
    
private:
    int capacity_;
    std::list<LRUCacheNode> list_;
    std::unordered_map<int,std::list<LRUCacheNode>::iterator> map_;
};

#endif
