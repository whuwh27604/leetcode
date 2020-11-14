/* 第 k 个缺失的正整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。

请你找到这个数组里第 k 个缺失的正整数。

 

示例 1：

输入：arr = [2,3,4,7,11], k = 5
输出：9
解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
示例 2：

输入：arr = [1,2,3,4], k = 2
输出：6
解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
 

提示：

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-missing-positive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, num, size = arr.size(), missing = 0;

        for (num = 1; num < INT_MAX; num++) {
            if (arr[i] == num) {
                i = (i == size - 1) ? size - 1 : i + 1;
            }
            else {
                if (++missing == k) {
                    break;
                }
            }
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 2,3,4,7,11 };
    check.checkInt(9, o.findKthPositive(arr, 5));

    arr = { 1,2,3,4 };
    check.checkInt(6, o.findKthPositive(arr, 2));

    arr = { 1 };
    check.checkInt(4, o.findKthPositive(arr, 3));

    arr = { 4 };
    check.checkInt(3, o.findKthPositive(arr, 3));
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
