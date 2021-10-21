/* 检查句子中的数字是否递增.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
句子是由若干 token 组成的一个列表，token 间用 单个 空格分隔，句子没有前导或尾随空格。每个 token 要么是一个由数字 0-9 组成的不含前导零的 正整数 ，要么是一个由小写英文字母组成的 单词 。

示例，"a puppy has 2 eyes 4 legs" 是一个由 7 个 token 组成的句子："2" 和 "4" 是数字，其他像 "puppy" 这样的 tokens 属于单词。
给你一个表示句子的字符串 s ，你需要检查 s 中的 全部 数字是否从左到右严格递增（即，除了最后一个数字，s 中的 每个 数字都严格小于它 右侧 的数字）。

如果满足题目要求，返回 true ，否则，返回 false 。

 

示例 1：



输入：s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
输出：true
解释：句子中的数字是：1, 3, 4, 6, 12 。
这些数字是按从左到右严格递增的 1 < 3 < 4 < 6 < 12 。
示例 2：

输入：s = "hello world 5 x 5"
输出：false
解释：句子中的数字是：5, 5 。这些数字不是严格递增的。
示例 3：



输入：s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
输出：false
解释：s 中的数字是：7, 51, 50, 60 。这些数字不是严格递增的。
示例 4：

输入：s = "4 5 11 26"
输出：true
解释：s 中的数字是：4, 5, 11, 26 。
这些数字是按从左到右严格递增的：4 < 5 < 11 < 26 。
 

提示：

3 <= s.length <= 200
s 由小写英文字母、空格和数字 0 到 9 组成（包含 0 和 9）
s 中数字 token 的数目在 2 和 100 之间（包含 2 和 100）
s 中的 token 之间由单个空格分隔
s 中至少有 两个 数字
s 中的每个数字都是一个 小于 100 的 正 数，且不含前导零
s 不含前导或尾随空格

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-numbers-are-ascending-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

bool operator< (const string& num1, const string& num2) {
    if (num1.size() != num2.size()) {
        return num1.size() < num2.size();
    }

    for (unsigned int i = 0; i < num1.size(); ++i) {
        if (num1[i] != num2[i]) {
            return num1[i] < num2[i];
        }
    }

    return false;
}

class Solution {
public:
    bool areNumbersAscending(string s) {
        char* p = const_cast<char*>(s.c_str());
        char* context;
        string prev = "0";

        p = strtok_s(p, " ", &context);

        while (p != NULL) {
            string token(p);

            if (token[0] > 0 && token[0] <= '9') {
                if (!(prev < token)) {
                    return false;
                }

                prev = token;
            }

            p = strtok_s(NULL, " ", &context);
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles"));
    check.checkBool(false, o.areNumbersAscending("hello world 5 x 5"));
    check.checkBool(false, o.areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"));
    check.checkBool(true, o.areNumbersAscending("4 5 11 26"));
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
