#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<std::vector<float> > vvec_f;
typedef std::vector<float> vec_f;

int main() {
    std::vector<std::vector<float> > random;
    vec_f update;

    std::vector<float> stuff1 = {8,4,2,1};
    std::vector<float> stuff2 = {5,1,2,7};
    std::vector<float> stuff3 = {5,1,1,4};

    random.push_back(stuff1);
    random.push_back(stuff2);
    random.push_back(stuff3);

    size_t size = random.size();

    for (int y = 0; y < 4; y++){
        vec_f v_temp;

        for (int x = 0; x < size; x++) {
            v_temp.push_back(random[x][y]);

            //std::cout << "[" << x << "]" << "[" << y << "]\n";

        }
        std::sort(v_temp.begin(), v_temp.end());
        float val_x = v_temp[(v_temp.size()/2) - 1];
        float val_y = v_temp[(v_temp.size()/2)];

        std::cout << "x: " << val_x << "\n";
        std::cout << "y: " << val_y << "\n\n";

        update.push_back(((val_x + val_y) / 2.0));
    }

    //std::sort(stuff.begin(), stuff.end());

    //std::cout << update[0] << "\n";
    //std::cout << update[1] << "\n";
    //std::cout << update[2] << "\n";

    return 0;
}
