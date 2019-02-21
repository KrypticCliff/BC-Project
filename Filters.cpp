#include <iostream>
#include <vector>
#include <algorithm>
#include "Filters.h"
#include "ScanSim.h"    // Remove after Testing

#define MIN_RANGE   0.03
#define MAX_RANGE   50.0

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

// If dist < 0.03 == MIN
// If dist > 50   == MAX
vec_f range_update(vec_f lr_scan) {
    for (int x = 0; x < lr_scan.size() - 1; x++) {
            if (lr_scan[x] < MIN_RANGE)
                lr_scan[x] = MIN_RANGE;

            if (lr_scan[x] > MAX_RANGE)
                lr_scan[x] = MAX_RANGE;
    }
    return lr_scan;
}

vvec_f tm_update(vvec_f lr_scan, int n_dist) {
    vvec_f lr_median;
    vec_f vec_push;

    for (int y = 0; y < n_dist; y++) {
        vec_f temp;
        size_t size;

        for (int x = 0; x < lr_scan.size() ; x++ ) {
            temp.push_back(lr_scan[x][y]);
        }
        std::sort(temp.begin(), temp.end());
        size = temp.size();

        if (temp_size % 2 != 0) {
            vec_push.push_back[x][y](temp[(size / 2) + 1]);
        } else if (temp_size % 2 = 0) {
            
        }

    }

    return lr_median;
    }
}
