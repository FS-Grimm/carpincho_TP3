//
// Created by valen on 3/12/2023.
//
#include "Random.hpp"


std::random_device rd;
std::mt19937 gen(rd());

int Random::random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return (dist(gen));
}