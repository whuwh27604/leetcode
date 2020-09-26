/* 文件的最长绝对路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设我们以下述方式将我们的文件系统抽象成一个字符串:

字符串 "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" 表示:

dir
    subdir1
    subdir2
        file.ext
目录 dir 包含一个空的子目录 subdir1 和一个包含一个文件 file.ext 的子目录 subdir2 。

字符串 "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 表示:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
目录 dir 包含两个子目录 subdir1 和 subdir2。 subdir1 包含一个文件 file1.ext 和一个空的二级子目录 subsubdir1。subdir2 包含一个二级子目录 subsubdir2 ，其中包含一个文件 file2.ext。

我们致力于寻找我们文件系统中文件的最长 (按字符的数量统计) 绝对路径。例如，在上述的第二个例子中，最长路径为 "dir/subdir2/subsubdir2/file2.ext"，其长度为 32 (不包含双引号)。

给定一个以上述格式表示文件系统的字符串，返回文件系统中文件的最长绝对路径的长度。 如果系统中没有文件，返回 0。

说明:

文件名至少存在一个 . 和一个扩展名。
目录或者子目录的名字不能包含 .。
要求时间复杂度为 O(n) ，其中 n 是输入字符串的大小。

请注意，如果存在路径 aaaaaaaaaaaaaaaaaaaaa/sth.png 的话，那么  a/aa/aaa/file1.txt 就不是一个最长的路径。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-absolute-file-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int endPosition = -1, pathOrFile, indentation, len, maxPathLen = 0;
        vector<int> pathLengths;

        while ((len = getlength(input, endPosition + 1, endPosition, pathOrFile, indentation)) != -1) {
            if (len == 0) {
                continue;
            }

            while ((int)pathLengths.size() > indentation) {
                pathLengths.pop_back();
            }
            pathLengths.push_back(len);

            if (pathOrFile == 1) {
                int absolutePathLen = getAbsolutePathLen(pathLengths);
                maxPathLen = max(absolutePathLen, maxPathLen);
            }
        }

        return maxPathLen;
    }

    int getlength(string& input, int position, int& endPosition, int& pathOrFile, int& indentation) {
        if (position >= (int)input.size()) {
            return -1;
        }

        int start = position;
        indentation = 0;
        if (input[start] == '\n') {
            start += 1;
        }

        while (input[start] == '\t') {
            indentation++;
            start += 1;
        }

        endPosition = input.find('\n', start);
        endPosition = (endPosition == input.npos) ? input.size() - 1 : endPosition - 1;

        int len = endPosition - start + 1;
        pathOrFile = 0;  // path
        for (; start < endPosition; start++) {
            if (input[start] == '.') {
                pathOrFile = 1;  // file
                break;
            }
        }

        return len;
    }

    int getAbsolutePathLen(vector<int>& pathLengths) {
        int absolutePathLen = 0;

        for (int len : pathLengths) {
            absolutePathLen += (len + 1);  // 路径需要添加一个'/'
        }

        return absolutePathLen - 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(20, o.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
    check.checkInt(32, o.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"));
    check.checkInt(29, o.lengthLongestPath("aaaaaaaaaaaaaaaaaaaaa\n\tsth.png\na\n\taa\n\t\taaa\n\t\t\tfile1.txt"));
    check.checkInt(0, o.lengthLongestPath(""));
    check.checkInt(0, o.lengthLongestPath("path\n\tfile"));
    check.checkInt(0, o.lengthLongestPath("a"));
    check.checkInt(4, o.lengthLongestPath("a.x/"));
    check.checkInt(3, o.lengthLongestPath("a.x"));
    check.checkInt(2, o.lengthLongestPath(".x"));
    check.checkInt(4, o.lengthLongestPath("  .x"));
    check.checkInt(14, o.lengthLongestPath("a.aaa\n\tfile.txt"));  // 算法出的结果就这样，和实际理解是冲突的
    check.checkInt(12, o.lengthLongestPath("dir\n    file.txt"));
    check.checkInt(7, o.lengthLongestPath("abc\n\ta.x"));
    check.checkInt(3, o.lengthLongestPath("abc\n\na.x"));
    check.checkInt(7, o.lengthLongestPath("\nabc\n\ta.x"));
    check.checkInt(6, o.lengthLongestPath("abc\n\t.x"));
    check.checkInt(10, o.lengthLongestPath("abc\n\t    .x"));
    check.checkInt(11, o.lengthLongestPath("abc \n\t    .x"));
    check.checkInt(4, o.lengthLongestPath("abc\na.xx"));
    check.checkInt(7, o.lengthLongestPath("dir\n\t\ta.x"));  // \t比实际的多，按照实际最多的可能算
    // 一个路径下如果同时有路径和文件，文件只能放在最后，否则文件名会被当做路径名处理
    check.checkInt(43, o.lengthLongestPath("dir\n\tsubdir\n\t\tsubsubdir\n\t\t\tfile.txt\n\tfileabcdefghiljklmn.txt\n\t\tsubsubdir\n\t\tfileabcdefg.txt"));
    check.checkInt(29, o.lengthLongestPath("dir\n\tsubdir\n\t\tsubsubdir\n\t\t\tfile.txt\n\t\tsubsubdir\n\t\tfileabcdefg.txt\n\tfileabcdefghiljklmn.txt"));
    check.checkInt(30, o.lengthLongestPath("dir\n\tsubdir\n\t\tsubsubdir\n\t\t\tfile.txt\n\t\tsubsubdir\n\t\tfileabcdefg.txt\n\tfileabcdefghiljklmnopq.txt"));
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
