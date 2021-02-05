/* “气球” 的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

 

示例 1：



输入：text = "nlaebolko"
输出：1
示例 2：



输入：text = "loonbalxballpoon"
输出：2
示例 3：

输入：text = "leetcode"
输出：0
 

提示：

1 <= text.length <= 10^4
text 全部由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        short charTable['z' + 1] = { 0 };
        for (unsigned int i = 0; i < text.size(); i++) {
            charTable[text[i]]++;
        }

        charTable['l'] /= 2;
        charTable['o'] /= 2;

        return min(charTable['a'], min(charTable['b'], min(charTable['l'], min(charTable['o'], charTable['n']))));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.maxNumberOfBalloons("nlaebolko"));
    check.checkInt(2, o.maxNumberOfBalloons("loonbalxballpoon"));
    check.checkInt(0, o.maxNumberOfBalloons("leetcode"));
    check.checkInt(0, o.maxNumberOfBalloons(""));
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
