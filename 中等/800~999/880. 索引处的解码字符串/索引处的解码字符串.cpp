/* 索引处的解码字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个编码字符串 S。请你找出 解码字符串 并将其写入磁带。解码时，从编码字符串中 每次读取一个字符 ，并采取以下步骤：

如果所读的字符是字母，则将该字母写在磁带上。
如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

 

示例 1：

输入：S = "leet2code3", K = 10
输出："o"
解释：
解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
字符串中的第 10 个字母是 "o"。
示例 2：

输入：S = "ha22", K = 5
输出："h"
解释：
解码后的字符串为 "hahahaha"。第 5 个字母是 "h"。
示例 3：

输入：S = "a2345678999999999999999", K = 1
输出："a"
解释：
解码后的字符串为 "a" 重复 8301530446056247680 次。第 1 个字母是 "a"。
 

提示：

2 <= S.length <= 100
S 只包含小写字母与数字 2 到 9 。
S 以字母开头。
1 <= K <= 10^9
题目保证 K 小于或等于解码字符串的长度。
解码后的字符串保证少于 2^63 个字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decoded-string-at-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<string> letters;
        vector<int> repeatTimes;
        parse(S, letters, repeatTimes);

        vector<long long> segmentLen;
        calcSegmentLen(letters, repeatTimes, segmentLen);

        int i, size = segmentLen.size();
        string ans;

        while (true) {
            for (i = 0; i < size; ++i) {
                if (K <= segmentLen[i]) {
                    break;
                }
            }

            if (i == 0) {
                K %= letters[0].size();
                if (K == 0) {
                    K = letters[0].size();
                }
                ans += letters[0][K - 1];
                break;
            }

            K %= (segmentLen[i - 1] + letters[i].size());
            if (K == 0) {
                K = (int)segmentLen[i - 1] + letters[i].size();
            }
            if (K > (int)segmentLen[i - 1]) {
                ans += letters[i][K - (int)segmentLen[i - 1] - 1];
                break;
            }
        }        

        return ans;
    }

    void parse(string& S, vector<string>& letters, vector<int>& repeatTimes) {
        if (S.back() >= 'a' && S.back() <= 'z') {
            S.push_back('1');
        }

        letters.push_back("");

        for (char c : S) {
            if (c >= 'a' && c <= 'z') {
                letters.back().push_back(c);
            }
            else {
                repeatTimes.push_back(c - '0');
                letters.push_back("");
            }
        }

        letters.pop_back();
    }

    void calcSegmentLen(vector<string>& letters, vector<int>& repeatTimes, vector<long long>& segmentLen) {
        long long len = 0;

        for (int i = 0; i < (int)letters.size(); ++i) {
            len = (len + letters[i].size()) * repeatTimes[i];
            segmentLen.push_back(len);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("o", o.decodeAtIndex("leet2code3", 10));
    check.checkString("h", o.decodeAtIndex("ha22", 5));
    check.checkString("a", o.decodeAtIndex("a23", 1));
    check.checkString("a", o.decodeAtIndex("ab2cde3fghi4", 1));
    check.checkString("b", o.decodeAtIndex("ab2cde3fghi4", 4));
    check.checkString("c", o.decodeAtIndex("ab2cde3fghi4", 5));
    check.checkString("e", o.decodeAtIndex("ab2cde3fghi4", 21));
    check.checkString("f", o.decodeAtIndex("ab2cde3fghi4", 22));
    check.checkString("i", o.decodeAtIndex("ab2cde3fghi4", 25));
    check.checkString("d", o.decodeAtIndex("ab2cde3fghi4", 56));
    check.checkString("g", o.decodeAtIndex("ab2cde3fghi4", 73));
    check.checkString("h", o.decodeAtIndex("ab2cde3fghi4", 99));
    check.checkString("i", o.decodeAtIndex("ab2cde3fghi4", 100));
    check.checkString("a", o.decodeAtIndex("aa4bb54cc387dd", 27777777));
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
