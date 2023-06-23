#include "CharacterCounter.h"

#include <fstream>
#include <cassert>

CharacterCounter::CharacterCounter() noexcept
{
    for (int i = 0; i < 256; i++) {
        fCharacterCounts[i].setCharacter(i);
    }
}

void CharacterCounter::count(unsigned char aCharacter) noexcept
{
    fCharacterCounts[aCharacter].increment();
    fTotalNumberOfCharacters++;
}

const CharacterMap& CharacterCounter::operator[](unsigned char aCharacter) const noexcept
{
	return fCharacterCounts[aCharacter];
}
