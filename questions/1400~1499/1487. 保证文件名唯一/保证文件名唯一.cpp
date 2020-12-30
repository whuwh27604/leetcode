/* 保证文件名唯一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的字符串数组 names 。你将会在文件系统中创建 n 个文件夹：在第 i 分钟，新建名为 names[i] 的文件夹。

由于两个文件 不能 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 (k) 的形式为新文件夹的文件名添加后缀，其中 k 是能保证文件名唯一的 最小正整数 。

返回长度为 n 的字符串数组，其中 ans[i] 是创建第 i 个文件夹时系统分配给该文件夹的实际名称。

 

示例 1：

输入：names = ["pes","fifa","gta","pes(2019)"]
输出：["pes","fifa","gta","pes(2019)"]
解释：文件系统将会这样创建文件名：
"pes" --> 之前未分配，仍为 "pes"
"fifa" --> 之前未分配，仍为 "fifa"
"gta" --> 之前未分配，仍为 "gta"
"pes(2019)" --> 之前未分配，仍为 "pes(2019)"
示例 2：

输入：names = ["gta","gta(1)","gta","avalon"]
输出：["gta","gta(1)","gta(2)","avalon"]
解释：文件系统将会这样创建文件名：
"gta" --> 之前未分配，仍为 "gta"
"gta(1)" --> 之前未分配，仍为 "gta(1)"
"gta" --> 文件名被占用，系统为该名称添加后缀 (k)，由于 "gta(1)" 也被占用，所以 k = 2 。实际创建的文件名为 "gta(2)" 。
"avalon" --> 之前未分配，仍为 "avalon"
示例 3：

输入：names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
输出：["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
解释：当创建最后一个文件夹时，最小的正有效 k 为 4 ，文件名变为 "onepiece(4)"。
示例 4：

输入：names = ["wano","wano","wano","wano"]
输出：["wano","wano(1)","wano(2)","wano(3)"]
解释：每次创建文件夹 "wano" 时，只需增加后缀中 k 的值即可。
示例 5：

输入：names = ["kaido","kaido(1)","kaido","kaido(1)"]
输出：["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
解释：注意，如果含后缀文件名被占用，那么系统也会按规则在名称后添加新的后缀 (k) 。
 

提示：

1 <= names.length <= 5 * 10^4
1 <= names[i].length <= 20
names[i] 由小写英文字母、数字和/或圆括号组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/making-file-names-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> folders;
        vector<string> actualNames(names.size());
        int i = 0;

        for (string& name : names) {
            if (folders.count(name) == 0) {
                actualNames[i++] = name;
                folders[name] = 0;
            }
            else {
                int index = folders[name];

                string actualName;
                do {
                    actualName = name + '(' + to_string(++index) + ')';
                } while (folders.count(actualName) != 0);

                folders[name] = index;
                folders[actualName] = 0;
                actualNames[i++] = actualName;
            }
        }

        return actualNames;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> names = { "pes","fifa","gta","pes(2019)" };
    vector<string> actual = o.getFolderNames(names);
    vector<string> expected = { "pes","fifa","gta","pes(2019)" };
    check.checkStringVector(expected, actual);

    names = { "gta","gta(1)","gta","avalon" };
    actual = o.getFolderNames(names);
    expected = { "gta","gta(1)","gta(2)","avalon" };
    check.checkStringVector(expected, actual);

    names = { "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece" };
    actual = o.getFolderNames(names);
    expected = { "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)" };
    check.checkStringVector(expected, actual);

    names = { "wano","wano","wano","wano" };
    actual = o.getFolderNames(names);
    expected = { "wano","wano(1)","wano(2)","wano(3)" };
    check.checkStringVector(expected, actual);

    names = { "kaido","kaido(1)","kaido","kaido(1)" };
    actual = o.getFolderNames(names);
    expected = { "kaido","kaido(1)","kaido(2)","kaido(1)(1)" };
    check.checkStringVector(expected, actual);

    names = { "kaido","kaido(1)","kaido","kaido(1)","kaido(2)" };
    actual = o.getFolderNames(names);
    expected = { "kaido","kaido(1)","kaido(2)","kaido(1)(1)","kaido(2)(1)" };
    check.checkStringVector(expected, actual);

    names = { "m","t","y(4)","t","a","p","h","h","z","z(2)(2)","x(3)","h(4)(3)","l","z(1)","h","s(1)(2)","y(3)(2)","m(3)","i","h","u","j(1)(4)","q","j(1)","c","n(4)","k","s(1)(4)","p(2)","m","r(1)(4)","k(3)","d(3)(1)","e(4)" };
    actual = o.getFolderNames(names);
    expected = { "m","t","y(4)","t(1)","a","p","h","h(1)","z","z(2)(2)","x(3)","h(4)(3)","l","z(1)","h(2)","s(1)(2)","y(3)(2)","m(3)","i","h(3)","u","j(1)(4)","q","j(1)","c","n(4)","k","s(1)(4)","p(2)","m(1)","r(1)(4)","k(3)","d(3)(1)","e(4)" };
    check.checkStringVector(expected, actual);

    names = { "pes","pes","pes(1)","pes(0)" };
    actual = o.getFolderNames(names);
    expected = { "pes","pes(1)","pes(1)(1)","pes(0)" };
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
