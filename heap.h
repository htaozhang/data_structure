//
//  heap.h
//  heap
//
//  Created by htaoZhang on 16/4/7.
//  Copyright © 2016年 htaoZhang. All rights reserved.
//

#ifndef __heap_h
#define __heap_h

#include <vector>

#define PARENT(i) ((i) >> 1)
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)

template<typename T>
class heap 
{
public:
    Heap()
    {
        
    }
    explicit Heap(int size)
        : size_(size)
    {
        
    }
    bool push(const T &e)
    {
        elements_.push_back(e);
        ++size_;
        shift_up(size_);
        return true;
    }
    void pop()
    {
        elements_.front() = elements_.back();
        elements_.pop_back();
        --size_;
        shift_down(0);
        return true;
    }
    
    T top() 
    { 
        return elements_.front(); 
    }
    
private:
    bool compare(const T &lhs, const T &rhs)
    {
        return true;
    }
    
    void swap(T& lhs, T&rhs) 
    {
        T tmp = lhs; lhs = rhs; rhs = tmp;
    }
    
    // 往上堆化
    void shift_up(int i)
    {
        
    }
    // 往下堆化
    void shift_down(int i)
    {
        
    }
    
    bool heapify(int pos)
    {
        int l = pos << 1;
        int r = l + 1;
        int target = pos;
        
        if (l < size_ && compare(elements_[l], elements_[pos]))
            target = l;
        if (r < size_ && compare(elements_[r], elements_[target]))
            target = r;
        
        if (target != pos)
        {
            swap(elements_[pos], elements_[target]);
            heapify(target);
        }
        
        return true;
    }
    
private:
    vector<T> elements_;
    size_t size_;
};

#endif /* __heap_h */


