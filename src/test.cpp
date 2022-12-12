#include <iostream>
#include <vector>
#include <fstream>
#include <random>

int main(void) {
    std::random_device rd_;
    std::mt19937  temp(rd_());
    std::mt19937 gen;
    gen = temp;
    std::vector<double> weights(5);
    for (size_t i = 0; i< 5; i++)
        weights[i] = ((int)gen() % 1000) * 0.0001;
    for (auto j : weights)
        std::cout << j << std::endl;

    return 0;
}

