/* 字母组合迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个迭代器类，包括以下内容：

一个构造函数，输入参数包括：一个 有序且字符唯一 的字符串 characters（该字符串只包含小写英文字母）和一个数字 combinationLength 。
函数 next() ，按 字典序 返回长度为 combinationLength 的下一个字母组合。
函数 hasNext() ，只有存在长度为 combinationLength 的下一个字母组合时，才返回 True；否则，返回 False。
 

示例：

CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator

iterator.next(); // 返回 "ab"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "ac"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "bc"
iterator.hasNext(); // 返回 false
 

提示：

1 <= combinationLength <= characters.length <= 15
每组测试数据最多包含 10^4 次函数调用。
题目保证每次调用函数 next 时都存在下一个字母组合。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/iterator-for-combination
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        letters = characters;
        lettersSize = letters.size();
        combinationSize = combinationLength;
        chosen = 0;

        for (int i = 0; i < combinationSize; ++i) {
            chosen <<= 1;
            chosen |= 1;
        }

        for (int i = combinationSize; i < lettersSize; ++i) {
            chosen <<= 1;
        }
    }

    string next() {
        string word = getWord();
        int i, rightOnes = 0, mask = 1;
        bool movable = false;

        for (i = 0; i < lettersSize; ++i) {
            if ((chosen & mask) == 0) {
                movable = true;
            }
            else {
                chosen &= ~mask;

                if (movable) {
                    for (i = 0; i <= rightOnes; ++i) {
                        mask >>= 1;
                        chosen |= mask;
                    }
                    break;
                }
                else {
                    ++rightOnes;
                }
            }

            mask <<= 1;
        }

        return word;
    }

    string getWord() {
        string word(combinationSize, 0);
        int i, index = 0, mask = (1 << (lettersSize - 1));

        for (i = 0; i < lettersSize && index < combinationSize; ++i) {
            if ((chosen & mask) != 0) {
                word[index++] = letters[i];
            }

            mask >>= 1;
        }

        return word;
    }

    bool hasNext() {
        return chosen != 0;
    }

private:
    string letters;
    int lettersSize;
    int combinationSize;
    int chosen;
};

int main()
{
    CheckResult check;

    CombinationIterator o1("abc", 2);
    check.checkString("ab", o1.next());
    check.checkBool(true, o1.hasNext());
    check.checkString("ac", o1.next());
    check.checkBool(true, o1.hasNext());
    check.checkString("bc", o1.next());
    check.checkBool(false, o1.hasNext());

    CombinationIterator o2("x", 1);
    check.checkString("x", o2.next());
    check.checkBool(false, o2.hasNext());

    CombinationIterator o3("abcde", 3);
    check.checkString("abc", o3.next());
    check.checkString("abd", o3.next());
    check.checkString("abe", o3.next());
    check.checkString("acd", o3.next());
    check.checkString("ace", o3.next());
    check.checkString("ade", o3.next());
    check.checkString("bcd", o3.next());
    check.checkString("bce", o3.next());
    check.checkString("bde", o3.next());
    check.checkString("cde", o3.next());
    check.checkBool(false, o3.hasNext());
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
