#include <stdio.h>
#include <openssl/rsa.h>

// If the console print error  like OPENSSL_Uplink（00110010,01): no OPENSSL_Applink
// Try to set project property c/c++--> code generation  --> Runtime libray = Multi-threaded DLL
int main()
{
	RSA* r;
	int bits = 512, ret;
	unsigned long e = RSA_3;
	BIGNUM* bne;

	r = RSA_generate_key(bits, e, NULL, NULL);
	RSA_print_fp(stdout, r, 11);
	RSA_free(r);
	printf("\n");

	bne = BN_new();
	ret = BN_set_word(bne, e);
	r = RSA_new();
	ret = RSA_generate_key_ex(r, bits, bne, NULL);
	if (ret != 1)
	{
		printf("RSA_generate_key_ex err!\n");
		return -1;
	}
	RSA_print_fp(stdout, r, 11);
	RSA_free(r);

	getchar();
	return 0;
}
