/* 简化路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "";
        }

        list<string> paths;
        path.push_back('/');

        int prevSlash = 0, curSlash;
        while ((curSlash = path.find('/', prevSlash + 1)) != string::npos) {
            string onePath(path, prevSlash + 1, curSlash - prevSlash - 1);
            prevSlash = curSlash;
            if (onePath == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            }
            else if (onePath == ".") {
                continue;
            }
            else if (onePath == "") {
                continue;
            }
            else {
                paths.push_back(onePath);
            }
        }

        if (paths.empty()) {
            return "/";
        }

        string simplifiedPath;
        while (!paths.empty()) {
            simplifiedPath += "/";
            simplifiedPath += paths.front();
            paths.pop_front();
        }

        return simplifiedPath;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("", o.simplifyPath(""));
    check.checkString("/", o.simplifyPath("/"));
    check.checkString("/home", o.simplifyPath("/home/"));
    check.checkString("/", o.simplifyPath("/../"));
    check.checkString("/home/foo", o.simplifyPath("/home//foo/"));
    check.checkString("/c", o.simplifyPath("/a/./b/../../c/"));
    check.checkString("/c", o.simplifyPath("/a/../../b/../c//.//"));
    check.checkString("/a/b/c", o.simplifyPath("/a//b////c/d//././/.."));
    check.checkString("/.a/..a/a.b/a.b./a.b.c..", o.simplifyPath("//.a//..a///a.b///a.b.//a.b.c.."));
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
