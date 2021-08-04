/* 子字符串突变后可能得到的最大整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 num ，该字符串表示一个大整数。另给你一个长度为 10 且 下标从 0  开始 的整数数组 change ，该数组将 0-9 中的每个数字映射到另一个数字。更规范的说法是，数字 d 映射为数字 change[d] 。

你可以选择 突变  num 的任一子字符串。突变 子字符串意味着将每位数字 num[i] 替换为该数字在 change 中的映射（也就是说，将 num[i] 替换为 change[num[i]]）。

请你找出在对 num 的任一子字符串执行突变操作（也可以不执行）后，可能得到的 最大整数 ，并用字符串表示返回。

子字符串 是字符串中的一个连续序列。

 

示例 1：

输入：num = "132", change = [9,8,5,0,3,6,4,2,6,8]
输出："832"
解释：替换子字符串 "1"：
- 1 映射为 change[1] = 8 。
因此 "132" 变为 "832" 。
"832" 是可以构造的最大整数，所以返回它的字符串表示。
示例 2：

输入：num = "021", change = [9,4,3,5,7,2,1,9,0,6]
输出："934"
解释：替换子字符串 "021"：
- 0 映射为 change[0] = 9 。
- 2 映射为 change[2] = 3 。
- 1 映射为 change[1] = 4 。
因此，"021" 变为 "934" 。
"934" 是可以构造的最大整数，所以返回它的字符串表示。
示例 3：

输入：num = "5", change = [1,4,7,5,3,2,5,6,9,4]
输出："5"
解释："5" 已经是可以构造的最大整数，所以返回它的字符串表示。
 

提示：

1 <= num.length <= 105
num 仅由数字 0-9 组成
change.length == 10
0 <= change[d] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-after-mutating-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool changed = false;

        for (char& c : num) {
            int n = c - '0';

            if (change[n] > n) {
                c = change[n] + '0';
                changed = true;
            }
            else if (change[n] == n) {
                continue;
            } 
            else {
                if (changed) {
                    break;
                }
            }
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> change = { 9,8,5,0,3,6,4,2,6,8 };
    check.checkString("832", o.maximumNumber("132", change));

    change = { 9,4,3,5,7,2,1,9,0,6 };
    check.checkString("934", o.maximumNumber("021", change));

    change = { 1,4,7,5,3,2,5,6,9,4 };
    check.checkString("5", o.maximumNumber("5", change));

    change = { 6,7,9,7,4,0,3,4,4,7 };
    check.checkString("974676", o.maximumNumber("214010", change));
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
