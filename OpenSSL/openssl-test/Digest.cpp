#include <stdio.h>
#include <string.h>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

int main()
{
	unsigned char in[] = "Hello World!";
	unsigned char out[64];
	size_t n;
	int i;
	n = strlen((const char*)in);

	MD4(in, n, out);
	printf("MD4 digest result :\n");
	for (i = 0;i < 16;i++)
		printf("%02x ", out[i]);


	MD5(in, n, out);
	printf("\n\nMD5 digest result :\n");
	for (i = 0;i < 16;i++)
		printf("%02x ", out[i]);


	SHA1(in, n, out);
	printf("\n\nSHA1 digest result :\n");
	for (i = 0;i < 20;i++)
		printf("%02x ", out[i]);


	SHA256(in, n, out);
	printf("\n\nSHA256 digest result :\n");
	for (i = 0;i < 32;i++)
		printf("%02x ", out[i]);


	SHA512(in, n, out);
	printf("\n\nSHA512 digest result :\n");
	for (i = 0;i < 64;i++)
		printf("%02x ", out[i]);
	printf("\n");

	getchar();
	return 0;
}