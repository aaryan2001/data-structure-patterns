#include "CharacterFrequencyIterator.h"

void CharacterFrequencyIterator::mapIndices() noexcept
{

	for (size_t i = 0; i < fCollection->count(); i++)
	{
		if ((*fCollection)[i].key() == fIndex)
		{
			fIndex = i;
			break;
		}
	}

}

CharacterFrequencyIterator::CharacterFrequencyIterator(const CharacterCounter* aCollection) noexcept:
	fCollection(aCollection),
	fIndex(0)
{
	mapIndices();
}

const CharacterMap& CharacterFrequencyIterator::operator*() const noexcept
{
	return (*fCollection)[fIndex];
}

CharacterFrequencyIterator& CharacterFrequencyIterator::operator++() noexcept
{
	fIndex++;

	mapIndices();

	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator::operator++(int) noexcept
{
	CharacterFrequencyIterator old = *this;

	++(*this);

	return old;
}

bool CharacterFrequencyIterator::operator==(const CharacterFrequencyIterator& aOther) const noexcept
{
	return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool CharacterFrequencyIterator::operator!=(const CharacterFrequencyIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

CharacterFrequencyIterator CharacterFrequencyIterator::begin() const noexcept
{
	return CharacterFrequencyIterator(fCollection);
}

CharacterFrequencyIterator CharacterFrequencyIterator::end() const noexcept
{
	CharacterFrequencyIterator result = begin();
	result.fIndex = fCollection->count();
	return result;

}
