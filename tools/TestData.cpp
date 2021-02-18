
#include <iostream>
#include <fstream>
#include <sstream>
#include "TestData.h"

using namespace std;

vector<vector<int>> getIntVectorVector(string filename) {
    vector<vector<int>> data;
    ifstream in(filename, ios::binary);
    string fileContext;
    in >> fileContext;
    int start = 0;

    for (int i = 1; i < (int)fileContext.size(); ++i) {
        char c = fileContext[i];
        if (c == '[') {
            data.push_back({});
            start = i + 1;
        }
        else if (c == ',') {
            data.back().push_back(stoi(string(fileContext, start, i - start)));
            start = i + 1;
        }
        else if (c == ']') {
            data.back().push_back(stoi(string(fileContext, start, i - start)));
            start = i + 1;
            i += 1;
        }
    }

    return data;
}