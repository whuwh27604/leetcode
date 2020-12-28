/* 设计浏览器历史记录.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个只支持单个标签页的 浏览器 ，最开始你浏览的网页是 homepage ，你可以访问其他的网站 url ，也可以在浏览历史中后退 steps 步或前进 steps 步。

请你实现 BrowserHistory 类：

BrowserHistory(string homepage) ，用 homepage 初始化浏览器类。
void visit(string url) 从当前页跳转访问 url 对应的页面  。执行此操作会把浏览历史前进的记录全部删除。
string back(int steps) 在浏览历史中后退 steps 步。如果你只能在浏览历史中后退至多 x 步且 steps > x ，那么你只后退 x 步。请返回后退 至多 steps 步以后的 url 。
string forward(int steps) 在浏览历史中前进 steps 步。如果你只能在浏览历史中前进至多 x 步且 steps > x ，那么你只前进 x 步。请返回前进 至多 steps步以后的 url 。
 

示例：

输入：
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
输出：
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

解释：
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // 你原本在浏览 "leetcode.com" 。访问 "google.com"
browserHistory.visit("facebook.com");     // 你原本在浏览 "google.com" 。访问 "facebook.com"
browserHistory.visit("youtube.com");      // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
browserHistory.back(1);                   // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
browserHistory.back(1);                   // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
browserHistory.forward(1);                // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
browserHistory.visit("linkedin.com");     // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
browserHistory.forward(2);                // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
browserHistory.back(7);                   // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"
 

提示：

1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage 和 url 都只包含 '.' 或者小写英文字母。
最多调用 5000 次 visit， back 和 forward 函数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-browser-history
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        urls.resize(5000);
        urls[0] = homepage;
        current = 0;
        size = 1;
    }

    void visit(string url) {
        urls[++current] = url;
        size = current + 1;
    }

    string back(int steps) {
        current = current > steps ? current - steps : 0;
        return urls[current];
    }

    string forward(int steps) {
        current = (current + steps) >= size ? size - 1 : (current + steps);
        return urls[current];
    }

private:
    vector<string> urls;
    int current;
    int size;
};

int main()
{
    CheckResult check;

    BrowserHistory o1("leetcode.com");
    o1.visit("google.com");
    o1.visit("facebook.com");
    o1.visit("youtube.com");
    check.checkString("facebook.com", o1.back(1));
    check.checkString("google.com", o1.back(1));
    check.checkString("facebook.com", o1.forward(1));
    o1.visit("linkedin.com");
    check.checkString("linkedin.com", o1.forward(2));
    check.checkString("google.com", o1.back(2));
    check.checkString("leetcode.com", o1.back(7));

    BrowserHistory o2("leetcode.com");
    o2.visit("google.com");
    check.checkString("leetcode.com", o2.back(1));
    check.checkString("google.com", o2.forward(2));

    BrowserHistory o3("a");
    o3.visit("b");
    check.checkString("a", o3.back(1));
    check.checkString("b", o3.forward(1));
    check.checkString("a", o3.back(2));
    check.checkString("b", o3.forward(2));
    o3.visit("c");
    check.checkString("b", o3.back(1));

    BrowserHistory o4("a");
    o4.visit("b");
    check.checkString("a", o4.back(1));
    check.checkString("b", o4.forward(1));
    check.checkString("a", o4.back(2));
    check.checkString("b", o4.forward(2));
    o4.visit("c");
    check.checkString("a", o4.back(2));

    BrowserHistory o5("a");
    o5.visit("b");
    check.checkString("a", o5.back(1));
    check.checkString("b", o5.forward(1));
    check.checkString("a", o5.back(2));
    check.checkString("b", o5.forward(2));
    o5.visit("c");
    check.checkString("a", o5.back(3));
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
