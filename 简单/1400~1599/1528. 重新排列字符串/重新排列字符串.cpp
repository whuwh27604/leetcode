/* 重新排列字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。

请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。

返回重新排列后的字符串。

 

示例 1：



输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
输出："leetcode"
解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
示例 2：

输入：s = "abc", indices = [0,1,2]
输出："abc"
解释：重新排列后，每个字符都还留在原来的位置上。
示例 3：

输入：s = "aiohn", indices = [3,1,4,2,0]
输出："nihao"
示例 4：

输入：s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
输出："arigatou"
示例 5：

输入：s = "art", indices = [1,0,2]
输出："rat"
 

提示：

s.length == indices.length == n
1 <= n <= 100
s 仅包含小写英文字母。
0 <= indices[i] < n
indices 的所有的值都是唯一的（也就是说，indices 是整数 0 到 n - 1 形成的一组排列）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i, size = s.size();
        string restored(size, 0);

        for (i = 0; i < size; i++) {
            restored[indices[i]] = s[i];
        }

        return restored;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> indices = { 4,5,6,7,0,2,1,3 };
    check.checkString("leetcode", o.restoreString("codeleet", indices));

    indices = { 0,1,2 };
    check.checkString("abc", o.restoreString("abc", indices));

    indices = { 3,1,4,2,0 };
    check.checkString("nihao", o.restoreString("aiohn", indices));

    indices = { 4,0,2,6,7,3,1,5 };
    check.checkString("arigatou", o.restoreString("aaiougrt", indices));

    indices = { 1,0,2 };
    check.checkString("rat", o.restoreString("art", indices));
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
