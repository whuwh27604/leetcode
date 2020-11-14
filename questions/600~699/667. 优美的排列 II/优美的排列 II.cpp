/* 优美的排列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数 n 和 k，你需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：

① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；.

② 如果存在多种答案，你只需实现并返回其中任意一种.

示例 1:

输入: n = 3, k = 1
输出: [1, 2, 3]
解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1
 

示例 2:

输入: n = 3, k = 2
输出: [1, 3, 2]
解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2
 

提示:

 n 和 k 满足条件 1 <= k < n <= 104.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arrangement;
        int head = 1, tail = n, count = 0;
        bool head2Tail = true;

        while (count++ < k - 1) {
            if (head2Tail) {
                arrangement.push_back(head++);
            }
            else {
                arrangement.push_back(tail--);
            }

            head2Tail = !head2Tail;
        }

        if (head2Tail) {
            while (head <= tail) {
                arrangement.push_back(head++);
            }
        }
        else {
            while (head <= tail) {
                arrangement.push_back(tail--);
            }
        }

        return arrangement;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.constructArray(2, 1);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(3, 1);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(3, 2);
    expected = { 1,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(4, 1);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(4, 2);
    expected = { 1,4,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(4, 3);
    expected = { 1,4,2,3 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 1);
    expected = { 1,2,3,4,5,6,7 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 2);
    expected = { 1,7,6,5,4,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 3);
    expected = { 1,7,2,3,4,5,6 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 4);
    expected = { 1,7,2,6,5,4,3 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 5);
    expected = { 1,7,2,6,3,4,5 };
    check.checkIntVector(expected, actual);

    actual = o.constructArray(7, 6);
    expected = { 1,7,2,6,3,5,4 };
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
