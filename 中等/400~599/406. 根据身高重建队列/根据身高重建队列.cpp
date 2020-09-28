/* 根据身高重建队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return (v1[0] == v2[0]) ? (v1[1] < v2[1]) : (v1[0] > v2[0]);
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), vectorCompare);

        vector<vector<int>> reconstructedQueue;
        for (vector<int> one : people) {
            auto iter = reconstructedQueue.begin();
            advance(iter, one[1]);
            reconstructedQueue.insert(iter, one);
        }

        return reconstructedQueue;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2}, };
    vector<vector<int>> actual = o.reconstructQueue(people);
    vector<vector<int>> expected = { {5,0},{7,0},{5,2},{6,1},{4,4},{7,1}, };
    check.checkIntVectorVector(expected, actual);

    people = {  };
    actual = o.reconstructQueue(people);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    people = { {5,0} };
    actual = o.reconstructQueue(people);
    expected = { {5,0} };
    check.checkIntVectorVector(expected, actual);

    people = { {5,0},{4,1} };
    actual = o.reconstructQueue(people);
    expected = { {5,0},{4,1} };
    check.checkIntVectorVector(expected, actual);

    people = { {4,1},{5,0} };
    actual = o.reconstructQueue(people);
    expected = { {5,0},{4,1} };
    check.checkIntVectorVector(expected, actual);

    people = { {4,0},{5,0} };
    actual = o.reconstructQueue(people);
    expected = { {4,0},{5,0} };
    check.checkIntVectorVector(expected, actual);

    people = { {1,0},{2,0},{3,0} };
    actual = o.reconstructQueue(people);
    expected = { {1,0},{2,0},{3,0} };
    check.checkIntVectorVector(expected, actual);

    people = { {1,2},{2,1},{3,0} };
    actual = o.reconstructQueue(people);
    expected = { {3,0},{2,1},{1,2} };
    check.checkIntVectorVector(expected, actual);
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
