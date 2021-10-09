/* 连接后等于目标字符串的字符串对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 数字 字符串数组 nums 和一个 数字 字符串 target ，请你返回 nums[i] + nums[j] （两个字符串连接）结果等于 target 的下标 (i, j) （需满足 i != j）的数目。

 

示例 1：

输入：nums = ["777","7","77","77"], target = "7777"
输出：4
解释：符合要求的下标对包括：
- (0, 1)："777" + "7"
- (1, 0)："7" + "777"
- (2, 3)："77" + "77"
- (3, 2)："77" + "77"
示例 2：

输入：nums = ["123","4","12","34"], target = "1234"
输出：2
解释：符合要求的下标对包括
- (0, 1)："123" + "4"
- (2, 3)："12" + "34"
示例 3：

输入：nums = ["1","1","1"], target = "11"
输出：6
解释：符合要求的下标对包括
- (0, 1)："1" + "1"
- (1, 0)："1" + "1"
- (0, 2)："1" + "1"
- (2, 0)："1" + "1"
- (1, 2)："1" + "1"
- (2, 1)："1" + "1"
 

提示：

2 <= nums.length <= 100
1 <= nums[i].length <= 100
2 <= target.length <= 100
nums[i] 和 target 只包含数字。
nums[i] 和 target 不含有任何前导 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int i, size = target.size(), pairs = 0, halfTargetCount = 0;
        string half1(target, 0, size / 2), half2(target, size / 2, size - size / 2), halfTarget = half1 == half2 ? half1 : "";
        vector<vector<string>> classifiedNums(size);

        for (string& num : nums) {
            if ((int)num.size() < size) {
                classifiedNums[num.size()].push_back(num);
            }

            if (num == halfTarget) {
                ++halfTargetCount;
            }
        }

        for (i = 1; i < size; ++i) {
            for (string& num1 : classifiedNums[i]) {
                for (string& num2 : classifiedNums[size - i]) {
                    string num = num1 + num2;
                    if (num == target) {
                        ++pairs;
                    }
                }
            }
        }

        return pairs - halfTargetCount;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> nums = { "777","7","77","77" };
    check.checkInt(4, o.numOfPairs(nums, "7777"));

    nums = { "123","4","12","34" };
    check.checkInt(2, o.numOfPairs(nums, "1234"));

    nums = { "1","1","1" };
    check.checkInt(6, o.numOfPairs(nums, "11"));

    nums = { "77777" };
    check.checkInt(0, o.numOfPairs(nums, "7777"));

    nums = { "7","7","7","7","7","7","7","7","7","7" };
    check.checkInt(90, o.numOfPairs(nums, "77"));
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
