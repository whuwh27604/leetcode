/* 价格减免.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
句子 是由若干个单词组成的字符串，单词之间用单个空格分隔，其中每个单词可以包含数字、小写字母、和美元符号 '$' 。如果单词的形式为美元符号后跟着一个非负实数，那么这个单词就表示一个价格。

例如 "$100"、"$23" 和 "$6.75" 表示价格，而 "100"、"$" 和 "2$3" 不是。
注意：本题输入中的价格均为整数。

给你一个字符串 sentence  和一个整数 discount 。对于每个表示价格的单词，都在价格的基础上减免 discount% ，并 更新 该单词到句子中。所有更新后的价格应该表示为一个 恰好保留小数点后两位 的数字。

返回表示修改后句子的字符串。

 

示例 1：

输入：sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
输出："there are $0.50 $1.00 and 5$ candies in the shop"
解释：
表示价格的单词是 "$1" 和 "$2" 。
- "$1" 减免 50% 为 "$0.50" ，所以 "$1" 替换为 "$0.50" 。
- "$2" 减免 50% 为 "$1" ，所以 "$1" 替换为 "$1.00" 。
示例 2：

输入：sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
输出："1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
解释：
任何价格减免 100% 都会得到 0 。
表示价格的单词分别是 "$3"、"$5"、"$6" 和 "$9"。
每个单词都替换为 "$0.00"。
 

提示：

1 <= sentence.length <= 105
sentence 由小写英文字母、数字、' ' 和 '$' 组成
sentence 不含前导和尾随空格
sentence 的所有单词都用单个空格分隔
所有价格都是 正 整数且不含前导零
所有价格 最多 为  10 位数字
0 <= discount <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/apply-discount-to-prices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        char* p = const_cast<char*>(sentence.c_str());
        char* context;
        string ans;

        p = strtok_s(p, " ", &context);

        while (p != NULL) {
            string word(p);

            if (isPrice(word)) {
                ans += getDiscountPrice(word, discount);
            }
            else {
                ans += word;
            }

            ans += ' ';
            p = strtok_s(NULL, " ", &context);
        }

        ans.pop_back();

        return ans;
    }

    bool isPrice(string& word) {
        int i, size = word.size();

        if (size < 2 || word[0] != '$') {
            return false;
        }

        for (i = 1; i < size; ++i) {
            if (word[i] < '0' || word[i] > '9') {
                return false;
            }
        }

        return true;
    }

    string getDiscountPrice(string& word, int discount) {
        long long price = stoll(string(word, 1, word.size() - 1));
        price *= ((long long)100 - discount);

        string s = "$";
        s += to_string(price / 100);
        s += '.';
        price %= 100;
        s += to_string(price / 10);
        price %= 10;
        s += to_string(price);

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("there are $0.50 $1.00 and 5$ candies in the shop", o.discountPrices("there are $1 $2 and 5$ candies in the shop", 50));
    check.checkString("1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$", o.discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$", 100));
    check.checkString("$2658129.12 5q $2113353.36", o.discountPrices("$7383692 5q $5870426", 64));
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
