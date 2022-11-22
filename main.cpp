#include "src/model/matrix.h"
#include <vector>
#include "src/model/reader.h"
#include "src/controller/controller.h"
int main() {
    s21::Controller temp;
    temp.set_net(s21::NetworkType::MATRIX, 2);
    std::cout << "Hello World!" << std::endl;
    return 0;
}
