/* 区间内查询数字的频率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个数据结构，它能求出给定子数组内一个给定值的 频率 。

子数组中一个值的 频率 指的是这个子数组中这个值的出现次数。

请你实现 RangeFreqQuery 类：

RangeFreqQuery(int[] arr) 用下标从 0 开始的整数数组 arr 构造一个类的实例。
int query(int left, int right, int value) 返回子数组 arr[left...right] 中 value 的 频率 。
一个 子数组 指的是数组中一段连续的元素。arr[left...right] 指的是 nums 中包含下标 left 和 right 在内 的中间一段连续元素。

 

示例 1：

输入：
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
输出：
[null, 1, 2]

解释：
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // 返回 1 。4 在子数组 [33, 4] 中出现 1 次。
rangeFreqQuery.query(0, 11, 33); // 返回 2 。33 在整个子数组中出现 2 次。
 

提示：

1 <= arr.length <= 105
1 <= arr[i], value <= 104
0 <= left <= right < arr.length
调用 query 不超过 105 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-frequency-queries
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            indices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto iter = indices.find(value);
        if (iter == indices.end()) {
            return 0;
        }
        else {
            return distance(lower_bound(iter->second.begin(), iter->second.end(), left), upper_bound(iter->second.begin(), iter->second.end(), right));
        }
    }

private:
    unordered_map<int, vector<int>> indices;
};

int main()
{
    CheckResult check;
    
    vector<int> arr = { 12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56 };
    RangeFreqQuery o1(arr);
    check.checkInt(1, o1.query(1, 2, 4));
    check.checkInt(2, o1.query(0, 11, 33));
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
