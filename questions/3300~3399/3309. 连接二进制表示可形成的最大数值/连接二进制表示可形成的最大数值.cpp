/* 连接二进制表示可形成的最大数值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 3 的整数数组 nums。

现以某种顺序 连接 数组 nums 中所有元素的 二进制表示 ，请你返回可以由这种方法形成的 最大 数值。

注意 任何数字的二进制表示 不含 前导零。



示例 1:

输入: nums = [1,2,3]

输出: 30

解释:

按照顺序 [3, 1, 2] 连接数字的二进制表示，得到结果 "11110"，这是 30 的二进制表示。

示例 2:

输入: nums = [2,8,16]

输出: 1296

解释:

按照顺序 [2, 8, 16] 连接数字的二进制表述，得到结果 "10100010000"，这是 1296 的二进制表示。



提示:

nums.length == 3
1 <= nums[i] <= 127
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        string s1 = toString(nums[0]), s2 = toString(nums[1]), s3 = toString(nums[2]);
        vector<string> ss = { s1 + s2 + s3, s1 + s3 + s2, s2 + s1 + s3, s2 + s3 + s1, s3 + s1 + s2, s3 + s2 + s1 };
        sort(ss.begin(), ss.end());

        return toInt(*ss.rbegin());
    }

    string toString(int num) {
        string s;

        while (num != 0) {
            s += ((num & 1) == 0 ? '0' : '1');
            num >>= 1;
        }

        reverse(s.begin(), s.end());

        return s;
    }

    int toInt(string& s) {
        int num = 0;

        for (char c : s) {
            num = ((num << 1) | (c == '0' ? 0 : 1));
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(30, o.maxGoodNumber(nums));

    nums = { 2,8,16 };
    check.checkInt(1296, o.maxGoodNumber(nums));

    nums = { 2,67,25 };
    check.checkInt(13123, o.maxGoodNumber(nums));
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
