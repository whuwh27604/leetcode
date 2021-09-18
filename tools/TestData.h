#ifndef __TEST_DATA_H__
#define __TEST_DATA_H__

#include <string>
#include <vector>

using namespace std;

extern vector<int> getIntVector(string filename);
extern vector<vector<int>> getIntVectorVector(string filename);
extern vector<vector<char>> getCharVectorVector(string filename);
extern string getString(string filename);
extern vector<string> getStringVector(string filename);

#endif