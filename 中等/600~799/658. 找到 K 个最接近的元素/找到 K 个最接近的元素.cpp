/* 找到 K 个最接近的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
 

示例 2:

输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
 

说明:

k 的值为正数，且总是小于给定排序数组的长度。
数组不为空，且长度不超过 104
数组里的每个元素与 x 的绝对值不超过 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-closest-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 答案是连续的区间arr[start, start+k)，用二分法来找这个start
        int startLeft = 0, startRight = arr.size() - k;

        while (startLeft < startRight) {
            int startMiddle = (startLeft + startRight) / 2;

            if ((x - arr[startMiddle]) > (arr[startMiddle + k] - x)) {
                /* 区间为arr[startMiddle, startMiddle+k)，arr[startMiddle+k]是区间右边第一个数，x到arr[startMiddle]的距离比到arr[startMiddle+k]的距离大，
                   那么明显不应该要arr[startMiddle]，而应该选arr[startMiddle+k]，所以应该到右半边去找start */
                startLeft = startMiddle + 1;
            }
            else {
                startRight = startMiddle;  // x到arr[startMiddle]的距离等于x到arr[startMiddle+k]的距离的情况下， startMiddle可能就是解，不能减一
            }
        }

        return vector<int>(arr.begin() + startLeft, arr.begin() + startLeft + k);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 1,2,3,4,5 };
    vector<int> actual = o.findClosestElements(arr, 4, 3);
    vector<int> expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.findClosestElements(arr, 4, -1);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.findClosestElements(arr, 1, 6);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.findClosestElements(arr, 5, 1);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.findClosestElements(arr, 5, 5);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    arr = { 5 };
    actual = o.findClosestElements(arr, 1, -1);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    arr = { 1 };
    actual = o.findClosestElements(arr, 1, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    arr = { 3,8 };
    actual = o.findClosestElements(arr, 1, 5);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    arr = { 3,8 };
    actual = o.findClosestElements(arr, 1, 6);
    expected = { 8 };
    check.checkIntVector(expected, actual);

    arr = { 3,8 };
    actual = o.findClosestElements(arr, 2, 9);
    expected = { 3,8 };
    check.checkIntVector(expected, actual);

    arr = { 3,7 };
    actual = o.findClosestElements(arr, 2, 5);
    expected = { 3,7 };
    check.checkIntVector(expected, actual);

    arr = { -3,-3,-1,-1,2,2,4,4 };
    actual = o.findClosestElements(arr, 5, 0);
    expected = { -3,-1,-1,2,2 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,3,5,6 };
    actual = o.findClosestElements(arr, 1, 4);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,1,3,3 };
    actual = o.findClosestElements(arr, 4, 2);
    expected = { 1,1,1,3 };
    check.checkIntVector(expected, actual);

    arr = { 0,0,0,0,0,0,1,1,1,3,3 };
    actual = o.findClosestElements(arr, 4, 2);
    expected = { 1,1,1,3 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,1,3,3,4,4,4,4,4,4,4 };
    actual = o.findClosestElements(arr, 4, 2);
    expected = { 1,1,1,3 };
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
