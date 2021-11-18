/* 从子集的和还原数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一个未知数组需要你进行还原，给你一个整数 n 表示该数组的长度。另给你一个数组 sums ，由未知数组中全部 2n 个 子集的和 组成（子集中的元素没有特定的顺序）。

返回一个长度为 n 的数组 ans 表示还原得到的未知数组。如果存在 多种 答案，只需返回其中 任意一个 。

如果可以由数组 arr 删除部分元素（也可能不删除或全删除）得到数组 sub ，那么数组 sub 就是数组 arr 的一个 子集 。sub 的元素之和就是 arr 的一个 子集的和 。一个空数组的元素之和为 0 。

注意：生成的测试用例将保证至少存在一个正确答案。

 

示例 1：

输入：n = 3, sums = [-3,-2,-1,0,0,1,2,3]
输出：[1,2,-3]
解释：[1,2,-3] 能够满足给出的子集的和：
- []：和是 0
- [1]：和是 1
- [2]：和是 2
- [1,2]：和是 3
- [-3]：和是 -3
- [1,-3]：和是 -2
- [2,-3]：和是 -1
- [1,2,-3]：和是 0
注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
示例 2：

输入：n = 2, sums = [0,0,0,0]
输出：[0,0]
解释：唯一的正确答案是 [0,0] 。
示例 3：

输入：n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
输出：[0,-1,4,5]
解释：[0,-1,4,5] 能够满足给出的子集的和。
 

提示：

1 <= n <= 15
sums.length == 2n
-104 <= sums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-array-given-subset-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> nums;

        sort(sums.begin(), sums.end());
        recover(sums, nums);

        return nums;
    }

    void recover(vector<int> sums, vector<int>& nums) {
        int size = sums.size();
        if (size == 2) {
            nums.push_back(sums[0] + sums[1]);  // 只剩2个数时，一定是0和一个原数组中的数
            return;
        }

        vector<int> withDiff(size / 2), withoutDiff(size / 2);
        int diff = sums[1] - sums[0], i = 0, j = 1, index = 0, invalid = INT_MAX;  // +-diff一定是原数组中的一个数

        for (i = 0; i < size; ++i) {  // 按顺序将sums划分到2组，一组包含diff，一组不包含diff
            if (sums[i] == invalid) {
                continue;
            }

            while (j <= i || sums[j] == invalid || sums[i] + diff != sums[j]) {  // 找到sums[i]后面第一个sums[i] + diff
                ++j;
            }

            withoutDiff[index] = sums[i];
            withDiff[index++] = sums[j];
            sums[i] = invalid;
            sums[j] = invalid;
        }

        // 找到包含0的一组，它代表空集，和它对应的另一组中的数就是准确的diff或-diff，即原数组中的数。两边都有0的情况，任选一边都可以。
        for (i = 0; withoutDiff[i] != 0 && withDiff[i] != 0; ++i) {}

        if (withoutDiff[i] == 0) {
            nums.push_back(withDiff[i]);  // 包含原数组中数的一边
            recover(withoutDiff, nums);  // 不包含的一边继续递归，寻找下一个数
        }
        else {
            nums.push_back(withoutDiff[i]);
            recover(withDiff, nums);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> sums = { -3,-2,-1,0,0,1,2,3 };
    vector<int> actual = o.recoverArray(3, sums);
    vector<int> expected = { -1,-2,3 };
    check.checkIntVector(expected, actual);

    sums = { 0,0,0,0 };
    actual = o.recoverArray(2, sums);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    sums = { 0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8 };
    actual = o.recoverArray(4, sums);
    expected = { 0,-1,4,5 };
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
