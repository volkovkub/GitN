// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"

#include "SpOPS.h"
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
TfmSpOPS *fmSpOPS;

// ---------------------------------------------------------------------------
int IniSpOPS(int *par, int tspr) {
	int ret = 0;

	fmSpOPS = new TfmSpOPS(Application);
	try {
		fmSpOPS->ret = &ret;
		fmSpOPS->par = par;
		fmSpOPS->tspr = tspr;
		fmSpOPS->Init();
		fmSpOPS->ShowModal();
	}
	catch (...) {
	}
	delete fmSpOPS;
	return ret;
}

// ---------------------------------------------------------------------------
__fastcall TfmSpOPS::TfmSpOPS(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::Init() {
	char loc[10] = "";
	TcxGridDataController* dc = tv->DataController;

	lcEdit->Visible = false;
	if (dc->RecordCount != 0) {
		tv->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		tv->OptionsSelection->MultiSelect = false;
	}

	if (tspr == tbSpPFK1) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk1");
		struct zppfk spr;

		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);

		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Тип форм СЗВ-1\"";
		lcitKod->Caption = "Тип формы";
		tvKod->Caption = "Тип формы";

		memcpy(loc, par, sizeof(spr.k));
	}
	else if (tspr == tbSpPFK2) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk2");
		struct zppfk spr;

		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);

		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Категории плательщиков\"";
		lcitKod->Caption = "Код";
		tvKod->Caption = "Код";

		memcpy(loc, par, sizeof(spr.k));
	}
	else if (tspr == tbSpPFK3) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk3");
		struct zppfk spr;

		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);

		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Условия труда\"";
		lcitKod->Caption = "Код";
		tvKod->Caption = "Код";

		memcpy(loc, par, sizeof(spr.k));
	}
	else if (tspr == tbSpPFK4) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk4");
		struct zppfk spr;

		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);

		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Исчисляемый стаж (доп.сведения)\"";
		lcitKod->Caption = "Код";
		tvKod->Caption = "Код";

		memcpy(loc, par, sizeof(spr.k));
	}
	else if (tspr == tbSpPFK5) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk5");
		struct zppfk spr;

		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);

		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Выслуга лет (основание)\"";
		lcitKod->Caption = "Код";
		tvKod->Caption = "Код";

		memcpy(loc, par, sizeof(spr.k));
	}
	else if (tspr == tbSpPFK6) {
		int i;
		FCB tmp = fafo(c_p->b_zp, "zppfk6");
		struct zppfk6 spr;
		// dc->BeginFullUpdate();
		CLR(spr);
		while (fargl(tmp, &spr, sizeof(spr)) == 0) {
			i = dc->AppendRecord();
			dc->Values[i][tvKod->Index] = OEMtoAL(spr.k, sizeof(spr.k));
			dc->Values[i][tvName->Index] = OEMtoAL(spr.n, sizeof(spr.n));
		}
		fafc(tmp);
		// dc->EndFullUpdate();
		// edKod->Properties->EditMask = "!9999;1;0";
		fmSpOPS->Caption = "Справочник \"Код позиции списка\"";
		lcitKod->Caption = "Код списка";
		tvKod->Caption = "Код списка";

		memcpy(loc, par, sizeof(spr.k));
	}

	// aOk->Enabled = (tv->DataController->RecordCount != 0);
	/* if(dc->RecordCount != 0){
	 aOk->Enabled = true;//dc->RecordCount != 0;
	 aDel->Enabled = true;//dc->RecordCount != 0;
	 aKor->Enabled = true;//dc->RecordCount != 0;
	 } */

	if (loc[0] == 0)
		dc->FocusedRecordIndex = 0;
	else
		dc->Search->Locate(tvKod->Index, ((AnsiString)loc).SubString(1, sizeof(loc)));
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::aNewExecute(TObject *Sender) {
	aExit->Enabled = false;
	aOk->Enabled = false;
	aKor->Enabled = false;
	aNew->Enabled = false;
	aDel->Enabled = false;

	aExit->ShortCut = 0;
	dbgSpr->Enabled = false;
	newrec = true;
	edKod->Enabled = true;
	lcEdit->Visible = true;
	edKod->SetFocus();

	edKod->Text = "";
	edName->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = tv->DataController;
	aExit->Enabled = false;
	aOk->Enabled = false;
	aKor->Enabled = false;
	aNew->Enabled = false;
	aDel->Enabled = false;

	aExit->ShortCut = 0;
	dbgSpr->Enabled = false;
	newrec = false;
	edKod->Enabled = false;
	lcEdit->Visible = true;
	edName->SetFocus();

	edKod->Text = dc->Values[dc->FocusedRecordIndex][tvKod->Index];
	edName->Text = dc->Values[dc->FocusedRecordIndex][tvName->Index];
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::aDelExecute(TObject *Sender) {
	FCB tmp;
	Variant Rvv;
	if (warmerr(-1, this->Handle, "Удалить запись?") == 0) {
		TcxGridDataController* dc = tv->DataController;

		if (tspr == tbSpPFK1) {
			tmp = fafo(c_p->b_zp, "zppfk1");
			struct zppfk spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		else if (tspr == tbSpPFK2) {
			tmp = fafo(c_p->b_zp, "zppfk2");
			struct zppfk spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		else if (tspr == tbSpPFK3) {
			tmp = fafo(c_p->b_zp, "zppfk3");
			struct zppfk spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		else if (tspr == tbSpPFK4) {
			tmp = fafo(c_p->b_zp, "zppfk4");
			struct zppfk spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		else if (tspr == tbSpPFK5) {
			tmp = fafo(c_p->b_zp, "zppfk5");
			struct zppfk spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		else if (tspr == tbSpPFK6) {
			tmp = fafo(c_p->b_zp, "zppfk6");
			struct zppfk6 spr;

			CLR(spr);
			MVCTOL(UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][tvKod->Index].VOleStr).c_str(),
					spr.k, sizeof(spr.k));
			fard(tmp, &spr);

			fafc(tmp);
		}
		dc->DeleteSelection();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::aOkExecute(TObject *Sender) {

	TcxGridDataController* dc = tv->DataController;
	if (dc->RecordCount != 0) {
		if (dc->Values[dc->FocusedRecordIndex][tvKod->Index].VString != NULL) {
			char * kod = UnToFm(dc->Values[dc->FocusedRecordIndex][tvKod->Index], PgWin);
			if (tspr == tbSpPFK1 || tspr == tbSpPFK2 || tspr == tbSpPFK3 || tspr == tbSpPFK4 ||
					tspr == tbSpPFK5) {
				MVL(kod, ((struct zppfk*)par)->k, sizeof(((struct zppfk*)par)->k));
			}
			else if (tspr == tbSpPFK6) {
				MVL(kod, ((struct zppfk6*)par)->k, sizeof(((struct zppfk6*)par)->k));
			}
		}
		if (dc->Values[dc->FocusedRecordIndex][tvName->Index].VString != NULL) {
			char * name = UnToFm(dc->Values[dc->FocusedRecordIndex][tvName->Index], PgWin);
			if (tspr == tbSpPFK1 || tspr == tbSpPFK2 || tspr == tbSpPFK3 || tspr == tbSpPFK4 ||
					tspr == tbSpPFK5) {
				MVL(name, ((struct zppfk*)par)->n, sizeof(((struct zppfk*)par)->n));
			}
			else if (tspr == tbSpPFK6) {
				MVL(name, ((struct zppfk6*)par)->n, sizeof(((struct zppfk6*)par)->n));
			}
		}
		*ret = 1;
	}
	else
		*ret = 0;
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::bnSaveClick(TObject * Sender) {
	int i;
	TcxGridDataController* dc = tv->DataController;
	if (tspr == tbSpPFK1) {
		FCB tmp = fafo(c_p->b_zp, "zppfk1");
		struct zppfk spr;

		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
	else if (tspr == tbSpPFK2) {
		FCB tmp = fafo(c_p->b_zp, "zppfk2");
		struct zppfk spr;
		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
	else if (tspr == tbSpPFK3) {
		FCB tmp = fafo(c_p->b_zp, "zppfk3");
		struct zppfk spr;

		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
	else if (tspr == tbSpPFK4) {
		FCB tmp = fafo(c_p->b_zp, "zppfk4");
		struct zppfk spr;

		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
	else if (tspr == tbSpPFK5) {
		FCB tmp = fafo(c_p->b_zp, "zppfk5");
		struct zppfk spr;

		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
	else if (tspr == tbSpPFK6) {
		FCB tmp = fafo(c_p->b_zp, "zppfk6");
		struct zppfk6 spr;

		CLR(spr);
		MVCTOL(UniToAnsiStr(edKod->EditText).c_str(), spr.k, sizeof(spr.k));
		if (newrec && (farel(tmp, &spr, sizeof(spr)) == 0)) {
			warmerr(0, this->Handle, "Запись с указанным кодом уже существует!");
		}
		else {
			MVCTOL(UniToAnsiStr(edName->Text).c_str(), spr.n, sizeof(spr.n));
			farwl(tmp, &spr, sizeof(spr));
			(dc->FocusedRecordIndex != -1) ? i = dc->FocusedRecordIndex : i = 0;
			if (newrec) {
				i = dc->InsertRecord(i);
				dc->Values[i][tvKod->Index] = edKod->EditText;
			}
			dc->Values[i][tvName->Index] = edName->Text;
			dc->FocusedRecordIndex = i;
			dbgSpr->Enabled = true;
			lcEdit->Visible = false;
			aExit->ShortCut = VK_ESCAPE;
			aExit->Enabled = true;
			aOk->Enabled = true;
			aKor->Enabled = true;
			aNew->Enabled = true;
			aDel->Enabled = true;
		}
		fafc(tmp);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::bnCancelClick(TObject * Sender) {
	dbgSpr->Enabled = true;
	lcEdit->Visible = false;
	aExit->ShortCut = VK_ESCAPE;
	aExit->Enabled = true;
	aOk->Enabled = true;
	aKor->Enabled = true;
	aNew->Enabled = true;
	aDel->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfmSpOPS::tvFocusedRecordChanged(TcxCustomGridTableView * Sender,
		TcxCustomGridRecord * APrevFocusedRecord, TcxCustomGridRecord * AFocusedRecord,
		bool ANewItemRecordFocusingChanged) {
	aKor->Enabled = (tv->DataController->RecordCount != 0);
	aDel->Enabled = (tv->DataController->RecordCount != 0);
	aOk->Enabled = (tv->DataController->RecordCount != 0);
	if (tv->DataController->RecordCount == 0) {
		dbgSpr->RootLevelOptions->DetailFrameWidth = 2;
	}
	else {
		dbgSpr->RootLevelOptions->DetailFrameWidth = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmSpOPS::tvCustomDrawCell(TcxCustomGridTableView * Sender, TcxCanvas * ACanvas,
		TcxGridTableDataCellViewInfo * AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmSpOPS::tvDblClick(TObject * Sender) {
	aOkExecute(aOk);
}
// ---------------------------------------------------------------------------

void __fastcall TfmSpOPS::dbgSprEnter(TObject * Sender) {
	if (tv->DataController->RecordCount == 0) {
		dbgSpr->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------
