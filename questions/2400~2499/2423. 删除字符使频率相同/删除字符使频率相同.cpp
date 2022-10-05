/* 删除字符使频率相同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 word ，字符串只包含小写英文字母。你需要选择 一个 下标并 删除 下标处的字符，使得 word 中剩余每个字母出现 频率 相同。

如果删除一个字母后，word 中剩余所有字母的出现频率都相同，那么返回 true ，否则返回 false 。

注意：

字母 x 的 频率 是这个字母在字符串中出现的次数。
你 必须 恰好删除一个字母，不能一个字母都不删除。
 

示例 1：

输入：word = "abcc"
输出：true
解释：选择下标 3 并删除该字母，word 变成 "abc" 且每个字母出现频率都为 1 。
示例 2：

输入：word = "aazz"
输出：false
解释：我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2 ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
 

提示：

2 <= word.length <= 100
word 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-letter-to-equalize-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> counts(26, 0);

        for (char c : word) {
            ++counts[c - 'a'];
        }

        for (int& count : counts) {
            if (count != 0) {
                --count;

                if (isEqual(counts)) {
                    return true;
                }

                ++count;
            }
        }

        return false;
    }

    bool isEqual(vector<int>& counts) {
        int freq = 0;

        for (int count : counts) {
            if (freq == 0) {
                freq = count;
            }

            if (count != 0 && count != freq) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.equalFrequency("abcc"));
    check.checkBool(true, o.equalFrequency("zz"));
    check.checkBool(true, o.equalFrequency("abcc"));
    check.checkBool(true, o.equalFrequency("aabbc"));
    check.checkBool(false, o.equalFrequency("aazz"));
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
