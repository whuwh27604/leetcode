/* 视频拼接.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你将会获得一系列视频片段，这些片段来自于一项持续时长为 T 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。

视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1] 结束。我们甚至可以对这些片段自由地再剪辑，例如片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。

我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, T]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。

 

示例 1：

输入：clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
输出：3
解释：
我们选中 [0,2], [8,10], [1,9] 这三个片段。
然后，按下面的方案重制比赛片段：
将 [1,9] 再剪辑为 [1,2] + [2,8] + [8,9] 。
现在我们手上有 [0,2] + [2,8] + [8,10]，而这些涵盖了整场比赛 [0, 10]。
示例 2：

输入：clips = [[0,1],[1,2]], T = 5
输出：-1
解释：
我们无法只用 [0,1] 和 [1,2] 覆盖 [0,5] 的整个过程。
示例 3：

输入：clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
输出：3
解释：
我们选取片段 [0,4], [4,7] 和 [6,9] 。
示例 4：

输入：clips = [[0,4],[2,8]], T = 5
输出：2
解释：
注意，你可能录制超过比赛结束时间的视频。
 

提示：

1 <= clips.length <= 100
0 <= clips[i][0] <= clips[i][1] <= 100
0 <= T <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/video-stitching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // 贪心算法，每次找和前一段有交集，结束时间最大的。使用最远可达数组加速，时间复杂度O(n)，n为最大时间值
        vector<int> maxTimeReachable(101, 0);

        for (vector<int>& clip : clips) {
            // maxTimeReachable[i]记录了从时间i出发，最远可到达的时间点。只用记录clips出现的时间点，其它没出现的不用管它
            maxTimeReachable[clip[0]] = max(maxTimeReachable[clip[0]], clip[1]);
        }

        int curMaxTime = 0, possibleMaxTime = 0, clipsNeed = 0;

        for (int time = 0; time < T; ++time) {
            possibleMaxTime = max(possibleMaxTime, maxTimeReachable[time]);
            if (possibleMaxTime >= T) {
                break;
            }

            if (time == curMaxTime) {  // 此时一段clip用完，需要下一段。而下一段clip能够到达的最大时间就是possibleMaxTime，把它记做curMaxTime
                ++clipsNeed;
                curMaxTime = possibleMaxTime;
            }

            if (time == possibleMaxTime) {  // 遍历到了最大时间，还是不能到达目标T，说明中断了
                return -1;
            }
        }

        return clipsNeed + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> clips = { {0,2},{3,6} };
    check.checkInt(-1, o.videoStitching(clips, 6));

    clips = { {0,3},{3,6} };
    check.checkInt(2, o.videoStitching(clips, 6));

    clips = { {0,6},{1,7},{0,9},{2,10},{0,4},{0,2},{10,10},{7,9},{0,3} };
    check.checkInt(-1, o.videoStitching(clips, 15));

    clips = { {0,2},{4,6},{8,10},{1,9},{1,5},{5,9} };
    check.checkInt(3, o.videoStitching(clips, 10));

    clips = { {0,1},{1,2} };
    check.checkInt(-1, o.videoStitching(clips, 5));

    clips = { {0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9} };
    check.checkInt(3, o.videoStitching(clips, 9));

    clips = { {0,4},{2,8} };
    check.checkInt(2, o.videoStitching(clips, 5));

    clips = { {0,1},{1,2},{2,3} };
    check.checkInt(3, o.videoStitching(clips, 3));
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
