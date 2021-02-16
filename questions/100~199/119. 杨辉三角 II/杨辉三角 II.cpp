/* 杨辉三角 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums(++rowIndex, 1);

        for (int i = 3; i <= rowIndex; ++i) {
            for (int j = (i - 2); j >= (i / 2); --j) {  // 先填充一行数据的后一半
                nums[j] = nums[i - 1 - j] + nums[i - 1 - j - 1];
            }

            for (int j = 1; j < (i / 2); ++j) {  // 再copy到前一半
                nums[j] = nums[i - 1 - j];
            }
        }

        return nums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> expected = { 1 };
    vector<int> actual = o.getRow(0);
    check.checkIntVector(expected, actual);

    expected = { 1,1 };
    actual = o.getRow(1);
    check.checkIntVector(expected, actual);

    expected = { 1,2,1 };
    actual = o.getRow(2);
    check.checkIntVector(expected, actual);

    expected = { 1,3,3,1 };
    actual = o.getRow(3);
    check.checkIntVector(expected, actual);

    expected = { 1,4,6,4,1 };
    actual = o.getRow(4);
    check.checkIntVector(expected, actual);

    expected = { 1,5,10,10,5,1 };
    actual = o.getRow(5);
    check.checkIntVector(expected, actual);

    expected = { 1,6,15,20,15,6,1 };
    actual = o.getRow(6);
    check.checkIntVector(expected, actual);

    expected = { 1,7,21,35,35,21,7,1 };
    actual = o.getRow(7);
    check.checkIntVector(expected, actual);

    expected = { 1,33,528,5456,40920,237336,1107568,4272048,13884156,38567100,92561040,193536720,354817320,573166440,818809200,1037158320,1166803110,1166803110,1037158320,818809200,573166440,354817320,193536720,92561040,38567100,13884156,4272048,1107568,237336,40920,5456,528,33,1 };
    actual = o.getRow(33);
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
