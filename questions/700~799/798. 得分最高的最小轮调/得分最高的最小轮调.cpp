/* 得分最高的最小轮调.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组 A，我们可以将它按一个非负整数 K 进行轮调，这样可以使数组变为 A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], A[1], ..., A[K-1] 的形式。此后，任何值小于或等于其索引的项都可以记作一分。

例如，如果数组为 [2, 4, 1, 3, 0]，我们按 K = 2 进行轮调后，它将变成 [1, 3, 0, 2, 4]。这将记作 3 分，因为 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point]。

在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调索引 K。如果有多个答案，返回满足条件的最小的索引 K。

 

示例 1：

输入：[2, 3, 1, 4, 0]
输出：3
解释：
下面列出了每个 K 的得分：
K = 0,  A = [2,3,1,4,0],    score 2
K = 1,  A = [3,1,4,0,2],    score 3
K = 2,  A = [1,4,0,2,3],    score 3
K = 3,  A = [4,0,2,3,1],    score 4
K = 4,  A = [0,2,3,1,4],    score 3
所以我们应当选择 K = 3，得分最高。
示例 2：

输入：[1, 3, 0, 2, 4]
输出：0
解释：
A 无论怎么变化总是有 3 分。
所以我们将选择最小的 K，即 0。
 

提示：

A 的长度最大为 20000。
A[i] 的取值范围是 [0, A.length]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-rotation-with-highest-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& A) {
        int i, size = A.size(), sum = 0, maxScore = 0, maxScoreRotation = 0;
        vector<int> diff(size + 1, 0);

        for (i = 0; i < size; ++i) {
            int num = A[i];

            if (i < num) {  // 对于数字num来说，index为[num,size-1]时，可以获得积分。当前index<num，需要把它移到[num,size-1]区间
                diff[i + 1] += 1;  // 移动到size-1位置需要i+1次移动
                diff[size - num + i + 1] -= 1;  // 移动到num位置需要size - num + i次移动，再继续移动将不能获得积分
            }
            else {
                diff[0] += 1;  // 移动[0,i-num]次可以获得积分
                diff[i - num + 1] -= 1;
                diff[i + 1] += 1;  // 移动到i后面都可以获得积分
            }
        }

        for (i = 0; i < size; ++i) {
            sum += diff[i];
            if (sum > maxScore) {
                maxScore = sum;
                maxScoreRotation = i;
            }
        }

        return maxScoreRotation;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 2,3,1,4,0 };
    check.checkInt(3, o.bestRotation(A));

    A = { 1,3,0,2,4 };
    check.checkInt(0, o.bestRotation(A));

    A = { 0 };
    check.checkInt(0, o.bestRotation(A));

    A = { 1 };
    check.checkInt(0, o.bestRotation(A));
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
