/* 根据数字二进制下 1 的数目排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。

如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。

请你返回排序后的数组。

 

示例 1：

输入：arr = [0,1,2,3,4,5,6,7,8]
输出：[0,1,2,4,8,3,5,6,7]
解释：[0] 是唯一一个有 0 个 1 的数。
[1,2,4,8] 都有 1 个 1 。
[3,5,6] 有 2 个 1 。
[7] 有 3 个 1 。
按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
示例 2：

输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
输出：[1,2,4,8,16,32,64,128,256,512,1024]
解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
示例 3：

输入：arr = [10000,10000]
输出：[10000,10000]
示例 4：

输入：arr = [2,3,5,7,11,13,17,19]
输出：[2,3,5,17,7,11,13,19]
示例 5：

输入：arr = [10,100,1000,10000]
输出：[10,100,10000,1000]
 

提示：

1 <= arr.length <= 500
0 <= arr[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<multiset<int>> bitsSortedNum(15);  // arr[i]最多14个1

        for (unsigned int i = 0; i < arr.size(); i++) {
            bitsSortedNum[countOnes(arr[i])].insert(arr[i]);
        }

        vector<int> ans;
        ans.reserve(arr.size());

        for (int j = 0; j < 15; j++) {
            for (auto iter = bitsSortedNum[j].begin(); iter != bitsSortedNum[j].end(); iter++) {
                ans.push_back(*iter);
            }
        }

        return ans;
    }

    int countOnes(int n) {
        int count = 0;

        while (n != 0) {
            n &= (n - 1);
            count++;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 0,1,2,3,4,5,6,7,8 };
    vector<int> actual = o.sortByBits(arr);
    vector<int> expected = { 0,1,2,4,8,3,5,6,7 };
    check.checkIntVector(expected, actual);

    arr = { 1024,512,256,128,64,32,16,8,4,2,1 };
    actual = o.sortByBits(arr);
    expected = { 1,2,4,8,16,32,64,128,256,512,1024 };
    check.checkIntVector(expected, actual);

    arr = { 10000,10000 };
    actual = o.sortByBits(arr);
    expected = { 10000,10000 };
    check.checkIntVector(expected, actual);

    arr = { 2,3,5,7,11,13,17,19 };
    actual = o.sortByBits(arr);
    expected = { 2,3,5,17,7,11,13,19 };
    check.checkIntVector(expected, actual);

    arr = { 10,100,1000,10000 };
    actual = o.sortByBits(arr);
    expected = { 10,100,10000,1000 };
    check.checkIntVector(expected, actual);

    arr = { 0 };
    actual = o.sortByBits(arr);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    arr = { 10000 };
    actual = o.sortByBits(arr);
    expected = { 10000 };
    check.checkIntVector(expected, actual);

    arr = { 8191,8192,8190,4095,4094,4096 };
    actual = o.sortByBits(arr);
    expected = { 4096,8192,4094,4095,8190,8191 };
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
