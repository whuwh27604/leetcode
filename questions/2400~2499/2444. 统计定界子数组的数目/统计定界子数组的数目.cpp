// 统计定界子数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int size = nums.size(), minIndex = -1, maxIndex = -1, outIndex = size;
        long long subarrays = 0;

        for (int i = size - 1; i >= 0; --i) {
            int num = nums[i];

            if (num == minK) {
                minIndex = i;
            }

            if (num == maxK) {
                maxIndex = i;
            }

            if (num < minK || num > maxK) {
                outIndex = i;
                minIndex = -1;
                maxIndex = -1;
            }

            if (minIndex != -1 && maxIndex != -1) {
                subarrays += ((long long)outIndex - max(minIndex, maxIndex));
            }
        }

        return subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,5,2,7,5 };
    check.checkLongLong(2, o.countSubarrays(nums, 1, 5));

    nums = { 1,1,1,1 };
    check.checkLongLong(10, o.countSubarrays(nums, 1, 1));

    nums = { 35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913 };
    check.checkLongLong(81, o.countSubarrays(nums, 35054, 945315));
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
