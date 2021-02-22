/* 移动所有球到每个盒子所需的最小操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，而 boxes[i] 的值为 '1' 表示盒子里有 一个 小球。

在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。注意，操作执行后，某些盒子中可能会存在不止一个小球。

返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。

每个 answer[i] 都需要根据盒子的 初始状态 进行计算。

 

示例 1：

输入：boxes = "110"
输出：[1,1,3]
解释：每个盒子对应的最小操作数如下：
1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
示例 2：

输入：boxes = "001011"
输出：[11,8,5,4,3,4]
 

提示：

n == boxes.length
1 <= n <= 2000
boxes[i] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i, size = boxes.size(), total = 0, operations = 0;
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            if (boxes[i] == '1') {
                total += 1;
                operations += i;
            }
        }

        ans[0] = operations;
        int left = 0, right = total;

        for (i = 1; i < size; ++i) {
            left += (boxes[i - 1] == '1' ? 1 : 0);
            right = total - left - (boxes[i] == '1' ? 1 : 0);
            operations = operations + left - right - (boxes[i] == '1' ? 1 : 0);
            ans[i] = operations;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.minOperations("110");
    vector<int> expected = { 1,1,3 };
    check.checkIntVector(expected, actual);

    actual = o.minOperations("001011");
    expected = { 11,8,5,4,3,4 };
    check.checkIntVector(expected, actual);

    actual = o.minOperations("0");
    expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.minOperations("1");
    expected = { 0 };
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
