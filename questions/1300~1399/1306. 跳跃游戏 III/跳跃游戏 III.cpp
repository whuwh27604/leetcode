/* 跳跃游戏 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

 

示例 1：

输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 5 -> 下标 4 -> 下标 1 -> 下标 3
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3
示例 2：

输入：arr = [4,2,3,0,3,1,2], start = 0
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 0 -> 下标 4 -> 下标 1 -> 下标 3
示例 3：

输入：arr = [3,0,2,1,2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。
 

提示：

1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<bool> visited(size, false);
        visited[start] = true;

        queue<int> bfs;
        bfs.push(start);

        while (!bfs.empty()) {
            int index = bfs.front();
            bfs.pop();

            int num = arr[index];
            if (num == 0) {
                return true;
            }

            int next = index + num;
            if (next < size && !visited[next]) {
                visited[next] = true;
                bfs.push(next);
            }

            next = index - num;
            if (next >= 0 && !visited[next]) {
                visited[next] = true;
                bfs.push(next);
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 4,2,3,0,3,1,2 };
    check.checkBool(true, o.canReach(arr, 5));

    arr = { 4,2,3,0,3,1,2 };
    check.checkBool(true, o.canReach(arr, 0));

    arr = { 3,0,2,1,2 };
    check.checkBool(false, o.canReach(arr, 2));

    arr = { 0 };
    check.checkBool(true, o.canReach(arr, 0));

    arr = { 1,1,1 };
    check.checkBool(false, o.canReach(arr, 0));

    arr = { 0,3,0,6,3,3,4 };
    check.checkBool(true, o.canReach(arr, 6));
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
