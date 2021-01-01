/* 所有蚂蚁掉下来前的最后一刻.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一块木板，长度为 n 个 单位 。一些蚂蚁在木板上移动，每只蚂蚁都以 每秒一个单位 的速度移动。其中，一部分蚂蚁向 左 移动，其他蚂蚁向 右 移动。

当两只向 不同 方向移动的蚂蚁在某个点相遇时，它们会同时改变移动方向并继续移动。假设更改方向不会花费任何额外时间。

而当蚂蚁在某一时刻 t 到达木板的一端时，它立即从木板上掉下来。

给你一个整数 n 和两个整数数组 left 以及 right 。两个数组分别标识向左或者向右移动的蚂蚁在 t = 0 时的位置。请你返回最后一只蚂蚁从木板上掉下来的时刻。

 

示例 1：

 



输入：n = 4, left = [4,3], right = [0,1]
输出：4
解释：如上图所示：
-下标 0 处的蚂蚁命名为 A 并向右移动。
-下标 1 处的蚂蚁命名为 B 并向右移动。
-下标 3 处的蚂蚁命名为 C 并向左移动。
-下标 4 处的蚂蚁命名为 D 并向左移动。
请注意，蚂蚁在木板上的最后时刻是 t = 4 秒，之后蚂蚁立即从木板上掉下来。（也就是说在 t = 4.0000000001 时，木板上没有蚂蚁）。
示例 2：



输入：n = 7, left = [], right = [0,1,2,3,4,5,6,7]
输出：7
解释：所有蚂蚁都向右移动，下标为 0 的蚂蚁需要 7 秒才能从木板上掉落。
示例 3：



输入：n = 7, left = [0,1,2,3,4,5,6,7], right = []
输出：7
解释：所有蚂蚁都向左移动，下标为 7 的蚂蚁需要 7 秒才能从木板上掉落。
示例 4：

输入：n = 9, left = [5], right = [4]
输出：5
解释：t = 1 秒时，两只蚂蚁将回到初始位置，但移动方向与之前相反。
示例 5：

输入：n = 6, left = [6], right = [0]
输出：6
 

提示：

1 <= n <= 10^4
0 <= left.length <= n + 1
0 <= left[i] <= n
0 <= right.length <= n + 1
0 <= right[i] <= n
1 <= left.length + right.length <= n + 1
left 和 right 中的所有值都是唯一的，并且每个值 只能出现在二者之一 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-moment-before-all-ants-fall-out-of-a-plank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // Who am i? Where i come from? Where will i go? The answer is, I'm you, you're me. And you go my ways, well I go yours.
        int leftmost = n, rightmost = 0;

        for (int ant : right) {
            leftmost = min(leftmost, ant);
        }

        for (int ant : left) {
            rightmost = max(rightmost, ant);
        }

        return max(n - leftmost, rightmost);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> left = { 4,3 };
    vector<int> right = { 0,1 };
    check.checkInt(4, o.getLastMoment(4, left, right));

    left = {  };
    right = { 0,1,2,3,4,5,6,7 };
    check.checkInt(7, o.getLastMoment(7, left, right));

    left = { 0,1,2,3,4,5,6,7 };
    right = {  };
    check.checkInt(7, o.getLastMoment(7, left, right));

    left = { 5 };
    right = { 4 };
    check.checkInt(5, o.getLastMoment(9, left, right));

    left = { 6 };
    right = { 0 };
    check.checkInt(6, o.getLastMoment(6, left, right));
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
