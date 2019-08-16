//
// Created by swk on 2019-07-19.
//

#include "linkmap.h"
#include "sha.h"
#include "hex.h"

namespace happycoding{

    template <typename K, typename V>
    linkmap<K,V>::linkmap(const int size) {
        slot_size = size;
        count = 0;
        slots = std::vector<node<K,V>*>(slot_size);
        head = nullptr;
        tail = nullptr;
    }

    template <typename K, typename V>
    int linkmap<K,V>::hash(K k) const{
        CryptoPP::SHA256 sha256;
        CryptoPP::byte digest[ CryptoPP::SHA256::DIGESTSIZE ];
        sha256.CalculateDigest( digest, reinterpret_cast<CryptoPP::byte*>(&k), sizeof(k) );
        auto hash_res = CryptoPP::Integer(digest, CryptoPP::SHA256::DIGESTSIZE);
        int index = hash_res % slot_size;
        return index;
    }

    template <typename K, typename V>
    void linkmap<K,V>::add(K k, V v) {
        auto nNode = new node<K,V>(k, v);
        add(nNode);
    }

    template <typename K, typename V>
    void linkmap<K,V>::add(node<K, V>* n) {
        int index = hash(n->k);
//        std::cout << std::endl << "SHA" <<"(" << n->k << "): " << index << std::endl;
        if(count == 0)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head -> prev = n;
            head = n;
        }

        if (slots[index] == nullptr)
        {
            slots[index] = n;
        }
        else
        {
            if(slots[index] -> k == n->k)
            {
//                slots[index] -> v = n->v;
                n -> next_slot = slots[index]->next_slot;
                slots[index]->next_slot->prev_slot = n;
                slots[index] = n;
                return;
            }

            node<K,V>* pNode = slots[index];
            while (pNode-> next_slot != nullptr)
            {
                if(pNode->next_slot->k == n->k)
                {
                    n->next_slot = pNode->next_slot->next_slot;
                    n->prev_slot = pNode;
                    pNode->next=n;
                    if(n->next_slot!= nullptr)
                        n->next_slot->prev_slot=n;
                    return;
                }
                pNode = pNode -> next_slot;
            }
            pNode -> next_slot = n ;
            n->prev_slot = pNode;
        }
    }

    template <typename K, typename V>
    V linkmap<K,V>::get(K k){
        auto nptr = get_node(k);
        if(nptr != nullptr)
            return nptr -> v;

        V *v = new V();
        return *v;
    }

    template <typename K, typename V>
    node<K,V>* linkmap<K,V>::get_node(K k) {
        int index = hash(k);

        node<K,V>* p = slots[index];


        while (p != nullptr)
        {
            if(p->k == k)
                return p;

            p = p->next_slot;
        }

        return nullptr;
    }

    template <typename K, typename V>
    V& linkmap<K,V>::operator[](K k) {
        auto nptr = get_node(k);
        if(nptr == nullptr)
        {
            node<K,V>* n = new node<K,V>(k);
            add(n);
            return n -> v;
        }
        return nptr -> v;
    }

    template <typename K, typename V>
    void linkmap<K,V>::remove(K k) {
        int index = hash(k);

        node<K,V>* p = slots[index];


        while (p != nullptr)
        {
            if(p->k == k)
                break;

            p = p->next_slot;
        }

        if(p == slots[index])
            slots[index] = nullptr;
        else if (p != nullptr) {
            auto prev_slot = p -> prev_slot;
            auto next_slot = p -> next_slot;

            if ( prev_slot != nullptr)
            {
                prev_slot -> next_slot = next_slot;
            }

            if (next_slot != nullptr)
            {
                next_slot -> prev_slot = prev_slot;
            }
        }
    }
}


