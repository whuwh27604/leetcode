/* 隐藏个人信息.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一条个人信息字符串 S，它可能是一个 邮箱地址 ，也可能是一串 电话号码 。

我们将隐藏它的隐私信息，通过如下规则:

 

1. 电子邮箱

定义名称 name 是长度大于等于 2 （length ≥ 2），并且只包含小写字母 a-z 和大写字母 A-Z 的字符串。

电子邮箱地址由名称 name 开头，紧接着是符号 '@'，后面接着一个名称 name，再接着一个点号 '.'，然后是一个名称 name。

电子邮箱地址确定为有效的，并且格式是 "name1@name2.name3"。

为了隐藏电子邮箱，所有的名称 name 必须被转换成小写的，并且第一个名称 name 的第一个字母和最后一个字母的中间的所有字母由 5 个 '*' 代替。

 

2. 电话号码

电话号码是一串包括数字 0-9，以及 {'+', '-', '(', ')', ' '} 这几个字符的字符串。你可以假设电话号码包含 10 到 13 个数字。

电话号码的最后 10 个数字组成本地号码，在这之前的数字组成国际号码。注意，国际号码是可选的。我们只暴露最后 4 个数字并隐藏所有其他数字。

本地号码是有格式的，并且如 "***-***-1111" 这样显示，这里的 1 表示暴露的数字。

为了隐藏有国际号码的电话号码，像 "+111 111 111 1111"，我们以 "+***-***-***-1111" 的格式来显示。在本地号码前面的 '+' 号和第一个 '-' 号仅当电话号码中包含国际号码时存在。例如，一个 12 位的电话号码应当以 "+**-" 开头进行显示。

注意：像 "("，")"，" " 这样的不相干的字符以及不符合上述格式的额外的减号或者加号都应当被删除。

 

最后，将提供的信息正确隐藏后返回。

 

示例 1：

输入: "LeetCode@LeetCode.com"
输出: "l*****e@leetcode.com"
解释：
所有的名称转换成小写, 第一个名称的第一个字符和最后一个字符中间由 5 个星号代替。
因此，"leetcode" -> "l*****e"。
示例 2：

输入: "AB@qq.com"
输出: "a*****b@qq.com"
解释: 
第一个名称"ab"的第一个字符和最后一个字符的中间必须有 5 个星号
因此，"ab" -> "a*****b"。
示例 3：

输入: "1(234)567-890"
输出: "***-***-7890"
解释: 
10 个数字的电话号码，那意味着所有的数字都是本地号码。
示例 4：

输入: "86-(10)12345678"
输出: "+**-***-***-5678"
解释: 
12 位数字，2 个数字是国际号码另外 10 个数字是本地号码 。
 

注意:

S.length <= 40。
邮箱的长度至少是 8。
电话号码的长度至少是 10。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/masking-personal-information
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maskPII(string S) {
        if (((S[0] >= 'a') && (S[0] <= 'z')) || ((S[0] >= 'A') && (S[0] <= 'Z'))) {
            return maskEmail(S);
        }
        else {
            return maskPhoneNumber(S);
        }
    }

    string maskEmail(string& s) {
        string masked;
        masked += tolower(s[0]);
        masked += "*****";
        unsigned int position = s.find('@');
        masked += tolower(s[position - 1]);

        for (unsigned int i = position; i < s.size(); i++) {
            masked += tolower(s[i]);
        }

        return masked;
    }

    string maskPhoneNumber(string& s) {
        string masked, onlyNumbers;

        for (char c : s) {
            if ((c >= '0') && (c <= '9')) {
                onlyNumbers += c;
            }
        }

        int len = onlyNumbers.size();
        if (len > 10) {
            masked += '+';
            masked.insert(1, len - 10, '*');
            masked += '-';
        }

        masked += "***-***-";
        masked.insert(masked.size(), onlyNumbers, len - 4, 4);

        return masked;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("l*****e@leetcode.com", o.maskPII("LeetCode@LeetCode.com"));
    check.checkString("a*****b@qq.com", o.maskPII("AB@qq.com"));
    check.checkString("***-***-7890", o.maskPII("1(234)567-890"));
    check.checkString("+**-***-***-5678", o.maskPII("86-(10)12345678"));
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
