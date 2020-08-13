#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <list>
#include <vector>

using namespace std;

class Iterator {
public:
	struct Data {
		list<int> dataList;
	};
	Data* data;

	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	//Returns true if the iteration has more elements.
	bool hasNext() const;
};

Iterator::Iterator(const vector<int>& nums) {
	data = new Data;
	for (int n : nums) {
		data->dataList.push_back(n);
	}
}

Iterator::Iterator(const Iterator& iter) {

}

int Iterator::next() {
	int n = data->dataList.front();
	data->dataList.pop_front();

	return n;
}

bool Iterator::hasNext() const {
	return (!data->dataList.empty());
}

#endif