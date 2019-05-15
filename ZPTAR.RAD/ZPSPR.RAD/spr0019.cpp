// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0019.h"
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
TfrSpr0019 *frSpr0019;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0019::TfrSpr0019(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0019(int Vspr1, int *par) {
	int ret = -1;
	frSpr0019 = new TfrSpr0019(Application);
	try {

		frSpr0019->Vspr = Vspr1;
		frSpr0019->ret = &ret;
		frSpr0019->par = par;
		frSpr0019->aOk->Enabled = true;
		frSpr0019->aOk->Visible = true;

		frSpr0019->aRefresh->Execute();
		frSpr0019->ShowModal();

	}
	catch (...) {
	}
	// *kod1=frVV->kod;
	// *kod2=frVV->kodrf;
	// *name1=frVV->name;
	delete frSpr0019;

	return ret;

}

void __fastcall TfrSpr0019::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();

	if (Vspr == 1) {
		for (int jj = 0; jj < 4; jj++) {
			ii = dc->AppendRecord();
			dc->Values[ii][kd->Index] = jj;
			switch (jj) {
			case 0:
				dc->Values[ii][nm->Index] = "Начислять страховые взносы (НР)";
				break;
			case 1:
				dc->Values[ii][nm->Index] = "Не начислять страховые взносы";
				break;
			case 2:
				dc->Values[ii][nm->Index] = "Работник-иностранец, временно проживает на территории России (ВЖНР)";
				break;
			case 3:
				dc->Values[ii][nm->Index] = "Работник-иностранец, временно пребывает на территории России (ВПНР)";
				break;
			}
		}
	}
	if (Vspr == 2) {;
		for (int jj = 0; jj < 2; jj++) {
			ii = dc->AppendRecord();
			dc->Values[ii][kd->Index] = jj;
			switch (jj) {
			case 0:
				dc->Values[ii][nm->Index] = "ставка НДФЛ 13%";
				break;
			case 1:
				dc->Values[ii][nm->Index] = "ставка НДФЛ 30%";
				break;
			}
		}
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0019::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		if (!dc->Values[dc->FocusedRecordIndex][kd->Index].IsNull()) {
			((struct zpsppar3*)par)->par4 = (unsigned char)dc->Values[dc->FocusedRecordIndex][kd->Index];
			if (!dc->Values[dc->FocusedRecordIndex][nm->Index].IsNull()) {
				char * kod = UnToFm(dc->Values[dc->FocusedRecordIndex][nm->Index], PgWin);
				MVL(kod, ((struct zpsppar3*)par)->nm, sizeof(((struct zpsppar3*)par)->nm));
				*ret = 1;
			}
			else {
				*ret = 0;
			}
		}
		else {
			*ret = 0;
		}
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------
