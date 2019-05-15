// ---------------------------------------------------------------------------
// Кучеренко И.Е. Справочник страхователей

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0023.h"
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
__fastcall TfrSpKpp::TfrSpKpp(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0023(struct zpkpp *par, struct zpsppard *pard) {
	TfrSpKpp *frSpKpp;
	int ret = -1;

	try {
		frSpKpp = new TfrSpKpp(Application);
		frSpKpp->dxLCNew->Visible = false;
		frSpKpp->ret = &ret;
		frSpKpp->par = par;
		frSpKpp->cxTE_N->Properties->MaxLength = sizeof(frSpKpp->kpp.n) - 1;
		frSpKpp->aNew->Enabled = true;
		frSpKpp->aKor->Enabled = true;
		frSpKpp->aDel->Enabled = true;
		frSpKpp->aOk->Enabled = true;
		frSpKpp->aNew->Visible = true;
		frSpKpp->aKor->Visible = true;
		frSpKpp->aDel->Visible = true;
		frSpKpp->aOk->Visible = true;
		/* if (pard == NULL) {
		 frSpKpp->aOk->Enabled = false;
		 frSpKpp->aOk->Visible = false;
		 frSpKpp->aOk->ShortCut = 0;
		 }
		 else {
		 frSpKpp->aNew->Enabled = false;
		 frSpKpp->aKor->Enabled = false;
		 frSpKpp->aDel->Enabled = false;
		 frSpKpp->aNew->Visible = false;
		 frSpKpp->aKor->Visible = false;
		 frSpKpp->aDel->Visible = false;

		 frSpKpp->aOk->Enabled = true;
		 frSpKpp->aOk->Visible = true;
		 } */
		frSpKpp->fkpp = fafonc(c_p->b_nc, "zpkpp");
		if (frSpKpp->fkpp == 0) {
			armerr(1, "Нет структуры Виды доходов!");
		}
		else {
			frSpKpp->aRefresh->Execute();
			frSpKpp->ShowModal();
			fafc(frSpKpp->fkpp);
		}
		delete frSpKpp;
	}
	catch (const Exception &e) {
		AnsiString ss = e.Message + " Модуль SPR0023  содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
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
		ss = ss + " Модуль SPR0023 содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
		armerr(1, ss.c_str());
		ExitProcess(1);
	}
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpKpp::aRefreshExecute(TObject *Sender) {
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
	CLR(kpp);
	while (fargl(fkpp, &kpp, sizeof(kpp)) == 0) {
		ii = dc->AppendRecord();
		swb(&kpp.kpp, &rr, 2);
		dc->Values[ii][Vw_kod->Index] = rr;
		dc->Values[ii][Vw_n->Index] = OEMtoWS(kpp.n, sizeof(kpp.n));
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKpp::cxOkClick(TObject *Sender) {
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

		CLR(kpp);
		kod = cxME_Kod->EditValue;
		swb(&kod, &kpp.kpp, 2);

		if (prNew == 1) {

			MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), kpp.n, sizeof(kpp.n));
			farwl(fkpp, &kpp, sizeof(kpp));
			ii = dc->AppendRecord();
			dc->Values[ii][Vw_kod->Index] = cxME_Kod->EditValue;
			dc->Values[ii][Vw_n->Index] = cxTE_N->Text;

		}
		else {

			if (farel(fkpp, &kpp, sizeof(kpp)) == 0) {

				MVCTOL(UnToFm(cxTE_N->Text.w_str(), PgWin), kpp.n, sizeof(kpp.n));
				farwl(fkpp, &kpp, sizeof(kpp));
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

void __fastcall TfrSpKpp::cxCancelClick(TObject *Sender) {
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

void __fastcall TfrSpKpp::aNewExecute(TObject *Sender) {
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
		new_kod();
		cxME_Kod->EditValue = new_kpp;
		cxTE_N->Clear();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKpp::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKpp::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int ii, kk;
	ushort kod;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			// ii = dc->FocusedRecordIndex;
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				kod = dc->Values[kk][Vw_kod->Index];
				CLR(kpp);
				swb(&kod, &kpp.kpp, 2);

				if (farel(fkpp, &kpp, sizeof(kpp)) == 0) {
					fard(fkpp, &kpp);
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

void __fastcall TfrSpKpp::aKorExecute(TObject *Sender) {
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

void __fastcall TfrSpKpp::cxTE_NEditing(TObject *Sender, bool &CanEdit) {
	f = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKpp::cxTE_NExit(TObject *Sender) {

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
void __fastcall TfrSpKpp::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	ushort kod;
	if (dc->RecordCount != 0) {
		kod = dc->Values[dc->FocusedRecordIndex][Vw_kod->Index];
		swb(&kod, &((struct zpkpp *)par)->kpp, 2);
		MVCTOL(UnToFm(dc->Values[dc->FocusedRecordIndex][Vw_n->Index], PgWin), ((struct zpkpp *)par)->n, sizeof(((struct zpkpp *)par)->n));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKpp::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
		TShiftState AShift, bool &AHandled) {
	if (this->aOk->Enabled) {
		aOk->Execute();

	}
}

// ---------------------------------------------------------------------------
void TfrSpKpp::new_kod() {
	ushort rr;

	new_kpp = 0;
	CLR(kpp);
	while (fargl(fkpp, &kpp, sizeof(kpp)) == 0) {
		swb(&kpp.kpp, &rr, 2);
		if (rr > new_kpp)
			new_kpp = rr;
	}
	++new_kpp;

}
// ---------------------------------------------------------------------------
