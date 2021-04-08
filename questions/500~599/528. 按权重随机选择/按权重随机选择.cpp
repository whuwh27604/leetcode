/* 按权重随机选择.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。

 

示例 1：

输入：
["Solution","pickIndex"]
[[[1]],[]]
输出：
[null,0]
解释：
Solution solution = new Solution([1]);
solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。
示例 2：

输入：
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
输出：
[null,1,1,1,1,0]
解释：
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。

由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
诸若此类。
 

提示：

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex 将被调用不超过 10000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-with-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        int i, size = w.size();

        sum = 0;
        presum.resize(size);
        presum[0] = 0;

        for (i = 0; i < size - 1; ++i) {
            sum += w[i];
            presum[i + 1] = sum;
        }

        sum += w[i];
    }

    int pickIndex() {
        int rnum = rd() % sum;
        auto iter = upper_bound(presum.begin(), presum.end(), rnum);
        return distance(presum.begin(), --iter);
    }

private:
    random_device rd;
    vector<int> presum;
    int sum;
};

int main()
{
    CheckResult check;

    vector<int> w = { 1 };
    Solution o1(w);
    check.checkInt(0, o1.pickIndex());
    check.checkInt(0, o1.pickIndex());

    w = { 1,3 };
    Solution o2(w);
    for (int i = 0; i < 20; ++i) {
        cout << o2.pickIndex() << " ";
    }
    cout << endl;

    w = { 1,3,2,4,5 };
    Solution o3(w);
    for (int i = 0; i < 50; ++i) {
        cout << o3.pickIndex() << " ";
    }
    cout << endl;
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
