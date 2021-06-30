/* 两个数对之间的最大乘积差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
两个数对 (a, b) 和 (c, d) 之间的 乘积差 定义为 (a * b) - (c * d) 。

例如，(5, 6) 和 (2, 7) 之间的乘积差是 (5 * 6) - (2 * 7) = 16 。
给你一个整数数组 nums ，选出四个 不同的 下标 w、x、y 和 z ，使数对 (nums[w], nums[x]) 和 (nums[y], nums[z]) 之间的 乘积差 取到 最大值 。

返回以这种方式取得的乘积差中的 最大值 。

 

示例 1：

输入：nums = [5,6,2,7,4]
输出：34
解释：可以选出下标为 1 和 3 的元素构成第一个数对 (6, 7) 以及下标 2 和 4 构成第二个数对 (2, 4)
乘积差是 (6 * 7) - (2 * 4) = 34
示例 2：

输入：nums = [4,2,5,9,7,4,8]
输出：64
解释：可以选出下标为 3 和 6 的元素构成第一个数对 (9, 8) 以及下标 1 和 5 构成第二个数对 (2, 4)
乘积差是 (9 * 8) - (2 * 4) = 64
 

提示：

4 <= nums.length <= 104
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-difference-between-two-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0, min1 = INT_MAX, min2 = INT_MAX;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        return max1 * max2 - min1 * min2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,6,2,7,4 };
    check.checkInt(34, o.maxProductDifference(nums));

    nums = { 4,2,5,9,7,4,8 };
    check.checkInt(64, o.maxProductDifference(nums));

    nums = { 1,1,1,1 };
    check.checkInt(0, o.maxProductDifference(nums));
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
