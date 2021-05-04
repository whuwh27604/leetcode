/* 找到最高海拔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个自行车手打算进行一场公路骑行，这条路线总共由 n + 1 个不同海拔的点组成。自行车手从海拔为 0 的点 0 开始骑行。

给你一个长度为 n 的整数数组 gain ，其中 gain[i] 是点 i 和点 i + 1 的 净海拔高度差（0 <= i < n）。请你返回 最高点的海拔 。

 

示例 1：

输入：gain = [-5,1,5,0,-7]
输出：1
解释：海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
示例 2：

输入：gain = [-4,-3,-2,-1,4,3,2]
输出：0
解释：海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
 

提示：

n == gain.length
1 <= n <= 100
-100 <= gain[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-highest-altitude
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxAltitude = 0;

        for (int diff : gain) {
            altitude += diff;
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> gain = { -5,1,5,0,-7 };
    check.checkInt(1, o.largestAltitude(gain));

    gain = { -4,-3,-2,-1,4,3,2 };
    check.checkInt(0, o.largestAltitude(gain));
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
