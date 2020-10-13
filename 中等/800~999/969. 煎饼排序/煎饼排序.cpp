/* 煎饼排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k 个元素的顺序。我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。

返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length 范围内的有效答案都将被判断为正确。

 

示例 1：

输入：[3,2,4,1]
输出：[4,2,4,3]
解释：
我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
初始状态 A = [3, 2, 4, 1]
第一次翻转后 (k=4): A = [1, 4, 2, 3]
第二次翻转后 (k=2): A = [4, 1, 2, 3]
第三次翻转后 (k=4): A = [3, 2, 1, 4]
第四次翻转后 (k=3): A = [1, 2, 3, 4]，此时已完成排序。
示例 2：

输入：[1,2,3]
输出：[]
解释：
输入已经排序，因此不需要翻转任何内容。
请注意，其他可能的答案，如[3，3]，也将被接受。
 

提示：

1 <= A.length <= 100
A[i] 是 [1, 2, ..., A.length] 的排列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pancake-sorting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> Ks;

        for (int last = arr.size(); last > 1; --last) {
            sortLast(arr, last, Ks);
        }

        return Ks;
    }

    void sortLast(vector<int>& arr, int last, vector<int>& Ks) {
        int index = findLast(arr, last);
        if (index == last - 1) {  // 已经在最后，不需要反转了
            return;
        }

        if (index != 0) {  // 如果不在第一个，先把它换到第一个
            Ks.push_back(index + 1);
            reverse(arr.begin(), arr.begin() + index + 1);
        }
        Ks.push_back(last);  // 再把它换到最后
        reverse(arr.begin(), arr.begin() + last);
    }

    int findLast(vector<int>& arr, int last) {
        int i, size = arr.size();

        for (i = 0; i < size; ++i) {
            if (arr[i] == last) {
                break;
            }
        }

        return i;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 3,2,4,1 };
    vector<int> actual = o.pancakeSort(arr);
    vector<int> expected = { 3,4,2,3,2 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3 };
    actual = o.pancakeSort(arr);
    expected = {  };
    check.checkIntVector(expected, actual);

    arr = { 1 };
    actual = o.pancakeSort(arr);
    expected = {  };
    check.checkIntVector(expected, actual);

    arr = { 1,2 };
    actual = o.pancakeSort(arr);
    expected = {  };
    check.checkIntVector(expected, actual);

    arr = { 2,1 };
    actual = o.pancakeSort(arr);
    expected = { 2 };
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
