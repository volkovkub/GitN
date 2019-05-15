// ---------------------------------------------------------------------------
// Выбор Источников финансирования
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"
#include "..\ZPBANK.RAD\banks.h"

extern struct compar *c_p;

#include "spr0005.h"
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
TfrNRfin *frNRfin;

// ---------------------------------------------------------------------------
__fastcall TfrNRfin::TfrNRfin(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0005(struct rzud *ud) {
	int ret = -1;
	frNRfin = new TfrNRfin(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
		if (ud->fil_fin == NULL || ud->fil_fin == 0){
			armerr(1, "Не открыта рабочая таблица rfino!");
			return 1;
		}
		else {
			frNRfin->frfin = ud->fil_fin;
			frNRfin->RefreshFin();

			frNRfin->ShowModal();

			frNRfin->CloseFin();
			ret = frNRfin->aRet;
		}
	}
	catch (...) {
	}
	delete frNRfin;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrNRfin::RefreshFin() {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;
	struct rfino rfin;

	if (dc->RecordCount != 0) {
		cxGrFinTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrFinTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginUpdate();
	CLR(rfin);
	while (fargl(frfin, &rfin, sizeof(rfin)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][cxGrFinTblnp->Index] = rfin.np;
		dc->Values[ii][cxGrFinTblfin->Index] = rfin.fin;
		dc->Values[ii][cxGrFinTbln->Index] = FmToUn(rfin.n, sizeof(rfin.n),PgDos);
		dc->Values[ii][cxGrFinTblp->Index] = rfin.p;
	}
	dc->EndUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfin::cxGrFinTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void TfrNRfin::CloseFin() {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;
	bool vp = true;
	struct rfino rfin;
	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		CLR(rfin);
		rfin.np = (unsigned char)dc->Values[ii][cxGrFinTblnp->Index];
		rfin.fin = (unsigned char)dc->Values[ii][cxGrFinTblfin->Index];
		if (farel(frfin, &rfin, sizeof(rfin)) == 0) {

			vp = (bool)dc->Values[ii][cxGrFinTblp->Index];
			if (vp == true)
				rfin.p = 1;
			else
				rfin.p = 0;
			farwl(frfin, &rfin, sizeof(rfin));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfin::cxGrFinTblpPropertiesEditValueChanged(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii, k, pr;

	ii = dc->FocusedRecordIndex;
	k = (int)dc->Values[ii][cxGrFinTblnp->Index];
	if (k > 0) {
		pr = (int)dc->Values[ii][cxGrFinTblp->Index];
		if (pr == 0)
			dc->Values[ii][cxGrFinTblp->Index] = 1;
		else
			dc->Values[ii][cxGrFinTblp->Index] = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfin::aChekExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	ii = 0;

	dc->BeginUpdate();
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrFinTblp->Index] = 1;
		ii++;
	}
	dc->EndUpdate();

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfin::aUnCheckExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	ii = 0;
	dc->BeginUpdate();
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrFinTblp->Index] = 0;
		ii++;
	}
	dc->EndUpdate();
}
// ---------------------------------------------------------------------------
