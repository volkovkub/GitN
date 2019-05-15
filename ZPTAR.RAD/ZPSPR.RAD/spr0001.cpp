// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0001.h"
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
TfrSpr0001 *frSpr0001;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0001::TfrSpr0001(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0001(struct zpsppar *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0001 = new TfrSpr0001(Application);
	try {
		// Тип банка для выгрузки
		frSpr0001->ret = &ret;
		frSpr0001->par = par;
		frSpr0001->tbank = ((struct zpsppar*)frSpr0001->par)->par1;
		if (pard == NULL) {
			frSpr0001->aOk->Enabled = false;
			frSpr0001->aOk->Visible = false;
			frSpr0001->aOk->ShortCut = 0;
		}
		else {
			frSpr0001->aOk->Enabled = true;
			frSpr0001->aOk->Visible = true;
		}
		frSpr0001->ftcart = fafo(c_p->b_zp, "zptcart");
		if (frSpr0001->ftcart == 0) {
			armerr(1, "Нет структуры Типов банковских карт!");
		}
		else {
			frSpr0001->aRefresh->Execute();
			frSpr0001->ShowModal();
			fafc(frSpr0001->ftcart);
		}
	}
	catch (...) {
	}
	delete frSpr0001;
	return ret;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0001::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(tcart);
	tcart.kod = 1;
	tcart.tbank = tbank;
	while (fargl(ftcart, &tcart, sizeof(tcart)) == 0 && tcart.kod == 1 && tcart.tbank == tbank) {
		ii = dc->AppendRecord();
		dc->Values[ii][Vw_snm->Index] = OEMtoWS(tcart.snm, sizeof(tcart.snm));
		dc->Values[ii][Vw_fnm->Index] = OEMtoWS(tcart.fnm, sizeof(tcart.fnm));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0001::aOkExecute(TObject *Sender) {
	//
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		char * name = UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][Vw_snm->Index].VOleStr).c_str();
		MVL(name, ((struct zpsppar*)par)->nm, sizeof(((struct zpsppar*)par)->nm));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0001::VwDblClick(TObject *Sender) {
	aOk->Execute();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0001::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
