// 还原原数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        map<int, int> numsCount;
        vector<int> ans;

        for (int num : nums) {
            ++numsCount[num];
        }

        auto iter = numsCount.begin();
        int minimum = iter->first;

        for (++iter; iter != numsCount.end(); ++iter) {
            ans.clear();
            int doubleK = iter->first - minimum;

            if ((doubleK & 1) == 0 && recover(numsCount, doubleK, ans)) {
                break;
            }
        }

        return ans;
    }

    bool recover(map<int, int> numsCount, int doubleK, vector<int>& ans) {
        while (!numsCount.empty()) {
            int low = numsCount.begin()->first, high = low + doubleK;
            auto iter = numsCount.find(high);

            if (iter == numsCount.end()) {
                return false;
            }

            ans.push_back((low + high) / 2);

            if (--iter->second == 0) {
                numsCount.erase(iter);
            }

            if (--numsCount.begin()->second == 0) {
                numsCount.erase(numsCount.begin());
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,10,6,4,8,12 };
    vector<int> actual = o.recoverArray(nums);
    vector<int> expected = { 3,7,11 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,3,3 };
    actual = o.recoverArray(nums);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    nums = { 5,435 };
    actual = o.recoverArray(nums);
    expected = { 220 };
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
