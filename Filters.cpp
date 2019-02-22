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

vec_f tm_update(vvec_f vec_scan, int n_dist) {
    vec_f lr_median;
    size_t size = vec_scan.size();

    if (size == 0) {
        exit(EXIT_FAILURE);
    } else if (size == 1) {
        for (int x = 0; x < vec_scan[0].size(); x++) {
            lr_median.push_back(vec_scan[0][x]);
        }
        return lr_median;
    }

    if (size % 2 == 0) {
        for (int y = 0; y < n_dist; y++){
            vec_f v_temp;

            for (int x = 0; x < size; x++) {
                v_temp.push_back(vec_scan[x][y]);
            }
            std::sort(v_temp.begin(), v_temp.end());
            float val_x = v_temp[(v_temp.size() / 2) - 1];
            float val_y = v_temp[(v_temp.size() / 2)];

            lr_median.push_back(((val_x + val_y) / 2.0));
        }
        return lr_median;

    }   else if (size % 2 != 0) {
            for (int y = 0; y < n_dist; y++) {
                vec_f v_temp;

                for (int x = 0; x < size; x++) {
                    v_temp.push_back(vec_scan[x][y]);
                }
                std::sort(v_temp.begin(), v_temp.end());
                lr_median.push_back(v_temp[size / 2.0]);
            }
            return lr_median;
        }
}
