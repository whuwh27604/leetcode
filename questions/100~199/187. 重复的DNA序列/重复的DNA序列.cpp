/* 重复的DNA序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

 

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
 

提示：

0 <= s.length <= 105
s[i] 为 'A'、'C'、'G' 或 'T'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-dna-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> sequences;
        vector<string> repeatedSequences;
        char letter2Num['T' + 1];
        letter2Num['A'] = 0;
        letter2Num['C'] = 1;
        letter2Num['G'] = 2;
        letter2Num['T'] = 3;
        int i, size = s.size(), sequence = 0;

        for (i = 0; i < 10 && i < size; ++i) {
            sequence <<= 2;
            sequence |= letter2Num[s[i]];
        }

        sequences[sequence] = 1;

        for (; i < size; ++i) {
            sequence <<= 2;
            sequence |= letter2Num[s[i]];
            sequence &= (~0b1100000000000000000000);
            if (++sequences[sequence] == 2) {
                string repeatedSequence(s, i - 9, 10);
                repeatedSequences.push_back(repeatedSequence);
            }
        }

        return repeatedSequences;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> expected = { "AAAAACCCCC","CCCCCAAAAA" };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    expected = { "AAAAAAAAAA" };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("AAAAAAAAAAA");
    expected = { "AAAAAAAAAA" };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("AAAAAAAAAA");
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("");
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    expected = { "AAAAACCCCC","CCCCCAAAAA" };
    check.checkStringVector(expected, actual);

    actual = o.findRepeatedDnaSequences("AACCGGAACCGGAACCGG");
    expected = { "AACCGGAACC","ACCGGAACCG","CCGGAACCGG" };
    check.checkStringVector(expected, actual);
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
