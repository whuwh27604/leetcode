#ifndef __TEST_DATA_H__
#define __TEST_DATA_H__

#include <string>
#include <vector>

using namespace std;

extern vector<int> getIntVector(string filename);
extern vector<vector<int>> getIntVectorVector(string filename);

#endif