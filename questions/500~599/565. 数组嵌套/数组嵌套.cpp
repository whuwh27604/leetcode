/* 数组嵌套.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

 

示例 1:

输入: A = [5,4,0,3,1,6,2]
输出: 4
解释:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 

提示：

N是[1, 20,000]之间的整数。
A中不含有重复的元素。
A中的元素大小在[0, N-1]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-nesting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int i, size = nums.size(), numsLeft = size;
        int nestLen, maxNestLen = 0;

        for (i = 0; i < size; i++) {
            if (nums[i] < 0) {
                continue;
            }

            nestLen = 0;
            int next = i;

            // 遍历从nums[i]开始的环。因为A从0到N-1每个数一个，所以只能是完整的环，不能有尾巴，即最后一定回到nums[i]，否则会有两个数的下一个指向同一个数。
            while (nums[next] >= 0) {
                int tmp = nums[next];
                nums[next] = -1;
                next = tmp;
                nestLen++;
            }

            maxNestLen = max(maxNestLen, nestLen);
            numsLeft -= nestLen;
            if (maxNestLen >= numsLeft) {
                break;
            }
        }

        return maxNestLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5,4,0,3,1,6,2 };
    check.checkInt(4, o.arrayNesting(nums));

    nums = { 0 };
    check.checkInt(1, o.arrayNesting(nums));

    nums = { 0,1 };
    check.checkInt(1, o.arrayNesting(nums));

    nums = { 1,0 };
    check.checkInt(2, o.arrayNesting(nums));

    nums = { 0,1,2 };
    check.checkInt(1, o.arrayNesting(nums));

    nums = { 0,2,1 };
    check.checkInt(2, o.arrayNesting(nums));

    nums = { 1,0,2 };
    check.checkInt(2, o.arrayNesting(nums));

    nums = { 1,2,0 };
    check.checkInt(3, o.arrayNesting(nums));
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
