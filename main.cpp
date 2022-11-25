#include "src/model/matrix.h"
#include <vector>
#include "src/model/reader.h"
#include "src/controller/controller.h"
int main() {
    s21::Controller temp;
    temp.set_net(s21::NetworkType::MATRIX, 2);
    temp.get_weights("2_h.txt");
    return 0;
}
