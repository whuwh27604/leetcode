/* 数组的相对排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-sort-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        short bucket[1001] = {0};
        unsigned int i, index = 0;

        for (i = 0; i < arr1.size(); i++) {
            bucket[arr1[i]]++;
        }

        for (i = 0; i < arr2.size(); i++) {
            while (bucket[arr2[i]]-- != 0) {
                arr1[index++] = arr2[i];
            }
        }

        for (i = 0; i < 1001; i++) {
            while (bucket[i]-- > 0) {
                arr1[index++] = i;
            }
        }

        return arr1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    vector<int> arr2 = { 2,1,4,3,9,6 };
    vector<int> actual = o.relativeSortArray(arr1, arr2);
    vector<int> expected = { 2,2,2,1,4,3,3,9,6,7,19 };
    check.checkIntVector(expected, actual);

    arr1 = {  };
    arr2 = {  };
    actual = o.relativeSortArray(arr1, arr2);
    expected = {  };
    check.checkIntVector(expected, actual);

    arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    arr2 = {  };
    actual = o.relativeSortArray(arr1, arr2);
    expected = { 1,2,2,2,3,3,4,6,7,9,19 };
    check.checkIntVector(expected, actual);

    arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    arr2 = { 19 };
    actual = o.relativeSortArray(arr1, arr2);
    expected = { 19,1,2,2,2,3,3,4,6,7,9 };
    check.checkIntVector(expected, actual);

    arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    arr2 = { 19,3 };
    actual = o.relativeSortArray(arr1, arr2);
    expected = { 19,3,3,1,2,2,2,4,6,7,9 };
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
