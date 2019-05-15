// ---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
// ---------------------------------------------------------------------------
#include "deff.hpp"
#include "wtzp.h"
#include "..\ZPBANK.RAD\banks.h"

extern struct compar *c_p;

#include "UDM.h"
#include "spr0001.h" // ���������� ����� ����
#include "spr0002.h" // ����� ����� ����������/���������
#include "spr0003.h" // ���������� ��� �����
#include "spr0004.h" // ���������� ��� ���������������� ����������
#include "spr0005.h" // ����� ���������� ��������������
#include "spr0006.h" // ����� ����������
#include "spr0007.h" // ����� �����������
#include "spr0008.h" // ���������� ����� �������
#include "spr0009.h" // ���������� ������������ ����� ZP � ��
#include "spr0010.h" // ���������� ����� � �� 5
#include "spr0011.h" // ���������� ���������� �������
#include "spr0012.h" // ����.����� ��� �������.
#include "spr0013.h" // ���������� ����� ����
#include "spr0014.h" // ������������� �������� �����/������
#include "spr0016.h" // ������������� �������� �����/������
//VDS 28/02/2019 #include "spr0017.h" // ���������� �������������  ���������� ���������� ����� 2012
#include "spr0018.h" // ���������� �����/�������������
#include "spr0019.h" // ����������
#include "spr0020.h" // ������� ����������
#include "spr0021.h" // ���������� �����
#include "spr0022.h" // ����� ����������� (� ����������� �� ���������)
#include "spr0023.h" // ���������� �������������
#include "spr0024.h" // ����� ���������� �������������� � ��������� �������� ��
#include "spr0025.h" // ����� ��������� �������������� �� ��������� � ���������
#include "spr0026.h" // ���������� ������������
#include "spr0028.h" // ���������� �������
#include "spr0029.h" // ������� ������������ ��� "��������"
#include "spr0030.h" // ������� ������������ ��� "��������"
#include "spr0032.h" // ���������� ��� ����� ���������� � ��������� ��������
#include "spr0033.h" // ���������� ��� ���������� ���������� � ��������� ��������
#include "spr0034.h" // ��������� ��������� ��� ���������� � ��������� ���������� �����
#include "spr0035.h" // ��������� ��� ������ ���������� � ��������� ���������� �����
#include "spr0036.h" // �������������� � ���� ���������� ��� ������������ ����
#include "spr0037.h" // �������� ���������� � ���� ����������
#include "spr0038.h" // ������� ��������� ���� ����������
#include "spr0039.h" // ����� ����� ��������� (�����)
#include "spr0041.h" // �������� �����������
#include "spr0042.h" // ��������� �����������������
#include "spr0043.h" // �������� ���������� � ������ ����� ����������
#include "spr0044.h" // ���������� ��� ���������� (������) � ����� ��-�����������
#include "spr0046.h" // ���� ���������� ��� ������������ ����
#include "spr0047.h" // ����� ���������� �������������� �� ����������� � ��������� �������� ��
#include "SpZConst.h"// ��������� �� "��������"
#include "spr0048.h" // ���������� ������������� ����������
#include "spr0049.h" // �������������� ����������� "��������� ���������"
#include "spr0050.h" // �������������� ����������� "���� ����������� � ����� �� ������� �������� ����"
#include "spr0051.h" // �������������� ����������� ��������� �������, ���������� �������� � �������� �������� (������)
#include "spr0052.h" // ���������� ������������ ����� ��������� ������ � �� ������
#include "spr0053.h" // ������� ��������� ���� ���������� ��������� ���
#include "spr0054.h" // ���������� �������������� �� �����������
#include "spr0055.h" // ���������� ��������������
#include "spr0056.h" // ���������� ����������
#include "spr0057.h" // ���������� ���������
#include "spr0059.h" // ���������� zpnalker
#include "NSpNVSR.h"
#include "SpOtsd.h"  // ����������  ���
#include "SpOts.h"   // ���������� ��������
#include "SpKpR.h"	 // ���������� ����������/����������� �������� �������
#include "SpKpRf.h"  // ���������� ����������/����������� �������� �������
#include "gTnTn.h"	 // ������������ ��
#include "SpOPS.h"   // �������������� �������������������� �����
#include "GADR.h"    // ������������� �����

#pragma argsused

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved) {
	return 1;
}

// ---------------------------------------------------------------------------
short mainw(short ac, char *av[]) {
	int ret = 0;
	struct zpsppar par;
	struct zpsppar1 par1;

	struct zpsppard pard;
	struct zptform tform;
	struct zpsptou sptou;
	struct bsp *b;
	struct bspzp bzp;
	struct zpvdoh1 vdoh;
	struct zpknu2 knu2;
	struct consth con;
	struct zpkgni gni;
	struct zpindo indo;
	struct zpkmo5 kmo5;
	struct zpso so;
	struct zppstzn stzn;
	struct zpkfrs kfrs;
	struct zpinf1	inf1;
	struct zpinf2	inf2;
	struct zpinf3	inf3;
	struct zpinf4	inf4;
	struct zpinf10	inf10;
	struct zprus1	rus1;
	struct zprus2	rus2;
	struct zprus3	rus3;
	struct rzud ud;
	struct zpkkn kkn;

	HWND shwA, shw;
	AnsiString Av2;

	shw = (HWND)c_p->hw;
	shwA = Application->Handle;
	if (Application->Handle == NULL) {
		Application->Handle = (HWND) c_p->mwnd[0];
	}
	Application->ShowHint = false;
	Application->ShowHint = true;

	if(c_p->ora){
		DMXE10=(TDMXE10*)c_p->ora;
	}
	else{
		armerr(1,"������ ������������� DM");
		DMXE10 = new TDMXE10(Application); // (TDM);
		DMXE10->OpenBas();
	}

	if (strcmp("SPR0001", av[1]) == 0) {
		Av2 = av[2];
		if (Av2.Length()) {
			CLR(par);
			par.par1 = atoi(av[2]);
			IniSpr0001(&par, NULL);
		}
		else {
			ret = IniSpr0001((struct zpsppar*)av[2], (struct zpsppard*)av[3]);
		}
	}
	// ����� ����� ����������/���������
	if (strcmp("SPR0002", av[1]) == 0) {
		ret = IniSpr0002((struct rzud*)av[2]);
	}
	// ���������� ��� �����
	if (strcmp("SPR0003M", av[1]) == 0) { // ����� �� ����
		CLR(tform);
		IniSpr0003(&tform, NULL);
	}
	if (strcmp("SPR0003", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0003((struct zptform*)av[2], (struct zpsppard*)av[3]);
	}
	// ���������� ��� ���������������� ����������
	if (strcmp("SPR0004M", av[1]) == 0) { // ����� �� ����
		CLR(sptou);
		IniSpr0004(&sptou, NULL);
	}
	if (strcmp("SPR0004", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0004((struct zpsptou*)av[2], (struct zpsppard*)av[3]);
	}
	// ����� ���������� ��������������
	if (strcmp("SPR0005", av[1]) == 0) {
		ret = IniSpr0005((struct rzud*)av[2]);
	}
	// ����� ����������
	if (strcmp("SPR0006", av[1]) == 0) {
		ret = IniSpr0006();
	}
	// ����� �����������
	if (strcmp("SPR0007", av[1]) == 0) {
		ret = IniSpr0007((FCB)av[2]);
	}

	// ���������� ����� �������
	if (strcmp("SPR0008M", av[1]) == 0) { // ����� �� ����
		CLR(vdoh);
		IniSpr0008(&vdoh, NULL);
	}
	if (strcmp("SPR0008", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0008((struct zpvdoh1*)av[2], (struct zpsppard*)av[3]);
	}

	// ���������� ������������ ����� zp � ��
	if (strcmp("SPR0009M", av[1]) == 0) { // ����� �� ����
		CLR(knu2);
		IniSpr0009(&knu2, NULL);
	}
	if (strcmp("SPR0009", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0009((struct zpknu2*)av[2], (struct zpsppard*)av[3]);
	}
	// ���������� ����� � ��5

	if (strcmp("SPR0010M", av[1]) == 0) { // ����� �� ����
		CLR(kmo5);
		IniSpr0010(&kmo5, NULL);

	}
	if (strcmp("SPR0010", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0010((struct zpkmo5*)av[2], (struct zpsppard*)av[3]);
	}

	// ����.����� ��� �������.
	if (strcmp("SPR0012M", av[1]) == 0) { // ����� �� ����
		CLR(so);
		IniSpr0012(&so, NULL);

	}
	// ������������� �������� �����/������
	if (strcmp("SPR0014M", av[1]) == 0) { // ����� �� ����
		CLR(stzn);
		IniSpr0014(&stzn, NULL);

	}
	// ������������� �������� �����/������
	if (strcmp("SPR0016M", av[1]) == 0) { // ����� �� ����
		CLR(stzn);
		IniSpr0016(&stzn, NULL);

	}

	// ���������� ���������� �������
	if (strcmp("SPR0011M", av[1]) == 0) { // ����� �� ����
		CLR(con);
		IniSpr0011(&con, NULL);
	}
	if (strcmp("SPR0011", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0011((struct consth*)av[2], (struct zpsppard*)av[3]);
	}

	// ���������� ����� ����
	if (strcmp("SPR0013M", av[1]) == 0) { // ����� �� ����
		CLR(gni);
		IniSpr0013(&gni, NULL);
	}
	if (strcmp("SPR0013", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0013((struct zpkgni*)av[2], (struct zpsppard*)av[3]);
	}
/*
VDS 28/02/2019 �������� �����
	if (strcmp("SPR0017M", av[1]) == 0) { // ����� �� ����
		b = (struct bsp*)c_p->b_sp;
		CLR(kfrs);
		IniSpr0017(1, &kfrs, ((fdate*)&b->uyy));
	}
	if (strcmp("SPR0017", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0017(0, (struct zpkfrs*)av[2], ((fdate*)av[3]));
	}
*/
	if (strcmp(av[1], "SPR0018M") == 0) { // ����� �� ����
		b = (struct bsp*)c_p->b_sp;
		CLR(par);
		IniSpr0018(1, &par, ((fdate*)&b->uyy));
	}
	if (strcmp(av[1], "SPR0018") == 0) {
		ret = IniSpr0018((int)av[2], (struct zpsppar*)av[3], ((fdate*)av[4]));
	}
	if (strcmp(av[1], "SPR0019") == 0) {
		ret = IniSpr0019((int)av[2], (int *)av[3]);
	}
	if (strcmp(av[1], "SPR0020M") == 0) {
		IniSpr0020();
	}
// ���������� �����
	if (strcmp(av[1], "SPR0021") == 0) {
		ret = IniSpr0021((struct zpsppar*)av[2]);
	}
	// ����� ����������� (� ����������� �� ���������)
	if (strcmp(av[1],"SPR0022") == 0 ){
		ret = IniSpr0022((int)av[2],(FCB)av[3]);
	}
	if(strcmp(av[1],"KPP")==0){    //���������� �������������
		ret = IniSpr0023((struct zpkpp*)av[2], (struct zpsppard*)av[3]);
	}
	// ����� ���������� �������������� � ��������� �������� ��
	if (strcmp("SPR0024", av[1]) == 0) {
		ret = IniSpr0024((struct par_fcb *)av[2]);
	}
	// ����� ���������� �������������� �� ��������� � ���������
	if (strcmp("SPR0025", av[1]) == 0) {
		CLR(par);
		ret = IniSpr0025(&par,(struct par_fcb *)av[3]);
	}
	// ����� ���������� �������������� �� ����������� � ��������� �������� ��
	if (strcmp("SPR0047", av[1]) == 0) {
		ret = IniSpr0047((struct par_fcb *)av[2]);
	}
	if(strcmp(av[1],"STRAH")==0){    //���������� ������������
		ret = IniSpr0026((struct zpstrah*)av[2], (struct zpsppard*)av[3]);
	}
	// ���������� �������
	if (strcmp(av[1], "SPR0028M") == 0) { // ����� �� ����
		IniSpr0028(&par);
	}
	if (strcmp(av[1], "SPR0028") == 0) { // ����� �� ������
		ret = IniSpr0028((struct zpsppar*)av[2]);
	}
// ������� ������������ ��� "��������"
if (strcmp(av[1], "SPR0029M") == 0) { // ����� �� ����
		CLR(kkn);
		IniSpr0029(&kkn, NULL, NULL, true);
	}

	if (strcmp(av[1], "SPR0029") == 0) { // ����� �� ������
	ret = IniSpr0029((struct zpkkn*)av[2], (int)av[3], (AnsiString)av[4], (bool)av[5]);
	}

// ������� ������������ ��� "��������"
	if (strcmp(av[1], "SPR0030M") == 0) { // ����� �� ����
		IniSpr0030();
	}
  //� "���������� � ��������� ���������� �����"-------------------------------
	if (strcmp("SPR0032", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0032((struct zpinf1*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0033", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0033((struct zpinf2*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0034", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0034((struct zpinf3*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0035", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0035((struct zpinf4*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	// �������������� � ���� ���������� ��� ������������ ����
	if (strcmp("SPR0036M", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 0);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 0);
	}
  //--------------------------------------------------------------------------
  //� "���������� � ��������� ���������� ����� � 2013 ����"-------------------
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_3", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 3);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M_3", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 3);
	}
	// ���� ���������� ��� ������������ ����
  	if (strcmp("SPR0046M_3", av[1]) == 0) { // ����� �� ����
		IniSpr0046(NULL, 3);
	}
  //--------------------------------------------------------------------------
  //� ����� "��-�����������"--------------------------------------------------
	// �������� ���������� � ������ ����� ����������
	if (strcmp("SPR0043M_1", av[1]) == 0) { // ����� �� ����
		IniSpr0043(NULL, 1);
	}
  // ���������� ��� ���������� (���������)
	if (strcmp("SPR0044M_1", av[1]) == 0) { // ����� �� ����
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 1);
	}
	if (strcmp("SPR0044", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0044((struct zpinf10*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_1", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 1);
	}
	//--------------------------------------------------------------------------
	//� ����� "��-���"--------------------------------------------------
	// �������� ���������� � ������ ����� ����������
	if (strcmp("SPR0043M_8", av[1]) == 0) { // ����� �� ����
		IniSpr0043(NULL, 8);
	}
	// ���������� ��� ���������� (���������)
	if (strcmp("SPR0044M_8", av[1]) == 0) { // ����� �� ����
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 8);
	}
	// �������������� ��� ������������ ����
 	if (strcmp("SPR0036M_8", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 8);
	}
	//--------------------------------------------------------------------------
	//� ����� "��-�����"--------------------------------------------------
	// �������� ���������� � ������ ����� ����������
	if (strcmp("SPR0043M_9", av[1]) == 0) { // ����� �� ����
		IniSpr0043(NULL, 9);
	}
	// ���������� ��� ���������� (���������)
	if (strcmp("SPR0044M_9", av[1]) == 0) { // ����� �� ����
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 9);
	}
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_9", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 9);
	}
	//--------------------------------------------------------------------------
  //� ����� "��-��������"--------------------------------------------------
	// �������� ���������� � ������ ����� ����������
	if (strcmp("SPR0043M_2", av[1]) == 0) { // ����� �� ����
		IniSpr0043(NULL, 2);
	}
  // ���������� ��� ���������� (���������)
	if (strcmp("SPR0044M_2", av[1]) == 0) { // ����� �� ����
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 2);
	}
	// �������������� � ���� ���������� ��� ������������ ����
	if (strcmp("SPR0036M_2", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 2);
	}
  //--------------------------------------------------------------------------
  //� "���������� � �������������� ���������� ����� (��� ������� ����)--------
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_4", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 4);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M_4", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 4);
	}
	// ���� ���������� ��� ������������ ����
  	if (strcmp("SPR0046M_4", av[1]) == 0) { // ����� �� ����
		IniSpr0046(NULL, 4);
	}
  //--------------------------------------------------------------------------
	  //� ����� "1-� ���"--------------------------------------------------
	// �������� ���������� � ������ ����� ����������
	if (strcmp("SPR0043M_11", av[1]) == 0) { // ����� �� ����
		IniSpr0043(NULL, 11);
	}

	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_11", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 11);
	}
	//� ����� "14 ��"--------------------------------------------------
	// ���� ���������� ��� ������������ ����
		if (strcmp("SPR0046M_13", av[1]) == 0) { // ����� �� ����
		IniSpr0046(NULL, 13);
	}
	//--------------------------------------------------------------------------
	//� ����� "�������� � ���������� �����������"--------------------------------------------------
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_12", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 12);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M_12", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 12);
	}
	//--------------------------------------------------------------------------
	//� "���������� � ��������� ���������� ����� � 2015 ����"-------------------
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_10", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 10);
	}
	// �������������� ��� ������������ ���� c 2018
	if (strcmp("SPR0036M_101", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 101);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M_10", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 10);
	}
	// ���� ���������� ��� ������������ ����
		if (strcmp("SPR0046M_10", av[1]) == 0) { // ����� �� ����
		IniSpr0046(NULL, 10);
	}
	//--------------------------------------------------------------------------

	//������� ��������� ���� ����������
	if (strcmp("SPR0038M", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,0);
	}
	//������� ��������� ���� ����������  ��������� ���
	if (strcmp("SPR0038M_6", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,6);
	}
/*>>>> ORIGINAL //depot/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp#12
==== THEIRS //depot/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp#13
	//������� ��������� ���� ����������
==== YOURS //vms_ZPTAR/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp
		//������� ��������� ���� ����������
<<<<            */
	if (strcmp("SPR0038M_7", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,7);
	}
	if (strcmp("SPR0038M_8", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,8);
	}
	if (strcmp("SPR0038M_9", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,9);
	}
	if (strcmp("SPR0038M_10", av[1]) == 0) { // ����� �� ����
		IniSpr0038(NULL,10);
	}
	// ����� ����� ��������� (�����)
	if (strcmp("SPR0039", av[1]) == 0) {
		ret = IniSpr0039((struct rzud*)av[2]);
	}
// �������� �����������
	if (strcmp("SPR0041", av[1]) == 0) {
		ret = IniSpr0041();
	}
// ��������� �����������������
	if (strcmp("SPR0042", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0042((struct zpsppar*)av[2], (struct zpsppard*)av[3]);
	}
  if(strcmp(av[1],"ZPCONST")==0){//��������� �� "��������"
	  IniSpConst();
  }
// ���������� ������������� ����������
	if (strcmp("SPR0048", av[1]) == 0) {
		IniSpr0048();
	}
  //�������������� ����������� "��������� ���������"
	if (strcmp("SPR0049", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0049((struct zprus1*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0049M", av[1]) == 0) { // ����� �� ����
		CLR(rus1);
		IniSpr0049(&rus1, NULL);
	}
  //�������������� ����������� "���� ����������� � ����� �� ������� �������� ����"
	if (strcmp("SPR0050", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0050((struct zprus2*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0050M", av[1]) == 0) { // ����� �� ����
		CLR(rus2);
		IniSpr0050(&rus2, NULL);
	}
	//�������������� ����������� ��������� �������, ���������� �������� � �������� �������� (������)
	if (strcmp("SPR0051", av[1]) == 0) { // ����� �� ������
		ret = IniSpr0051((struct zprus3*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0051M", av[1]) == 0) { // ����� �� ����
		CLR(rus3);
		IniSpr0051(&rus3, NULL);
	}
// ���������� ������������ ����� ��������� ������ � �� ������
	if (strcmp("SPR0052M", av[1]) == 0) { // ����� �� ����
		IniSpr0052(NULL);
	}
  //������� ��������� ���� ����������  ��������� ���
	if (strcmp("SPR0053M_1", av[1]) == 0) { // ����� �� ����
		IniSpr0053(NULL,1);
	}
	// ����� ����������
	if (strcmp("SPR0054", av[1]) == 0) {
		ret = IniSpr0054();
	}
	//--------------------------------------------------------------------------
	//� "���������� � ������������ ������� �/����� ���������� ������������������� ����������"
	// �������������� ��� ������������ ����
	if (strcmp("SPR0036M_14", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 14);
	}
	// �������� ���������� � ���� ����������
	if (strcmp("SPR0037M_14", av[1]) == 0) { // ����� �� ����
		IniSpr0037(NULL, 14);
	}
	// ���� ���������� ��� ������������ ����
		if (strcmp("SPR0046M_14", av[1]) == 0) { // ����� �� ����
		IniSpr0046(NULL, 14);
	}
	//--------------------------------------------------------------------------
  if(strcmp(av[1],"VSR")==0){//���������� ���.������� �� ����� �������(����)
		IniSpNVSR(1,0,&par,(fdate*)&b->fd);
	}
	if(strcmp(av[1],"GVSR")==0){//���������� ���.������� �� ����� �������
   	ret=IniSpNVSR(1,1,(struct zpsppar *)av[4],(struct fdate *)av[5]);
  }

	if(strcmp(av[1],"FIN")==0){//���������� ��������������
		CLR(bzp);
    CLR(par);
		IniSpFin(0,&par,&bzp);
	}
	else if(strcmp(av[1],"GFIN")==0){//���������� ��������������
		ret=IniSpFin(1,(struct zpsppar *)av[2],(struct bspzp *)av[3]);
	}

	if(strcmp(av[1],"KD")==0){//���������� ���������
		CLR(par);
		IniSpKd(0,&par);
	}
	else if(strcmp(av[1],"GKD")==0){//���������� ���������
		ret=IniSpKd(1,(struct zpsppar *)av[2]);
	}
	if(strcmp(av[1],"KAT")==0){//���������� ���������
		CLR(par);
		IniSpKat(0,&par);
	}
	else if(strcmp(av[1],"GKAT")==0){//���������� ���������
		ret=IniSpKat(1,(struct zpsppar *)av[2]);
	}

	if (strcmp(av[1], "OTSD") == 0) { // ���������� ��������  ����� �� ����
		b = (struct bsp*)c_p->b_sp;
		CLR(par1);
		IniSpOtsd(0, 0, &par1, (fdate*)&b->fd);
	}
	else if (strcmp(av[1], "GOTSD") == 0) { // ���������� �������� ����� �� ����
		ret = IniSpOtsd(1, 1, (struct zpsppar1*)av[2], (struct fdate*)av[3]);
	}

/*
	if (strcmp(av[1], "GOTS") == 0) { // ���������� ��������  ����� �� ����
		ret = IniSpOts(0, 0, &par, (fdate*)&b->fd);
	}
*/

/*
	if (strcmp("SPR0040", av[1]) == 0) {
		Av2 = av[2];
		if (Av2.Length()) {
			CLR(par);
			par.par1 = atoi(av[2]);
			IniSpr0040(&par, NULL);
		}
		else {
			ret = IniSpr0040((struct zpsppar*)av[2], (struct zpsppard*)av[3]);
		}
	}
*/
	if(strcmp(av[1],"KK2")==0){//���������� ����������/�������������/���������
		CLR(par);
		Ini2(&par,0,0);
	}
	if(strcmp(av[1],"GKPNN")==0){//���������� ����������/�������������/���������
		ret=Ini2((struct zpsppar *)av[2],(int)av[3],(int)av[4]);
//		ret=Ini2((struct zpsppar *)av[2],((fdate*)&av[3]),((char *)av[4]),(char)av[5],(char)av[6]);
	}

 	if(strcmp(av[1],"KPNFI")==0){//���������� ����������/�������������/���������
		b = (struct bsp*)c_p->b_sp;
		IniRfi(&par,(fdate*)&b->uyy,1,0);
	}
	if(strcmp(av[1],"GKPNFI")==0){//���������� ����������/�������������/���������
		ret=IniRfi((struct zpsppar *)av[2],(fdate*)av[3],(int)av[4],(uchar)av[5]);
	}
	if(strcmp(av[1],"TNTN")==0){	//������������ ��������� �������
		I_TnTn();
	}
	if (strcmp(av[1], "PFK1") == 0) {
		struct zppfk par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK1);
	}
	if (strcmp(av[1], "GPFK1") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK1);
	}
	if (strcmp(av[1], "PFK2") == 0) {
		struct zppfk par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK2);
	}
	if (strcmp(av[1], "GPFK2") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK2);
	}
	if (strcmp(av[1], "PFK3") == 0) {
		struct zppfk par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK3);
	}
	if (strcmp(av[1], "GPFK3") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK3);
	}
	if (strcmp(av[1], "PFK4") == 0) {
		struct zppfk par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK4);
	}
	if (strcmp(av[1], "GPFK4") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK4);
	}
	if (strcmp(av[1], "PFK5") == 0) {
		struct zppfk par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK5);
	}
	if (strcmp(av[1], "GPFK5") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK5);
	}
	if (strcmp(av[1], "PFK6") == 0) {
		struct zppfk6 par;
		CLR(par);
		IniSpOPS((int*)&par, tbSpPFK6);
	}
	if (strcmp(av[1], "GPFK6") == 0) {
		ret = IniSpOPS((int *)av[2], tbSpPFK6);
	}
	if (strcmp(av[1], "ADR") == 0) { // ���������� �������
		ret = Ini((struct bcb*)av[2], (struct paradrn*)av[3], *(uchar*)av[4], 0);
	}
	// ���������� � ����������� �� ������� � 1732
	if (strcmp("SPR0036M_102", av[1]) == 0) { // ����� �� ����
		IniSpr0036(NULL, 102);
	}
	if (strcmp("SPR0059M", av[1]) == 0) { // ����� �� ���� ���������� zpnalker
		IniSpr0059();
	}

	if(!c_p->ora){
		delete DMXE10;
	}
	c_p->hw = shw;
	Application->Handle = shwA;
	return ret;
}
