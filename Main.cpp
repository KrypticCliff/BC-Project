#include <iostream>
#include <vector>
#include <unistd.h>
#include "ScanSim.h"

#define N_VEC_LIST  5   // N amount of Vectors

int main(int argc, char** argv) {
    //std::vector<float> lr_scan;
    std::vector< std::vector<float> > lr_scan;

    for (int i = 0; i < N_VEC_LIST; i++) {
        std::vector<float> temp = scanGen();
        lr_scan.push_back(temp);
        usleep(5000000);
    }

    getScan(lr_scan);

    return 0;
}
