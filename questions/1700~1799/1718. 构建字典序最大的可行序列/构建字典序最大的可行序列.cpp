/* 构建字典序最大的可行序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，请你找到满足下面条件的一个序列：

整数 1 在序列中只出现一次。
2 到 n 之间每个整数都恰好出现两次。
对于每个 2 到 n 之间的整数 i ，两个 i 之间出现的距离恰好为 i 。
序列里面两个数 a[i] 和 a[j] 之间的 距离 ，我们定义为它们下标绝对值之差 |j - i| 。

请你返回满足上述条件中 字典序最大 的序列。题目保证在给定限制条件下，一定存在解。

一个序列 a 被认为比序列 b （两者长度相同）字典序更大的条件是： a 和 b 中第一个不一样的数字处，a 序列的数字比 b 序列的数字大。比方说，[0,1,9,0] 比 [0,1,5,6] 字典序更大，因为第一个不同的位置是第三个数字，且 9 比 5 大。

 

示例 1：

输入：n = 3
输出：[3,1,2,3,2]
解释：[2,3,2,1,3] 也是一个可行的序列，但是 [3,1,2,3,2] 是字典序最大的序列。
示例 2：

输入：n = 5
输出：[5,3,1,4,3,5,2,4,2]
 

提示：

1 <= n <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, 0);
        (void)DFS(0, (int)pow(2, n - 1), sequence, 0);

        return sequence;
    }

    bool DFS(int selected, int highestBit, vector<int>& sequence, int position) {
        int i, size = sequence.size(), nextPos;

        if (position == size) {
            return true;
        }

        for (i = highestBit; i != 0; i >>= 1) {
            if ((selected & i) != 0) {
                continue;
            }

            int num = (int)log2(i) + 1;  // 按从大到小的顺序选择num，那么第一个解就是字典序最大的
            if (num != 1 && (position + num >= size || sequence[position + num] != 0)) {
                continue;
            }

            selected |= i;
            sequence[position] = num;
            if (num != 1) {
                sequence[position + num] = num;
            }

            // 编码简单，只尝试第一个空位，如果无解则说明这个位置不该填num，回溯selected选择下一个num尝试
            for (nextPos = position + 1; nextPos < size && sequence[nextPos] != 0; ++nextPos) {}

            if (DFS(selected, highestBit, sequence, nextPos)) {
                return true;
            }

            selected &= ~i;
            sequence[position] = 0;
            if (num != 1) {
                sequence[position + num] = 0;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.constructDistancedSequence(3);
    vector<int> expected = { 3,1,2,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(2);
    expected = { 2,1,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(5);
    expected = { 5,3,1,4,3,5,2,4,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(6);
    expected = { 6,4,2,5,2,4,6,3,5,1,3 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(7);
    expected = { 7,5,3,6,4,3,5,7,4,6,2,1,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(8);
    expected = { 8,6,4,2,7,2,4,6,8,5,3,7,1,3,5 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(10);
    expected = { 10,8,6,9,3,1,7,3,6,8,10,5,9,7,4,2,5,2,4 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(15);
    expected = { 15,13,14,10,8,12,5,3,11,9,3,5,8,10,13,15,14,12,9,11,7,4,6,1,2,4,2,7,6 };
    check.checkIntVector(expected, actual);

    actual = o.constructDistancedSequence(20);
    expected = { 20,18,19,15,13,17,10,16,7,5,3,14,12,3,5,7,10,13,15,18,20,19,17,16,12,14,11,9,4,6,8,2,4,2,1,6,9,11,8 };
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
