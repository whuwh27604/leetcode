/* 移除盒子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一些不同颜色的盒子 boxes ，盒子的颜色由不同的正数表示。

你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k * k 个积分。

返回 你能获得的最大积分和 。

 

示例 1：

输入：boxes = [1,3,2,2,2,3,4,3,1]
输出：23
解释：
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 分)
----> [1, 3, 3, 3, 1] (1*1=1 分)
----> [1, 1] (3*3=9 分)
----> [] (2*2=4 分)
示例 2：

输入：boxes = [1,1,1]
输出：9
示例 3：

输入：boxes = [1]
输出：1
 

提示：

1 <= boxes.length <= 100
1 <= boxes[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-boxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<int> leftLastIndices(n);  // 索引i左边最后一个和boxes[i]相等的索引
        // memo[left][right][sameCnt]表示区间[left,right]，假设在right后面，有连续sameCnt个boxes[right]的情况下，可以取得的最大分数
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

        getLeftLast(n, boxes, leftLastIndices);

        return getMaxScore(boxes, memo, leftLastIndices, 0, n - 1, 0);
    }

    void getLeftLast(int n, vector<int>& boxes, vector<int>& leftLastIndices) {
        vector<int> numIndices(101, -1);

        for (int i = 0; i < n; ++i) {
            leftLastIndices[i] = numIndices[boxes[i]];
            numIndices[boxes[i]] = i;
        }
    }

    int getMaxScore(vector<int>& boxes, vector<vector<vector<int>>>& memo, vector<int>& leftLastIndices, int left, int right, int sameCnt) {
        if (left > right) {
            return 0;
        }

        if (memo[left][right][sameCnt] != -1) {
            return memo[left][right][sameCnt];
        }

        int& maxScore = memo[left][right][sameCnt];
        int num = boxes[right];

        for (; right >= left && boxes[right] == num; --right, ++sameCnt) {}  // 连续的num

        // 直接消除最后sameCnt个盒子，剩下区间[left, right]，此时boxes[right] != num，所以sameCnt = 0
        maxScore = sameCnt * sameCnt + getMaxScore(boxes, memo, leftLastIndices, left, right, 0);
        int prev = leftLastIndices[right + 1];

        while (prev >= left) {  // 先消除区间[prev + 1, right]，让prev和right + 1位置的num连起来，再消除区间[left, prev]，此时prev后面有sameCnt个num
            maxScore = max(maxScore, getMaxScore(boxes, memo, leftLastIndices, prev + 1, right, 0) + getMaxScore(boxes, memo, leftLastIndices, left, prev, sameCnt));
            prev = leftLastIndices[prev];
        }

        return maxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> boxes = { 1,3,2,2,2,3,4,3,1 };
    check.checkInt(23, o.removeBoxes(boxes));

    boxes = { 1,1,1 };
    check.checkInt(9, o.removeBoxes(boxes));

    boxes = { 1 };
    check.checkInt(1, o.removeBoxes(boxes));

    boxes = { 1,2,2,1,2,1 };
    check.checkInt(14, o.removeBoxes(boxes));

    boxes = { 1,3,2,2,2,1,3,4,3,1,1 };
    check.checkInt(31, o.removeBoxes(boxes));

    boxes = { 4,6,8,4,8,8,6,4 };
    check.checkInt(18, o.removeBoxes(boxes));

    boxes = { 9,5,3,5,3,3,9,8,8,5,3,9 };
    check.checkInt(28, o.removeBoxes(boxes));

    boxes = { 1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1 };
    check.checkInt(2758, o.removeBoxes(boxes));

    boxes = { 1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1 };
    check.checkInt(8290, o.removeBoxes(boxes));

    boxes = { 1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1 };
    check.checkInt(724, o.removeBoxes(boxes));
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
