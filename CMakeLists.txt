cmake_minimum_required(VERSION 3.21)
project(s21_MultilayerPerceptron)

set(CMAKE_CXX_STANDARD 17)

add_executable(s21_MultilayerPerceptron
                src/matrix/s21_matrix.cpp
                src/matrix/s21_matrix.h
                src/matrix/s21_support_func.cc
                src/model/network.h
                src/model/neuron.cc
                src/model/neuron.h
                src/model/graph_network.cc
                src/model/graph_network.h
                src/model/matrix.cc
                src/model/matrix.h
                main.cpp
        )
