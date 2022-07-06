/* 统计重复个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。

例如，str == ["abc", 3] =="abcabcabc" 。
如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。

例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2, n2] 。

请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得。

 

示例 1：

输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
输出：2
示例 2：

输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
输出：1
 

提示：

1 <= s1.length, s2.length <= 100
s1 和 s2 由小写英文字母组成
1 <= n1, n2 <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-the-repetitions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (!exist(s1, s2)) {
            return 0;
        }

        int size1 = s1.size() * n1, firstSize = 0, repeatCnt = 0, circleRepeat = 0;
        int circleSize = getCircle(s1, n1, s2, n2, firstSize, repeatCnt, circleRepeat);

        if (firstSize > size1) {
            return 0;
        }

        repeatCnt += (size1 - firstSize) / circleSize * circleRepeat;
        int lastStart = size1 - (size1 - firstSize) % circleSize;
        repeatCnt += getLastRepeat(s1, n1, s2, lastStart);

        return repeatCnt / n2;
    }

    bool exist(string& s1, string& s2) {
        vector<bool> letters('z' + 1, false);

        for (char c : s1) {
            letters[c] = true;
        }

        for (char c : s2) {
            if (!letters[c]) {
                return false;  // s2有s1不存在的字符，无解
            }
        }

        return true;
    }

    int getCircle(string& s1, int n1, string& s2, int n2, int& firstSize, int& repeatCnt, int& circleRepeat) {
        int size1 = s1.size(), size2 = s2.size(), i, j = 0, repeat = 0, circleSize = 0;
        vector<pair<int, int>> endAt(size1, { -1,-1 });

        for (i = 0; circleSize == 0; ++i) {
            if (s1[i % size1] != s2[j]) {
                continue;
            }

            if (++j != size2) {
                continue;
            }

            j = 0;
            ++repeat;

            if (endAt[i % size1].first == -1) {
                endAt[i % size1] = { i,repeat };
            }
            else {
                circleSize = i - endAt[i % size1].first;
                firstSize = endAt[i % size1].first + 1;
                repeatCnt = endAt[i % size1].second;
                circleRepeat = repeat - endAt[i % size1].second;
            }
        }

        return circleSize;
    }

    int getLastRepeat(string& s1, int n1, string& s2, int lastStart) {
        int i, j = 0, size1 = s1.size(), size2 = s2.size(), repeat = 0;

        for (i = lastStart; i < size1 * n1; ++i) {
            if (s1[i % size1] == s2[j]) {
                if (++j == size2) {
                    j = 0;
                    ++repeat;
                }
            }
        }

        return repeat;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.getMaxRepetitions("acb", 4, "d", 2));
    check.checkInt(0, o.getMaxRepetitions("acb", 1, "acbacb", 1));
    check.checkInt(2, o.getMaxRepetitions("acb", 4, "ab", 2));
    check.checkInt(1, o.getMaxRepetitions("acb", 1, "acb", 1));
    check.checkInt(333, o.getMaxRepetitions("phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikef", 1000000, "fmznimkkasvwsrenzkycxfxtlsgypsfad", 333));
    check.checkInt(303, o.getMaxRepetitions("phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikeffmznimkkasvwsrenzkycxf", 1000000, "xtlsgypsfadpooefxzbcoejuvpvaboygpoeylfpbnpljvrvipyamyehwqnqrqpmxujjloovaowuxwhmsncbxcoksfzkvatxdknly", 100));
    check.checkInt(1, o.getMaxRepetitions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1000000, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1000000));
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
