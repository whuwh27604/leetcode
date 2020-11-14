/* 宝石与石头.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

示例 1:

输入: J = "aA", S = "aAAbbbb"
输出: 3
示例 2:

输入: J = "z", S = "ZZ"
输出: 0
注意:

S 和 J 最多含有50个字母。
 J 中的字符不重复。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jewels-and-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int JewelsTable[(int)('z') + 1] = { 0 };
        int sum = 0;
        for (unsigned int i = 0; i < J.size(); i++) {
            JewelsTable[(int)(J[i])] = 1;
        }

        for (unsigned int j = 0; j < S.size(); j++) {
            sum += JewelsTable[(int)(S[j])];
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string J = "aA";
    string S = "aAAbbbb";
    check.checkInt(3, o.numJewelsInStones(J, S));

    J = "z";
    S = "ZZ";
    check.checkInt(0, o.numJewelsInStones(J, S));

    J = "";
    S = "";
    check.checkInt(0, o.numJewelsInStones(J, S));

    J = "";
    S = "abcdefghijklmnopqrstuvwxyz";
    check.checkInt(0, o.numJewelsInStones(J, S));

    J = "a";
    S = "a";
    check.checkInt(1, o.numJewelsInStones(J, S));
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
