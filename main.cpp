#include <iostream>
#include <vector>
#include "RandomGenerator.h"

int main() {

    bb::RandomGenerator::RandomGenerator<int, 0, 100> randomInt;
    std::cout << "Random Int Value : " << randomInt.GetRandomNumber() << "\n";

    std::vector<int> randomVector(10,0);
    randomInt.GetRandomNumber(randomVector);
    for(auto elem : randomVector) {
        std::cout << "Random Int Value : " << elem << "\n";
    }

    bb::RandomGenerator::RandomGenerator<double> randomDouble;
    std::cout << "Random Double Value : " << randomDouble.GetRandomNumber() << "\n";

    bb::RandomGenerator::RandomGenerator<char, 48, 100> randomChar;
    std::cout << "Random Char Value : " << randomChar.GetRandomNumber() << "\n";
    
    return 0;
}