//
// Created by shiwk on 2021/3/9.
//

#ifndef CPP_NRVO_HPP
#define CPP_NRVO_HPP

#include <iostream> // std::cout/endl
#include <utility> // std::move
using namespace std;
class Obj {
public:
    Obj()
    {
        cout << "Obj()" << endl;
    }
    Obj(const Obj&)
    {
        cout << "Obj(const Obj&)"
             << endl;
    }
    Obj(Obj&&)
    {
        cout << "Obj(Obj&&)" << endl;
    }

    ~Obj(){
        cout << "~Obj()" << endl;
    }
};

Obj arg(Obj obj)
{
    return Obj();
}

Obj simple()
{
    Obj obj;
    // NRVO
    return obj;
}
Obj simple_with_move()
{
    Obj obj;
    // move bans NRVO
    return std::move(obj);
}
Obj complicated(int n)
{
    Obj obj1;
    Obj obj2;
    if (n % 2 == 0) {
        return arg(obj1);
    } else {
        return obj2;
    }
}



#endif //CPP_NRVO_HPP
