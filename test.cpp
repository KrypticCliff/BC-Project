#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<float> > random;

    std::vector<float> stuff1 = {4,3,2,1};
    std::vector<float> stuff2 = {5,1,2,7};
    std::vector<float> stuff3 = {5,1,1,4};

    random.push_back(stuff1);
    random.push_back(stuff2);
    random.push_back(stuff3);


    std::cout << random[0].size() << "\n";

    return 0;
}
