#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "ScanSim.h"

//#define N_DIST_VALUE    5       // N Values of Distance Values in Vector
#define MIN_RAND        0.0     // Min Random Generate Value
#define MAX_RAND        60.0    // Max Random Generate Value

std::vector<float> scanGen(int n_dist) {
    std::vector<float> f_vec;

    // Random Generator Config
    srand(time(NULL));
    const float range = MAX_RAND - MIN_RAND;

    // Pushes Random Distance Values into f_vec
        for (int i = 0; i < n_dist; i++) {
            float random = range * ((((float) rand()) / (float) RAND_MAX)) \
                                    + MIN_RAND;
            f_vec.push_back(random);
        }
    return f_vec;
}

// Prints All Values Stored in Simulated LIDAR Scan
void getScan(std::vector< std::vector<float> > lr_scan) {
    for (int x = 0; x < lr_scan.size() - 1; x++) {
        std::cout << "Set" << x << ":\n";

        for (int y = 0; y < lr_scan[x].size(); y++) {
            std::cout   << std::fixed
                        << std::setprecision(3)
                        << lr_scan[x][y] << "\t";
        }
        std::cout << "\n";
    }
}
