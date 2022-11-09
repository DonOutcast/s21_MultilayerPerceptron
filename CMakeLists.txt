cmake_minimum_required(VERSION 3.21)
project(s21_MultilayerPerceptron)

set(CMAKE_CXX_STANDARD 17)

add_executable(s21_MultilayerPerceptron
                src/model/network.h
                src/model/neuron.cc
                src/model/neuron.h
                src/model/graph_network.cc
                src/model/graph_network.h
                main.cpp
        )
