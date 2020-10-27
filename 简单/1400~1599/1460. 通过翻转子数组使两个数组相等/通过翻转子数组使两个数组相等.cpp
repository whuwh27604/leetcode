/* 通过翻转子数组使两个数组相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相同的整数数组 target 和 arr 。

每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。你可以执行此过程任意次。

如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

 

示例 1：

输入：target = [1,2,3,4], arr = [2,4,1,3]
输出：true
解释：你可以按照如下步骤使 arr 变成 target：
1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
示例 2：

输入：target = [7], arr = [7]
输出：true
解释：arr 不需要做任何翻转已经与 target 相等。
示例 3：

输入：target = [1,12], arr = [12,1]
输出：true
示例 4：

输入：target = [3,7,9], arr = [3,7,11]
输出：false
解释：arr 没有数字 9 ，所以无论如何也无法变成 target 。
示例 5：

输入：target = [1,1,1,1,1], arr = [1,1,1,1,1]
输出：true
 

提示：

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-two-arrays-equal-by-reversing-sub-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int i, len = arr.size(), targetBucket[1001]{}, arrBucket[1001]{};

        for (i = 0; i < len; i++) {
            targetBucket[target[i]]++;
            arrBucket[arr[i]]++;
        }

        for (i = 0; i < 1001; i++) {
            if (targetBucket[i] != arrBucket[i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> target = { 1,2,3,4 };
    vector<int> arr = { 2,4,1,3 };
    check.checkBool(true, o.canBeEqual(target, arr));

    target = { 7 };
    arr = { 7 };
    check.checkBool(true, o.canBeEqual(target, arr));

    target = { 1,12 };
    arr = { 12,1 };
    check.checkBool(true, o.canBeEqual(target, arr));

    target = { 3,7,9 };
    arr = { 3,7,11 };
    check.checkBool(false, o.canBeEqual(target, arr));

    target = { 1,1,1,1,1 };
    arr = { 1,1,1,1,1 };
    check.checkBool(true, o.canBeEqual(target, arr));
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
