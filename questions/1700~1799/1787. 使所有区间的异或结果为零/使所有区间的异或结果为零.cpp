/* 使所有区间的异或结果为零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括 left 和 right ）之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。

返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。

 

示例 1：

输入：nums = [1,2,0,3,0], k = 1
输出：3
解释：将数组 [1,2,0,3,0] 修改为 [0,0,0,0,0]
示例 2：

输入：nums = [3,4,5,2,1,7,3,4,7], k = 3
输出：3
解释：将数组 [3,4,5,2,1,7,3,4,7] 修改为 [3,4,7,3,4,7,3,4,7]
示例 3：

输入：nums = [1,2,4,1,2,5,1,2,6], k = 3
输出：3
解释：将数组[1,2,4,1,2,5,1,2,6] 修改为 [1,2,3,1,2,3,1,2,3]
 

提示：

1 <= k <= nums.length <= 2000
​​​​​​0 <= nums[i] < 210

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        /* 1、最后的数组必然是ABCABCABC的形式，即以k为周期循环。因为A^B^C=0，接下来B^C^X=0，那么X只能等于A，同理接下来只能是B、C...
           2、所以数组被划分为k组，每一组有[A0,A1,A2...],[B0,B1,B2...]...[J0,J1,J2...],[K0,K1,K2...]
           3、假设前面A到J组分别选择了Ax、Bx...Jx，那么Ax^Bx^...^Jx^Kx=0，即Kx=Ax^Bx^...^Jx^0。
           4、令dp[i][j]表示i组数据，异或结果为j需要改变的最小元素数，那么在面对第i+1组数据时，我们有两个选择：
              a、选择这组数据里面的一个数x，那么其它数需要改变为x，同时，前面i组数据需要改变为x^0
              b、任选一个其它数y，那么这组数据全部要改变为y，同时，前面i组数据需要改变为y^0。显然，y应该选一个dp[i][j]最小的。
           5、最后dp[k][0]就是答案 */
        int size = nums.size(), group, xorVal, maxXorValue = getMaxXorValue(nums);
        vector<unordered_map<int, int>> frequences(k);
        vector<vector<int>> dp(k, vector<int>(maxXorValue + 1));
        int groupNums = (size + k - 1) / k, prevMin = INT_MAX;

        getFrequences(nums, k, frequences);

        for (xorVal = 0; xorVal <= maxXorValue; ++xorVal) {
            dp[0][xorVal] = frequences[0].count(xorVal) == 0 ? groupNums : groupNums - frequences[0][xorVal];  // 第0组数据，全部变为xorVal需要改变的次数
            prevMin = min(prevMin, dp[0][xorVal]);  // 记录下上一组的最小值
        }

        for (group = 1; group < k; ++group) {
            int dpMin = prevMin;
            prevMin = INT_MAX;
            groupNums = size / k + (group < (size % k) ? 1 : 0);  // 这一组有几个数

            for (xorVal = 0; xorVal <= maxXorValue; ++xorVal) {
                dp[group][xorVal] = dpMin + groupNums;  // 这一组全部改变，需要的最小次数是上一组的最小次数加上这一组的个数

                for (auto& numFrequence : frequences[group]) {  // 这一组选择其中一个数num，剩下的数改变，那么前面的组需要变为num^xorVal
                    dp[group][xorVal] = min(dp[group][xorVal], groupNums - numFrequence.second + dp[group - 1][numFrequence.first ^ xorVal]);
                }

                prevMin = min(prevMin, dp[group][xorVal]);
            }
        }

        return dp[k - 1][0];
    }

    int getMaxXorValue(vector<int>& nums) {
        int maxXorValue = 1, maxNum = *max_element(nums.begin(), nums.end());

        while (maxXorValue < maxNum) {
            maxXorValue = ((maxXorValue << 1) | 1);
        }

        return maxXorValue;
    }

    void getFrequences(vector<int>& nums, int k, vector<unordered_map<int, int>>& frequences) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            ++frequences[i % k][nums[i]];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,2,2,2 };
    check.checkInt(3, o.minChanges(nums, 3));
    
    nums = { 1,1,2,2,2 };
    check.checkInt(3, o.minChanges(nums, 3));

    nums = { 1,1,2,2,2,2,2,2 };
    check.checkInt(4, o.minChanges(nums, 3));

    nums = { 1,2,0,3,0 };
    check.checkInt(3, o.minChanges(nums, 1));

    nums = { 1,2,4,1,2,5,1,2,6 };
    check.checkInt(3, o.minChanges(nums, 3));

    nums = { 3,4,5,2,1,7,3,4,7 };
    check.checkInt(3, o.minChanges(nums, 3));

    nums = { 0 };
    check.checkInt(0, o.minChanges(nums, 1));

    nums = { 1 };
    check.checkInt(1, o.minChanges(nums, 1));

    nums = { 0,1,10,100,1000,999,99,9,8,88,888,777,77,7,6,66,666,555,55,5,4,44,444,333,33,3,2,22,222,111,11 };
    check.checkInt(16, o.minChanges(nums, 15));
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
