/* K 秒后第 N 个元素的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
最初，你有一个长度为 n 的整数数组 a，对所有 0 <= i <= n - 1，都有 a[i] = 1 。每过一秒，你会同时更新每个元素为其前面所有元素的和加上该元素本身。例如，一秒后，a[0] 保持不变，a[1] 变为 a[0] + a[1]，a[2] 变为 a[0] + a[1] + a[2]，以此类推。

返回 k 秒后 a[n - 1] 的值。

由于答案可能非常大，返回其对 109 + 7 取余 后的结果。



示例 1：

输入：n = 4, k = 5

输出：56

解释：

时间（秒）	数组状态
0	[1,1,1,1]
1	[1,2,3,4]
2	[1,3,6,10]
3	[1,4,10,20]
4	[1,5,15,35]
5	[1,6,21,56]
示例 2：

输入：n = 5, k = 3

输出：35

解释：

时间（秒）	数组状态
0	[1,1,1,1,1]
1	[1,2,3,4,5]
2	[1,3,6,10,15]
3	[1,4,10,20,35]


提示：

1 <= n, k <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> nums(n, 1), presum(n);

        for (int i = 0; i < k; ++i) {
            presum[0] = 1;

            for (int j = 1; j < n; ++j) {
                presum[j] = (presum[j - 1] + nums[j]) % 1000000007;
            }

            nums = presum;
        }

        return nums.back();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(56, o.valueAfterKSeconds(4, 5));
    check.checkInt(35, o.valueAfterKSeconds(5, 3));
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
