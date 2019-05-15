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
#include "spr0001.h" // Справочник типов карт
#include "spr0002.h" // Выбор кодов начислений/удержаний
#include "spr0003.h" // Справочник тип формы
#include "spr0004.h" // Справочник Тип образовательного учреждения
#include "spr0005.h" // Выбор Источников финансирования
#include "spr0006.h" // Выбор должностей
#include "spr0007.h" // Выбор сотрудников
#include "spr0008.h" // Справочник видов доходов
#include "spr0009.h" // Справочник соответствия кодов ZP и РФ
#include "spr0010.h" // Справочник строк в МО 5
#include "spr0011.h" // Справочник постоянных величин
#include "spr0012.h" // Пред.суммы для статист.
#include "spr0013.h" // Справочник кодов ИМНС
#include "spr0014.h" // Бухгалтерские проводки Дебет/Кредит
#include "spr0016.h" // Бухгалтерские проводки Дебет/Кредит
//VDS 28/02/2019 #include "spr0017.h" // Справочник классификаций  Справочник Балансовые счета 2012
#include "spr0018.h" // Справочник Счета/Классификация
#include "spr0019.h" // Справочник
#include "spr0020.h" // Таблица входимости
#include "spr0021.h" // Справочник СНИЛС
#include "spr0022.h" // Выбор сотрудников (с сортировкой по должности)
#include "spr0023.h" // Справочник страхователей
#include "spr0024.h" // Выбор Источников финансирования с переносом закрытых ИФ
#include "spr0025.h" // Выбор Источника финансирования из имеющихся у работника
#include "spr0026.h" // Справочник страховщиков
#include "spr0028.h" // Справочник округов
#include "spr0029.h" // Краткие наименования для "Шахматки"
#include "spr0030.h" // Таблица соответствия для "Шахматки"
#include "spr0032.h" // Справочник тип формы информации о повышении зарплаты
#include "spr0033.h" // Справочник Тип учреждения информации о повышении зарплаты
#include "spr0034.h" // Категория персонала для информации о повышении заработной платы
#include "spr0035.h" // Должности для печати информации о повышении заработной платы
#include "spr0036.h" // Финансирования и коды начислений для формирования форм
#include "spr0037.h" // Привязка учреждения к типу учреждения
#include "spr0038.h" // Таблица настройки форм отчетности
#include "spr0039.h" // Выбор типов персонала (услуг)
#include "spr0041.h" // Стажевый коэффициент
#include "spr0042.h" // категория налогоплатильщика
#include "spr0043.h" // Привязка учреждения к группе типов учреждения
#include "spr0044.h" // Справочник Тип учреждения (полный) к форме ЗП-образование
#include "spr0046.h" // коды начислений для формирования форм
#include "spr0047.h" // Выбор Источников финансирования по сотрудникам с переносом закрытых ИФ
#include "SpZConst.h"// Константы ПП "Зарплата"
#include "spr0048.h" // Справочник коэффициентов индексации
#include "spr0049.h" // Общероссийский кодификатор "Категория персонала"
#include "spr0050.h" // Общероссийский кодификатор "Виды производств и работ по номерам выпусков ЕТКС"
#include "spr0051.h" // Общероссийский кодификатор профессий рабочих, должностей служащих и тарифных разрядов (ОКПДТР)
#include "spr0052.h" // справочник соответствия кодов должности КУБНЕТ и по ОКПДТР
#include "spr0053.h" // Таблица настройки форм отчетности Аналитика ФОТ
#include "spr0054.h" // Справочник финансирования по учреждениям
#include "spr0055.h" // Справочник финансирования
#include "spr0056.h" // Справочник должностей
#include "spr0057.h" // Справочник категорий
#include "spr0059.h" // Справочник zpnalker
#include "NSpNVSR.h"
#include "SpOtsd.h"  // Справочник  ПКУ
#include "SpOts.h"   // Справочник отраслей
#include "SpKpR.h"	 // Справочник Учреждений/Сотрудников согласно доступа
#include "SpKpRf.h"  // Справочник Учреждений/Сотрудников согласно доступа
#include "gTnTn.h"	 // Соответствие ТН
#include "SpOPS.h"   // Классификаторы Персонифицированного учета
#include "GADR.h"    // Классификатор Кладр

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
		armerr(1,"Ошибка инициализации DM");
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
	// Выбор кодов начислений/удержаний
	if (strcmp("SPR0002", av[1]) == 0) {
		ret = IniSpr0002((struct rzud*)av[2]);
	}
	// Справочник тип формы
	if (strcmp("SPR0003M", av[1]) == 0) { // вызов из меню
		CLR(tform);
		IniSpr0003(&tform, NULL);
	}
	if (strcmp("SPR0003", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0003((struct zptform*)av[2], (struct zpsppard*)av[3]);
	}
	// Справочник Тип образовательного учреждения
	if (strcmp("SPR0004M", av[1]) == 0) { // вызов из меню
		CLR(sptou);
		IniSpr0004(&sptou, NULL);
	}
	if (strcmp("SPR0004", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0004((struct zpsptou*)av[2], (struct zpsppard*)av[3]);
	}
	// Выбор Источников финансирования
	if (strcmp("SPR0005", av[1]) == 0) {
		ret = IniSpr0005((struct rzud*)av[2]);
	}
	// Выбор Должностей
	if (strcmp("SPR0006", av[1]) == 0) {
		ret = IniSpr0006();
	}
	// Выбор сотрудников
	if (strcmp("SPR0007", av[1]) == 0) {
		ret = IniSpr0007((FCB)av[2]);
	}

	// Справочник видов доходов
	if (strcmp("SPR0008M", av[1]) == 0) { // вызов из меню
		CLR(vdoh);
		IniSpr0008(&vdoh, NULL);
	}
	if (strcmp("SPR0008", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0008((struct zpvdoh1*)av[2], (struct zpsppard*)av[3]);
	}

	// Справочник соответствия кодов zp и РФ
	if (strcmp("SPR0009M", av[1]) == 0) { // вызов из меню
		CLR(knu2);
		IniSpr0009(&knu2, NULL);
	}
	if (strcmp("SPR0009", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0009((struct zpknu2*)av[2], (struct zpsppard*)av[3]);
	}
	// справочник Строк в МО5

	if (strcmp("SPR0010M", av[1]) == 0) { // вызов из меню
		CLR(kmo5);
		IniSpr0010(&kmo5, NULL);

	}
	if (strcmp("SPR0010", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0010((struct zpkmo5*)av[2], (struct zpsppard*)av[3]);
	}

	// Пред.суммы для статист.
	if (strcmp("SPR0012M", av[1]) == 0) { // вызов из меню
		CLR(so);
		IniSpr0012(&so, NULL);

	}
	// Бухгалтерские проводки Дебет/Кредит
	if (strcmp("SPR0014M", av[1]) == 0) { // вызов из меню
		CLR(stzn);
		IniSpr0014(&stzn, NULL);

	}
	// Бухгалтерские проводки Дебет/Кредит
	if (strcmp("SPR0016M", av[1]) == 0) { // вызов из меню
		CLR(stzn);
		IniSpr0016(&stzn, NULL);

	}

	// Справочник постоянных величин
	if (strcmp("SPR0011M", av[1]) == 0) { // вызов из меню
		CLR(con);
		IniSpr0011(&con, NULL);
	}
	if (strcmp("SPR0011", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0011((struct consth*)av[2], (struct zpsppard*)av[3]);
	}

	// Справочник кодов ИМНС
	if (strcmp("SPR0013M", av[1]) == 0) { // вызов из меню
		CLR(gni);
		IniSpr0013(&gni, NULL);
	}
	if (strcmp("SPR0013", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0013((struct zpkgni*)av[2], (struct zpsppard*)av[3]);
	}
/*
VDS 28/02/2019 отключил вызов
	if (strcmp("SPR0017M", av[1]) == 0) { // вызов из меню
		b = (struct bsp*)c_p->b_sp;
		CLR(kfrs);
		IniSpr0017(1, &kfrs, ((fdate*)&b->uyy));
	}
	if (strcmp("SPR0017", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0017(0, (struct zpkfrs*)av[2], ((fdate*)av[3]));
	}
*/
	if (strcmp(av[1], "SPR0018M") == 0) { // вызов из меню
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
// справочник снилс
	if (strcmp(av[1], "SPR0021") == 0) {
		ret = IniSpr0021((struct zpsppar*)av[2]);
	}
	// Выбор сотрудников (с сортировкой по должности)
	if (strcmp(av[1],"SPR0022") == 0 ){
		ret = IniSpr0022((int)av[2],(FCB)av[3]);
	}
	if(strcmp(av[1],"KPP")==0){    //Справочник страхователей
		ret = IniSpr0023((struct zpkpp*)av[2], (struct zpsppard*)av[3]);
	}
	// Выбор Источников финансирования с переносом закрытых ИФ
	if (strcmp("SPR0024", av[1]) == 0) {
		ret = IniSpr0024((struct par_fcb *)av[2]);
	}
	// Выбор Источников финансирования из имеющихся у работника
	if (strcmp("SPR0025", av[1]) == 0) {
		CLR(par);
		ret = IniSpr0025(&par,(struct par_fcb *)av[3]);
	}
	// Выбор Источников финансирования по сотрудникам с переносом закрытых ИФ
	if (strcmp("SPR0047", av[1]) == 0) {
		ret = IniSpr0047((struct par_fcb *)av[2]);
	}
	if(strcmp(av[1],"STRAH")==0){    //Справочник страховщиков
		ret = IniSpr0026((struct zpstrah*)av[2], (struct zpsppard*)av[3]);
	}
	// справочник округов
	if (strcmp(av[1], "SPR0028M") == 0) { // вызов из меню
		IniSpr0028(&par);
	}
	if (strcmp(av[1], "SPR0028") == 0) { // вызов из модуля
		ret = IniSpr0028((struct zpsppar*)av[2]);
	}
// Краткие наименования для "Шахматки"
if (strcmp(av[1], "SPR0029M") == 0) { // вызов из меню
		CLR(kkn);
		IniSpr0029(&kkn, NULL, NULL, true);
	}

	if (strcmp(av[1], "SPR0029") == 0) { // вызов из модуля
	ret = IniSpr0029((struct zpkkn*)av[2], (int)av[3], (AnsiString)av[4], (bool)av[5]);
	}

// таблица соответствия для "Шахматки"
	if (strcmp(av[1], "SPR0030M") == 0) { // вызов из меню
		IniSpr0030();
	}
  //К "Информации о повышении заработной платы"-------------------------------
	if (strcmp("SPR0032", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0032((struct zpinf1*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0033", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0033((struct zpinf2*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0034", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0034((struct zpinf3*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	if (strcmp("SPR0035", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0035((struct zpinf4*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	// Финансирования и коды начислений для формирования форм
	if (strcmp("SPR0036M", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 0);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 0);
	}
  //--------------------------------------------------------------------------
  //К "Информации о повышении заработной платы с 2013 года"-------------------
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_3", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 3);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M_3", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 3);
	}
	// коды начислений для формирования форм
  	if (strcmp("SPR0046M_3", av[1]) == 0) { // вызов из меню
		IniSpr0046(NULL, 3);
	}
  //--------------------------------------------------------------------------
  //К форме "ЗП-Образование"--------------------------------------------------
	// Привязка учреждения к группе типов учреждения
	if (strcmp("SPR0043M_1", av[1]) == 0) { // вызов из меню
		IniSpr0043(NULL, 1);
	}
  // Справочник Тип учреждения (подробный)
	if (strcmp("SPR0044M_1", av[1]) == 0) { // вызов из меню
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 1);
	}
	if (strcmp("SPR0044", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0044((struct zpinf10*)av[2], (struct zpsppard*)av[3], (char)av[4]);
	}
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_1", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 1);
	}
	//--------------------------------------------------------------------------
	//К форме "ЗП-соц"--------------------------------------------------
	// Привязка учреждения к группе типов учреждения
	if (strcmp("SPR0043M_8", av[1]) == 0) { // вызов из меню
		IniSpr0043(NULL, 8);
	}
	// Справочник Тип учреждения (подробный)
	if (strcmp("SPR0044M_8", av[1]) == 0) { // вызов из меню
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 8);
	}
	// Финансирования для формирования форм
 	if (strcmp("SPR0036M_8", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 8);
	}
	//--------------------------------------------------------------------------
	//К форме "ЗП-здрав"--------------------------------------------------
	// Привязка учреждения к группе типов учреждения
	if (strcmp("SPR0043M_9", av[1]) == 0) { // вызов из меню
		IniSpr0043(NULL, 9);
	}
	// Справочник Тип учреждения (подробный)
	if (strcmp("SPR0044M_9", av[1]) == 0) { // вызов из меню
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 9);
	}
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_9", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 9);
	}
	//--------------------------------------------------------------------------
  //К форме "ЗП-культура"--------------------------------------------------
	// Привязка учреждения к группе типов учреждения
	if (strcmp("SPR0043M_2", av[1]) == 0) { // вызов из меню
		IniSpr0043(NULL, 2);
	}
  // Справочник Тип учреждения (подробный)
	if (strcmp("SPR0044M_2", av[1]) == 0) { // вызов из меню
		CLR(inf10);
		IniSpr0044(&inf10, NULL, 2);
	}
	// Финансирования и коды начислений для формирования форм
	if (strcmp("SPR0036M_2", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 2);
	}
  //--------------------------------------------------------------------------
  //К "Информации о среднемесячной заработной плате (для краевых школ)--------
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_4", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 4);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M_4", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 4);
	}
	// коды начислений для формирования форм
  	if (strcmp("SPR0046M_4", av[1]) == 0) { // вызов из меню
		IniSpr0046(NULL, 4);
	}
  //--------------------------------------------------------------------------
	  //К форме "1-Т ГМС"--------------------------------------------------
	// Привязка учреждения к группе типов учреждения
	if (strcmp("SPR0043M_11", av[1]) == 0) { // вызов из меню
		IniSpr0043(NULL, 11);
	}

	// Финансирования для формирования форм
	if (strcmp("SPR0036M_11", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 11);
	}
	//К форме "14 МО"--------------------------------------------------
	// коды начислений для формирования форм
		if (strcmp("SPR0046M_13", av[1]) == 0) { // вызов из меню
		IniSpr0046(NULL, 13);
	}
	//--------------------------------------------------------------------------
	//К форме "Сведения о количестве сотрудников"--------------------------------------------------
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_12", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 12);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M_12", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 12);
	}
	//--------------------------------------------------------------------------
	//К "Информации о повышении заработной платы с 2015 года"-------------------
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_10", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 10);
	}
	// Финансирования для формирования форм c 2018
	if (strcmp("SPR0036M_101", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 101);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M_10", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 10);
	}
	// коды начислений для формирования форм
		if (strcmp("SPR0046M_10", av[1]) == 0) { // вызов из меню
		IniSpr0046(NULL, 10);
	}
	//--------------------------------------------------------------------------

	//Таблица настройки форм отчетности
	if (strcmp("SPR0038M", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,0);
	}
	//Таблица настройки форм отчетности  Аналитика ФОТ
	if (strcmp("SPR0038M_6", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,6);
	}
/*>>>> ORIGINAL //depot/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp#12
==== THEIRS //depot/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp#13
	//Таблица настройки форм отчетности
==== YOURS //vms_ZPTAR/ZPTAR.RAD/ZPSPR.RAD/mZPSPR.cpp
		//Таблица настройки форм отчетности
<<<<            */
	if (strcmp("SPR0038M_7", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,7);
	}
	if (strcmp("SPR0038M_8", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,8);
	}
	if (strcmp("SPR0038M_9", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,9);
	}
	if (strcmp("SPR0038M_10", av[1]) == 0) { // вызов из меню
		IniSpr0038(NULL,10);
	}
	// Выбор типов персонала (услуг)
	if (strcmp("SPR0039", av[1]) == 0) {
		ret = IniSpr0039((struct rzud*)av[2]);
	}
// Стажевый коэффициент
	if (strcmp("SPR0041", av[1]) == 0) {
		ret = IniSpr0041();
	}
// категория налогоплатильщика
	if (strcmp("SPR0042", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0042((struct zpsppar*)av[2], (struct zpsppard*)av[3]);
	}
  if(strcmp(av[1],"ZPCONST")==0){//Константы ПП "Зарплата"
	  IniSpConst();
  }
// Справочник коэффициентов индексации
	if (strcmp("SPR0048", av[1]) == 0) {
		IniSpr0048();
	}
  //Общероссийский кодификатор "Категория персонала"
	if (strcmp("SPR0049", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0049((struct zprus1*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0049M", av[1]) == 0) { // вызов из меню
		CLR(rus1);
		IniSpr0049(&rus1, NULL);
	}
  //Общероссийский кодификатор "Виды производств и работ по номерам выпусков ЕТКС"
	if (strcmp("SPR0050", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0050((struct zprus2*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0050M", av[1]) == 0) { // вызов из меню
		CLR(rus2);
		IniSpr0050(&rus2, NULL);
	}
	//Общероссийский кодификатор профессий рабочих, должностей служащих и тарифных разрядов (ОКПДТР)
	if (strcmp("SPR0051", av[1]) == 0) { // вызов из модуля
		ret = IniSpr0051((struct zprus3*)av[2], (struct zpsppard*)av[3]);
	}
	if (strcmp("SPR0051M", av[1]) == 0) { // вызов из меню
		CLR(rus3);
		IniSpr0051(&rus3, NULL);
	}
// справочник соответствия кодов должности КУБНЕТ и по ОКПДТР
	if (strcmp("SPR0052M", av[1]) == 0) { // вызов из меню
		IniSpr0052(NULL);
	}
  //Таблица настройки форм отчетности  Аналитика ФОТ
	if (strcmp("SPR0053M_1", av[1]) == 0) { // вызов из меню
		IniSpr0053(NULL,1);
	}
	// Выбор Должностей
	if (strcmp("SPR0054", av[1]) == 0) {
		ret = IniSpr0054();
	}
	//--------------------------------------------------------------------------
	//К "Информации о формировании средней з/платы работников общеобразовательных учреждений"
	// Финансирования для формирования форм
	if (strcmp("SPR0036M_14", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 14);
	}
	// Привязка учреждения к типу учреждения
	if (strcmp("SPR0037M_14", av[1]) == 0) { // вызов из меню
		IniSpr0037(NULL, 14);
	}
	// коды начислений для формирования форм
		if (strcmp("SPR0046M_14", av[1]) == 0) { // вызов из меню
		IniSpr0046(NULL, 14);
	}
	//--------------------------------------------------------------------------
  if(strcmp(av[1],"VSR")==0){//Справочник нал.вычетов по видам доходов(Меню)
		IniSpNVSR(1,0,&par,(fdate*)&b->fd);
	}
	if(strcmp(av[1],"GVSR")==0){//Справочник нал.вычетов по видам доходов
   	ret=IniSpNVSR(1,1,(struct zpsppar *)av[4],(struct fdate *)av[5]);
  }

	if(strcmp(av[1],"FIN")==0){//Справочник Финансирования
		CLR(bzp);
    CLR(par);
		IniSpFin(0,&par,&bzp);
	}
	else if(strcmp(av[1],"GFIN")==0){//Справочник Финансирования
		ret=IniSpFin(1,(struct zpsppar *)av[2],(struct bspzp *)av[3]);
	}

	if(strcmp(av[1],"KD")==0){//Справочник Должности
		CLR(par);
		IniSpKd(0,&par);
	}
	else if(strcmp(av[1],"GKD")==0){//Справочник Должности
		ret=IniSpKd(1,(struct zpsppar *)av[2]);
	}
	if(strcmp(av[1],"KAT")==0){//Справочник Категории
		CLR(par);
		IniSpKat(0,&par);
	}
	else if(strcmp(av[1],"GKAT")==0){//Справочник Категории
		ret=IniSpKat(1,(struct zpsppar *)av[2]);
	}

	if (strcmp(av[1], "OTSD") == 0) { // Справосник Разрядов  вызов из Меню
		b = (struct bsp*)c_p->b_sp;
		CLR(par1);
		IniSpOtsd(0, 0, &par1, (fdate*)&b->fd);
	}
	else if (strcmp(av[1], "GOTSD") == 0) { // Справосник Разрядов вызов из Форм
		ret = IniSpOtsd(1, 1, (struct zpsppar1*)av[2], (struct fdate*)av[3]);
	}

/*
	if (strcmp(av[1], "GOTS") == 0) { // Справочник Разрядов  вызов из Меню
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
	if(strcmp(av[1],"KK2")==0){//Справочник Учреждение/Подразделение/Сотрудник
		CLR(par);
		Ini2(&par,0,0);
	}
	if(strcmp(av[1],"GKPNN")==0){//Справочник Учреждение/Подразделение/Сотрудник
		ret=Ini2((struct zpsppar *)av[2],(int)av[3],(int)av[4]);
//		ret=Ini2((struct zpsppar *)av[2],((fdate*)&av[3]),((char *)av[4]),(char)av[5],(char)av[6]);
	}

 	if(strcmp(av[1],"KPNFI")==0){//Справочник Учреждение/Подразделение/Сотрудник
		b = (struct bsp*)c_p->b_sp;
		IniRfi(&par,(fdate*)&b->uyy,1,0);
	}
	if(strcmp(av[1],"GKPNFI")==0){//Справочник Учреждение/Подразделение/Сотрудник
		ret=IniRfi((struct zpsppar *)av[2],(fdate*)av[3],(int)av[4],(uchar)av[5]);
	}
	if(strcmp(av[1],"TNTN")==0){	//Соответствие Табельных номеров
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
	if (strcmp(av[1], "ADR") == 0) { // Справочник адресов
		ret = Ini((struct bcb*)av[2], (struct paradrn*)av[3], *(uchar*)av[4], 0);
	}
	// Информация о начислениях по приказу № 1732
	if (strcmp("SPR0036M_102", av[1]) == 0) { // вызов из меню
		IniSpr0036(NULL, 102);
	}
	if (strcmp("SPR0059M", av[1]) == 0) { // вызов из меню Справочник zpnalker
		IniSpr0059();
	}

	if(!c_p->ora){
		delete DMXE10;
	}
	c_p->hw = shw;
	Application->Handle = shwA;
	return ret;
}
