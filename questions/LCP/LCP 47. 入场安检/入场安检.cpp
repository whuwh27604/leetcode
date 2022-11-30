/* 入场安检.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」 的入场仪式马上就要开始了，由于安保工作的需要，设置了可容纳人数总和为 M 的 N 个安检室，capacities[i] 记录第 i 个安检室可容纳人数。安检室拥有两种类型：

先进先出：在安检室中的所有观众中，最早进入安检室的观众最先离开
后进先出：在安检室中的所有观众中，最晚进入安检室的观众最先离开


恰好 M+1 位入场的观众（编号从 0 开始）需要排队依次入场安检， 入场安检的规则如下：

观众需要先进入编号 0 的安检室
当观众将进入编号 i 的安检室时（0 <= i < N)，
若安检室未到达可容纳人数上限，该观众可直接进入；
若安检室已到达可容纳人数上限，在该观众进入安检室之前需根据当前安检室类型选择一位观众离开后才能进入；
当观众离开编号 i 的安检室时 （0 <= i < N-1)，将进入编号 i+1 的安检室接受安检。
若可以任意设定每个安检室的类型，请问有多少种设定安检室类型的方案可以使得编号 k 的观众第一个通过最后一个安检室入场。

注意：

观众不可主动离开安检室，只有当安检室容纳人数达到上限，且又有新观众需要进入时，才可根据安检室的类型选择一位观众离开；
由于方案数可能过大，请将答案对 1000000007 取模后返回。
示例 1：

输入：capacities = [2,2,3], k = 2

输出：2
解释：
存在两种设定的 2 种方案：

方案 1：将编号为 0 、1 的实验室设置为 后进先出 的类型，编号为 2 的实验室设置为 先进先出 的类型；
方案 2：将编号为 0 、1 的实验室设置为 先进先出 的类型，编号为 2 的实验室设置为 后进先出 的类型。
以下是方案 1 的示意图：


示例 2：

输入：capacities = [3,3], k = 3

输出：0

示例 3：

输入：capacities = [4,3,2,2], k = 6

输出：2

提示:

1 <= capacities.length <= 200
1 <= capacities[i] <= 200
0 <= k <= sum(capacities)

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/oPs9Bm
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int securityCheck(vector<int>& capacities, int k) {
        int size = capacities.size(), mod = 1000000007;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int cap : capacities) {
            for (int i = k - --cap; i >= 0; --i) {
                dp[i + cap] = (dp[i + cap] + dp[i]) % mod;
            }
        }

        return dp[k];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> capacities = { 2,2,3 };
    check.checkInt(2, o.securityCheck(capacities, 2));

    capacities = { 3,3 };
    check.checkInt(0, o.securityCheck(capacities, 3));

    capacities = { 4,3,2,2 };
    check.checkInt(2, o.securityCheck(capacities, 6));

    capacities = { 1,1,1,1 };
    check.checkInt(0, o.securityCheck(capacities, 1));

    capacities = { 1,1,1,1 };
    check.checkInt(16, o.securityCheck(capacities, 0));

    capacities = { 21,1,20,16,27,28,11,8,24,11,23,28,3,7,30,19,8,8,26,5,26,18,15,3,3,11,29,17,30,16,4,10,18,10,23,4,18,11,27,30,18,7,26 };
    check.checkInt(13082, o.securityCheck(capacities, 617));
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
