/* 黑板异或游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
黑板上写着一个非负整数数组 nums[i] 。Alice 和 Bob 轮流从黑板上擦掉一个数字，Alice 先手。如果擦除一个数字后，剩余的所有数字按位异或运算得出的结果等于 0 的话，当前玩家游戏失败。 (另外，如果只剩一个数字，按位异或运算得到它本身；如果无数字剩余，按位异或运算结果为 0。）

换种说法就是，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 0，这个玩家获胜。

假设两个玩家每步都使用最优解，当且仅当 Alice 获胜时返回 true。

 

示例：

输入: nums = [1, 1, 2]
输出: false
解释:
Alice 有两个选择: 擦掉数字 1 或 2。
如果擦掉 1, 数组变成 [1, 2]。剩余数字按位异或得到 1 XOR 2 = 3。那么 Bob 可以擦掉任意数字，因为 Alice 会成为擦掉最后一个数字的人，她总是会输。
如果 Alice 擦掉 2，那么数组变成[1, 1]。剩余数字按位异或得到 1 XOR 1 = 0。Alice 仍然会输掉游戏。
 

提示：

1 <= N <= 1000
0 <= nums[i] <= 2^16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chalkboard-xor-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        // 这个游戏只有两种结果：1、一上来就躺赢；2、否则奇数必输，偶数必赢
        int xorResult = 0;

        for (int num : nums) {
            xorResult ^= num;
        }

        return xorResult == 0 || (nums.size() & 1) == 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,2 };
    check.checkBool(false, o.xorGame(nums));

    nums = { 1,2,3 };
    check.checkBool(true, o.xorGame(nums));

    nums = { 1,2,3,4 };
    check.checkBool(true, o.xorGame(nums));

    nums = { 1 };
    check.checkBool(false, o.xorGame(nums));

    nums = { 1,2 };
    check.checkBool(true, o.xorGame(nums));
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
