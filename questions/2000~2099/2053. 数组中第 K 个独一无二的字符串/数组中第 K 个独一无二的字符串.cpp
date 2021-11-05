/* 数组中第 K 个独一无二的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
独一无二的字符串 指的是在一个数组中只出现过 一次 的字符串。

给你一个字符串数组 arr 和一个整数 k ，请你返回 arr 中第 k 个 独一无二的字符串 。如果 少于 k 个独一无二的字符串，那么返回 空字符串 "" 。

注意，按照字符串在原数组中的 顺序 找到第 k 个独一无二字符串。

 

示例 1:

输入：arr = ["d","b","c","b","c","a"], k = 2
输出："a"
解释：
arr 中独一无二字符串包括 "d" 和 "a" 。
"d" 首先出现，所以它是第 1 个独一无二字符串。
"a" 第二个出现，所以它是 2 个独一无二字符串。
由于 k == 2 ，返回 "a" 。
示例 2:

输入：arr = ["aaa","aa","a"], k = 1
输出："aaa"
解释：
arr 中所有字符串都是独一无二的，所以返回第 1 个字符串 "aaa" 。
示例 3：

输入：arr = ["a","b","a"], k = 3
输出：""
解释：
唯一一个独一无二字符串是 "b" 。由于少于 3 个独一无二字符串，我们返回空字符串 "" 。
 

提示：

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-distinct-string-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;

        for (string& str : arr) {
            ++count[str];
        }

        for (string& str : arr) {
            if (count[str] == 1) {
                if (--k == 0) {
                    return str;
                }
            }
        }

        return "";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> arr = { "d","b","c","b","c","a" };
    check.checkString("a", o.kthDistinct(arr, 2));

    arr = { "aaa","aa","a" };
    check.checkString("aaa", o.kthDistinct(arr, 1));

    arr = { "a","b","a" };
    check.checkString("", o.kthDistinct(arr, 3));
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
