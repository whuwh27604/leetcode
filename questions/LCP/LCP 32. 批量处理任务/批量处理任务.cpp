/* 批量处理任务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某实验室计算机待处理任务以 [start,end,period] 格式记于二维数组 tasks，表示完成该任务的时间范围为起始时间 start 至结束时间 end 之间，需要计算机投入 period 的时长，注意：

period 可为不连续时间
首尾时间均包含在内
处于开机状态的计算机可同时处理任意多个任务，请返回电脑最少开机多久，可处理完所有任务。

示例 1：

输入：tasks = [[1,3,2],[2,5,3],[5,6,2]]

输出：4

解释： tasks[0] 选择时间点 2、3； tasks[1] 选择时间点 2、3、5； tasks[2] 选择时间点 5、6； 因此计算机仅需在时间点 2、3、5、6 四个时刻保持开机即可完成任务。

示例 2：

输入：tasks = [[2,3,1],[5,5,1],[5,6,2]]

输出：3

解释： tasks[0] 选择时间点 2 或 3； tasks[1] 选择时间点 5； tasks[2] 选择时间点 5、6； 因此计算机仅需在时间点 2、5、6 或 3、5、6 三个时刻保持开机即可完成任务。

提示：

2 <= tasks.length <= 10^5
tasks[i].length == 3
0 <= tasks[i][0] <= tasks[i][1] <= 10^9
1 <= tasks[i][2] <= tasks[i][1]-tasks[i][0] + 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] < v2[1];  // 按照end排序
}

class Section {
public:
	int start;
	int end;
	int runTime;  // [section[0].start, end]区间内，一共运行了多少秒

	Section(int s, int e) : start(s), end(e), runTime(0) {}
	Section(int s, int e, int r) : start(s), end(e), runTime(r) {}

	bool operator<(const Section& o) const {
		return start == o.start ? end < o.end : start < o.start;  // 按照start排序
	}
};

class Solution {
public:
	int processTasks(vector<vector<int>>& tasks) {
		int size = (int)tasks.size();
		sort(tasks.begin(), tasks.end(), vectorCompare);
		vector<Section> sections = { Section(tasks[0][1] - tasks[0][2] + 1, tasks[0][1], tasks[0][2]) };

		for (int i = 1; i < size; ++i) {
			int start = tasks[i][0], end = tasks[i][1], period = tasks[i][2];
			int runTime = getRunTime(sections, start, end);  // [start, end]区间内，已经运行了多少秒
			if (runTime < period) {
				assignTime(sections, end, period - runTime);
			}
		}

		return sections.back().runTime;
	}

	int getRunTime(vector<Section>& sections, int start, int end) {
		Section section(start, 0);
		auto iter = lower_bound(sections.begin(), sections.end(), section);
		if (iter == sections.begin()) {  // 如果第一个区间就大于start，那么所有区间都在[start, end]范围内
			return sections.back().runTime;
		}

		--iter;  // 指向第一个小于start的区间
		int runTime = sections.back().runTime - iter->runTime;  // 该区间后续所有区间的和
		if (iter->end >= start) {  // 如果该区间和[start, end]有交集，需要加上来
			runTime += (iter->end - start + 1);
		}

		return runTime;
	}

	void assignTime(vector<Section>& sections, int end, int time) {
		int available = end - sections.back().end;  // 最后一段可用时间
		if (available > time) {  // 时间已够用，分配一段新的区间
			sections.push_back(Section(end - time + 1, end, sections.back().runTime + time));
			return;
		}

		sections.back().end = end;  // 最后一个区间延长到end
		sections.back().runTime += available;
		time -= available;

		while (time != 0) {  // 从前面区间的空隙继续分配时间
			Section section1 = sections.back();
			sections.pop_back();

			if (sections.empty()) {  // 最后一个区间了，start时间往前移
				section1.start -= time;
				section1.runTime += time;
				sections.push_back(section1);
				time = 0;
			}
			else {
				Section& section2 = sections.back();
				available = section1.start - section2.end - 1;
				if (available > time) {  // 时间够了，最后一个区间的start往前移
					section1.start -= time;
					section1.runTime += time;
					sections.push_back(section1);
					time = 0;
				}
				else {  // 把最后两个区间合并
					section2.end = section1.end;
					section2.runTime = (section1.runTime + available);
					time -= available;
				}
			}
		}
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> tasks = { {1,3,2},{2,5,3},{5,6,2} };
	check.checkInt(4, o.processTasks(tasks));

	tasks = { {2,3,1},{5,5,1},{5,6,2} };
	check.checkInt(3, o.processTasks(tasks));

	tasks = { {10,42,6},{47,81,35},{38,58,13},{39,48,4},{12,62,24},{54,73,1},{59,96,34},{65,91,20} };
	check.checkInt(54, o.processTasks(tasks));

	tasks = { {2,3,1},{4,5,1},{1,6,6} };
	check.checkInt(6, o.processTasks(tasks));
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
