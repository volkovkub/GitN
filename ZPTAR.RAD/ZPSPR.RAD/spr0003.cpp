// ---------------------------------------------------------------------------
// Тип формы
// 18.05.2011 год
// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0003.h"
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
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrSpr0003 *frSpr0003;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0003::TfrSpr0003(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0003(struct zptform *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0003 = new TfrSpr0003(Application);
	try {
		// Тип банка для выгрузки
		frSpr0003->ret = &ret;
		frSpr0003->par = par;
		if (pard == NULL) {
			frSpr0003->aOk->Enabled = false;
			frSpr0003->aOk->Visible = true;
			frSpr0003->aOk->ShortCut = 0;
		}
		else {
			frSpr0003->aOk->Enabled = true;
			frSpr0003->aOk->Visible = true;
		}
		frSpr0003->ftform = fafo(c_p->b_zp, "zptform");
		if (frSpr0003->ftform == 0) {
			armerr(1, "Нет структуры Тип формы!");
		}
		else {
			frSpr0003->aRefresh->Execute();
			frSpr0003->ShowModal();
			fafc(frSpr0003->ftform);
		}
	}
	catch (...) {
	}
	delete frSpr0003;
	return ret;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0003::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(tform);
	while (fargl(ftform, &tform, sizeof(tform)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][Vw_tf->Index] = tform.tf;
		dc->Values[ii][Vw_nm->Index] = tform.nm;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0003::aOkExecute(TObject *Sender) {

	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		((struct zptform*)par)->tf = (unsigned char)dc->Values[dc->FocusedRecordIndex][Vw_tf->Index];
		char * name = UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][Vw_nm->Index].VOleStr).c_str();
		MVL(name, ((struct zptform*)par)->nm, sizeof(((struct zptform*)par)->nm));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0003::VwDblClick(TObject *Sender) {
	aOk->Execute();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0003::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
