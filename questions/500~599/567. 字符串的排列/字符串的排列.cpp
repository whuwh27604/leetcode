/* 字符串的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charCount(26, 0);
        for (char c : s1) {
            charCount[c - 'a']++;
        }

        vector<int> bakCharCount = charCount;
        int left = 0, right = 0, size1 = s1.size(), size2 = s2.size();
        while (right < size2) {
            char cRight = s2[right++];
            if (charCount[cRight - 'a'] != 0) {
                if (right - left == size1) {
                    return true;  // 匹配上s1的字符，扩展窗口。如果能扩展到s1的大小，说明找到一个解。
                }
                charCount[cRight - 'a']--;
                continue;
            }

            while (left < right) {
                char cLeft = s2[left++];
                if (bakCharCount[cLeft - 'a'] == 0) {
                    continue;  // 不是s1中字符，窗口一直收缩到right
                }

                if (cLeft == cRight) {
                    break;  // 是s1中字符，但是个数多了，窗口收缩到移除一个c
                }
                charCount[cLeft - 'a']++;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.checkInclusion("ab", "eidbaooo"));
    check.checkBool(false, o.checkInclusion("ab", "eidboaoo"));
    check.checkBool(true, o.checkInclusion("a", "a"));
    check.checkBool(false, o.checkInclusion("a", "b"));
    check.checkBool(true, o.checkInclusion("a", "ab"));
    check.checkBool(true, o.checkInclusion("ab", "ab"));
    check.checkBool(true, o.checkInclusion("abc", "cba"));
    check.checkBool(true, o.checkInclusion("abc", "bbbca"));
    check.checkBool(true, o.checkInclusion("dac", "dcda"));
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
