/* 雇佣 K 名工人的最低成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 N 名工人。 第 i 名工人的工作质量为 quality[i] ，其最低期望工资为 wage[i] 。

现在我们想雇佣 K 名工人组成一个工资组。在雇佣 一组 K 名工人时，我们必须按照下述规则向他们支付工资：

对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
工资组中的每名工人至少应当得到他们的最低期望工资。
返回组成一个满足上述条件的工资组至少需要多少钱。

 

示例 1：

输入： quality = [10,20,5], wage = [70,50,30], K = 2
输出： 105.00000
解释： 我们向 0 号工人支付 70，向 2 号工人支付 35。
示例 2：

输入： quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
输出： 30.66667
解释： 我们向 0 号工人支付 4，向 2 号和 3 号分别支付 13.33333。
 

提示：

1 <= K <= N <= 10000，其中 N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
与正确答案误差在 10^-5 之内的答案将被视为正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-hire-k-workers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Worker {
public:
    int quality;
    int wage;
    double rate;

    Worker() : quality(0), wage(0), rate(0) {}
    Worker(int _quality, int _wage) : quality(_quality), wage(_wage), rate((double)wage / quality) {}

    bool operator< (const Worker& worker) const {
        return rate < worker.rate;
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        /* 假设选择的k个人为Worker[1]、Worker[2]...Worker[k]，他们的quality之和为sum
           1、这k个人中，只有一个人会拿到他实际的wage，其他人因为按照比例，会拿到比自己wage多的钱。
           2、假设这个人是i，那么总钱数就是Worker[i].wage/(Worker[i].quality/sum)
           3、其他人拿的钱是Worker[i].wage/(Worker[i].quality/sum)*(Worker[j].quality/sum)=Worker[i].wage*Worker[j].quality/Worker[i].quality > Worker[j].wage
              即Worker[i].wage/Worker[i].quality > Worker[j].wage/Worker[j].quality，这说明其他人的比例会小于这个人。
           4、总钱数只和sum相关，sum越小钱数越小。所以需要找到rate小于Worker[i].rate的quality最小的k-1个人。 */
        vector<Worker> workers(wage.size());
        getWorkers(quality, wage, workers);
        sort(workers.begin(), workers.end());

        priority_queue<int> qualities;
        int sum = getSum(workers, qualities, K);

        return getMinCost(workers, qualities, K, sum);
    }

    void getWorkers(vector<int>& quality, vector<int>& wage, vector<Worker>& workers) {
        for (int i = 0; i < (int)wage.size(); ++i) {
            workers[i] = Worker(quality[i], wage[i]);
        }
    }

    int getSum(vector<Worker>& workers, priority_queue<int>& qualities, int K) {
        int sum = 0;

        for (int i = 0; i < K - 1; ++i) {  // 注意队列里面只有k-1个数，因为按照wage拿钱的那个人占了一个，只需要选择剩下k-1个最小的quality
            qualities.push(workers[i].quality);
            sum += workers[i].quality;
        }

        return sum + workers[K - 1].quality;
    }

    double getMinCost(vector<Worker>& workers, priority_queue<int>& qualities, int K, int& sum) {
        double minCost = workers[K - 1].rate * sum;

        for (int i = K; i < (int)workers.size(); ++i) {
            qualities.push(workers[i - 1].quality);
            sum += (workers[i].quality - qualities.top());
            minCost = min(minCost, workers[i].rate * sum);
            qualities.pop();
        }

        return minCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> quality = { 10,20,5 };
    vector<int> wage = { 70,50,30 };
    check.checkDouble(105, o.mincostToHireWorkers(quality, wage, 2));

    quality = { 3,1,10,10,1 };
    wage = { 4,8,2,2,7 };
    check.checkDouble(30.666667, o.mincostToHireWorkers(quality, wage, 3));

    quality = { 3 };
    wage = { 4 };
    check.checkDouble(4, o.mincostToHireWorkers(quality, wage, 1));
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
