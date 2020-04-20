#include <openssl/x509.h>

int main()
{
	X509* x;
	FILE* fp;
	unsigned char buf[5000], * p;
	int len, ret;
	BIO* b;
	errno_t err;

	err = fopen_s(&fp,"cert.cer", "rb");
	if (err) return -1;

	len = fread(buf, 1, 5000, fp);
	fclose(fp);
	p = buf;
	x = X509_new();
	d2i_X509(&x, (const unsigned char**)&p, len);
	b = BIO_new(BIO_s_file());
	BIO_set_fp(b, stdout, BIO_NOCLOSE);
	ret = X509_print(b, x);
	BIO_free(b);
	X509_free(x);

	getchar();
	return 0;
}
