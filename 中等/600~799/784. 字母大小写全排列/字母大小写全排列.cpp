/* 字母大小写全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

 

示例：
输入：S = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]

输入：S = "3z4"
输出：["3z4", "3Z4"]

输入：S = "12345"
输出：["12345"]
 

提示：

S 的长度不超过12。
S 仅由数字和字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> permutations = {""};

        for (char charactor : S) {
            if ((charactor >= '0') && (charactor <= '9')) {
                addNumber(permutations, charactor);
            }
            else if ((charactor >= 'a') && (charactor <= 'z')) {
                addCharactor(permutations, charactor);
            }
            else if ((charactor >= 'A') && (charactor <= 'Z')) {
                addCharactor(permutations, charactor + 32);
            }
        }

        return permutations;
    }

    void addNumber(vector<string>& permutations, char c) {
        for (string& permutation : permutations) {
            permutation.push_back(c);
        }
    }

    void addCharactor(vector<string>& permutations, char c) {
        int i, size = permutations.size();
        
        for (i = 0; i < size; i++) {
            permutations.push_back(permutations[i]);
            permutations[i].push_back(c);
            permutations[i + size].push_back(c - 32);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.letterCasePermutation("a1b2");
    vector<string> expected = { "a1b2","A1b2","a1B2","A1B2" };
    check.checkStringVector(expected, actual);

    actual = o.letterCasePermutation("3z4");
    expected = { "3z4","3Z4" };
    check.checkStringVector(expected, actual);

    actual = o.letterCasePermutation("12345");
    expected = { "12345" };
    check.checkStringVector(expected, actual);

    actual = o.letterCasePermutation("");
    expected = { "" };
    check.checkStringVector(expected, actual);
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
