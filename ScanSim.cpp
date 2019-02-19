#include "ScanSim.h"

#define N_VEC_LIST      5       // N Amount of Vectors
#define N_DIST_VALUE    5       // N Values of Distance Values in Vector
#define MIN_RAND        0.0     // Min Random Generate
#define MAX_RAND        60.0    // Max Random Generate

std::vector<float> scanGen() {
    std::vector<float> f_vec;

    // Random Generator Config
    srand(time(NULL));
    const float range = MAX_RAND - MIN_RAND;

    // Pushes Random Distance Values into f_vec
        for (int i = 0; i < N_DIST_VALUE; i++) {
            float random = range * ((((float) rand()) / (float) RAND_MAX)) \
                                    + MIN_RAND;

            f_vec.push_back(random);
        }
    return f_vec;
}

void getScan(std::vector< std::vector<float> > lr_scan) {
    for (int x = 0; x < N_VEC_LIST; x++) {
        std::cout << "Set" << x << ":\n";
        for (int y = 0; y < lr_scan[x].size(); y++) {
            std::cout << lr_scan[x][y] << "\n";
        }
    }
}
