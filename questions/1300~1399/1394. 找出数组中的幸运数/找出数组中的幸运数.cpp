/* 找出数组中的幸运数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。

给你一个整数数组 arr，请你从中找出并返回一个幸运数。

如果数组中存在多个幸运数，只需返回 最大 的那个。
如果数组中不含幸运数，则返回 -1 。
 

示例 1：

输入：arr = [2,2,3,4]
输出：2
解释：数组中唯一的幸运数是 2 ，因为数值 2 的出现频次也是 2 。
示例 2：

输入：arr = [1,2,2,3,3,3]
输出：3
解释：1、2 以及 3 都是幸运数，只需要返回其中最大的 3 。
示例 3：

输入：arr = [2,2,2,3,3]
输出：-1
解释：数组中不存在幸运数。
示例 4：

输入：arr = [5]
输出：-1
示例 5：

输入：arr = [7,7,7,7,7,7,7]
输出：7
 

提示：

1 <= arr.length <= 500
1 <= arr[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-lucky-integer-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int i, len = arr.size(), numsCount[501]{};

        for (i = 0; i < len; i++) {
            numsCount[arr[i]]++;
        }

        for (i = 500; i > 0; i--) {
            if (numsCount[i] == i) {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 2,2,3,4 };
    check.checkInt(2, o.findLucky(arr));

    arr = { 1,2,2,3,3,3 };
    check.checkInt(3, o.findLucky(arr));

    arr = { 2,2,2,3,3 };
    check.checkInt(-1, o.findLucky(arr));

    arr = { 5 };
    check.checkInt(-1, o.findLucky(arr));

    arr = { 1 };
    check.checkInt(1, o.findLucky(arr));

    arr = { 7,7,7,7,7,7,7 };
    check.checkInt(7, o.findLucky(arr));

    arr = {};
    for (int i = 0; i < 500; i++) {
        arr.push_back(500);
    }
    check.checkInt(500, o.findLucky(arr));
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
