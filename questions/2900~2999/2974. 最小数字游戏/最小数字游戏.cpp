/* 最小数字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个下标从 0 开始、长度为 偶数 的整数数组 nums ，同时还有一个空数组 arr 。Alice 和 Bob 决定玩一个游戏，游戏中每一轮 Alice 和 Bob 都会各自执行一次操作。游戏规则如下：

每一轮，Alice 先从 nums 中移除一个 最小 元素，然后 Bob 执行同样的操作。
接着，Bob 会将移除的元素添加到数组 arr 中，然后 Alice 也执行同样的操作。
游戏持续进行，直到 nums 变为空。
返回结果数组 arr 。



示例 1：

输入：nums = [5,4,2,3]
输出：[3,2,5,4]
解释：第一轮，Alice 先移除 2 ，然后 Bob 移除 3 。然后 Bob 先将 3 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [3,2] 。
第二轮开始时，nums = [5,4] 。Alice 先移除 4 ，然后 Bob 移除 5 。接着他们都将元素添加到 arr 中，arr 变为 [3,2,5,4] 。
示例 2：

输入：nums = [2,5]
输出：[5,2]
解释：第一轮，Alice 先移除 2 ，然后 Bob 移除 5 。然后 Bob 先将 5 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [5,2] 。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
nums.length % 2 == 0
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i += 2) {
            ans[i] = nums[i + 1];
            ans[i + 1] = nums[i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,4,2,3 };
    vector<int> actual = o.numberGame(nums);
    vector<int> expected = { 3,2,5,4 };
    check.checkIntVector(expected, actual);

    nums = { 2,5 };
    actual = o.numberGame(nums);
    expected = { 5,2 };
    check.checkIntVector(expected, actual);
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
