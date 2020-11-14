/* 判断能否形成等差数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数字数组 arr 。

如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。

如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

 

示例 1：

输入：arr = [3,5,1]
输出：true
解释：对数组重新排序得到 [1,3,5] 或者 [5,3,1] ，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
示例 2：

输入：arr = [1,2,4]
输出：false
解释：无法通过重新排序得到等差数列。
 

提示：

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-make-arithmetic-progression-from-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minimum = INT_MAX, maximum = INT_MIN;
        for (int num : arr) {
            minimum = minimum < num ? minimum : num;
            maximum = maximum > num ? maximum : num;
        }

        if (maximum == minimum) {
            return true;
        }

        int size = arr.size();
        if ((maximum - minimum) % (size - 1) != 0) {
            return false;
        }

        int diff = (maximum - minimum) / (size - 1);
        int* differences = new int[size]();
        for (int num : arr) {
            differences[(num - minimum) / diff] = 1;
        }

        for (int i = 0; i < size; i++) {
            if (differences[i] != 1) {
                return false;
            }
        }

        delete[] differences;
        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 1,2 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 2,1 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr)); 
    
    arr = { 2,2 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 0,0 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 2,0 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 1,3,5 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 3,5,1 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 5,3,1 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 1,2,4 };
    check.checkBool(false, o.canMakeArithmeticProgression(arr));

    arr = { 0,-2,2 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 8,2,6,4,10 };
    check.checkBool(true, o.canMakeArithmeticProgression(arr));

    arr = { 8,16,4,0,20 };
    check.checkBool(false, o.canMakeArithmeticProgression(arr));
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
