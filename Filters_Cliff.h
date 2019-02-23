// Created By: Clifton A Rawlings Jr.

#include <vector>

#ifndef FILTERS_CLIFF_H_
#define FILTERS_CLIFF_H_

typedef std::vector<float> vec_f;
typedef std::vector<std::vector<float> > vvec_f;

// Range Update
vec_f range_update(vec_f lr_scan);
// Temporal Medial Update
vec_f tm_update(vvec_f lr_scan, int n_dist);

#endif
