/* 检测大写字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-capital
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int i, len = word.size();
        if (len == 1) {
            return true;
        }

        if ((word[0] >= 'a') && (word[1] < 'a')) {
            return false;
        }

        if (word[1] >= 'a') {
            for (i = 2; i < len; i++) {
                if (word[i] < 'a') {
                    return false;
                }
            }
        }
        else {
            for (i = 2; i < len; i++) {
                if (word[i] >= 'a') {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.detectCapitalUse("USA"));
    check.checkBool(false, o.detectCapitalUse("flaG"));
    check.checkBool(true, o.detectCapitalUse("U"));
    check.checkBool(true, o.detectCapitalUse("a"));
    check.checkBool(true, o.detectCapitalUse("US"));
    check.checkBool(true, o.detectCapitalUse("us"));
    check.checkBool(true, o.detectCapitalUse("Us"));
    check.checkBool(false, o.detectCapitalUse("uS"));
    check.checkBool(true, o.detectCapitalUse("USA"));
    check.checkBool(false, o.detectCapitalUse("USa"));
    check.checkBool(false, o.detectCapitalUse("uSA"));
    check.checkBool(false, o.detectCapitalUse("uSa"));
    check.checkBool(true, o.detectCapitalUse("Usa"));
    check.checkBool(false, o.detectCapitalUse("UsA"));
    check.checkBool(true, o.detectCapitalUse("usa"));
    check.checkBool(false, o.detectCapitalUse("usA"));
    check.checkBool(true, o.detectCapitalUse("AAAAA"));
    check.checkBool(false, o.detectCapitalUse("AAAAa"));
    check.checkBool(true, o.detectCapitalUse("Aaaaa"));
    check.checkBool(false, o.detectCapitalUse("AaaaA"));
    check.checkBool(true, o.detectCapitalUse("aaaaa"));
    check.checkBool(false, o.detectCapitalUse("aaaaA"));
    check.checkBool(false, o.detectCapitalUse("aAAAA"));
    check.checkBool(false, o.detectCapitalUse("aAAAa"));
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
