/* 四因数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，请你返回该数组中恰有四个因数的这些整数的各因数之和。

如果数组中不存在满足题意的整数，则返回 0 。

 

示例：

输入：nums = [21,4,7]
输出：32
解释：
21 有 4 个因数：1, 3, 7, 21
4 有 3 个因数：1, 2, 4
7 有 2 个因数：1, 7
答案仅为 21 的所有因数的和。
 

提示：

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/four-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution() {
        maxNum = 100000;
        primes.resize(maxNum + 1, 1);
        Eratosthenes(primes);
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += get4DivisorsSum(num);
        }

        return sum;
    }

    void Eratosthenes(vector<int>& primes) {
        primes[1] = 0;

        for (int i = 2; i < sqrt(maxNum); ++i) {  // 如果n=i*i，则n不是质数，所以只需要循环到(i * i) < n就可以了
            if (primes[i] == 0) {
                continue;
            }

            for (int j = (i * i); j < maxNum; j += i) {  // i的小于i的倍数都已经排除过了，现在只需要排除更大的i的倍数
                primes[j] = 0;
            }
        }
    }

    int get4DivisorsSum(int num) {
        for (int i = 2; i <= sqrt(num); ++i) {
            if (i * i * i == num) {  // 4因子只有两种可能：1、num是某个数的3次方，比如27：1，3，9，27
                return 1 + i + i * i + num;
            }

            int divisor = num / i;
            if (divisor * i != num) {
                continue;
            }

            if (divisor == i || primes[i] == 0 || primes[divisor] == 0) {  // 2、num是2个不同质数的乘积，比如15：1，3，5，15
                break;
            }

            return 1 + i + divisor + num;
        }

        return 0;
    }

private:
    vector<int> primes;
    int maxNum;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 21,4,7 };
    check.checkInt(32, o.sumFourDivisors(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(45, o.sumFourDivisors(nums));

    nums = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
    51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90 };
    check.checkInt(1822, o.sumFourDivisors(nums));
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
