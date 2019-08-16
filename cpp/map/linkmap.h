//
// Created by swk on 2019-07-19.
//

#ifndef CPP_LTC_LINKMAP_H
#define CPP_LTC_LINKMAP_H

#include <vector>

template <typename K, typename V>
struct node {
    K k;
    V v;
    node* next;
    node* prev;
    node* next_slot;
    node* prev_slot;

public:
    explicit node(K k) : k(k){
        next_slot = nullptr;
        prev_slot = nullptr;
        next = nullptr;
        prev = nullptr;
    }

    node(K k, V v): k(k), v(v){
        next_slot = nullptr;
        prev_slot = nullptr;
        next = nullptr;
        prev = nullptr;
    }
};


namespace happycoding{
    template <typename K, typename V>
    class linkmap {
    public:
        struct Deref;
        void add(K k, V v);
        V get(K k);
        void remove(K k);
        // operator[]
        explicit linkmap(int slot_size);
        V operator[] ( K k) const;
        V& operator[](K k);
    private:
        int count;
        std::vector<node<K,V>*> slots;
        int slot_size;
        node<K,V>* head;
        node<K,V>* tail;
        node<K,V>* get_node(K k);
        int hash(K k) const;
        void add(node<K,V>* n);
    };
}


#endif //CPP_LTC_LINKMAP_H
