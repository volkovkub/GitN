// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0008.h"
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
TfrSpr0008 *frSpr0008;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0008::TfrSpr0008(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0008(struct zpvdoh1 *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0008 = new TfrSpr0008(Application);
	try {
		// Тип банка для выгрузки
		frSpr0008->dxLCNew->Visible = false;
		frSpr0008->ret = &ret;
		frSpr0008->par = par;
		frSpr0008->cxTE_N->Properties->MaxLength = sizeof(frSpr0008->vdoh.n) - 1;
		frSpr0008->aNew->Enabled = true;
		frSpr0008->aKor->Enabled = true;
		frSpr0008->aDel->Enabled = true;
		frSpr0008->aNew->Visible = true;
		frSpr0008->aKor->Visible = true;
		frSpr0008->aDel->Visible = true;
		// frSpr0008->tbank = ((struct zpsppar*)frSpr0008->par)->par1;
		if (pard == NULL) {
			frSpr0008->aOk->Enabled = false;
			frSpr0008->aOk->Visible = false;
			frSpr0008->aOk->ShortCut = 0;
		}
		else {
			frSpr0008->aNew->Enabled = false;
			frSpr0008->aKor->Enabled = false;
			frSpr0008->aDel->Enabled = false;
			frSpr0008->aNew->Visible = false;
			frSpr0008->aKor->Visible = false;
			frSpr0008->aDel->Visible = false;

			frSpr0008->aOk->Enabled = true;
			frSpr0008->aOk->Visible = true;
		}
		frSpr0008->fvdoh = fafo(c_p->b_nc, "zpvdoh1");
		if (frSpr0008->fvdoh == 0) {
			armerr(1, "Нет структуры Виды доходов!");
		}
		else {
			frSpr0008->aRefresh->Execute();
			frSpr0008->ShowModal();
			fafc(frSpr0008->fvdoh);
		}
	}
	catch (...) {
	}
	delete frSpr0008;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0008::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ulong rr;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(vdoh);
	while (fargl(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
		ii = dc->AppendRecord();
		swb(&vdoh.kod, &rr, 4);
		dc->Values[ii][Vw_kod->Index] = rr;
		dc->Values[ii][Vw_n->Index] = OEMtoWS(vdoh.n, sizeof(vdoh.n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ulong kod;
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

		CLR(vdoh);

		kod = cxME_Kod->EditValue;
		swb(&kod, &vdoh.kod, 4);
		if (prNew == 1) {

			if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
				armerr(2, "Данный код уже введён");
				cxME_Kod->SetFocus();
			}
			else {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), vdoh.n, sizeof(vdoh.n));
				farwl(fvdoh, &vdoh, sizeof(vdoh));
				ii = dc->AppendRecord();
				dc->Values[ii][Vw_kod->Index] = cxME_Kod->EditValue;
				dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

			}
		}
		else {

			if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), vdoh.n, sizeof(vdoh.n));
				farwl(fvdoh, &vdoh, sizeof(vdoh));
				dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

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

void __fastcall TfrSpr0008::cxCancelClick(TObject *Sender) {
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

void __fastcall TfrSpr0008::aNewExecute(TObject *Sender) {
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

void __fastcall TfrSpr0008::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int ii, kk;
	ulong kod;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			// ii = dc->FocusedRecordIndex;
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				kod = dc->Values[kk][Vw_kod->Index];
				CLR(vdoh);
				swb(&kod, &vdoh.kod, 4);

				if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
					fard(fvdoh, &vdoh);
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

void __fastcall TfrSpr0008::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
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

			kk = dc->FocusedRecordIndex;
			cxME_Kod->Text = dc->Values[kk][Vw_kod->Index];
			cxTE_N->Text = dc->Values[kk][Vw_n->Index];
			cxME_Kod->Enabled = false;

		}
	}
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::cxME_KodKeyPress(TObject *Sender, wchar_t &Key) {
	/* if (prNew==1) {
	 cxOk->Enabled=((cxME_Kod->Text!="")&&(cxTE_N->Text!=""));

	 }
	 else {
	 cxOk->Enabled=cxTE_N->EditModified;
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::cxME_KodEditing(TObject *Sender, bool &CanEdit) {
	//
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::cxTE_NExit(TObject *Sender) {
	if (cxME_Kod->Text != "") {

		if (cxME_Kod->EditValue > 2147483647) {
			armerr(2, "Введенное значение вне диапозоне данных");
			cxME_Kod->EditValue = 2147483647;
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
void __fastcall TfrSpr0008::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	ulong kod;
	if (dc->RecordCount != 0) {
		kod = dc->Values[dc->FocusedRecordIndex][Vw_kod->Index];
		swb(&kod, &((struct zpvdoh1 *)par)->kod, 4);
		MVCTOL(UnToFm(dc->Values[dc->FocusedRecordIndex][Vw_n->Index], PgWin), ((struct zpvdoh1 *)par)->n, sizeof(((struct zpvdoh1 *)par)->n));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0008::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	if (frSpr0008->aOk->Enabled) {
		aOk->Execute();

	}
}
// ---------------------------------------------------------------------------
