/* 字母与数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。

示例 1:

输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]

输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
示例 2:

输入: ["A","A"]

输出: []
提示：

array.length <= 100000
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int start = 0;
        unordered_map<int, int> diffIndices;

        int totalDiff = getDiff(array, diffIndices);
        int maxLen = getMaxLen(array, diffIndices, totalDiff, start);
        if (maxLen == 0) {
            return {};
        }

        return getAns(array, maxLen, start);
    }

    int getDiff(vector<string>& array, unordered_map<int, int>& diffIndices) {
        int size = array.size(), diff = 0;

        diffIndices[0] = size;

        for (int i = size - 1; i >= 0; --i) {
            if (array[i][0] >= '0' && array[i][0] <= '9') {
                ++diff;
            }
            else {
                --diff;
            }

            if (diffIndices.count(diff) == 0) {
                diffIndices[diff] = i;
            }
        }

        return diff;
    }

    int getMaxLen(vector<string>& array, unordered_map<int, int>& diffIndices, int totalDiff, int& start) {
        int size = array.size(), diff = 0, maxLen = 0;

        for (int i = 0; i < size; ++i) {
            if (diffIndices[totalDiff - diff] - i > maxLen) {
                maxLen = diffIndices[totalDiff - diff] - i;
                start = i;
            }

            if (array[i][0] >= '0' && array[i][0] <= '9') {
                ++diff;
            }
            else {
                --diff;
            }
        }

        return maxLen;
    }

    vector<string> getAns(vector<string>& array, int maxLen, int start) {
        vector<string> ans;

        for (int i = 0; i < maxLen; ++i) {
            ans.push_back(array[i + start]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> array = { "A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M" };
    vector<string> actual = o.findLongestSubarray(array);
    vector<string> expected = { "A","1","B","C","D","2","3","4","E","5","F","G","6","7" };
    check.checkStringVector(expected, actual);

    array = { "A","A" };
    actual = o.findLongestSubarray(array);
    expected = {  };
    check.checkStringVector(expected, actual);

    array = { "A","1" };
    actual = o.findLongestSubarray(array);
    expected = { "A","1" };
    check.checkStringVector(expected, actual);

    array = { "ABC","1","B","C","D","2","333","4","E","5","F","G","6","7","H","I","J","K","L","M" };
    actual = o.findLongestSubarray(array);
    expected = { "ABC","1","B","C","D","2","333","4","E","5","F","G","6","7" };
    check.checkStringVector(expected, actual);

    array = { "AA", "A", "A", "1", "2", "3" };
    actual = o.findLongestSubarray(array);
    expected = { "AA","A","A","1","2","3" };
    check.checkStringVector(expected, actual);

    array = { "AB","1","2" };
    actual = o.findLongestSubarray(array);
    expected = { "AB","1" };
    check.checkStringVector(expected, actual);
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
