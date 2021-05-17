/* 找出和为指定值的下标对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2 ，请你实现一个支持下述两类查询的数据结构：

累加 ，将一个正整数加到 nums2 中指定下标对应元素上。
计数 ，统计满足 nums1[i] + nums2[j] 等于指定值的下标对 (i, j) 数目（0 <= i < nums1.length 且 0 <= j < nums2.length）。
实现 FindSumPairs 类：

FindSumPairs(int[] nums1, int[] nums2) 使用整数数组 nums1 和 nums2 初始化 FindSumPairs 对象。
void add(int index, int val) 将 val 加到 nums2[index] 上，即，执行 nums2[index] += val 。
int count(int tot) 返回满足 nums1[i] + nums2[j] == tot 的下标对 (i, j) 数目。
 

示例：

输入：
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
输出：
[null, 8, null, 2, 1, null, null, 11]

解释：
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // 返回 8 ; 下标对 (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) 满足 2 + 5 = 7 ，下标对 (5,1), (5,5) 满足 3 + 4 = 7
findSumPairs.add(3, 2); // 此时 nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // 返回 2 ；下标对 (5,2), (5,4) 满足 3 + 5 = 8
findSumPairs.count(4);  // 返回 1 ；下标对 (5,0) 满足 3 + 1 = 4
findSumPairs.add(0, 1); // 此时 nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // 此时 nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // 返回 11 ；下标对 (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) 满足 2 + 5 = 7 ，下标对 (5,3), (5,5) 满足 3 + 4 = 7
 

提示：

1 <= nums1.length <= 1000
1 <= nums2.length <= 105
1 <= nums1[i] <= 109
1 <= nums2[i] <= 105
0 <= index < nums2.length
1 <= val <= 105
1 <= tot <= 109
最多调用 add 和 count 函数各 1000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/finding-pairs-with-a-certain-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        numbers2 = nums2;

        for (int num : nums1) {
            ++nums1Count[num];
        }

        for (int num : nums2) {
            ++nums2Count[num];
        }
    }

    void add(int index, int val) {
        --nums2Count[numbers2[index]];
        numbers2[index] += val;
        ++nums2Count[numbers2[index]];
    }

    int count(int tot) {
        int pairs = 0;

        for (auto iter = nums1Count.begin(); iter != nums1Count.end(); ++iter) {
            int target = tot - iter->first;
            if (nums2Count.count(target) != 0) {
                pairs += (iter->second * nums2Count[target]);
            }
        }

        return pairs;
    }

private:
    unordered_map<int, int> nums1Count;
    unordered_map<int, int> nums2Count;
    vector<int> numbers2;
};

int main()
{
    CheckResult check;

    vector<int> nums1 = { 1, 1, 2, 2, 2, 3 };
    vector<int> nums2 = { 1, 4, 5, 2, 5, 4 };
    FindSumPairs o1(nums1, nums2);
    check.checkInt(8, o1.count(7));
    o1.add(3, 2);
    check.checkInt(2, o1.count(8));
    check.checkInt(1, o1.count(4));
    o1.add(0, 1);
    o1.add(1, 1);
    check.checkInt(11, o1.count(7));
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
