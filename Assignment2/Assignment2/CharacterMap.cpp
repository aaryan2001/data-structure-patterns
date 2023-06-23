#include "CharacterMap.h"

#include <fstream>
#include <cassert>

CharacterMap::CharacterMap(unsigned char aCharacter = '\0', int aFrequency = 0) noexcept:
	fCharacter(aCharacter),
	fFrequency(aFrequency)
{
}

void CharacterMap::increment() noexcept
{
	fFrequency++;
}

void CharacterMap::setCharacter(unsigned char aCharacter) noexcept
{
	fCharacter = aCharacter;
}

bool CharacterMap::operator<(const CharacterMap& aOther) const noexcept
{
	return !(*this < aOther);
}

unsigned char CharacterMap::character() const noexcept
{
	return fCharacter;
}

size_t CharacterMap::frequency() const noexcept
{
	return fFrequency;
}
