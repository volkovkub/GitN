/* Власова М.
 18.10.11 */

// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0011.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
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
#pragma link "cxMaskEdit"
#pragma link "cxNavigator"
#pragma link "cxPropertiesStore"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutControlAdapters"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrSpr0011 *frSpr0011;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0011::TfrSpr0011(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0011(struct consth *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0011 = new TfrSpr0011(Application);
	try {
		// Тип банка для выгрузки
		frSpr0011->dxLCNew->Visible = false;
		frSpr0011->ret = &ret;
		frSpr0011->par = par;
		frSpr0011->cxTE_N->Properties->MaxLength = sizeof(frSpr0011->con.c_n) - 1;
		frSpr0011->cxTE_D->Properties->MaxLength = sizeof(frSpr0011->con.c_d) - 1;
		/* if (true) {
		 frSpr0011->aKor->Enabled = true;
		 frSpr0011->aKor->Visible = true;
		 }
		 if (pard == NULL)

		 {
		 frSpr0011->aKor->Enabled = false;
		 frSpr0011->aKor->Visible = false;
		 } */
		frSpr0011->fcon = fafo(c_p->b_zp, "consth");
		if (frSpr0011->fcon == 0) {
			armerr(1, "Нет структуры Постоянные величины!");
		}
		else {
			frSpr0011->aRefresh->Execute();
			frSpr0011->ShowModal();
			fafc(frSpr0011->fcon);
		}
	}
	catch (...) {
	}
	delete frSpr0011;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0011::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(con);
	while (fargl(fcon, &con, sizeof(con)) == 0) {
		ii = dc->AppendRecord();

		dc->Values[ii][Vw_key->Index] = OEMtoWS(con.c_key, sizeof(con.c_key));
		dc->Values[ii][Vw_d->Index] = OEMtoWS(con.c_d, sizeof(con.c_d));
		dc->Values[ii][Vw_n->Index] = OEMtoWS(con.c_n, sizeof(con.c_n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (cxTE_N->Text.IsEmpty()) {
		armerr(2, "Введите наименование");
		cxTE_N->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(con);

		MVCTOL(UnToFm(cxME_Key->Text.w_str(), PgWin), con.c_key, sizeof(con.c_key));
		MVCTOL(UnToFm(cxTE_D->Text.w_str(), PgWin), con.c_d, sizeof(con.c_d));
		MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), con.c_n, sizeof(con.c_n));
		farwl(fcon, &con, sizeof(con));

		dc->Values[ii][Vw_key->Index] = cxME_Key->Text;
		dc->Values[ii][Vw_d->Index] = cxTE_D->Text;
		dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

		dxLCNew->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		aKor->Enabled = true;
		aExit->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr->SetFocus();
		dc->FocusedRecordIndex = ii;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::cxCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	aKor->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	cxGr->SetFocus();

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	char ss[50];
	if (Vw->IsControlFocused) {

		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			cxME_Key->Text = dc->Values[kk][Vw_key->Index];
			cxTE_N->Text = dc->Values[kk][Vw_n->Index];
			cxTE_D->Text = dc->Values[kk][Vw_d->Index];
			cxME_Key->Enabled = false;
			CLR(TmpStr);
			MVCTOL(UnToFm(cxTE_D->Text.w_str(), PgWin), TmpStr, sizeof(TmpStr));

			CLR(TmpStr2);
			MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), TmpStr2, sizeof(TmpStr2));
		}
		dxLCNew->Visible = true;
		cxTE_D->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		aKor->Enabled = false;
		cxOk->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		f = false;
		t = false;
	}

}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;
	t = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::cxTE_DPropertiesChange(TObject *Sender) {
	char Str1[200];

	CLR(Str1);
	MVCTOL(UnToFm(cxTE_D->Text.w_str(), PgWin), Str1, sizeof(Str1));
	if (cmp(&TmpStr, &Str1, sizeof(Str1)) != 0)
		cxOk->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0011::cxTE_NPropertiesChange(TObject *Sender) {
	char Str2[200];

	CLR(Str2);
	MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), Str2, sizeof(Str2));
	if (cmp(&TmpStr2, &Str2, sizeof(Str2)) != 0)
		cxOk->Enabled = true;
}
// ---------------------------------------------------------------------------
