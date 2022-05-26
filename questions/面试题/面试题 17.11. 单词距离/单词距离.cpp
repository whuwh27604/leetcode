/* 单词距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1
提示：

words.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-closest-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int i, size = words.size(), minDistance = INT_MAX, index1 = -1000000000, index2 = -1000000000;

        for (i = 0; i < size; ++i) {
            if (words[i] == word1) {
                index1 = i;
                minDistance = min(minDistance, index1 - index2);
            }
            else if (words[i] == word2) {
                index2 = i;
                minDistance = min(minDistance, index2 - index1);
            }
        }

        return minDistance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "I","am","a","student","from","a","university","in","a","city" };
    check.checkInt(1, o.findClosest(words, "a", "student"));
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
