#include "PrefixString.h"

PrefixString::PrefixString(char aExtension) noexcept:
	fPrefix(-1),
	fExtension(aExtension)
{
	fCode = -1;
}

PrefixString::PrefixString(uint16_t aPrefix, char aExtension) noexcept :
	fPrefix(aPrefix),
	fExtension(aExtension)
{
	fCode = -1;
}

uint16_t PrefixString::getCode() const noexcept
{
	return fCode;
}

void PrefixString::setCode(uint16_t aCode) noexcept
{
	fCode = aCode;
}

uint16_t PrefixString::w() const noexcept
{
	return fPrefix;
}

char PrefixString::K() const noexcept
{
	return fExtension;
}

PrefixString PrefixString::operator+(char aExtension) const noexcept
{
	if (fCode != -1)
	{
		PrefixString newt = PrefixString(fCode, aExtension);
		return newt;
	}
}

bool PrefixString::operator==(const PrefixString& aOther) const noexcept
{
	return aOther.K() == fExtension && aOther.w() == fPrefix;
}

std::ostream& operator<<(std::ostream& aOStream, const PrefixString& aObject)
{
	return aOStream << "(" << aObject.getCode() << "," << aObject.w() << "," << aObject.K() << ")";
}
