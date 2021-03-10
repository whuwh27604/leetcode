/* 构成特定和需要添加的最少元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，和两个整数 limit 与 goal 。数组 nums 有一条重要属性：abs(nums[i]) <= limit 。

返回使数组元素总和等于 goal 所需要向数组中添加的 最少元素数量 ，添加元素 不应改变 数组中 abs(nums[i]) <= limit 这一属性。

注意，如果 x >= 0 ，那么 abs(x) 等于 x ；否则，等于 -x 。

 

示例 1：

输入：nums = [1,-1,1], limit = 3, goal = -4
输出：2
解释：可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
示例 2：

输入：nums = [1,-10,9,1], limit = 100, goal = 0
输出：1
 

提示：

1 <= nums.length <= 105
1 <= limit <= 106
-limit <= nums[i] <= limit
-109 <= goal <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return (int)((abs(goal - sum) + limit - 1) / limit);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,-1,1 };
    check.checkInt(2, o.minElements(nums, 3, -4));

    nums = { 1,-10,9,1 };
    check.checkInt(1, o.minElements(nums, 100, 0));

    nums = { 1,-20,9,1 };
    check.checkInt(9, o.minElements(nums, 1, 0));

    nums = getIntVector("./testcase1.txt");
    check.checkInt(101000, o.minElements(nums, 1000000, -1000000000));
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
