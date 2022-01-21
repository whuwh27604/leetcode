/* 跳跃游戏 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。

 

示例 1：

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
示例 2：

输入：arr = [7]
输出：0
解释：一开始就在最后一个元素处，所以你不需要跳跃。
示例 3：

输入：arr = [7,6,9,6,9,6,9,7]
输出：1
解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
示例 4：

输入：arr = [6,1,9]
输出：2
示例 5：

输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
输出：3
 

提示：

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int i, size = arr.size(), jumps = -1;
        unordered_map<int, vector<int>> numIndices;
        queue<int> bfs;
        vector<bool> visited(size, false);

        for (i = 0; i < size; ++i) {
            numIndices[arr[i]].push_back(i);
        }

        bfs.push(0);
        visited[0] = true;

        while (!bfs.empty()) {
            int count = bfs.size();
            ++jumps;

            for (i = 0; i < count; ++i) {
                int index = bfs.front(), num = arr[index];
                bfs.pop();

                if (index == size - 1) {
                    return jumps;
                }

                for (int idx : numIndices[num]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        bfs.push(idx);
                    }
                }

                numIndices[num].clear();  // 避免重复操作

                if (index != 0 && !visited[index - 1]) {
                    visited[index - 1] = true;
                    bfs.push(index - 1);
                }

                if (index != size - 1 && !visited[index + 1]) {
                    visited[index + 1] = true;
                    bfs.push(index + 1);
                }
            }
        }

        return jumps;  // 一定有解，不会走到这里
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 100,-23,-23,404,100,23,23,23,3,404 };
    check.checkInt(3, o.minJumps(arr));

    arr = { 7 };
    check.checkInt(0, o.minJumps(arr));

    arr = { 7,6,9,6,9,6,9,7 };
    check.checkInt(1, o.minJumps(arr));

    arr = { 6,1,9 };
    check.checkInt(2, o.minJumps(arr));

    arr = { 11,22,7,7,7,7,7,7,7,22,13 };
    check.checkInt(3, o.minJumps(arr));

    arr = { 100, 100, 100,100,100,100,1,2,3 };
    check.checkInt(4, o.minJumps(arr));

    arr = { 51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63 };
    check.checkInt(4, o.minJumps(arr));
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
