// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "SpOtsd.h"
#include "SpOts.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCurrencyEdit"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataControllerConditionalFormattingRulesManagerDialog"
#pragma link "cxDataStorage"
#pragma link "cxDateUtils"
#pragma link "cxDropDownEdit"
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
#pragma link "dxCore"
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
TfrSpOtsd *frSpOtsd;

// ---------------------------------------------------------------------------
short fmafw(struct ffcb *f, char *nk, char t, char l, char ll, char *n) {
	CharToOemA(n, n);
	return fmaf(f, nk, t, l, ll, n);
}

// ---------------------------------------------------------------------------
__fastcall TfrSpOtsd::TfrSpOtsd(TComponent* Owner) : Tfraspr03(Owner) {
	// TcxImageList
	Tfraspr03::BarManager->LargeImages = Tfraspr03::cxImageListD;
	BarManager->Bars->BeginUpdate();
	BarManager->Bars->EndUpdate();
	aNew->Caption = "Новый уровень";
	aNewCopy->Caption = "Новый под. уровень";
	aSave->Caption = "Итоговый уровень";
}

// ---------------------------------------------------------------------------
int IniSpOtsd(int d, int vsp, struct zpsppar1 *par1, struct fdate *fdpar) {
	int ret = -1;
	AnsiString rStr;
	frSpOtsd = new TfrSpOtsd(Application);

	frSpOtsd->b = (struct bsp*)c_p->b_sp;

	frSpOtsd->dxLayoutED->Enabled = false;
	frSpOtsd->dxLayoutED->Visible = false;

	if (vsp) {
		frSpOtsd->dxLayoutControlDate->Enabled = false;
		frSpOtsd->aOk->Enabled = true;
		frSpOtsd->aOk->Visible = true;
	}
	else {
		frSpOtsd->dxLayoutControlDate->Enabled = true;
		frSpOtsd->dxLayoutControlSp->Enabled = true;
	}
	frSpOtsd->predit = vsp;

	frSpOtsd->fdD = EncodeDate(fdpar->fd_yy + 1980, fdpar->fd_mm, 1);
	frSpOtsd->fd.fd_yy = fdpar->fd_yy;
	frSpOtsd->fd.fd_mm = fdpar->fd_mm;
	frSpOtsd->fd.fd_dd = 1;
	swb(&frSpOtsd->fd, &frSpOtsd->fdsw, 2);
	frSpOtsd->cxDate->Date = frSpOtsd->fdD;
	if (par1->par1 > 0) {
		frSpOtsd->KodOTS = par1->par1;
	}
	try {
		frSpOtsd->aRefresh->Execute();
		frSpOtsd->ShowModal();
		ret = frSpOtsd->aRet;
		if (ret == 1) {
			par1->par1 = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_kod->Index];

			// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kod")->AsInteger;
			par1->par2 = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_kodst->Index];
			// frSpOtsd->cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kodst")->AsInteger;
			par1->sum1 = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_sum->Index];
			// frSpOtsd->cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sum")->AsFloat;
			par1->sum2 = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_kf->Index];
			// frSpOtsd->cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kf")->AsFloat;
			par1->sum3 = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_sumkf->Index];
			// frSpOtsd->cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sumkf")->AsFloat;
			CLR(par1->nm);
			rStr = frSpOtsd->Vw->DataController->Values[frSpOtsd->Vw->DataController->FocusedRecordIndex][frSpOtsd->Vw_fr->Index];
			// frSpOtsd->cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("fr")->AsString;
			strcat(par1->nm, rStr.c_str());
		}
	}
	catch (...) {
	}
	delete frSpOtsd;
	return ret;
}

void __fastcall TfrSpOtsd::cxGridEnter(TObject *Sender) {
	aExit->ShortCut = 0;
	aExit->Enabled = false;
	aExit->Visible = false;
	if (predit == 0 && KodOTS > 1) {
		aNew->Enabled = true;
		aNew->Visible = true;
		aKor->Enabled = true;
		aKor->Visible = true;
		aNewCopy->Enabled = true;
		aNewCopy->Visible = true;
		aSave->Enabled = true;
		aSave->Visible = true;
		aDel->Enabled = true;
		aDel->Visible = true;
	}
	if (Vw->DataController->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxGridExit(TObject *Sender) {
	aNew->Enabled = false;
	aNew->Visible = false;
	aKor->Enabled = false;
	aKor->Visible = false;
	aNewCopy->Enabled = false;
	aNewCopy->Visible = false;
	aSave->Enabled = false;
	aSave->Visible = false;
	aDel->Enabled = false;
	aDel->Visible = false;
	if (Vw->DataController->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxDateEditing(TObject *Sender, bool &CanEdit) {
	DateEd = true;
	fdD_old = cxDate->Date.Val;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxDatePropertiesEditValueChanged(TObject *Sender) {
	unsigned short dd, mm, yy;

	if (DateEd) {
		if (!cxDate->EditValue.IsNull()) {
			DecodeDate(cxDate->EditValue.date, yy, mm, dd);
			if (fdD_old.Val != cxDate->EditValue.date) {
				fdD_old = cxDate->Date.Val;
				fd.fd_dd = 1;
				fd.fd_mm = mm;
				fd.fd_yy = yy - 1980;
				swb(&fd, &fdsw, 2);
				if (KodOTS) {
					aRefresh->Execute();
				}
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxButtonEdit1PropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	int prkr;
	struct zpsppar par;
	unsigned short dd, mm, yy;
	struct fdate fdSp;

	DecodeDate(cxDate->EditValue.date, yy, mm, dd);
	fdSp.fd_dd = 1;
	fdSp.fd_mm = mm;
	fdSp.fd_yy = yy - 1980;
	if (AButtonIndex == 0) {
		CLR(par);
		if (b->sts[7] == '9') {
			prkr = 1;
		}
		if (IniSpOts(prkr, 0, &par, (fdate*)&fdSp) == 1) {
			cxBtEdOTS->Text = par.nm;
			KodOTS = par.par1;
			aRefresh->Execute();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aRefreshExecute(TObject *Sender) {
	//
	TcxGridDataController* dc = Vw->DataController;
	ushort kodst;
	int ii;

	char rnm[101];
	dc->BeginUpdate();
	if (dc->RecordCount != 0) {
		while (dc->RecordCount != 0) {
			dc->DeleteRecord(dc->RecordCount - 1);
		}
	}
	dc->EndUpdate();

	if ((frotsd = fafo_wrk_uf(1, 3, 147)) == 0) {
		armerr(1, "Невозможно создать файл в wrk! (rotsd)");
	}

	fmdf(frotsd); // Удаление описания структуры
	// описание структуры
	fmafw(frotsd, "kod", 'u', 3, 1, "Код сетки");
	fmafw(frotsd, "kodst", 'd', 5, 0, "Код строки");
	fmafw(frotsd, "ld", 'u', 3, 0, "Длина константы");
	fmafw(frotsd, "sum", 'f', 14, 2, "Сумма");
	fmafw(frotsd, "kf", 'f', 14, 2, "Коэффициент");
	fmafw(frotsd, "sumkf", 'f', 14, 2, "Сумма итоговая");
	fmafw(frotsd, "it", 'u', 3, 0, "Признак выбора записи");
	fmafw(frotsd, "fr", 's', 21, 0, "Маска");
	fmafw(frotsd, "nm", 's', 101, 0, "Наименование");
	if (fmchdf(frotsd) != 0) {
		armerr(1, "Ошибка описания структуры ROTSD!!!");
	}
	fots = fafo(c_p->b_tr, "trots");
	CLR(rnm);
	CLR(ots);
	swb(&fd, &ots.fd, 2);
	ots.kod = KodOTS;
	ots.kodst = 0;
	farel(fots, &ots, sizeof(ots));
	MV(ots.nm, rnm);
	OemToCharBuffA(rnm, rnm,sizeof(rnm));
	cxBtEdOTS->Text = rnm;
	CLR(ots);
	swb(&fd, &ots.fd, 2);
	ots.kod = KodOTS;
	while (fargl(fots, &ots, sizeof(ots)) == 0 && cmp(&ots.fd, &fdsw, 2) == 0 && ots.kod == KodOTS) {
		if (ots.kodst != 0) {
			CLR(rotsd);
			rotsd.kod = ots.kod;
			rotsd.kodst = ots.kodst;
			rotsd.sum = ots.sum;
			rotsd.kf = ots.kf;
			rotsd.sumkf = ots.sumkf;
			rotsd.it = ots.it;
			MV(ots.fr, rotsd.fr);
			MV(ots.nm, rotsd.nm);
			farwl(frotsd, &rotsd, sizeof(rotsd));
		}
	}
	dc->BeginUpdate();
	CLR(rotsd);
	while (fargl(frotsd, &rotsd, sizeof(rotsd)) == 0) {
		swb(&rotsd.kodst, &kodst, 2);
		ii = dc->AppendRecord();
		dc->Values[ii][Vw_kod->Index] = rotsd.kod;
		dc->Values[ii][Vw_kodst->Index] = kodst;
		dc->Values[ii][Vw_sum->Index] = rotsd.sum;
		dc->Values[ii][Vw_kf->Index] = rotsd.kf;
		dc->Values[ii][Vw_sumkf->Index] = rotsd.sumkf;
		dc->Values[ii][Vw_it->Index] = rotsd.it;
		dc->Values[ii][Vw_fr->Index] = FmToUn(rotsd.fr, sizeof(rotsd.fr), PgDos);
		dc->Values[ii][Vw_nm->Index] = FmToUn(rotsd.nm, sizeof(rotsd.nm), PgDos);
	}
	dc->EndUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

	// fdsROTSD->Open();
	// cxGridDBTableVw->NavigatorButtons->First->Click();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxDateEnter(TObject *Sender) {
	aExit->ShortCut = VK_ESCAPE;
	aExit->Enabled = true;
	aExit->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxBtEdOTSEnter(TObject *Sender) {
	aExit->ShortCut = VK_ESCAPE;
	aExit->Enabled = true;
	aExit->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxDateKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	if (Key == VK_RETURN || (Key == VK_TAB && Shift.Empty())) {
		SelectNext(ActiveControl, true, true);
	}
	else if ((Key == VK_TAB && Shift.Contains(ssShift))) {
		SelectNext(ActiveControl, false, true);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxBtEdOTSKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	if (Key == VK_RETURN) {
		if (KodOTS == 0) {
			Key = VK_SPACE;
		}
		else {
			Key = VK_TAB;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aNewExecute(TObject *Sender) {
	// Новый уровень
	char r_str[21];

	fledit = 0;
	dxLayoutED->Enabled = true;
	dxLayoutED->Visible = true;
	dxLayoutControlFR->Caption = "Код уровня";

	dxLayoutControlFR->Enabled = false;
	dxLayoutControlSUM->Enabled = false;
	dxLayoutControlSUM->Visible = false;
	dxLayoutControlKF->Enabled = false;
	dxLayoutControlKF->Visible = false;
	dxLayoutControlSUMKF->Enabled = false;
	dxLayoutControlSUMKF->Visible = false;

	dxLayoutControlDate->Visible = false;
	dxLayoutControlSp->Visible = false;
	cxGr->Enabled = false;
	CLR(r_str);
	sprintf(r_str, "%2.2d", KodOTS);
	cxMaskEdFR->Text = r_str;
	cxMaskEDfrnew->Text = "";
	cxTEDnm->Text = "";
	cxCEDsum->Value = 0;
	cxCEDkf->Value = 0;
	cxCEDsumkf->Value = 0;
	dxLayoutControlFRNEW->Enabled = true;
	dxLayoutControlFRNEW->Visible = true;
	cxMaskEDfrnew->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxOkClick(TObject *Sender) {
	// сохранить
	AnsiString r_fr;
	Integer ii;
	struct fdate fdr;
	ushort rkodst;
	AnsiString rStr;
	bool ok = true;
	TcxGridDataController* dc1 = Vw->DataController;
	if (fledit == 0) {
		r_fr = cxMaskEdFR->Text + "." + cxMaskEDfrnew->Text;
		ii = dc1->FindRecordIndexByText(0, Vw_fr->Index, r_fr, false, true, true);
		if (ii != -1) {
			dc1->FocusedRecordIndex = ii;
			armerr(1, "Такая запись уже существует !!!");
			cxMaskEDfrnew->SetFocus();
			ok = false;
		}
		else {
			rkodst = fmgg(c_p->b_tr, "G_OTS", 1);
		}
	}
	else { // корректировка
		rkodst = dc1->Values[dc1->FocusedRecordIndex][Vw_kodst->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kodst")->AsInteger;
		r_fr = dc1->Values[dc1->FocusedRecordIndex][Vw_fr->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("fr")->AsString;
	}
	if (ok) {
		CLR(ots);
		swb(&fd, &ots.fd, 2);
		ots.kod = KodOTS;
		swb(&rkodst, &ots.kodst, 2);
		ots.sum = cxCEDsum->Value;
		ots.kf = cxCEDkf->Value;
		ots.sumkf = cxCEDsumkf->Value;
		if (cxCEDsumkf->Value) {
			ots.it = 1;
		}
		rStr = cxTEDnm->Text;
		strcat(ots.nm, rStr.c_str());
		CharToOemA(ots.nm, ots.nm);
		strcat(ots.fr, r_fr.c_str());
		mov(&ots, &ots1, sizeof(ots));
		farwl(fots, &ots, sizeof(ots));
		if (fd.fd_mm != 12) {
			mov(&fd, &fdr, 2);
			for (ii = fd.fd_mm + 1; ii <= 12; ii++) {
				fdr.fd_mm = ii;
				swb(&fdr, &ots1.fd, 2);
				farwl(fots, &ots1, sizeof(ots));
			}
		}
		if (fledit == 0) {
			ii = dc1->AppendRecord();
			dc1->Values[ii][Vw_kod->Index] = KodOTS;
			dc1->Values[ii][Vw_kodst->Index] = rkodst;
			dc1->Values[ii][Vw_sum->Index] = cxCEDsum->Value;
			dc1->Values[ii][Vw_kf->Index] = cxCEDkf->Value;
			dc1->Values[ii][Vw_sumkf->Index] = cxCEDsumkf->Value;
			if (cxCEDsumkf->Value) {
				dc1->Values[ii][Vw_it->Index] = 1;
			}
			else {
				dc1->Values[ii][Vw_it->Index] = 0;
			}
			dc1->Values[ii][Vw_fr->Index] = r_fr;
			dc1->Values[ii][Vw_nm->Index] = Trim(cxTEDnm->Text);
		}
		else {
			dc1->Edit();
			dc1->Values[dc1->FocusedRecordIndex][Vw_kod->Index] = KodOTS;
			dc1->Values[dc1->FocusedRecordIndex][Vw_kodst->Index] = rkodst;
			dc1->Values[dc1->FocusedRecordIndex][Vw_sum->Index] = cxCEDsum->Value;
			dc1->Values[dc1->FocusedRecordIndex][Vw_kf->Index] = cxCEDkf->Value;
			dc1->Values[dc1->FocusedRecordIndex][Vw_sumkf->Index] = cxCEDsumkf->Value;
			if (cxCEDsumkf->Value) {
				dc1->Values[dc1->FocusedRecordIndex][Vw_it->Index] = 1;
			}
			else {
				dc1->Values[dc1->FocusedRecordIndex][Vw_it->Index] = 0;
			}
			dc1->Values[dc1->FocusedRecordIndex][Vw_fr->Index] = r_fr;
			dc1->Values[dc1->FocusedRecordIndex][Vw_nm->Index] = Trim(cxTEDnm->Text);

		}
		dc1->Post();
		if (fledit == 0)
			dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, Vw_fr->Index, r_fr, false, true, true);
		dxLayoutED->Enabled = false;
		dxLayoutED->Visible = false;
		dxLayoutControlDate->Visible = true;
		dxLayoutControlSp->Visible = true;
		cxGr->Enabled = true;
		cxGr->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxCancelClick(TObject *Sender) {
	dxLayoutED->Enabled = false;
	dxLayoutED->Visible = false;
	dxLayoutControlDate->Visible = true;
	dxLayoutControlSp->Visible = true;
	cxGr->Enabled = true;
	cxGr->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aNewCopyExecute(TObject *Sender) {
	// создать вложенный
	fledit = 0;

	dxLayoutED->Enabled = true;
	dxLayoutED->Visible = true;
	dxLayoutControlFR->Caption = "Код уровня";
	dxLayoutControlFR->Enabled = false;
	dxLayoutControlSUM->Enabled = false;
	dxLayoutControlSUM->Visible = false;
	dxLayoutControlKF->Enabled = false;
	dxLayoutControlKF->Visible = false;
	dxLayoutControlSUMKF->Enabled = false;
	dxLayoutControlSUMKF->Visible = false;

	dxLayoutControlDate->Visible = false;
	dxLayoutControlSp->Visible = false;
	cxGr->Enabled = false;
	cxMaskEdFR->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_fr->Index];
	// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("fr")->AsString;
	cxMaskEDfrnew->Text = "";
	cxTEDnm->Text = "";
	cxCEDsum->Value = 0;
	cxCEDkf->Value = 0;
	cxCEDsumkf->Value = 0;
	dxLayoutControlFRNEW->Enabled = true;
	dxLayoutControlFRNEW->Visible = true;
	cxMaskEDfrnew->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aSaveExecute(TObject *Sender) {
	// Ввод сумм
	char r_str[21];

	fledit = 0;
	dxLayoutED->Enabled = true;
	dxLayoutED->Visible = true;
	dxLayoutControlFR->Caption = "Код уровня";
	dxLayoutControlFR->Enabled = false;
	dxLayoutControlSUM->Enabled = true;
	dxLayoutControlSUM->Visible = true;
	dxLayoutControlKF->Enabled = true;
	dxLayoutControlKF->Visible = true;
	dxLayoutControlSUMKF->Enabled = true;
	dxLayoutControlSUMKF->Visible = true;

	dxLayoutControlDate->Visible = false;
	dxLayoutControlSp->Visible = false;
	cxGr->Enabled = false;
	cxMaskEdFR->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_fr->Index];
	if (cxMaskEdFR->Text.Length() == 0) {
		CLR(r_str);
		sprintf(r_str, "%2.2d", KodOTS);
		cxMaskEdFR->Text = r_str;
	}
	cxMaskEDfrnew->Clear();
	cxTEDnm->Clear();
	cxCEDsum->Value = 0;
	cxCEDkf->Value = 0;
	cxCEDsumkf->Value = 0;
	dxLayoutControlFRNEW->Enabled = true;
	dxLayoutControlFRNEW->Visible = true;
	cxMaskEDfrnew->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc1 = Vw->DataController;

	struct trostp ostp;
	FCB fostp;
	struct trvstp vstp;
	FCB fvstp;

	struct zpls ls;
	FCB fls;
	struct zplsfi lsfi;
	FCB flsfi;

	struct zplssow lssow;
	FCB flssow;

	uchar kod, kod_it, Del_no = 0;
	ushort kodst, sw_kodst; ;
	AnsiString rfr;

	fls = fafo(c_p->b_zp, "zpls");
	flsfi = fafo(c_p->b_zp, "zplsfi");
	fostp = fafo(c_p->b_tr, "trostp");
	fvstp = fafo(c_p->b_tr, "trvstp");
	flssow = fafo(c_p->b_zp, "zplssow");
	if (dc1->FocusedRecordIndex != -1) {
		if (armerr(-1, "Удалить ???") == 0) {
			aNew->Enabled = false;
			aNew->Visible = true;
			aKor->Enabled = false;
			aKor->Visible = true;
			aNewCopy->Enabled = false;
			aNewCopy->Visible = true;
			aSave->Enabled = false;
			aSave->Visible = true;
			aDel->Enabled = false;
			aDel->Visible = true;
			kod = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_kod->Index];
			kodst = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_kodst->Index];
			if (kodst > 0) {
				kod_it = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_it->Index];
				if (kod_it > 0) {
					swb(&kodst, &sw_kodst, 2);
					CLR(ostp);
					while (fargl(fostp, &ostp, sizeof(ostp)) == 0) {
						if (ostp.kots == kod && ostp.kraz == sw_kodst) {
							Del_no = 2;
							break;
						}
					}
					CLR(vstp);
					while (fargl(fvstp, &vstp, sizeof(vstp)) == 0) {
						if (vstp.kots == kod && vstp.kraz == sw_kodst) {
							Del_no = 2;
							break;
						}
					}
					if (Del_no != 2) {
						CLR(ls);
						while (fargl(fls, &ls, sizeof(ls)) == 0) {
							if ((ls.raz == kod && ls.kraz == kodst) || (ls.uraz == kod && ls.ukraz == kodst)) {
								Del_no = 2;
								break;
							}
						}
					}
					if (Del_no != 2) {
						CLR(lsfi);
						while (fargl(flsfi, &lsfi, sizeof(lsfi)) == 0) {
							if ((lsfi.raz == kod && lsfi.kraz == kodst) || (lsfi.uraz == kod && lsfi.ukraz == kodst)) {
								Del_no = 2;
								break;
							}
						}
					}
					if (Del_no != 2) {
						CLR(lssow);
						while (fargl(flssow, &lssow, sizeof(lssow)) == 0) {
							if (lssow.raz == kod && lssow.kraz == kodst) {
								Del_no = 2;
								break;
							}
						}
					}
				}
				else {
					rfr = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_fr->Index];
					rfr = rfr + ".";
					if (dc1->FindRecordIndexByText(0, Vw_fr->Index, rfr, true, true, true) != -1) {
						armerr(2, " Есть вложенный уровень !!!");
						Del_no = 1;
					}
				}
				if (Del_no == 2) {
					armerr(2, "Данные используются !!!");
				}
				if (Del_no == 0) {
					CLR(ots);
					while (fargl(fots, &ots, sizeof(ots)) == 0) {
						if (ots.kod == kod && ots.kodst == sw_kodst) {
							fard(fots, &ots);
						}
					}
					Vw->DataController->DeleteFocused();
				}
			}
			aNew->Enabled = true;
			aNew->Visible = true;
			aKor->Enabled = true;
			aKor->Visible = true;
			aNewCopy->Enabled = true;
			aNewCopy->Visible = true;
			aSave->Enabled = true;
			aSave->Visible = true;
			aDel->Enabled = true;
			aDel->Visible = true;
		}
	}
	fafc(fls);
	fafc(flsfi);
	fafc(fostp);
	fafc(fvstp);
	fafc(flssow);
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aKorExecute(TObject *Sender) {
	// корретировка
	dxLayoutED->Enabled = true;
	dxLayoutED->Visible = true;
	dxLayoutControlDate->Visible = false;
	dxLayoutControlSp->Visible = false;
	cxGr->Enabled = false;
	cxMaskEDfrnew->Clear();

	if (Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_sum->Index].VDouble > 0) {
		dxLayoutControlFR->Enabled = true;
		dxLayoutControlFR->Caption = "Код";
		cxMaskEdFR->Enabled = false;
		cxMaskEdFR->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_fr->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("fr")->AsString;
		dxLayoutControlFRNEW->Enabled = false;
		dxLayoutControlFRNEW->Visible = false;
		dxLayoutControlSUM->Enabled = true;
		dxLayoutControlSUM->Visible = true;
		dxLayoutControlKF->Enabled = true;
		dxLayoutControlKF->Visible = true;
		dxLayoutControlSUMKF->Enabled = true;
		dxLayoutControlSUMKF->Visible = true;
		cxCEDsum->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_sum->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sum")->AsFloat;
		cxCEDkf->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_kf->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kf")->AsFloat;
		cxCEDsumkf->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_sumkf->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sumkf")->AsFloat;
		cxTEDnm->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_nm->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("nm")->AsString;
	}
	else {
		dxLayoutControlFR->Enabled = true;
		dxLayoutControlFR->Caption = "Код";
		cxMaskEdFR->Enabled = false;
		cxMaskEdFR->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_fr->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("fr")->AsString;
		dxLayoutControlFRNEW->Enabled = false;
		dxLayoutControlFRNEW->Visible = false;
		dxLayoutControlSUM->Enabled = false;
		dxLayoutControlSUM->Visible = false;
		dxLayoutControlKF->Enabled = false;
		dxLayoutControlKF->Visible = false;
		dxLayoutControlSUMKF->Enabled = false;
		dxLayoutControlSUMKF->Visible = false;
		cxCEDsum->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_sum->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sum")->AsFloat;
		cxCEDkf->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_kf->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("kf")->AsFloat;
		cxCEDsumkf->Value = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_sumkf->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("sumkf")->AsFloat;
		cxTEDnm->Text = Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_nm->Index];
		// cxGridDBTableVw->DataController->DataSource->DataSet->FieldByName("nm")->AsString;

	}
	cxTEDnm->SetFocus();
	fledit = 1;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::aOkExecute(TObject *Sender) {
	Tfraspr03::aOkExecute(Sender);

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	TRect ARect;
	int vv;
	vv = AViewInfo->GridRecord->Values[Vw_it->Index];
	if (vv == 0) {
		if (!AViewInfo->GridRecord->Focused) {
			ACanvas->SetBrushColor(clMoneyGreen);
			ACanvas->Font->Color = clBlack;
		}
		if (AViewInfo->GridRecord->Focused && !AViewInfo->Selected) {
			ACanvas->FillRect(AViewInfo->Bounds, clMoneyGreen);
			ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
		}
	}
	else {
		if (AViewInfo->GridRecord->Focused && !AViewInfo->Selected) {
			ACanvas->FillRect(AViewInfo->Bounds, clSkyBlue);
			ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::VwDblClick(TObject *Sender) {
	if (Vw->DataController->Values[Vw->DataController->FocusedRecordIndex][Vw_it->Index]) {
		aOk->Execute();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::VwKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	if (Key == VK_ESCAPE) {
		cxBtEdOTS->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxGrEnter(TObject *Sender) {
	aExit->ShortCut = 0;
	aExit->Enabled = false;
	aExit->Visible = false;
	if (predit == 0 && KodOTS > 1) {
		aNew->Enabled = true;
		aNew->Visible = true;
		aKor->Enabled = true;
		aKor->Visible = true;
		aNewCopy->Enabled = true;
		aNewCopy->Visible = true;
		aSave->Enabled = true;
		aSave->Visible = true;
		aDel->Enabled = true;
		aDel->Visible = true;
	}
	if (Vw->DataController->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpOtsd::cxGrExit(TObject *Sender) {
	aNew->Enabled = false;
	aNew->Visible = false;
	aKor->Enabled = false;
	aKor->Visible = false;
	aNewCopy->Enabled = false;
	aNewCopy->Visible = false;
	aSave->Enabled = false;
	aSave->Visible = false;
	aDel->Enabled = false;
	aDel->Visible = false;
	if (Vw->DataController->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 0;
	}
}
// ---------------------------------------------------------------------------
