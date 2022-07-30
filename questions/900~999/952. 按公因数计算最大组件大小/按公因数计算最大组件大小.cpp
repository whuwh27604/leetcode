/* 按公因数计算最大组件大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由不同正整数的组成的非空数组 nums ，考虑下面的图：

有 nums.length 个节点，按从 nums[0] 到 nums[nums.length - 1] 标记；
只有当 nums[i] 和 nums[j] 共用一个大于 1 的公因数时，nums[i] 和 nums[j]之间才有一条边。
返回 图中最大连通组件的大小 。

 

示例 1：



输入：nums = [4,6,15,35]
输出：4
示例 2：



输入：nums = [20,50,9,63]
输出：2
示例 3：



输入：nums = [2,3,6,7,4,12,21,39]
输出：8
 

提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 105
nums 中所有值都 不同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-component-size-by-common-factor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);
        sizes.resize(size, 1);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);  // 路径压缩，父节点设置为根节点
        }

        return parents[x];
    }

    void merge(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (parentX != parentY) {
            if (sizes[parentX] < sizes[parentY]) {
                swap(parentX, parentY);
            }

            parents[parentY] = parentX;  // 把小的集合合并到大的
            sizes[parentX] += sizes[parentY];
        }
    }

private:
    vector<int> parents;
    vector<int> sizes;
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        DSU dsu(maxNum + 1);

        merge(nums, dsu);
        
        return getMaxSize(maxNum, nums, dsu);
    }

    void merge(vector<int>& nums, DSU& dsu) {
        for (int num : nums) {
            for (int factor = 2; factor * factor <= num; ++factor) {
                if (num % factor == 0) {
                    dsu.merge(num, factor);
                    dsu.merge(num, num / factor);
                }
            }
        }
    }

    int getMaxSize(int maxNum, vector<int>& nums, DSU& dsu) {
        int maxSize = 0;
        vector<int> count(maxNum + 1, 0);

        for (int num : nums) {
            int root = dsu.find(num);
            maxSize = max(maxSize, ++count[root]);
        }

        return maxSize;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,6,15,35 };
    check.checkInt(4, o.largestComponentSize(nums));

    nums = { 20,50,9,63 };
    check.checkInt(2, o.largestComponentSize(nums));

    nums = { 2,3,6,7,4,12,21,39 };
    check.checkInt(8, o.largestComponentSize(nums));

    nums = { 1,2,3,4,5,6,7,8,9 };
    check.checkInt(6, o.largestComponentSize(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
    check.checkInt(14, o.largestComponentSize(nums));

    nums = getIntVector("./testcase1.txt");
    check.checkInt(2370, o.largestComponentSize(nums));
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
