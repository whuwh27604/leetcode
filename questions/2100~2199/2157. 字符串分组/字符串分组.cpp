/* 字符串分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words 。每个字符串都只包含 小写英文字母 。words 中任意一个子串中，每个字母都至多只出现一次。

如果通过以下操作之一，我们可以从 s1 的字母集合得到 s2 的字母集合，那么我们称这两个字符串为 关联的 ：

往 s1 的字母集合中添加一个字母。
从 s1 的字母集合中删去一个字母。
将 s1 中的一个字母替换成另外任意一个字母（也可以替换为这个字母本身）。
数组 words 可以分为一个或者多个无交集的 组 。如果一个字符串与另一个字符串关联，那么它们应当属于同一个组。

注意，你需要确保分好组后，一个组内的任一字符串与其他组的字符串都不关联。可以证明在这个条件下，分组方案是唯一的。

请你返回一个长度为 2 的数组 ans ：

ans[0] 是 words 分组后的 总组数 。
ans[1] 是字符串数目最多的组所包含的字符串数目。
 

示例 1：

输入：words = ["a","b","ab","cde"]
输出：[2,3]
解释：
- words[0] 可以得到 words[1] （将 'a' 替换为 'b'）和 words[2] （添加 'b'）。所以 words[0] 与 words[1] 和 words[2] 关联。
- words[1] 可以得到 words[0] （将 'b' 替换为 'a'）和 words[2] （添加 'a'）。所以 words[1] 与 words[0] 和 words[2] 关联。
- words[2] 可以得到 words[0] （删去 'b'）和 words[1] （删去 'a'）。所以 words[2] 与 words[0] 和 words[1] 关联。
- words[3] 与 words 中其他字符串都不关联。
所以，words 可以分成 2 个组 ["a","b","ab"] 和 ["cde"] 。最大的组大小为 3 。
示例 2：

输入：words = ["a","ab","abc"]
输出：[1,3]
解释：
- words[0] 与 words[1] 关联。
- words[1] 与 words[0] 和 words[2] 关联。
- words[2] 与 words[1] 关联。
由于所有字符串与其他字符串都关联，所以它们全部在同一个组内。
所以最大的组大小为 3 。
 

提示：

1 <= words.length <= 2 * 104
1 <= words[i].length <= 26
words[i] 只包含小写英文字母。
words[i] 中每个字母最多只出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/groups-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

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

private:
    vector<int> parents;
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int size = words.size();
        unordered_map<int, int> numIndices;
        DSU dsu(size);

        assignIndex(words, numIndices, dsu);
        connect(numIndices, dsu);        

        return getTotalMaxGroup(size, dsu);
    }

    int word2Num(string& word) {
        int num = 0;

        for (char c : word) {
            num |= (1 << (c - 'a'));
        }

        return num;
    }

    void assignIndex(vector<string>& words, unordered_map<int, int>& numIndices, DSU& dsu) {
        int index = 0;

        for (string& word : words) {
            int num = word2Num(word);

            if (numIndices.count(num) == 0) {
                numIndices[num] = index++;
            }
            else {
                dsu.merge(numIndices[num], index++);  // 相同的word，放入同一个group
            }
        }
    }

    void connect(unordered_map<int, int>& numIndices, DSU& dsu) {
        for (auto& numIndex : numIndices) {
            int num = numIndex.first, index = numIndex.second, next;

            for (int bit = 1; bit < (1 << 26); bit <<= 1) {
                if ((num & bit) == 0) {
                    next = (num | bit);  // 往 s1 的字母集合中添加一个字母

                    if (numIndices.count(next) != 0) {
                        dsu.merge(index, numIndices[next]);
                    }
                }
            }

            for (int bit = 1; bit < (1 << 26); bit <<= 1) {
                if ((num & bit) != 0) {
                    next = (num ^ bit);  // 从 s1 的字母集合中删去一个字母

                    if (numIndices.count(next) != 0) {
                        dsu.merge(index, numIndices[next]);
                    }

                    for (int bit1 = 1; bit1 < (1 << 26); bit1 <<= 1) {
                        if (bit1 != bit && (next & bit1) == 0) {
                            int nnext = (next | bit1);  // 将 s1 中的一个字母替换成另外任意一个字母

                            if (numIndices.count(nnext) != 0) {
                                dsu.merge(index, numIndices[nnext]);
                            }
                        }
                    }
                }
            }
        }
    }

    vector<int> getTotalMaxGroup(int size, DSU& dsu) {
        vector<int> totalMaxGroup(2, 0);
        unordered_map<int, int> groups;

        for (int i = 0; i < size; ++i) {
            ++groups[dsu.find(i)];
        }

        totalMaxGroup[0] = groups.size();

        for (auto& groupSize : groups) {
            totalMaxGroup[1] = max(totalMaxGroup[1], groupSize.second);
        }

        return totalMaxGroup;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "a","b","ab","cde" };
    vector<int> actual = o.groupStrings(words);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    words = { "a","ab","abc" };
    actual = o.groupStrings(words);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    words = { "a","a" };
    actual = o.groupStrings(words);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    words = { "a","a","abc","abc" };
    actual = o.groupStrings(words);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    words = { "ghnv","uip","tenv","hvepx","e","ktc","byjdt","ulm","cae","ea" };
    actual = o.groupStrings(words);
    expected = { 8,3 };
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
