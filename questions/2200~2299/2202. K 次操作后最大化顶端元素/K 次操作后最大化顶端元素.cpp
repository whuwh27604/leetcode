/* K 次操作后最大化顶端元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，它表示一个 栈 ，其中 nums[0] 是栈顶的元素。

每一次操作中，你可以执行以下操作 之一 ：

如果栈非空，那么 删除 栈顶端的元素。
如果存在 1 个或者多个被删除的元素，你可以从它们中选择任何一个，添加 回栈顶，这个元素成为新的栈顶元素。
同时给你一个整数 k ，它表示你总共需要执行操作的次数。

请你返回 恰好 执行 k 次操作以后，栈顶元素的 最大值 。如果执行完 k 次操作以后，栈一定为空，请你返回 -1 。

 

示例 1：

输入：nums = [5,2,2,4,0,6], k = 4
输出：5
解释：
4 次操作后，栈顶元素为 5 的方法之一为：
- 第 1 次操作：删除栈顶元素 5 ，栈变为 [2,2,4,0,6] 。
- 第 2 次操作：删除栈顶元素 2 ，栈变为 [2,4,0,6] 。
- 第 3 次操作：删除栈顶元素 2 ，栈变为 [4,0,6] 。
- 第 4 次操作：将 5 添加回栈顶，栈变为 [5,4,0,6] 。
注意，这不是最后栈顶元素为 5 的唯一方式。但可以证明，4 次操作以后 5 是能得到的最大栈顶元素。
示例 2：

输入：nums = [2], k = 1
输出：-1
解释：
第 1 次操作中，我们唯一的选择是将栈顶元素弹出栈。
由于 1 次操作后无法得到一个非空的栈，所以我们返回 -1 。
 

提示：

1 <= nums.length <= 105
0 <= nums[i], k <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-the-topmost-element-after-k-moves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int size = nums.size();

        if (size == 1) {
            return k % 2 == 0 ? nums[0] : -1;  // 只有一个元素，奇数次操作变为空，偶数次操作不变
        }

        if (k < 2) {
            return nums[k];  // 0或1次操作，只能返回nums[0]或nums[1]
        }

        int top = *max_element(nums.begin(), nums.begin() + min(size, k - 1));  // 取k-1个元素里面的最大值，然后最后一次操作把它放回去

        return k < size ? max(top, nums[k]) : top;  // 如果k小于size，还可以选择拿掉k个元素，让第k+1个元素作为栈顶
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,2,2,4,0,6 };
    check.checkInt(5, o.maximumTop(nums, 4));

    nums = { 5,2,2,4,0,6 };
    check.checkInt(6, o.maximumTop(nums, 7));

    nums = { 5,2,2,4,0,6 };
    check.checkInt(5, o.maximumTop(nums, 6));

    nums = { 5,2,2,4,0,6 };
    check.checkInt(6, o.maximumTop(nums, 5));

    nums = { 2 };
    check.checkInt(-1, o.maximumTop(nums, 1));

    nums = { 18 };
    check.checkInt(-1, o.maximumTop(nums, 3));

    nums = { 5 };
    check.checkInt(5, o.maximumTop(nums, 2));

    nums = { 0,1,2 };
    check.checkInt(1, o.maximumTop(nums, 3));

    nums = { 1,2 };
    check.checkInt(2, o.maximumTop(nums, 4));

    nums = { 3,2,1 };
    check.checkInt(3, o.maximumTop(nums, 0));

    nums = { 3,2,1 };
    check.checkInt(2, o.maximumTop(nums, 1));
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
