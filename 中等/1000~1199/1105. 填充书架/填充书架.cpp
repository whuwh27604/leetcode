/* 填充书架.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
附近的家居城促销，你买回了一直心仪的可调节书架，打算把自己的书都整理到新的书架上。

你把要摆放的书 books 都整理好，叠成一摞：从上往下，第 i 本书的厚度为 books[i][0]，高度为 books[i][1]。

按顺序 将这些书摆放到总宽度为 shelf_width 的书架上。

先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelf_width），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。

需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。 例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。

每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。

以这种方式布置书架，返回书架整体可能的最小高度。

 

示例：



输入：books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
输出：6
解释：
3 层书架的高度和为 1 + 3 + 2 = 6 。
第 2 本书不必放在第一层书架上。
 

提示：

1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/filling-bookcase-shelves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int i, j, size = books.size();
        vector<int> dp(size + 1, 0);  // 令dp[i]表示books[i]在一层的开始位置，放下books[i~size-1]需要的最小层高
        dp[size - 1] = books[size - 1][1];  // 最后一本书需要的层高就是这本书的高度

        for (i = size - 2; i >= 0; --i) {  // 每次往前新增一本书
            int width = books[i][0], levelMaxHeight = books[i][1];
            dp[i] = levelMaxHeight + dp[i + 1];  // 这本书单独一层，剩下的书另起一层，需要的层高就是两者之和

            for (j = i + 1; j < size; ++j) {  // 然后依次尝试把剩下的书放在和当前这本书同一层，找到最小需要的层高
                width += books[j][0];
                if (width > shelf_width) {  // 如果当前这一层已经摆不下了，就不需要再往后尝试
                    break;
                }

                levelMaxHeight = max(levelMaxHeight, books[j][1]);  // 新书加进来后，更新当前层的最大层高
                dp[i] = min(dp[i], levelMaxHeight + dp[j + 1]);  // 当前层高加剩下的书需要的最小层高，就是放下books[i~size-1]需要的最小层高
            }
        }

        return dp[0];  // 最后dp[0]就是放下books[0~size-1]一共size本书需要的最小层高
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> books = { {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    check.checkInt(6, o.minHeightShelves(books, 4));

    books = { {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    check.checkInt(3, o.minHeightShelves(books, 9));

    books = { {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    check.checkInt(4, o.minHeightShelves(books, 8));

    books = { {5,6} };
    check.checkInt(6, o.minHeightShelves(books, 8));

    books = { {1,1},{1,2},{1,3},{1,4},{1,5} };
    check.checkInt(15, o.minHeightShelves(books, 1));
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
