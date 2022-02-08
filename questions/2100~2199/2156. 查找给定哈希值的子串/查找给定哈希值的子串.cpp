/* 查找给定哈希值的子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定整数 p 和 m ，一个长度为 k 且下标从 0 开始的字符串 s 的哈希值按照如下函数计算：

hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.
其中 val(s[i]) 表示 s[i] 在字母表中的下标，从 val('a') = 1 到 val('z') = 26 。

给你一个字符串 s 和整数 power，modulo，k 和 hashValue 。请你返回 s 中 第一个 长度为 k 的 子串 sub ，满足 hash(sub, power, modulo) == hashValue 。

测试数据保证一定 存在 至少一个这样的子串。

子串 定义为一个字符串中连续非空字符组成的序列。

 

示例 1：

输入：s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
输出："ee"
解释："ee" 的哈希值为 hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0 。
"ee" 是长度为 2 的第一个哈希值为 0 的子串，所以我们返回 "ee" 。
示例 2：

输入：s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
输出："fbx"
解释："fbx" 的哈希值为 hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 312) mod 100 = 23132 mod 100 = 32 。
"bxz" 的哈希值为 hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 312) mod 100 = 25732 mod 100 = 32 。
"fbx" 是长度为 3 的第一个哈希值为 32 的子串，所以我们返回 "fbx" 。
注意，"bxz" 的哈希值也为 32 ，但是它在字符串中比 "fbx" 更晚出现。
 

提示：

1 <= k <= s.length <= 2 * 104
1 <= power, modulo <= 109
0 <= hashValue < modulo
s 只包含小写英文字母。
测试数据保证一定 存在 满足条件的子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-substring-with-given-hash-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int i, size = s.size(), index = 0;
        long long value = 0, kPower = 1;

        for (i = size - 1; i > size - k; --i) {
            value = (value * power + s[i] - 'a' + 1) % modulo;
            kPower = (kPower * power) % modulo;
        }

        value = (value * power + s[i] - 'a' + 1) % modulo;
        if (value == hashValue) {
            index = i;
        }

        for (--i; i >= 0; --i) {
            value = ((value + modulo - ((long long)s[i + k] - 'a' + 1) * kPower % modulo) % modulo * power + s[i] - 'a' + 1) % modulo;
            if (value == hashValue) {
                index = i;
            }
        }

        return string(s, index, k);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("ee", o.subStrHash("leetcode", 7, 20, 2, 0));
    check.checkString("fbx", o.subStrHash("fbxzaad", 31, 100, 3, 32));
    check.checkString("leetc", o.subStrHash("leetcodeleetcodeleetcodeleetcode", 999999999, 3, 5, 0));
    check.checkString("delee", o.subStrHash("leetcodeleetcodeleetcodeleetcode", 999999999, 3, 5, 1));
    check.checkString("eetco", o.subStrHash("leetcodeleetcodeleetcodeleetcode", 999999999, 3, 5, 2));
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
