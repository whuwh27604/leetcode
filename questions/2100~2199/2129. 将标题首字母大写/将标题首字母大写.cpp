/* 将标题首字母大写.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 大写 ：

如果单词的长度为 1 或者 2 ，所有字母变成小写。
否则，将单词首字母大写，剩余字母变成小写。
请你返回 大写后 的 title 。

 

示例 1：

输入：title = "capiTalIze tHe titLe"
输出："Capitalize The Title"
解释：
由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。
示例 2：

输入：title = "First leTTeR of EACH Word"
输出："First Letter of Each Word"
解释：
单词 "of" 长度为 2 ，所以它保持完全小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
示例 3：

输入：title = "i lOve leetcode"
输出："i Love Leetcode"
解释：
单词 "i" 长度为 1 ，所以它保留小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
 

提示：

1 <= title.length <= 100
title 由单个空格隔开的单词组成，且不含有任何前导或后缀空格。
每个单词由大写和小写英文字母组成，且都是 非空 的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/capitalize-the-title
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int i, index = 0, size = title.size();

        for (i = 0; i < size; ++i) {
            if (title[i] == ' ') {
                if (i - index > 2) {
                    title[index] -= 32;  // 长度大于2，首字母大写
                }

                index = i + 1;
            }
            else {
                if (title[i] < 'a') {
                    title[i] += 32;  // 如果是大写则转小写
                }
            }
        }

        if (i - index > 2) {  // 最后一个单词
            title[index] -= 32;
        }

        return title;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("Capitalize The Title", o.capitalizeTitle("capiTalIze tHe titLe"));
    check.checkString("First Letter of Each Word", o.capitalizeTitle("First leTTeR of EACH Word"));
    check.checkString("i Love Leetcode", o.capitalizeTitle("i lOve leetcode"));
    check.checkString("i", o.capitalizeTitle("i"));
    check.checkString("l", o.capitalizeTitle("L"));
    check.checkString("Leetcode", o.capitalizeTitle("leetcode"));
    check.checkString("Leetcode", o.capitalizeTitle("Leetcode"));
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
