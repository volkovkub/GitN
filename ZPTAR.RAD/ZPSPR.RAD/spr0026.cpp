// Кучеренко И.Е. Справочник страховщиков
// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0026.h"
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

// ---------------------------------------------------------------------------
__fastcall TfrSpStrah::TfrSpStrah(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0026(struct zpstrah *par, struct zpsppard *pard) {
	TfrSpStrah *frSpStrah;
	int ret = -1;
	try {
		frSpStrah = new TfrSpStrah(Application);
		frSpStrah->dxLCNew->Visible = false;
		frSpStrah->ret = &ret;
		frSpStrah->par = par;
		frSpStrah->cxTE_N->Properties->MaxLength = sizeof(frSpStrah->strah.n) - 1;
		frSpStrah->aNew->Enabled = true;
		frSpStrah->aKor->Enabled = true;
		frSpStrah->aDel->Enabled = true;
		frSpStrah->aOk->Enabled = true;
		frSpStrah->aNew->Visible = true;
		frSpStrah->aKor->Visible = true;
		frSpStrah->aDel->Visible = true;
		frSpStrah->aOk->Visible = true;
		/* if (pard == NULL) {
		 frSpStrah->aOk->Enabled = false;
		 frSpStrah->aOk->Visible = false;
		 frSpStrah->aOk->ShortCut = 0;
		 }
		 else {
		 frSpStrah->aNew->Enabled = false;
		 frSpStrah->aKor->Enabled = false;
		 frSpStrah->aDel->Enabled = false;
		 frSpStrah->aNew->Visible = false;
		 frSpStrah->aKor->Visible = false;
		 frSpStrah->aDel->Visible = false;

		 frSpStrah->aOk->Enabled = true;
		 frSpStrah->aOk->Visible = true;
		 } */
		frSpStrah->fstrah = fafonc(c_p->b_nc, "zpstrah");
		if (frSpStrah->fstrah == 0) {
			armerr(1, "Нет структуры Виды доходов!");
		}
		else {
			frSpStrah->aRefresh->Execute();
			frSpStrah->ShowModal();
			fafc(frSpStrah->fstrah);
		}
		delete frSpStrah;
	}
	catch (const Exception &e) {
		AnsiString ss = e.Message + " Модуль SPR0026  содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
		armerr(1, ss.c_str());
		ExitProcess(1);
	}
	catch (...) {
		AnsiString ss;
		unsigned long dwError = GetLastError();
		if (dwError != 0)
			ss = SysErrorMessage(dwError);
		else
			ss = "Не определенная ошибка";
		ss = ss + " Модуль SPR0026 содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
		armerr(1, ss.c_str());
		ExitProcess(1);
	}
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpStrah::aRefreshExecute(TObject *Sender) {
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
	CLR(strah);
	while (fargl(fstrah, &strah, sizeof(strah)) == 0) {
		ii = dc->AppendRecord();
		swb(&strah.kd, &rr, 2);
		dc->Values[ii][Vw_kod->Index] = rr;
		dc->Values[ii][Vw_n->Index] = OEMtoWS(strah.n, sizeof(strah.n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpStrah::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ushort kod;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (cxTE_N->Text.IsEmpty()) {
		armerr(2, "Введите наименование");
		cxTE_N->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(strah);
		kod = cxME_Kod->EditValue;
		swb(&kod, &strah.kd, 2);

		if (prNew == 1) {

			MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), strah.n, sizeof(strah.n));
			farwl(fstrah, &strah, sizeof(strah));
			ii = dc->AppendRecord();
			dc->Values[ii][Vw_kod->Index] = cxME_Kod->EditValue;
			dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

		}
		else {

			if (farel(fstrah, &strah, sizeof(strah)) == 0) {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), strah.n, sizeof(strah.n));
				farwl(fstrah, &strah, sizeof(strah));
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

void __fastcall TfrSpStrah::cxCancelClick(TObject *Sender) {
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

void __fastcall TfrSpStrah::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		prNew = 1;
		cxME_Kod->Enabled = false;
		dxLCNew->Visible = true;
		cxTE_N->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		cxOk->Enabled = false;
		cxME_Kod->Clear();
		new_kod_st();
		cxME_Kod->EditValue = new_strah;
		cxTE_N->Clear();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpStrah::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpStrah::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int ii, kk;
	ushort kod;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			// ii = dc->FocusedRecordIndex;
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				kod = dc->Values[kk][Vw_kod->Index];
				CLR(strah);
				swb(&kod, &strah.kd, 2);

				if (farel(fstrah, &strah, sizeof(strah)) == 0) {
					fard(fstrah, &strah);
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

void __fastcall TfrSpStrah::aKorExecute(TObject *Sender) {
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

void __fastcall TfrSpStrah::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpStrah::cxTE_NExit(TObject *Sender) {

	if (prNew == 1) {
		cxOk->Enabled = (cxTE_N->Text != "");

	}
	else {
		cxOk->Enabled = cxTE_N->Text.Length() > 0 && f;
	}
	if (cxOk->Enabled == true) {
		cxOk->SetFocus();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpStrah::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	ushort kod;
	if (dc->RecordCount != 0) {
		kod = dc->Values[dc->FocusedRecordIndex][Vw_kod->Index];
		swb(&kod, &((struct zpstrah *)par)->kd, 2);
		MVCTOL(UnToFm(dc->Values[dc->FocusedRecordIndex][Vw_n->Index], PgWin), ((struct zpstrah *)par)->n, sizeof(((struct zpstrah *)par)->n));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpStrah::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	if (this->aOk->Enabled) {
		aOk->Execute();

	}
}

// ---------------------------------------------------------------------------
void TfrSpStrah::new_kod_st() {
	ushort rr;

	new_strah = 0;
	CLR(strah);
	while (fargl(fstrah, &strah, sizeof(strah)) == 0) {
		swb(&strah.kd, &rr, 2);
		if (rr > new_strah)
			new_strah = rr;
	}
	++new_strah;

}
// ---------------------------------------------------------------------------
