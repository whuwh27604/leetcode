/* 字符串中的第一个唯一字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count('z' + 1, 0), firstIndices('z' + 1, 0);
        int i, size = s.size(), firstUniqIndex = INT_MAX;

        for (i = 0; i < size; ++i) {
            if (++count[s[i]] == 1) {
                firstIndices[s[i]] = i;
            }
        }

        for (i = 'a'; i <= 'z'; ++i) {
            if (count[i] == 1) {
                firstUniqIndex = min(firstUniqIndex, firstIndices[i]);
            }
        }

        return firstUniqIndex == INT_MAX ? -1 : firstUniqIndex;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "leetcode";
    check.checkInt(0, o.firstUniqChar(s));

    s = "loveleetcode";
    check.checkInt(2, o.firstUniqChar(s));

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    check.checkInt(60, o.firstUniqChar(s));

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz";
    check.checkInt(60, o.firstUniqChar(s));

    s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzza";
    check.checkInt(60, o.firstUniqChar(s));

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    check.checkInt(-1, o.firstUniqChar(s));

    s = "";
    check.checkInt(-1, o.firstUniqChar(s));

    s = "z";
    check.checkInt(0, o.firstUniqChar(s));
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
