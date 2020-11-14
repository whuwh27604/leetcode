/* 最长字符串链.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个单词列表，其中每个单词都由小写英文字母组成。

如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。

词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。

从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。
 

示例：

输入：["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] 仅由小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-string-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_map<string*, int>> sameLenWords(17, unordered_map<string*, int>{});
        catalog(words, sameLenWords);

        /* dp[i]表示以words[i]为结尾的chain的长度，则dp[i]=max(dp[x])+1，x是所有可以和words[i]构成chain的前一个word */
        vector<int> dp(words.size(), 0);
        int index = init(sameLenWords, dp);
        checkAllChains(sameLenWords, index, dp);

        return getLongestChain(dp);
    }

    void catalog(vector<string>& words, vector<unordered_map<string*, int>>& sameLenWords) {
        for (int i = 0; i < (int)words.size(); ++i) {
            sameLenWords[words[i].size()].insert({ &words[i], i });
        }
    }

    int init(vector<unordered_map<string*, int>>& sameLenWords, vector<int>& dp) {
        int i, size = sameLenWords.size();

        for (i = 1; i < size; ++i) {
            if (!sameLenWords[i].empty()) {
                for (auto iter = sameLenWords[i].begin(); iter != sameLenWords[i].end(); ++iter) {
                    dp[iter->second] = 1;
                }
                break;
            }
        }

        return i;
    }

    void checkAllChains(vector<unordered_map<string*, int>>& sameLenWords, int start, vector<int>& dp) {
        for (int i = start; i < (int)sameLenWords.size() - 1; ++i) {
            checkChain(sameLenWords[i], sameLenWords[i + 1], dp);
        }
    }

    void checkChain(unordered_map<string*, int>& current, unordered_map<string*, int>& next, vector<int>& dp) {
        for (auto itN = next.begin(); itN != next.end(); ++itN) {
            int chainLen = 0;

            for (auto itC = current.begin(); itC != current.end(); ++itC) {
                if (isChain(*itC->first, *itN->first)) {
                    chainLen = max(chainLen, dp[itC->second]);
                }
            }

            dp[itN->second] = chainLen + 1;
        }
    }

    bool isChain(string& current, string& next) {
        int forward, backward, i, size = current.size();

        for (forward = 0, i = 0; forward < size; ++forward, ++i) {
            if (current[forward] != next[i]) {
                break;
            }
        }

        for (backward = size - 1, i = size; backward >= forward; --backward, --i) {
            if (current[backward] != next[i]) {
                return false;
            }
        }

        return true;
    }

    int getLongestChain(vector<int>& dp) {
        int longestChain = 0;

        for (int len : dp) {
            longestChain = max(longestChain, len);
        }

        return longestChain;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    check.checkInt(4, o.longestStrChain(words));

    words = { "a","b","ba","bca","bda","bdca","bdace" };
    check.checkInt(4, o.longestStrChain(words));

    words = { "sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz" };
    check.checkInt(6, o.longestStrChain(words));

    words = { "kwigbkfeqp","tpiufntqzo","blmwegckaplqwjpo","uiesdrhcbvbbk","przuvuo","kntmjgnqbxlwh","glac","uz","qqhw","gdtunmaw","neymepxl","eqtxh","qz","bek","xgadqztq","cicgtxs","grakdthb","kwigbkfeqop","uqyqhjqwegizcx","kewiygbkfejqop","tufntz","gulamac","sluiobdm","ujdyugagn","fuyz","eth","vzxiobwgyhrdkh","ikfjaivyvreql","jimpyin","cuotmvfqzizu","tkopssxh","gmwmzsowjf","nel","zo","kntmmjgnqbxtlwh","cyuicglbdtxwsu","vjrenjwntklm","uevrxuklobce","tkaopssxh","rwkedydnadd","uqyqhjqdwegizcx","ouethhse","zcmmrtilpti","tmfuxxyk","honyw","nyepl","qqhqwix","mjhg","gdtwunmaw","kigbkfeqp","wnyhsm","oeqatxhree","qyqhjqweizcx","xadqztq","wqnyghsmt","ndozeaylmetnpxlj","przuvuhob","wqnlyghnqsmtt","tkossxh","qyqhjqwix","epwcjxytvt","bexk","ga","em","zojodbw","gulmac","cizocgw","suibdm","nvcyutywhus","bwjofkuchx","f","pdtwv","dzohajcodbw","kuc","tpawplvfzlx","mg","re","oh","wciqob","el","wciqo","mftmgv","grakkdthtbd","cnbnyvuhmrj","odqphbhkf","oeqatxhre","sqzrlhs","bwsjofvkuptchx","xdqztq","tmv","kewigbkfejqop","faepomn","bdwwnalubrvxtdgu","cotmfqziz","lvzl","dmqz","hdmqz","gdigs","ujdyugag","mepjqbuvdku","g","kigbkeqp","oegqataxhree","zscinzobcgtwdwhn","fuaepwobimn","qf","cusotmvfqziknzu","qvroffuk","rweydnadd","zoow","meqcfzkbnrb","tpaplvzlx","zscinzocgwdwhn","zcmmrtilpt","ndeaymenpxlj","jimpn","wofkuchx","tkaopsssxh","vodwqphbhkfx","faepwoimn","gzenkasrciui","nyhm","tpufntqzo","ovqeyvxfdll","tufntzo","gmyrmf","vxobwgrdkh","faepwobimn","przujvuhobk","vzxobwgyrdkh","ksszdumgko","kewiylgbkfejqop","rey","vo","qqfe","moyddffrwwyzk","qzwsbnuejvsi","vodwqpzhbhjkfx","r","vttpoelti","sqzrlehhs","tpiuftntqzo","qfe","qyvsrofgnfuk","evxuklce","wiqo","prpzuujvuaxhkobk","gy","vnjxkjvmz","qroffuk","qqhwi","przuvuhobk","mfttmgvj","moydfrwzk","jibmpuyin","pwcytvt","eqtxhre","gcdtwunmaw","wfkucx","ryedhy","vttpolti","qyqhqwix","kutkavldvvqvp","el","tmfuxxyku","tplvzlx","gdtu","z","ksg","xmgadqzptq","qcqfre","zcmmrtiklpti","hobxltexk","vburq","funyz","kc","vjrenjwntklqm","wqnlyghnqsmt","sibdm","vodwqpzhbhkfx","zsnv","pouegzfyk","arci","vzxobwgyhrdkh","fetoesaot","riyedhy","cyuicgtxsu","gdtua","gchdtwgwunmaw","cuotmvfqziz","obltexk","epwcytvt","scinzocgw","ptwv","jimpuyin","uevrxukloce","tkqaopsssxh","pdtwdv","fetsaot","cyuicgldtxsu","przujvuaxhkobk","wciqoxb","gdtuna","lvzlx","ytpawcplvfzlx","uyugag","ksszdumugiko","bm","pgdmigs","grakdthtbd","uyz","zscinzobcgwdwhn","oeqataxhree","qzsbnuvs","gznkarciui","zoodw","jimpin","tqksugh","zuvo","tmgv","gdmigs","sluibdm","nvcxyzwyutywhus","bwsjofkuchx","fetsat","kgbeqp","neymenpxlj","vzxobwgrdkh","tpawcplvfzlx","qbzwsbnuejvsi","przuvuho","wqnlyguhnqsmtt","ujhadylujgaazgsn","axuelrnnnwhg","qbzwsbnuejvsmoi","qzsbnuvsi","yugag","bwsjofvkupchx","mqz","gchdtwunmaw","kntmmjgnqbxlwh","xfpt","vvburq","moydfrwk","qksgh","faepoimn","odwqphbhkfx","ryey","gchdtwwunmaw","uiesdrhcvbbk","qyqhjqwicx","yilxbltwwxh","jrenjwntkm","gzenkarciui","moyddffrhwwyezk","tqksugvhr","oveyvxfl","agmyrmf","scinzocgwdn","neymenpxl","gonpxzngjv","rwkeydnadd","zohjodbw","bdwwnalubvxtdgu","jrenjwntk","ovqheyvxubfdtll","qcqfqrezof","znkarcii","b","qzsnuvs","ndzeaylmenpxlj","tossxh","fetsa","przujvuxhkobk","ovqeyvxubfdll","tpufntzo","cuicgtxs","mv","vbur","moyddffrhwwyzk","yilxcbltwwxh","eqtxhe","zow","qbzwsbnuejvsoi","nvczwyutywhus","cyquicglbdtxwsu","evxukce","axuelrnnwhg","aci","ouemthhqse","wfkuchx","bwsjofvkmuptchx","mfjhg","bwsjofvkuchx","qffu","qyqhjqwegizcx","rzuvuo","uvo","qh","qvsrofgfuk","neymepl","mepjqybuvdku","sqzrlehs","cnbnyvumrj","qcqfqrezoif","gyrm","przujvuhkobk","cuotmvfqzinzu","gym","ujdylujgaagn","thdmmqz","honw","odwqphbhkf","ksszgko","qbzwsbnuejvsmvoi","m","gtu","qyvsrofgfuk","uqqyqhjqdwegizcx","obtexk","hobltexk","ftmgv","bwsjofvkmuptchxy","taynfxo","tqksugvhrc","jibmpduyin","vxue","zuvuo","gonpxzngv","gmpwamzsowjf","rwednadd","zv","tosh","pqdtwdv","zcmmrtsiklpti","tkqaopesssxh","ovqeyvxbfdll","gac","gsqzrlehhs","znv","cuotmvfqziknzu","ryedy","vnjoxkjvmz","pouegnzfyk","evrxuklce","ujdyujgagn","tmfnuxxyku","semj","xmgadvqzptq","cnnyvmrj","gonpxzvngjv","meqczkbnrb","bwofkuchx","fuvnyz","znarci","moydffrwzk","kwigbkfejqop","wqnyghnsmt","uiesdrehcbvobbk","qcqfreo","zohajodbw","nvcxyzwyutywhuhs","scinzocgwdwn","ksyszdumugiko","qfu","mjg","zsnuvs","eqth","ccgtxs","pgdmidtgs","rwednad","lel","cusotmvfqzwiknzu","znkarciui","o","qzsbnuevsi","veodwqpzhbhjkfx","jrenjwntklm","gmwamzsowjf","ndeymenpxlj","moydffrwwzk","nvczyutywhus","dzohajodbw","ujadylujgaazgsn","nvcytywhus","qcqfrezo","mfttmgv","tqksugvh","qksg","njxkjvmz","udyugag","qffuk","ksszdugko","wkuc","tmfxxyk","qqh","sbdm","rwedna","ovqheyvxubsfdtll","ndzeaymenpxlj","neyepl","qf","xgadqzptq","redna","pougzfyk","zarci","mftbtmgvj","taplvzlx","uiesdrhcbvobbk","ovqeyvxfdl","qcqfrezof","qvrofgfuk","scizocgw","mftbtmgvdj","rsgwmsted","ovqheyvxubfdll","oveyvxfdl","m","wi","znkarci","ikfjaivyvrql","pgdmidgs","btexk","cuotmfqziz","xdqzq","jimp","qqhqwi","lvz","ilojawyersju","wnyhm","gsqzrlenhhs","bu","wkucx","bdm","lsel","tpawplvzlx","ai","kntmmjognqbxtlwh","hkonyw","vxuce","zsnvs","qyqhjqweicx","nyel","cyuicgtxs","qzsbnuejvsi","ujadylujgaagsn","thdmqz","ilojawyersu","uevirxuklobce","qrffuk","zoodbw","sem","cyuicgldtxwsu","wnyhsmt","prpzujvuaxhkobk","uesdrhcvbbk","vhvburq","ndzeaylmetnpxlj","ksszdgko","scinzocgwd","cyuicgltxsu","ptw","mplaxm","scinzocgwdwhn","ytpawcplvifzlx","evxuce","bur","kigbeqp","ksszdumugko","cnnyvumrj","toh","kewiylgbkfejqfop","gulac","pugzfyk","nvcyzwyutywhus","ouemthhse","wqnyghnqsmt","b","ujdylujgagn","tlvzlx","pgidmidtgs","eqatxhre","gmyrm","dqzq","oveyvxl","vttpoeltci","gk","wqnyhsmt","zcmmrtsitklpti","iaxuelrnnnwhg","gdtunma","ujadylujgaagn","tqksgh","moydffrwwyzk","mfftbtmgvdj","wio","fetosaot","grakdthtb","nxmrvm","evrxukloce","ikfjaivyrql","tosxh","grakkbdthtbd","epwcxytvt","blmwegckaplwjpo","qcqfe" };
    check.checkInt(16, o.longestStrChain(words));

    words = { "a" };
    check.checkInt(1, o.longestStrChain(words));

    words = { "qyssedya","pabouk","mjwdrbqwp","vylodpmwp","nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw","qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa","qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr" };
    check.checkInt(8, o.longestStrChain(words));

    words = { "uiykgmcc","jrgbss","mhkqodcpy","lkj","bwqktun","s","nrctyzifwytjblwy","wrp","scqlcwmxw","irqvnxdcxoejuu","gmlckvofwyifmrw","wbzbyrcppaljigvo","lk","kfeouqyyrer","efzzpvi","ubkcitcmwxk","txihn","mdwdmbtx","vuzvcoaif","jwmboqvhpqodsj","wscfvrfl","pzye","waxyoxftvrgqmkg","wwdidopozinxxn","dclpg","xjsvlxktxs","ajj","pvsdastm","tatjxhygidhn","feafycxdxagn","irqvnxxoeuu","kwjo","tztoovsyfwz","prllrw","sclmx","bbmjnwaxcwaml","gl","wiax","uzvcoaif","ztovyfwz","qxy","zuexoxyp","qxyyrl","pvsdasvtm","femafycxdxaagn","rspvccjcm","wvyiax","vst","efzi","fjmdcc","icsinrbpql","ctybiizlcr","ntyzfwytjblw","tatjxhygidhpn","e","kykizdandafusu","pnepuwcsxl","kfeuqyyrer","afplzhbqguu","hvajtj","prll","ildzdimea","zueoxp","ezi","lqr","jkaagljikwamaqvf","mlzwhkxsn","rspvccbcjjtcm","wscfvrl","m","msygukwlkrqboc","pifojogoveub","bkcmwx","jercgybhss","wrpi","aicsinkgrbpqli","aplzbuu","sclcmxw","atpepgsz","govrcuuglaer","bdxjpsvlxkytxs","uikgm","bm","wvyhiqax","znvaasgfvqi","hatpepgsz","hrzebpa","bnfz","lybtqrfzw","taxhygihn","bjnfzk","mhqp","ide","znvcaasgfvqi","ftv","afplzhbqsguuu","thn","pdbccbe","mxevopfoimgjww","fjmdrcce","rspvccjjcm","jv","motnfwohwule","xjsvlxtxs","bqeb","eug","jftavwgl","rzebpa","lybtqrfazw","zuexoxp","jercgybhsys","hajtj","bkcitcmwxk","mbpvxsdastvtm","mowlznwhkxsn","dvenn","rsacxe","tatjxhygihn","cotybiizlcr","bbmnaxaml","pkwrpsi","nqpdbccbkxens","mbpbovxsdastvtm","mj","pxpsvikwekuq","qeug","dmelddga","aicsinkgrbpxqli","bdxjpsvlxktytxs","pkrllrxw","jkgljikwmaqf","iddie","ctybiizcr","nyzfwytjblw","yvuhmiuehspi","keuqre","wzbypaigvo","sck","uzcoaf","dlpg","ubkcpitlscmwxk","molzwhkxsn","pepuwcsxl","laplm","dclpgc","mahkxqodcpy","sclcmx","hvrzebpaz","bgovrcuuglaer","clazpulmw","yvuyhmiuehspiq","wzbycpaljigvo","sceqalciwmxw","hjytflmvsgv","u","hjyvxytfflhmvsgv","jkgjikwmaqf","fefycxdxagn","ftvw","ofncgxrkqvcr","spvcjc","pvsdastvtm","kykzdandaus","wbzbycppaljigvo","haytpepgsz","jmowlznwhkxsn","aplzhbguu","zvyz","nfvqi","jfvtavwsgl","xejnllhfulns","zhhvbiqiw","jkgljikwmaqvf","tyizc","irqvnxcxoejuu","clvazzpulmw","oncgxrqvcr","qlupvpdkhrm","mtnfwohwule","wwdidopzozinxxn","auiykgmcc","wscfvrfyl","pfksmrullrxw","jwmoqvhpqods","ftavwg","iddiea","kcmw","ykkwjwo","pe","aplzbguu","eu","bbmnaxal","ntyswtnlab","zhhhvbhbiqiw","jwmoqvpqods","kykzdndaus","bbmjnaxcwaml","zunvcaasgfvqi","icsingrbpql","sceqalciwmsxyw","yvuhmiuehsp","bxjsvlxktxs","waxoxftvrgqmkg","cogxxpaknks","scllvazzpulmw","tatjxhygeidhpn","ftvwg","tyz","nafvqi","oby","pgzpkhqog","irqvnxxoejuu","oxwpkxlakcp","bnf","oxwnpkxlakcp","bwqktu","ufybbaozoqk","ntydswtnlab","zvyfz","znaafvqi","npdbccbke","mhkqocpy","kuq","bjnfz","taxhyihn","kwrpsi","qifepmcatbdjlf","lzwhks","kfeuqre","mxevopfoimgww","spvcjcm","oncgxrkqvcr","jftavwsgl","soifcbya","jpzyeg","jwmboqvhpqods","lapulm","jrgbhss","xejfnllhfulns","zhhhvbbiqiw","km","kuqre","scxlzlvazzpulmw","ztvyfwz","wbzbycpaljigvo","rzbpa","vsastm","uybaooqk","dn","ykwjwo","ufybmvbaozoqk","nknm","mbpvsdastvtm","dpgzpxykhqog","wzbypajigvo","bnjnfzk","eollbigtftpdrd","zhbiqiw","yvuhiuehp","zhhhvbhbiqiwg","pfksrullrxw","pzyeg","aplzhbqguu","z","hvrzecbpazw","clvazpulmw","tajxhygihn","pgzpxykhqog","fefyxdxagn","wimomuvhn","lqrzw","xejnlhfulns","jhrc","xsxxs","slmx","jrgss","uikgmc","ncgqvcr","womuhn","aryouvtnmme","uzco","zhhhvbiqiw","hjytflhmvsgv","znvaasfvqi","kuqr","ojrpp","ztoovyfwz","zvz","pxpsviweuq","ufybaooqk","xy","jfvvtavwksvgl","raiachv","bmnaxl","rspvccjjtcm","pgzpxkhqog","xhbtfnqebaj","sceqalciwmsxw","jssctk","uzvcoaf","fefydxagn","jhrvc","mbj","raiahv","nrtyzifwytjblwy","mhqcp","jkgjkwmaqf","wscfvrfylhi","lqrz","ahabucermswyrvl","wxoxftvrgqmkg","ku","uyaoq","mhqocp","ykwjo","vstm","ofncgxrkqvcwr","dqvh","taxyihn","idie","bwqtu","tztoovyfwz","rspvcccjjtcm","uojrpp","wmomuhn","cotycbiizlxcr","nrtyzfwytjblw","ocbya","sceqlciwmxw","ajtj","rspvccbcjjthcm","kfeuqyyre","dmelddg","txyihn","ubkcitlscmwxk","ntyswtnla","bdxjpstvlxktytxs","odqdvbh","pxpsvikeewekuq","mdwdmbdtux","vs","bma","wzbypigvo","qxyy","vsstm","hbtnqeba","hrzebpaz","xhbtfnjsqebbaj","ahaucermswyrv","ddmbtx","zhhbiqiw","pxpsvikewekuq","odqdvgbh","bxjpsvlxktxs","jsck","fjmdc","mdwdmbdtx","jqxyyrl","pxpsvikweuq","ctybizcr","dqvbh","lpl","lqrfzw","ufybaozoqk","znvaafvqi","yvuhmiuehp","hvrzebpazw","pfksrllrxw","alzuu","xjsvxtxs","afplzhbqguuu","icsingrbpqli","hjxytflhmvsgv","femafycxdxagn","uyaoqk","gmlckvofwyifrw","cinrbpql","jrcgbhss","oxwpkxlkcp","jkagljikwamaqvf","eollbigtftpdrdy","rspvcjcm","socbya","clapulm","qeb","kwrpi","efzpi","hbtfnqebaj","kykizdnandafusu","sclvazzpulmw","efzzpvvi","jfvvtavwsvgl","mhqocpy","v","mbpbvxsdastvtm","irqvnxouu","hvaajtj","ofnlcgxrkqvcwr","hbtqeba","hbtqeb","jwmqpds","ntrnlhujdslco","zv","npdbccbken","mhp","ddb","prllw","mddmbtx","clazpulm","cogxxpaknkse","bkitcmwxk","oxwpklkcp","tyiz","jwmqvpqods","waxyoxftvrgqmkgb","afplzhbbqsgujuu","bwtu","jercgbhss","rsacx","mahkqodcpy","cotycbiizlcr","ahabucermswyrv","lupvpkhr","dvnn","b","atpepsz","ncgxqvcr","qe","ubkcitlcmwxk","lyqrfzw","wimomuhn","bbmnaxl","motnfwohrwule","yvuyhmiuehspi","jfvvtavwsgl","rac","fefdxagn","bwqkctun","uotjrpp","ddbtx","afplzhbbqsguuu","xss","xsxs","wvyiqax","kykizdandaus","npdbccbkens","r","oxwnpkxjlakcp","tzmteoovsyfwz","kykizdnandafuspu","ahabulcermswyrvl","xjsxxs","qxyyr","ck","xhbtfnqebbaj","nqpdbccbkens","mpvsdastvtm","zuexqoxyp","gmlkvofwyifrw","kmw","txhn","kykizdandausu","molznwhkxsn","lupvpdkhr","jwmqvpds","bktcmwx","wyiax","hzvaajtj","ddbx","pifojogveub","naafvqi","motnfwjohrwule","odqvbh","aicsingrbpqli","jopzyeg","lybtqrfazrw","pijogveub","xzejfnllhfulns","scxllvazzpulmw","irqyvnxdcxfoejuu","cogxpaknks","pdkwrpsi","wzbycpajigvo","xjsxtxs","irqvnxdcxfoejuu","xhbtfnjqebbaj","uybaoqk","oncgxqvcr","aj","pepuwsxl","lytqrfzw","nkm","jrgs","pkrllrw","wscfvrfyli","bbmjnaxcaml","jftavwg","vuzvcozaif","pifjogveub","cmogxxpaknkse","cinrbql","scqlciwmxw","ztvyfz","mxyevopfoimgjpww","soicbya","lupvpdkhrm","ahaucermsyrv","ufybmvbaouzoqk","bdxjpsvlxktxs","hjxytfflhmvsgv","hjvxytfflhmvsgv","nqpdbccbzkxens","wr","kykzdndus","iddimea","fjmdrcc","efzzpi","vsdastm","btqeb","pfkrllrxw","ocby","irqvnxxouu","ildzpdimea","lzwhkxsn","ilddimea","ufybvbaozoqk","mxyevopfoimgjww","jhr","kcmwx","dvn","uzcof","glw","hbtnqebaj","riahv","w","qeugv","kfeuqyre","ilrdzpdimea","lplm","icinrbpql","scqlcmxw","bbmjnaxaml","e","rsac","bf","jwmqvpqds","tzteoovsyfwz","rc","lzwhkxs","jkgljikwamaqvf","tybizc","aplzuu","nrtyzifwytjblw","pze","bktcmwxk","uiykgmc","jsctk","npdbccbe","tybizcr" };
    check.checkInt(15, o.longestStrChain(words));
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
