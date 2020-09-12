/* 模糊坐标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表中。

原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。

最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。

 

示例 1:
输入: "(123)"
输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
示例 2:
输入: "(00011)"
输出:  ["(0.001, 1)", "(0, 0.011)"]
解释:
0.0, 00, 0001 或 00.01 是不被允许的。
示例 3:
输入: "(0123)"
输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
示例 4:
输入: "(100)"
输出: [(10, 0)]
解释:
1.0 是不被允许的。
 

提示:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ambiguous-coordinates
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        S.erase(S.begin());
        S.pop_back();
        int i, j, k, size = S.size();
        vector<string> originals;

        for (i = 1; i < size; i++) {
            string integer1(S, 0, i), integer2(S, i, size - i);

            if (validInteger(integer1) && validInteger(integer2)) {
                originals.push_back('(' + integer1 + ", " + integer2 + ')');
            }

            if (validInteger(integer1)) {
                for (k = 1; k < (int)integer2.size(); k++) {
                    string decimal = integer2;
                    decimal.insert(k, 1, '.');

                    if (validDecimal(decimal, k)) {
                        originals.push_back('(' + integer1 + ", " + decimal + ')');
                    }
                }
            }

            for (j = 1; j < (int)integer1.size(); j++) {
                string decimal1 = integer1;
                decimal1.insert(j, 1, '.');

                if (!validDecimal(decimal1, j)) {
                    continue;
                }

                if (validInteger(integer2)) {
                    originals.push_back('(' + decimal1 + ", " + integer2 + ')');
                }

                for (k = 1; k < (int)integer2.size(); k++) {
                    string decimal2 = integer2;
                    decimal2.insert(k, 1, '.');

                    if (validDecimal(decimal2, k)) {
                        originals.push_back('(' + decimal1 + ", " + decimal2 + ')');
                    }
                }
            }
        }

        return originals;
    }

    bool validInteger(string& s) {
        return !((s[0] == '0') && (s.size() != 1));
    }

    bool validDecimal(string& s, int dotIndex) {
        string integer(s, 0, dotIndex);
        if (!validInteger(integer)) {
            return false;
        }

        return s[s.size() - 1] != '0';
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.ambiguousCoordinates("(123)");
    vector<string> expected = { "(1, 23)","(12, 3)","(1.2, 3)","(1, 2.3)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(00011)");
    expected = { "(0.001, 1)","(0, 0.011)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(0123)");
    expected = { "(0, 123)","(0, 12.3)","(0, 1.23)","(0.1, 23)","(0.1, 2.3)","(0.12, 3)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(100)");
    expected = { "(10, 0)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(10)");
    expected = { "(1, 0)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(01)");
    expected = { "(0, 1)" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.ambiguousCoordinates("(000)");
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);
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
