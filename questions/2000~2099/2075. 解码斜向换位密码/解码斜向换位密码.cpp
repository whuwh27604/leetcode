/* 解码斜向换位密码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串 originalText 使用 斜向换位密码 ，经由 行数固定 为 rows 的矩阵辅助，加密得到一个字符串 encodedText 。

originalText 先按从左上到右下的方式放置到矩阵中。


先填充蓝色单元格，接着是红色单元格，然后是黄色单元格，以此类推，直到到达 originalText 末尾。箭头指示顺序即为单元格填充顺序。所有空单元格用 ' ' 进行填充。矩阵的列数需满足：用 originalText 填充之后，最右侧列 不为空 。

接着按行将字符附加到矩阵中，构造 encodedText 。


先把蓝色单元格中的字符附加到 encodedText 中，接着是红色单元格，最后是黄色单元格。箭头指示单元格访问顺序。

例如，如果 originalText = "cipher" 且 rows = 3 ，那么我们可以按下述方法将其编码：


蓝色箭头标识 originalText 是如何放入矩阵中的，红色箭头标识形成 encodedText 的顺序。在上述例子中，encodedText = "ch   ie   pr" 。

给你编码后的字符串 encodedText 和矩阵的行数 rows ，返回源字符串 originalText 。

注意：originalText 不 含任何尾随空格 ' ' 。生成的测试用例满足 仅存在一个 可能的 originalText 。

 

示例 1：

输入：encodedText = "ch   ie   pr", rows = 3
输出："cipher"
解释：此示例与问题描述中的例子相同。
示例 2：



输入：encodedText = "iveo    eed   l te   olc", rows = 4
输出："i love leetcode"
解释：上图标识用于编码 originalText 的矩阵。
蓝色箭头展示如何从 encodedText 找到 originalText 。
示例 3：



输入：encodedText = "coding", rows = 1
输出："coding"
解释：由于只有 1 行，所以 originalText 和 encodedText 是相同的。
示例 4：


输入：encodedText = " b  ac", rows = 2
输出：" abc"
解释：originalText 不能含尾随空格，但它可能会有一个或者多个前置空格。
 

提示：

0 <= encodedText.length <= 106
encodedText 仅由小写英文字母和 ' ' 组成
encodedText 是对某个 不含 尾随空格的 originalText 的一个有效编码
1 <= rows <= 1000
生成的测试用例满足 仅存在一个 可能的 originalText

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-the-slanted-ciphertext
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size = encodedText.size(), columns = size / rows, r = 0, c = 0, oc = 0;
        string text;

        while (oc < columns) {
            text += encodedText[r * columns + c];

            if (++r == rows || ++c == columns) {
                r = 0, c = ++oc;
            }
        }

        while (!text.empty() && text.back() == ' ') {
            text.pop_back();
        }

        return text;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("cipher", o.decodeCiphertext("ch   ie   pr", 3));
    check.checkString("i love leetcode", o.decodeCiphertext("iveo    eed   l te   olc", 4));
    check.checkString("coding", o.decodeCiphertext("coding", 1));
    check.checkString(" abc", o.decodeCiphertext(" b  ac", 2));
    check.checkString("", o.decodeCiphertext("", 3));
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
