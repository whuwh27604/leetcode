/* 在 D 天内送达包裹的能力.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

 

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。
示例 2：

输入：weights = [3,2,2,4,1,4], D = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
示例 3：

输入：weights = [1,2,3,1,1], D = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
 

提示：

1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0, high = 0;
        init(weights, low, high);

        while (low < high) {
            int middle = (low + high) / 2;
            if (canFinish(weights, middle, D)) {
                high = middle;
            }
            else {
                low = middle + 1;
            }
        }

        return low;
    }

    void init(vector<int>& weights, int& low, int& high) {
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }
    }

    bool canFinish(vector<int>& weights, int capacity, int D) {
        int sum = 0, days = 1;

        for (int weight : weights) {
            sum += weight;
            if (sum > capacity) {
                if (++days > D) {
                    return false;
                }

                sum = weight;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> weights = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(15, o.shipWithinDays(weights, 5));

    weights = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(10, o.shipWithinDays(weights, 10));

    weights = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(55, o.shipWithinDays(weights, 1));

    weights = { 3,2,2,4,1,4 };
    check.checkInt(6, o.shipWithinDays(weights, 3));

    weights = { 1,2,3,1,1 };
    check.checkInt(3, o.shipWithinDays(weights, 4));
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
