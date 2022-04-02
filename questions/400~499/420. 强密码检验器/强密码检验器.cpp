/* 强密码检验器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个密码满足下述所有条件，则认为这个密码是强密码：
由至少 6 个，至多 20 个字符组成。
至少包含 一个小写 字母，一个大写 字母，和 一个数字 。
同一字符 不能 连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 如果满足其他条件也可以算是强密码)。
给你一个字符串 password ，返回 将 password 修改到满足强密码条件需要的最少修改步数。如果 password 已经是强密码，则返回 0 。

在一步修改操作中，你可以：

插入一个字符到 password ，
从 password 中删除一个字符，或
用另一个字符来替换 password 中的某个字符。
 

示例 1：

输入：password = "a"
输出：5
示例 2：

输入：password = "aA1"
输出：3
示例 3：

输入：password = "1337C0d3"
输出：0
 

提示：

1 <= password.length <= 50
password 由字母、数字、点 '.' 或者感叹号 '!'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strong-password-checker
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int size = password.size();
        password += '*';

        if (size < 6) {
            return minOperShorter(password, size);
        }

        if (size > 20) {
            return minOperLonger(password, size);
        }

        return minOper(password, size);
    }

    // 长度小于6时，只能添加字符，差哪种类型就添加哪种。并且插入字符后，一定满足没有连续的3个相同的字符
    int minOperShorter(string& password, int size) {
        return max(6 - size, 3 - getTypes(password));
    }

    // 长度已经符合要求，只需要使用替换操作。1、差某种字符时，替换一个该类字符。2、多个连续相同字符时，替换3X位置的字符
    int minOper (string& password, int size) {
        int consective = 1, modify = 0;
        char prev = 0;

        for (char c : password) {
            if (c == prev) {
                ++consective;
            }
            else {
                modify += (consective / 3);
                consective = 1;
                prev = c;
            }
        }

        return max(modify, 3 - getTypes(password));
    }

    int minOperLonger(string& password, int size) {
        vector<int> remainder0, remainder1, remainder2;
        int consective = 1, modify = 0, del = 0;
        char prev = 0;

        for (char c : password) {
            if (c == prev) {
                ++consective;
            }
            else {
                if (consective > 2) {
                    if (consective % 3 == 0) {
                        remainder0.push_back(consective);
                    }
                    else if (consective % 3 == 1) {
                        remainder1.push_back(consective);
                    }
                    else {
                        remainder2.push_back(consective);
                    }
                }

                consective = 1;
                prev = c;
            }
        }

        delRemainder0(remainder0, remainder2, del, size);
        delRemainder1(remainder1, remainder2, modify, del, size);
        delRemainder2(remainder2, modify, del, size);

        if (size > 20) {  // 如果仍然比20大，将多余的字符直接删除
            del += (size - 20);
        }

        return del + max(modify, 3 - getTypes(password));
    }

    void delRemainder0(vector<int>& remainder0, vector<int>& remainder2, int& del, int& size) {
        for (int len : remainder0) {
            del += 1;  // 就算size已经小于20，删除一个字符和修改一个字符的操作数是一样的。可以直接选择删除最后一个字符
            size -= 1;

            if (len - 1 > 2) {  // 仍然有连续3个相同的字符，此时余2，放入remainder2待处理
                remainder2.push_back(len - 1);
            }
        }
    }

    void delRemainder1(vector<int>& remainder1, vector<int>& remainder2, int& modify, int& del, int& size) {
        for (int len : remainder1) {
            if (size > 20) {  // 如果size还大于20，选择删除最后两个字符
                del += 2;
                size -= 2;

                if (len - 2 > 2) {  // 仍然有连续3个相同的字符，此时余2，放入remainder2待处理
                    remainder2.push_back(len - 2);
                }
            }
            else {  // size已经满足要求，不用再删除2个了，直接修改3X位置的字符使它满足没有连续3个相同字符
                modify += (len / 3);
            }
        }
    }

    void delRemainder2(vector<int>& remainder2, int& modify, int& del, int& size) {
        for (int len : remainder2) {
            if (size > 20) {  // 只要size还大于20，这一组只保留2个相同字符，多余的全部删掉
                int delNum = min(size - 20, len - 2);
                del += delNum;
                size -= delNum;
                modify += (len - delNum) / 3;  // 剩余的还需要修改
            }
            else {  // size已经满足要求，不用再删除，直接修改3X位置的字符使它满足没有连续3个相同字符
                modify += (len / 3);
            }
        }
    }

    int getTypes(string& password) {
        bool lowercase = false, uppercase = false, digit = false;

        for (char c : password) {
            if (islower(c)) {
                lowercase = true;
            }
            else if (isupper(c)) {
                uppercase = true;
            }
            else if (isdigit(c)) {
                digit = true;
            }
        }

        return (lowercase ? 1 : 0) + (uppercase ? 1 : 0) + (digit ? 1 : 0);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.strongPasswordChecker("a"));
    check.checkInt(3, o.strongPasswordChecker("aA1"));
    check.checkInt(0, o.strongPasswordChecker("1337C0d3"));
    check.checkInt(3, o.strongPasswordChecker("abababababababababaaa"));
    check.checkInt(7, o.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaa"));
    check.checkInt(6, o.strongPasswordChecker("ABABABABABABABABABABABAB"));
    check.checkInt(2, o.strongPasswordChecker("1010101010aaaB10101010"));
    check.checkInt(3, o.strongPasswordChecker("..."));
    check.checkInt(3, o.strongPasswordChecker("1234567890123456Baaaaa"));
    check.checkInt(2, o.strongPasswordChecker("aaa111"));
    check.checkInt(7, o.strongPasswordChecker("..................!!!"));
    check.checkInt(2, o.strongPasswordChecker("1Abababcaaaabababababa"));
    check.checkInt(3, o.strongPasswordChecker("aaaaabbbb1234567890ABA"));
    check.checkInt(4, o.strongPasswordChecker("aaaaaa1234567890123Ubefg"));
    check.checkInt(13, o.strongPasswordChecker("aaaaaaaAAAAAA6666bbbbaaaaaaABBC"));
    check.checkInt(6, o.strongPasswordChecker(""));
    check.checkInt(5, o.strongPasswordChecker("A"));
    check.checkInt(5, o.strongPasswordChecker("1"));
    check.checkInt(3, o.strongPasswordChecker("aA1"));
    check.checkInt(1, o.strongPasswordChecker("aA123"));
    check.checkInt(1, o.strongPasswordChecker("aa123"));
    check.checkInt(1, o.strongPasswordChecker("aaa123"));
    check.checkInt(3, o.strongPasswordChecker("1111111111"));
    check.checkInt(2, o.strongPasswordChecker("ABABABABABABABABABAB1"));
    check.checkInt(10, o.strongPasswordChecker("hoAISJDBVWD09232UHJEPODKNLADU1"));
    check.checkInt(4, o.strongPasswordChecker("ABABABABABABABABABABAB3b"));
    check.checkInt(5, o.strongPasswordChecker("ababababababababababaaa"));
    check.checkInt(1, o.strongPasswordChecker("abAbababababababaaa"));
    check.checkInt(2, o.strongPasswordChecker("abAbabababababababaaa"));
    check.checkInt(2, o.strongPasswordChecker("aaaaaa"));
    check.checkInt(2, o.strongPasswordChecker("QQQQQ"));
    check.checkInt(6, o.strongPasswordChecker("ppppppppppppppppppp"));
    check.checkInt(3, o.strongPasswordChecker("ababababababababaaaaa"));
    check.checkInt(2, o.strongPasswordChecker("qqq123qqq"));
    check.checkInt(3, o.strongPasswordChecker("1020304050607080Baaaaa"));
    check.checkInt(3, o.strongPasswordChecker("10203040aaaaa50607080B"));
    check.checkInt(3, o.strongPasswordChecker("pppppp1020304050607080"));
    check.checkInt(3, o.strongPasswordChecker("ppppppppp"));
    check.checkInt(3, o.strongPasswordChecker("aaaabbaaabbaaa123456A"));
    check.checkInt(4, o.strongPasswordChecker("AAAAAABBBBBB123456789a"));
    check.checkInt(3, o.strongPasswordChecker("aaaabaaaaaa123456789F"));
    check.checkInt(2, o.strongPasswordChecker("1234567890123456Baaaa"));
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
