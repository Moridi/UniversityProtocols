#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <Acmp.h> /* Acmp ASN.1 type */
/* Write the encoded output into some FILE stream. */
static int write_out(const void *buffer, size_t size, void *app_key) {
FILE *out_fp = (FILE *)app_key;
size_t wrote = fwrite(buffer, 1, size, out_fp);
return (wrote == size) ? 0 : -1;
}
int main() {
Acmp_t *acmp; /* Type to encode */
asn_enc_rval_t ec; /* Encoder return value */
/* Allocate the Acmp_t */
acmp = (Acmp_t*)calloc(1, sizeof(Acmp_t)); /* not malloc! */

/* Initialize the Acmp members */
acmp->height = 42; /* any random value */
acmp->width = 23; /* any random value */
/* BER encode the data if filename is given */
const char *filename = "acmp.xer";
FILE *fp = (FILE *)fopen(filename, "wb"); /* for BER output */

/* Encode the Acmp type as BER (DER) */
ec = der_encode(&asn_DEF_Acmp, acmp, write_out, fp);
fclose(fp);

/* Also print the constructed Acmp XER encoded (XML) */
xer_fprint(stdout, &asn_DEF_Acmp, acmp);


{
	char buf[1024];
	FILE *fp = fopen(filename, "rb");
	size_t size = fread(buf, 1, sizeof(buf), fp);
	asn_dec_rval_t rval = ber_decode(0, &asn_DEF_Acmp, (void **)&acmp, buf, size);
	xer_fprint(stdout, &asn_DEF_Acmp, acmp);
}
return 0; /* Encoding finished successfully */
}
