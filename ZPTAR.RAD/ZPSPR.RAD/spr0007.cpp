// ---------------------------------------------------------------------------
// Выбор сотрудников
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0007.h"
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
TfrSpr0007 *frSpr0007;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0007::TfrSpr0007(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0007(FCB fcbrfio) {
	int ret = -1, ii;
	frSpr0007 = new TfrSpr0007(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
		//frSpr0007->frfio = fmfo(c_p->b_wrk, "rabfio");
		frSpr0007->frfio = fcbrfio;
		if (frSpr0007->frfio == 0 || frSpr0007->frfio == NULL) {
			armerr(1, "Не открыта рабочая таблица rabfio!");
		}
		else {
			frSpr0007->fkpn = fafo(c_p->b_zp, "kdrkpn");
			frSpr0007->RefreshFio();

			frSpr0007->ShowModal();

			frSpr0007->CloseFio();
			ret = frSpr0007->aRet;

			fafc(frSpr0007->fkpn);
			//fmfc(frSpr0007->frfio);
		}
	}
	catch (...) {
	}
	delete frSpr0007;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrSpr0007::RefreshFio() {
	char fio[40];

	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		cxGrTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rfio);
	while (fargl(frfio, &rfio, sizeof(rfio)) == 0) {
		ii = dc->AppendRecord();
		CLR(kpn);
		kpn.kdkp = rfio.kdkp;
		if (farel(fkpn, &kpn, sizeof(kpn)) == 0)
			dc->Values[ii][cxGrTbltn->Index] = kpn.tn;
		dc->Values[ii][cxGrTblkdkp->Index] = rfio.kdkp;
		dc->Values[ii][cxGrTblfio->Index] = rfio.sname;
		//CLR(fio);
		//oemta(rfio.sname, fio);
		//dc->Values[ii][cxGrTbln->Index] = fio;
		dc->Values[ii][cxGrTbln->Index] = FmToUn(rfio.sname, sizeof(rfio.sname),PgDos);
		dc->Values[ii][cxGrTblp->Index] = rfio.prv;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0007::cxGrTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void TfrSpr0007::CloseFio() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	bool vp = true;
	AnsiString TmpStr;
	char fio[40];

	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		TmpStr = dc->Values[ii][cxGrTblfio->Index];
		CLR(fio);
		strcat(fio, TmpStr.c_str());
		CLR(rfio);
		mov(&fio, &rfio.sname, sizeof(rfio.sname));
		rfio.kdkp = (unsigned short)dc->Values[ii][cxGrTblkdkp->Index];
		if (farel(frfio, &rfio, sizeof(rfio)) == 0) {
			vp = (bool)dc->Values[ii][cxGrTblp->Index];
			if (vp == true)
				rfio.prv = 1;
			else
				rfio.prv = 0;
			farwl(frfio, &rfio, sizeof(rfio));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0007::aChekExecute(TObject *Sender) {
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

void __fastcall TfrSpr0007::aUnCheckExecute(TObject *Sender) {
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

void __fastcall TfrSpr0007::cxGrTblpPropertiesEditValueChanged(TObject *Sender) {
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

void __fastcall TfrSpr0007::cxGrTblKeyPress(TObject *Sender, wchar_t &Key) {
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
