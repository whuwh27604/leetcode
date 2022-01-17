/* 将字符串拆分为若干长度为 k 的组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串 s 可以按下述步骤划分为若干长度为 k 的组：

第一组由字符串中的前 k 个字符组成，第二组由接下来的 k 个字符串组成，依此类推。每个字符都能够成为 某一个 组的一部分。
对于最后一组，如果字符串剩下的字符 不足 k 个，需使用字符 fill 来补全这一组字符。
注意，在去除最后一个组的填充字符 fill（如果存在的话）并按顺序连接所有的组后，所得到的字符串应该是 s 。

给你一个字符串 s ，以及每组的长度 k 和一个用于填充的字符 fill ，按上述步骤处理之后，返回一个字符串数组，该数组表示 s 分组后 每个组的组成情况 。

 

示例 1：

输入：s = "abcdefghi", k = 3, fill = "x"
输出：["abc","def","ghi"]
解释：
前 3 个字符是 "abc" ，形成第一组。
接下来 3 个字符是 "def" ，形成第二组。
最后 3 个字符是 "ghi" ，形成第三组。
由于所有组都可以由字符串中的字符完全填充，所以不需要使用填充字符。
因此，形成 3 组，分别是 "abc"、"def" 和 "ghi" 。
示例 2：

输入：s = "abcdefghij", k = 3, fill = "x"
输出：["abc","def","ghi","jxx"]
解释：
与前一个例子类似，形成前三组 "abc"、"def" 和 "ghi" 。
对于最后一组，字符串中仅剩下字符 'j' 可以用。为了补全这一组，使用填充字符 'x' 两次。
因此，形成 4 组，分别是 "abc"、"def"、"ghi" 和 "jxx" 。
 

提示：

1 <= s.length <= 100
s 仅由小写英文字母组成
1 <= k <= 100
fill 是一个小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-a-string-into-groups-of-size-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i, size = s.size();
        string group;
        vector<string> groups;

        for (i = 0; i < size; ++i) {
            group += s[i];

            if ((i + 1) % k == 0) {
                groups.push_back(group);
                group.clear();
            }
        }

        if (!group.empty()) {
            group += string(k - group.size(), fill);
            groups.push_back(group);
        }

        return groups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.divideString("abcdefghi", 3, 'x');
    vector<string> expected = { "abc","def","ghi" };
    check.checkStringVector(expected, actual);

    actual = o.divideString("abcdefghij", 3, 'x');
    expected = { "abc","def","ghi","jxx" };
    check.checkStringVector(expected, actual);

    actual = o.divideString("abcdz", 1, 'x');
    expected = { "a","b","c","d","z" };
    check.checkStringVector(expected, actual);

    actual = o.divideString("z", 1, 'x');
    expected = { "z" };
    check.checkStringVector(expected, actual);

    actual = o.divideString("abcdedf", 10, 'x');
    expected = { "abcdedfxxx" };
    check.checkStringVector(expected, actual);
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
