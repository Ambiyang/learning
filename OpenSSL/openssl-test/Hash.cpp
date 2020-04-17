#include <string.h>
#include <openssl/lhash.h>
#include <stdio.h>

//#pragma comment(lib,"C:\\Program Files (x86)\\OpenSSL\\lib\\libssl.lib")
//#pragma comment(lib,"C:\\Program Files (x86)\\OpenSSL\\lib\\libcrypto.lib")

typedef struct Student_st
{
	char name[20];
	int age;
	char otherInfo[200];
}Student;

static int Student_cmp(const void* a, const void* b)
{
	char* namea = ((Student*)a)->name;
	char* nameb = ((Student*)b)->name;
	return strcmp(namea, nameb);
}

static void PrintValue(void* a)
{
	printf("name :%s\n", ((Student*)a)->name);
	printf("age :%d\n", ((Student*)a)->age);
	printf("otherInfo : %s\n\n", ((Student*)a)->otherInfo);
}

static void PrintValue_arg(void* a, void* b)
{
	int flag = 0;
	flag = *(int*)b;
	printf("para:%d\n", flag);
	printf("name :%s\n", ((Student*)a)->name);
	printf("age :%d\n", ((Student*)a)->age);
	printf("otherInfo : %s\n\n", ((Student*)a)->otherInfo);
}

int main()
{
	int flag = 11;
	OPENSSL_LHASH* h;
	Student s1 = { "zcp",28,"hu bei" },
			s2 = { "forxy",28,"no info" },
			s3 = { "skp",24,"student" },
			s4 = { "zhao_zcp",28,"zcp's name" },
			* s5;
	void* data;

	h = lh_new(NULL, Student_cmp);
	if (h == NULL)
	{
		printf("err.\n");
		return -1;
	}

	data = &s1;
	lh_insert(h, data);
	data = &s2;
	lh_insert(h, data);
	data = &s3;
	lh_insert(h, data);
	data = &s4;
	lh_insert(h, data);

	lh_doall(h, PrintValue);
	lh_doall_arg(h, PrintValue_arg, (void*)(&flag));

	data = lh_retrieve(h, (const void*)"skp");
	if (data == NULL)
	{
		printf("can not look up skp!\n");
		lh_free(h);
		return -1;
	}

	s5 = ((Student*)data);
	printf("***Found skp in hash***\n");
	printf("student name : %s\n", s5->name);
	printf("sutdent age : %d\n", s5->age);
	printf("student otherinfo : %s\n", s5->otherInfo);

	lh_free(h);
	getchar();
	return 0;
}