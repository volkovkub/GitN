// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0010.h"
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
TfrSpr0010 *frSpr0010;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0010::TfrSpr0010(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0010(struct zpkmo5 *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0010 = new TfrSpr0010(Application);
	try {

		frSpr0010->dxLCNew->Visible = false;
		frSpr0010->ret = &ret;
		frSpr0010->par = par;
		frSpr0010->cxTE_N->Properties->MaxLength = sizeof(frSpr0010->kmo5.n) - 1;
		frSpr0010->aNew->Enabled = true;
		frSpr0010->aKor->Enabled = true;
		frSpr0010->aDel->Enabled = true;
		frSpr0010->aNew->Visible = true;
		frSpr0010->aKor->Visible = true;
		frSpr0010->aDel->Visible = true;

		if (pard == NULL) {
			frSpr0010->aOk->Enabled = false;
			frSpr0010->aOk->Visible = false;
			frSpr0010->aOk->ShortCut = 0;
		}
		else {
			frSpr0010->aNew->Enabled = false;
			frSpr0010->aKor->Enabled = false;
			frSpr0010->aDel->Enabled = false;
			frSpr0010->aNew->Visible = false;
			frSpr0010->aKor->Visible = false;
			frSpr0010->aDel->Visible = false;

			frSpr0010->aOk->Enabled = true;
			frSpr0010->aOk->Visible = true;
		}
		frSpr0010->fkmo5 = fafo(c_p->b_nc, "zpkmo5");
		if (frSpr0010->fkmo5 == 0) {
			armerr(1, "Нет структуры Строки в МО5!");
		}
		else {
			frSpr0010->aRefresh->Execute();
			frSpr0010->ShowModal();
			fafc(frSpr0010->fkmo5);
		}
	}
	catch (...) {
	}
	delete frSpr0010;
	return ret;
}

void __fastcall TfrSpr0010::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(kmo5);
	while (fargl(fkmo5, &kmo5, sizeof(kmo5)) == 0) {
		ii = dc->AppendRecord();

		dc->Values[ii][VwKod->Index] = kmo5.npp;
		dc->Values[ii][VwName->Index] = OEMtoWS(kmo5.n, sizeof(kmo5.n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::cxCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	aNew->Enabled = true;
	aDel->Enabled = true;
	aKor->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	cxGr->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		prNew = 1;
		cxME_Kod->Enabled = true;
		dxLCNew->Visible = true;
		cxME_Kod->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		cxOk->Enabled = false;
		cxME_Kod->Clear();
		cxTE_N->Clear();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	if (Vw->IsControlFocused) {
		prNew = 0;
		dxLCNew->Visible = true;
		cxTE_N->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		cxOk->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		f = false;

		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			cxME_Kod->Text = dc->Values[kk][VwKod->Index];
			cxTE_N->Text = dc->Values[kk][VwName->Index];
			cxME_Kod->Enabled = false;

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::cxTE_NExit(TObject *Sender) {
	if (prNew == 1) {
		cxOk->Enabled = ((cxME_Kod->Text != "") && (cxTE_N->Text != ""));

	}
	else {
		cxOk->Enabled = cxTE_N->Text.Length() > 0 && f;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int ii, kk;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {

			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				CLR(kmo5);
				kmo5.npp = dc->Values[kk][VwKod->Index];

				if (farel(fkmo5, &kmo5, sizeof(kmo5)) == 0) {
					fard(fkmo5, &kmo5);
					dc->DeleteFocused();
					if (dc->RecordCount == 0) {
						cxGr->RootLevelOptions->DetailFrameWidth = 2;
					}
				}

			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	// ulong kod;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (cxME_Kod->EditValue.IsNull()) {
		armerr(2, "Введите код");
		cxME_Kod->SetFocus();
		Ok = false;
	}
	if (cxTE_N->Text.IsEmpty()) {
		armerr(2, "Введите наименование");
		cxTE_N->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(kmo5);

		kmo5.npp = cxME_Kod->EditValue;

		if (prNew == 1) {

			if (farel(fkmo5, &kmo5, sizeof(kmo5)) == 0) {
				armerr(2, "Данный код уже введён");
				cxME_Kod->SetFocus();
			}
			else {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), kmo5.n, sizeof(kmo5.n));
				farwl(fkmo5, &kmo5, sizeof(kmo5));
				ii = dc->AppendRecord();
				dc->Values[ii][VwKod->Index] = cxME_Kod->EditValue;
				dc->Values[ii][VwName->Index] = cxTE_N->Text;

			}
		}
		else {

			if (farel(fkmo5, &kmo5, sizeof(kmo5)) == 0) {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), kmo5.n, sizeof(kmo5.n));
				farwl(fkmo5, &kmo5, sizeof(kmo5));
				dc->Values[ii][VwName->Index] = cxTE_N->Text;

			}

		}

		dxLCNew->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		aNew->Enabled = true;
		aDel->Enabled = true;
		aKor->Enabled = true;
		aExit->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr->SetFocus();
		dc->FocusedRecordIndex = ii;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	if (dc->RecordCount != 0) {
		((struct zpkmo5*)par)->npp = dc->Values[dc->FocusedRecordIndex][VwKod->Index];
		MVCTOL(UnToFm(dc->Values[dc->FocusedRecordIndex][VwName->Index], PgWin), ((struct zpkmo5 *)par)->n, sizeof(((struct zpkmo5 *)par)->n));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	if (frSpr0010->aOk->Enabled) {
		aOk->Execute();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0010::cxME_KodExit(TObject *Sender) {

	if (cxME_Kod->Text != "") {

		if (cxME_Kod->EditValue > 255) {
			armerr(2, "Введенное значение вне диапозоне данных");
			cxME_Kod->EditValue = 255;
		}
	}
	if (prNew == 1) {
		cxOk->Enabled = ((cxME_Kod->Text != "") && (cxTE_N->Text != ""));

	}
	else {
		cxOk->Enabled = cxTE_N->Text.Length() > 0 && f;
	}
}
// ---------------------------------------------------------------------------
