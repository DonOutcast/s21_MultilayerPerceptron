#include <iostream>
#include <vector>
#include <fstream>
#include <random>

int main(void) {
    std::mt19937 gen;
    std::vector<double> weights(5);
    for (size_t i = 0; i< 5; i++)
        weights[i] = ((int)gen() % 1000) * 0.0001;
    for (auto j : weights)
        std::cout << j << std::endl;

    return 0;
}

