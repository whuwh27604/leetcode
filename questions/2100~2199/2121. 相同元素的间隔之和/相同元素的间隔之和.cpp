// 相同元素的间隔之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int i, size = arr.size();
        unordered_map<int, vector<int>> numIndices;
        vector<long long> distances(size, -1);

        getIndices(arr, numIndices);

        for (i = 0; i < size; ++i) {
            if (distances[i] == -1) {
                getNumDistances(numIndices[arr[i]], distances);
            }
        }

        return distances;
    }

    void getIndices(vector<int>& arr, unordered_map<int, vector<int>>& numIndices) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            numIndices[arr[i]].push_back(i);
        }
    }

    void getNumDistances(vector<int>& indices, vector<long long>& distances) {
        int i, size = indices.size();
        long long total = 0, sum = 0;

        for (int index : indices) {
            total += index;
        }

        for (i = 0; i < size; ++i) {
            int index = indices[i];
            distances[index] = (long long)i * index - sum;
            sum += index;
            distances[index] += (total - sum - ((long long)size - i - 1) * index);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 2,1,3,1,2,3,3 };
    vector<long long> actual = o.getDistances(arr);
    vector<long long> expected = { 4,2,7,2,4,4,5 };
    check.checkLongLongVector(expected, actual);

    arr = { 10,5,10,10 };
    actual = o.getDistances(arr);
    expected = { 5,0,3,4 };
    check.checkLongLongVector(expected, actual);

    arr = { 10 };
    actual = o.getDistances(arr);
    expected = { 0 };
    check.checkLongLongVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.getDistances(arr);
    expected = { 0,0,0,0,0 };
    check.checkLongLongVector(expected, actual);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
