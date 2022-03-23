/* 由单个字符重复的最长子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s 。另给你一个下标从 0 开始、长度为 k 的字符串 queryCharacters ，一个下标从 0 开始、长度也是 k 的整数 下标 数组 queryIndices ，这两个都用来描述 k 个查询。

第 i 个查询会将 s 中位于下标 queryIndices[i] 的字符更新为 queryCharacters[i] 。

返回一个长度为 k 的数组 lengths ，其中 lengths[i] 是在执行第 i 个查询 之后 s 中仅由 单个字符重复 组成的 最长子字符串 的 长度 。

 

示例 1：

输入：s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
输出：[3,3,4]
解释：
- 第 1 次查询更新后 s = "bbbacc" 。由单个字符重复组成的最长子字符串是 "bbb" ，长度为 3 。
- 第 2 次查询更新后 s = "bbbccc" 。由单个字符重复组成的最长子字符串是 "bbb" 或 "ccc"，长度为 3 。
- 第 3 次查询更新后 s = "bbbbcc" 。由单个字符重复组成的最长子字符串是 "bbbb" ，长度为 4 。
因此，返回 [3,3,4] 。
示例 2：

输入：s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
输出：[2,3]
解释：
- 第 1 次查询更新后 s = "abazz" 。由单个字符重复组成的最长子字符串是 "zz" ，长度为 2 。
- 第 2 次查询更新后 s = "aaazz" 。由单个字符重复组成的最长子字符串是 "aaa" ，长度为 3 。
因此，返回 [2,3] 。
 

提示：

1 <= s.length <= 105
s 由小写英文字母组成
k == queryCharacters.length == queryIndices.length
1 <= k <= 105
queryCharacters 由小写英文字母组成
0 <= queryIndices[i] < s.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-of-one-repeating-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Segment {
public:
    int start;
    int end;
    int len;
    char c;

    Segment() : start(0), end(0), len(0), c('a') {}
    Segment(int s_, int e_, char c_) : start(s_), end(e_), len(e_ - s_ + 1), c(c_) {}

    bool operator<(const Segment& o) const {
        return start < o.start;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int i, k = queryCharacters.size();
        set<Segment> segments;
        map<int, int> lens;
        vector<int> ans(k);

        init(s, segments, lens);

        for (i = 0; i < k; ++i) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            if (c != s[index]) {
                update(index, c, segments, lens);
            }

            s[index] = c;
            ans[i] = (--lens.end())->first;
        }

        return ans;
    }

    void init(string& s, set<Segment>& segments, map<int, int>& lens) {
        s.push_back('Z');
        int i, size = s.size(), start = 0, len = 1;

        for (i = 1; i < size; ++i) {
            if (s[i] == s[i - 1]) {
                ++len;
            }
            else {
                segments.insert(Segment(start, i - 1, s[i - 1]));
                ++lens[i - start];
                start = i;
                len = 1;
            }
        }
    }

    void update(int index, char c, set<Segment>& segments, map<int, int>& lens) {
        auto next = segments.upper_bound(Segment(index, 0, 0));
        auto current = next;
        --current;
        Segment segment(index, index, c);

        if (index == current->start && current != segments.begin()) {  // 改变第一个，尝试和前一段合并
            auto prev = current;
            --prev;

            if (prev->c == c) {  // 和前一段是相同字符，合并
                if (--lens[prev->len] == 0) {
                    lens.erase(prev->len);
                }

                segment.start = prev->start;
                segment.len += prev->len;
                segments.erase(prev);
            }
        }

        if (index == current->end && next != segments.end() && next->c == c) {  // 改变最后一个，合并下一段
            if (--lens[next->len] == 0) {
                lens.erase(next->len);
            }

            segment.end = next->end;
            segment.len += next->len;
            segments.erase(next);
        }

        Segment tmp = *current;  // 删除current节点
        segments.erase(current);

        if (--lens[tmp.len] == 0) {
            lens.erase(tmp.len);
        }

        if (index != tmp.start) {  // 不是改变第一个，那么current的前半部分会保留下来
            Segment newSeg(tmp.start, index - 1, tmp.c);
            segments.insert(newSeg);
            ++lens[newSeg.len];
        }

        if (index != tmp.end) {  // 不是改变最后一个，那么current的后半部分会保留下来
            Segment newSeg(index + 1, tmp.end, tmp.c);
            segments.insert(newSeg);
            ++lens[newSeg.len];
        }

        segments.insert(segment);  // 加入新的current节点
        ++lens[segment.len];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> queryIndices = { 1,3,3 };
    vector<int> actual = o.longestRepeating("babacc", "bcb", queryIndices);
    vector<int> expected = { 3,3,4 };
    check.checkIntVector(expected, actual);

    queryIndices = { 2,1 };
    actual = o.longestRepeating("abyzz", "aa", queryIndices);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    queryIndices = { 0 };
    actual = o.longestRepeating("z", "z", queryIndices);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    queryIndices = { 0 };
    actual = o.longestRepeating("z", "a", queryIndices);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    queryIndices = { 0 };
    actual = o.longestRepeating("zx", "x", queryIndices);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    queryIndices = { 1 };
    actual = o.longestRepeating("zx", "z", queryIndices);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    queryIndices = { 1 };
    actual = o.longestRepeating("zzz", "x", queryIndices);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    queryIndices = { 2 };
    actual = o.longestRepeating("zzxzzz", "z", queryIndices);
    expected = { 6 };
    check.checkIntVector(expected, actual);

    queryIndices = { 21,25,19,4,22,17,23,20,21,9,5,17,23,11,23,21,5,14,4,25,22,13,0,18,1,3,3,7,20,18,12,21,9,14,15,0,18,13,3,7,10,10,17,15,13,11,25,3,11,4,14,23,12,4,20,9,1,11,19,10,9,20,15,15,7,12,1,1,17,10,17,19,5,15,3 };
    actual = o.longestRepeating("feivczcpziqukyekqztimsymzx", "kzngqbdcgimfqzpbdyrkbccyhoplvbamsoklatfhjxyvmpvdtuakjhqpluvkdytraryhbfrkvtl", queryIndices);
    expected = { 1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1 };
    check.checkIntVector(expected, actual);

    queryIndices = { 1,5,5,2,1,15,12,0,13,5,9,3,2,1,13,7,19,21,18,19,16,9,0,2,18,8,9,10,12,10,8,5,13,2,14,0,9,3,21,0,14,5,9,16,16,5,19,8,15,10,19,15 };
    actual = o.longestRepeating("lptxlmmlcvfihnsulmomex", "tsqhthtruwlmbsoyyvjrhutjjwgbobkqbvihtspheychbtrbcxal", queryIndices);
    expected = { 2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1 };
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
