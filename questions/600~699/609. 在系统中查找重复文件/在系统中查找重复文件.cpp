/* 在系统中查找重复文件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个目录信息列表，包括目录路径，以及该目录中的所有包含内容的文件，您需要找到文件系统中的所有重复文件组的路径。一组重复的文件至少包括二个具有完全相同内容的文件。

输入列表中的单个目录信息字符串的格式如下：

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

这意味着有 n 个文件（f1.txt, f2.txt ... fn.txt 的内容分别是 f1_content, f2_content ... fn_content）在目录 root/d1/d2/.../dm 下。注意：n>=1 且 m>=0。如果 m=0，则表示该目录是根目录。

该输出是重复文件路径组的列表。对于每个组，它包含具有相同内容的文件的所有文件路径。文件路径是具有下列格式的字符串：

"directory_path/file_name.txt"

示例 1：

输入：
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
输出：
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 

注：

最终输出不需要顺序。
您可以假设目录名、文件名和文件内容只有字母和数字，并且文件内容的长度在 [1，50] 的范围内。
给定的文件数量在 [1，20000] 个范围内。
您可以假设在同一目录中没有任何文件或目录共享相同的名称。
您可以假设每个给定的目录信息代表一个唯一的目录。目录路径和文件信息用一个空格分隔。
 

超越竞赛的后续行动：

假设您有一个真正的文件系统，您将如何搜索文件？广度搜索还是宽度搜索？
如果文件内容非常大（GB级别），您将如何修改您的解决方案？
如果每次只能读取 1 kb 的文件，您将如何修改解决方案？
修改后的解决方案的时间复杂度是多少？其中最耗时的部分和消耗内存的部分是什么？如何优化？
如何确保您发现的重复文件不是误报？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-duplicate-file-in-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contextFiles;
        vector<vector<string>> duplicates;

        for (string& pathFiles : paths) {
            analysisPath(pathFiles, contextFiles);
        }

        for (auto iter = contextFiles.begin(); iter != contextFiles.end(); iter++) {
            if (iter->second.size() > 1) {
                duplicates.push_back(iter->second);
            }
        }

        return duplicates;
    }

    void analysisPath(string& pathFiles, unordered_map<string, vector<string>>& contextFiles) {
        pathFiles.push_back(' ');
        int space = pathFiles.find(' ');
        string path(pathFiles, 0, space);

        int prev = space;
        while ((space = pathFiles.find(' ', prev + 1)) != pathFiles.npos) {
            int parenthesis = pathFiles.find('(', prev + 1);
            string file(pathFiles, prev + 1, parenthesis - prev - 1);
            string context(pathFiles, parenthesis + 1, space - 1 - parenthesis);

            auto iter = contextFiles.find(context);
            if (iter == contextFiles.end()) {
                contextFiles[context] = { path + '/' + file };
            }
            else {
                iter->second.push_back(path + '/' + file);
            }

            prev = space;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> paths = { "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)" };
    vector<vector<string>> actual = o.findDuplicate(paths);
    vector<vector<string>> expected = { {"root/a/2.txt","root/c/d/4.txt","root/4.txt"},{"root/a/1.txt","root/c/3.txt"} };
    check.checkStringVectorVector(expected, actual);

    paths = { "root/c 3.txt(abcd)" };
    actual = o.findDuplicate(paths);
    expected = {  };
    check.checkStringVectorVector(expected, actual);
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
