/* 字典序排数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographical-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <time.h>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicalNumbers;
        stack<int> numbers;
        numbers.push(0);

        while (!numbers.empty()) {
            int current = numbers.top();
            numbers.pop();
            if ((current % 10) == 9) {
                continue;
            }

            current += 1;
            bool increased = false;
            while (current <= n) {
                lexicalNumbers.push_back(current);
                numbers.push(current);
                current *= 10;
                increased = true;
            }

            if (!increased) {
                continue;
            }
            
            current = numbers.top();
            numbers.pop();
            int i = 1, end = 9 - current % 10;
            while ((i <= end) && (current + i <= n)) {
                lexicalNumbers.push_back(current + i++);
            }
        }

        return lexicalNumbers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.lexicalOrder(1);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(2);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(9);
    expected = { 1,2,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(10);
    expected = { 1,10,2,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(20);
    expected = { 1,10,11,12,13,14,15,16,17,18,19,2,20,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(100);
    expected = { 1,10,100,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,
        5,50,51,52,53,54,55,56,57,58,59,6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99 };
    check.checkIntVector(expected, actual);

    actual = o.lexicalOrder(123);
    expected = { 1,10,100,101,102,103,104,105,106,107,108,109,11,110,111,112,113,114,115,116,117,118,119,12,120,121,122,123,13,14,15,16,17,18,19,
        2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,5,50,51,52,53,54,55,56,57,58,59,
        6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99 };
    check.checkIntVector(expected, actual);

    int time1 = clock();
    actual = o.lexicalOrder(5000000);
    int time2 = clock();
    cout << "time1 = " << time1 << ", time2 = " << time2 << ", duration = " << time2 - time1 << endl;
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
