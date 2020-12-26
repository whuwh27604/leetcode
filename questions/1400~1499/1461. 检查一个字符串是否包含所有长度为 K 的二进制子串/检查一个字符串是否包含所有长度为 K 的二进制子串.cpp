/* 检查一个字符串是否包含所有长度为 K 的二进制子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 和一个整数 k 。

如果所有长度为 k 的二进制字符串都是 s 的子串，请返回 True ，否则请返回 False 。

 

示例 1：

输入：s = "00110110", k = 2
输出：true
解释：长度为 2 的二进制串包括 "00"，"01"，"10" 和 "11"。它们分别是 s 中下标为 0，1，3，2 开始的长度为 2 的子串。
示例 2：

输入：s = "00110", k = 2
输出：true
示例 3：

输入：s = "0110", k = 1
输出：true
解释：长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
示例 4：

输入：s = "0110", k = 2
输出：false
解释：长度为 2 的二进制串 "00" 没有出现在 s 中。
示例 5：

输入：s = "0000000001011100", k = 4
输出：false
 

提示：

1 <= s.length <= 5 * 10^5
s 中只含 0 和 1 。
1 <= k <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int size = s.size(), len = (int)pow(2, k);
        if (size < len + k - 1) {
            return false;
        }

        vector<int> nums(len, 0);
        int i, num = 0, mask = ~(1 << (k - 1));

        for (i = 0; i < k; ++i) {
            num <<= 1;
            num |= (s[i] == '0' ? 0 : 1);
        }

        nums[num] = 1;

        for (i = k; i < size; ++i) {
            num &= mask;
            num <<= 1;
            num |= (s[i] == '0' ? 0 : 1);
            nums[num] = 1;
        }

        for (i = 0; i < len; ++i) {
            if (nums[i] == 0) {
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

    check.checkBool(true, o.hasAllCodes("00110110", 2));
    check.checkBool(true, o.hasAllCodes("00110", 2));
    check.checkBool(true, o.hasAllCodes("0110", 1));
    check.checkBool(false, o.hasAllCodes("0110", 2));
    check.checkBool(false, o.hasAllCodes("0000000001011100", 4));
    check.checkBool(true, o.hasAllCodes("10010011", 2));
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
