/* 奖励最顶尖的 K 名学生.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 positive_feedback 和 negative_feedback ，分别包含表示正面的和负面的词汇。不会 有单词同时是正面的和负面的。

一开始，每位学生分数为 0 。每个正面的单词会给学生的分数 加 3 分，每个负面的词会给学生的分数 减  1 分。

给你 n 个学生的评语，用一个下标从 0 开始的字符串数组 report 和一个下标从 0 开始的整数数组 student_id 表示，其中 student_id[i] 表示这名学生的 ID ，这名学生的评语是 report[i] 。每名学生的 ID 互不相同。

给你一个整数 k ，请你返回按照得分 从高到低 最顶尖的 k 名学生。如果有多名学生分数相同，ID 越小排名越前。



示例 1：

输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
输出：[1,2]
解释：
两名学生都有 1 个正面词汇，都得到 3 分，学生 1 的 ID 更小所以排名更前。
示例 2：

输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
输出：[2,1]
解释：
- ID 为 1 的学生有 1 个正面词汇和 1 个负面词汇，所以得分为 3-1=2 分。
- ID 为 2 的学生有 1 个正面词汇，得分为 3 分。
学生 2 分数更高，所以返回 [2,1] 。


提示：

1 <= positive_feedback.length, negative_feedback.length <= 104
1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
positive_feedback[i] 和 negative_feedback[j] 都只包含小写英文字母。
positive_feedback 和 negative_feedback 中不会有相同单词。
n == report.length == student_id.length
1 <= n <= 104
report[i] 只包含小写英文字母和空格 ' ' 。
report[i] 中连续单词之间有单个空格隔开。
1 <= report[i].length <= 100
1 <= student_id[i] <= 109
student_id[i] 的值 互不相同 。
1 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Student {
public:
    int id;
    int score;

    Student() : id(0), score(0) {}
    Student(int i, int s) : id(i), score(s) {}

    bool operator<(const Student& o) const {
        return score == o.score ? id < o.id : score > o.score;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = report.size();
        vector<Student> scores(n);
        vector<int> topK(k);
        unordered_set<string> positive, negative;

        getFeedback(positive_feedback, positive);
        getFeedback(negative_feedback, negative);

        for (int i = 0; i < n; ++i) {
            scores[i] = Student(student_id[i], getScore(positive, negative, report[i]));
        }

        sort(scores.begin(), scores.end());

        for (int i = 0; i < k; ++i) {
            topK[i] = scores[i].id;
        }

        return topK;
    }

    void getFeedback(vector<string>& feedback, unordered_set<string>& feedbackSet) {
        for (string& word : feedback) {
            feedbackSet.insert(word);
        }
    }

    int getScore(unordered_set<string>& positive_feedback, unordered_set<string>& negative_feedback, string& report) {
        int i = 0, j = 0, size = report.size(), score = 0;

        while (i < size) {
            for (j = i + 1; j < size && report[j] != ' '; ++j) {}
            string word(report, i, j - i);
            if (positive_feedback.count(word) != 0) {
                score += 3;
            }
            else if (negative_feedback.count(word) != 0) {
                score -= 1;
            }

            i = j + 1;
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> positive_feedback = { "smart","brilliant","studious" };
    vector<string> negative_feedback = { "not" };
    vector<string> report = { "this student is studious","the student is smart" };
    vector<int> student_id = { 1,2 };
    vector<int> actual = o.topStudents(positive_feedback, negative_feedback, report, student_id, 2);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    positive_feedback = { "smart","brilliant","studious" };
    negative_feedback = { "not" };
    report = { "this student is not studious","the student is smart" };
    student_id = { 1,2 };
    actual = o.topStudents(positive_feedback, negative_feedback, report, student_id, 2);
    expected = { 2,1 };
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
