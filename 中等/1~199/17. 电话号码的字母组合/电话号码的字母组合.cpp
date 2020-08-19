/* 电话号码的字母组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> num2char = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        list<string> ls;
        unsigned int i, j, k, len = digits.size();

        if (len == 0) {
            return {};
        }

        int number = digits[0] - '0';
        for (k = 0; k < num2char[number].size(); k++) {
            string s(1, num2char[number][k]);
            ls.push_back(s);
        }

        for (i = 1; i < len; i++) {
            number = digits[i] - '0';
            unsigned int lsSize = ls.size();
            for (j = 0; j < lsSize; j++) {
                string s = ls.front();
                ls.pop_front();

                for (k = 0; k < num2char[number].size(); k++) {
                    ls.push_back(s + num2char[number][k]);
                }
            }
        }

        vector<string> ans;
        for (auto iter = ls.begin(); iter != ls.end(); iter++) {
            ans.push_back(*iter);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.letterCombinations("23");
    vector<string> expected = { "ad","ae","af","bd","be","bf","cd","ce","cf" };
    check.checkStringVector(expected, actual);

    actual = o.letterCombinations("");
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.letterCombinations("8");
    expected = { "t","u","v" };
    check.checkStringVector(expected, actual);

    actual = o.letterCombinations("97");
    expected = { "wp","wq","wr","ws","xp","xq","xr","xs","yp","yq","yr","ys","zp","zq","zr","zs" };
    check.checkStringVector(expected, actual);

    actual = o.letterCombinations("456");
    expected = { "gjm","gjn","gjo","gkm","gkn","gko","glm","gln","glo","hjm","hjn","hjo","hkm","hkn","hko","hlm","hln","hlo","ijm","ijn","ijo","ikm","ikn","iko","ilm","iln","ilo" };
    check.checkStringVector(expected, actual);

    actual = o.letterCombinations("234567897");
    expected = {};
    //check.checkStringVector(expected, actual);
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
