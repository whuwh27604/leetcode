/* 相似字符串组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。

例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。

总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。

给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。请问 strs 中有多少个相似字符串组？

 

示例 1：

输入：strs = ["tars","rats","arts","star"]
输出：2
示例 2：

输入：strs = ["omv","ovm"]
输出：1
 

提示：

1 <= strs.length <= 100
1 <= strs[i].length <= 1000
sum(strs[i].length) <= 2 * 104
strs[i] 只包含小写字母。
strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
 

备注：

      字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/similar-string-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        sets = size;
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
        int parentX = find(x), parentY = find(y);

        if (parentX != parentY) {
            parents[parentX] = parentY;
            --sets;
        }
    }

    int getSets() {
        return sets;
    }

private:
    vector<int> parents;
    int sets;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int i, j, size = strs.size();
        DSU dsu(size);

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (dsu.find(i) != dsu.find(j) && checkIfSmilar(strs[i], strs[j])) {
                    dsu.merge(i, j);
                }
            }
        }

        return dsu.getSets();
    }

    bool checkIfSmilar(string& word1, string& word2) {
        int i, size = word1.size(), diff = 0;

        for (i = 0; i < size; ++i) {
            if (word1[i] != word2[i] && ++diff > 2) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> strs = { "tars","rats","arts","star" };
    check.checkInt(2, o.numSimilarGroups(strs));

    strs = { "omv","ovm" };
    check.checkInt(1, o.numSimilarGroups(strs));

    strs = { "aaaaa" };
    check.checkInt(1, o.numSimilarGroups(strs));

    strs = { "abc","abc" };
    check.checkInt(1, o.numSimilarGroups(strs));

    strs = { "blw","bwl","wlb" };
    check.checkInt(1, o.numSimilarGroups(strs));

    strs = { "koqnn","knnqo","noqnk","nqkon" };
    check.checkInt(3, o.numSimilarGroups(strs));

    strs = { "kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs" };
    check.checkInt(5, o.numSimilarGroups(strs));
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
