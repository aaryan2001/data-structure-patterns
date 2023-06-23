#include "LWZTable.h"
#include <cassert>

LZWTable::LZWTable(uint16_t aInitialCharacters):
	fIndex(128),
	fInitialCharacters(aInitialCharacters)
{
	initialize();
}

void LZWTable::initialize()
{
	for (uint16_t i=0; i<fInitialCharacters; i++)
	{
		fEntries[i] = PrefixString(i);
		fEntries[i].setCode(i);
	}
}

const PrefixString& LZWTable::lookupStart(char aK) const noexcept
{
	assert(fEntries[aK].w() != -1);
	return fEntries[aK];
}

bool LZWTable::contains(PrefixString& aWK) const noexcept
{
		assert(aWK.w() != -1);
		for (size_t i = 1023; i > aWK.w(); i--)
		{
			if (fEntries[i] == aWK)
			{
				aWK = fEntries[i];
				return true;
			}
		}
		return false;
}

void LZWTable::add(PrefixString& aWK) noexcept
{
	if (aWK.w() != -1)
	{
		aWK.setCode(fIndex);
		fEntries[fIndex++] = aWK;
	}
}
