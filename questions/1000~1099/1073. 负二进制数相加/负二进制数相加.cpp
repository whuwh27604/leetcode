/* 负二进制数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。

数字以 数组形式 给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。例如，arr = [1,1,0,1] 表示数字 (-2)^3 + (-2)^2 + (-2)^0 = -3。数组形式 的数字也同样不含前导零：以 arr 为例，这意味着要么 arr == [0]，要么 arr[0] == 1。

返回相同表示形式的 arr1 和 arr2 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。

 

示例：

输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
输出：[1,0,0,0,0]
解释：arr1 表示 11，arr2 表示 5，输出表示 16 。
 

提示：

1 <= arr1.length <= 1000
1 <= arr2.length <= 1000
arr1 和 arr2 都不含前导零
arr1[i] 为 0 或 1
arr2[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/adding-two-negabinary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i, j, size1 = arr1.size(), size2 = arr2.size(), carrier = 0, sum;

        for (i = size1 - 1, j = size2 - 1; i >= 0 && j >= 0; --i, --j) {
            if (carrier == 0) {
                sum = arr1[i] + arr2[j];
                carrier = sum / 2;
                ans.push_back(sum % 2);
            }
            else {
                sum = arr1[i] + arr2[j] - carrier;
                carrier = (sum == -1) ? -1 : sum / 2;
                sum = (sum == -1) ? 1 : sum % 2;
                ans.push_back(sum);
            }
        }

        for (; i >= 0; --i) {
            sum = arr1[i] - carrier;
            carrier = (sum == -1) ? -1 : sum / 2;
            sum = (sum == -1) ? 1 : sum % 2;
            ans.push_back(sum);
        }

        for (; j >= 0; --j) {
            sum = arr2[j] - carrier;
            carrier = (sum == -1) ? -1 : sum / 2;
            sum = (sum == -1) ? 1 : sum % 2;
            ans.push_back(sum);
        }

        if (carrier != 0) {
            ans.push_back(1);
            ans.push_back(1);
        }

        while (ans.size() > 1 && ans.back() == 0) {  // 删除多余的0
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr1 = { 1,1,1,1,1 };
    vector<int> arr2 = { 1,0,1 };
    vector<int> actual = o.addNegabinary(arr1, arr2);
    vector<int> expected = { 1,0,0,0,0 };
    check.checkIntVector(expected, actual);

    arr1 = { 1,0,1 };
    arr2 = { 1,0,1 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 1,1,1,1,0 };
    check.checkIntVector(expected, actual);

    arr1 = { 1,1,1 };
    arr2 = { 1,1,1 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 1,1,0,1,0 };
    check.checkIntVector(expected, actual);

    arr1 = { 0 };
    arr2 = { 0 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    arr1 = { 1,0 };
    arr2 = { 0 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);

    arr1 = { 1 };
    arr2 = { 1,1 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    arr1 = { 1 };
    arr2 = { 1,1,0,1 };
    actual = o.addNegabinary(arr1, arr2);
    expected = { 1,0 };
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
