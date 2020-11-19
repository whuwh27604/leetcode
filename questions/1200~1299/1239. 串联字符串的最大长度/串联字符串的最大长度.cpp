/* 串联字符串的最大长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26
 

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        vector<int> exist('z' + 1, 0);

        DFS(arr, exist, 0, 0, maxLen);
        return maxLen;
    }

    void DFS(vector<string>& arr, vector<int>& exist, int start, int len, int& maxLen) {
        maxLen = max(maxLen, len);
        int i, size = arr.size();

        for (i = start; i < size; ++i) {
            if (addExist(arr[i], exist)) {
                DFS(arr, exist, i + 1, len + arr[i].size(), maxLen);
                delExist(arr[i], exist);
            }
        }
    }

    bool addExist(string& s, vector<int>& exist) {
        int i, size = s.size();

        for (i = 0; i < size; ++i) {
            if (exist[s[i]] == 1) {
                break;
            }
            else {
                exist[s[i]] = 1;
            }
        }

        if (i == size) {
            return true;
        }

        for (i -= 1; i >= 0; --i) {
            exist[s[i]] = 0;
        }

        return false;
    }

    void delExist(string& s, vector<int>& exist) {
        for (char c : s) {
            exist[c] = 0;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> arr = { "un","iq","ue" };
    check.checkInt(4, o.maxLength(arr));

    arr = { "cha","r","act","ers" };
    check.checkInt(6, o.maxLength(arr));

    arr = { "abcdefghijklmnopqrstuvwxyz" };
    check.checkInt(26, o.maxLength(arr));

    arr = { "jnfbyktlrqumowxd","mvhgcpxnjzrdei" };
    check.checkInt(16, o.maxLength(arr));

    arr = { "a","d","df" };
    check.checkInt(3, o.maxLength(arr));

    arr = { "a" };
    check.checkInt(1, o.maxLength(arr));

    arr = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p" };
    check.checkInt(16, o.maxLength(arr));

    arr = { "yy","bkhwmpbiisbldzknpm" };
    check.checkInt(0, o.maxLength(arr));
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
