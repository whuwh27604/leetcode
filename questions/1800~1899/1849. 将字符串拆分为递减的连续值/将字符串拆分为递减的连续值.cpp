/* 将字符串拆分为递减的连续值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由数字组成的字符串 s 。

请你判断能否将 s 拆分成两个或者多个 非空子字符串 ，使子字符串的 数值 按 降序 排列，且每两个 相邻子字符串 的数值之 差 等于 1 。

例如，字符串 s = "0090089" 可以拆分成 ["0090", "089"] ，数值为 [90,89] 。这些数值满足按降序排列，且相邻值相差 1 ，这种拆分方法可行。
另一个例子中，字符串 s = "001" 可以拆分成 ["0", "01"]、["00", "1"] 或 ["0", "0", "1"] 。然而，所有这些拆分方法都不可行，因为对应数值分别是 [0,1]、[0,1] 和 [0,0,1] ，都不满足按降序排列的要求。
如果可以按要求拆分 s ，返回 true ；否则，返回 false 。

子字符串 是字符串中的一个连续字符序列。

 

示例 1：

输入：s = "1234"
输出：false
解释：不存在拆分 s 的可行方法。
示例 2：

输入：s = "050043"
输出：true
解释：s 可以拆分为 ["05", "004", "3"] ，对应数值为 [5,4,3] 。
满足按降序排列，且相邻值相差 1 。
示例 3：

输入：s = "9080701"
输出：false
解释：不存在拆分 s 的可行方法。
示例 4：

输入：s = "10009998"
输出：true
解释：s 可以拆分为 ["100", "099", "98"] ，对应数值为 [100,99,98] 。
满足按降序排列，且相邻值相差 1 。
 

提示：

1 <= s.length <= 20
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/splitting-a-string-into-descending-consecutive-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool splitString(string s) {
        for (unsigned int i = 0; i < s.size() - 1; ++i) {
            string first(s, 0, i + 1);

            if (splitString(s, i + 1, first)) {
                return true;
            }
        }

        return false;
    }

    bool splitString(string& s, int start, string& prev) {
        int i, size = s.size();
        if (start == size) {
            return true;
        }

        for (i = start; i < size; ++i) {
            string num(s, start, i - start + 1);

            if (isDecrease(prev, num) && splitString(s, i + 1, num)) {
                return true;
            }
        }

        return false;
    }

    bool isDecrease(string& num1, string& num2) {
        int i, size1 = num1.size(), size2 = num2.size(), minSize = min(size1, size2), carrier = 1;

        for (i = 0; i < minSize; ++i) {
            char c = num2[size2 - 1 - i];
            if (c == '9' && carrier == 1) {
                c = '0';
                carrier = 1;
            }
            else {
                c += carrier;
                carrier = 0;
            }

            if (c != num1[size1 - 1 - i]) {
                return false;
            }
        }

        if (size1 > size2) {
            return num1[size1 - size2 - 1] == (carrier == 1 ? '1' : '0') && string(num1, 0, size1 - size2 - 1) == string(size1 - size2 - 1, '0');
        }

        return carrier == 0 && string(num2, 0, size2 - size1) == string(size2 - size1, '0');
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.splitString("0090089"));
    check.checkBool(true, o.splitString("050043"));
    check.checkBool(true, o.splitString("10009998"));
    check.checkBool(true, o.splitString("200100"));
    check.checkBool(true, o.splitString("109"));
    check.checkBool(true, o.splitString("00000000000021"));
    check.checkBool(false, o.splitString("001"));
    check.checkBool(false, o.splitString("1234"));
    check.checkBool(false, o.splitString("9080701"));
    check.checkBool(false, o.splitString("19979817075396416247"));
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
