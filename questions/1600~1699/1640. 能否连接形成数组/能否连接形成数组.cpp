/* 能否连接形成数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr ，数组中的每个整数 互不相同 。另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同 。请你以 任意顺序 连接 pieces 中的数组以形成 arr 。但是，不允许 对每个数组 pieces[i] 中的整数重新排序。

如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false 。

 

示例 1：

输入：arr = [85], pieces = [[85]]
输出：true
示例 2：

输入：arr = [15,88], pieces = [[88],[15]]
输出：true
解释：依次连接 [15] 和 [88]
示例 3：

输入：arr = [49,18,16], pieces = [[16,18,49]]
输出：false
解释：即便数字相符，也不能重新排列 pieces[0]
示例 4：

输入：arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
输出：true
解释：依次连接 [91]、[4,64] 和 [78]
示例 5：

输入：arr = [1,3,5,7], pieces = [[2,4,6,8]]
输出：false
 

提示：

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
arr 中的整数 互不相同
pieces 中的整数 互不相同（也就是说，如果将 pieces 扁平化成一维数组，数组中的所有整数互不相同）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-array-formation-through-concatenation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i, j = 0, size = 0;

        vector<int> firstIndices(101, -1);
        getFirstIndices(pieces, firstIndices);

        for (int num : arr) {
            if (j == size) {
                i = firstIndices[num];
                if (i == -1) {
                    return false;
                }

                j = 0;
                size = pieces[i].size();
            }

            if (num != pieces[i][j++]) {
                return false;
            }
        }

        return true;
    }

    void getFirstIndices(vector<vector<int>>& pieces, vector<int>& firstIndices) {
        for (int i = 0; i < (int)pieces.size(); ++i) {
            firstIndices[pieces[i][0]] = i;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 85 };
    vector<vector<int>> pieces = { {85} };
    check.checkBool(true, o.canFormArray(arr, pieces));

    arr = { 15,88 };
    pieces = { {88},{15} };
    check.checkBool(true, o.canFormArray(arr, pieces));

    arr = { 49,18,16 };
    pieces = { {16,18,49} };
    check.checkBool(false, o.canFormArray(arr, pieces));

    arr = { 91,4,64,78 };
    pieces = { {78},{4,64},{91} };
    check.checkBool(true, o.canFormArray(arr, pieces));

    arr = { 1,3,5,7 };
    pieces = { {2,4,6,8} };
    check.checkBool(false, o.canFormArray(arr, pieces));
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
