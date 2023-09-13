/* 与车相交的点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中 starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。

返回数轴上被车 任意部分 覆盖的整数点的数目。



示例 1：

输入：nums = [[3,6],[1,5],[4,7]]
输出：7
解释：从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。
示例 2：

输入：nums = [[1,3],[5,8]]
输出：7
解释：1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。


提示：

1 <= nums.length <= 100
nums[i].length == 2
1 <= starti <= endi <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> exist(101, false);
        int points = 0;

        for (auto& car : nums) {
            for (int point = car[0]; point <= car[1]; ++point) {
                exist[point] = true;
            }
        }

        for (bool ex : exist) {
            if (ex) {
                ++points;
            }
        }

        return points;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums = { {3,6},{1,5},{4,7} };
    check.checkInt(7, o.numberOfPoints(nums));

    nums = { {1,3},{5,8} };
    check.checkInt(7, o.numberOfPoints(nums));
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
