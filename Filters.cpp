// Created By: Clifton A Rawlings Jr.
// Timestamp: March 12, 2019

#include <iostream>
#include <vector>
#include <algorithm>
#include "Filters.h"

#define MIN_RANGE   0.03
#define MAX_RANGE   50.0

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

// dist < 0.03 == MIN | dist > 50 == MAX
vec_f range_update(vec_f lr_scan) {
    for (int x = 0; x < lr_scan.size() - 1; x++) {
            if (lr_scan[x] < MIN_RANGE)
                lr_scan[x] = MIN_RANGE;

            if (lr_scan[x] > MAX_RANGE)
                lr_scan[x] = MAX_RANGE;
    }
    return lr_scan;
}

/*
    Uses external incrementing vvec_f to combine N-1 vectors.
    n_dist (y) the amount of distant values in a vector[x][y] (matrix columns)

            Vec_Scan
        y0  y1  y2  y3  y4  y5
    x0 [#] [$] [%] [^] [&] [*]
    x1 [#] [$] [%] [^] [&] [*]
    x2 [#] [$] [%] [^] [&] [*]
    x3 [#] [$] [%] [^] [&] [*]
        ^   ^  ...>
        ^   ^  > V_Temp [%] [%] [%] [%] [%]  Loop#3  Passed -> lr_median[2]
        ^   >    V_Temp [$] [$] [$] [$] [$]  Loop#2  Passed -> lr_median[1]
        >        V_Temp [#] [#] [#] [#] [#]  Loop#1  Passed -> lr_median[0]

    V_Temp is ran through loop, sort, & alg. respectfully
*/
vec_f tm_update(vvec_f vec_scan, int n_dist) {
    vec_f lr_median;
    size_t size = vec_scan.size();

    if (size == 0) {
        exit(EXIT_FAILURE);
    } else if (size == 1) {
        // Immediately Pass First Vector
        for (int x = 0; x < vec_scan[0].size(); x++) {
            lr_median.push_back(vec_scan[0][x]);
        }
        return lr_median;
    }

/*
    Checks if Vector list is Even. Vector has 2 Middle Values.
    size 6 (6%2 = 0)
    [#] [5] [6] [#]
         ^   ^
         5 + 6 = 11 / 2 = 5.5 -> pushed to return lr_median vector
*/
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

/*
    Checks if Vector List is Odd. Vector has 1 Middle Value.
    size 3 (3%2 = 1)
    [#] [3] [#]
         ^
         3 -> pushed to return lr_median vector
*/
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
