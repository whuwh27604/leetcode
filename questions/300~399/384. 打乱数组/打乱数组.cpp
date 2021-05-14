/* 打乱数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果
 

示例：

输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
 

提示：

1 <= nums.length <= 200
-106 <= nums[i] <= 106
nums 中的所有元素都是 唯一的
最多可以调用 5 * 104 次 reset 和 shuffle

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
        result = nums;
        size = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        result = original;
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < size; ++i) {
            swap(result[i], result[randRange(i, size)]);
        }

        return result;
    }

    int randRange(int left, int right) {
        return rd() % (right - left) + left;
    }

private:
    vector<int> original;
    vector<int> result;
    int size;
    random_device rd;
};

int main()
{
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    Solution o1(nums);
    vector<int> actual;
    for (int i = 0; i < 10; ++i) {
        actual = o1.shuffle();
        for (int num : actual) {
            cout << num << " ";
        }
        cout << endl;
    }
    actual = o1.reset();
    check.checkIntVector(nums, actual);
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
