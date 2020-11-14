/* 132模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

注意：n 的值小于15000。

示例1:

输入: [1, 2, 3, 4]

输出: False

解释: 序列中不存在132模式的子序列。
示例 2:

输入: [3, 1, 4, 2]

输出: True

解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
示例 3:

输入: [-1, 3, 2, 0]

输出: True

解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 从尾到头遍历数组，维护一个单调递减栈
        int i, size = nums.size(), ak = INT_MIN;
        stack<int> lessNums;

        for (i = size - 1; i >= 0; i--) {
            int num = nums[i];
            if (num < ak) {
                return true;
            }
            
            while (!lessNums.empty() && (num > lessNums.top())) {
                ak = lessNums.top();
                lessNums.pop();
            }
            lessNums.push(num);  // 栈顶保持右边有一个小的数的最大数，ak是比这个最大数小的第二大的数。再往左找到一个比ak小的就是答案
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4 };
    check.checkBool(false, o.find132pattern(nums));

    nums = { 3,1,4,2 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { -1,3,2,0 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { 1,0,1,-4,-3 };
    check.checkBool(false, o.find132pattern(nums));

    nums = { 1,1,0,0,1,1,-4,-4,-3,-3 };
    check.checkBool(false, o.find132pattern(nums));

    nums = { 1,2,3,4,5,8,7 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { 8,10,5,7,2,4,3 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { 8,10,5,7,2,4,6 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { 8,10,5,7,2,4,9 };
    check.checkBool(true, o.find132pattern(nums));

    nums = { 8,8,10,10,5,5,7,7,2,2,4,4,9,9 };
    check.checkBool(true, o.find132pattern(nums));
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
