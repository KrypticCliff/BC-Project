#include <iostream>
#include <vector>
#include <unistd.h>
#include "ScanSim.h"
#include "Filters.h"

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

#define N_VEC_LIST  3   // N amount of Vectors

int main(int argc, char** argv) {
    vvec_f lr_scan;
    vvec_f lr_range;
    vvec_f lr_median;

    int n_dist = 10;

// Creates Vector of Simulated Distance Vectors
    for (int i = 0; i < N_VEC_LIST; i++) {
        vec_f temp = scanGen(n_dist);
        vvec_f vv_temp;

        // Original Scan Test
        lr_scan.push_back(temp);

        // Range Test
        //lr_range.push_back(range_update(temp));


        // Temporal Median Test
        vv_temp.push_back(temp);
        lr_median.push_back(tm_update(vv_temp, n_dist));

        // Delay Time by 1 Second
        usleep(1000000);
    }

    std::cout << "Original Scan: \n";
    getScan(lr_scan);

    std::cout << "\nRange Update: \n";
    getScan(lr_median);

    return 0;
}
