// ---------------------------------------------------------------------------
// Выбор должностей
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0006.h"
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
TfrSpr0006 *frSpr0006;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0006::TfrSpr0006(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0006() {
	int ret = -1, ii;
	frSpr0006 = new TfrSpr0006(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
		frSpr0006->frkd = fafo(c_p->b_wrk, "rabkd");
		if (frSpr0006->frkd == 0) {
			armerr(1, "Не открыта рабочая таблица rabkd!");
		}
		else {
			frSpr0006->RefreshDol();

			frSpr0006->ShowModal();

			frSpr0006->CloseDol();
			ret = frSpr0006->aRet;

			fafc(frSpr0006->frkd);
		}
	}
	catch (...) {
	}
	delete frSpr0006;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrSpr0006::RefreshDol() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	unsigned short kkd;

	if (dc->RecordCount != 0) {
		cxGrTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rkd);
	while (fargl(frkd, &rkd, sizeof(rkd)) == 0) {
		ii = dc->AppendRecord();
		swb(&rkd.d, &kkd, sizeof(rkd.d));
		dc->Values[ii][cxGrTblkdol->Index] = kkd;
		dc->Values[ii][cxGrTblkdolsw->Index] = rkd.d;
		//oemta(rkd.n, rkd.n);
		//dc->Values[ii][cxGrTbln->Index] = rkd.n;
		dc->Values[ii][cxGrTbln->Index] = FmToUn(rkd.n, sizeof(rkd.n),PgDos);
		dc->Values[ii][cxGrTblp->Index] = rkd.pr;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0006::cxGrTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void TfrSpr0006::CloseDol() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	bool vp = true;

	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		CLR(rkd);
		rkd.d = (unsigned short)dc->Values[ii][cxGrTblkdolsw->Index];
		if (farel(frkd, &rkd, sizeof(rkd)) == 0) {

			vp = (bool)dc->Values[ii][cxGrTblp->Index];
			if (vp == true)
				rkd.pr = 1;
			else
				rkd.pr = 0;
			farwl(frkd, &rkd, sizeof(rkd));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0006::aChekExecute(TObject *Sender) {
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

void __fastcall TfrSpr0006::aUnCheckExecute(TObject *Sender) {
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

void __fastcall TfrSpr0006::cxGrTblpPropertiesEditValueChanged(TObject *Sender) {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii, k, pr;

	ii = dc->FocusedRecordIndex;
	k = (int)dc->Values[ii][cxGrTblkdol->Index];
	if (k > 0) {
		pr = (int)dc->Values[ii][cxGrTblp->Index];
		if (pr == 0)
			dc->Values[ii][cxGrTblp->Index] = 1;
		else
			dc->Values[ii][cxGrTblp->Index] = 0;
	}

}
// ---------------------------------------------------------------------------
