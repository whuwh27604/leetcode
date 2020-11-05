/* 单词接龙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        vector2set(wordList, words);

        queue<string> bfs;
        bfs.push(beginWord);
        int wordLen = endWord.size(), transforLen = 0;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++transforLen;

            for (i = 0; i < size; ++i) {
                if (bfs.front() == endWord) {
                    return transforLen;
                }

                if (wordLen * 26 < (int)words.size()) {
                    transfor1(bfs, words);
                }
                else {
                    transfor2(bfs, words);
                }

                bfs.pop();
            }
        }

        return 0;
    }

    void vector2set(vector<string>& wordList, unordered_set<string>& words) {
        for (string& word : wordList) {
            words.insert({ word, word });
        }
    }

    void transfor1(queue<string>& bfs, unordered_set<string>& words) {
        string word = bfs.front();

        for (unsigned int i = 0; i < word.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == bfs.front()[i]) {
                    continue;
                }

                word[i] = c;
                if (words.count(word) != 0) {
                    bfs.push(word);
                    words.erase(word);
                }
            }

            word[i] = bfs.front()[i];
        }
    }

    void transfor2(queue<string>& bfs, unordered_set<string>& words) {
        auto iter = words.begin();
        while (iter != words.end()) {
            if (canTransfor(bfs.front(), *iter)) {
                bfs.push(*iter);
                iter = words.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    bool canTransfor(const string& s1, const string& s2) {
        int diff = 0;

        for (unsigned int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (++diff > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    check.checkInt(5, o.ladderLength("hit", "cog", wordList));

    wordList = { "hit","hot","dot","dog","lot","log","cog" };
    check.checkInt(5, o.ladderLength("hit", "cog", wordList));

    wordList = { "hot","dot","dog","lot","log","cog" };
    check.checkInt(1, o.ladderLength("cog", "cog", wordList));

    wordList = { "hot","dot","dog","lot","log","cog" };
    check.checkInt(1, o.ladderLength("ccc", "ccc", wordList));

    wordList = { "hot","dot","dog","lot","log" };
    check.checkInt(0, o.ladderLength("hit", "cog", wordList));

    wordList = { "a","b","c" };
    check.checkInt(2, o.ladderLength("a", "c", wordList));

    wordList = { "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob" };
    check.checkInt(11, o.ladderLength("cet", "ism", wordList));
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
