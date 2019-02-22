#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::vector<float> > random;

    std::vector<float> stuff;
    // std::vector<float> stuff2 = {5,1,2,7};
    // std::vector<float> stuff3 = {5,1,1,4};

    stuff.push_back(2);
    stuff.push_back(4.1);
    stuff.push_back(1.4);
    // random.push_back(stuff2);
    // random.push_back(stuff3);

    std::sort(stuff.begin(), stuff.end());

    std::cout << stuff[0] << "\n";
    std::cout << stuff[1] << "\n";
    std::cout << stuff[2] << "\n";

    return 0;
}
