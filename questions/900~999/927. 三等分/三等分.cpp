/* 三等分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由 0 和 1 组成的数组 arr ，将数组分成  3 个非空的部分 ，使得所有这些部分表示相同的二进制值。

如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：

arr[0], arr[1], ..., arr[i] 为第一部分；
arr[i + 1], arr[i + 2], ..., arr[j - 1] 为第二部分；
arr[j], arr[j + 1], ..., arr[arr.length - 1] 为第三部分。
这三个部分所表示的二进制值相等。
如果无法做到，就返回 [-1, -1]。

注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0] 表示十进制中的 6，而不会是 3。此外，前导零也是被允许的，所以 [0,1,1] 和 [1,1] 表示相同的值。

 

示例 1：

输入：arr = [1,0,1,0,1]
输出：[0,3]
示例 2：

输入：arr = [1,1,0,1,1]
输出：[-1,-1]
示例 3:

输入：arr = [1,1,0,0,1]
输出：[0,2]
 

提示：

3 <= arr.length <= 3 * 104
arr[i] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/three-equal-parts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = accumulate(arr.begin(), arr.end(), 0);

        if (ones == 0) {
            return { 0,2 };
        }

        if (ones % 3 != 0) {
            return { -1,-1 };
        }

        ones /= 3;
        int zeros = getLastZeros(arr);

        int firstEnd = getEnd(arr, ones, zeros, 0);
        if (firstEnd == -1) {
            return { -1,-1 };
        }

        int secondEnd = getEnd(arr, ones, zeros, firstEnd + 1);
        if (secondEnd == -1) {
            return { -1,-1 };
        }

        if (check(arr, firstEnd, secondEnd, ones)) {
            return { firstEnd,secondEnd + 1 };
        }

        return { -1,-1 };
    }

    int getLastZeros(vector<int>& arr) {
        int zeros = 0;

        for (int i = arr.size() - 1; i > 0 && arr[i] == 0; --i) {
            ++zeros;
        }

        return zeros;
    }

    int getEnd(vector<int>& arr, int ones, int zeros, int start) {
        int i, size = arr.size();

        for (i = start; i < size; ++i) {
            if (arr[i] == 1) {
                if (--ones == 0) {
                    break;
                }
            }
        }

        while (zeros != 0) {
            ++i, --zeros;
            if (i == size || arr[i] != 0) {
                return -1;
            }
        }

        return i;
    }

    bool check(vector<int>& arr, int firstEnd, int secondEnd, int ones) {
        for (int i = firstEnd, j = secondEnd, k = arr.size() - 1; ones != 0; --i, --j, --k) {
            if (arr[i] != arr[j] || arr[i] != arr[k]) {
                return false;
            }

            if (arr[i] == 1) {
                --ones;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,0,1,0,1 };
    vector<int> actual = o.threeEqualParts(arr);
    vector<int> expected = { 0,3 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,0,1,1 };
    actual = o.threeEqualParts(arr);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,0,0,1 };
    actual = o.threeEqualParts(arr);
    expected = { 0,2 };
    check.checkIntVector(expected, actual);

    arr = { 0,0,0,0,0 };
    actual = o.threeEqualParts(arr);
    expected = { 0,2 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,0,1,0 };
    actual = o.threeEqualParts(arr);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    arr = { 1,0,1,1,0 };
    actual = o.threeEqualParts(arr);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    arr = { 1,0,1,1,1,0,1,1,1,1,0,1 };
    actual = o.threeEqualParts(arr);
    expected = { -1,-1 };
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
