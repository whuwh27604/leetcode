/* 猜字谜.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）都不能作为谜底。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。

 

示例：

输入：
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
输出：[1,1,3,2,4,0]
解释：
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa"
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
 

提示：

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] 都是小写英文字母。
每个 puzzles[i] 所包含的字符都不重复。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> statesCount;
        getWordsStates(words, statesCount);

        vector<int> indices = { 1,2,3,4,5,6 };
        vector<vector<int>> subsets(64);
        getSubsets(indices, subsets);

        int i, size = puzzles.size();
        vector<int> validNums(size);

        for (i = 0; i < size; ++i) {
            validNums[i] = getValidNum(puzzles[i], subsets, statesCount);
        }

        return validNums;
    }

    void getWordsStates(vector<string>& words, unordered_map<int, int>& statesCount) {
        for (string& word : words) {
            ++statesCount[getState(word)];
        }
    }

    int getState(string& word) {
        int state = 0;

        for (char c : word) {
            state |= (1 << (c - 'a'));
        }

        return state;
    }

    int getValidNum(string& puzzle, vector<vector<int>>& subsets, unordered_map<int, int>& statesCount) {
        int validNum = 0;

        for (auto& subset : subsets) {
            int state = 1 << (puzzle[0] - 'a');

            for (int num : subset) {
                state |= (1 << (puzzle[num] - 'a'));
            }

            validNum += statesCount[state];
        }

        return validNum;
    }

    void getSubsets(vector<int>& indices, vector<vector<int>>& subsets) {
        for (int i = 1; i < 64; ++i) {
            int selected = i;
            int index = 0;

            while (selected != 0) {
                if ((selected & 1) == 1) {
                    subsets[i].push_back(indices[index]);
                }

                selected >>= 1;
                ++index;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "aaaa","asas","able","ability","actt","actor","access" };
    vector<string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
    vector<int> actual = o.findNumOfValidWords(words, puzzles);
    vector<int> expected = { 1,1,3,2,4,0 };
    check.checkIntVector(expected, actual);

    words = { "bbbb" };
    puzzles = { "aboveyz" };
    actual = o.findNumOfValidWords(words, puzzles);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    words = { "bbbb" };
    puzzles = { "baoveyz" };
    actual = o.findNumOfValidWords(words, puzzles);
    expected = { 1 };
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
