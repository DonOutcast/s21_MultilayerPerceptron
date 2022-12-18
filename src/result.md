# Research

*Network parameters*

|     _layer_   |_number of Neurons_| 
| ------------- |:-----------------:|
| input layer   |        784        |
| Hidden layer 1|        140        |
| Hidden layer 2|        140        |
| Hidden layer 3|        140        |
| Hidden layer 4|        140        |
| Output layer  |         26        |


| Network |    10 runs   |    100 runs   |    1000 runs   |
| --------|  --------|  ---------|:----------:|
| Matrix  |    201 sec  |    2010 sec  |    20100 sec  |
| Graph   |    391 sec   |   3910 sec  |    39101 sec  |



# Заключение
Можно было бы много чего сказать но я просто устал
1. Скорость алгоритма FeedForward - O(n^2) для графовой и матричной сети
2. Скорость алгоритма BackPropogation - O(n^3) для графовой и матричной сети
