/* 寻找比目标字母大的最小字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例：

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
 

提示：

letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        if ((target < letters[0]) || (target >= letters[len - 1])) {
            return letters[0];
        }

        return binarySearch(letters, target, 0, len - 1);
    }

    char binarySearch(vector<char>& letters, char target, int left, int right) {
        int middle = (left + right) / 2;
        if (middle == left) {
            if (letters[middle] > target) {
                return letters[middle];
            }
            return letters[right];
        }

        if ((letters[middle] > target) && (letters[middle - 1] <= target)) {
            return letters[middle];
        }

        if (letters[middle] <= target) {
            return binarySearch(letters, target, middle + 1, right);
        }

        return binarySearch(letters, target, left, middle - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<char> letters = { 'c', 'f', 'j' };
    check.checkChar('c', o.nextGreatestLetter(letters, 'a'));
    check.checkChar('f', o.nextGreatestLetter(letters, 'c'));
    check.checkChar('f', o.nextGreatestLetter(letters, 'd'));
    check.checkChar('j', o.nextGreatestLetter(letters, 'g'));
    check.checkChar('c', o.nextGreatestLetter(letters, 'j'));
    check.checkChar('c', o.nextGreatestLetter(letters, 'k'));

    letters = { 'c', 'f' };
    check.checkChar('c', o.nextGreatestLetter(letters, 'a'));
    check.checkChar('f', o.nextGreatestLetter(letters, 'c'));
    check.checkChar('f', o.nextGreatestLetter(letters, 'd'));
    check.checkChar('c', o.nextGreatestLetter(letters, 'f'));
    check.checkChar('c', o.nextGreatestLetter(letters, 'z'));

    letters = { 'e', 'e', 'e', 'e', 'e', 'e', 'n', 'n', 'n', 'n' };
    check.checkChar('n', o.nextGreatestLetter(letters, 'e'));

    letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'i' };
    check.checkChar('d', o.nextGreatestLetter(letters, 'c'));
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
