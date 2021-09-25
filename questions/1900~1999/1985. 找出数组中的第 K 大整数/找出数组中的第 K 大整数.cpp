/* 找出数组中的第 K 大整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 nums 和一个整数 k 。nums 中的每个字符串都表示一个不含前导零的整数。

返回 nums 中表示第 k 大整数的字符串。

注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是 ["1","2","2"]，那么 "2" 是最大的整数，"2" 是第二大的整数，"1" 是第三大的整数。

 

示例 1：

输入：nums = ["3","6","7","10"], k = 4
输出："3"
解释：
nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
其中第 4 大整数是 "3"
示例 2：

输入：nums = ["2","21","12","1"], k = 3
输出："2"
解释：
nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
其中第 3 大整数是 "2"
示例 3：

输入：nums = ["0","0"], k = 2
输出："0"
解释：
nums 中的数字按非递减顺序排列为 ["0","0"]
其中第 2 大整数是 "0"
 

提示：

1 <= k <= nums.length <= 104
1 <= nums[i].length <= 100
nums[i] 仅由数字组成
nums[i] 不含任何前导零

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-kth-largest-integer-in-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

struct stringCompare {
    bool operator()(const string& s1, const string& s2) const {
        if (s1.size() != s2.size()) {
            return s1.size() > s2.size();
        }

        for (int i = 0; i < (int)s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }

            return s1[i] > s2[i];
        }

        return false;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, stringCompare> sortedNums;

        for (string& num : nums) {
            sortedNums.push(num);

            if ((int)sortedNums.size() > k) {
                sortedNums.pop();
            }
        }

        return sortedNums.top();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> nums = { "3","6","7","10" };
    check.checkString("3", o.kthLargestNumber(nums, 4));

    nums = { "2","21","12","1" };
    check.checkString("2", o.kthLargestNumber(nums, 3));

    nums = { "0","0" };
    check.checkString("0", o.kthLargestNumber(nums, 2));

    nums = { "423","521","2","42" };
    check.checkString("423", o.kthLargestNumber(nums, 2));
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
