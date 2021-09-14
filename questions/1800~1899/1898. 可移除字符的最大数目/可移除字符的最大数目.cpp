/* 可移除字符的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 p ，其中 p 是 s 的一个 子序列 。同时，给你一个元素 互不相同 且下标 从 0 开始 计数的整数数组 removable ，该数组是 s 中下标的一个子集（s 的下标也 从 0 开始 计数）。

请你找出一个整数 k（0 <= k <= removable.length），选出 removable 中的 前 k 个下标，然后从 s 中移除这些下标对应的 k 个字符。整数 k 需满足：在执行完上述步骤后， p 仍然是 s 的一个 子序列 。更正式的解释是，对于每个 0 <= i < k ，先标记出位于 s[removable[i]] 的字符，接着移除所有标记过的字符，然后检查 p 是否仍然是 s 的一个子序列。

返回你可以找出的 最大 k ，满足在移除字符后 p 仍然是 s 的一个子序列。

字符串的一个 子序列 是一个由原字符串生成的新字符串，生成过程中可能会移除原字符串中的一些字符（也可能不移除）但不改变剩余字符之间的相对顺序。

 

示例 1：

输入：s = "abcacb", p = "ab", removable = [3,1,0]
输出：2
解释：在移除下标 3 和 1 对应的字符后，"abcacb" 变成 "accb" 。
"ab" 是 "accb" 的一个子序列。
如果移除下标 3、1 和 0 对应的字符后，"abcacb" 变成 "ccb" ，那么 "ab" 就不再是 s 的一个子序列。
因此，最大的 k 是 2 。
示例 2：

输入：s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
输出：1
解释：在移除下标 3 对应的字符后，"abcbddddd" 变成 "abcddddd" 。
"abcd" 是 "abcddddd" 的一个子序列。
示例 3：

输入：s = "abcab", p = "abc", removable = [0,1,2,3,4]
输出：0
解释：如果移除数组 removable 的第一个下标，"abc" 就不再是 s 的一个子序列。
 

提示：

1 <= p.length <= s.length <= 105
0 <= removable.length < s.length
0 <= removable[i] < s.length
p 是 s 的一个 子字符串
s 和 p 都由小写英文字母组成
removable 中的元素 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-removable-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int size = removable.size(), left = 0, right = size - 1, maxIndex = -1;

        while (left <= right) {
            int middle = (left + right) / 2;
            flip(s, removable, left, middle);

            if (isSubseq(s, p)) {
                maxIndex = middle;
                left = middle + 1;
            }
            else {
                flip(s, removable, left, middle);
                right = middle - 1;
            }
        }

        return maxIndex + 1;
    }

    bool isSubseq(string& s, string& p) {
        int i = -1, size = s.size();

        for (char c : p) {
            for (i += 1; i < size && s[i] != c; ++i) {}
            if (i == size) {
                return false;
            }
        }

        return true;
    }

    void flip(string& s, vector<int>& removable, int left, int right) {
        for (int i = left; i <= right; ++i) {
            s[removable[i]] = -s[removable[i]];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> removable = { 3,1,0 };
    check.checkInt(2, o.maximumRemovals("abcacb", "ab", removable));

    removable = { 3,2,1,4,5,6 };
    check.checkInt(1, o.maximumRemovals("abcbddddd", "abcd", removable));

    removable = { 0,1,2,3,4 };
    check.checkInt(0, o.maximumRemovals("abcab", "abc", removable));

    removable = {  };
    check.checkInt(0, o.maximumRemovals("abcacb", "ab", removable));

    removable = { 5,3,0,6,4,9,10,7,2,8 };
    check.checkInt(7, o.maximumRemovals("qobftgcueho", "obue", removable));
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
