#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <string>

#include "AcmProtocol.h"
#include "IeeeProtocol.h"

class Protocol
{
public:
	inline void get_input();
	template<class ProtocolType, class ProtocolAnsType>
	inline void get_fields();

private:
	std::string file_name;
	int budget;
	int consumed;
};

#include "Protocol-inl.h"
#endif
