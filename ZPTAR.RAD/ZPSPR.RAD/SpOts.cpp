// ---------------------------------------------------------------------------

#include <vcl.h>
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "SpOts.h"
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
TfrSpOts *frSpOts;

// ---------------------------------------------------------------------------
short fmafw(struct ffcb *f, char *nk, char t, char l, char ll, char *n) {
	CharToOemA(n, n);
	return fmaf(f, nk, t, l, ll, n);
}

// ---------------------------------------------------------------------------
__fastcall TfrSpOts::TfrSpOts(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpOts(int d, int vsp, struct zpsppar *par, struct fdate *fdpar) {
	int ret = -1;
	AnsiString rStr;
	try {
		frSpOts = new TfrSpOts(Application);
		frSpOts->fdpar.fd_dd = 1;
		frSpOts->fdpar.fd_mm = fdpar->fd_mm;
		frSpOts->fdpar.fd_yy = fdpar->fd_yy;

		frSpOts->aOk->Enabled = true;
		frSpOts->aOk->Visible = true;

		frSpOts->dxLayoutControlTop->Enabled = false;
		frSpOts->dxLayoutControlTop->Visible = false;
		frSpOts->flUser = d;

		if (d == 0) { // Корректировка ввод нового запрещена
			frSpOts->aNew->Enabled = false;
			frSpOts->aNew->Visible = false;
			frSpOts->aKor->Enabled = false;
			frSpOts->aKor->Visible = false;
		}
		if (d == 1) {
			frSpOts->aNew->Enabled = true;
			frSpOts->aNew->Visible = true;
			frSpOts->aKor->Enabled = true;
			frSpOts->aKor->Visible = true;
			frSpOts->aDel->Enabled = true;
			frSpOts->aDel->Visible = true;
		}
		frSpOts->fd.fd_dd = fdpar->fd_dd;
		frSpOts->fd.fd_mm = fdpar->fd_mm;
		frSpOts->fd.fd_yy = fdpar->fd_yy;
		swb(&frSpOts->fd, &frSpOts->fdsw, 2);
		frSpOts->aRefresh->Execute();
		frSpOts->ShowModal();
		ret = frSpOts->aRet;
		if (ret == 1) {
			par->par1 = frSpOts->Vw->DataController->Values[frSpOts->Vw->DataController->FocusedRowIndex][frSpOts->Vw_kod->Index];
			CLR(par->nm);
			rStr = frSpOts->Vw->DataController->Values[frSpOts->Vw->DataController->FocusedRowIndex][frSpOts->Vw_nm->Index];
			strcat(par->nm, rStr.c_str());
		}
		del_fil(frSpOts->frots);
		fafc(frSpOts->fots);
	}
	catch (...) {
	}
	delete frSpOts;
	return ret;
}

void __fastcall TfrSpOts::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	ushort kod;
	int ii;
	dc->BeginUpdate();
	if (dc->RecordCount != 0) {
		while (dc->RecordCount != 0) {
			dc->DeleteRecord(dc->RecordCount - 1);
		}
	}
	dc->EndUpdate();

	if ((frots = fafo_wrk_uf(0, 1, 101)) == 0) {
		armerr(1, "Невозможно создать файл в wrk! (rots)");
	}
	fots = fafo(c_p->b_tr, "trots");
	dc->BeginUpdate();
	CLR(ots);
	swb(&fd, &ots.fd, 2);
	while (fargl(fots, &ots, sizeof(ots)) == 0 && cmp(&ots.fd, &fdsw, 2) == 0) {
		if (ots.kodst == 0) {
			ii = dc->AppendRecord();
			dc->Values[ii][Vw_kod->Index] = ots.kod;
			dc->Values[ii][Vw_nm->Index] = FmToUn(ots.nm, sizeof(ots.nm), PgDos);
			CLR(rots);
			rots.kod = ots.kod;
			MV(ots.nm, rots.nm);
			farwl(frots, &rots, sizeof(rots));
		}
	}
	dc->EndUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::aNewExecute(TObject *Sender) {
	// Ввод нового
	char rkod;

	for (rkod = 2; rkod < 127; rkod++) {
		CLR(rots);
		rots.kod = rkod;
		if (farel(frots, &rots, sizeof(rots)) != 0) {
			break;
		}
	}
	if (rkod < 127) {
		flKor = 0;
		dxLayoutControlTop->Enabled = true;
		dxLayoutControlTop->Visible = true;
		cxCEdkod->Value = rkod;
		cxCEdkod->Enabled = false;
		cxTEDnm->Clear();
		aOk->Enabled = false;
		aOk->Visible = false;
		aKor->Enabled = false;
		aKor->Visible = false;
		aExit->Enabled = false;
		aExit->Visible = false;
		aExit->ShortCut = 0;
		aDel->Enabled = false;
		aDel->Visible = false;
		cxTEDnm->SetFocus();
		cxGr->Enabled = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::cxOkClick(TObject *Sender) {
	struct trots ots1;
	struct fdate fdr;
	uchar ii;
	AnsiString rStr;
	TcxGridDataController* dc1 = Vw->DataController;
	if (flKor == 1) {
		dc1->Edit();
		dc1->Values[dc1->FocusedRecordIndex][Vw_nm->Index] = Trim(cxTEDnm->Text);
	}
	else {
		ii = dc1->AppendRecord();
		dc1->Values[ii][Vw_kod->Index] = cxCEdkod->Value;
		dc1->Values[ii][Vw_nm->Index] = Trim(cxTEDnm->Text);
		CLR(rots);
		rots.kod = cxCEdkod->Value;
		farwl(frots, &rots, sizeof(rots));
	}

	CLR(ots);
	swb(&fdpar, &ots.fd, 2);
	ots.kod = cxCEdkod->Value;
	ots.kodst = 0;
	rStr = cxTEDnm->Text;
	strcat(ots.nm, rStr.c_str());
	CharToOemA(ots.nm, ots.nm);
	sprintf(ots.fr, "%2.2d", ots.kod);
	mov(&ots, &ots1, sizeof(ots));
	farwl(fots, &ots, sizeof(ots));
	if (fdpar.fd_mm != 12) {
		mov(&fdpar, &fdr, 2);
		for (ii = fdpar.fd_mm + 1; ii <= 12; ii++) {
			fdr.fd_mm = ii;
			swb(&fdr, &ots1.fd, 2);
			farwl(fots, &ots1, sizeof(ots));
		}
	}
	dc1->Post();
	dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, Vw_kod->Index, FloatToStr(cxCEdkod->Value), false, true, true);
	cxGr->Enabled = true;
	cxGr->SetFocus();
	dxLayoutControlTop->Enabled = false;
	dxLayoutControlTop->Visible = false;
	aOk->Enabled = true;
	aOk->Visible = true;
	aKor->Enabled = true;
	aKor->Visible = true;
	aExit->Enabled = true;
	aExit->Visible = true;
	aExit->ShortCut = VK_ESCAPE;
	aDel->Enabled = true;
	aDel->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::cxCancelClick(TObject *Sender) {
	cxGr->Enabled = true;
	cxGr->SetFocus();
	dxLayoutControlTop->Enabled = false;
	dxLayoutControlTop->Visible = false;
	aOk->Enabled = true;
	aOk->Visible = true;
	aKor->Enabled = true;
	aKor->Visible = true;
	aExit->Enabled = true;
	aExit->Visible = true;
	aExit->ShortCut = VK_ESCAPE;
	aDel->Enabled = true;
	aDel->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::aKorExecute(TObject *Sender) {
	flKor = 1;
	dxLayoutControlTop->Enabled = true;
	dxLayoutControlTop->Visible = true;
	cxCEdkod->Value = Vw->DataController->Values[Vw->DataController->FocusedRowIndex][Vw_kod->Index];
	cxCEdkod->Enabled = false;
	cxTEDnm->Text = Vw->DataController->Values[Vw->DataController->FocusedRowIndex][Vw_nm->Index];
	aOk->Enabled = false;
	aOk->Visible = false;
	aKor->Enabled = false;
	aKor->Visible = false;
	aExit->Enabled = false;
	aExit->Visible = false;
	aExit->ShortCut = 0;
	aDel->Enabled = false;
	aDel->Visible = false;
	cxTEDnm->SetFocus();
	cxGr->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::aDelExecute(TObject *Sender) {
	uchar kod;
	bool prdel;

	aDel->Enabled = false;
	aDel->Visible = false;
	if (armerr(-1, "Удалить Запись?") == 0) {
		prdel = true;
		kod = Vw->DataController->Values[Vw->DataController->FocusedRowIndex][Vw_kod->Index];
		CLR(ots);
		while (fargl(fots, &ots, sizeof(ots)) == 0) {
			if (ots.kod == kod && ots.kodst > 0) {
				prdel = false;
				break;
			}
		}
		if (prdel == true) {
			CLR(ots);
			while (fargl(fots, &ots, sizeof(ots)) == 0) {
				if (ots.kod == kod) {
					fard(fots, &ots);
				}
			}
			Vw->DataController->DeleteFocused();
		}
		else {
			armerr(1, "Отраслевая сетка содержит данные, удаление невозможно !!!");
		}
	}
	aDel->Enabled = true;
	aDel->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
		TShiftState AShift, bool &AHandled) {
	aOk->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOts::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
