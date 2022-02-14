/* 堆叠长方体的最大高度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个长方体 cuboids ，其中第 i 个长方体的长宽高表示为 cuboids[i] = [widthi, lengthi, heighti]（下标从 0 开始）。请你从 cuboids 选出一个 子集 ，并将它们堆叠起来。

如果 widthi <= widthj 且 lengthi <= lengthj 且 heighti <= heightj ，你就可以将长方体 i 堆叠在长方体 j 上。你可以通过旋转把长方体的长宽高重新排列，以将它放在另一个长方体上。

返回 堆叠长方体 cuboids 可以得到的 最大高度 。

 

示例 1：



输入：cuboids = [[50,45,20],[95,37,53],[45,23,12]]
输出：190
解释：
第 1 个长方体放在底部，53x37 的一面朝下，高度为 95 。
第 0 个长方体放在中间，45x20 的一面朝下，高度为 50 。
第 2 个长方体放在上面，23x12 的一面朝下，高度为 45 。
总高度是 95 + 50 + 45 = 190 。
示例 2：

输入：cuboids = [[38,25,45],[76,35,3]]
输出：76
解释：
无法将任何长方体放在另一个上面。
选择第 1 个长方体然后旋转它，使 35x3 的一面朝下，其高度为 76 。
示例 3：

输入：cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
输出：102
解释：
重新排列长方体后，可以看到所有长方体的尺寸都相同。
你可以把 11x7 的一面朝下，这样它们的高度就是 17 。
堆叠长方体的最大高度为 6 * 17 = 102 。
 

提示：

n == cuboids.length
1 <= n <= 100
1 <= widthi, lengthi, heighti <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-height-by-stacking-cuboids
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool cuboidCompare(const vector<int>& c1, const vector<int>& c2) {
    return c1[0] * c1[1] * c1[2] < c2[0] * c2[1] * c2[2];
}

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int i, j, size = cuboids.size(), maximumHeight = 0;
        vector<int> dp(size);

        sort(cuboids.begin(), cuboids.end(), cuboidCompare);

        for (i = 0; i < size; ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());

            for (j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }

            dp[i] += cuboids[i][2];
            maximumHeight = max(maximumHeight, dp[i]);
        }

        return maximumHeight;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> cuboids = { {50,45,20},{95,37,53},{45,23,12} };
    check.checkInt(190, o.maxHeight(cuboids));

    cuboids = { {38,25,45},{76,35,3} };
    check.checkInt(76, o.maxHeight(cuboids));

    cuboids = { {7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7} };
    check.checkInt(102, o.maxHeight(cuboids));

    cuboids = { {7,11,17} };
    check.checkInt(17, o.maxHeight(cuboids));

    cuboids = { {36,46,41},{15,100,100},{75,91,59},{13,82,64} };
    check.checkInt(182, o.maxHeight(cuboids));
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
