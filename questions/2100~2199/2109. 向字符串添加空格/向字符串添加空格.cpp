/* 向字符串添加空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s ，以及一个下标从 0 开始的整数数组 spaces 。

数组 spaces 描述原字符串中需要添加空格的下标。每个空格都应该插入到给定索引处的字符值 之前 。

例如，s = "EnjoyYourCoffee" 且 spaces = [5, 9] ，那么我们需要在 'Y' 和 'C' 之前添加空格，这两个字符分别位于下标 5 和下标 9 。因此，最终得到 "Enjoy Your Coffee" 。
请你添加空格，并返回修改后的字符串。

 

示例 1：

输入：s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
输出："Leetcode Helps Me Learn"
解释：
下标 8、13 和 15 对应 "LeetcodeHelpsMeLearn" 中加粗斜体字符。
接着在这些字符前添加空格。
示例 2：

输入：s = "icodeinpython", spaces = [1,5,7,9]
输出："i code in py thon"
解释：
下标 1、5、7 和 9 对应 "icodeinpython" 中加粗斜体字符。
接着在这些字符前添加空格。
示例 3：

输入：s = "spacing", spaces = [0,1,2,3,4,5,6]
输出：" s p a c i n g"
解释：
字符串的第一个字符前可以添加空格。
 

提示：

1 <= s.length <= 3 * 105
s 仅由大小写英文字母组成
1 <= spaces.length <= 3 * 105
0 <= spaces[i] <= s.length - 1
spaces 中的所有值 严格递增

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/adding-spaces-to-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i, j = 0, k = 0, size1 = s.size(), size2 = spaces.size();
        string ans(size1 + size2, 0);

        for (i = 0; i < size1; ++i) {
            if (k < size2 && i == spaces[k]) {
                ans[j++] = ' ';
                ++k;
            }

            ans[j++] = s[i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> spaces = { 8,13,15 };
    check.checkString("Leetcode Helps Me Learn", o.addSpaces("LeetcodeHelpsMeLearn", spaces));

    spaces = { 1,5,7,9 };
    check.checkString("i code in py thon", o.addSpaces("icodeinpython", spaces));

    spaces = { 0,1,2,3,4,5,6 };
    check.checkString(" s p a c i n g", o.addSpaces("spacing", spaces));
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
