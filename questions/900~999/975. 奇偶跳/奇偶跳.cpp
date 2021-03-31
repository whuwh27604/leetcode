/* 奇偶跳.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，你可以从某一起始索引出发，跳跃一定次数。在你跳跃的过程中，第 1、3、5... 次跳跃称为奇数跳跃，而第 2、4、6... 次跳跃称为偶数跳跃。

你可以按以下方式从索引 i 向后跳转到索引 j（其中 i < j）：

在进行奇数跳跃时（如，第 1，3，5... 次跳跃），你将会跳到索引 j，使得 A[i] <= A[j]，A[j] 是可能的最小值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
在进行偶数跳跃时（如，第 2，4，6... 次跳跃），你将会跳到索引 j，使得 A[i] >= A[j]，A[j] 是可能的最大值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
（对于某些索引 i，可能无法进行合乎要求的跳跃。）
如果从某一索引开始跳跃一定次数（可能是 0 次或多次），就可以到达数组的末尾（索引 A.length - 1），那么该索引就会被认为是好的起始索引。

返回好的起始索引的数量。

 

示例 1：

输入：[10,13,12,14,15]
输出：2
解释：
从起始索引 i = 0 出发，我们可以跳到 i = 2，（因为 A[2] 是 A[1]，A[2]，A[3]，A[4] 中大于或等于 A[0] 的最小值），然后我们就无法继续跳下去了。
从起始索引 i = 1 和 i = 2 出发，我们可以跳到 i = 3，然后我们就无法继续跳下去了。
从起始索引 i = 3 出发，我们可以跳到 i = 4，到达数组末尾。
从起始索引 i = 4 出发，我们已经到达数组末尾。
总之，我们可以从 2 个不同的起始索引（i = 3, i = 4）出发，通过一定数量的跳跃到达数组末尾。
示例 2：

输入：[2,3,1,1,4]
输出：3
解释：
从起始索引 i=0 出发，我们依次可以跳到 i = 1，i = 2，i = 3：

在我们的第一次跳跃（奇数）中，我们先跳到 i = 1，因为 A[1] 是（A[1]，A[2]，A[3]，A[4]）中大于或等于 A[0] 的最小值。

在我们的第二次跳跃（偶数）中，我们从 i = 1 跳到 i = 2，因为 A[2] 是（A[2]，A[3]，A[4]）中小于或等于 A[1] 的最大值。A[3] 也是最大的值，但 2 是一个较小的索引，所以我们只能跳到 i = 2，而不能跳到 i = 3。

在我们的第三次跳跃（奇数）中，我们从 i = 2 跳到 i = 3，因为 A[3] 是（A[3]，A[4]）中大于或等于 A[2] 的最小值。

我们不能从 i = 3 跳到 i = 4，所以起始索引 i = 0 不是好的起始索引。

类似地，我们可以推断：
从起始索引 i = 1 出发， 我们跳到 i = 4，这样我们就到达数组末尾。
从起始索引 i = 2 出发， 我们跳到 i = 3，然后我们就不能再跳了。
从起始索引 i = 3 出发， 我们跳到 i = 4，这样我们就到达数组末尾。
从起始索引 i = 4 出发，我们已经到达数组末尾。
总之，我们可以从 3 个不同的起始索引（i = 1, i = 3, i = 4）出发，通过一定数量的跳跃到达数组末尾。
示例 3：

输入：[5,1,3,4,2]
输出：3
解释：
我们可以从起始索引 1，2，4 出发到达数组末尾。
 

提示：

1 <= A.length <= 20000
0 <= A[i] < 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-jump
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int i, size = arr.size(), goodIndices = 1;

        vector<bool> odds(size), evens(size);
        odds[size - 1] = evens[size - 1] = true;

        map<int, int> numIndices;
        numIndices[arr[size - 1]] = size - 1;

        for (i = size - 2; i >= 0; --i) {
            int num = arr[i];
            auto iter = numIndices.lower_bound(num);  // 找后面第一个>=自己的
            if (iter == numIndices.end()) {
                odds[i] = false;  // 如果没有，说明奇数跳不可达
            }
            else {
                odds[i] = evens[iter->second];  // 奇数跳可以往后，那么当前位置奇数跳状态等于下一跳偶数跳状态
                if (odds[i]) {
                    ++goodIndices;  // 如果可达最后，记数加1
                }
            }

            if (iter == numIndices.end()) {  // 将iter减1就是第一个小于自己的数
                --iter;
                evens[i] = odds[iter->second];
            }
            else {
                if (iter->first == num) {  // 如果已经有一个等于自己的数，则不用减了
                    evens[i] = odds[iter->second];
                }
                else {
                    if (iter == numIndices.begin()) {  // 如果没有小于自己的数，则不可达
                        evens[i] = false;
                    }
                    else {
                        --iter;
                        evens[i] = odds[iter->second];  // 如果偶数跳可以往后，那么偶数跳状态等于下一跳奇数跳状态
                    }
                }
            }

            numIndices[num] = i;  // 记录该数字的最小索引
        }

        return goodIndices;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 10,13,12,14,15 };
    check.checkInt(2, o.oddEvenJumps(arr));

    arr = { 2,3,1,1,4 };
    check.checkInt(3, o.oddEvenJumps(arr));

    arr = { 5,1,3,4,2 };
    check.checkInt(3, o.oddEvenJumps(arr));

    arr = { 5 };
    check.checkInt(1, o.oddEvenJumps(arr));

    arr = { 1,2,3,2,1,4,4,5 };
    check.checkInt(6, o.oddEvenJumps(arr));

    arr = { 1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5 };
    check.checkInt(12, o.oddEvenJumps(arr));

    arr = { 1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5,1,2,3,2,1,4,4,5 };
    check.checkInt(48, o.oddEvenJumps(arr));
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
