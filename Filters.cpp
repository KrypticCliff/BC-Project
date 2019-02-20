#include <iostream>
#include <vector>
#include "Filters.h"

#define MIN_RANGE   0.03
#define MAX_RANGE   50.0

std::vector<float> range_update(std::vector<float> lr_scan) {
    for (int x = 0; x < lr_scan.size() - 1; x++) {
            if (lr_scan[x] < MIN_RANGE)
                lr_scan[x] = MIN_RANGE;

            if (lr_scan[x] > MAX_RANGE)
                lr_scan[x] = MAX_RANGE;
    }
    return lr_scan;
}

std::vector<float> tm_update(std::vector<float> lr_scan) {

}
