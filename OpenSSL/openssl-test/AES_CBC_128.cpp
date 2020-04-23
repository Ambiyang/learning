#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>
#define AES_BITS 128
#define MSG_LEN 128

int aes_encrypt(char* in, char* key, char* out,int len)
{
	if (!in || !key || !out) return 0;
	unsigned char iv[AES_BLOCK_SIZE];
	for (int i = 0; i < AES_BLOCK_SIZE; ++i)
		iv[i] = 0;
	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)
	{
		return 0;
	}

	AES_cbc_encrypt((unsigned char*)in, (unsigned char*)out, len, &aes, iv, AES_ENCRYPT);
	return 1;
}
int aes_decrypt(char* in, char* key, char* out, int len)
{
	if (!in || !key || !out) return 0;
	unsigned char iv[AES_BLOCK_SIZE];
	for (int i = 0; i < AES_BLOCK_SIZE; ++i)
		iv[i] = 0;//0;
	AES_KEY aes;
	if (AES_set_decrypt_key((unsigned char*)key, 128, &aes) < 0)
	{
		return 0;
	}

	AES_cbc_encrypt((unsigned char*)in, (unsigned char*)out, len, &aes, iv, AES_DECRYPT);
	return 1;
}

int main()
{
	char sourceStringTemp[MSG_LEN];
	char dstStringTemp[MSG_LEN];
	memset((char*)sourceStringTemp, 0, MSG_LEN);
	memset((char*)dstStringTemp, 0, MSG_LEN);
	strcpy_s((char*)sourceStringTemp, 6,"HELLO");

	char key[AES_BLOCK_SIZE];
	int i;
	for (i = 0; i < 16; i++)
	{
		key[i] = 49;
	}

	// Pad according to https://www.devglan.com/online-tools/aes-encryption-decryption specification
	// without pad the result will be different from the above site's
	for (i = strlen(sourceStringTemp); i < 16; i++)
	{
		sourceStringTemp[i] = 0x0b;
	}

	if (!aes_encrypt(sourceStringTemp, key, dstStringTemp,16))
	{
		printf("encrypt error\n");
		return -1;
	}
	printf("enc %d:", strlen((char*)dstStringTemp));
	for (i = 0;i<16;i += 1) {
		printf("%x", (unsigned char)dstStringTemp[i]);
	}
	memset((char*)sourceStringTemp, 0, MSG_LEN);	

	if (!aes_decrypt(dstStringTemp, key, sourceStringTemp, 16))
	{
		printf("decrypt error\n");
		return -1;
	}
	printf("\n");
	printf("dec %d:", strlen((char*)sourceStringTemp));
	printf("%s\n", sourceStringTemp);
	for (i = 0;sourceStringTemp[i];i += 1) {
		printf("%02x", (unsigned char)sourceStringTemp[i]);
	}
	printf("\n");
	return 0;
}