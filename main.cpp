#include "src/model/matrix.h"
int main(void) {
    std::cout << "Hello World!" << std::endl;
    s21::MatrixNetwork tmp;
    tmp.set_layers_vector(1);
    tmp.set_layers(tmp.get_layers_vector());
    tmp.feed_forward();

    std::cout<< "Hello World 2" << std::endl;
    return 0;
}
