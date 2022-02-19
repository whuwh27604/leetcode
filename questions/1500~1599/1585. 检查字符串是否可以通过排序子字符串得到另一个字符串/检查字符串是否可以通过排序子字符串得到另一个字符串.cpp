/* 检查字符串是否可以通过排序子字符串得到另一个字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t ，请你通过若干次以下操作将字符串 s 转化成字符串 t ：

选择 s 中一个 非空 子字符串并将它包含的字符就地 升序 排序。
比方说，对下划线所示的子字符串进行操作可以由 "14234" 得到 "12344" 。

如果可以将字符串 s 变成 t ，返回 true 。否则，返回 false 。

一个 子字符串 定义为一个字符串中连续的若干字符。

 

示例 1：

输入：s = "84532", t = "34852"
输出：true
解释：你可以按以下操作将 s 转变为 t ：
"84532" （从下标 2 到下标 3）-> "84352"
"84352" （从下标 0 到下标 2） -> "34852"
示例 2：

输入：s = "34521", t = "23415"
输出：true
解释：你可以按以下操作将 s 转变为 t ：
"34521" -> "23451"
"23451" -> "23415"
示例 3：

输入：s = "12345", t = "12435"
输出：false
示例 4：

输入：s = "1", t = "2"
输出：false
 

提示：

s.length == t.length
1 <= s.length <= 105
s 和 t 都只包含数字字符，即 '0' 到 '9' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-string-is-transformable-with-substring-sort-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        int i, j, size = s.size();
        vector<queue<int>> indices(10);

        for (i = 0; i < size; ++i) {
            indices[s[i] - '0'].push(i);
        }

        for (i = 0; i < size; ++i) {
            int num = t[i] - '0';

            if (indices[num].empty()) {
                return false;
            }

            for (j = 0; j < num; ++j) {
                if (!indices[j].empty() && indices[j].front() < indices[num].front()) {
                    return false;
                }
            }

            indices[num].pop();
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isTransformable("84532", "34852"));
    check.checkBool(true, o.isTransformable("34521", "23415"));
    check.checkBool(true, o.isTransformable("345213452134521345213452134521345213452134521", "234152341523415234152341523415234152341523415"));
    check.checkBool(true, o.isTransformable("0", "0"));
    check.checkBool(false, o.isTransformable("12345", "12435"));
    check.checkBool(false, o.isTransformable("1", "2"));
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
