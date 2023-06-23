
// COS30008, Final Exam, 2023

#include "DSPString.h"

#include <cassert>
#include <algorithm>

DSPString::DSPString( const char* aContents )
{
	size_t lSize = 0;

	while ( aContents[lSize] )
	{
		lSize++;
	}

	fContents = new char[++lSize];

	for ( size_t i = 0; i < lSize; i++ )
	{
		fContents[i] = aContents[i];
	}
}

DSPString::~DSPString()
{
	delete[] fContents; //3c
	fContents = nullptr;
}

DSPString::DSPString( const DSPString& aOther ) :
	DSPString( aOther.fContents )
{}

DSPString& DSPString::operator=(const DSPString& aOther)
{
	if (this != &aOther)
	{
		delete[] fContents; // 3d)
		fContents = nullptr;
		size_t lSize = aOther.size();
		fContents = new char[lSize + 1];
		for (size_t i = 0; i <= lSize; i++)
		{
			fContents[i] = aOther.fContents[i];
		}
	}
	return *this;
}

DSPString::DSPString( DSPString&& aOther ) noexcept :
	DSPString( "\0" )
{
	std::swap(fContents, aOther.fContents); //3e

}

DSPString& DSPString::operator=(DSPString&& aOther) noexcept
{
	if (this != &aOther)
	{
		std::swap(fContents, aOther.fContents);
	}

	return *this; //3f
}

size_t DSPString::size() const noexcept
{
	size_t lSize = 0;
	if (fContents)
	{
		while (fContents[lSize] != '\0')
		{
			lSize++;
		}
	}

	return lSize; //3g
}

char DSPString::operator[](size_t aIndex) const noexcept
{
	assert(aIndex < size()); // 3h)
	return fContents[aIndex];
}

bool DSPString::operator==( const DSPString& aOther ) const noexcept
{
	if ( size() == aOther.size() )
	{
		for ( size_t i = 0; i < size(); i++ )
		{
			if ( fContents[i] != aOther.fContents[i] )
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& aOStream, const DSPString& aObject)
{
	aOStream << aObject.fContents; // 3i)
	return aOStream;
}
