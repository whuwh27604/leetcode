/* 活字印刷.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。

 

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：

输入："AAABBC"
输出：188
 

提示：

1 <= tiles.length <= 7
tiles 由大写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-tile-possibilities
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> tilesCount;
        countTiles(tiles, tilesCount);

        int count = -1;
        DFS(tilesCount, count);

        return count;
    }

    void countTiles(string& tiles, vector<int>& tilesCount) {
        char tilesTable[26] = { 0 };

        for (char c : tiles) {
            ++tilesTable[c - 'A'];
        }

        for (int i = 0; i < 26; ++i) {
            if (tilesTable[i] != 0) {
                tilesCount.push_back(tilesTable[i]);
            }
        }

        tilesCount.push_back(tiles.size());  // 最后一位保存还剩下多少个字符
    }

    void DFS(vector<int>& tilesCount, int& count) {
        ++count;

        if (tilesCount.back() == 0) {  // 所有字符已用完
            return;
        }

        int i, size = tilesCount.size() - 1;

        for (i = 0; i < size; ++i) {
            if (tilesCount[i] != 0) {
                --tilesCount[i];
                --tilesCount.back();
                DFS(tilesCount, count);  // 遍历所有可选的字符，重复的字符只选一次，因为两次选一样的字符出来的结果是一样的
                ++tilesCount[i];  // 回溯，把刚刚尝试的字符加回来，再尝试其它可能
                ++tilesCount.back();
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(8, o.numTilePossibilities("AAB"));
    check.checkInt(188, o.numTilePossibilities("AAABBC"));
    check.checkInt(1, o.numTilePossibilities("X"));
    check.checkInt(2, o.numTilePossibilities("XX"));
    check.checkInt(4, o.numTilePossibilities("XY"));
    check.checkInt(7, o.numTilePossibilities("XXXXXXX"));
    check.checkInt(13699, o.numTilePossibilities("CDEFGAB"));
    check.checkInt(649, o.numTilePossibilities("BBCCCDD"));
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
