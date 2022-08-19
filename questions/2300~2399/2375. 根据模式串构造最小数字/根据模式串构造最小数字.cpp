/* 根据模式串构造最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。

你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：

num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
请你返回满足上述条件字典序 最小 的字符串 num。

 

示例 1：

输入：pattern = "IIIDIDDD"
输出："123549876"
解释：
下标 0 ，1 ，2 和 4 处，我们需要使 num[i] < num[i+1] 。
下标 3 ，5 ，6 和 7 处，我们需要使 num[i] > num[i+1] 。
一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
"123549876" 是满足条件最小的数字。
注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。
示例 2：

输入：pattern = "DDD"
输出："4321"
解释：
一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
"4321" 是满足条件最小的数字。
 

提示：

1 <= pattern.length <= 8
pattern 只包含字符 'I' 和 'D' 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/construct-smallest-number-from-di-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        char current = '1';
        int i, j, size = pattern.size();

        for (i = 0; i < size; ++i) {
            if (pattern[i] == 'I') {
                ans += current;
                current = '1' + (char)ans.size();
            }
            else {
                for (j = i + 1; j < size && pattern[j] == 'D'; ++j) {}
                int count = j - i;

                for (current += count; j != i; --j) {
                    ans += current--;
                }

                i += (count - 1);
            }
        }

        ans += current;

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("123549876", o.smallestNumber("IIIDIDDD"));
    check.checkString("4321", o.smallestNumber("DDD"));
    check.checkString("132546", o.smallestNumber("IDIDI"));
    check.checkString("12", o.smallestNumber("I"));
    check.checkString("21", o.smallestNumber("D"));
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
