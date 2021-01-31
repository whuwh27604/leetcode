/* 复写零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/duplicate-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i, countNums = 0, countZeros = 0, len = arr.size(), index = len - 1;
        bool lastZeroDuplicate = false;

        for (i = 0; i < len; i++) {
            countNums++;
            if (countNums == len) {
                lastZeroDuplicate = false;
                break;
            }

            if (arr[i] != 0) {
                continue;
            }

            countZeros++;
            countNums++;
            if (countNums == len) {
                lastZeroDuplicate = true;
                break;
            }
        }

        if ((arr[i] == 0) && (!lastZeroDuplicate)) {
            arr[index--] = arr[i--];
        }

        while ((i >= 0) && (countZeros != 0)) {
            arr[index--] = arr[i];
            if (arr[i] == 0) {
                arr[index--] = 0;
                countZeros--;
            }

            i--;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 0,1 };
    o.duplicateZeros(arr);
    vector<int> expected = { 0,0 };
    check.checkIntVector(expected, arr);

    arr = { 1,0,2,3,0,4,5,0 };
    o.duplicateZeros(arr);
    expected = { 1,0,0,2,3,0,0,4 };
    check.checkIntVector(expected, arr);

    arr = { 1,2,3 };
    o.duplicateZeros(arr);
    expected = { 1,2,3 };
    check.checkIntVector(expected, arr);

    arr = { 1,1,0,1 };
    o.duplicateZeros(arr);
    expected = { 1,1,0,0 };
    check.checkIntVector(expected, arr);

    arr = { 1,0 };
    o.duplicateZeros(arr);
    expected = { 1,0 };
    check.checkIntVector(expected, arr);

    arr = { 0,0,0,1,1,1 };
    o.duplicateZeros(arr);
    expected = { 0,0,0,0,0,0 };
    check.checkIntVector(expected, arr);

    arr = { 1,1,1,0,0,0 };
    o.duplicateZeros(arr);
    expected = { 1,1,1,0,0,0 };
    check.checkIntVector(expected, arr);
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
