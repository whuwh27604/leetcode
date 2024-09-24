/* 求出数组中最大序列值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 正 整数 k 。

定义长度为 2 * x 的序列 seq 的 值 为：

(seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1]).
请你求出 nums 中所有长度为 2 * k 的
子序列
 的 最大值 。



示例 1：

输入：nums = [2,6,7], k = 1

输出：5

解释：

子序列 [2, 7] 的值最大，为 2 XOR 7 = 5 。

示例 2：

输入：nums = [4,2,5,6,7], k = 2

输出：2

解释：

子序列 [4, 5, 6, 7] 的值最大，为 (4 OR 5) XOR (6 OR 7) = 2 。



提示：

2 <= nums.length <= 400
1 <= nums[i] < 27
1 <= k <= nums.length / 2
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int size = (int)nums.size();
        vector<vector<vector<bool>>> leftORs(size, vector<vector<bool>>(k + 1, vector<bool>(maxNum, false)));
        vector<vector<vector<bool>>> rightORs(size, vector<vector<bool>>(k + 1, vector<bool>(maxNum, false)));
        
        getLeftORs(nums, k, size, leftORs);
        getRightORs(nums, k, size, rightORs);

        return getMaxValue(size, k, leftORs, rightORs);
    }

    void getLeftORs(vector<int>& nums, int k, int size, vector<vector<vector<bool>>>& leftORs) {
        leftORs[0][1][nums[0]] = true;  // dp[i][cnt][num]表示从nums[0, i]取cnt个数，是否可以或成num

        for (int i = 1; i < size; ++i) {
            leftORs[i][1] = leftORs[i - 1][1];
            leftORs[i][1][nums[i]] = true;

            for (int cnt = 2; cnt <= k; ++cnt) {
                leftORs[i][cnt] = leftORs[i - 1][cnt];  // 不取nums[i]

                for (int num = 1; num < maxNum; ++num) {  // 取nums[i]
                    if (leftORs[i - 1][cnt - 1][num]) {
                        leftORs[i][cnt][num | nums[i]] = true;
                    }
                }
            }
        }
    }

    void getRightORs(vector<int>& nums, int k, int size, vector<vector<vector<bool>>>& rightORs) {
        rightORs[size - 1][1][nums[size - 1]] = true;  // dp[i][cnt][num]表示从numsi[i, size - 1]取cnt个数，是否可以或成num

        for (int i = size - 2; i >= 0; --i) {
            rightORs[i][1] = rightORs[i + 1][1];
            rightORs[i][1][nums[i]] = true;

            for (int cnt = 2; cnt <= k; ++cnt) {
                rightORs[i][cnt] = rightORs[i + 1][cnt];  // 不取nums[i]

                for (int num = 1; num < maxNum; ++num) {  // 取nums[i]
                    if (rightORs[i + 1][cnt - 1][num]) {
                        rightORs[i][cnt][num | nums[i]] = true;
                    }
                }
            }
        }
    }

    int getMaxValue(int size, int k, vector<vector<vector<bool>>>& leftORs, vector<vector<vector<bool>>>& rightORs) {
        int maxVal = 0;

        for (int i = k - 1; i < size - k; ++i) {
            for (int n1 = 1; n1 < maxNum; ++n1) {
                if (leftORs[i][k][n1]) {
                    for (int n2 = 1; n2 < maxNum; ++n2) {
                        if (rightORs[i + 1][k][n2]) {
                            maxVal = max(maxVal, n1 ^ n2);
                        }
                    }
                }
            }
        }

        return maxVal;
    }

    int maxNum = 128;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,6,7 };
    check.checkInt(5, o.maxValue(nums, 1));

    nums = { 4,2,5,6,7 };
    check.checkInt(2, o.maxValue(nums, 2));

    nums = { 4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7,4,2,5,6,7,2,6,7 };
    check.checkInt(7, o.maxValue(nums, 3));

    nums = { 91,92,95,86,87,71,72,75,66,67,91,92,95,86,87,71,72,75,66,67,91,92,95,86,87,71,72,75,66,67,91,92,95,86,87,71,72,75,66,67 };
    check.checkInt(29, o.maxValue(nums, 5));
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
