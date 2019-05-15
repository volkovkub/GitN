// ---------------------------------------------------------------------------
// Выбор Источников финансирования из имеющихся у работника
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"
#include "..\ZPBANK.RAD\banks.h"

extern struct compar *c_p;

#include "spr0025.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
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
TfrNRfin25 *frNRfin25;

// ---------------------------------------------------------------------------
__fastcall TfrNRfin25::TfrNRfin25(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0025(struct zpsppar *par,struct par_fcb *par_fcb) {
	int ret = -1, ii;
	frNRfin25 = new TfrNRfin25(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
		//frNRfin25->frfin = fmfo(c_p->b_wrk, "rfino");
		frNRfin25->frfin = par_fcb->fwrk3;
		if (frNRfin25->frfin == 0) {
			armerr(1, "Не открыта рабочая таблица rfino!");
		}
		else {
    	frNRfin25->par = par;
    	frNRfin25->ret = &ret;
			frNRfin25->RefreshFin25();

			frNRfin25->ShowModal();

			//fmfc(frNRfin25->frfin);
		}
	}
	catch (...) {
	}
	delete frNRfin25;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrNRfin25::RefreshFin25() {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		cxGrFinTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrFinTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rfin);
	while (fargl(frfin, &rfin, sizeof(rfin)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][cxGrFinTblnp->Index] = rfin.np;
		dc->Values[ii][cxGrFinTblfin->Index] = rfin.fin;
		dc->Values[ii][cxGrFinTbln->Index] = FmToUn(rfin.n, sizeof(rfin.n),PgDos);
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfin25::cxGrFinTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------



void __fastcall TfrNRfin25::aOkExecute(TObject *Sender)
{
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii,np,kfin;
	AnsiString ss;
	unsigned siz;

	ii = dc->FocusedRecordIndex;
	if (dc->RecordCount != 0) {
		kfin = (int)dc->Values[ii][cxGrFinTblfin->Index];
		np = (int)dc->Values[ii][cxGrFinTblnp->Index];
		mov(&np, &((struct zpsppar *)par)->par1, 2);
		mov(&kfin, &((struct zpsppar *)par)->par2, 2);
    ss = dc->Values[ii][cxGrFinTbln->Index];
		siz = ss.Length();
		MVL(UnToFm(dc->Values[ii][cxGrFinTbln->Index], PgWin), ((struct zpsppar *)par)->nm,siz);
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();

}
//---------------------------------------------------------------------------

void __fastcall TfrNRfin25::cxGrFinTblCellDblClick(TcxCustomGridTableView *Sender,
          TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
          TShiftState AShift, bool &AHandled)
{
	if (frNRfin25->aOk->Enabled) {
		aOk->Execute();

	}

}
//---------------------------------------------------------------------------


