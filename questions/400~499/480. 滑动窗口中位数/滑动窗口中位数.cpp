/* 滑动窗口中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

 

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

 

提示：

你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i, size = nums.size();
        multiset<int> firstHalf, secondHalf;  // 始终保持firstHalf比secondHalf多一个或者相等
        vector<double> medians(size - k + 1);

        for (i = 0; i < size; ++i) {
            int num = nums[i];  // 插入当前的数
            if (firstHalf.empty() || num <= (*firstHalf.rbegin())) {
                firstHalf.insert(num);
            }
            else {
                secondHalf.insert(num);
            }

            if (i >= k) {  // 删除窗口外的数，注意multiset删除单个元素要用迭代器删，如果用val将删除所有这个元素
                num = nums[i - k];
                if (num <= *firstHalf.rbegin()) {
                    firstHalf.erase(firstHalf.find(num));                    
                }
                else {
                    secondHalf.erase(secondHalf.find(num));
                }
            }

            if ((int)firstHalf.size() - (int)secondHalf.size() >= 2) {  // 调整前后数列长度
                auto iter = --firstHalf.end();
                secondHalf.insert(*iter);
                firstHalf.erase(iter);
            }
            else if (firstHalf.size() < secondHalf.size()) {
                firstHalf.insert(*secondHalf.begin());
                secondHalf.erase(secondHalf.begin());
            }

            if (i >= k - 1) {
                if ((k & 1) == 0) {
                    medians[i + 1 - k] = ((double)(*firstHalf.rbegin()) + (*secondHalf.begin())) / 2;
                }
                else {
                    medians[i + 1 - k] = *firstHalf.rbegin();
                }
            }
        }

        return medians;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<double> actual = o.medianSlidingWindow(nums, 3);
    vector<double> expected = { 1,-1,-1,3,5,6 };
    check.checkDoubleVector(expected, actual);

    nums = { -2147483648,-2147483648,2147483647,-2147483648 };
    actual = o.medianSlidingWindow(nums, 2);
    expected = { -2147483648.00000,-0.50000,-0.50000 };
    check.checkDoubleVector(expected, actual);

    nums = { 2147483647,2147483647 };
    actual = o.medianSlidingWindow(nums, 2);
    expected = { 2147483647 };
    check.checkDoubleVector(expected, actual);

    nums = { 1,4,2,3 };
    actual = o.medianSlidingWindow(nums, 4);
    expected = { 2.5 };
    check.checkDoubleVector(expected, actual);

    nums = { 1,4,2,3 };
    actual = o.medianSlidingWindow(nums, 1);
    expected = { 1,4,2,3 };
    check.checkDoubleVector(expected, actual);

    nums = { 1,2,3,4,2,3,1,4,2 };
    actual = o.medianSlidingWindow(nums, 3);
    expected = { 2.0,3.0,3.0,3.0,2.0,3.0,2.0 };
    check.checkDoubleVector(expected, actual);
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
