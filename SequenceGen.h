#pragma once

#include <vector>

#include "Drink.h"
#include "ObjectPool.h"

class SequenceGen {
private:
	std::vector<Drink> sequence;

public:
	void Generate(ObjectPool<Drink>& pool);
	const std::vector<Drink>& GetSequence() const;
	void ReleaseSequence(ObjectPool<Drink>& pool);
};