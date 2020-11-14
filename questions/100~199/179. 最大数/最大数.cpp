/* 最大数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool compareFunc(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    string ab = sa + sb, ba = sb + sa;
    return ab.compare(ba) > 0;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        sort(nums.begin(), nums.end(), compareFunc);

        bool allZeros = true;
        string largest;
        for (int number : nums) {
            largest += to_string(number);
            if (number != 0) {
                allZeros = false;
            }
        }

        return allZeros ? "0" : largest;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkString("", o.largestNumber(nums));
    
    nums = { 0 };
    check.checkString("0", o.largestNumber(nums));

    nums = { 1 };
    check.checkString("1", o.largestNumber(nums));

    nums = { INT_MAX };
    check.checkString("2147483647", o.largestNumber(nums));

    nums = { INT_MAX,0 };
    check.checkString("21474836470", o.largestNumber(nums));

    nums = { 0,0 };
    check.checkString("0", o.largestNumber(nums));

    nums = { 0,1 };
    check.checkString("10", o.largestNumber(nums));

    nums = { 10,2 };
    check.checkString("210", o.largestNumber(nums));

    nums = { 56,5 };
    check.checkString("565", o.largestNumber(nums));

    nums = { 54,5 };
    check.checkString("554", o.largestNumber(nums));

    nums = { 336,33 };
    check.checkString("33633", o.largestNumber(nums));

    nums = { 332,33 };
    check.checkString("33332", o.largestNumber(nums));

    nums = { 3,30,34,5,9 };
    check.checkString("9534330", o.largestNumber(nums));
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
