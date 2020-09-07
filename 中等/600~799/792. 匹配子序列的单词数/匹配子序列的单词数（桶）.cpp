/* 匹配子序列的单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定字符串 S 和单词字典 words, 求 words[i] 中是 S 的子序列的单词个数。

示例:
输入:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
输出: 3
解释: 有三个是 S 的子序列的单词: "a", "acd", "ace"。
注意:

所有在words和 S 里的单词都只由小写字母组成。
S 的长度在 [1, 50000]。
words 的长度在 [1, 5000]。
words[i]的长度在[1, 50]。
通过次数5,311提交次数12,408

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-matching-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int i, size = words.size(), count = 0;
        vector<list<pair<int, int>>> buckets(26, list<pair<int, int>>{});

        for (i = 0; i < size; i++) {
            buckets[words[i][0] - 'a'].push_back({i, 0});  // pair<int, int>记录words中的第first个word，匹配到了第second个字符
        }

        for (char c : S) {
            int j, sameFirstWordsSize = buckets[c - 'a'].size();

            for (j = 0; j < sameFirstWordsSize; j++) {
                pair<int, int>& word = buckets[c - 'a'].front();
                if (word.second + 1 == words[word.first].size()) {
                    count++;
                }
                else {  // 匹配上的index加一，放入新的bucket
                    buckets[words[word.first][word.second + 1] - 'a'].push_back({ word.first, word.second + 1 });
                }

                buckets[c - 'a'].pop_front();  // 从老的bucket删除
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "a","bb","acd","ace" };
    check.checkInt(3, o.numMatchingSubseq("abcde", words));

    words = { "fxxxbzg","cfxxxbz" };
    check.checkInt(2, o.numMatchingSubseq("cfxxxbzg", words));

    words = { "a" };
    check.checkInt(1, o.numMatchingSubseq("abcde", words));

    words = { "x" };
    check.checkInt(0, o.numMatchingSubseq("abcde", words));

    words = { "ykbkihjdfxxxwragzcbhngbzgasxysxdtwn" };
    check.checkInt(1, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "wxakdcovjeczhqvbevkhlixsrhumxykbkihj" };
    check.checkInt(1, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "diht" };
    check.checkInt(1, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "covjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbz" };
    check.checkInt(1, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "ovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhng" };
    check.checkInt(1, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "ykbkihjdfxxxwragzcbhngbzgasxysxdtwn","wxakdcovjeczhqvbevkhlixsrhumxykbkihj","diht","covjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbz","ovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhng" };
    check.checkInt(5, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "ykbkihjdfxxxwragzcbhngbzgasxysxdtwn","wxakdcovjeczhqvbevkhlixsrhumxykbkihj","diht","covjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbz","ovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhng","qhzucvqxalfrtlrdjverseuldzymzbunhugekoyyghmkpkfqmd","eydmbsorvjnnifqxsyuypsrijzrosukrhtbneprpyyoawbvoki","uanfzlfmmtvhzzebrazyuslbapsfzwtlvqbhqxsfmqagwxetro","fffaawedchlcyqvzzxbzczbwyfjkllpsjhoozyresqemmawban","astrknwzefcmuswdxalooatmiduspjuofthtomoqilgdojwhon" };
    check.checkInt(5, o.numMatchingSubseq("kguhsugfxvwxakdcovjeczhqvbevkhlixsrhumxykbkihjdfxxxwragzcbhngbzgasxysxdtwntvbpdihtvkffacmxhbxxqniyqm", words));

    words = { "ddeoincygycdpeh","yznmojdhbeomyjqptltpugzceyzenflfnhrptuug","ejuisks","teiqyligsnbqglqblhpdzzeurtdohdcbjvzgjwylmmoi","mrwnxhaqfezeeabuacyswollycgio","qfskkpfakjretogrokmxemjjbvgmmqrfdxlkfvycwalbdeumav","wjgjhlrpvhqozvvkifhftnfqcfjmmzhtxsoqbeduqmnpvimagq","ibxhtobuolmllbasaxlanjgalgmbjuxmqpadllryaobcucdeqc","ydlddogzvzttizzzjohfsenatvbpngarutztgdqczkzoenbxzv","rmsakibpprdrttycxglfgtjlifznnnlkgjqseguijfctrcahbb","pqquuarnoybphojyoyizhuyjfgwdlzcmkdbdqzatgmabhnpuyh" };
    check.checkInt(5, o.numMatchingSubseq("ricogwqznwxxcpueelcobbbkuvxxrvgyehsudccpsnuxpcqobtvwkuvsubiidjtccoqvuahijyefbpqhbejuisksutsowhufsygtwteiqyligsnbqglqblhpdzzeurtdohdcbjvzgjwylmmoiundjscnlhbrhookmioxqighkxfugpeekgtdofwzemelpyjsdeeppapjoliqlhbrbghqjezzaxuwyrbczodtrhsvnaxhcjiyiphbglyolnswlvtlbmkrsurrcsgdzutwgjofowhryrubnxkahocqjzwwagqidjhwbunvlchojtbvnzdzqpvrazfcxtvhkruvuturdicnucvndigovkzrqiyastqpmfmuouycodvsyjajekhvyjyrydhxkdhffyytldcdlxqbaszbuxsacqwqnhrewhagldzhryzdmmrwnxhaqfezeeabuacyswollycgiowuuudrgzmwnxaezuqlsfvchjfloczlwbefksxsbanrektvibbwxnokzkhndmdhweyeycamjeplecewpnpbshhidnzwopdjuwbecarkgapyjfgmanuavzrxricbgagblomyseyvoeurekqjyljosvbneofjzxtaizjypbcxnbfeibrfjwyjqrisuybfxpvqywqjdlyznmojdhbeomyjqptltpugzceyzenflfnhrptuugyfsghluythksqhmxlmggtcbdddeoincygycdpehteiugqbptyqbvokpwovbnplshnzafunqglnpjvwddvdlmjjyzmwwxzjckmaptilrbfpjxiarmwalhbdjiwbaknvcqovwcqiekzfskpbhgxpyomekqvzpqyirelpadooxjhsyxjkfqavbaoqqvvknqryhotjritrkvdveyapjfsfzenfpuazdrfdofhudqbfnzxnvpluwicurrtshyvevkriudayyysepzqfgqwhgobwyhxltligahroyshfndydvffd", words));

    words = { "wpddkvbnn","lnagtva","kvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvju","rwpddkvbnnugln","gloeofnpjqlkdsqvruvabjrikfwronbrdyyj","vbgeinupkvgmgxeaaiuiyojmoqkahwvbpwugdainxciedbdkos","mspuhbykmmumtveoighlcgpcapzczomshiblnvhjzqjlfkpina","rgmliajkiknongrofpugfgajedxicdhxinzjakwnifvxwlokip","fhepktaipapyrbylskxddypwmuuxyoivcewzrdwwlrlhqwzikq","qatithxifaaiwyszlkgoljzkkweqkjjzvymedvclfxwcezqebx" };
    check.checkInt(5, o.numMatchingSubseq("rwpddkvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvjubjgloeofnpjqlkdsqvruvabjrikfwronbrdyyjnakstqjac", words));
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
