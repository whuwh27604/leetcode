/* 统计道路上的碰撞次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一条无限长的公路上有 n 辆汽车正在行驶。汽车按从左到右的顺序按从 0 到 n - 1 编号，每辆车都在一个 独特的 位置。

给你一个下标从 0 开始的字符串 directions ，长度为 n 。directions[i] 可以是 'L'、'R' 或 'S' 分别表示第 i 辆车是向 左 、向 右 或者 停留 在当前位置。每辆车移动时 速度相同 。

碰撞次数可以按下述方式计算：

当两辆移动方向 相反 的车相撞时，碰撞次数加 2 。
当一辆移动的车和一辆静止的车相撞时，碰撞次数加 1 。
碰撞发生后，涉及的车辆将无法继续移动并停留在碰撞位置。除此之外，汽车不能改变它们的状态或移动方向。

返回在这条道路上发生的 碰撞总次数 。

 

示例 1：

输入：directions = "RLRSLL"
输出：5
解释：
将会在道路上发生的碰撞列出如下：
- 车 0 和车 1 会互相碰撞。由于它们按相反方向移动，碰撞数量变为 0 + 2 = 2 。
- 车 2 和车 3 会互相碰撞。由于 3 是静止的，碰撞数量变为 2 + 1 = 3 。
- 车 3 和车 4 会互相碰撞。由于 3 是静止的，碰撞数量变为 3 + 1 = 4 。
- 车 4 和车 5 会互相碰撞。在车 4 和车 3 碰撞之后，车 4 会待在碰撞位置，接着和车 5 碰撞。碰撞数量变为 4 + 1 = 5 。
因此，将会在道路上发生的碰撞总次数是 5 。
示例 2：

输入：directions = "LLRR"
输出：0
解释：
不存在会发生碰撞的车辆。因此，将会在道路上发生的碰撞总次数是 0 。
 

提示：

1 <= directions.length <= 105
directions[i] 的值为 'L'、'R' 或 'S'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-collisions-on-a-road
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int i, j, k, size = directions.size(), collisions = 0;

        for (i = 0; i < size && directions[i] == 'L'; ++i) {}
        for (j = size - 1; j >= 0 && directions[j] == 'R'; --j) {}

        for (k = i; k <= j; ++k) {
            if (directions[k] != 'S') {
                ++collisions;
            }
        }

        return collisions;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.countCollisions("RLRSLL"));
    check.checkInt(0, o.countCollisions("LLRR"));
    check.checkInt(0, o.countCollisions("L"));
    check.checkInt(0, o.countCollisions("R"));
    check.checkInt(2, o.countCollisions("RL"));
    check.checkInt(98, o.countCollisions("RLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLLRLRSLLLLRRRLRSLL"));
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
