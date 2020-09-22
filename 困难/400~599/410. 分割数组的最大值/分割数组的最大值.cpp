/* 分割数组的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long maximum = 0, sum = 0;
        for (int number : nums) {
            sum += number;
            maximum = (maximum > number ? maximum : number);
        }

        /* 把nums分为size组，则子数组和的最大值为maximum；把nums分为1组，则子数组和的最大值为sum。所以分为m组时，子数组和的最大值在maximum和sum之间。
           采用二分法逼近子数组和最大值的最小可能：假设该最小可能是middle，然后按照middle划分nums，如果划分的组数大于m，说明每组的数少了，也就是
           middle偏小，应该到右半区间再找；如果划分的组数小于等于m，说明middle要么大了，要么就是最终的最小可能，所以到左半区间再找。因为此时middle
           可能是答案，所以左半区间要包含middle。最终left+1=right时，执行最后一次循环。此时如果分出来大于m，left会加1；如果小于等于m，left不变。
           所以最终返回left就可以了。 */
        long long left = maximum, right = sum, middle;
        int subArrayNum = 0;

        while (left < right) {  // 不能<=，因为执行的结果可能是right = middle;如果包含相等的话，right一直不变就死循环了。
            middle = (left + right) / 2;
            subArrayNum = splitArr(nums, middle);
            if (subArrayNum > m) {
                left = middle + 1;  // subArrayNum > m，那么middle一定不是解，所以left可以直接跳到middle+1
            }
            else {
                right = middle;  // subArrayNum <= m，那么middle可能是解，所以不能漏过了。
            }
        }

        // 因为答案一定在[left,right]之间，每一次把确定错误的排除，最后剩下的left==right就一定是答案
        return (int)left;
    }

    int splitArr(vector<int>& nums, long long maxSubArraySum) {
        long long sum = 0;
        int count = 0;

        for (int number : nums) {
            sum += number;
            if (sum > maxSubArraySum) {
                count++;
                sum = number;
            }
        }

        return count + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 7,2,5,10,8 };
    check.checkInt(18, o.splitArray(nums, 2));

    nums = { 7,2,5,10,8 };
    check.checkInt(10, o.splitArray(nums, 5));

    nums = { 7,2,5,10,8 };
    check.checkInt(32, o.splitArray(nums, 1));

    nums = { 5,23 };
    check.checkInt(23, o.splitArray(nums, 2));

    nums = { 5,8,10 };
    check.checkInt(13, o.splitArray(nums, 2));

    nums = { 1,2,3,4,2,1,5 };
    check.checkInt(6, o.splitArray(nums, 3));

    nums = { 0,0,0 };
    check.checkInt(0, o.splitArray(nums, 3));

    nums = { 1,1,1 };
    check.checkInt(1, o.splitArray(nums, 3));

    nums = { 1,1,1 };
    check.checkInt(2, o.splitArray(nums, 2));

    nums = { 1,1,1 };
    check.checkInt(3, o.splitArray(nums, 1));

    nums = { 1,2147483647 };
    check.checkInt(2147483647, o.splitArray(nums, 2));
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
