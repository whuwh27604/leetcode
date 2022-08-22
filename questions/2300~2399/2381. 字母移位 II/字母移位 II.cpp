/* 字母移位 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个小写英文字母组成的字符串 s 和一个二维整数数组 shifts ，其中 shifts[i] = [starti, endi, directioni] 。对于每个 i ，将 s 中从下标 starti 到下标 endi （两者都包含）所有字符都进行移位运算，如果 directioni = 1 将字符向后移位，如果 directioni = 0 将字符向前移位。

将一个字符 向后 移位的意思是将这个字符用字母表中 下一个 字母替换（字母表视为环绕的，所以 'z' 变成 'a'）。类似的，将一个字符 向前 移位的意思是将这个字符用字母表中 前一个 字母替换（字母表是环绕的，所以 'a' 变成 'z' ）。

请你返回对 s 进行所有移位操作以后得到的最终字符串。

 

示例 1：

输入：s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
输出："ace"
解释：首先，将下标从 0 到 1 的字母向前移位，得到 s = "zac" 。
然后，将下标从 1 到 2 的字母向后移位，得到 s = "zbd" 。
最后，将下标从 0 到 2 的字符向后移位，得到 s = "ace" 。
示例 2:

输入：s = "dztz", shifts = [[0,0,0],[1,1,1]]
输出："catz"
解释：首先，将下标从 0 到 0 的字母向前移位，得到 s = "cztz" 。
最后，将下标从 1 到 1 的字符向后移位，得到 s = "catz" 。
 

提示：

1 <= s.length, shifts.length <= 5 * 104
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shifting-letters-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size = s.size();
        vector<int> diff(size + 1, 0);

        getDiff(shifts, diff);
        calcDiff(diff);
        shifting(s, diff);

        return s;
    }

    void getDiff(vector<vector<int>>& shifts, vector<int>& diff) {
        for (auto& shift : shifts) {
            if (shift[2] == 1) {
                ++diff[shift[0]];
                --diff[shift[1] + 1];
            }
            else {
                --diff[shift[0]];
                ++diff[shift[1] + 1];
            }
        }
    }

    void calcDiff(vector<int>& diff) {
        int sum = 0;

        for (int& num : diff) {
            sum += num;
            num = sum;
        }
    }

    void shifting(string& s, vector<int>& diff) {
        for (int i = 0; i < (int)s.size(); ++i) {
            int num = (s[i] - 'a' + 26 + diff[i] % 26) % 26;
            s[i] = 'a' + num;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> shifts = { {0,1,0},{1,2,1},{0,2,1} };
    check.checkString("ace", o.shiftingLetters("abc", shifts));

    shifts = { {0,0,0},{1,1,1} };
    check.checkString("catz", o.shiftingLetters("dztz", shifts));

    shifts = { {0,0,1} };
    check.checkString("a", o.shiftingLetters("z", shifts));

    shifts = { {0,0,0} };
    check.checkString("z", o.shiftingLetters("a", shifts));
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
