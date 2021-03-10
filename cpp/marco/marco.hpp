//
// Created by shiwk on 2021/2/22.
//

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MILLI_SECONDS_PER_YEAR (1000 * 60 * 60 * 365UL)
#define SUB1(X, Y) X-Y
#define SUB2(X, Y) (X-Y)
#define OFFSET_ASSIGN(D, O, V) (*SUB2(&D, O)=V)

#include <iostream>

extern int Static_A;
auto Statcic_B = Static_A; // dynamic initialized

class Marco{
public:
    void funcMarco();
    void objMarco();
    static void multiMarco();
};

void Marco::funcMarco() {
    std::cout << MIN(1, 2) << std::endl;
}

void Marco::objMarco() {
    std::cout << MILLI_SECONDS_PER_YEAR << std::endl;
}

void Marco::multiMarco() {
    int arr[3] = {1, 2, 3};
    for (int i : arr) {
        std::cout << i << std::endl;
    }

    std::cout << "================" << std::endl;
    OFFSET_ASSIGN(arr[1], 1, -1);
    for (int i : arr) {
        std::cout << i << std::endl;
    }
}