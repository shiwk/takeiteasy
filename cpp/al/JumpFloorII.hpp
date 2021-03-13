//
// Created by shiwk on 2021/3/12.
//

#ifndef CPP_JUMPFLOORII_HPP
#define CPP_JUMPFLOORII_HPP
class JumpFloorII{
    int jumpFloorII(int number) {
        if (number<=2)
            return number;
        int res=0;
        for (int i = 0;i<number;i++)
        {
            res+=jumpFloorII(i);
        }
        return res+1;
    }
};
#endif //CPP_JUMPFLOORII_HPP
