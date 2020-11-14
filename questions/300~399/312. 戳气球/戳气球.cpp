/* 戳气球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

/* 令dp[i][j]表示戳破开区间(i,j)之内的所有气球，可以得到的最大硬币，即戳破i+1,i+2...j-2,j-1，最后剩下i、j不戳破。
   假设可以获得最大硬币的方案，最后一个戳破的气球是k，那么意味着需要先戳破(i,k)之间的气球，再戳破(k,j)之间的气球，最后戳破k
   而戳破(i,k)之间的气球可以获得的最大硬币是dp[i][k]，戳破(k,j)之间的气球可以获得的最大硬币是dp[k][j]，戳破k（此时i、k、j相邻）可以获得的硬币是nums[i]*nums[k]*nums[j]，
   所以dp[i][j]=max(dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])(k遍历(i,j)之间每一个值) */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        int i = 0, j = 2;  // 左上往右下动态规划，因为(i,i)和(i,i+1)之间都没有气球可戳，dp[i][i]=0，dp[i][i+1]=0，所以从(0,2)开始规划。
        while (j < size) {
            for (int k = i + 1; k < j; k++) {
                int dpIJ = dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j];
                dp[i][j] = max(dp[i][j], dpIJ);
            }

            i++;
            j++;
            if (j >= size) {
                j = j - i + 1;
                i = 0;
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,1,5,8 };
    check.checkInt(167, o.maxCoins(nums));

    nums = {  };
    check.checkInt(0, o.maxCoins(nums));

    nums = { 5 };
    check.checkInt(5, o.maxCoins(nums));

    nums = { 5,8 };
    check.checkInt(48, o.maxCoins(nums));

    nums = { 2,3,5 };
    check.checkInt(45, o.maxCoins(nums));
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
