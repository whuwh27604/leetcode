/* 检查是否所有 A 都在 B 之前.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。

 

示例 1：

输入：s = "aaabbb"
输出：true
解释：
'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
示例 2：

输入：s = "abab"
输出：false
解释：
存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
示例 3：

输入：s = "bbb"
输出：true
解释：
不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
 

提示：

1 <= s.length <= 100
s[i] 为 'a' 或 'b'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-all-as-appears-before-all-bs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int i, size = s.size();

        for (i = 0; i < size && s[i] == 'a'; ++i) {}

        for (; i < size; ++i) {
            if (s[i] == 'a') {
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

    check.checkBool(true, o.checkString("a"));
    check.checkBool(true, o.checkString("aaabbb"));
    check.checkBool(false, o.checkString("abab"));
    check.checkBool(true, o.checkString("bbb"));
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
