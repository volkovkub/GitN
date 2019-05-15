/* Власова М.
 21.10.11 */

// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0013.h"
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
TfrSpr0013 *frSpr0013;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0013::TfrSpr0013(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0013(struct zpkgni *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0013 = new TfrSpr0013(Application);
	try {
		// Тип банка для выгрузки
		frSpr0013->dxLCNew->Visible = false;
		frSpr0013->ret = &ret;
		frSpr0013->par = par;
		frSpr0013->cxTE_N->Properties->MaxLength = sizeof(frSpr0013->gni.n) - 1;
		frSpr0013->fcnst = fafo(c_p->b_zp, "const");
		CLR(frSpr0013->cnst);
		strcpy(frSpr0013->cnst.n, "KLIENT");
		if (fare(frSpr0013->fcnst, &frSpr0013->cnst) == 0) {
			if (strcmp(frSpr0013->cnst.ct, "1") == 0) {
			frSpr0013->aNew->Enabled = false;
			frSpr0013->aKor->Enabled = false;
			frSpr0013->aDel->Enabled = false;
			frSpr0013->aNew->Visible = false;
			frSpr0013->aKor->Visible = false;
			frSpr0013->aDel->Visible = false;
			}
		}

		if (pard != NULL) {
			frSpr0013->aOk->Enabled = true;
					frSpr0013->aOk->Visible = true;
		}

		frSpr0013->fgni = fafo(c_p->b_nc, "zpkgni");
		if (frSpr0013->fgni == 0) {
			armerr(1, "Нет структуры Коды ИМНС!");
		}
		else {
			frSpr0013->aRefresh->Execute();
			frSpr0013->ShowModal();
			fafc(frSpr0013->fgni);
		}
	}
	catch (...) {
	}
	delete frSpr0013;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0013::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ushort rr;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(gni);
	while (fargl(fgni, &gni, sizeof(gni)) == 0) {
		ii = dc->AppendRecord();
		swb(&gni.k, &rr, 2);
		dc->Values[ii][Vw_k->Index] = rr;
		dc->Values[ii][Vw_n->Index] = OEMtoWS(gni.n, sizeof(gni.n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0013::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ushort k;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (cxME_K->EditValue.IsNull()) {
		armerr(2, "Введите код");
		cxME_K->SetFocus();
		Ok = false;
	}
	if (cxTE_N->Text.IsEmpty()) {
		armerr(2, "Введите наименование");
		cxTE_N->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(gni);
		k = cxME_K->EditValue;
		swb(&k, &gni.k, 2);

		if (prNew == 1) {

			if (farel(fgni, &gni, sizeof(gni)) == 0) {
				armerr(2, "Данный код уже введён");
				cxME_K->SetFocus();

			}
			else {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), gni.n, sizeof(gni.n));
				farwl(fgni, &gni, sizeof(gni));
				ii = dc->AppendRecord();
				dc->Values[ii][Vw_k->Index] = cxME_K->EditValue;
				dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

			}
		}
		else {

			if (farel(fgni, &gni, sizeof(gni)) == 0) {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), gni.n, sizeof(gni.n));
				farwl(fgni, &gni, sizeof(gni));
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

void __fastcall TfrSpr0013::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		prNew = 1;
		CLR(TmpStr);
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		cxOk->Enabled = false;
		cxME_K->Clear();
		cxTE_N->Clear();
		cxME_K->Enabled = true;
		dxLCNew->Visible = true;
		cxME_K->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0013::cxCancelClick(TObject *Sender) {
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

void __fastcall TfrSpr0013::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int kk;
	ushort k;
	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {

			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {

				k = dc->Values[kk][Vw_k->Index];
				CLR(gni);
				swb(&k, &gni.k, 2);

				if (farel(fgni, &gni, sizeof(gni)) == 0) {
					fard(fgni, &gni);
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

void __fastcall TfrSpr0013::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	if (Vw->IsControlFocused) {
		prNew = 0;
		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			cxME_K->Text = dc->Values[kk][Vw_k->Index];
			cxTE_N->Text = dc->Values[kk][Vw_n->Index];
			cxME_K->Enabled = false;
			CLR(TmpStr);
			MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), TmpStr, sizeof(TmpStr));

		}
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

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0013::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0013::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0013::cxME_KExit(TObject *Sender) {
	if (prNew == 1) {

		if (cxME_K->Text.Length() > 4) {
			armerr(2, "Превышение допустимого значения!");
			cxME_K->SetFocus();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0013::cxTE_NPropertiesChange(TObject *Sender) {
	char Str1[200];

	CLR(Str1);
	MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), Str1, sizeof(Str1));
	if (cmp(&TmpStr, &Str1, sizeof(Str1)) != 0)
		cxOk->Enabled = true;
	else
		cxOk->Enabled = false;

}
// ---------------------------------------------------------------------------
void __fastcall TfrSpr0013::aOkExecute(TObject *Sender)
{
TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		((struct zpkgni*)par)->k = dc->Values[dc->FocusedRecordIndex][Vw_k->Index];

		MVCTOL(UnToFm(dc->Values[dc->FocusedRecordIndex][Vw_n->Index], PgWin),
					   ((struct zpkgni *)par)->n,sizeof(((struct zpkgni *)par)->n));

		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
//---------------------------------------------------------------------------

