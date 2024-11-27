/* 验证二叉搜索树的后序遍历序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请实现一个函数来判断整数数组 postorder 是否为二叉搜索树的后序遍历结果。



示例 1：



输入: postorder = [4,9,6,5,8]
输出: false
解释：从上图可以看出这不是一颗二叉搜索树
示例 2：



输入: postorder = [4,6,5,9,8]
输出: true
解释：可构建的二叉搜索树如上图


提示：

数组长度 <= 1000
postorder 中无重复数字
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return check(postorder, 0, (int)postorder.size() - 1);
    }

    bool check(vector<int>& postorder, int start, int end) {
        if (start >= end) {
            return true;
        }

        int idx = start;

        while (postorder[idx] < postorder[end]) {
            ++idx;
        }

        for (int i = idx; i < end; ++i) {
            if (postorder[i] < postorder[end]) {
                return false;
            }
        }

        return check(postorder, start, idx - 1) && check(postorder, idx, end - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> postorder = { 4,9,6,5,8 };
    check.checkBool(false, o.verifyTreeOrder(postorder));

    postorder = { 4,6,5,9,8 };
    check.checkBool(true, o.verifyTreeOrder(postorder));
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
