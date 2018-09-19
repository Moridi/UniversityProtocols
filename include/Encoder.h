#ifndef ENCODER_H_
#define ENCODER_H_

class Encoder
{
public:
	inline Encoder();

	template<class ProtocolAnsType>
	static void encode(const std::string& file_name, int budget, int consumed);
};

#include "Encoder-inl.h"
#endif
