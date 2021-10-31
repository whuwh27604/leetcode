/* 键盘行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

 



 

示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<int> lines = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3,0,0,0,0,0,0,2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3,0,0,0,0 };

        for (string& word : words) {
            int i = 0, size = word.size(), line = lines[word[0]];

            for (i = 1; i < size && lines[word[i]] == line; ++i) {}

            if (i == size) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
    vector<string> actual = o.findWords(words);
    vector<string> expected = { "Alaska", "Dad" };
    check.checkStringVector(expected, actual);

    words = {  };
    actual = o.findWords(words);
    expected = {  };
    check.checkStringVector(expected, actual);

    words = { "q","a","z" };
    actual = o.findWords(words);
    expected = { "q","a","z" };
    check.checkStringVector(expected, actual);

    words = { "qwertyuiopQWERTYUIOP","ASDFGHJKLasdfghjkl","zxcvbnmZXCVBNM" };
    actual = o.findWords(words);
    expected = { "qwertyuiopQWERTYUIOP","ASDFGHJKLasdfghjkl","zxcvbnmZXCVBNM" };
    check.checkStringVector(expected, actual);

    words = { "qwertyuiopQWERTYUIOPa" };
    actual = o.findWords(words);
    expected = {  };
    check.checkStringVector(expected, actual);

    words = { "qwertyuiopQWERTYUIOPz" };
    actual = o.findWords(words);
    expected = {  };
    check.checkStringVector(expected, actual);
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
