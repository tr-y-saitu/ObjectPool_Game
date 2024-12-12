#pragma once
#include "Common.h"

template <typename T>
class ObjectPool
{
public:
    ObjectPool(size_t initialSize) {
        for (size_t i = 0; i < initialSize; ++i) {
            objects.emplace_back(std::make_unique<T>());
            unused.push_back(objects.back().get());
        }
    }

    T* create() {
        if (unused.empty()) return nullptr;
        T* obj = unused.front();
        unused.pop_front();
        return obj;
    }

    void add(T* obj) {
        unused.push_back(obj);
        obj->active = false;
    }


    std::list<T*> unused;
    std::vector<std::unique_ptr<T>> objects;

};


