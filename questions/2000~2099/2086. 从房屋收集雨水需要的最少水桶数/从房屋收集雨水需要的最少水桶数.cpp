/* 从房屋收集雨水需要的最少水桶数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 street 。street 中每个字符要么是表示房屋的 'H' ，要么是表示空位的 '.' 。

你可以在 空位 放置水桶，从相邻的房屋收集雨水。位置在 i - 1 或者 i + 1 的水桶可以收集位置为 i 处房屋的雨水。一个水桶如果相邻两个位置都有房屋，那么它可以收集 两个 房屋的雨水。

在确保 每个 房屋旁边都 至少 有一个水桶的前提下，请你返回需要的 最少 水桶数。如果无解请返回 -1 。

 

示例 1：

输入：street = "H..H"
输出：2
解释：
我们可以在下标为 1 和 2 处放水桶。
"H..H" -> "HBBH"（'B' 表示放置水桶）。
下标为 0 处的房屋右边有水桶，下标为 3 处的房屋左边有水桶。
所以每个房屋旁边都至少有一个水桶收集雨水。
示例 2：

输入：street = ".H.H."
输出：1
解释：
我们可以在下标为 2 处放置一个水桶。
".H.H." -> ".HBH."（'B' 表示放置水桶）。
下标为 1 处的房屋右边有水桶，下标为 3 处的房屋左边有水桶。
所以每个房屋旁边都至少有一个水桶收集雨水。
示例 3：

输入：street = ".HHH."
输出：-1
解释：
没有空位可以放置水桶收集下标为 2 处的雨水。
所以没有办法收集所有房屋的雨水。
示例 4：

输入：street = "H"
输出：-1
解释：
没有空位放置水桶。
所以没有办法收集所有房屋的雨水。
示例 5：

输入：street = "."
输出：0
解释：
没有房屋需要收集雨水。
所以需要 0 个水桶。
 

提示：

1 <= street.length <= 105
street[i] 要么是 'H' ，要么是 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumBuckets(string street) {
        int i, size = street.size(), buckets = 0;

        for (i = 0; i < size; ++i) {
            if (street[i] != 'H' || (i != 0 && street[i - 1] == 'B')) {  // 不是房子，或者是房子但是左边已经有水桶，则不用处理
                continue;
            }

            if (i != size - 1 && street[i + 1] == '.') {  // 优先放右边，这样后面的房子有可能共用上水桶
                ++buckets;
                street[i + 1] = 'B';
                continue;
            }

            if (i != 0 && street[i - 1] == '.') {  // 右边放不了，只能放左边
                ++buckets;
                continue;
            }

            return -1;  // 两边都放不了，失败
        }

        return buckets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumBuckets("H..H"));
    check.checkInt(1, o.minimumBuckets(".H.H."));
    check.checkInt(-1, o.minimumBuckets(".HHH."));
    check.checkInt(-1, o.minimumBuckets("H"));
    check.checkInt(0, o.minimumBuckets("."));
    check.checkInt(1, o.minimumBuckets("H.."));
    check.checkInt(1, o.minimumBuckets(".H."));
    check.checkInt(1, o.minimumBuckets("..H"));
    check.checkInt(-1, o.minimumBuckets("HH."));
    check.checkInt(-1, o.minimumBuckets(".HH"));
    check.checkInt(1, o.minimumBuckets("H.H"));
    check.checkInt(-1, o.minimumBuckets("HHH"));
    check.checkInt(0, o.minimumBuckets("..."));
    check.checkInt(6, o.minimumBuckets("...H..H.H.H.H.H.H.HH.."));
    check.checkInt(-1, o.minimumBuckets("..HH"));
    check.checkInt(-1, o.minimumBuckets("HH"));
    check.checkInt(3, o.minimumBuckets(".HH.H.H.H.."));
    check.checkInt(1, o.minimumBuckets(".H"));
    check.checkInt(3, o.minimumBuckets("...HH...H."));
    check.checkInt(2, o.minimumBuckets(".HH.H"));
    check.checkInt(-1, o.minimumBuckets("HH........"));
    check.checkInt(-1, o.minimumBuckets("H.HHH.H"));
    check.checkInt(6, o.minimumBuckets(".HH.HH.HH.HH..H"));
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
