/* 数组序号转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。

序号代表了一个元素有多大。序号编号的规则如下：

序号从 1 开始编号。
一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
每个数字的序号都应该尽可能地小。
 

示例 1：

输入：arr = [40,10,20,30]
输出：[4,1,2,3]
解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
示例 2：

输入：arr = [100,100,100]
输出：[1,1,1]
解释：所有元素有相同的序号。
示例 3：

输入：arr = [37,12,28,9,100,56,80,5,12]
输出：[5,3,4,2,8,6,7,1,3]
 

提示：

0 <= arr.length <= 105
-109 <= arr[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rank-transform-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int i, len = arr.size(), rank = 0, prevNumber = INT_MAX;
        vector<pair<int, int>> numberIndex(len);

        for (i = 0; i < len; i++) {
            numberIndex[i] = { arr[i], i };
        }

        sort(numberIndex.begin(), numberIndex.end());  // 默认按照pair.first排序

        for (i = 0; i < len; i++) {
            int number = numberIndex[i].first;
            int index = numberIndex[i].second;
            if (number != prevNumber) {
                rank++;
            }
            prevNumber = number;

            arr[index] = rank;
        }

        return arr;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 40,10,20,30 };
    vector<int> actual = o.arrayRankTransform(arr);
    vector<int> expected = { 4,1,2,3 };
    check.checkIntVector(expected, actual);

    arr = { 100,100,100 };
    actual = o.arrayRankTransform(arr);
    expected = { 1,1,1 };
    check.checkIntVector(expected, actual);

    arr = { 37,12,28,9,100,56,80,5,12 };
    actual = o.arrayRankTransform(arr);
    expected = { 5,3,4,2,8,6,7,1,3 };
    check.checkIntVector(expected, actual);

    arr = {  };
    actual = o.arrayRankTransform(arr);
    expected = {  };
    check.checkIntVector(expected, actual);

    arr = { 5 };
    actual = o.arrayRankTransform(arr);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    arr = { 5,6 };
    actual = o.arrayRankTransform(arr);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    arr = getIntVector("./testcase1.txt");
    actual = o.arrayRankTransform(arr);
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
