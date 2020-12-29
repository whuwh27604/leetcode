/* 不同整数的最少数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。

 

示例 1：

输入：arr = [5,5,4], k = 1
输出：1
解释：移除 1 个 4 ，数组中只剩下 5 一种整数。
示例 2：

输入：arr = [4,3,1,1,3,3,2], k = 3
输出：2
解释：先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> numsCount;
        multimap<int, int> sortedNums;

        for (int num : arr) {
            ++numsCount[num];
        }

        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            sortedNums.insert({ iter->second, iter->first });
        }

        auto iter = sortedNums.begin();
        while (k > 0 && k >= iter->first) {
            k -= iter->first;
            iter = sortedNums.erase(iter);
        }

        return sortedNums.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 5,5,4 };
    check.checkInt(1, o.findLeastNumOfUniqueInts(arr, 1));
    check.checkInt(2, o.findLeastNumOfUniqueInts(arr, 0));
    check.checkInt(0, o.findLeastNumOfUniqueInts(arr, 3));

    arr = { 4,3,1,1,3,3,2 };
    check.checkInt(4, o.findLeastNumOfUniqueInts(arr, 0));
    check.checkInt(3, o.findLeastNumOfUniqueInts(arr, 1));
    check.checkInt(2, o.findLeastNumOfUniqueInts(arr, 2));
    check.checkInt(2, o.findLeastNumOfUniqueInts(arr, 3));
    check.checkInt(1, o.findLeastNumOfUniqueInts(arr, 4));
    check.checkInt(1, o.findLeastNumOfUniqueInts(arr, 5));
    check.checkInt(1, o.findLeastNumOfUniqueInts(arr, 6));
    check.checkInt(0, o.findLeastNumOfUniqueInts(arr, 7));

    arr = { 4 };
    check.checkInt(1, o.findLeastNumOfUniqueInts(arr, 0));
    check.checkInt(0, o.findLeastNumOfUniqueInts(arr, 1));
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
