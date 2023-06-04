/* 最大公约数遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，你可以在一些下标之间遍历。对于两个下标 i 和 j（i != j），当且仅当 gcd(nums[i], nums[j]) > 1 时，我们可以在两个下标之间通行，其中 gcd 是两个数的 最大公约数 。

你需要判断 nums 数组中 任意 两个满足 i < j 的下标 i 和 j ，是否存在若干次通行可以从 i 遍历到 j 。

如果任意满足条件的下标对都可以遍历，那么返回 true ，否则返回 false 。



示例 1：

输入：nums = [2,3,6]
输出：true
解释：这个例子中，总共有 3 个下标对：(0, 1) ，(0, 2) 和 (1, 2) 。
从下标 0 到下标 1 ，我们可以遍历 0 -> 2 -> 1 ，我们可以从下标 0 到 2 是因为 gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1 ，从下标 2 到 1 是因为 gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1 。
从下标 0 到下标 2 ，我们可以直接遍历，因为 gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1 。同理，我们也可以从下标 1 到 2 因为 gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1 。
示例 2：

输入：nums = [3,9,5]
输出：false
解释：我们没法从下标 0 到 2 ，所以返回 false 。
示例 3：

输入：nums = [4,3,12,8]
输出：true
解释：总共有 6 个下标对：(0, 1) ，(0, 2) ，(0, 3) ，(1, 2) ，(1, 3) 和 (2, 3) 。所有下标对之间都存在可行的遍历，所以返回 true 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 100000;
vector<vector<int>> factors(maxNum + 1);

void EratosthenesSieve() {
    vector<bool> isPrime(maxNum + 1, true);

    for (int i = 2; i <= maxNum; ++i) {
        if (isPrime[i]) {
            factors[i].push_back(i);

            for (int j = 2 * i; j <= maxNum; j += i) {
                isPrime[j] = false;
                factors[j].push_back(i);
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EratosthenesSieve();
    }
}

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

    int getSets() {
        int sets = 0, size = parents.size();

        for (int i = 0; i < size; ++i) {
            if (find(i) == i) {
                ++sets;
            }
        }

        return sets;
    }

private:
    vector<int> parents;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        init();
        int size = nums.size();
        DSU dsu(size);
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < size; ++i) {
            for (int factor : factors[nums[i]]) {
                groups[factor].push_back(i);
            }
        }

        for (auto& group : groups) {
            vector<int>& indices = group.second;
            for (int i = 1; i < (int)indices.size(); ++i) {
                dsu.merge(indices[0], indices[i]);
            }
        }

        return dsu.getSets() == 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,6 };
    check.checkBool(true, o.canTraverseAllPairs(nums));

    nums = { 4,3,12,8 };
    check.checkBool(true, o.canTraverseAllPairs(nums));

    nums = { 1 };
    check.checkBool(true, o.canTraverseAllPairs(nums));

    nums = { 3,9,5 };
    check.checkBool(false, o.canTraverseAllPairs(nums));

    nums = { 1,2,4 };
    check.checkBool(false, o.canTraverseAllPairs(nums));
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
