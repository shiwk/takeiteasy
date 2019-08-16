//
// Created by swk on 2019-03-24.
//

#ifndef CPP_LTC_MINHEAPNODE_HPP
#define CPP_LTC_MINHEAPNODE_HPP

#endif //CPP_LTC_MINHEAPNODE_HPP

class node{
public:
    node(): value(-1) {

    }

    bool operator >(const node& node) const{
        return this->value > node.value;
    }

    bool operator <(const node& node) const {
        return this->value < node.value;
    }

    bool operator ==(const node& node) const{
        return this->value == node.value;
    }

    bool operator <=(const node& node) const{
        return value < node.value || value == node.value;
    }

    bool operator >=(const node& node) const{
        return value > node.value || value == node.value;
    }

    int getValue(){
        return value;
    }
    node(int value, int index) : value(value){}
private:
    int value;
};