/* 合并两个二维数组 - 求和法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 二维 整数数组 nums1 和 nums2.

nums1[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
nums2[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
每个数组都包含 互不相同 的 id ，并按 id 以 递增 顺序排列。

请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：

只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。
每个 id 在结果数组中 只能出现一次 ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则认为其对应的值等于 0 。
返回结果数组。返回的数组需要按 id 以递增顺序排列。



示例 1：

输入：nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
输出：[[1,6],[2,3],[3,2],[4,6]]
解释：结果数组中包含以下元素：
- id = 1 ，对应的值等于 2 + 4 = 6 。
- id = 2 ，对应的值等于 3 。
- id = 3 ，对应的值等于 2 。
- id = 4 ，对应的值等于5 + 1 = 6 。
示例 2：

输入：nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
输出：[[1,3],[2,4],[3,6],[4,3],[5,5]]
解释：不存在共同 id ，在结果数组中只需要包含每个 id 和其对应的值。


提示：

1 <= nums1.length, nums2.length <= 200
nums1[i].length == nums2[j].length == 2
1 <= idi, vali <= 1000
数组中的 id 互不相同
数据均按 id 以严格递增顺序排列
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();

        while (i < size1 && j < size2) {
            if (nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i++]);
            }
            else if (nums1[i][0] > nums2[j][0]) {
                ans.push_back(nums2[j++]);
            }
            else {
                ans.push_back({ nums1[i][0], nums1[i++][1] + nums2[j++][1] });
            }
        }

        while (i < size1) {
            ans.push_back(nums1[i++]);
        }

        while (j < size2) {
            ans.push_back(nums2[j++]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums1 = { {1,2},{2,3},{4,5} };
    vector<vector<int>> nums2 = { {1,4},{3,2},{4,1} };
    vector<vector<int>> actual = o.mergeArrays(nums1, nums2);
    vector<vector<int>> expected = { {1,6},{2,3},{3,2},{4,6} };
    check.checkIntVectorVector(expected, actual);

    nums1 = { {2,4},{3,6},{5,5} };
    nums2 = { {1,3},{4,3} };
    actual = o.mergeArrays(nums1, nums2);
    expected = { {1,3},{2,4},{3,6},{4,3},{5,5} };
    check.checkIntVectorVector(expected, actual);
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
