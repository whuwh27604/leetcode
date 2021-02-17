/* 将每个元素替换为右侧最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。

 

示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int i, len = arr.size(), rightMax = -1;
        vector<int> ans(len, 0);

        for (i = len - 1; i >= 0; i--) {
            ans[i] = rightMax;
            if (arr[i] > rightMax) {
                rightMax = arr[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 17,18,5,4,6,1 };
    vector<int> actual = o.replaceElements(arr);
    vector<int> expected = { 18,6,6,6,1,-1 };
    check.checkIntVector(expected, actual);

    arr = { 1 };
    actual = o.replaceElements(arr);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    arr = { 1,2 };
    actual = o.replaceElements(arr);
    expected = { 2,-1 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3 };
    actual = o.replaceElements(arr);
    expected = { 3,3,-1 };
    check.checkIntVector(expected, actual);

    arr = { 9,8,7,6,5 };
    actual = o.replaceElements(arr);
    expected = { 8,7,6,5,-1 };
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
