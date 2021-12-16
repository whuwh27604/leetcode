/* 给植物浇水 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 打算给花园里的 n 株植物浇水。植物排成一行，从左到右进行标记，编号从 0 到 n - 1 。其中，第 i 株植物的位置是 x = i 。

每一株植物都需要浇特定量的水。Alice 和 Bob 每人有一个水罐，最初是满的 。他们按下面描述的方式完成浇水：

 Alice 按 从左到右 的顺序给植物浇水，从植物 0 开始。Bob 按 从右到左 的顺序给植物浇水，从植物 n - 1 开始。他们 同时 给植物浇水。
如果没有足够的水 完全 浇灌下一株植物，他 / 她会立即重新灌满浇水罐。
不管植物需要多少水，浇水所耗费的时间都是一样的。
不能 提前重新灌满水罐。
每株植物都可以由 Alice 或者 Bob 来浇水。
如果 Alice 和 Bob 到达同一株植物，那么当前水罐中水更多的人会给这株植物浇水。如果他俩水量相同，那么 Alice 会给这株植物浇水。
给你一个下标从 0 开始的整数数组 plants ，数组由 n 个整数组成。其中，plants[i] 为第 i 株植物需要的水量。另有两个整数 capacityA 和 capacityB 分别表示 Alice 和 Bob 水罐的容量。返回两人浇灌所有植物过程中重新灌满水罐的 次数 。

 

示例 1：

输入：plants = [2,2,3,3], capacityA = 5, capacityB = 5
输出：1
解释：
- 最初，Alice 和 Bob 的水罐中各有 5 单元水。
- Alice 给植物 0 浇水，Bob 给植物 3 浇水。
- Alice 和 Bob 现在分别剩下 3 单元和 2 单元水。
- Alice 有足够的水给植物 1 ，所以她直接浇水。Bob 的水不够给植物 2 ，所以他先重新装满水，再浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 0 + 1 + 0 = 1 。
示例 2：

输入：plants = [2,2,3,3], capacityA = 3, capacityB = 4
输出：2
解释：
- 最初，Alice 的水罐中有 3 单元水，Bob 的水罐中有 4 单元水。
- Alice 给植物 0 浇水，Bob 给植物 3 浇水。
- Alice 和 Bob 现在都只有 1 单元水，并分别需要给植物 1 和植物 2 浇水。
- 由于他们的水量均不足以浇水，所以他们重新灌满水罐再进行浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 1 + 1 + 0 = 2 。
示例 3：

输入：plants = [5], capacityA = 10, capacityB = 8
输出：0
解释：
- 只有一株植物
- Alice 的水罐有 10 单元水，Bob 的水罐有 8 单元水。因此 Alice 的水罐中水更多，她会给这株植物浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 。
示例 4：

输入：plants = [1,2,4,4,5], capacityA = 6, capacityB = 5
输出：2
解释：
- 最初，Alice 的水罐中有 6 单元水，Bob 的水罐中有 5 单元水。
- Alice 给植物 0 浇水，Bob 给植物 4 浇水。
- Alice 和 Bob 现在分别剩下 5 单元和 0 单元水。
- Alice 有足够的水给植物 1 ，所以她直接浇水。Bob 的水不够给植物 3 ，所以他先重新装满水，再浇水。
- Alice 和 Bob 现在分别剩下 3 单元和 1 单元水。
- 由于 Alice 的水更多，所以由她给植物 2 浇水。然而，她水罐里的水不够给植物 2 ，所以她先重新装满水，再浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 0 + 1 + 1 + 0 = 2 。
示例 5：

输入：plants = [2,2,5,2,2], capacityA = 5, capacityB = 5
输出：1
解释：
Alice 和 Bob 都会到达中间的植物，并且此时他俩剩下的水量相同，所以 Alice 会给这株植物浇水。
由于她到达时只剩下 1 单元水，所以需要重新灌满水罐。
这是唯一一次需要重新灌满水罐的情况。所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 1 。
 

提示：

n == plants.length
1 <= n <= 105
1 <= plants[i] <= 106
max(plants[i]) <= capacityA, capacityB <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/watering-plants-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left, right, waterA = capacityA, waterB = capacityB, refill = 0;

        for (left = 0, right = plants.size() - 1; left < right; ++left, --right) {
            if (waterA >= plants[left]) {
                waterA -= plants[left];
            }
            else {
                waterA = capacityA - plants[left];
                ++refill;
            }

            if (waterB >= plants[right]) {
                waterB -= plants[right];
            }
            else {
                waterB = capacityB - plants[right];
                ++refill;
            }
        }

        if (left == right && waterA < plants[left] && waterB < plants[right]) {
            ++refill;
        }

        return refill;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> plants = { 2,2,3,3 };
    check.checkInt(1, o.minimumRefill(plants, 5, 5));

    plants = { 2,2,3,3 };
    check.checkInt(2, o.minimumRefill(plants, 3, 4));

    plants = { 5 };
    check.checkInt(0, o.minimumRefill(plants, 10, 8));

    plants = { 1,2,4,4,5 };
    check.checkInt(2, o.minimumRefill(plants, 6, 5));

    plants = { 2,2,5,2,2 };
    check.checkInt(1, o.minimumRefill(plants, 5, 5));

    plants = { 2,1,1 };
    check.checkInt(0, o.minimumRefill(plants, 2, 2));

    plants = { 1,10,1 };
    check.checkInt(0, o.minimumRefill(plants, 10, 11));

    plants = { 726,739,934,116,643,648,473,984,482,85,850,806,146,764,156,66,186,339,985,237,662,552,800,78,617,933,481,652,796,594,151,82,183,241,525,221,951,732,799,483,368,354,776,175,974,187,913,842 };
    check.checkInt(24, o.minimumRefill(plants, 1439, 1207));
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
