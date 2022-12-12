#include "src/model/matrix.h"
#include <vector>
#include "src/model/reader.h"
#include "src/controller/controller.h"

int main() {
    s21::Controller temp;
    temp.set_net(s21::NetworkType::MATRIX, 2);
    std::cout << temp.load_weights("../2_h.txt") << std::endl;
//    temp.save_weights("tatar.txt");
    return 0;
}
