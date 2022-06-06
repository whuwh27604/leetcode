/* 设计一个文本编辑器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个带光标的文本编辑器，它可以实现以下功能：

添加：在光标所在处添加文本。
删除：在光标所在处删除文本（模拟键盘的删除键）。
移动：将光标往左或者往右移动。
当删除文本时，只有光标左边的字符会被删除。光标会留在文本内，也就是说任意时候 0 <= cursor.position <= currentText.length 都成立。

请你实现 TextEditor 类：

TextEditor() 用空文本初始化对象。
void addText(string text) 将 text 添加到光标所在位置。添加完后光标在 text 的右边。
int deleteText(int k) 删除光标左边 k 个字符。返回实际删除的字符数目。
string cursorLeft(int k) 将光标向左移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
string cursorRight(int k) 将光标向右移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
 

示例 1：

输入：
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
输出：
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

解释：
TextEditor textEditor = new TextEditor(); // 当前 text 为 "|" 。（'|' 字符表示光标）
textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
textEditor.deleteText(4); // 返回 4
                          // 当前文本为 "leet|" 。
                          // 删除了 4 个字符。
textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
textEditor.cursorRight(3); // 返回 "etpractice"
                           // 当前文本为 "leetpractice|".
                           // 光标无法移动到文本以外，所以无法移动。
                           // "etpractice" 是光标左边的 10 个字符。
textEditor.cursorLeft(8); // 返回 "leet"
                          // 当前文本为 "leet|practice" 。
                          // "leet" 是光标左边的 min(10, 4) = 4 个字符。
textEditor.deleteText(10); // 返回 4
                           // 当前文本为 "|practice" 。
                           // 只有 4 个字符被删除了。
textEditor.cursorLeft(2); // 返回 ""
                          // 当前文本为 "|practice" 。
                          // 光标无法移动到文本以外，所以无法移动。
                          // "" 是光标左边的 min(10, 0) = 0 个字符。
textEditor.cursorRight(6); // 返回 "practi"
                           // 当前文本为 "practi|ce" 。
                           // "practi" 是光标左边的 min(10, 6) = 6 个字符。
 

提示：

1 <= text.length, k <= 40
text 只含有小写英文字母。
调用 addText ，deleteText ，cursorLeft 和 cursorRight 的 总 次数不超过 2 * 104 次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-a-text-editor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    Node* prev;
    Node* next;
    char c;

    Node() : prev(NULL), next(NULL), c(0) {}
    Node(char c_) : prev(NULL), next(NULL), c(c_) {}
};

class TextEditor {
public:
    TextEditor() {
        head.next = &tail;
        tail.prev = &head;
        cursor = &tail;
    }

    void addText(string text) {
        Node* prev = cursor->prev;

        for (char c : text) {
            Node* node = new Node(c);
            prev->next = node;
            node->prev = prev;
            prev = node;
        }

        prev->next = cursor;
        cursor->prev = prev;
    }

    int deleteText(int k) {
        int count = 0;
        Node* node = cursor->prev;

        for (int i = 0; i < k && node != &head; ++i) {
            node->prev->next = cursor;
            cursor->prev = node->prev;
            node = node->prev;
            ++count;
        }

        return count;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k && cursor->prev != &head; ++i) {
            cursor = cursor->prev;
        }

        return getText();
    }

    string cursorRight(int k) {
        for (int i = 0; i < k && cursor != &tail; ++i) {
            cursor = cursor->next;
        }

        return getText();
    }

    string getText() {
        string text;
        Node* node = cursor->prev;

        for (int i = 0; i < 10 && node != &head; ++i) {
            text += node->c;
            node = node->prev;
        }

        reverse(text.begin(), text.end());

        return text;
    }

private:
    Node head;
    Node tail;
    Node* cursor;
};

int main()
{
    CheckResult check;

    TextEditor o1;
    o1.addText("leetcode");
    check.checkInt(4, o1.deleteText(4));
    o1.addText("practice");
    check.checkString("etpractice", o1.cursorRight(3));
    check.checkString("leet", o1.cursorLeft(8));
    check.checkInt(4, o1.deleteText(10));
    check.checkString("", o1.cursorLeft(2));
    check.checkString("practi", o1.cursorRight(6));
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
