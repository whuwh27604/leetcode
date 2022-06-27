/* 统计星号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，每 两个 连续竖线 '|' 为 一对 。换言之，第一个和第二个 '|' 为一对，第三个和第四个 '|' 为一对，以此类推。

请你返回 不在 竖线对之间，s 中 '*' 的数目。

注意，每个竖线 '|' 都会 恰好 属于一个对。

 

示例 1：

输入：s = "l|*e*et|c**o|*de|"
输出：2
解释：不在竖线对之间的字符加粗加斜体后，得到字符串："l|*e*et|c**o|*de|" 。
第一和第二条竖线 '|' 之间的字符不计入答案。
同时，第三条和第四条竖线 '|' 之间的字符也不计入答案。
不在竖线对之间总共有 2 个星号，所以我们返回 2 。
示例 2：

输入：s = "iamprogrammer"
输出：0
解释：在这个例子中，s 中没有星号。所以返回 0 。
示例 3：

输入：s = "yo|uar|e**|b|e***au|tifu|l"
输出：5
解释：需要考虑的字符加粗加斜体后："yo|uar|e**|b|e***au|tifu|l" 。不在竖线对之间总共有 5 个星号。所以我们返回 5 。
 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母，竖线 '|' 和星号 '*' 。
s 包含 偶数 个竖线 '|' 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-asterisks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int stars = 0, bars = 0;

        for (char c : s) {
            if (c == '|') {
                ++bars;
            }
            else if (c == '*' && bars % 2 == 0) {
                ++stars;
            }
        }

        return stars;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.countAsterisks("l|*e*et|c**o|*de|"));
    check.checkInt(0, o.countAsterisks("iamprogrammer"));
    check.checkInt(5, o.countAsterisks("yo|uar|e**|b|e***au|tifu|l"));
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
