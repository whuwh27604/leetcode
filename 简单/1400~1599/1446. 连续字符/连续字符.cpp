/* 连续字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

 

示例 1：

输入：s = "leetcode"
输出：2
解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
示例 2：

输入：s = "abbcccddddeeeeedcba"
输出：5
解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
示例 3：

输入：s = "triplepillooooow"
输出：5
示例 4：

输入：s = "hooraaaaaaaaaaay"
输出：11
示例 5：

输入：s = "tourist"
输出：1
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/consecutive-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int consecutive = 0, maxConsecutive = 0;;
        char last = '0';
        s += '0';

        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == last) {
                consecutive++;
                continue;
            }

            if (consecutive > maxConsecutive) {
                maxConsecutive = consecutive;
            }
            consecutive = 1;
            last = s[i];
        }

        return maxConsecutive;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.maxPower("leetcode"));
    check.checkInt(5, o.maxPower("abbcccddddeeeeedcba"));
    check.checkInt(5, o.maxPower("triplepillooooow"));
    check.checkInt(11, o.maxPower("hooraaaaaaaaaaay"));
    check.checkInt(12, o.maxPower("hooraaaaaaaaaaaa"));
    check.checkInt(1, o.maxPower("tourist"));
    check.checkInt(5, o.maxPower("aaaaabbb"));
    check.checkInt(4, o.maxPower("abbcdddeffffe"));
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
