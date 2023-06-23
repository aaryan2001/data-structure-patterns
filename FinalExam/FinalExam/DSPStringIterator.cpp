
// COS30008, Final Exam, 2023

#include "DSPStringIterator.h"

DSPStringIterator::DSPStringIterator( const DSPString& aCollection ) :
	fCollection( std::make_shared<DSPString>( aCollection ) ),
	fIndex( 0 )
{}

char DSPStringIterator::operator*() const noexcept
{
	return (*fCollection)[fIndex]; // 4a)
}

DSPStringIterator& DSPStringIterator::operator++() noexcept
{
	++fIndex; // 4b)
	return *this;
}

DSPStringIterator DSPStringIterator::operator++( int ) noexcept
{
	DSPStringIterator old = *this;

	++(*this);

	return old;
}

DSPStringIterator& DSPStringIterator::operator--() noexcept
{
	--fIndex; // 4c)
	return *this;
}

DSPStringIterator DSPStringIterator::operator--( int ) noexcept
{
	DSPStringIterator old = *this;

	--(*this);

	return old;
}

bool DSPStringIterator::operator==(const DSPStringIterator& aOther) const noexcept
{
	return (fCollection == aOther.fCollection && fIndex == aOther.fIndex); // 4d)
}

bool DSPStringIterator::operator!=( const DSPStringIterator& aOther ) const noexcept
{
	return !(*this == aOther);
}

DSPStringIterator  DSPStringIterator::begin() const noexcept
{
	DSPStringIterator lResult = *this;
	lResult.fIndex = 0;
	return lResult;
}

DSPStringIterator DSPStringIterator::end() const noexcept
{
	DSPStringIterator lResult = *this;
	lResult.fIndex = static_cast<int>(fCollection->size());
	return lResult;
}

DSPStringIterator DSPStringIterator::rbegin() const noexcept
{
	DSPStringIterator lResult = *this;
	lResult.fIndex = static_cast<int>(fCollection->size()) - 1;
	return lResult;
}

DSPStringIterator DSPStringIterator::rend() const noexcept
{
	return DSPStringIterator(*fCollection, -1); // 4h)
}
