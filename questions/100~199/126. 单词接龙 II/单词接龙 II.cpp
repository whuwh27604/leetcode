/* 单词接龙 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换后得到的单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> wordMap;
        vector2Map(wordList, wordMap);

        if (wordMap.count(beginWord) == 0) {  // 如果beginWord不在字典里面，把它放进去
            wordMap.insert({ beginWord, wordList.size() });
            wordList.push_back(beginWord);
        }

        if (wordMap.count(endWord) == 0) {  // 如果endWord不在字典里面，则无法完成转换
            return {};
        }

        vector<vector<int>> transforTable(wordList.size());
        getTransforTable(wordList, wordMap, transforTable);  // 构建转移表

        vector<vector<string>> shortestPaths;
        bfs(wordList, wordMap[beginWord], wordMap[endWord], transforTable, shortestPaths);

        return shortestPaths;
    }

    void vector2Map(vector<string>& wordList, unordered_map<string, int>& wordMap) {
        for (int i = 0; i < (int)wordList.size(); ++i) {
            wordMap.insert({ wordList[i], i });
        }
    }

    void getTransforTable(vector<string>& wordList, unordered_map<string, int>& wordMap, vector<vector<int>>& transforTable) {
        if (wordList[0].size() * 26 < wordList.size() / 2) {
            transfor1(wordMap, transforTable);  // 单词太多，尝试改变一个字符，看转变后的单词是否在列表中
        }
        else {
            transfor2(wordList, transforTable);  // 单词较少，直接遍历单词对，看是否能够转换
        }
    }

    void transfor1(unordered_map<string, int>& wordMap, vector<vector<int>>& transforTable) {
        for (auto iter = wordMap.begin(); iter != wordMap.end(); ++iter) {
            const string& word = iter->first;
            string tmp = word;

            for (int i = 0; i < (int)word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[i] == c) {
                        continue;
                    }

                    tmp[i] = c;
                    auto it = wordMap.find(tmp);
                    if (it != wordMap.end()) {
                        transforTable[iter->second].push_back(it->second);
                    }
                }

                tmp[i] = word[i];
            }
        }
    }

    void transfor2(vector<string>& wordList, vector<vector<int>>& transforTable) {
        int i, j, size = wordList.size(), wordSize = wordList[0].size();

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (canTransfor(wordList[i], wordList[j])) {
                    transforTable[i].push_back(j);
                    transforTable[j].push_back(i);
                }
            }
        }
    }

    bool canTransfor(string& word1, string& word2) {
        int diff = 0;

        for (unsigned int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                if (++diff > 1) {
                    return false;
                }
            }
        }

        return true;
    }

    void bfs(vector<string>& wordList, int start, int end, vector<vector<int>>& transforTable, vector<vector<string>>& shortestPaths) {
        int steps = 0;
        vector<int> distance(wordList.size(), INT_MAX);
        distance[start] = 0;
        queue<vector<int>> paths;
        paths.push({ start });

        while (!paths.empty()) {
            if (!shortestPaths.empty()) {
                return;
            }

            int i, size = paths.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                vector<int> path = paths.front();
                paths.pop();

                if (path.back() == end) {
                    getPath(wordList, path, shortestPaths);
                    continue;
                }

                for (int next : transforTable[path.back()]) {
                    if (steps <= distance[next]) {  // 花费更多的步骤到达同一个单词，肯定不会是最短路径
                        distance[next] = steps;
                        path.push_back(next);
                        paths.push(path);
                        path.pop_back();
                    }
                }
            }
        }
    }

    void getPath(vector<string>& wordList, vector<int>& path, vector<vector<string>>& shortestPaths) {
        shortestPaths.push_back({});

        for (int index : path) {
            shortestPaths.back().push_back(wordList[index]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    vector<vector<string>> actual = o.findLadders("hit", "cog", wordList);
    vector<vector<string>> expected = { {"hit","hot","dot","dog","cog"},{"hit","hot","lot","log","cog"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    wordList = { "hot","dot","dog","lot","log" };
    actual = o.findLadders("hit", "cog", wordList);
    expected = {  };
    check.checkStringVectorRandomOrderVector(expected, actual);

    wordList = { "hot","dog","dot" };
    actual = o.findLadders("hot", "dog", wordList);
    expected = { {"hot","dot","dog"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    wordList = { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" };
    actual = o.findLadders("qa", "sq", wordList);
    expected = { {"qa","ba","be","se","sq"},{"qa","ba","bi","si","sq"},{"qa","ba","br","sr","sq"},{"qa","ca","ci","si","sq"},{"qa","ca","cm","sm","sq"},{"qa","ca","co","so","sq"},{"qa","ca","cr","sr","sq"},{"qa","fa","fe","se","sq"},{"qa","fa","fm","sm","sq"},{"qa","fa","fr","sr","sq"},{"qa","ga","ge","se","sq"},{"qa","ga","go","so","sq"},{"qa","ha","he","se","sq"},{"qa","ha","hi","si","sq"},{"qa","ha","ho","so","sq"},{"qa","la","le","se","sq"},{"qa","la","li","si","sq"},{"qa","la","ln","sn","sq"},{"qa","la","lo","so","sq"},{"qa","la","lr","sr","sq"},{"qa","la","lt","st","sq"},{"qa","ma","mb","sb","sq"},{"qa","ma","me","se","sq"},{"qa","ma","mi","si","sq"},{"qa","ma","mn","sn","sq"},{"qa","ma","mo","so","sq"},{"qa","ma","mr","sr","sq"},{"qa","ma","mt","st","sq"},{"qa","na","nb","sb","sq"},{"qa","na","ne","se","sq"},{"qa","na","ni","si","sq"},{"qa","na","no","so","sq"},{"qa","pa","pb","sb","sq"},{"qa","pa","ph","sh","sq"},{"qa","pa","pi","si","sq"},{"qa","pa","pm","sm","sq"},{"qa","pa","po","so","sq"},{"qa","pa","pt","st","sq"},{"qa","ra","rb","sb","sq"},{"qa","ra","re","se","sq"},{"qa","ra","rh","sh","sq"},{"qa","ra","rn","sn","sq"},{"qa","ta","tb","sb","sq"},{"qa","ta","tc","sc","sq"},{"qa","ta","th","sh","sq"},{"qa","ta","ti","si","sq"},{"qa","ta","tm","sm","sq"},{"qa","ta","to","so","sq"},{"qa","ya","yb","sb","sq"},{"qa","ya","ye","se","sq"},{"qa","ya","yo","so","sq"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    wordList = { "lest","leet","lose","code","lode","robe","lost" };
    actual = o.findLadders("leet", "code", wordList);
    expected = { {"leet","lest","lost","lose","lode","code"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    wordList = { "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob" };
    actual = o.findLadders("cet", "ism", wordList);
    expected = { {"cet","get","gee","gte","ate","ats","its","ito","ibo","ibm","ism"},{"cet","cat","can","ian","inn","ins","its","ito","ibo","ibm","ism"},{"cet","cot","con","ion","inn","ins","its","ito","ibo","ibm","ism"} };
    check.checkStringVectorRandomOrderVector(expected, actual);
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
