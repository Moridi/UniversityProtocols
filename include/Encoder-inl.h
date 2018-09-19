#ifndef ENCODER_INL_H_
#define ENCODER_INL_H_

#ifndef ENCODER_H_
#error "Encoder-inl.h" should be included only in "Encoder.h" file.
#endif

#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <Acmp.h> /* ACM PROTOCOL ASN.1 type */

template<class ProtocolAnsType>
void Encoder::encode(const std::string& file_name, int budget, int consumed)
{
	ProtocolAnsType protocol;

	protocol.budget = budget;
	protocol.consumed = consumed;

	FILE* file_pointer = reinterpret_cast<FILE*>(fopen(file_name.c_str(), "wb"));
	xer_fprint(file_pointer, &asn_DEF_Acmp, &protocol);
	xer_fprint(stdout, &asn_DEF_Acmp, &protocol);
	fclose(file_pointer);
}

#endif
