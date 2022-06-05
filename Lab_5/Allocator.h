#pragma once
#include "MyPool.h"
#include <map>

struct MyAllAllocators {
    std::map<size_t, MyPool*> AllSizePoolPairs;

    MyAllAllocators(std::initializer_list<std::pair<size_t, size_t>> all){
          for (const auto & i : all){
            auto* new_pool = new MyPool(i.first, i.second);
            AllSizePoolPairs.insert(std::pair<size_t, MyPool*>(i.first, new_pool));
        }
    }

    ~MyAllAllocators(){
        for (auto i : AllSizePoolPairs){
            delete i.second;
        }
    }

    template<class T>
    friend class MyAllocator;
};

template<class T>
class MyAllocator{
private:
public:
    const MyAllAllocators* alloc;
    //MyPool* pool;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;

    template<class U>
    struct rebind {
        using other [[maybe_unused]] = MyAllocator<U>;
    };

    explicit MyAllocator(const MyAllAllocators& all_allocators){
        alloc = &all_allocators;
    }

    template<class U>
    explicit MyAllocator(const MyAllocator<U>& other){
        alloc = other.alloc;
      //  pool = other.pool;
    }

    [[maybe_unused]] pointer allocate(size_t n){
        return reinterpret_cast<pointer>(alloc->AllSizePoolPairs.at(sizeof(T))->allocate(n));
    }

    void deallocate(pointer ptr, size_t n){
        alloc->AllSizePoolPairs.at(sizeof(T))->deallocate(ptr,n);
    }

    friend bool operator==(const MyAllocator<T> first_alloc, const MyAllocator<T>& second_alloc){
        if (first_alloc.alloc->AllSizePoolPairs.at(sizeof(T)) == second_alloc.alloc->AllSizePoolPairs.at(sizeof(T))){
            return true;
        }
        return false;
    }

    friend bool operator!=(const MyAllocator<T> first_alloc, const MyAllocator<T>& second_alloc){
        if (first_alloc == second_alloc){
            return false;
        }
        return true;
    }
};