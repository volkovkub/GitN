#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#pragma argsused

#include "deff.hpp"

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
short mainw(short ac, char *av[]) {
	int ret = 0;
	struct bsp *b;
	ret = l_call(av[0],av[1],av[2]);
	return ret;
}
