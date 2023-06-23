#include "LZWCompressor.h"

LZWCompressor::LZWCompressor(const std::string& aInput) :
	fIndex(0),
	fCurrentCode(0),
	fInput(aInput),
	fK(0)
{
	start();
}

bool LZWCompressor::readK() noexcept
{
	if (fIndex < fInput.size())
	{
		fK = fInput[fIndex++];
		return true;
	}
	fK = -1;
	return false;
}

void LZWCompressor::start()
{
	if (fIndex == 0) {
		fTable.initialize();
		fK = fInput[fIndex++];
		fW = fTable.lookupStart(fK);
		fCurrentCode = nextCode();
	}
}


uint16_t LZWCompressor::nextCode()
{
	/*
	if (fK == -1) {
		return fCurrentCode;
	}
	while (readK()) {
		if (fK != -1) {
			PrefixString fW == fCurrentCode;
		}
	}
	return fW.getCode();
	*/
	return true;
}


const uint16_t& LZWCompressor::operator*() const noexcept
{
	return fCurrentCode;
}

LZWCompressor& LZWCompressor::operator++() noexcept
{
	fCurrentCode = nextCode();
	return *this;
}

LZWCompressor LZWCompressor::operator++(int) noexcept
{
	LZWCompressor tempint(*this);
	++(*this);
	return tempint;
}

bool LZWCompressor::operator==(const LZWCompressor& aOther) const noexcept
{
	return fInput == aOther.fInput && fIndex == aOther.fIndex
		&& fK == aOther.fK && fCurrentCode == aOther.fCurrentCode;
}

bool LZWCompressor::operator!=(const LZWCompressor& aOther) const noexcept
{
	return !(*this == aOther);
}

LZWCompressor LZWCompressor::begin() const noexcept
{
	LZWCompressor copy = *this;
	copy.fIndex = 0;
	return copy;
}

LZWCompressor LZWCompressor::end() const noexcept
{
	LZWCompressor scopy = *this;
	scopy.fIndex = 128;
	return scopy;
}
