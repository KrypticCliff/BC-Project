#include <iostream>
#include <vector>
#include <unistd.h>
#include "ScanSim.h"
#include "Filters.h"

#define N_VEC_LIST  3   // N amount of Vectors

int main(int argc, char** argv) {
    std::vector< std::vector<float> > lr_scan;
    std::vector< std::vector<float> > lr_range;

// Creates Vector of Simulated Distance Vectors
    for (int i = 0; i < N_VEC_LIST; i++) {
        std::vector<float> temp = scanGen(5);

        // Original Scan Test
        lr_scan.push_back(temp);

        // Range Test
        lr_range.push_back(range_update(temp));

        usleep(1000000);
    }

    std::cout << "Original Scan: \n";
    getScan(lr_scan);

    std::cout << "\nRange Update: \n";
    getScan(lr_range);

    return 0;
}
