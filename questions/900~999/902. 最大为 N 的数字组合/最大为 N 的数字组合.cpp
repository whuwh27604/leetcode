/* 最大为 N 的数字组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个按 非递减顺序 排列的数字数组 digits 。你可以用任意次数 digits[i] 来写的数字。例如，如果 digits = ['1','3','5']，我们可以写数字，如 '13', '551', 和 '1351315'。

返回 可以生成的小于或等于给定整数 n 的正整数的个数 。

 

示例 1：

输入：digits = ["1","3","5","7"], n = 100
输出：20
解释：
可写出的 20 个数字是：
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
示例 2：

输入：digits = ["1","4","9"], n = 1000000000
输出：29523
解释：
我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。
总共，可以使用D中的数字写出 29523 个整数。
示例 3:

输入：digits = ["7"], n = 8
输出：1
 

提示：

1 <= digits.length <= 9
digits[i].length == 1
digits[i] 是从 '1' 到 '9' 的数
digits 中的所有值都 不同 
digits 按 非递减顺序 排列
1 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/numbers-at-most-n-given-digit-set
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int size1 = digits.size(), size2 = num.size(), count = 0;

        vector<bool> exist('9' + 1, false);
        digitExist(digits, exist);

        for (int i = 1; i < size2; ++i) {
            count += (int)pow(size1, i);
        }

        for (int i = 0; i < size2; ++i) {
            count += countLess(digits, num[i]) * (int)pow(size1, size2 - 1 - i);

            if (!exist[num[i]]) {
                break;
            }
        }

        return allExist(num, exist) ? count + 1 : count;
    }

    void digitExist(vector<string>& digits, vector<bool>& exist) {
        for (string& digit : digits) {
            exist[digit[0]] = true;
        }
    }

    bool allExist(string& num, vector<bool>& exist) {
        for (char c : num) {
            if (!exist[c]) {
                return false;
            }
        }

        return true;
    }

    int countLess(vector<string>& digits, char digit) {
        int i = 0, size = digits.size();

        for (i = 0; i < size && digits[i][0] < digit; ++i) {}

        return i;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> digits = { "1","3","5","7" };
    check.checkInt(20, o.atMostNGivenDigitSet(digits, 100));

    digits = { "1","3","5","7" };
    check.checkInt(205, o.atMostNGivenDigitSet(digits, 3751));

    digits = { "1","4","9" };
    check.checkInt(29523, o.atMostNGivenDigitSet(digits, 1000000000));

    digits = { "7" };
    check.checkInt(1, o.atMostNGivenDigitSet(digits, 8));
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
