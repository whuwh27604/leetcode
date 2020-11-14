/* 旅行终点站.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。

 

示例 1：

输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
输出："Sao Paulo"
解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。
示例 2：

输入：paths = [["B","C"],["D","B"],["C","A"]]
输出："A"
解释：所有可能的线路是：
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
显然，旅行终点站是 "A" 。
示例 3：

输入：paths = [["A","Z"]]
输出："Z"
 

提示：

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
所有字符串均由大小写英文字母和空格字符组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/destination-city
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> cityPaths;

        for (unsigned int i = 0; i < paths.size(); i++) {
            cityPaths[paths[i][0]] = paths[i][1];
        }

        auto iter = cityPaths.begin();
        string destination;
        while (iter != cityPaths.end()) {
            destination = iter->second;
            iter = cityPaths.find(destination);
        }

        return destination;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> paths = { {"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"} };
    check.checkString("Sao Paulo", o.destCity(paths));

    paths = { {"B","C"},{"D","B"},{"C","A"} };
    check.checkString("A", o.destCity(paths));

    paths = { {"A","Z"} };
    check.checkString("Z", o.destCity(paths));

    paths = { {"A","Z"},{"B","Z"},{"C","Z"},{"Z","X"} };
    check.checkString("X", o.destCity(paths));
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
