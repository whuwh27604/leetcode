/* 形成三的最大倍数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 digits，你可以通过按任意顺序连接其中某些数字来形成 3 的倍数，请你返回所能得到的最大的 3 的倍数。

由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。

如果无法得到答案，请返回一个空字符串。

 

示例 1：

输入：digits = [8,1,9]
输出："981"
示例 2：

输入：digits = [8,6,7,1,0]
输出："8760"
示例 3：

输入：digits = [1]
输出：""
示例 4：

输入：digits = [0,0,0,0,0,0]
输出："0"
 

提示：

1 <= digits.length <= 10^4
0 <= digits[i] <= 9
返回的结果不应包含不必要的前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-multiple-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string ans;
        int sum = 0;
        vector<int> counts(10, 0);

        for (int digit : digits) {
            sum += digit;
            ++counts[digit];
        }

        if (sum % 3 == 1) {  // 一定有一个数余1，或者2个数余2
            if (!deleteRemainder1(counts)) {
                deleteRemainder2(counts);
                deleteRemainder2(counts);
            }
        }
        else if (sum % 3 == 2) {  // 一定有一个数余2，或者2个数余1
            if (!deleteRemainder2(counts)) {
                deleteRemainder1(counts);
                deleteRemainder1(counts);
            }
        }

        for (int i = 9; i > 0; --i) {
            ans += string(counts[i], '0' + i);
        }

        if (ans.empty()) {
            if (counts[0] != 0) {
                ans = "0";
            }
        }
        else {
            ans += string(counts[0], '0');
        }

        return ans;
    }

    bool deleteRemainder1(vector<int>& counts) {
        if (counts[1] != 0) {
            --counts[1];
        }
        else if (counts[4] != 0) {
            --counts[4];
        }
        else if (counts[7] != 0) {
            --counts[7];
        }
        else {
            return false;
        }

        return true;
    }

    bool deleteRemainder2(vector<int>& counts) {
        if (counts[2] != 0) {
            --counts[2];
        }
        else if (counts[5] != 0) {
            --counts[5];
        }
        else if (counts[8] != 0) {
            --counts[8];
        }
        else {
            return false;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> digits = { 8,1,9 };
    check.checkString("981", o.largestMultipleOfThree(digits));

    digits = { 8,6,7,1,0 };
    check.checkString("8760", o.largestMultipleOfThree(digits));

    digits = { 9,6,2,5 };
    check.checkString("96", o.largestMultipleOfThree(digits));

    digits = { 9,6,1,4 };
    check.checkString("96", o.largestMultipleOfThree(digits));

    digits = { 0,0,1,4 };
    check.checkString("0", o.largestMultipleOfThree(digits));

    digits = { 1,4 };
    check.checkString("", o.largestMultipleOfThree(digits));

    digits = { 1 };
    check.checkString("", o.largestMultipleOfThree(digits));

    digits = { 0,0,0,0,0,0 };
    check.checkString("0", o.largestMultipleOfThree(digits));
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
