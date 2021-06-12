/* 数位成本和为目标值的最大数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
总成本必须恰好等于 target 。
添加的数位中没有数字 0 。
由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。

 

示例 1：

输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
输出："7772"
解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "977" 也是满足要求的数字，但 "7772" 是较大的数字。
 数字     成本
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
示例 2：

输入：cost = [7,6,5,5,5,6,8,7,8], target = 12
输出："85"
解释：添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5 = 12 。
示例 3：

输入：cost = [2,4,6,2,4,6,4,4,4], target = 5
输出："0"
解释：总成本是 target 的条件下，无法生成任何整数。
示例 4：

输入：cost = [6,10,15,40,40,40,40,40,40], target = 47
输出："32211"
 

提示：

cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "0");
        dp[0] = "";

        removeDuplicate(cost);

        for (int i = 1; i <= target; ++i) {
            for (int j = 1; j < 10; ++j) {
                if (i >= cost[j - 1] && dp[i - cost[j - 1]] != "0") {
                    string num = dp[i - cost[j - 1]] + to_string(j);
                    dp[i] = maxNum(dp[i], num);
                }
            }
        }

        return dp[target];
    }

    void removeDuplicate(vector<int>& cost) {
        unordered_set<int> nums;

        for (int i = 8; i >= 0; --i) {
            if (nums.count(cost[i]) != 0) {
                cost[i] = 10000;  // 两个选择的cost相等，那么必然应该选大的那个数。把小的cost置为很大的一个数，就不会参与计算了。
            }

            nums.insert(cost[i]);
        }
    }

    string maxNum(string& num1, string& num2) {
        if (num1.size() != num2.size()) {
            return num1.size() > num2.size() ? num1 : num2;
        }

        return num1.compare(num2) > 0 ? num1 : num2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cost = { 4,3,2,5,6,7,2,5,5 };
    check.checkString("7772", o.largestNumber(cost, 9));

    cost = { 7,6,5,5,5,6,8,7,8 };
    check.checkString("85", o.largestNumber(cost, 12));

    cost = { 2,4,6,2,4,6,4,4,4 };
    check.checkString("0", o.largestNumber(cost, 5));

    cost = { 6,10,15,40,40,40,40,40,40 };
    check.checkString("32211", o.largestNumber(cost, 47));

    cost = { 1,2,3,4,5,6,7,8,9 };
    check.checkString(string(5000, '1'), o.largestNumber(cost, 5000));

    cost = { 1,1,1,1,1,1,1,1,1 };
    check.checkString(string(5000, '9'), o.largestNumber(cost, 5000));
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
