/* 判断句子是否为全字母句.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
全字母句 指包含英语字母表中每个字母至少一次的句子。

给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。

如果是，返回 true ；否则，返回 false 。

 

示例 1：

输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
输出：true
解释：sentence 包含英语字母表中每个字母至少一次。
示例 2：

输入：sentence = "leetcode"
输出：false
 

提示：

1 <= sentence.length <= 1000
sentence 由小写英语字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-the-sentence-is-pangram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> letters('z' + 1, false);
        int count = 0;

        for (char c : sentence) {
            if (!letters[c]) {
                letters[c] = true;
                if (++count == 26) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.checkIfPangram("z"));
    check.checkBool(true, o.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));
    check.checkBool(false, o.checkIfPangram("thequickbrownfoxjumpsoverthelazydod"));
    check.checkBool(false, o.checkIfPangram("leetcode"));
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
