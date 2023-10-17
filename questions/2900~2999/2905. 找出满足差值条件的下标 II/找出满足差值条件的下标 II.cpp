// 找出满足差值条件的下标 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int size = nums.size();
        vector<pair<int, int>> maxIndices(size + 1, { -1,size }), minIndices(size + 1, { INT_MAX,size });

        for (int i = size - 1; i >= 0; --i) {
            if (nums[i] > maxIndices[i + 1].first) {
                maxIndices[i] = { nums[i], i };
            }
            else {
                maxIndices[i] = maxIndices[i + 1];
            }

            if (nums[i] < minIndices[i + 1].first) {
                minIndices[i] = { nums[i], i };
            }
            else {
                minIndices[i] = minIndices[i + 1];
            }
        }

        for (int i = 0; i < size - indexDifference; ++i) {
            if (abs(maxIndices[i + indexDifference].first - nums[i]) >= valueDifference) {
                return { i,maxIndices[i + indexDifference].second };
            }

            if (abs(nums[i] - minIndices[i + indexDifference].first) >= valueDifference) {
                return { i,minIndices[i + indexDifference].second };
            }
        }

        return { -1,-1 };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,1,4,1 };
    vector<int> actual = o.findIndices(nums, 2, 4);
    vector<int> expected = { 0,3 };
    check.checkIntVector(expected, actual);

    nums = { 2,1 };
    actual = o.findIndices(nums, 0, 0);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.findIndices(nums, 2, 4);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);
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
