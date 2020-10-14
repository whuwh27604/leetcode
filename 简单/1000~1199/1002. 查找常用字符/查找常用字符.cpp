/* 查找常用字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        char* charTable = new char[len * 26];
        memset(charTable, 0, len * 26);

        for (int i = 0; i < len; i++) {
            string word = A[i];
            for (unsigned int j = 0; j < word.size(); j++) {
                charTable[i * 26 + word[j] - 'a']++;
            }
        }

        vector<string> ans;
        for (int m = 0; m < 26; m++) {
            char minTimes = 127;
            for (int n = 0; n < len; n++) {
                minTimes = min(minTimes, charTable[n * 26 + m]);
                if (charTable[n * 26 + m] == 0) {
                    break;
                }
            }

            if (minTimes == 0) {
                continue;
            }

            for (int l = 0; l < minTimes; l++) {
                string commonChar(1, (char)('a' + m));
                ans.push_back(commonChar);
            }
        }

        delete[] charTable;

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> A = { "bella","label","roller" };
    vector<string> actual = o.commonChars(A);
    vector<string> expected = { "e","l","l" };
    check.checkStringVector(expected, actual);

    A = { "cool","lock","cook" };
    actual = o.commonChars(A);
    expected = { "c","o" };
    check.checkStringVector(expected, actual);

    A = { "cool" };
    actual = o.commonChars(A);
    expected = { "c","l","o","o" };
    check.checkStringVector(expected, actual);

    A = { "abc","def" };
    actual = o.commonChars(A);
    expected = {  };
    check.checkStringVector(expected, actual);

    A = { "abcc","abcc","abcc" };
    actual = o.commonChars(A);
    expected = { "a","b","c","c" };
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
