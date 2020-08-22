/* 最小区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

示例 1:

输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释:
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
注意:

给定的列表可能包含重复元素，所以在这里升序表示 >= 。
1 <= k <= 3500
-105 <= 元素的值 <= 105
对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), minimum = INT_MAX, maximum = INT_MIN;
        unordered_map<int, vector<int>> numIndices;
        createNumIndicesTable(nums, k, numIndices, minimum, maximum);

        int* numsEachList = new int[k]();
        int left = minimum, right = left - 1, listsInWindow = 0;
        vector<int> shortestRange = {0, INT_MAX};

        while (++right <= maximum) {
            if (numIndices.find(right) == numIndices.end()) {
                continue;  // 遍历所有数的区间[minimum,maximum]，这个数没有出现过，直接跳过
            }

            for (int index : numIndices[right]) {
                numsEachList[index]++;  // 把这个数所有出现的序列的计数统计加1
                if (numsEachList[index] == 1) {  // 计数统计大于等于1说明窗口中包含了这个序列的数。由于要统计序列的个数，只比较等于1的情况
                    listsInWindow++;
                }
            }

            while (listsInWindow == k) {  // 当窗口内的序列等于k时，说明找到一个包含所有序列值的区间
                if (right - left < shortestRange[1] - shortestRange[0]) {
                    shortestRange[0] = left;
                    shortestRange[1] = right;
                }

                // 然后尝试增长左窗口，寻找最优解
                for (int index : numIndices[left]) {
                    numsEachList[index]--;  // 先把left所在list的计数都减1
                    if (numsEachList[index] == 0) {
                        listsInWindow--;
                    }
                }
                while ((++left <= maximum) && (numIndices.find(left) == numIndices.end())) {}  // 再把left跳到下一个数
            }
        }

        delete[] numsEachList;
        return shortestRange;
    }

    void createNumIndicesTable(vector<vector<int>>& nums, int k, unordered_map<int, vector<int>>& numIndices, int& minimum, int& maximum) {
        for (int i = 0; i < k; i++) {
            for (int num : nums[i]) {
                numIndices[num].push_back(i);  // 以序列中的数为key，这个数出现在哪些序列中为value构造hash表
                minimum = minimum < num ? minimum : num;
                maximum = maximum > num ? maximum : num;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> nums = { {4,10,15,24,26},{0,9,12,20},{5,18,22,30} };
    vector<int> actual = o.smallestRange(nums);
    vector<int> expected = { 20,24 };
    check.checkIntVector(expected, actual);

    nums = { {4,4,10,10,15,15,24,24,26,26},{0,0,9,9,12,12,20,20},{5,5,18,18,22,22,30,30} };
    actual = o.smallestRange(nums);
    expected = { 20,24 };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3},{1,2,3},{1,2,3} };
    actual = o.smallestRange(nums);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    nums = { {5} };
    actual = o.smallestRange(nums);
    expected = { 5,5 };
    check.checkIntVector(expected, actual);

    nums = { {-100000},{100000} };
    actual = o.smallestRange(nums);
    expected = { -100000,100000 };
    check.checkIntVector(expected, actual);

    nums = { {-5,-3},{3,5} };
    actual = o.smallestRange(nums);
    expected = { -3,3 };
    check.checkIntVector(expected, actual);

    nums = { {-5,-3},{-4} };
    actual = o.smallestRange(nums);
    expected = { -5,-4 };
    check.checkIntVector(expected, actual);

    nums = { {-5,-3},{3,5},{7,8} };
    actual = o.smallestRange(nums);
    expected = { -3,7 };
    check.checkIntVector(expected, actual);

    nums = { {-89,1,69,89,90,98},{-43,-36,-24,-14,49,61,66,69},{73,94,94,96},{11,13,76,79,90},{-40,-20,1,9,12,12,14},{-91,-31,0,21,25,26,28,29,29,30},
        {23,88,89},{31,42,42,57},{-2,6,11,12,12,13,15},{-3,25,34,36,39},{-7,3,29,29,31,32,33},{4,11,14,15,15,18,19},{-34,9,12,19,19,19,19,20},
        {-26,4,47,53,64,64,64,64,64,65},{-51,-25,36,38,50,54},{17,25,38,38,38,38,40},{-30,12,15,19,19,20,22},{-14,-13,-10,68,69,69,72,74,75},
        {-39,42,70,70,70,71,72,72,73},{-67,-34,6,26,28,28,28,28,29,30,31} };
    actual = o.smallestRange(nums);
    expected = { 13,73 };
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
