/* 统计作战单位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。

每 3 个士兵可以组成一个作战单位，分组规则如下：

从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n
请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。

 

示例 1：

输入：rating = [2,5,3,4,1]
输出：3
解释：我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
示例 2：

输入：rating = [2,1,3]
输出：0
解释：根据题目条件，我们无法组建作战单位。
示例 3：

输入：rating = [1,2,3,4]
输出：4
 

提示：

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-teams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        unordered_map<int, int> indices;
        discretization(rating, indices);

        int size = rating.size(), teams = 0;
        BIT bitLess(size), bitGreater(size);

        for (int num : rating) {
            int index = indices[num];
            int less = bitLess.query(index);  // 在num前面比num小的数的个数
            int greater = bitGreater.query(size + 1 - index);  // 在num前面比num大的数的个数
            teams += (less * (size - index - greater) + greater * (index - 1 - less));  // 前面小*后面大+前面大*后面小
            bitLess.update(index, 1);
            bitGreater.update(size + 1 - index, 1);
        }

        return teams;
    }

    void discretization(vector<int>& rating, unordered_map<int, int>& indices) {
        vector<int> tmp = rating;
        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < (int)tmp.size(); ++i) {
            indices[tmp[i]] = i + 1;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rating = { 2,5,3,4,1 };
    check.checkInt(3, o.numTeams(rating));

    rating = { 2,1,3 };
    check.checkInt(0, o.numTeams(rating));

    rating = { 1,2,3,4 };
    check.checkInt(4, o.numTeams(rating));

    rating = { 4 };
    check.checkInt(0, o.numTeams(rating));

    rating = { 2,4 };
    check.checkInt(0, o.numTeams(rating));

    rating = { 1,2,4 };
    check.checkInt(1, o.numTeams(rating));

    rating = { 100,90,110,109,91,92,108,107,93,94,106,105,95,96,104,103,97,98,102,101,99 };
    check.checkInt(525, o.numTeams(rating));
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
