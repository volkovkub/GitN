// ---------------------------------------------------------------------------
// Выбор сотрудников
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"

#include "armerrw.h"

extern struct compar *c_p;

#include "spr0022.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataControllerConditionalFormattingRulesManagerDialog"
#pragma link "cxDataStorage"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxImageList"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxPropertiesStore"
#pragma link "cxStyles"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrSpr0022 *frSpr0022;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0022::TfrSpr0022(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0022(int Vdol,FCB fcbrfiod) {
	int ret = -1, ii;
	frSpr0022 = new TfrSpr0022(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
		if(Vdol==1){//должность
			frSpr0022->pdol=Vdol;
			frSpr0022->cxGrTblDol->Visible=true;
		}
		if(Vdol==0){//нет должность
			frSpr0022->pdol=Vdol;
			frSpr0022->cxGrTblDol->Visible=false;
		}
		//frSpr0022->frfiod = fmfo(c_p->b_wrk, "rabfio");
		frSpr0022->frfiod = fcbrfiod;
		if (frSpr0022->frfiod == 0 || frSpr0022->frfiod == NULL) {
			armerr(1, "Не открыта рабочая таблица rabfio!");
		}
		else {
			frSpr0022->fkpn = fafo(c_p->b_zp, "kdrkpn");
			frSpr0022->fkd = fafo(c_p->b_nc, "zpkd");
			frSpr0022->RefreshFioD();

			frSpr0022->ShowModal();

			frSpr0022->CloseFioD();
			ret = frSpr0022->aRet;

			fafc(frSpr0022->fkpn);
			fafc(frSpr0022->fkd);
			//fmfc(frSpr0022->frfiod);
		}
	}
	catch (...) {
	}
	delete frSpr0022;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrSpr0022::RefreshFioD() {
	char fio[40],nmdol[40];

	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		cxGrTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rfiod);
	while (fargl(frfiod, &rfiod, sizeof(rfiod)) == 0) {
		ii = dc->AppendRecord();
		CLR(nmdol);
		OemToCharBuffA(rfiod.nmdol, nmdol,sizeof(rfiod.nmdol)>sizeof(nmdol)?sizeof(nmdol):sizeof(rfiod.nmdol));
		dc->Values[ii][cxGrTblDol->Index] = nmdol;
		CLR(kpn);
		kpn.kdkp = rfiod.kdkp;
		if (farel(fkpn, &kpn, sizeof(kpn)) == 0)
			dc->Values[ii][cxGrTbltn->Index] = kpn.tn;
			dc->Values[ii][cxGrTblkdkp->Index] = rfiod.kdkp;
		CLR(fio);
		OemToCharBuffA(rfiod.sname, fio,sizeof(rfiod.sname)>sizeof(fio)?sizeof(fio):sizeof(rfiod.sname));
		dc->Values[ii][cxGrTbln->Index] = fio;
		dc->Values[ii][cxGrTblfio->Index] = rfiod.sname;
		dc->Values[ii][cxGrTblp->Index] = rfiod.prv;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0022::cxGrTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void TfrSpr0022::CloseFioD() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	bool vp = true;
	AnsiString TmpStr;
	char fio[40];

	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		TmpStr = dc->Values[ii][cxGrTblfio->Index];//ФИО
		CLR(fio);
		strcat(fio, TmpStr.c_str());
		CLR(rfiod);
		mov(&fio, &rfiod.sname, sizeof(rfiod.sname));
		if(!dc->Values[ii][cxGrTblDol->Index].IsNull()){
			TmpStr = dc->Values[ii][cxGrTblDol->Index]; //должность
			CLR(fio);
			strcat(fio, TmpStr.c_str());
			CharToOemA(fio,rfiod.nmdol);
		}
		rfiod.kdkp = (unsigned short)dc->Values[ii][cxGrTblkdkp->Index];
		if (farel(frfiod, &rfiod, sizeof(rfiod)) == 0) {
			vp = (bool)dc->Values[ii][cxGrTblp->Index];
			if (vp == true)
				rfiod.prv = 1;
			else
				rfiod.prv = 0;
			farwl(frfiod, &rfiod, sizeof(rfiod));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0022::aChekExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;

	ii = 0;
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrTblp->Index] = 1;
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0022::aUnCheckExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;

	ii = 0;
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrTblp->Index] = 0;
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0022::cxGrTblpPropertiesEditValueChanged(TObject *Sender) {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii, k, pr;

	ii = dc->FocusedRecordIndex;
	k = (int)dc->Values[ii][cxGrTblkdkp->Index];
	if (k > 0) {
		pr = (int)dc->Values[ii][cxGrTblp->Index];
		if (pr == 0)
			dc->Values[ii][cxGrTblp->Index] = 1;
		else
			dc->Values[ii][cxGrTblp->Index] = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0022::cxGrTblKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == '+') {
		dxBarButtonaCheck->Click();
		// aChekExecute(NULL);
	}
	if (Key == '-') {
		dxBarButtonaUnCheck->Click();
		// aUnCheckExecute(NULL);
	}
}
// ---------------------------------------------------------------------------
