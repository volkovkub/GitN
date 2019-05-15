// ---------------------------------------------------------------------------
// Выбор кодов начислений/удержаний
// 11.05.2011 г.
// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"
extern struct compar *c_p;

#include "spr0002.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxCheckBox"
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
TfrSpr0002 *frSpr0002;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0002::TfrSpr0002(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0002(struct rzud *ud) {
	int ret = -1;
	frSpr0002 = new TfrSpr0002(Application);
	try {
		// Таблица создается в модуле, откуда вызывается справочник
  	if (ud->fil_wrk == NULL || ud->fil_wrk == 0){
		armerr(1, "Не открыта рабочая таблица rabknus!");
		return 1;
	}
		else {
			frSpr0002->udfil = ud->fil_wrk;
			frSpr0002->RefreshSpr();

			frSpr0002->ShowModal();

			frSpr0002->CloseSpr();
			ret = frSpr0002->aRet;
		}
	}
	catch (...) {
	}
	delete frSpr0002;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrSpr0002::RefreshSpr() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	AnsiString ss;
	struct rabknus rknus;
	if (dc->RecordCount != 0) {
		cxGrTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rknus);
	while (fargl(udfil, &rknus, sizeof(rknus)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][cxGrTblkod->Index] = rknus.kod;
		dc->Values[ii][cxGrTblknu->Index] = rknus.knu;
		ss = "";
		ss = IntToStr(rknus.kod);
		if (rknus.knu > 0) {
			ss = ss + "." + IntToStr(rknus.knu);
		}
		dc->Values[ii][cxGrTblsknu->Index] = ss;
		dc->Values[ii][cxGrTbln->Index] = FmToUn(rknus.n, sizeof(rknus.n),PgDos);
		dc->Values[ii][cxGrTblpr->Index] = rknus.pr;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void TfrSpr0002::CloseSpr() {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii;
	bool vp = true;
	struct rabknus rknus;
	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		CLR(rknus);
		rknus.kod = (unsigned char)dc->Values[ii][cxGrTblkod->Index];
		rknus.knu = (unsigned char)dc->Values[ii][cxGrTblknu->Index];
		if (farel(udfil, &rknus, sizeof(rknus)) == 0) {
			vp = (bool)dc->Values[ii][cxGrTblpr->Index];
			if (vp == true)
				rknus.pr = 1;
			else
				rknus.pr = 0;
			farwl(udfil, &rknus, sizeof(rknus));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0002::cxGrTblprPropertiesEditValueChanged(TObject *Sender) {
	TcxGridDataController* dc = cxGrTbl->DataController;
	int ii, k, pr;

	ii = dc->FocusedRecordIndex;
	k = (int)dc->Values[ii][cxGrTblknu->Index];
	if (k > 0) {
		pr = (int)dc->Values[ii][cxGrTblpr->Index];
		if (pr == 0)
			dc->Values[ii][cxGrTblpr->Index] = 1;
		else
			dc->Values[ii][cxGrTblpr->Index] = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0002::cxGrTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	int kod = 0;

	if (!AViewInfo->GridRecord->Values[cxGrTblknu->Index].IsNull()){
		kod = (int)AViewInfo->GridRecord->Values[cxGrTblknu->Index];
  }
	if (kod == 0) {
		if (!AViewInfo->GridRecord->Focused) {
			ACanvas->FillRect(AViewInfo->Bounds, clMoneyGreen);
		}
		if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
			ACanvas->Brush->Color = clGradientInactiveCaption;
		}
	}
	else{
		if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
			ACanvas->Brush->Color = clGradientInactiveCaption;
		}
	}

}
// ---------------------------------------------------------------------------
