/* 汉明距离总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count1s[32] = { 0 }, totalDistance = 0, size = nums.size();

        for (int num : nums) {
            int index = 0;
            while (num != 0) {
                if ((num & 1) == 1) {
                    count1s[index]++;
                }
                index++;
                num >>= 1;
            }
        }

        for (int i = 0; i < 32; i++) {
            totalDistance += (count1s[i] * (size - count1s[i]));
        }

        return totalDistance;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,14,2 };
    check.checkInt(6, o.totalHammingDistance(nums));

    nums = {  };
    check.checkInt(0, o.totalHammingDistance(nums));

    nums = { 5 };
    check.checkInt(0, o.totalHammingDistance(nums));

    nums = { 0b1111111111111111111111111111111,0,1 };
    check.checkInt(62, o.totalHammingDistance(nums));

    nums = { 0b1111111111111111111111111111111,0,1,2 };
    check.checkInt(95, o.totalHammingDistance(nums));
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
