/* 收藏清单.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 favoriteCompanies ，其中 favoriteCompanies[i] 是第 i 名用户收藏的公司清单（下标从 0 开始）。

请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标。下标需要按升序排列。

 

示例 1：

输入：favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
输出：[0,1,4]
解释：
favoriteCompanies[2]=["google","facebook"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集。
favoriteCompanies[3]=["google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 和 favoriteCompanies[1]=["google","microsoft"] 的子集。
其余的收藏清单均不是其他任何人收藏的公司清单的子集，因此，答案为 [0,1,4] 。
示例 2：

输入：favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
输出：[0,1]
解释：favoriteCompanies[2]=["facebook","google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集，因此，答案为 [0,1] 。
示例 3：

输入：favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
输出：[0,1,2,3]
 

提示：

1 <= favoriteCompanies.length <= 100
1 <= favoriteCompanies[i].length <= 500
1 <= favoriteCompanies[i][j].length <= 20
favoriteCompanies[i] 中的所有字符串 各不相同 。
用户收藏的公司清单也 各不相同 ，也就是说，即便我们按字母顺序排序每个清单， favoriteCompanies[i] != favoriteCompanies[j] 仍然成立。
所有字符串仅包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

bool comparePair(const pair<int, unordered_set<string>>& p1, const pair<int, unordered_set<string>>& p2) {
    return p1.second.size() > p2.second.size();
}

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int i, j, size = favoriteCompanies.size();
        vector<pair<int, unordered_set<string>>> favorCompanies(size);
        vector<int> nonSubsetIndices;
        
        addUserId(favoriteCompanies, favorCompanies);
        sort(favorCompanies.begin(), favorCompanies.end(), comparePair);

        for (i = 0; i < size; ++i) {
            bool isAnySubset = false;

            for (j = 0; j < i && favorCompanies[i].second.size() < favorCompanies[j].second.size(); ++j) {
                if (isSubset(favorCompanies[i].second, favorCompanies[j].second)) {
                    isAnySubset = true;
                    break;
                }
            }

            if (!isAnySubset) {
                nonSubsetIndices.push_back(favorCompanies[i].first);
            }
        }

        sort(nonSubsetIndices.begin(), nonSubsetIndices.end());
        return nonSubsetIndices;
    }

    void addUserId(vector<vector<string>>& favoriteCompanies, vector<pair<int, unordered_set<string>>>& favorCompanies) {
        for (int i = 0; i < (int)favoriteCompanies.size(); ++i) {
            favorCompanies[i].first = i;

            for (string& company : favoriteCompanies[i]) {
                favorCompanies[i].second.insert(company);
            }
        }
    }

    bool isSubset(unordered_set<string>& s1, unordered_set<string>& s2) {
        for (auto iter = s1.begin(); iter != s1.end(); ++iter) {
            if (s2.count(*iter) == 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> favoriteCompanies = { {"leetcode", "google", "facebook"},{"google", "microsoft"},{"google", "facebook"},{"google"},{"amazon"} };
    vector<int> actual = o.peopleIndexes(favoriteCompanies);
    vector<int> expected = { 0,1,4 };
    check.checkIntVector(expected, actual);

    favoriteCompanies = { {"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"} };
    actual = o.peopleIndexes(favoriteCompanies);
    expected = { 0,1 };
    check.checkIntVector(expected,actual);

    favoriteCompanies = { {"leetcode"},{"google"},{"facebook"},{"amazon"} };
    actual = o.peopleIndexes(favoriteCompanies);
    expected = { 0,1,2,3 };
    check.checkIntVector(expected,actual);

    favoriteCompanies = { {"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"} };
    actual = o.peopleIndexes(favoriteCompanies);
    expected = { 0,1,4 };
    check.checkIntVector(expected, actual);

    favoriteCompanies = { {"arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","zibvccaoayyihidztflj"},
        {"cffiqfviuwjowkppdajm","owqvnrhuzwqohquamvsz"},
        {"knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl"},
        {"arrtztkotazhufrsfczr","cffiqfviuwjowkppdajm"},
        {"arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl","zibvccaoayyihidztflj"}};
    actual = o.peopleIndexes(favoriteCompanies);
    expected = { 1,3,4 };
    check.checkIntVector(expected, actual);
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
