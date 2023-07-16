/* 戳印序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你想要用小写字母组成一个目标字符串 target。

开始的时候，序列由 target.length 个 '?' 记号组成。而你有一个小写字母印章 stamp。

在每个回合，你可以将印章放在序列上，并将序列中的每个字母替换为印章上的相应字母。你最多可以进行 10 * target.length  个回合。

举个例子，如果初始序列为 "?????"，而你的印章 stamp 是 "abc"，那么在第一回合，你可以得到 "abc??"、"?abc?"、"??abc"。（请注意，印章必须完全包含在序列的边界内才能盖下去。）

如果可以印出序列，那么返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成。如果不能印出序列，就返回一个空数组。

例如，如果序列是 "ababc"，印章是 "abc"，那么我们就可以返回与操作 "?????" -> "abc??" -> "ababc" 相对应的答案 [0, 2]；

另外，如果可以印出序列，那么需要保证可以在 10 * target.length 个回合内完成。任何超过此数字的答案将不被接受。



示例 1：

输入：stamp = "abc", target = "ababc"
输出：[0,2]
（[1,0,2] 以及其他一些可能的结果也将作为答案被接受）
示例 2：

输入：stamp = "abca", target = "aabcaca"
输出：[3,0,1]


提示：

1 <= stamp.length <= target.length <= 1000
stamp 和 target 只包含小写字母。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int sizeS = stamp.size(), sizeT = target.size(), sizeW = sizeT - sizeS + 1;
        vector<unordered_set<int>> windows(sizeW);
        queue<int> indices;
        unordered_set<int> changed;
        vector<int> ans;

        for (int i = 0; i < sizeW; ++i) {
            init(i, sizeS, stamp, target, windows);

            if (windows[i].empty()) {
                doStamp(i, sizeS, sizeT, stamp, indices, changed, ans);
            }
        }

        while (!indices.empty()) {
            int index = indices.front();
            indices.pop();

            checkWindow(index, sizeS, sizeT, stamp, indices, changed, windows, ans);
        }

        if (changed.size() == sizeT) {
            reverse(ans.begin(), ans.end());

            return ans;
        }

        return {};
    }

    void init(int index, int sizeS, string& stamp, string& target, vector<unordered_set<int>>& windows) {
        for (int i = 0; i < sizeS; ++i) {
            if (stamp[i] != target[index + i]) {
                windows[index].insert(index + i);
            }
        }
    }

    void doStamp(int index, int sizeS, int sizeT, string& stamp, queue<int>& indices, unordered_set<int>& changed, vector<int>& ans) {
        if (changed.size() == sizeT) {
            return;
        }

        ans.push_back(index);

        for (int i = index; i < index + sizeS; ++i) {
            if (changed.count(i) == 0) {
                changed.insert(i);
                indices.push(i);
            }
        }
    }

    void checkWindow(int index, int sizeS, int sizeT, string& stamp, queue<int>& indices, unordered_set<int>& changed, vector<unordered_set<int>>& windows, vector<int>& ans) {
        int low = max(0, index - sizeS + 1), high = min(index, sizeT - sizeS);

        for (int i = low; i <= high; ++i) {
            if (windows[i].count(index) != 0) {
                windows[i].erase(index);
                if (windows[i].empty()) {
                    doStamp(i, sizeS, sizeT, stamp, indices, changed, ans);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.movesToStamp("abc", "ababc");
    vector<int> expected = { 0,2 };
    check.checkIntVector(expected, actual);

    actual = o.movesToStamp("abca", "aabcaca");
    expected = { 3,0,1 };
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
