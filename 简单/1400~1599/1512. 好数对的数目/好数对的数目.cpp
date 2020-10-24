/* 好数对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目。

 

示例 1：

输入：nums = [1,2,3,1,1,3]
输出：4
解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
示例 2：

输入：nums = [1,1,1,1]
输出：6
解释：数组中的每组数字都是好数对
示例 3：

输入：nums = [1,2,3]
输出：0
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int numberCount[101] = { 0 };
        int pairs = 0;

        for (int num : nums) {
            numberCount[num]++;
        }

        for (int count : numberCount) {
            if (count > 1) {
                pairs += (count * (count - 1) / 2);  // C(m,n)=C!/(m-n)!n!, m=count, n=2
            }
        }

        return pairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,1,1,3 };
    check.checkInt(4, o.numIdenticalPairs(nums));
    
    nums = { 1 };
    check.checkInt(0, o.numIdenticalPairs(nums));

    nums = { 1,2 };
    check.checkInt(0, o.numIdenticalPairs(nums));

    nums = { 1,1 };
    check.checkInt(1, o.numIdenticalPairs(nums));

    nums = { 1,2,3 };
    check.checkInt(0, o.numIdenticalPairs(nums));

    nums = { 1,1,2 };
    check.checkInt(1, o.numIdenticalPairs(nums));

    nums = { 1,1,1 };
    check.checkInt(3, o.numIdenticalPairs(nums));

    nums = { 2,2,2,2,2,3,3,3,3,3,3 };
    check.checkInt(25, o.numIdenticalPairs(nums));
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
