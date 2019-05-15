// ---------------------------------------------------------------------------
// Тип образовательного учреждения
// 18.05.2011 год
// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"
#include "..\ZPBANK.RAD\banks.h"

extern struct compar *c_p;

#include "spr0003.h"
#include "spr0005.h"
#include "spr0004.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
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
TfrSpr0004 *frSpr0004;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0004::TfrSpr0004(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0004(struct zpsptou *par, struct zpsppard *pard) {
	int ret = -1;
	try {
		frSpr0004 = new TfrSpr0004(Application);
		writebspzp(&frSpr0004->bzp);
		// Тип банка для выгрузки
		frSpr0004->ret = &ret;
		frSpr0004->par = par;
		frSpr0004->tipform = par->tf;
		frSpr0004->dxLayoutAllGNew->Visible = false;
		frSpr0004->dxLayoutAllGNewF->Visible = false;
		frSpr0004->aNew->Enabled = false;
		frSpr0004->aNew->ShortCut = 0;
		frSpr0004->aDel->Enabled = false;
		frSpr0004->aDel->ShortCut = 0;
		if (pard == NULL) {
			frSpr0004->aOk->Enabled = false;
			frSpr0004->aOk->Visible = true;
			frSpr0004->aOk->ShortCut = 0;
			frSpr0004->cxBEtf->Enabled = true;
		}
		else {
			frSpr0004->aOk->Enabled = true;
			frSpr0004->aOk->Visible = true;
			frSpr0004->cxBEtf->Enabled = false;
			frSpr0004->dxLayoutControl1Group2->Enabled = false;
			frSpr0004->dxLayoutControl1Group4->Enabled = false;
		}
		frSpr0004->ftform = fafo(c_p->b_zp, "zptform");
		frSpr0004->fsptou = fafo(c_p->b_zp, "zpsptou");
		frSpr0004->fptou = fafo(c_p->b_zp, "zpptou");
		frSpr0004->fptouf = fafo(c_p->b_zp, "zpptouf");
		frSpr0004->ffin = fafo(c_p->b_nc, "zpfin");
		frSpr0004->fkpn = fafo(c_p->b_zp, "kdrkpn");
		if (frSpr0004->ftform == 0) {
			armerr(1, "Нет структуры Тип формы!");
		}
		else if (frSpr0004->fsptou == 0) {
			armerr(1, "Нет структуры Тип общеобразовательного учреждения!");
		}
		else if (frSpr0004->fptou == 0) {
			armerr(1, "Нет таблицы Привязка учреждений к типу общеобразовательного учреждения!");
		}
		else if (frSpr0004->fptouf == 0) {
			armerr(1, "Нет таблицы Привязка источников финансирования к типу общеобразовательного учреждения!");
		}
		else {
			if (frSpr0004->tipform > 0) {
				CLR(frSpr0004->tform);
				frSpr0004->tform.tf = frSpr0004->tipform;
				if (farel(frSpr0004->ftform, &frSpr0004->tform, sizeof(frSpr0004->tform)) == 0) {
					frSpr0004->cxBEtf->Text = IntToStr(frSpr0004->tform.tf) + " " + frSpr0004->tform.nm;
				}
			}
			else {
				frSpr0004->tipform = 0;
				frSpr0004->cxBEtf->Clear();
				frSpr0004->cxBEtf->Enabled = true;
			}
			frSpr0004->aRefresh->Execute();
			frSpr0004->ShowModal();

			fafc(frSpr0004->ftform);
			fafc(frSpr0004->fsptou);
			fafc(frSpr0004->fptou);
			fafc(frSpr0004->fptouf);
			fafc(frSpr0004->ffin);
			fafc(frSpr0004->fkpn);
		}
	}
	catch (...) {
	}
	delete frSpr0004;
	return ret;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dcOw = VwOw->DataController;
	TcxGridDataController* dcF = VwFin->DataController;
	int ii;
	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	if (dcOw->RecordCount != 0) {
		VwOw->OptionsSelection->MultiSelect = true;
		dcOw->SelectAll();
		dcOw->DeleteSelection();
		VwOw->OptionsSelection->MultiSelect = false;
	}
	if (dcF->RecordCount != 0) {
		VwFin->OptionsSelection->MultiSelect = true;
		dcF->SelectAll();
		dcF->DeleteSelection();
		VwFin->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(sptou);
	sptou.tf = tipform;
	if (farel(fsptou, &sptou, sizeof(sptou)) == 0) {
		ii = dc->AppendRecord();
		dc->Values[ii][Vwtou->Index] = sptou.tou;
		dc->Values[ii][Vwnm->Index] = sptou.nm;
	}
	while (fargl(fsptou, &sptou, sizeof(sptou)) == 0 && sptou.tf == tipform) {
		ii = dc->AppendRecord();
		dc->Values[ii][Vwtou->Index] = sptou.tou;
		dc->Values[ii][Vwnm->Index] = sptou.nm;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
		VwFocusedRecordChanged(NULL, NULL, NULL, true);
		// cxGrOw->RootLevelOptions->DetailFrameWidth = 0;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0004::aOkExecute(TObject *Sender) {

	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount != 0) {
		((struct zpsptou*)par)->tf = tipform;
		((struct zpsptou*)par)->tou = (unsigned char)dc->Values[dc->FocusedRecordIndex][Vwtou->Index];
		char * name = UniToAnsiStr(dc->Values[dc->FocusedRecordIndex][Vwnm->Index].VOleStr).c_str();
		MVL(name, ((struct zpsptou*)par)->nm, sizeof(((struct zpsptou*)par)->nm));
		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBEtfPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	struct zpsppard sppard;
	uchar otform;

	otform = tipform;
	CLR(tform1);
	tform1.tf = tipform;
	CLR(sppard);
	sppard.gpar = 1;
	if (IniSpr0003(&tform1, &sppard) == 1) {
		cxBEtf->SetFocus();
		tipform = tform1.tf;
		cxBEtf->Text = tform1.nm; // наименование
		if (otform != tipform && tipform != 0) {
			aRefresh->Execute();
		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0004::cxBEtfEnter(TObject *Sender) {
	if (cxBEtf->Enabled) {
		aExit->Enabled = true;
		aExit->Visible = true;
		aExit->ShortCut = VK_ESCAPE;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::VwKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_ESCAPE && cxBEtf->Enabled) {
		cxBEtf->SetFocus();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBEtfExit(TObject *Sender) {
	if (cxBEtf->Enabled) {
		if (tipform == 0) {
			cxBEtfPropertiesButtonClick(NULL, NULL);
		}
		else {
			aExit->Enabled = false;
			aExit->Visible = false;
			aExit->ShortCut = 0;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::VwDblClick(TObject *Sender) {
	aOk->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::VwFocusedRecordChanged(TcxCustomGridTableView *Sender,
		TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged)

{
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dcOw = VwOw->DataController;
	TcxGridDataController* dcF = VwFin->DataController;
	int ii, iiOw, iiF;
	unsigned char ktou;

	if (dc->FocusedRecordIndex != -1) {
		ii = dc->FocusedRecordIndex;
		ktou = (unsigned char)dc->Values[ii][Vwtou->Index];
		if (dcOw->RecordCount != 0) {
			VwOw->OptionsSelection->MultiSelect = true;
			dcOw->SelectAll();
			dcOw->DeleteSelection();
			VwOw->OptionsSelection->MultiSelect = false;
		}
		dcOw->BeginFullUpdate();
		CLR(ptou);
		ptou.tf = tipform;
		ptou.tou = ktou;
		while (fargl(fptou, &ptou, sizeof(ptou)) == 0 && ptou.tf == tipform && ptou.tou == ktou) {
			iiOw = dcOw->AppendRecord();
			CLR(kpn);
			kpn.kdkp = ptou.owner;
			if (farel(fkpn, &kpn, sizeof(kpn)) == 0) {
				dcOw->Values[iiOw][VwOwkdkp->Index] = kpn.kdkp;
				dcOw->Values[iiOw][VwOwsname->Index] = OEMtoAL(kpn.sname, sizeof(kpn.sname));
			}
		}
		dcOw->EndFullUpdate();
		if (dcOw->RecordCount != 0) {
			dcOw->GotoFirst();
		}

		if (dcF->RecordCount != 0) {
			VwFin->OptionsSelection->MultiSelect = true;
			dcF->SelectAll();
			dcF->DeleteSelection();
			VwFin->OptionsSelection->MultiSelect = false;
		}
		dcF->BeginFullUpdate();
		CLR(ptouf);
		ptouf.tf = tipform;
		ptouf.tou = ktou;
		if (farel(fptouf, &ptouf, sizeof(ptouf)) == 0) {
			iiF = dcF->AppendRecord();
			dcF->Values[iiF][VwFink->Index] = 0;
			dcF->Values[iiF][VwFinnm->Index] = "Основной бюджет";
		}
		while (fargl(fptouf, &ptouf, sizeof(ptouf)) == 0 && ptouf.tf == tipform && ptouf.tou == ktou) {
			iiF = dcF->AppendRecord();
			CLR(fin);
			fin.k = ptouf.fin;
			if (farel(ffin, &fin, sizeof(fin)) == 0) {
				dcF->Values[iiF][VwFink->Index] = fin.k;
				dcF->Values[iiF][VwFinnm->Index] = OEMtoAL(fin.n, sizeof(fin.n));
			}
		}
		dcF->EndFullUpdate();
		if (dcF->RecordCount != 0) {
			dcF->GotoFirst();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrOwEnter(TObject *Sender) {
	aNew->Enabled = true;
	aNew->ShortCut = VK_F7;
	if (VwOw->DataController->RecordCount == 0) {
		cxGrOw->RootLevelOptions->DetailFrameWidth = 2;
		aDel->Enabled = false;
		aDel->ShortCut = 0;
	}
	else {
		cxGrOw->RootLevelOptions->DetailFrameWidth = 0;
		aDel->Enabled = true;
		aDel->ShortCut = VK_F8;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrOwExit(TObject *Sender) {
	aNew->Enabled = false;
	aNew->ShortCut = 0;
	aDel->Enabled = false;
	aDel->ShortCut = 0;
	cxGrOw->RootLevelOptions->DetailFrameWidth = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrEnter(TObject *Sender) {
	if (Vw->DataController->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}
	else {
		cxGr->RootLevelOptions->DetailFrameWidth = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrExit(TObject *Sender) {
	cxGr->RootLevelOptions->DetailFrameWidth = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrFinEnter(TObject *Sender) {
	aNew->Enabled = true;
	aNew->ShortCut = VK_F7;
	if (VwFin->DataController->RecordCount == 0) {
		cxGrFin->RootLevelOptions->DetailFrameWidth = 2;
		aDel->Enabled = false;
		aDel->ShortCut = 0;
	}
	else {
		cxGrFin->RootLevelOptions->DetailFrameWidth = 0;
		aDel->Enabled = true;
		aDel->ShortCut = VK_F8;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxGrFinExit(TObject *Sender) {
	aNew->Enabled = false;
	aNew->ShortCut = 0;
	aDel->Enabled = false;
	aDel->ShortCut = 0;
	cxGrFin->RootLevelOptions->DetailFrameWidth = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBEownerPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	struct zpsppar par;

	KOwner = 0;
	CLR(par);
	par.par1 = bzp.zpkr;
	if (l_call("ZPSPR1", "GKPU", &par, (fdate*)&bzp.uyy, 0) == 1) {
		KOwner = par.par1;
		cxBEowner->Text = par.nm1; // Краткое наименование
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::aNewExecute(TObject *Sender) {
	if (VwOw->IsControlFocused) {
		dxLayoutAllGNew->Visible = true;
		cxBEowner->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		dxLayoutControl1Item2->Enabled = false;
		dxLayoutControl1Item3->Enabled = false;
		dxLayoutControl1Item4->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		cxBEowner->Clear();
		if (VwOw->DataController->RecordCount == 0) {
			cxGrOw->RootLevelOptions->DetailFrameWidth = 2;
		}
		else {
			cxGrOw->RootLevelOptions->DetailFrameWidth = 0;
		}
	}
	else if (VwFin->IsControlFocused) {
		dxLayoutAllGNewF->Visible = true;
		cxBOk1->SetFocus();
		dxLayoutControl1Item1->Enabled = false;
		dxLayoutControl1Item2->Enabled = false;
		dxLayoutControl1Item3->Enabled = false;
		dxLayoutControl1Item4->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		if (VwFin->DataController->RecordCount == 0) {
			cxGrFin->RootLevelOptions->DetailFrameWidth = 2;
		}
		else {
			cxGrFin->RootLevelOptions->DetailFrameWidth = 0;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBCancelClick(TObject *Sender) {
	dxLayoutAllGNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	dxLayoutControl1Item3->Enabled = true;
	dxLayoutControl1Item4->Enabled = true;
	cxGrOw->SetFocus();
	cxGrOwEnter(NULL);
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dcOw = VwOw->DataController;
	int ii, iiOw;
	unsigned char ktou;
	Variant RKey;

	if (dc->FocusedRecordIndex != -1) {
		ii = dc->FocusedRecordIndex;
		ktou = (unsigned char)dc->Values[ii][Vwtou->Index];
		if (cxBEowner->Text.Length() == 0)
			KOwner = 0;
		if (KOwner == 0) {
			armerr(1, "Не выбрано учреждение!");
			cxBEowner->SetFocus();
			return;
		}
		CLR(ptou);
		ptou.tf = tipform;
		ptou.tou = ktou;
		swb(&KOwner, &ptou.owner, sizeof(ptou.owner));
		if (farel(fptou, &ptou, sizeof(ptou)) == 0) {
			armerr(1, "Такая запись уже существует!");
			cxBEowner->SetFocus();
			return;
		}
		farwl(fptou, &ptou, sizeof(ptou));

		iiOw = dcOw->AppendRecord();
		dcOw->Values[iiOw][VwOwkdkp->Index] = ptou.owner;
		dcOw->Values[iiOw][VwOwsname->Index] = cxBEowner->Text;

		RKey = dcOw->Values[iiOw][VwOwsname->Index];
		dcOw->Post();

		cxGrOw->Enabled = true;
		dcOw->Search->Locate(VwOwsname->Index, RKey);
		cxGrOw->SetFocus();
		dcOw->Search->Cancel();

	}
	else {
		cxGrOw->Enabled = true;
		cxGrOw->SetFocus();
	}
	dxLayoutAllGNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	dxLayoutControl1Item3->Enabled = true;
	dxLayoutControl1Item4->Enabled = true;
	cxGrOwEnter(NULL);
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dcOw = VwOw->DataController;
	TcxGridDataController* dcF = VwFin->DataController;
	int ii, kk;
	unsigned char ktou;

	if (VwOw->IsControlFocused) {
		if (dcOw->FocusedRecordIndex != -1) {
			ii = dcOw->FocusedRecordIndex;
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				ktou = (unsigned char)dc->Values[kk][Vwtou->Index];
				CLR(ptou);
				ptou.owner = (unsigned short)dcOw->Values[ii][VwOwkdkp->Index];
				ptou.tf = tipform;
				ptou.tou = ktou;
				if (farel(fptou, &ptou, sizeof(ptou)) == 0) {
					fard(fptou, &ptou);
					dcOw->DeleteFocused();
					if (dcOw->RecordCount == 0) {
						cxGrOw->RootLevelOptions->DetailFrameWidth = 2;
					}
				}
				cxGrOwEnter(NULL);
			}
		}
	}
	if (VwFin->IsControlFocused) {
		if (dcF->FocusedRecordIndex != -1) {
			ii = dcF->FocusedRecordIndex;
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {
				ktou = (unsigned char)dc->Values[kk][Vwtou->Index];
				CLR(ptouf);
				ptouf.fin = (unsigned char)dcF->Values[ii][VwFink->Index];
				ptouf.tf = tipform;
				ptouf.tou = ktou;
				if (farel(fptouf, &ptouf, sizeof(ptouf)) == 0) {
					fard(fptouf, &ptouf);
					dcF->DeleteFocused();
					if (dcF->RecordCount == 0) {
						cxGrFin->RootLevelOptions->DetailFrameWidth = 2;
					}
				}
				cxGrFinEnter(NULL);
			}
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0004::cxBCancel1Click(TObject *Sender) {
	dxLayoutAllGNewF->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	dxLayoutControl1Item3->Enabled = true;
	dxLayoutControl1Item4->Enabled = true;
	cxGrFin->SetFocus();
	cxGrFinEnter(NULL);

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0004::cxBOk1Click(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dcF = VwFin->DataController;
	struct rfino rfin;
	struct rzud ud;
	int ii, iiF;
	unsigned char NP, ktou;
	CLR(ud);
	if ((ud.fil_fin=fafo_wrk_uf(0, 2, 51))== 0){
		armerr(1, "Невозможно создать файл в wrk! (rfino)");
	}

	NP = 1;
	CLR(rfin);
	rfin.np = NP;
	rfin.fin = 0;
	CharToOemBuffA("Основной бюджет", rfin.n, sizeof("Основной бюджет"));
	farwl(ud.fil_fin, &rfin,sizeof(rfin));
	CLR(fin);
	while (fargl(ffin, &fin, sizeof(fin)) == 0) {
		NP++;
		CLR(rfin);
		rfin.np = NP;
		rfin.fin = fin.k;
		mov(fin.n, &rfin.n, sizeof(fin.n));
		farwl(ud.fil_fin, &rfin,sizeof(rfin));
	}
	IniSpr0005(&ud);

	if (dc->FocusedRecordIndex != -1) {
		ii = dc->FocusedRecordIndex;
		ktou = (unsigned char)dc->Values[ii][Vwtou->Index];
		CLR(rfin);
		while (fargl(ud.fil_fin, &rfin,sizeof(rfin)) == 0) {
			if (rfin.p == 0)
				continue;
			CLR(ptouf);
			ptouf.tf = tipform;
			ptouf.tou = ktou;
			ptouf.fin = rfin.fin;
			if (farel(fptouf, &ptouf, sizeof(ptouf)) != 0) {
				farwl(fptouf, &ptouf, sizeof(ptouf));
				iiF = dcF->AppendRecord();
				dcF->Values[iiF][VwFink->Index] = rfin.fin;
				dcF->Values[iiF][VwFinnm->Index] = OEMtoAL(rfin.n, sizeof(rfin.n));
				dcF->Post();
			}
		}
	}

	dxLayoutAllGNewF->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	dxLayoutControl1Item3->Enabled = true;
	dxLayoutControl1Item4->Enabled = true;
	cxGrFin->Enabled = true;
 	aRefreshExecute(cxGrFin);
	cxGrFin->SetFocus();
}
// ---------------------------------------------------------------------------
