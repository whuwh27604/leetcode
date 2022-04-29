#ifndef __MOUNTAINARRAY_H__
#define __MOUNTAINARRAY_H__

#include <vector>

using namespace std;

class MountainArray {
public:
    MountainArray(vector<int>& nums) : arr(nums) {}

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }

private:
    vector<int> arr;
};

#endif