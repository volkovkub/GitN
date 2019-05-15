// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "frVi4et.h"
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
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrVV *frVV;

// ---------------------------------------------------------------------------
__fastcall TfrVV::TfrVV(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniVV(TStringGrid *SG, long *kod1, long *kod2, AnsiString *name1) {
	int ret = -1;
	frVV = new TfrVV(Application);
	try {

		frVV->ret = &ret;
		frVV->SG = SG;
		frVV->kod = 0;
		frVV->kodrf = 0;
		frVV->name = "";
		frVV->aOk->Enabled = true;
		frVV->aOk->Visible = true;

		frVV->aRefresh->Execute();
		frVV->ShowModal();

	}
	catch (...) {
	}
	*kod1 = frVV->kod;
	*kod2 = frVV->kodrf;
	*name1 = frVV->name;
	delete frVV;

	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrVV::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();

	for (int i = 1; i <= SG->RowCount - 1; i++) {

		ii = dc->AppendRecord();
		dc->Values[ii][Vw_kv->Index] = SG->Cells[0][i];
		dc->Values[ii][Vw_kod->Index] = SG->Cells[1][i];
		dc->Values[ii][Vw_kodrf->Index] = SG->Cells[2][i];
		dc->Values[ii][Vw_name->Index] = SG->Cells[3][i];

	}

	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrVV::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfrVV::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	if (dc->RecordCount != 0) {
		kod = dc->Values[dc->FocusedRecordIndex][Vw_kod->Index];
		kodrf = dc->Values[dc->FocusedRecordIndex][Vw_kodrf->Index];
		name = dc->Values[dc->FocusedRecordIndex][Vw_name->Index];

		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrVV::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	if (frVV->aOk->Enabled) {
		aOk->Execute();

	}
}
// ---------------------------------------------------------------------------
