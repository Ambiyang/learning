#include "string.h"
#include <openssl/pem.h>
#include <openssl/evp.h>

int mycb(char* buf, int num, int a, char* key)
{
	if (key)
		strcpy_s(buf, 100, key);
	else
	{
		if (a == 1)
			printf("Encrypt Password:\n");
		else
			printf("Decrypt Password:\n");
		scanf_s("%s", buf, 100);
	}
	return strlen(buf);
}

int main()
{
	int ret;
	BIO* out, * in;
	RSA* r, * read;
	int i, bits = 512;
	unsigned long e = RSA_3;
	BIGNUM* bne;
	const EVP_CIPHER* enc = NULL;
	bne = BN_new();
	ret = BN_set_word(bne, e);
	r = RSA_new();
	ret = RSA_generate_key_ex(r, bits, bne, NULL);
	if (ret != 1)
	{
		printf("RSA_generate_key_ex err!\n");
		return -1;
	}
	enc = EVP_des_ede3_ofb();
	out = BIO_new_file("pri.pem", "w");

	ret = PEM_write_bio_RSAPrivateKey(out, r, enc, NULL, 0, (pem_password_cb*)mycb, NULL);
	if (ret != 1)
	{
		RSA_free(r);
		BIO_free(out);
		return -1;
	}
	BIO_flush(out);
	BIO_free(out);
	out = BIO_new_file("pub.pem", "w");
	ret = PEM_write_bio_RSAPublicKey(out, r);
	if (ret != 1)
	{
		RSA_free(r);
		BIO_free(out);
		return -1;
	}
	BIO_flush(out);
	BIO_free(out);

	OpenSSL_add_all_algorithms();
	in = BIO_new_file("pri.pem", "rb");
	read = RSA_new();

	read = PEM_read_bio_RSAPrivateKey(in, &read, (pem_password_cb*)mycb, NULL);
	RSA_print_fp(stdout, read, 11);
	RSA_free(read);
	BIO_free(in);

	getchar();
	return 0;
}