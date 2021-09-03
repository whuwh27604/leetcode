/* 最小K个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int> smallest;
        vector<int> knum(k);

        for (int num : arr) {
            smallest.push(num);
            if ((int)smallest.size() > k) {
                smallest.pop();
            }
        }

        for (int i = 0; i < k; ++i) {
            knum[i] = smallest.top();
            smallest.pop();
        }

        return knum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,3,5,7,2,4,6,8 };
    vector<int> actual = o.smallestK(arr, 4);
    vector<int> expected = { 1,2,3,4 };
    check.checkIntVectorRandomOrder(expected, actual);

    arr = {  };
    actual = o.smallestK(arr, 0);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    arr = { 1,2,3 };
    actual = o.smallestK(arr, 1);
    expected = { 1 };
    check.checkIntVectorRandomOrder(expected, actual);

    arr = { 1,2,3 };
    actual = o.smallestK(arr, 3);
    expected = { 1,2,3 };
    check.checkIntVectorRandomOrder(expected, actual);
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
