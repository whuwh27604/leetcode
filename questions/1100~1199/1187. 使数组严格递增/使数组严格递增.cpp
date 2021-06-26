/* 使数组严格递增.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 arr1 和 arr2，返回使 arr1 严格递增所需要的最小「操作」数（可能为 0）。

每一步「操作」中，你可以分别从 arr1 和 arr2 中各选出一个索引，分别为 i 和 j，0 <= i < arr1.length 和 0 <= j < arr2.length，然后进行赋值运算 arr1[i] = arr2[j]。

如果无法让 arr1 严格递增，请返回 -1。

 

示例 1：

输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
输出：1
解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。
示例 2：

输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]
输出：2
解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。
示例 3：

输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
输出：-1
解释：无法使 arr1 严格递增。
 

提示：

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-array-strictly-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());  // arr2去重
        arr1.insert(arr1.begin(), -1);  // arr1添加前置、后置节点
        arr1.push_back(INT_MAX);
        int i, j, k, size1 = arr1.size(), size2 = arr2.size(), inf = 1000000007;
        vector<int> dp(size1, inf);  // dp[i]表示arr1[i]不被替换的情况下，需要的最小操作数
        dp[0] = 0;

        for (i = 1; i < size1; ++i) {
            j = distance(arr2.begin(), lower_bound(arr2.begin(), arr2.end(), arr1[i])) - 1;  // 找到可以被替换的位置

            for (k = i - 1; k > 0 && j >= 0; --k, --j) {  // 尝试替换掉arr1[i]前面所有数
                if (arr1[k - 1] < arr2[j]) {  // 替换完成以后，前面一个数比替换的这个数小，整个序列可以构成一个递增序列
                    dp[i] = min(dp[i], dp[k - 1] + i - k);
                }
            }

            if (arr1[i - 1] < arr1[i]) {  // 前一个数更小，可以选择不替换它
                dp[i] = min(dp[i], dp[i - 1]);
            }
        }

        return dp.back() >= inf ? -1 : dp.back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr1 = { 1,5,3,6,7 };
    vector<int> arr2 = { 1,3,2,4 };
    check.checkInt(1, o.makeArrayIncreasing(arr1, arr2));

    arr1 = { 1,5,3,6,7 };
    arr2 = { 4,3,1 };
    check.checkInt(2, o.makeArrayIncreasing(arr1, arr2));

    arr1 = { 1,5,3,6,7 };
    arr2 = { 1,6,3,3 };
    check.checkInt(-1, o.makeArrayIncreasing(arr1, arr2));

    arr1 = { 0,11,6,1,4,3 };
    arr2 = { 0,1,4,5,10,11 };
    check.checkInt(5, o.makeArrayIncreasing(arr1, arr2));
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
