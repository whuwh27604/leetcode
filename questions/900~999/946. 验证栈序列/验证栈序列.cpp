/* 验证栈序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-stack-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> nums;
        int i = 0, size = pushed.size();

        for (int num : popped) {
            if (!nums.empty() && num == nums.top()) {
                nums.pop();
                continue;
            }

            for (; i < size && pushed[i] != num; ++i) {
                nums.push(pushed[i]);
            }

            if (i++ == size) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,2,1 };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1,2,3,4,5 };
    popped = { 4,3,5,1,2 };
    check.checkBool(false, o.validateStackSequences(pushed, popped));

    pushed = {  };
    popped = {  };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1 };
    popped = { 1 };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1 };
    popped = { 2 };
    check.checkBool(false, o.validateStackSequences(pushed, popped));

    pushed = { 1,2,3 };
    popped = { 1,2,3 };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1,2,3 };
    popped = { 3,2,1 };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1,2,3 };
    popped = { 3,2,0 };
    check.checkBool(false, o.validateStackSequences(pushed, popped));

    pushed = { 2,1,0 };
    popped = { 1,2,0 };
    check.checkBool(true, o.validateStackSequences(pushed, popped));

    pushed = { 1,2,3 };
    popped = { 3,1,2 };
    check.checkBool(false, o.validateStackSequences(pushed, popped));
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
