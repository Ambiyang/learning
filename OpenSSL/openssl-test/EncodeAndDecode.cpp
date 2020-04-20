#include <string.h>
#include <openssl/evp.h>

int main()
{
	//EVP_ENCODE_CTX ectx,dctx;
	//this will cause compiler error: invalid use of incomplete type ‘EVP_CIPHER_CTX’
	//instead of direct declaration use EVP_ENCODE_CTX_new()
	//internal type (EVP_ENCODE_CTX) isn't allowed to be used any more
	//see https://github.com/openssl/openssl/issues/962
	EVP_ENCODE_CTX* ectx = EVP_ENCODE_CTX_new();
	EVP_ENCODE_CTX* dctx = EVP_ENCODE_CTX_new();

	unsigned char in[500], out[800], d[500];
	int inl, outl, i, total, ret, total2;
	EVP_EncodeInit(ectx);
	for (i = 0;i < 500;i++)
		memset(&in[i], i, 1);
	inl = 500;
	total = 0;
	EVP_EncodeUpdate(ectx, out, &outl, in, inl);
	total += outl;
	EVP_EncodeFinal(ectx, out + total, &outl);
	total += outl;
	printf("%s\n", out);
	printf("********\n");

	//To do:why is there no output after calling EVP_DecodeUpdate?
	EVP_DecodeInit(dctx);
	outl = 500;
	total2 = 0;
	ret = EVP_DecodeUpdate(dctx, d, &outl, out, total);
	if (ret < 0)
	{
		printf("EVP_DecodeUpdate err!\n");
		return -1;
	}
	total2 += outl;
	ret = EVP_DecodeFinal(dctx, d, &outl);
	total2 += outl;
	printf("%s\n", d);

	EVP_ENCODE_CTX_free(ectx);
	EVP_ENCODE_CTX_free(dctx);
	getchar();
	return 0;
}
