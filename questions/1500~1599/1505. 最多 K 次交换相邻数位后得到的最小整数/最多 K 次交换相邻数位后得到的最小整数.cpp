/* 最多 K 次交换相邻数位后得到的最小整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 num 和一个整数 k 。其中，num 表示一个很大的整数，字符串中的每个字符依次对应整数上的各个 数位 。

你可以交换这个整数相邻数位的数字 最多 k 次。

请你返回你能得到的最小整数，并以字符串形式返回。

 

示例 1：



输入：num = "4321", k = 4
输出："1342"
解释：4321 通过 4 次交换相邻数位得到最小整数的步骤如上图所示。
示例 2：

输入：num = "100", k = 1
输出："010"
解释：输出可以包含前导 0 ，但输入保证不会有前导 0 。
示例 3：

输入：num = "36789", k = 1000
输出："36789"
解释：不需要做任何交换。
示例 4：

输入：num = "22", k = 22
输出："22"
示例 5：

输入：num = "9438957234785635408", k = 23
输出："0345989723478563548"
 

提示：

1 <= num.length <= 30000
num 只包含 数字 且不含有 前导 0 。
1 <= k <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

#include <iostream>
#include <queue>
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
    string minInteger(string num, int k) {
        int size = num.size();
        vector<queue<int>> indices(10);
        BIT bit(size);
        string ans;

        for (int i = 0; i < size; ++i) {
            indices[num[i] - '0'].push(i);
        }

        // 算法思路：贪心，每一次，找到num[0,k]范围内最小的数字，将它移入ans（注意因为前面已经处理掉一些数字，实际范围会比k大）。
        // 具体的，我们并不知道这个数字是什么，但它一定是[0,9]中的一个，所以从0到9尝试，第一个满足条件（index - 已处理个数 <= k）的数字就是当前要找的最小的。
        while (k != 0 && (int)ans.size() != size) {
            for (int i = 0; i < 10; ++i) {  // 从0到9遍历digit
                if (!indices[i].empty()) {
                    int index = indices[i].front();  // 第一个该digit的索引
                    int swaps = index - bit.query(index + 1);  // 将该digit交换到最前面需要的次数，等于它的索引减去前面已经移走的个数
                    if (swaps <= k) {  // 找到该digit可行
                        indices[i].pop();
                        ans.push_back(num[index]);
                        num[index] = 'X';
                        bit.update(index + 1, 1);  // 单点更新该位置已经被处理
                        k -= swaps;
                        break;
                    }
                }
            }
        }

        for (char c : num) {
            if (c != 'X') {
                ans.push_back(c);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("1342", o.minInteger("4321", 4));
    check.checkString("010", o.minInteger("100", 1));
    check.checkString("36789", o.minInteger("36789", 1000));
    check.checkString("22", o.minInteger("22", 22));
    check.checkString("0345989723478563548", o.minInteger("9438957234785635408", 23));
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
