/* 公平分发饼干.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 cookies ，其中 cookies[i] 表示在第 i 个零食包中的饼干数量。另给你一个整数 k 表示等待分发零食包的孩子数量，所有 零食包都需要分发。在同一个零食包中的所有饼干都必须分发给同一个孩子，不能分开。

分发的 不公平程度 定义为单个孩子在分发过程中能够获得饼干的最大总数。

返回所有分发的最小不公平程度。

 

示例 1：

输入：cookies = [8,15,10,20,8], k = 2
输出：31
解释：一种最优方案是 [8,15,8] 和 [10,20] 。
- 第 1 个孩子分到 [8,15,8] ，总计 8 + 15 + 8 = 31 块饼干。
- 第 2 个孩子分到 [10,20] ，总计 10 + 20 = 30 块饼干。
分发的不公平程度为 max(31,30) = 31 。
可以证明不存在不公平程度小于 31 的分发方案。
示例 2：

输入：cookies = [6,1,3,2,2,4,1,2], k = 3
输出：7
解释：一种最优方案是 [6,1]、[3,2,2] 和 [4,1,2] 。
- 第 1 个孩子分到 [6,1] ，总计 6 + 1 = 7 块饼干。
- 第 2 个孩子分到 [3,2,2] ，总计 3 + 2 + 2 = 7 块饼干。
- 第 3 个孩子分到 [4,1,2] ，总计 4 + 1 + 2 = 7 块饼干。
分发的不公平程度为 max(7,7,7) = 7 。
可以证明不存在不公平程度小于 7 的分发方案。
 

提示：

2 <= cookies.length <= 8
1 <= cookies[i] <= 105
2 <= k <= cookies.length

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fair-distribution-of-cookies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int size = cookies.size(), maxMask = (1 << size), inf = 1000000000;
        vector<vector<int>> dp(maxMask, vector<int>(k + 1, inf));
        dp[0][0] = 0;

        for (int mask = 1; mask < maxMask; ++mask) {
            for (int n = 1; n <= k; ++n) {
                for (int sub = mask; sub != 0; sub = (sub - 1) & mask) {  // 遍历mask的所有子集，将该子集分给1个人，剩下的分给n - 1个人
                    dp[mask][n] = min(dp[mask][n], max(getCookies(cookies, sub), dp[mask ^ sub][n - 1]));
                }
            }
        }

        return dp[maxMask - 1][k];
    }

    int getCookies(vector<int>& cookies, int mask) {
        int count = 0, size = cookies.size();

        for (int i = 0, bit = 1; i < size; ++i, bit <<= 1) {
            if ((bit & mask) != 0) {
                count += cookies[i];
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cookies = { 8,15,10,20,8 };
    check.checkInt(31, o.distributeCookies(cookies, 2));

    cookies = { 3,5 };
    check.checkInt(5, o.distributeCookies(cookies, 2));

    cookies = { 6,1,3,2,2,4,1,2 };
    check.checkInt(7, o.distributeCookies(cookies, 3));
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
