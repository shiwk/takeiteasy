//
// Created by shiwk on 2021/3/10.
//

#ifndef CPP_SHARE_PTR_HPP
#define CPP_SHARE_PTR_HPP

template <typename T>
class Node
{
public:
    Node(const T& value)
            :_pPre(NULL)
            , _pNext(NULL)
            , _value(value)
    {
        cout << "Node()" << endl;
    }
    ~Node()
    {
        cout << "~Node()" << endl;
        cout << "this:" << this << endl;
    }

    shared_ptr<Node<T>> _pPre;
    shared_ptr<Node<T>> _pNext;
    T _value;
};
#endif //CPP_SHARE_PTR_HPP
