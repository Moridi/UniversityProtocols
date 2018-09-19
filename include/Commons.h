#ifndef COMMONS_H_
#define COMMONS_H_

#include <cstdlib>

class Commons
{
public:
	enum class Protocols : uint8_t
	{
		AcmProtocol = 1,
		IeeeProtocol = 2
	};
};

#include "Commons-inl.h"
#endif
