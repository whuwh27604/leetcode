/* 带因子的二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个含有不重复整数元素的数组，每个整数均大于 1。

我们用这些整数来构建二叉树，每个整数可以使用任意次数。

其中：每个非叶结点的值应等于它的两个子结点的值的乘积。

满足条件的二叉树一共有多少个？返回的结果应模除 10 ** 9 + 7。

 

示例 1:

输入: A = [2, 4]
输出: 3
解释: 我们可以得到这些二叉树: [2], [4], [4, 2, 2]
示例 2:

输入: A = [2, 4, 5, 10]
输出: 7
解释: 我们可以得到这些二叉树: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

提示:

1 <= A.length <= 1000.
2 <= A[i] <= 10 ^ 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-trees-with-factors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int allTrees = 0, mod = 1000000007;
        unordered_map<int, vector<pair<int, int>>> parentChildren;
        unordered_map<int, int> memo;

        getAllParentChildren(A, parentChildren);

        for (int root : A) {
            allTrees = (allTrees + numFactoredBinaryTrees(root, parentChildren, memo)) % mod;
        }

        return allTrees;
    }

    int numFactoredBinaryTrees(int root, unordered_map<int, vector<pair<int, int>>>& parentChildren, unordered_map<int, int>& memo) {
        if (memo.count(root) != 0) {
            return memo[root];
        }

        int trees = 1, mod = 1000000007;

        if (parentChildren.count(root) != 0) {
            for (pair<int, int>& children : parentChildren[root]) {
                if (children.first == children.second) {
                    int child = numFactoredBinaryTrees(children.first, parentChildren, memo);
                    trees = (trees + (int)((long long)child * (long long)child % mod)) % mod;
                }
                else {
                    int left = numFactoredBinaryTrees(children.first, parentChildren, memo);
                    int right = numFactoredBinaryTrees(children.second, parentChildren, memo);
                    trees = (trees + (int)((long long)left * (long long)right * 2 % mod)) % mod;
                }
            }
        }

        memo[root] = trees;
        return trees;
    }

    void getAllParentChildren(vector<int>& A, unordered_map<int, vector<pair<int, int>>>& parentChildren) {
        unordered_set<long long> nums;
        int i, j, size = A.size();

        for (int num : A) {
            nums.insert(num);
        }

        for (i = 0; i < size; ++i) {
            for (j = i; j < size; ++j) {
                long long parent = (long long)A[i] * A[j];
                if (nums.count(parent) != 0) {
                    parentChildren[(int)parent].push_back({ A[i], A[j] });
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 2,3,6 };
    check.checkInt(5, o.numFactoredBinaryTrees(A));

    A = { 2,4 };
    check.checkInt(3, o.numFactoredBinaryTrees(A));

    A = { 2,4,5,10 };
    check.checkInt(7, o.numFactoredBinaryTrees(A));

    A = { 35,11,180,69300,6,2,385,5,36,7,3 };
    check.checkInt(344, o.numFactoredBinaryTrees(A));

    A = { 35,11,180,69300,6,2,385,5,36,7,3,693,100 };
    check.checkInt(348, o.numFactoredBinaryTrees(A));

    A = { 4 };
    check.checkInt(1, o.numFactoredBinaryTrees(A));

    A = { 2,17,34 };
    check.checkInt(5, o.numFactoredBinaryTrees(A));

    A = { 17,32,43,21,46,44,8,35,28,22,29,25,26,11,20,27,41,13,16,49,15,612,36,5,34,10,37,33,24,23,6,47,7,48,301,3,4,14,9,39,31,38,40,30,12,18,19,42,45,2 };
    check.checkInt(783, o.numFactoredBinaryTrees(A));

    A = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,301,612 };
    check.checkInt(783, o.numFactoredBinaryTrees(A));
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
