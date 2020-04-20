#include <stdio.h>
#include <openssl/bn.h>
#include <openssl/bio.h>
#include <openssl/rand.h>

int main()
{
	puts("------Method 1------");
	BIGNUM* bn;
	bn = BN_new(); //generate a BIGNUM struct
	int bitLen = 8;
	int top = -1;
	int bottom = 1;

	for (int i = 0;i <= 20;i++)
	{
		BN_rand(bn, bitLen, top, bottom); //generate a bitLen length random number
		char* a = BN_bn2hex(bn); //conver to hex string
		puts(a);
	}

	puts("------Method 2------");
	unsigned char rkey[6];
	RAND_pseudo_bytes(rkey, sizeof rkey);
	for (int i = 0;i < 6; i++)
	{
		printf("%x ", rkey[i]);
	}

	puts("");
	puts("------Method 3------");
	RAND_bytes(rkey, 6);
	for (int i = 0;i < 6; i++)
	{
		printf("%x ", rkey[i]);
	}
	
	//--------End----------
	BN_free(bn); //release
	getchar();
	return 0;
}


