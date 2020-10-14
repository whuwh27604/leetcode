/* 和可被 K 整除的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

 

示例：

输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

提示：

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sums-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> remainderCount;
        int preSum = 0, subarrays = 0;

        for (int num : A) {
            preSum += num;
            int remainder = preSum % K;
            if (remainder < 0) {
                remainder += K;  // 关键点，如果remainder是负数，要转化为正数。比如K=5,remainder=-2,那么应该和remainder=3是一组的
            }
            if (remainderCount.count(remainder) == 0) {
                remainderCount[remainder] = 1;
            }
            else {
                ++remainderCount[remainder];
            }
        }

        for (auto iter = remainderCount.begin(); iter != remainderCount.end(); ++iter) {
            if (iter->first == 0) {
                subarrays += (iter->second + 1) * iter->second / 2;
            }
            else if (iter->second > 1) {
                subarrays += (iter->second - 1) * iter->second / 2;
            }
        }

        return subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 4,5,0,-2,-3,1 };
    check.checkInt(7, o.subarraysDivByK(A, 5));

    A = { 0,8,5 };
    check.checkInt(1, o.subarraysDivByK(A, 10));

    A = { 5,5,5,5 };
    check.checkInt(10, o.subarraysDivByK(A, 5));

    A = { 5,5,4,5,5 };
    check.checkInt(6, o.subarraysDivByK(A, 5));

    A = { 8,3,4,7 };
    check.checkInt(1, o.subarraysDivByK(A, 5));

    A = { -2,-5,10 };
    check.checkInt(3, o.subarraysDivByK(A, 5));
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
