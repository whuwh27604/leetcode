/* 给植物浇水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你打算用一个水罐给花园里的 n 株植物浇水。植物排成一行，从左到右进行标记，编号从 0 到 n - 1 。其中，第 i 株植物的位置是 x = i 。x = -1 处有一条河，你可以在那里重新灌满你的水罐。

每一株植物都需要浇特定量的水。你将会按下面描述的方式完成浇水：

按从左到右的顺序给植物浇水。
在给当前植物浇完水之后，如果你没有足够的水 完全 浇灌下一株植物，那么你就需要返回河边重新装满水罐。
你 不能 提前重新灌满水罐。
最初，你在河边（也就是，x = -1），在 x 轴上每移动 一个单位 都需要 一步 。

给你一个下标从 0 开始的整数数组 plants ，数组由 n 个整数组成。其中，plants[i] 为第 i 株植物需要的水量。另有一个整数 capacity 表示水罐的容量，返回浇灌所有植物需要的 步数 。

 

示例 1：

输入：plants = [2,2,3,3], capacity = 5
输出：14
解释：从河边开始，此时水罐是装满的：
- 走到植物 0 (1 步) ，浇水。水罐中还有 3 单位的水。
- 走到植物 1 (1 步) ，浇水。水罐中还有 1 单位的水。
- 由于不能完全浇灌植物 2 ，回到河边取水 (2 步)。
- 走到植物 2 (3 步) ，浇水。水罐中还有 2 单位的水。
- 由于不能完全浇灌植物 3 ，回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。
需要的步数是 = 1 + 1 + 2 + 3 + 3 + 4 = 14 。
示例 2：

输入：plants = [1,1,1,4,2,3], capacity = 4
输出：30
解释：从河边开始，此时水罐是装满的：
- 走到植物 0，1，2 (3 步) ，浇水。回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。回到河边取水 (4 步)。
- 走到植物 4 (5 步) ，浇水。回到河边取水 (5 步)。
- 走到植物 5 (6 步) ，浇水。
需要的步数是 = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30 。
示例 3：

输入：plants = [7,7,7,7,7,7,7], capacity = 8
输出：49
解释：每次浇水都需要重新灌满水罐。
需要的步数是 = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49 。
 

提示：

n == plants.length
1 <= n <= 1000
1 <= plants[i] <= 106
max(plants[i]) <= capacity <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/watering-plants
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, water = capacity, i, size = plants.size();

        for (i = 0; i < size; ++i) {
            if (water >= plants[i]) {
                steps += 1;
                water -= plants[i];
            }
            else {
                steps += (2 * i + 1);
                water = capacity - plants[i];
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> plants = { 2,2,3,3 };
    check.checkInt(14, o.wateringPlants(plants, 5));

    plants = { 1,1,1,4,2,3 };
    check.checkInt(30, o.wateringPlants(plants, 4));

    plants = { 7,7,7,7,7,7,7 };
    check.checkInt(49, o.wateringPlants(plants, 8));

    plants = { 1 };
    check.checkInt(1, o.wateringPlants(plants, 1));
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
