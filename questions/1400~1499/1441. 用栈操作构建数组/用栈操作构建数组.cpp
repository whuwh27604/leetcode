/* 用栈操作构建数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个目标数组 target 和一个整数 n。每次迭代，需要从  list = {1,2,3..., n} 中依序读取一个数字。

请使用下述操作来构建目标数组 target ：

Push：从 list 中读取一个新元素， 并将其推入数组中。
Pop：删除数组中的最后一个元素。
如果目标数组构建完成，就停止读取更多元素。
题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。

请返回构建目标数组所用的操作序列。

题目数据保证答案是唯一的。

 

示例 1：

输入：target = [1,3], n = 3
输出：["Push","Push","Pop","Push"]
解释：
读取 1 并自动推入数组 -> [1]
读取 2 并自动推入数组，然后删除它 -> [1]
读取 3 并自动推入数组 -> [1,3]
示例 2：

输入：target = [1,2,3], n = 3
输出：["Push","Push","Push"]
示例 3：

输入：target = [1,2], n = 4
输出：["Push","Push"]
解释：只需要读取前 2 个数字就可以停止。
示例 4：

输入：target = [2,3,4], n = 4
输出：["Push","Pop","Push","Push","Push"]
 

提示：

1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target 是严格递增的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/build-an-array-with-stack-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0, len = target.size(), number = 0;
        vector<string> operation;

        for (i = 0; i < len; i++) {
            operation.push_back("Push");
            number++;

            while (number != target[i]) {
                operation.push_back("Pop");
                operation.push_back("Push");
                number++;
            }
        }

        return operation;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> target = { 1,3 };
    vector<string> actual = o.buildArray(target, 3);
    vector<string> expected = { "Push","Push","Pop","Push" };
    check.checkStringVector(expected, actual);

    target = { 1,2,3 };
    actual = o.buildArray(target, 3);
    expected = { "Push","Push","Push" };
    check.checkStringVector(expected, actual);

    target = { 1,2 };
    actual = o.buildArray(target, 4);
    expected = { "Push","Push" };
    check.checkStringVector(expected, actual);

    target = { 2,3,4 };
    actual = o.buildArray(target, 4);
    expected = { "Push","Pop","Push","Push","Push" };
    check.checkStringVector(expected, actual);

    target = { 1 };
    actual = o.buildArray(target, 4);
    expected = { "Push" };
    check.checkStringVector(expected, actual);

    target = { 3 };
    actual = o.buildArray(target, 4);
    expected = { "Push","Pop","Push","Pop","Push" };
    check.checkStringVector(expected, actual);

    target = { 2,4,6 };
    actual = o.buildArray(target, 4);
    expected = { "Push","Pop","Push","Push","Pop","Push","Push","Pop","Push" };
    check.checkStringVector(expected, actual);
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
