#ifndef PROTOCOL_INL_H_
#define PROTOCOL_INL_H_

#ifndef PROTOCOL_H_
#error "Protocol-inl.h" should be included only in "Protocol.h" file.
#endif

#include <iostream>

#include <Acmp.h>
#include <Ieeep.h>
#include "Commons.h"
#include "Encoder.h"

template<class ProtocolType, class ProtocolAnsType>
void Protocol::get_fields()
{
	std::cout << "Please enter output file name : " << std::endl;
	std::cin >> file_name;

	std::cout << "Please enter budget and consumed cost of "
			<< ProtocolType::to_string() << " Branch : " << std::endl;

	std::cin >> budget >> consumed;

	Encoder::encode<ProtocolAnsType>(file_name, budget, consumed);

}

void Protocol::get_input()
{
	int protocol_type;

	std::cout << "Please enter Protocol Type:" << std::endl
			<< "1- ACM PROTOCOL" << std::endl
			<< "2- IEEE PROTOCOL" << std::endl;
	std::cin >> protocol_type;

	switch (protocol_type)
	{
		case static_cast<int>(Commons::Protocols::AcmProtocol):
			get_fields<AcmProtocol, Acmp>();
			break;
		case static_cast<int>(Commons::Protocols::IeeeProtocol):
			get_fields<IeeeProtocol, Ieeep>();
			break;
		default:
			break;
	}
}

#endif
