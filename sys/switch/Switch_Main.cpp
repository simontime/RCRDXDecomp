#include <cstdio>

#include "../../Hash.h"

#define nnMain main // For testing purposes.

int nnMain(int argc, char **argv)
{
	const char *testStr = "Test string hash";
	printf("%s: %x\n", testStr, Hash::FromStr(testStr));
	return 0;
}