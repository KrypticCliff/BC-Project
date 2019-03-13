// Created By: Clifton A Rawlings Jr.
// Timestamp: March 12, 2019

#include <iostream>
#include <vector>
#include "ScanSim.h"
#include "Filters.h"

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

#define N_VEC_LIST  6   // N amount of Vectors
#define N_DIST      5   // N amount of Distance Values

int main(int argc, char** argv) {
    vvec_f lr_scan;
    vvec_f lr_range;
    vvec_f lr_median;
    vvec_f temporal_vvec;

// Creates Vector of Simulated Distance Vectors
    for (int i = 0; i < N_VEC_LIST; i++) {
        vec_f temp = scanGen(N_DIST);

        // Original Scan Test
        lr_scan.push_back(temp);

        // Range Test
        lr_range.push_back(range_update(temp));

        // Temporal Median Test (temporal vec combines N-1 vector)
        temporal_vvec.push_back(temp);
        lr_median.push_back(tm_update(temporal_vvec, N_DIST));
    }

    std::cout << "Original Scan: \n";
    getScan(lr_scan);

    std::cout << "\nMedian Update: \n";
    getScan(lr_median);

    std::cout << "\nRange Update: \n";
    getScan(lr_range);

    return 0;
}
