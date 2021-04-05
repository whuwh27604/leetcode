/* TinyURL 的加密与解密.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.

要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/encode-and-decode-tinyurl
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution() : id(0) {}

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        idUrl[id] = longUrl;
        string shortUrl = to_string(id++);
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return idUrl[stoi(shortUrl)];
    }

private:
    int id;
    unordered_map<int, string> idUrl;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("a", o.decode(o.encode("a")));
    check.checkString("ab", o.decode(o.encode("ab")));
    check.checkString("abc", o.decode(o.encode("abc")));
    check.checkString("a", o.decode(o.encode("a")));
    check.checkString("ab", o.decode(o.encode("ab")));
    check.checkString("abc", o.decode(o.encode("abc")));
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
