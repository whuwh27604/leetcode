/* 情侣牵手.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。

人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)。

这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。

示例 1:

输入: row = [0, 2, 1, 3]
输出: 1
解释: 我们只需要交换row[1]和row[2]的位置即可。
示例 2:

输入: row = [3, 2, 0, 1]
输出: 0
解释: 无需交换座位，所有的情侣都已经可以手牵手了。
说明:

len(row) 是偶数且数值在 [4, 60]范围内。
可以保证row 是序列 0...len(row)-1 的一个全排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/couples-holding-hands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int i, size = row.size(), swaps = 0;
        vector<int> indices(size);

        for (i = 0; i < size; ++i) {
            indices[row[i]] = i;
        }

        for (i = 1; i < size; i += 2) {
            if ((row[i] ^ row[i - 1]) != 1) {  // 贪心算法，不是couple就交换奇数位置的人
                int couple = (1 ^ row[i - 1]);
                int index = indices[couple];
                row[index] = row[i];  // 将row[i - 1]的couple交换到row[i]位置，原row[i]位置的数交换到couple的位置
                indices[row[i]] = index;
                row[i] = couple;
                indices[couple] = i;
                ++swaps;
            }
        }

        return swaps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> row = { 0,2,1,3 };
    check.checkInt(1, o.minSwapsCouples(row));

    row = { 3,2,0,1 };
    check.checkInt(0, o.minSwapsCouples(row));

    row = { 8,3,1,9,4,2,5,0,7,6 };
    check.checkInt(3, o.minSwapsCouples(row));

    row = { 1,9,7,4,8,11,5,3,0,2,6,10 };
    check.checkInt(5, o.minSwapsCouples(row));

    row = { 5,6,13,14,22,16,12,25,7,11,2,18,20,21,23,3,9,17,0,10,4,8,19,24,1,15 };
    check.checkInt(11, o.minSwapsCouples(row));

    row = { 26,10,11,8,22,28,19,27,7,21,31,20,0,25,18,5,2,12,24,6,16,3,23,29,17,9,15,13,4,14,1,30 };
    check.checkInt(13, o.minSwapsCouples(row));

    row = { 25,29,19,15,6,30,21,17,23,34,14,16,18,36,24,22,10,37,20,8,27,0,11,1,35,13,4,5,3,2,32,12,33,9,7,28,26,31 };
    check.checkInt(16, o.minSwapsCouples(row));

    row = { 7,1,20,35,8,27,43,26,17,13,21,3,24,42,28,33,4,39,36,30,11,32,23,45,41,40,0,14,18,10,44,9,25,5,31,34,16,15,2,37,12,6,29,22,19,38 };
    check.checkInt(19, o.minSwapsCouples(row));

    row = { 54,33,35,32,55,44,38,18,48,5,37,10,21,34,7,53,1,24,16,30,15,42,27,3,11,47,26,22,52,20,46,31,8,4,29,6,9,51,40,49,25,19,41,2,0,28,43,50,12,13,45,14,36,23,39,17 };
    check.checkInt(26, o.minSwapsCouples(row));

    row = { 24,15,8,16,30,11,22,52,42,26,27,46,32,48,21,55,33,17,41,6,13,12,19,2,10,5,35,23,20,4,29,38,9,7,54,25,1,50,36,37,39,57,3,53,51,28,18,44,47,43,49,34,0,31,14,45,56,40 };
    check.checkInt(25, o.minSwapsCouples(row));
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
