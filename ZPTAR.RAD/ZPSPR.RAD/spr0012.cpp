// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;
#include "spr0012.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCurrencyEdit"
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
TfrSpr0012 *frSpr0012;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0012::TfrSpr0012(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0012(struct zpso *par, struct zpsppard *pard) {
	int ret = -1;
	frSpr0012 = new TfrSpr0012(Application);
	try {

		frSpr0012->dxLCNew->Visible = false;
		frSpr0012->ret = &ret;
		frSpr0012->par = par;

		frSpr0012->aNew->Enabled = true;

		frSpr0012->aDel->Enabled = true;
		frSpr0012->aNew->Visible = true;

		frSpr0012->aDel->Visible = true;

		frSpr0012->fso = fafo(c_p->b_nc, "zpso");
		if (frSpr0012->fso == 0) {
			armerr(1, "Нет структуры Пред.суммы для статист.!");
		}
		else {
			frSpr0012->aRefresh->Execute();
			frSpr0012->ShowModal();
			fafc(frSpr0012->fso);
		}
	}
	catch (...) {
	}
	delete frSpr0012;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0012::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	long rr;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(so);
	while (fargl(fso, &so, sizeof(so)) == 0) {
		ii = dc->AppendRecord();
		swb(&so.sum, &rr, 4);
		dc->Values[ii][VwSum->Index] = rr;

	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0012::cxCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	aNew->Enabled = true;
	aDel->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	cxGr->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0012::VwDataControllerBeforePost(TcxCustomDataController *ADataController)

{
	//
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0012::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {

		cxME_Sum->Enabled = true;
		dxLCNew->Visible = true;
		cxME_Sum->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		cxOk->Enabled = false;
		cxME_Sum->Clear();

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0012::cxME_SumExit(TObject *Sender) {
	if (cxME_Sum->Text != "") {

		if (cxME_Sum->EditValue > 2147483647) {
			armerr(2, "Введенное значение вне диапозоне данных");
			cxME_Sum->EditValue = 2147483647;
		}
	}
	cxOk->Enabled = (cxME_Sum->Text != "");

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0012::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	long sum;
	int kk;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				CLR(so);
				sum = dc->Values[kk][VwSum->Index];
				swb(&sum, &so.sum, 4);

				if (farel(fso, &so, sizeof(so)) == 0) {
					fard(fso, &so);
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

void __fastcall TfrSpr0012::cxOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	long sum;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (cxME_Sum->EditValue.IsNull()) {
		armerr(2, "Введите код");
		cxME_Sum->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(so);

		sum = cxME_Sum->EditValue;
		swb(&sum, &so.sum, 4);

		if (farel(fso, &so, sizeof(so)) == 0) {
			armerr(2, "Данная сумма уже введена");
			cxME_Sum->SetFocus();
		}
		else {
			farwl(fso, &so, sizeof(so));
			ii = dc->AppendRecord();
			dc->Values[ii][VwSum->Index] = cxME_Sum->EditValue;

		}

		dxLCNew->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		aNew->Enabled = true;
		aDel->Enabled = true;
		aExit->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr->SetFocus();
		dc->FocusedRecordIndex = ii;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0012::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
