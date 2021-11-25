/* 两个回文子字符串长度的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s ，你需要找到两个 不重叠的回文 子字符串，它们的长度都必须为 奇数 ，使得它们长度的乘积最大。

更正式地，你想要选择四个整数 i ，j ，k ，l ，使得 0 <= i <= j < k <= l < s.length ，且子字符串 s[i...j] 和 s[k...l] 都是回文串且长度为奇数。s[i...j] 表示下标从 i 到 j 且 包含 两端下标的子字符串。

请你返回两个不重叠回文子字符串长度的 最大 乘积。

回文字符串 指的是一个从前往后读和从后往前读一模一样的字符串。子字符串 指的是一个字符串中一段连续字符。

 

示例 1：

输入：s = "ababbb"
输出：9
解释：子字符串 "aba" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。
示例 2：

输入：s = "zaaaxbbby"
输出：9
解释：子字符串 "aaa" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。
 

提示：

2 <= s.length <= 105
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxProduct(string s) {
        int size = s.size();
        vector<int> radii(size, 1);
        vector<int> left(size, 1), right(size, 1);

        manacher(s, radii);  // 求任意一点的最长半径，a是1，aba是2...
        getLeft(radii, left);  // 求区间s[0, i]的最长回文串
        getRight(radii, right);  // 求区间s[i, size)的最长回文串

        return getMaxProduct(left, right);
    }

    void manacher(string& s, vector<int>& radii) {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = s.size();
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

            // 中心拓展找最大的半径
            while (i >= radii[i] && i + radii[i] < size && s[i - radii[i]] == s[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }
        }
    }

    void getLeft(vector<int>& radii, vector<int>& left) {
        for (int i = 1, j = 0; i < (int)radii.size(); ++i) {
            while (j + radii[j] <= i) {  // 双指针，每次找到第一个可以够到位置i的回文串中心j
                ++j;
            }

            left[i] = max(left[i - 1], 2 * (i - j) + 1);
        }
    }

    void getRight(vector<int>& radii, vector<int>& right) {
        for (int i = radii.size() - 2, j = i + 1; i >= 0; --i) {
            while (j - radii[j] >= i) {
                --j;
            }

            right[i] = max(right[i + 1], 2 * (j - i) + 1);
        }
    }

    long long getMaxProduct(vector<int>& left, vector<int>& right) {
        long long product = 0;

        for (int i = 0; i < (int)left.size() - 1; ++i) {
            product = max(product, (long long)left[i] * right[i + 1]);
        }

        return product;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(9, o.maxProduct("ababbb"));
    check.checkLongLong(9, o.maxProduct("zaaaxbbby"));
    check.checkLongLong(1, o.maxProduct("az"));
    check.checkLongLong(15, o.maxProduct("zzzzzzzz"));
    check.checkLongLong(2115, o.maxProduct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
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
