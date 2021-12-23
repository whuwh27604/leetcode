/* 最长重复子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，考虑其所有 重复子串 ：即，s 的连续子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。

返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。

 

示例 1：

输入：s = "banana"
输出："ana"
示例 2：

输入：s = "abcd"
输出：""
 

提示：

2 <= s.length <= 3 * 104
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-duplicate-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int low = 1, high = s.size() - 1, dupPos = -1, dupLen = -1;

        while (low <= high) {
            int middle = (low + high) / 2;
            int pos = findDupSubstring(s, middle);

            if (pos == -1) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
                dupPos = pos;
                dupLen = middle;
            }
        }

        return dupPos == -1 ? "" : string(s, dupPos, dupLen);
    }

    int findDupSubstring(string& s, int len) {
        int i, size = s.size(), base1 = 31, base2 = 47, mod1 = 1000000007, mod2 = 1010100007;
        long long key1 = (long long)s[0] - 'a', key2 = (long long)s[0] - 'a', power1 = 1, power2 = 1;
        unordered_set<long long> seen;

        for (i = 1; i < len; ++i) {  // 计算s[0, len)的hashkey
            key1 = (key1 * base1 + ((long long)s[i] - 'a')) % mod1;
            key2 = (key2 * base2 + ((long long)s[i] - 'a')) % mod2;
            power1 = power1 * base1 % mod1;
            power2 = power2 * base2 % mod2;
        }

        long long keyPair = ((key1 << 32) | key2);
        seen.insert(keyPair);

        for (i = 1; i + len <= size; ++i) {  // 滚动计算s[i, i + len)的hashkey，先减去最高位，再左移一位，再加上最末位
            long long highest = ((long long)s[i - 1] - 'a') * power1 % mod1;
            key1 = ((key1 + (key1 < highest ? mod1 : 0) - highest) * base1 + ((long long)s[i + len - 1] - 'a')) % mod1;
            highest = ((long long)s[i - 1] - 'a') * power2 % mod2;
            key2 = ((key2 + (key2 < highest ? mod2 : 0) - highest) * base2 + ((long long)s[i + len - 1] - 'a')) % mod2;
            keyPair = ((key1 << 32) | key2);

            if (seen.count(keyPair) != 0) {
                return i;
            }

            seen.insert(keyPair);
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("ana", o.longestDupSubstring("banana"));
    check.checkString("", o.longestDupSubstring("abcd"));
    check.checkString("a", o.longestDupSubstring("aa"));
    check.checkString("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", o.longestDupSubstring("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
    check.checkString("akyj", o.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc"));
    check.checkString("ma", o.longestDupSubstring("nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy"));
    check.checkString("xyl", o.longestDupSubstring("ibzlasqyjtsbihixoauthfqbbpmcnwcdbgzdirkmuxbvawqnwrtdmhryrvztzdnmwmjoaewzotqbzvkvivnlhpttakfpiihadfxylcxaarcrqidmuonuhouzyucnejwydtzznkwrlksjnadrgpjkzqiwqtrwdyycyzzuwndgtdixtyehehnknjgdurzetifqxhvyligrjtzrznahggmbmkigptzedeiuhtbuqpvsmswpbkcbdjlzhexyyqdthqimxxylvfluzssoxdfywoykdkwjimmrxgprarnbgtojkosetiycwldbdoundualvkttyplyseinffyoyxfjzdgfrulolczknddpgdbpyxhfcxjsplfztzcemodowgghlsjfjwpjrxcwmzdkqfojkmrtuflqkklnkfnpdavnrfsngtbmbqhbijdgtjcfxctxdwxlgiteuifnorhdlabnvfvaitfqgrofgykjleejgomtydsjxybgdwbdmesnrhhimwdmjidugknunejkbxmrpwlkzseuehrmmlkymzgqmwxqnetvcyglmvoiihsapwupvnmrtkqzjaxfrlzceeetkfruafaqmfhboquapperhvshxnvklnmiztxwahdaimibpbxcrvryfbfcniiphtbihdblbhuhucbthshulgzgofgvyuytnyfulhjcvuutlmfmhbghalwjexkxeorehrwirmowsrblctajdjrhnxyfuirckxabowziowrlsssrlgzldsavpemjqlvtyobfjaaoybbqwyiofbaxognsn"));
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
