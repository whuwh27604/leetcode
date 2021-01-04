/* 较大分组的位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。

例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。

我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。

最终结果按照字典顺序输出。

示例 1:

输入: "abbxxxxzzy"
输出: [[3,6]]
解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
示例 2:

输入: "abc"
输出: []
解释: "a","b" 和 "c" 均不是符合要求的较大分组。
示例 3:

输入: "abcdddeeeeaabbbcd"
输出: [[3,5],[6,9],[12,14]]
说明:  1 <= S.length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/positions-of-large-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> positions;
        S += 'A';
        int i, size = S.size(), count = 1, start = 0;

        for (i = 1; i < size; i++) {
            if (S[i] == S[i - 1]) {
                count++;
            }
            else {
                if (count >= 3) {
                    positions.push_back({ start, i - 1 });
                }

                count = 1;
                start = i;
            }
        }

        return positions;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "abbxxxxzzy";
    vector<vector<int>> actual = o.largeGroupPositions(S);
    vector<vector<int>> expected = { {3,6} };
    check.checkIntVectorVector(expected, actual);

    S = "abc";
    actual = o.largeGroupPositions(S);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    S = "a";
    actual = o.largeGroupPositions(S);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    S = "abcdddeeeeaabbbcd";
    actual = o.largeGroupPositions(S);
    expected = { {3,5},{6,9},{12,14} };
    check.checkIntVectorVector(expected, actual);

    S = "aaa";
    actual = o.largeGroupPositions(S);
    expected = { {0,2} };
    check.checkIntVectorVector(expected, actual);
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
