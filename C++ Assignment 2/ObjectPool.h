#pragma once

#include <vector>
#include <cstdlib>

template<typename T>
class ObjectPool {
private:
	std::vector<T> objects;

public:
	void Add(const T& object) {
		objects.push_back(object);
	}

	size_t GetSize() const {
		return objects.size();
	}

	// check if pool is empty
	bool IsEmpty() const {
		return objects.empty();
	}

	T Acquire() {
		int index = rand() % objects.size();
		T selected = objects[index];
		objects.erase(objects.begin() + index);
		return selected;
	}

	void Release(const T& object) {
		objects.push_back(object);
	}
};