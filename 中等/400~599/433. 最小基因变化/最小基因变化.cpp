/* 最小基因变化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。

例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。

与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。

现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。

注意:

起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
所有的目标基因序列必须是合法的。
假定起始基因序列与目标基因序列是不一样的。
示例 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

返回值: 1
示例 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

返回值: 2
示例 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

返回值: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> validMutations;
        for (string validGene : bank) {
            validMutations.insert(validGene);
        }

        int char2Index[85] = { 0 };
        char2Index['A'] = 0;
        char2Index['C'] = 1;
        char2Index['G'] = 2;
        char2Index['T'] = 3;
        char index2Char[4] = { 'A','C','G','T' };
        int level = 0;
        list<string> mutations;
        mutations.push_back(start);
        validMutations.erase(start);

        while (!mutations.empty()) {
            level++;
            int size = mutations.size();
            for (int i = 0; i < size; i++) {
                string mutation = mutations.front();
                mutations.pop_front();

                for (int m = 0; m < 8; m++) {
                    int index = char2Index[mutation[m]];

                    for (int n = 0; n < 3; n++) {
                        index = (index == 3) ? 0 : index + 1;
                        mutation[m] = index2Char[index];

                        auto iter = validMutations.find(mutation);
                        if (iter == validMutations.end()) {
                            continue;
                        }

                        if (mutation == end) {
                            return level;
                        }

                        mutations.push_back(mutation);
                        validMutations.erase(iter);  // 避免下次又变回来了
                    }

                    index = (index == 3) ? 0 : index + 1;
                    mutation[m] = index2Char[index];
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> bank = { "AACCGGTA" };
    check.checkInt(1, o.minMutation("AACCGGTT", "AACCGGTA", bank));

    bank = { "AACCTGTT" };
    check.checkInt(1, o.minMutation("AACCGGTT", "AACCTGTT", bank));

    bank = { "AACGGGTT" };
    check.checkInt(1, o.minMutation("AACCGGTT", "AACGGGTT", bank));

    bank = { "CACCGGTT" };
    check.checkInt(1, o.minMutation("AACCGGTT", "CACCGGTT", bank));

    bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
    check.checkInt(2, o.minMutation("AACCGGTT", "AAACGGTA", bank));

    bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
    check.checkInt(3, o.minMutation("AAAAACCC", "AACCCCCC", bank));

    bank = { "AAAAACCC","AAAACCCC", "AAACCCCC", "AACCCCCC" };
    check.checkInt(3, o.minMutation("AAAAACCC", "AACCCCCC", bank));

    bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
    check.checkInt(-1, o.minMutation("AAAAACCC", "AACCCCCT", bank));

    bank = { "AAAAAAGG","AAAAAACG","AAAAAACA" };
    check.checkInt(3, o.minMutation("AAAAAAAA", "AAAAAAGG", bank));

    bank = { "AAAAAAGG","AAAAAACG","AAAAAACA","AAAAAAAA" };
    check.checkInt(3, o.minMutation("AAAAAAAA", "AAAAAAGG", bank));

    bank = {  };
    check.checkInt(-1, o.minMutation("AAAAAAAA", "AAAAAAAG", bank));
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
