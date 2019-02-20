#include <vector>

#ifndef FILTERS_H_
#define FILTERS_H_

// Range Update
std::vector<float> range_update(std::vector<float> lr_scan);
// Temporal Medial Update
std::vector<float> tm_update(std::vector<float> lr_scan);

#endif
