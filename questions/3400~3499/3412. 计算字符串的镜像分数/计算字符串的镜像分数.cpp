/* 计算字符串的镜像分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s。

英文字母中每个字母的 镜像 定义为反转字母表之后对应位置上的字母。例如，'a' 的镜像是 'z'，'y' 的镜像是 'b'。

最初，字符串 s 中的所有字符都 未标记 。

字符串 s 的初始分数为 0 ，你需要对其执行以下过程：

从左到右遍历字符串。
对于每个下标 i ，找到距离最近的 未标记 下标 j，下标 j 需要满足 j < i 且 s[j] 是 s[i] 的镜像。然后 标记 下标 i 和 j，总分加上 i - j 的值。
如果对于下标 i，不存在满足条件的下标 j，则跳过该下标，继续处理下一个下标，不需要进行标记。
返回最终的总分。



示例 1：

输入： s = "aczzx"

输出： 5

解释：

i = 0。没有符合条件的下标 j，跳过。
i = 1。没有符合条件的下标 j，跳过。
i = 2。距离最近的符合条件的下标是 j = 0，因此标记下标 0 和 2，然后将总分加上 2 - 0 = 2 。
i = 3。没有符合条件的下标 j，跳过。
i = 4。距离最近的符合条件的下标是 j = 1，因此标记下标 1 和 4，然后将总分加上 4 - 1 = 3 。
示例 2：

输入： s = "abcdef"

输出： 0

解释：

对于每个下标 i，都不存在满足条件的下标 j。



提示：

1 <= s.length <= 105
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        vector<vector<int>> indices(26);

        for (int i = 0; i < (int)s.size(); ++i) {
            int idx = s[i] - 'a', mirror = 25 - idx;

            if (!indices[mirror].empty()) {
                score += ((long long)i - indices[mirror].back());
                indices[mirror].pop_back();
            }
            else {
                indices[idx].push_back(i);
            }
        }

        return score;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkLongLong(5, o.calculateScore("aczzx"));
    check.checkLongLong(0, o.calculateScore("abcdef"));
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
