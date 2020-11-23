/* 只出现一次的数字 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;

        /* num第一次出现，once、twice都没有num，所以once^num后，once有num，&~twice后仍然有；twice^num后twice有num，但此时once有num，所以&~once后又去掉了num
           num第二次出现，此时once有num，所以once^num后没有num；twice没有num，twice^num后有num，&~once后仍然有num
           num第三次出现，此时once没有num，once^num后有num，但因为twice也有num，所以&~twice后没有num；因为twice有num，所以twice^num后没有num
           综上，num第三次出现后，once、twice里面都没有num。而只出现一次的数会保留在once里面 */

        for (int num : nums) {
            once = ~twice & (once ^ num);
            twice = ~once & (twice ^ num);
        }

        return once;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,2,3,2 };
    check.checkInt(3, o.singleNumber(nums));

    nums = { 0,1,0,1,0,1,99 };
    check.checkInt(99, o.singleNumber(nums));

    nums = { -5,-5,-3,-5 };
    check.checkInt(-3, o.singleNumber(nums));
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
