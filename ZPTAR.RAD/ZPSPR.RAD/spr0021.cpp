//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0021.h"
//---------------------------------------------------------------------------
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
TfrSpr0021 *frSpr0021;
//---------------------------------------------------------------------------
__fastcall TfrSpr0021::TfrSpr0021(TComponent* Owner)
	: Tfraspr03(Owner)
{
}
//---------------------------------------------------------------------------
int IniSpr0021(struct zpsppar *par) {
	int ret = -1;
	frSpr0021 = new TfrSpr0021(Application);
	try {
		frSpr0021->ret = &ret;
		frSpr0021->par = par;
		frSpr0021->aOk->Enabled = true;
		frSpr0021->aOk->Visible = true;
		frSpr0021->frsnilsnm = fafo(c_p->b_wrk, "rsnilsnm");
		if (frSpr0021->frsnilsnm == 0) {
			armerr(1, "Нет структуры !");
		}
		else {
			frSpr0021->aRefresh->Execute();
			frSpr0021->ShowModal();
			fafc(frSpr0021->frsnilsnm);
		}
	}
	catch (...) {
	}
	delete frSpr0021;
	return ret;
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0021::aRefreshExecute(TObject *Sender)
{
//
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rsnilsnm);
	while (fargl(frsnilsnm, &rsnilsnm, sizeof(rsnilsnm)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][fname->Index] = OEMtoWS(rsnilsnm.fname, sizeof(rsnilsnm.fname));
		dc->Values[ii][snils->Index] = OEMtoWS(rsnilsnm.snils, sizeof(rsnilsnm.snils));
	}
	dc->EndFullUpdate();
	Vw->FindItemByName("fname")->ApplyBestFit();

	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0021::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0021::VwDblClick(TObject *Sender)
{
	aOk->Execute();

}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0021::aOkExecute(TObject *Sender)
{
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		char * name = UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][fname->Index].VOleStr).c_str();
		MVL(name, ((struct zpsppar*)par)->nm, sizeof(((struct zpsppar*)par)->nm));
		char * name1 = UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][snils->Index].VOleStr).c_str();
		MVL(name1, ((struct zpsppar*)par)->nm1, sizeof(((struct zpsppar*)par)->nm1));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
//---------------------------------------------------------------------------

