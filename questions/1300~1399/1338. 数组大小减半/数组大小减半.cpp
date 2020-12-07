/* 数组大小减半.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。

返回 至少 能删除数组中的一半整数的整数集合的最小大小。

 

示例 1：

输入：arr = [3,3,3,3,5,5,5,2,2,7]
输出：2
解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
示例 2：

输入：arr = [7,7,7,7,7,7]
输出：1
解释：我们只能选择集合 {7}，结果数组为空。
示例 3：

输入：arr = [1,9]
输出：1
示例 4：

输入：arr = [1000,1000,3,7]
输出：1
示例 5：

输入：arr = [1,2,3,4,5,6,7,8,9,10]
输出：5
 

提示：

1 <= arr.length <= 10^5
arr.length 为偶数
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reduce-array-size-to-the-half
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> numsCount;
        countNums(arr, numsCount);

        multiset<int> frequencies;
        sortFrequency(numsCount, frequencies);

        return getMinSet(frequencies, arr.size() / 2);
    }

    void countNums(vector<int>& arr, unordered_map<int, int>& numsCount) {
        for (int num : arr) {
            ++numsCount[num];
        }
    }

    void sortFrequency(unordered_map<int, int>& numsCount, multiset<int>& frequencies) {
        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            frequencies.insert(iter->second);
        }
    }

    int getMinSet(multiset<int>& frequencies, int half) {
        int frequency = 0, count = 0;

        for (auto iter = frequencies.rbegin(); iter != frequencies.rend() && frequency < half; ++iter) {
            frequency += *iter;
            ++count;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 3,3,3,3,5,5,5,2,2,7 };
    check.checkInt(2, o.minSetSize(arr));

    arr = { 7,7,7,7,7,7 };
    check.checkInt(1, o.minSetSize(arr));

    arr = { 1,9 };
    check.checkInt(1, o.minSetSize(arr));

    arr = { 1000,1000,3,7 };
    check.checkInt(1, o.minSetSize(arr));

    arr = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(5, o.minSetSize(arr));

    arr = { 1,1,2,2,3,3,4,4 };
    check.checkInt(2, o.minSetSize(arr));
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
