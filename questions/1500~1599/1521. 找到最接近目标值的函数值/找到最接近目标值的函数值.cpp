/* 找到最接近目标值的函数值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

Winston 构造了一个如上所示的函数 func 。他有一个整数数组 arr 和一个整数 target ，他想找到让 |func(arr, l, r) - target| 最小的 l 和 r 。

请你返回 |func(arr, l, r) - target| 的最小值。

请注意， func 的输入参数 l 和 r 需要满足 0 <= l, r < arr.length 。

 

示例 1：

输入：arr = [9,12,3,7,15], target = 5
输出：2
解释：所有可能的 [l,r] 数对包括 [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]]， Winston 得到的相应结果为 [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0] 。最接近 5 的值是 7 和 3，所以最小差值为 2 。
示例 2：

输入：arr = [1000000,1000000,1000000], target = 1
输出：999999
解释：Winston 输入函数的所有可能 [l,r] 数对得到的函数值都为 1000000 ，所以最小差值为 999999 。
示例 3：

输入：arr = [1,2,4,8,16], target = 0
输出：0
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
0 <= target <= 10^7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-a-value-of-a-mysterious-function-closest-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int left, right = 0, size = arr.size(), maxBit = 20, ans = 0, closest = INT_MAX;
        vector<int> bitsSum;

        for (left = 0; left < size; ++left) {
            if (left == right) {
                bitsSum = toBinary(arr[left], maxBit);
                right += 1;
                ans = arr[left];
            }
            else {
                remove(bitsSum, arr[left - 1], maxBit);
                ans = getAns(bitsSum, right - left, maxBit);
            }

            for (; right < size && (ans & arr[right]) >= target; ++right) {
                ans &= arr[right];
                add(bitsSum, arr[right], maxBit);
            }

            if (ans < target) {
                closest = min(closest, target - ans);  // arr[left]已经小于target
            }
            else {
                closest = min(closest, ans - target);  // 最后一个大于target的ans

                if (right < size) {
                    closest = min(closest, target - (ans & arr[right]));  // 第一个小于target的ans
                }
            }
        }

        return closest;
    }

    int getAns(vector<int>& bitsSum, int size, int maxBit) {
        int ans = 0;

        for (int i = 0; i < maxBit; ++i) {
            ans = (ans << 1) | (bitsSum[i] == size ? 1 : 0);
        }

        return ans;
    }

    void add(vector<int>& bitsSum, int num, int maxBit) {
        vector<int> bits = toBinary(num, maxBit);

        for (int i = 0; i < maxBit; ++i) {
            bitsSum[i] += bits[i];
        }
    }

    void remove(vector<int>& bitsSum, int num, int maxBit) {
        vector<int> bits = toBinary(num, maxBit);

        for (int i = 0; i < maxBit; ++i) {
            bitsSum[i] -= bits[i];
        }
    }

    vector<int> toBinary(int num, int maxBit) {
        vector<int> bits(maxBit, 0);
        int index = maxBit - 1;

        while (num != 0) {
            bits[index--] = (num & 1);
            num >>= 1;
        }

        return bits;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 9,12,3,7,15 };
    check.checkInt(2, o.closestToTarget(arr, 5));

    arr = { 1000000,1000000,1000000 };
    check.checkInt(999999, o.closestToTarget(arr, 1));

    arr = { 1,2,4,8,16 };
    check.checkInt(0, o.closestToTarget(arr, 0));

    arr = { 1,2,4,8,16 };
    check.checkInt(0, o.closestToTarget(arr, 1));

    arr = { 1,2,4,8,16 };
    check.checkInt(1, o.closestToTarget(arr, 3));

    arr = { 1,2,4,8,16 };
    check.checkInt(2, o.closestToTarget(arr, 6));

    arr = { 1,2,4,8,16 };
    check.checkInt(1, o.closestToTarget(arr, 9));

    arr = { 1,2,4,8,16 };
    check.checkInt(4, o.closestToTarget(arr, 12));

    arr = { 59,63,31,53 };
    check.checkInt(0, o.closestToTarget(arr, 21));
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
