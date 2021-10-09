/* 考试的最大困扰度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

 

示例 1：

输入：answerKey = "TTFF", k = 2
输出：4
解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
总共有四个连续的 'T' 。
示例 2：

输入：answerKey = "TFFT", k = 1
输出：3
解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
两种情况下，都有三个连续的 'F' 。
示例 3：

输入：answerKey = "TTFTTFTT", k = 1
输出：5
解释：我们可以将第一个 'F' 换成 'T' ，得到 answerKey = "TTTTTFTT" 。
或者我们可以将第二个 'F' 换成 'T' ，得到 answerKey = "TTFTTTTT" 。
两种情况下，都有五个连续的 'T' 。
 

提示：

n == answerKey.length
1 <= n <= 5 * 104
answerKey[i] 要么是 'T' ，要么是 'F'
1 <= k <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveAnswers(answerKey, k + 1, 'T'), maxConsecutiveAnswers(answerKey, k + 1, 'F'));
    }

    int maxConsecutiveAnswers(string answerKey, int window, char change) {
        int left = -1, right = 0, size = answerKey.size(), count = 0, maxConsecutive = 0;

        for (right = 0; right < size; ++right) {
            if (answerKey[right] == change) {
                if (++count >= window) {
                    maxConsecutive = max(maxConsecutive, right - left - 1);
                    for (left += 1; answerKey[left] != change; ++left);
                }
            }
        }

        return max(maxConsecutive, right - left - 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.maxConsecutiveAnswers("TTFF", 2));
    check.checkInt(3, o.maxConsecutiveAnswers("TFFT", 1));
    check.checkInt(5, o.maxConsecutiveAnswers("TTFTTFTT", 1));
    check.checkInt(1, o.maxConsecutiveAnswers("T", 1));
    check.checkInt(34, o.maxConsecutiveAnswers("TFFTFFTFTFTFTTTTTTTTTTTTFTFTFTFTFTFFFFFFFFFTFTFTTFFTFTFTFTTTTTTTTTTTTTTFTFFTFTFTFTFTTFTFTFTFTFTFTTF", 10));
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
