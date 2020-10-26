/* 最小绝对差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

 

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]
示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]
示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]
 

提示：

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        for (unsigned int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff == minDiff) {
                ans.push_back({ arr[i - 1],arr[i] });
            }
            else if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({ arr[i - 1],arr[i] });
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 4,2,1,3 };
    vector<vector<int>> actual = o.minimumAbsDifference(arr);
    vector<vector<int>> expected = { {1,2},{2,3},{3,4} };
    check.checkIntDoubleVector(expected, actual);

    arr = { 1,3,6,10,15 };
    actual = o.minimumAbsDifference(arr);
    expected = { {1,3} };
    check.checkIntDoubleVector(expected, actual);

    arr = { 3,8,-10,23,19,-4,-14,27 };
    actual = o.minimumAbsDifference(arr);
    expected = { {-14,-10},{19,23},{23,27} };
    check.checkIntDoubleVector(expected, actual);

    arr = { 3,6 };
    actual = o.minimumAbsDifference(arr);
    expected = { {3,6} };
    check.checkIntDoubleVector(expected, actual);
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
