/* 回文串分割 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。

当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。

 

示例 1：

输入：s = "abcbdd"
输出：true
解释："abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
示例 2：

输入：s = "bcbddxy"
输出：false
解释：s 没办法被分割成 3 个回文子字符串。
 

提示：

3 <= s.length <= 2000
s​​​​​​ 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Manacher {
public:
    Manacher(string& s) {
        preprocess(s);
        radii.resize(ms.size());
    }

    void preprocess(string& s) {
        ms += "@#";  // 首尾添加字符@、$，可以简化后面算法的边界处理

        for (char c : s) {
            ms += c;
            ms += '#';  // 每个字符前后插入#，可以使奇偶回文都变为奇回文，简化算法的处理
        }

        ms += '$';
    }

    void calculate() {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = ms.size();
        int center, maxRight = 0;

        for (i = 1; i < size - 1; i++) {
            if (i < maxRight) {
                /* （2 * center - i）是symmetryI，分三种情况可证明下面这句话成立：
                   1、radii[symmetryI]大于(symmetryI-symmetryMaxRight)，则radii[i]=(symmetryI-symmetryMaxRight)=(maxRight-i)，不能再大
                   2、radii[symmetryI]小于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]，不能再大
                   3、radii[symmetryI]等于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]=(maxRight-i)，然后执行下面的while语句继续拓展 */
                radii[i] = min(radii[2 * center - i], maxRight - i);
            }
            else {
                radii[i] = 1;
            }

            // 中心拓展找最大的半径，预处理在首尾添加的不同字符保证不会越界
            while (ms[i - radii[i]] == ms[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }
        }
    }

    bool isPalindrome(int start, int end) {
        return radii[(start + 1) + (end + 1)] / 2 >= (end - start + 2) / 2;
    }

private:
    string ms;
    vector<int> radii;
};

class Solution {
public:
    bool checkPartitioning(string s) {
        int midStart, midEnd, size = s.size();
        Manacher manacher(s);

        manacher.calculate();

        for (midStart = 1; midStart < size - 1; ++midStart) {
            for (midEnd = midStart; midEnd < size - 1; ++midEnd) {
                if (manacher.isPalindrome(0, midStart - 1) && manacher.isPalindrome(midStart, midEnd) && manacher.isPalindrome(midEnd + 1, size - 1)) {
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

    check.checkBool(true, o.checkPartitioning("abcbdd"));
    check.checkBool(true, o.checkPartitioning("abbaacddcaabbaabbaa"));
    check.checkBool(true, o.checkPartitioning("zbcbcbabc"));
    check.checkBool(true, o.checkPartitioning("abc"));
    check.checkBool(false, o.checkPartitioning("bcbddxy"));
    check.checkBool(false, o.checkPartitioning("acab"));
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
