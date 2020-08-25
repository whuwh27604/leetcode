/* 键值映射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个 MapSum 类里的两个方法，insert 和 sum。

对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。

对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:

输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode(int val) {
        memset(next, 0, sizeof(TrieNode*) * 26);
        isEnd = false;
        value = val;
        sum = val;
    }

    bool isEnd;
    int value;
    int sum;
    TrieNode* next[26];
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(0);
    }

    void insert(string key, int val) {
        TrieNode* current = root;

        for (char c : key) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                current->next[index] = new TrieNode(val);
            }
            else {
                current->next[index]->sum += val;
            }

            current = current->next[index];
        }

        if (current->isEnd == true) {
            int oldValue = current->value;
            current = root;

            for (char c : key) {
                current->next[c - 'a']->sum -= oldValue;
                current = current->next[c - 'a'];
            }
        }

        current->value = val;        
        current->isEnd = true;
    }

    int sum(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                return 0;
            }

            current = current->next[index];
        }

        return current->sum;
    }

private:
    TrieNode* root;
};

int main()
{
    MapSum o;
    CheckResult check;

    o.insert("apple", 3);
    check.checkInt(3, o.sum("ap"));
    o.insert("app", 2);
    check.checkInt(5, o.sum("ap"));
    o.insert("apple", 4);
    check.checkInt(6, o.sum("ap"));
    o.insert("app", 5);
    check.checkInt(9, o.sum("ap"));
    o.insert("app", 6);
    check.checkInt(10, o.sum("ap"));
    o.insert("apple", 7);
    check.checkInt(13, o.sum("ap"));
    o.insert("ab", 8);
    check.checkInt(13, o.sum("ap"));
    check.checkInt(13, o.sum("app"));
    check.checkInt(21, o.sum("a"));
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
