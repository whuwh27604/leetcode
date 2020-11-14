#if 0 
删除注释.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第i行源码。 这表示每行源码由\n分隔。

在 C++ 中有两种注释风格，行内注释和块注释。

字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。

字符串/* 表示一个块注释，它表示直到*/的下一个（非重叠）出现的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串/*/并没有结束块注释，因为注释的结尾与开头相重叠。

第一个有效注释优先于其他注释：如果字符串//出现在块注释中会被忽略。 同样，如果字符串/*出现在行或块注释中也会被忽略。

如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。

样例中没有控制字符，单引号或双引号字符。比如，source = "string s = "/* Not a comment. */";" 不会出现在测试样例里。（此外，没有其他内容（如定义或宏）会干扰注释。）

我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的/*总是开始新的注释。

最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。

从源代码中删除注释后，需要以相同的格式返回源代码。

示例 1:

输入:
source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]

示例代码可以编排成这样:
/*Test program */
int main()
{
    // variable declaration 
    int a, b, c;
    /* This is a test
       multiline
       comment for
       testing */
    a = b + c;
}

输出: ["int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}"]

编排后 :
    int main()
{

    int a, b, c;
    a = b + c;
}

解释:
第 1 行和第 6 - 9 行的字符串 /* 表示块注释。第 4 行的字符串 // 表示行注释。
示例 2:

输入:
source = ["a/*comment", "line", "more_comment*/b"]
输出 : ["ab"]
解释 : 原始的 source 字符串是 "a/*comment\nline\nmore_comment*/b", 其中我们用粗体显示了换行符。删除注释后，隐含的换行符被删除，留下字符串 "ab" 用换行符分隔成数组时就是["ab"].
注意 :

    source的长度范围为[1, 100].
    source[i]的长度范围为[0, 80].
    每个块注释都会被闭合。
    给定的源码中不会有单引号、双引号或其他控制字符。

    来源：力扣（LeetCode）
    链接：https ://leetcode-cn.com/problems/remove-comments
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> pureSources;
        bool inComment = false;

        for (string& line : source) {
            if (!inComment) {
                pureSources.push_back("");
            }

            int i, size = line.size();
            for (i = 0; i < size - 1; i++) {
                if ((line[i] == '/') && (line[i + 1] == '/')) {
                    processLineComment(inComment, i);
                }
                else if ((line[i] == '/') && (line[i + 1] == '*')) {
                    processBlockCommentStart(inComment, i);
                }
                else if ((line[i] == '*') && (line[i + 1] == '/')) {
                    processBlockCommentEnd(inComment, i, pureSources.back());
                }
                else {
                    processCommonCode(inComment, line[i], pureSources.back());
                }
            }

            if (!inComment && (i == size - 1)) {
                pureSources.back() += line[i];
            }

            if (!inComment && pureSources.back().empty()) {
                pureSources.pop_back();
            }
        }

        return pureSources;
    }

    void processLineComment(bool& inComment, int& index) {
        if (!inComment) {
            index = INT_MAX - 1;
        }
        else {
            index++;
        }
    }

    void processBlockCommentStart(bool& inComment, int& index) {
        if (!inComment) {
            inComment = true;
            index++;
        }
    }

    void processBlockCommentEnd(bool& inComment, int& index, string& pureSource) {
        if (inComment) {
            inComment = false;
            index++;
        }
        else {
            pureSource += "*";
        }
    }

    void processCommonCode(bool& inComment, char c, string& pureSource) {
        if (!inComment) {
            pureSource += c;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> source = { "/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}" };
    vector<string> actual = o.removeComments(source);
    vector<string> expected = { "int main()","{ ","  ","int a, b, c;","a = b + c;","}" };
    check.checkStringVector(expected, actual);

    source = { "a/*comment", "line", "more_comment*/b" };
    actual = o.removeComments(source);
    expected = { "ab" };
    check.checkStringVector(expected, actual);

    source = { "class test{","public: ","   int x = 1;","   /*double y = 1;*/","   char c;","};" };
    actual = o.removeComments(source);
    expected = { "class test{","public: ","   int x = 1;","   ","   char c;","};" };
    check.checkStringVector(expected, actual);

    source = { "void func(int k) {", "// this function does nothing /*", " k = k*2/4;", " k = k/2;*/", "}" };
    actual = o.removeComments(source);
    expected = { "void func(int k) {", " k = k*2/4;", " k = k/2;*/", "}" };
    check.checkStringVector(expected, actual);

    source = { "a//*b//*c","blank","d/*/e*//f" };
    actual = o.removeComments(source);
    expected = { "a","blank","d/f" };
    check.checkStringVector(expected, actual);

    source = { "a//*b//*c","blank","d*//e*//f" };
    actual = o.removeComments(source);
    expected = { "a","blank","d*" };
    check.checkStringVector(expected, actual);

    source = { "a//*b/*/c","blank","d/*/e/*/f" };
    actual = o.removeComments(source);
    expected = { "a","blank","df" };
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
