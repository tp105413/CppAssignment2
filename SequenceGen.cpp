#include "SequenceGen.h"

void SequenceGen::Generate(ObjectPool<Drink>& pool) {
	ReleaseSequence(pool);

	for (int i = 0; i < 4; i++) {
		sequence.push_back(pool.Acquire());
	}
}

const std::vector<Drink>& SequenceGen::GetSequence() const {
	return sequence;
}

void SequenceGen::ReleaseSequence(ObjectPool<Drink>& pool) {
	for (const Drink& drink : sequence) {
		pool.Release(drink);
	}
	sequence.clear();
}