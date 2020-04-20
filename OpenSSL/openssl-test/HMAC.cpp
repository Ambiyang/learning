#include <string.h>
#include <openssl/hmac.h>

int main()
{
	int i;
	unsigned char in[] = "Hello World!";
	size_t inl = strlen((const char*)in);
	unsigned char key[] = "123";
	unsigned char out[64];
	unsigned int outl;

	HMAC(EVP_md5(), key, sizeof key, in, inl, out, &outl);
	printf("EVP_md5 HMAC result :\n");
	for (i = 0;i < 16;i++)
		printf("%02x ", out[i]);

	HMAC(EVP_sha1(),key,sizeof key,in, inl, out, &outl);
	printf("\n\nEVP_sha1 HMAC result :\n");
	for (i = 0;i < 20;i++)
		printf("%02x ", out[i]);

	HMAC(EVP_sha256(), key, sizeof key, in, inl, out, &outl);
	printf("\n\nEVP_sha256 HMAC result :\n");
	for (i = 0;i < 32;i++)
		printf("%02x ", out[i]);

	HMAC(EVP_sha512(), key, sizeof key, in, inl, out, &outl);
	printf("\n\nEVP_sha512 HMAC result :\n");
	for (i = 0;i < 64;i++)
		printf("%02x ", out[i]);

	getchar();
	return 0;
}