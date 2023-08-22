// 统计和小于目标的下标对数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0, size = nums.size();

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] < target) {
                    ++count;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -1,1,2,3,1 };
    check.checkInt(3, o.countPairs(nums, 2));

    nums = { -6,2,5,-2,-7,-1,3 };
    check.checkInt(10, o.countPairs(nums, -2));
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
