/* 从双倍数组中还原原数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个整数数组 original 可以转变成一个 双倍 数组 changed ，转变方式为将 original 中每个元素 值乘以 2 加入数组中，然后将所有元素 随机打乱 。

给你一个数组 changed ，如果 change 是 双倍 数组，那么请你返回 original数组，否则请返回空数组。original 的元素可以以 任意 顺序返回。

 

示例 1：

输入：changed = [1,3,4,2,6,8]
输出：[1,3,4]
解释：一个可能的 original 数组为 [1,3,4] :
- 将 1 乘以 2 ，得到 1 * 2 = 2 。
- 将 3 乘以 2 ，得到 3 * 2 = 6 。
- 将 4 乘以 2 ，得到 4 * 2 = 8 。
其他可能的原数组方案为 [4,3,1] 或者 [3,1,4] 。
示例 2：

输入：changed = [6,3,0,1]
输出：[]
解释：changed 不是一个双倍数组。
示例 3：

输入：changed = [1]
输出：[]
解释：changed 不是一个双倍数组。
 

提示：

1 <= changed.length <= 105
0 <= changed[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-original-array-from-doubled-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> originalArray;
        map<int, int> nums;

        for (int num : changed) {
            ++nums[num];
        }

        while (!nums.empty()) {
            auto iter = nums.begin();
            int num = iter->first;
            originalArray.push_back(num);

            if (--iter->second == 0) {
                nums.erase(iter);
            }

            iter = nums.find(num * 2);
            if (iter == nums.end()) {
                return {};
            }

            if (--iter->second == 0) {
                nums.erase(iter);
            }
        }

        return originalArray;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> changed = { 1,3,4,2,6,8 };
    vector<int> actual = o.findOriginalArray(changed);
    vector<int> expected = { 1,3,4 };
    check.checkIntVector(expected, actual);

    changed = { 6,3,0,1 };
    actual = o.findOriginalArray(changed);
    expected = {  };
    check.checkIntVector(expected, actual);

    changed = { 1 };
    actual = o.findOriginalArray(changed);
    expected = {  };
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
