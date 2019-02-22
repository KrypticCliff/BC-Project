#include <iostream>
#include <vector>
#include <unistd.h>
#include "ScanSim.h"
#include "Filters.h"

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

#define N_VEC_LIST  8   // N amount of Vectors

int main(int argc, char** argv) {
    vvec_f lr_scan;
    vvec_f lr_range;
    vvec_f lr_median;

    int n_dist = 200;
    vvec_f vv_temp;

// Creates Vector of Simulated Distance Vectors
    for (int i = 0; i < N_VEC_LIST; i++) {
        vec_f temp = scanGen(n_dist);

        // Delay Time by 1 Second
        usleep(3000);

        // Original Scan Test
        lr_scan.push_back(temp);

        // Range Test
        //lr_range.push_back(range_update(temp));


        // Temporal Median Test
        vv_temp.push_back(temp);
        lr_median.push_back(tm_update(vv_temp, n_dist));

    }

    std::cout << "Original Scan: \n";
    getScan(lr_scan);

    std::cout << "\nMedian Update: \n";
    getScan(lr_median);

    std::cout << "\nRange Update: \n";
    getScan(lr_range);

    return 0;
}
