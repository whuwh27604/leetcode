/* 毯子覆盖的最多白色砖块数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 tiles ，其中 tiles[i] = [li, ri] ，表示所有在 li <= j <= ri 之间的每个瓷砖位置 j 都被涂成了白色。

同时给你一个整数 carpetLen ，表示可以放在 任何位置 的一块毯子。

请你返回使用这块毯子，最多 可以盖住多少块瓷砖。

 

示例 1：



输入：tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
输出：9
解释：将毯子从瓷砖 10 开始放置。
总共覆盖 9 块瓷砖，所以返回 9 。
注意可能有其他方案也可以覆盖 9 块瓷砖。
可以看出，瓷砖无法覆盖超过 9 块瓷砖。
示例 2：



输入：tiles = [[10,11],[1,1]], carpetLen = 2
输出：2
解释：将毯子从瓷砖 10 开始放置。
总共覆盖 2 块瓷砖，所以我们返回 2 。
 

提示：

1 <= tiles.length <= 5 * 104
tiles[i].length == 2
1 <= li <= ri <= 109
1 <= carpetLen <= 109
tiles 互相 不会重叠 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int left, right = 0, size = tiles.size();
        int whites = 0, maxWhites = 0;

        sort(tiles.begin(), tiles.end());
        tiles.push_back({ INT_MAX - 1, INT_MAX - 1 });

        for (left = 0; left < size; ++left) {
            while (tiles[right + 1][0] - tiles[left][0] <= carpetLen) {
                whites += (tiles[right][1] - tiles[right][0] + 1);
                ++right;
            }

            if (tiles[right][1] - tiles[left][0] + 1 > carpetLen) {
                maxWhites = max(maxWhites, whites + carpetLen - tiles[right][0] + tiles[left][0]);
            }
            else {
                maxWhites = max(maxWhites, whites + tiles[right][1] - tiles[right][0] + 1);
            }

            whites -= (tiles[left][1] - tiles[left][0] + 1);
        }

        return maxWhites;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}};
    check.checkInt(9,o.maximumWhiteTiles(tiles,10));

    tiles = {{10,11},{1,1}};
    check.checkInt(2,o.maximumWhiteTiles(tiles,2));

    tiles = {{8051,8057},{8074,8089},{7994,7995},{7969,7987},{8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};
    check.checkInt(126,o.maximumWhiteTiles(tiles,9854));

    tiles = {{5802,5819},{5512,5532},{5749,5749},{5538,5555},{5771,5777},{5856,5873},{5778,5794},{5570,5589},{5751,5763},{5649,5658},{5605,5608},{5641,5641},{5837,5841},{5699,5712},{5485,5487},{5724,5735},{5620,5638},{5493,5494},{5677,5682}};
    check.checkInt(209,o.maximumWhiteTiles(tiles,2327));

    tiles = {{1,1000000000}};
    check.checkInt(1000000000, o.maximumWhiteTiles(tiles, 1000000000));
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
