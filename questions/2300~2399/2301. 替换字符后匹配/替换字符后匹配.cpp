/* 替换字符后匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 sub 。同时给你一个二维字符数组 mappings ，其中 mappings[i] = [oldi, newi] 表示你可以替换 sub 中任意数目的 oldi 个字符，替换成 newi 。sub 中每个字符 不能 被替换超过一次。

如果使用 mappings 替换 0 个或者若干个字符，可以将 sub 变成 s 的一个子字符串，请你返回 true，否则返回 false 。

一个 子字符串 是字符串中连续非空的字符序列。

 

示例 1：

输入：s = "fool3e7bar", sub = "leet", mappings = [["e","3"],["t","7"],["t","8"]]
输出：true
解释：将 sub 中第一个 'e' 用 '3' 替换，将 't' 用 '7' 替换。
现在 sub = "l3e7" ，它是 s 的子字符串，所以我们返回 true 。
示例 2：

输入：s = "fooleetbar", sub = "f00l", mappings = [["o","0"]]
输出：false
解释：字符串 "f00l" 不是 s 的子串且没有可以进行的修改。
注意我们不能用 'o' 替换 '0' 。
示例 3：

输入：s = "Fool33tbaR", sub = "leetd", mappings = [["e","3"],["t","7"],["t","8"],["d","b"],["p","b"]]
输出：true
解释：将 sub 里第一个和第二个 'e' 用 '3' 替换，用 'b' 替换 sub 里的 'd' 。
得到 sub = "l33tb" ，它是 s 的子字符串，所以我们返回 true 。
 

提示：

1 <= sub.length <= s.length <= 5000
0 <= mappings.length <= 1000
mappings[i].length == 2
oldi != newi
s 和 sub 只包含大写和小写英文字母和数字。
oldi 和 newi 是大写、小写字母或者是个数字。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/match-substring-after-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<bool>> canMapping(127, vector<bool>(127, false));

        map(mappings, canMapping);

        for (int i = 0; i <= (int)(s.size() - sub.size()); ++i) {
            if (check(s, sub, i, canMapping)) {
                return true;
            }
        }

        return false;
    }

    void map(vector<vector<char>>& mappings, vector<vector<bool>>& canMapping) {
        for (auto& mapping : mappings) {
            canMapping[mapping[0]][mapping[1]] = true;
        }
    }

    bool check(string& s, string& sub, int start, vector<vector<bool>>& canMapping) {
        for (int i = 0, j = start; i < (int)sub.size(); ++i, ++j) {
            if (sub[i] != s[j] && !canMapping[sub[i]][s[j]]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> mappings = { {'e','3'},{'t','7'},{'t','8'} };
    check.checkBool(true, o.matchReplacement("fool3e7bar", "leet", mappings));

    mappings = { {'e','3'},{'t','7'},{'t','8'},{'d','b'},{'p','b'} };
    check.checkBool(true, o.matchReplacement("Fool33tbaR", "leetd", mappings));

    mappings = { {'i','a'},{'i','b'},{'i','c'},{'i','d'},{'i','e'},{'i','g'},{'i','h'},{'i','j'},{'i','k'},{'i','m'},{'i','n'},{'i','o'},{'i','p'},{'i','q'},{'i','r'},{'i','s'},{'i','t'},{'i','u'},{'i','v'},{'i','w'},{'i','x'},{'i','y'},{'i','z'},{'i','0'},{'i','1'},{'i','2'},{'i','3'},{'i','4'},{'i','5'},{'i','6'},{'i','7'},{'i','8'},{'i','9'},{'i','A'},{'i','B'},{'i','C'},{'i','D'},{'i','E'},{'i','F'},{'i','G'},{'i','H'},{'i','I'},{'i','J'},{'i','K'},{'i','L'},{'i','M'},{'i','N'},{'i','O'},{'i','P'},{'i','Q'},{'i','R'},{'i','S'},{'i','T'},{'i','U'},{'i','V'},{'i','W'},{'i','X'},{'i','Y'},{'i','Z'},{'1','a'},{'1','b'},{'1','c'},{'1','d'},{'1','e'},{'1','g'},{'1','h'},{'1','i'},{'1','j'},{'1','k'},{'1','m'},{'1','n'},{'1','o'},{'1','p'},{'1','q'},{'1','r'},{'1','s'},{'1','t'},{'1','u'},{'1','v'},{'1','w'},{'1','x'},{'1','y'},{'1','z'},{'1','0'},{'1','2'},{'1','3'},{'1','4'},{'1','5'},{'1','6'},{'1','7'},{'1','8'},{'1','9'},{'1','A'},{'1','B'},{'1','C'},{'1','D'},{'1','E'},{'1','F'},{'1','G'},{'1','H'},{'1','I'},{'1','J'},{'1','K'},{'1','L'},{'1','M'},{'1','N'},{'1','O'},{'1','P'},{'1','Q'},{'1','R'},{'1','S'},{'1','T'},{'1','U'},{'1','V'},{'1','W'},{'1','X'},{'1','Y'},{'1','Z'},{'t','a'},{'t','b'},{'t','c'},{'t','d'},{'t','e'},{'t','g'},{'t','h'},{'t','i'},{'t','j'},{'t','k'},{'t','m'},{'t','n'},{'t','o'},{'t','p'},{'t','q'},{'t','r'},{'t','s'},{'t','u'},{'t','v'},{'t','w'},{'t','x'},{'t','y'},{'t','z'},{'t','0'},{'t','1'},{'t','2'},{'t','3'},{'t','4'},{'t','5'},{'t','6'},{'t','7'},{'t','8'},{'t','9'},{'t','A'},{'t','B'},{'t','C'},{'t','D'},{'t','E'},{'t','F'},{'t','G'},{'t','H'},{'t','I'},{'t','J'},{'t','K'},{'t','L'},{'t','M'},{'t','N'},{'t','O'},{'t','P'},{'t','Q'},{'t','R'},{'t','S'},{'t','T'},{'t','U'},{'t','V'},{'t','W'},{'t','X'},{'t','Y'},{'t','Z'},{'I','a'},{'I','b'},{'I','c'},{'I','d'},{'I','e'},{'I','g'},{'I','h'},{'I','i'},{'I','j'},{'I','k'},{'I','m'},{'I','n'},{'I','o'},{'I','p'},{'I','q'},{'I','r'},{'I','s'},{'I','t'},{'I','u'},{'I','v'},{'I','w'},{'I','x'},{'I','y'},{'I','z'},{'I','0'},{'I','1'},{'I','2'},{'I','3'},{'I','4'},{'I','5'},{'I','6'},{'I','7'},{'I','8'},{'I','9'},{'I','A'},{'I','B'},{'I','C'},{'I','D'},{'I','E'},{'I','F'},{'I','G'},{'I','H'},{'I','J'},{'I','K'},{'I','L'},{'I','M'},{'I','N'},{'I','O'},{'I','P'},{'I','Q'},{'I','R'},{'I','S'},{'I','T'},{'I','U'},{'I','V'},{'I','W'},{'I','X'},{'I','Y'},{'I','Z'},{'L','a'},{'L','b'},{'L','c'},{'L','d'},{'L','e'},{'L','g'},{'L','h'},{'L','i'},{'L','j'},{'L','k'},{'L','m'},{'L','n'},{'L','o'},{'L','p'},{'L','q'},{'L','r'},{'L','s'},{'L','t'},{'L','u'},{'L','v'},{'L','w'},{'L','x'},{'L','y'},{'L','z'},{'L','0'},{'L','1'},{'L','2'},{'L','3'},{'L','4'},{'L','5'},{'L','6'},{'L','7'},{'L','8'},{'L','9'},{'L','A'},{'L','B'},{'L','C'},{'L','D'},{'L','E'},{'L','F'},{'L','G'},{'L','H'},{'L','I'},{'L','J'},{'L','K'},{'L','M'},{'L','N'},{'L','O'},{'L','P'},{'L','Q'},{'L','R'},{'L','S'},{'L','T'},{'L','U'},{'L','V'},{'L','W'},{'L','X'},{'L','Y'},{'L','Z'},{'i','l'},{'1','l'},{'t','l'},{'I','l'},{'L','l'} };
    check.checkBool(true, o.matchReplacement("lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllf", "11LtiiItLI11I11LIL1tt1tLL1I1iL1LI1iLLtii11titL1IittIItitt1itLt1II1IiiL1i1ittIIL1IIIi1IItii1Li1tt11L1i1i1L1t1iLii1iILtItLitItLLLLti1i1Itttt1LtLIL1Lit11IIL1tIILtiL1iLiItLtLLtiiIiitt1LiIitLIIIitIiitLLiti1tt1iILILiiIiIttI111I11iIiLtiiiI1ILIii1t11ILLI1IitLt1LIiItLLtLItIiL111t1LttiLttL1tLi1iI1tILILIiiIIt11tLtLi1IItitiitIt1LttitLL1ILLLIIILi11tLL1IItI1L1iI1111ttLLLLILitLIiILItItiiii11itIiiIIii1iittiiiLLIIiILIiLI1tiL1L11tI11iLtIi1iIIItII1tIiI1iLLLItiL1ILit1LtI1t1iLti111LttiILiiiiI1LIItI111L11IItIIti1LII1ILILiitL1iLIt1ttIit11tItIII1I1L1tI1iLiLitttI11ittiti1ItI11L11IttLiii1IIILt1LLIiILIL1IiL1ILI1tt1i111IiiLLiLIL1LILLLLI11t1L1Li1i1tttIII1i1t1IIitItiLtL1iLLI11LI1iI1IILIiILttiIt1itIItL1LLILLtiii1tLIItIIt1tiIit1t1iLiiIIiiIIt1ILL1tiit11IILtI1iLLiIIi1LiI1LILiiLitLLttLLtLIiLiiIiI1IILLLLLLL1LtILLItiLLIi1LiIIttII11ILItIIi1L1iiLItt11tiIItLi1tIIILILI111LtItiIL1tiLILLIiiLILLLiLLtt1iIii1IIIItLtIIiL1Ii1tLtitiiiLIIt1tLii1L1I1ii11it1I1itLLiLLLIL1LL1t1LtLLtiIItII1iIII1LLtLI11LttLL1Li1tIIIi1I11Lt1LitIIiiiLtiIii1I1iiitI1IIiLIL11111ILI1IitIIiiiLtIItLtt1i111IiL1i1L1L1IiI111t11itLiLttLiiittittL1Li11ILi11IILtt1L1i1itiIII1tLtiIIIi1tIiIIi1ttiiL11I1tiit1tiitLi11iiL111iIiLItt1L1tt1L1iLt1LLtiii1tt1i1ttt1LLLL1ILItILiiL1LitttiIL1IititLiit11iitLiit11t1iLtiL11tL1ttLL1ILItiL1Ltt1iL1tLtLiLI1IiIL1i1ItiiL1I111LIiiiI1i11tiIiiiLiiiI1tLIIIiLti1iitiitit1L11LitLIi1LitIIi1111ItILiitLiiILt1iItILLi111iiiiIIiiit1ttii1t111Iii1LIi1ILi1Li1iLttIiitiiii1t1ii1IiIittIIIiiLtiLt1L11L1iIItIiiitL1I1ti1iL11Lt1tL11i1ttiLi1LLI1tIi11LL1tLLtii1iIiLiItLLLIi1tiI1i11LLItLtiLtLLi11ittLIiIiLLt1tiI1iitIIIi1I11I1LILI1it11t1Li1tt1ILIitI1iIit1IILiIIitL11iiiLLtItitILL1LIIi1tIII11iIIItIItttL1IIItLLtL1iIIiIiLtiiIL1IIIiL11I1I11itLLiitItLittItLittILiLII1iLi1IILILt1L1iILLILI1LiLILiLtiI1iLtI1Li1tiiIt1itIL1ttLi1LtiiLLittttLIL1tt1LtIL11it1L1LILLi1LtLL1iILtLLLIi11LtiLIIiLtLI1IitIIIL1LiIIL11iLI1iti1LLL1ttLIiit1L1iiLiiitLtit1i1ILLItLIt1tttL1Ii1Itt1ItIti1iILii1iLI1ttItiiItitiL1Iiiii11IitILiLILIit1ILittLLiIii11tItLLL1IL1tL1IiLtLI11iLLiiIL1L1iL1LiiIII1it1I1i1tti11LtLLLI1IL1L111IIILi1iL1it11LLLIItLIIILiLt111ti1it1ttI1tLIII1iL1Ltt11IttiLILiI11It1LttIi1Lii1L1It1iIi1iILIiitLII11tt1iIit1t11iI1ItiitLiIILLILLt1t1ttii1it1tit1III1IiLtII1i1t1i1LL1Iti1I1IILIL1LLiiii1t1LiL1tIiIiiIIIiI11Lt1it1tiLItiitiiiiii1tILL1LI11tLIL1I111ItiILI1ii1L1ILtL1LLIiLItIIIILi11LLiILttt11LtLtLItLLi1L11iI1Liit1Lt11iLt1tt1iIIiIIitLtit1LItti1iit1itL1i1iIL1tI1t1tLtti1It1LLtLLtt1It1iiILiIt111LLi11LItL1LLittIiLi1I1IIIL1IiIii11t1itiitLiiIIItLLLtiLtti1I111Iii11tiLIt1iL1ItL1tittiLi1tILI1LtitLf", mappings));

    mappings = { {'o','0'} };
    check.checkBool(false, o.matchReplacement("fooleetbar", "f00l", mappings));
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
