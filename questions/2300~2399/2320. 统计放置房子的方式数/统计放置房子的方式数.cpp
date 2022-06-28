/* 统计放置房子的方式数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。

现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 109 + 7 取余后再返回。

注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。

 

示例 1：

输入：n = 1
输出：4
解释：
可能的放置方式：
1. 所有地块都不放置房子。
2. 一所房子放在街道的某一侧。
3. 一所房子放在街道的另一侧。
4. 放置两所房子，街道两侧各放置一所。
示例 2：


输入：n = 2
输出：9
解释：如上图所示，共有 9 种可能的放置方式。
 

提示：

1 <= n <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-number-of-ways-to-place-houses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        int total = dp(1, 1, n);

        return dp(total, total, n);
    }

    int dp(int house, int noHouse, int n) {
        int mod = 1000000007;

        for (int i = 1; i < n; ++i) {
            int tmpHouse = noHouse;
            int tmpNoHouse = (house + noHouse) % mod;
            house = tmpHouse;
            noHouse = tmpNoHouse;
        }

        return (house + noHouse) % mod;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.countHousePlacements(1));
    check.checkInt(9, o.countHousePlacements(2));
    check.checkInt(402613600, o.countHousePlacements(10000));
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
