/* 只出现一次的数字 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int n : nums) {
            bitmask ^= n;
        }  // bitmask = x ^ y ^ a ^ a ^ b ^ b... = x ^ y;

        //int rightmostOne = (bitmask & (-bitmask));  // 保留最后一位1，这个1要么来自x，要么来自y。但是没有限定数据范围的情况下，用例{0,INT_MIN}会导致这条语句整型溢出
        int rightmostOne = 1;
        while ((rightmostOne & bitmask) == 0) {
            rightmostOne <<= 1;
        }

        int x = 0;
        for (int n : nums) {
            if (n & rightmostOne) {  // 假设1来自x，则n & bitmask保留下了x，去掉了y，所以最后的结果就是x
                x ^= n;
            }
        }

        return { x, x ^ bitmask };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2 };
    vector<int> actual = o.singleNumber(nums);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    nums = { 0,INT_MIN };
    actual = o.singleNumber(nums);
    expected = { INT_MIN,0 };
    check.checkIntVector(expected, actual);

    nums = { 1,-1,0,INT_MIN,1,-1 };
    actual = o.singleNumber(nums);
    expected = { INT_MIN,0 };
    check.checkIntVector(expected, actual);

    nums = { 1,-1,INT_MAX,INT_MIN,1,-1 };
    actual = o.singleNumber(nums);
    expected = { INT_MAX,INT_MIN };
    check.checkIntVector(expected, actual);

    nums = { 1,-1,INT_MAX,0,0,INT_MIN,1,-1 };
    actual = o.singleNumber(nums);
    expected = { INT_MAX,INT_MIN };
    check.checkIntVector(expected, actual);

    nums = { 1,2,1,3,2,5 };
    actual = o.singleNumber(nums);
    expected = { 3,5 };
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
