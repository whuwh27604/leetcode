/* 魔术索引.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。

示例1:

 输入：nums = [0, 2, 3, 4, 5]
 输出：0
 说明: 0下标的元素为0
示例2:

 输入：nums = [1, 1, 1]
 输出：1
提示:

nums长度在[1, 1000000]之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magic-index-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

// 这个题太扯淡了，二分法效率还不如直接遍历高。
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == i) {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkInt(-1, o.findMagicIndex(nums));

    nums = { 0 };
    check.checkInt(0, o.findMagicIndex(nums));

    nums = { 1 };
    check.checkInt(-1, o.findMagicIndex(nums));

    nums = { 1,2,3,4,4 };
    check.checkInt(4, o.findMagicIndex(nums));

    nums = { 1,1,1 };
    check.checkInt(1, o.findMagicIndex(nums));
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
