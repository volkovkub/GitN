// ---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"
#include "l_call_bud.h"

extern struct compar *c_p;

#include "spr0014.h"
#include "spr0010.h"
#include "spr0018.h"
#include "spr0055.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxGridExportLink"   // экспорт в Excel
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
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
#pragma link "cxLabel"
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
TfrSpr0014 *frSpr0014;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0014::TfrSpr0014(TComponent* Owner) : Tfraspr03(Owner) {
}

bool IsOLEObjectInstalled(AnsiString Name) {

	Activex::TCLSID ClassID;
	HRESULT Rez;

	// Ищем CLSID OLE-объекта
	Rez = CLSIDFromProgID(PWideChar(WideString(Name)), &ClassID);

	if (Rez == S_OK)
			// Объект найден
				return true;
	else
		return false;
}

// ---------------------------------------------------------------------------
int IniSpr0014(struct zppstzn *par, struct zpsppard *pard) {
	int ret = -1;
	try {
		frSpr0014 = new TfrSpr0014(Application);
		frSpr0014->cxBEFin->Text = "Основной источник финансирования";
		frSpr0014->tfin = 0;
		frSpr0014->ttp = 0;

		writebspzp(&frSpr0014->bzp);
		frSpr0014->fdnst.fd_dd = 1;
		frSpr0014->fdnst.fd_mm = frSpr0014->bzp.uyy.mm;
		frSpr0014->fdnst.fd_yy = frSpr0014->bzp.uyy.yy;

		frSpr0014->cxDE->Date = EncodeDate(frSpr0014->fdnst.fd_yy + 1980, frSpr0014->fdnst.fd_mm, frSpr0014->fdnst.fd_dd);

		frSpr0014->dxLCNew->Visible = false;
		frSpr0014->ret = &ret;
		frSpr0014->par = par;

		frSpr0014->aNew->Enabled = true;
		frSpr0014->aKor->Enabled = true;
		frSpr0014->aDel->Enabled = true;
		frSpr0014->aNewCopy->Enabled = true;

		frSpr0014->aNew->Visible = true;
		frSpr0014->aKor->Visible = true;
		frSpr0014->aDel->Visible = true;
		frSpr0014->aNewCopy->Visible = true;

		frSpr0014->aPrnStr->Enabled = true;
		frSpr0014->aPrnStr->Visible = true;
		frSpr0014->aPrnStr->Caption = "Выгрузка в Excel";
		frSpr0014->aPrnStr->Hint = "Выгрузка в Excel";

		if (pard == NULL) {
			frSpr0014->aOk->Enabled = false;
			frSpr0014->aOk->Visible = false;
			frSpr0014->aOk->ShortCut = 0;
		}
		else {
			frSpr0014->aOk->Enabled = true;
			frSpr0014->aOk->Visible = true;
		}

		frSpr0014->fknus = fafonc(c_p->b_nc, "zpknus"); // н/у
		frSpr0014->ffin = fafonc(c_p->b_nc, "zpfin"); // и.ф.
		frSpr0014->ftp = fafonc(c_p->b_nc, "zptp"); // тип пер
		frSpr0014->fstzn = fafonc(c_p->b_nc, "zppstzn"); //
		frSpr0014->fkmo5 = fafonc(c_p->b_nc, "zpkmo5"); // строки в мо 5
		frSpr0014->fkfr = fafonc(c_p->b_nc, "zpkfr"); // ко
		frSpr0014->fop = fafonc(c_p->b_nc, "spop"); // справочник операций
		frSpr0014->fbsn = fafonc(c_p->b_nc, "spbsn");
		frSpr0014->fker = fafonc(c_p->b_nc, "spker");
		frSpr0014->fisf = fafonc(c_p->b_nc, "spisf");
		frSpr0014->fsbker = fafonc(c_p->b_nc, "spsbker");
		frSpr0014->ftf = fafonc(c_p->b_nc, "sptf");
		frSpr0014->fts = fafonc(c_p->b_nc, "spts");
		frSpr0014->fmrp = fafonc(c_p->b_nc, "spmrp");

		if (frSpr0014->fstzn == 0) {
			armerr(1, "Нет структуры");
			/// дописать
		}
		else {
			frSpr0014->aRefresh->Execute();
			frSpr0014->ShowModal();
			fafc(frSpr0014->fstzn);
		}
	}
	catch (...) {
	}
	delete frSpr0014;
	return ret;

}

void __fastcall TfrSpr0014::cxBEFinPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	uchar tmpfin;
	tmpfin = tfin;
	if (AButtonIndex == 1) {
		cxBEFin->Text = "Основной источник финансирования";
		cxBEFin->SetFocus();
		tfin = 0;
	}
	else {
		struct zpsppar par;
		struct bspzp bzp;
		CLR(par);
		CLR(bzp);
		if(IniSpFin(1, &par, &bzp) == 1){
		//if (l_call("ZPSPR", "GFIN", &par, &bzp) == 1)
			tfin = par.par1;
			cxBEFin->Text = par.nm;
		}
		else {
			tfin = 0;
			cxBEFin->Text = "Основной источник финансирования";

		}
	}
	if (tmpfin != tfin) {
		aRefresh->Execute();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::cxBEPerPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	uchar tmptp;
	tmptp = ttp;
	if (AButtonIndex == 1) {
		cxBEPer->Text = "";
		cxBEPer->SetFocus();
		ttp = 0;
	}
	else {
		CLR(tp);
		if (l_call("ZPSPR1", "GKTP", &tp) == 1){
			ttp = tp.k;
			cxBEPer->Text = tp.nm;

		}
		else {
			ttp = 0;
			cxBEPer->Text = "";

		}
	}
	if (tmptp != ttp) {
		aRefresh->Execute();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::cxDEEnter(TObject *Sender) {

	mov(&fdnst, &fduu, 2);
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxDEExit(TObject *Sender) {
	unsigned short dd, mm, yy;
	if (!cxDE->EditValue.IsNull()) {
		cxDE->Date.DecodeDate(&yy, &mm, &dd);
		fdnst.fd_dd = 1;
		fdnst.fd_mm = mm;
		fdnst.fd_yy = yy - 1980;
		cxDE->Date = EncodeDate(fdnst.fd_yy + 1980, fdnst.fd_mm, fdnst.fd_dd);

		if (cmpdt((struct fdt*)&fdnst, (struct fdt*)&fduu, 2) != 0) {
			aRefresh->Execute();
		}

	}
	else {
		cxDE->SetFocus();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::aRefreshExecute(TObject *Sender) { // доделать
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	char s[10];
	struct fdate fdt1, fdt;
	ushort kdkfr, nr;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	cxTextEdit1->Text = "";

	if (ttp != 0) {

		dc->BeginFullUpdate();

		CLR(stzn);
		swb(&fdnst, &stzn.fd, 2);
		stzn.fin = tfin;
		stzn.kdtp = ttp;
		swb(&fdnst, &fdt1, 2);
		while (fargl(fstzn, &stzn, sizeof(stzn)) == 0 && cmp(&fdt1, &stzn.fd, 2) == 0 && stzn.fin == tfin && stzn.kdtp == ttp) {

			ii = dc->AppendRecord();
			CLR(s);
			sprintf(s, "%2.2d.%2.2d", stzn.kod, stzn.knu);

			dc->Values[ii][VwVidKod->Index] = s; // H/У
			dc->Values[ii][VwVidNU->Index] = stzn.kod;
			dc->Values[ii][VwKodNU->Index] = stzn.knu;
			CLR(knus);
			knus.kod = stzn.kod;
			knus.knu = stzn.knu;
			if (farel(fknus, &knus, sizeof(knus)) == 0) {
				dc->Values[ii][VwVKName->Index] = OEMtoWS(knus.n, sizeof(knus.n));
			}

			if (stzn.pgk == 1) { // ГК
				dc->Values[ii][VwGK->Index] = "Да";
			}
			else {
				dc->Values[ii][VwGK->Index] = "Нет";
			}

			CLR(kmo5);
			kmo5.npp = stzn.npp;
			if (farel(fkmo5, &kmo5, sizeof(kmo5)) == 0) { // ЖО6
				dc->Values[ii][VwJOName->Index] = OEMtoWS(kmo5.n, sizeof(kmo5.n));
				dc->Values[ii][VwJO->Index] = kmo5.npp;
			}
			else {
				dc->Values[ii][VwJOName->Index] = "";
				dc->Values[ii][VwJO->Index] = 0;
			}

			swb(&stzn.kdkfr, &kdkfr, sizeof(stzn.kdkfr));
			dc->Values[ii][VwKO->Index] = kdkfr; // KO
			CLR(kfr);
			fdt = fdnst;
			fdt.fd_dd = 1;
			fdt.fd_mm = 1;

			swb(&fdt, &kfr.fdg, 2);
			kfr.kdkfr = stzn.kdkfr;
			if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {
				CLR(op);
				op.kd = kfr.kd;
				op.ko = kfr.ko;
				op.ks = kfr.ks;
				if (farel(fop, &op, sizeof(op)) == 0) {

					// дебет и кредит
					CLR(bsn);
					mov(&op.srd, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);
					dc->Values[ii][VwDebet->Index] = s;

					// кредит
					mov(&op.srk, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					dc->Values[ii][VwKredit->Index] = s;
				}

			}

		}
		dc->EndFullUpdate();
		if (dc->RecordCount != 0) {
			dc->GotoFirst();
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		if (ttp != 0) {

			prNew = 1;
			dxLCNew->Visible = true;
			cxBENU->Enabled = true;
			cxBENU->SetFocus();
			dxLayoutControl1Item2->Enabled = false;
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item6->Enabled = false;
			dxLayoutControl1Item5->Enabled = false;
			aNewCopy->Enabled = false;
			aNew->Enabled = false;
			aDel->Enabled = false;
			aKor->Enabled = false;
			aExit->Enabled = false;
			aExit->ShortCut = 0;
			aPrnStr->Enabled = false;

			// cxOk->Enabled = false;
			cxBENU->Clear();
			cxBEJO->Clear();
			cxBEKO->Clear();
			cxCBGK->ItemIndex = 0;

			dxLayoutControl1Item7->Enabled = false;
			dxLayoutControl1Item7->Visible = false;

			///label'ы
			cxLIFName->Caption = "";
			cxLIFNum->Caption = "";
			cxLKName->Caption = "";
			cxLKNum->Caption = "";
			cxLMerName->Caption = "";
			cxLMerNum->Caption = "";
			cxLSubName->Caption = "";
			cxLSubNum->Caption = "";
			cxLTipfName->Caption = "";
			cxLTipfNum->Caption = "";
			cxLTipsName->Caption = "";
			cxLTipsNum->Caption = "";

			dxLayoutControl1Item13->CaptionOptions->Text = "Дебет";
			dxLayoutControl1Item12->CaptionOptions->Text = "Кредит";

			jo = 0;

			knu = 0;
			kod = 0;
			kdkfr = 0;
			CLR(nuname);
			CLR(debet);
			CLR(kredit);
		}
		else {
			armerr(2, "Укажите тип персонала");
		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxBCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	dxLayoutControl1Item6->Enabled = true;
	dxLayoutControl1Item5->Enabled = true;

	aNew->Enabled = true;
	aDel->Enabled = true;
	aKor->Enabled = true;
	aNewCopy->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	aPrnStr->Enabled = true;
	cxGr->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxBENUPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	struct zpsppar par;
	char ss[60];

	CLR(par);

	if (l_call("ZPSPR1", "GKNUSN", &par) == 1) {
		cxBENU->SetFocus();

		CLR(stzn);
		swb(&fdnst, &stzn.fd, 2);
		stzn.fin = tfin;
		stzn.kdtp = ttp;
		stzn.kod = (uchar)par.par1;
		stzn.knu = (uchar) par.par2;

		if (farel(fstzn, &stzn, sizeof(stzn)) == 0) {
			armerr(1, "Такой код Начисления/Удержания - ' Внесен ' ");

		}
		else {
			kod = (uchar)par.par1;
			knu = (uchar) par.par2;
			CLR(ss);
			CLR(nuname);
			sprintf(ss, "%2.2u.%2.2u %s", par.par1, par.par2, par.nm);
			cxBENU->Text = AS(ss);
			sprintf(nuname, "%s", par.nm);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::FormShow(TObject *Sender) {
	cxBEFin->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxGrEnter(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxGrExit(TObject *Sender) {
	cxGr->RootLevelOptions->DetailFrameWidth = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxBEKOPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	if (AButtonIndex == 1) {
		cxBEKO->Text = "";
		cxBEKO->SetFocus();

		kdkfr = 0;
		CLR(debet);
		CLR(kredit);
		cxCBGK->ItemIndex = 0;

		///label'ы
		cxLIFName->Caption = "";
		cxLIFNum->Caption = "";
		cxLKName->Caption = "";
		cxLKNum->Caption = "";
		cxLMerName->Caption = "";
		cxLMerNum->Caption = "";
		cxLSubName->Caption = "";
		cxLSubNum->Caption = "";
		cxLTipfName->Caption = "";
		cxLTipfNum->Caption = "";
		cxLTipsName->Caption = "";
		cxLTipsNum->Caption = "";

		dxLayoutControl1Item13->CaptionOptions->Text = "Дебет";
		dxLayoutControl1Item12->CaptionOptions->Text = "Кредит";
	}
	else {

		struct zpsppar sppar;
		fdate fdt;
		ushort nr;

		char s[10];
		char ss[100];
		CLR(sppar);
		fdt = fdnst;
		fdt.fd_dd = 1;
		fdt.fd_mm = 1;

		CLR(sppar);
		if (IniSpr0018(0, &sppar, &fdt) == 1) {
		//BG 02/07/2018 if (l_call("ZPSPRSW", "GIKFR", 1, &sppar, &fdt) == 1) {

			swb(&sppar.par1, &kdkfr, 2);

			CLR(kfr);
			swb(&fdt, &kfr.fdg, 2);
			swb(&sppar.par1, &kfr.kdkfr, 2);

			if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

				cxBEKO->Text = sppar.par1;

				cxLKNum->Caption = OEMtoWS(kfr.ker, sizeof(kfr.ker));

				CLR(ker);
				mov(kfr.ker, ker.ker, sizeof(ker.ker));
				fare(fker, &ker);
				cxLKName->Caption = OEMtoWS(ker.name, sizeof(ker.name));

				cxLIFNum->Caption = OEMtoWS(kfr.isf, sizeof(kfr.isf));
				CLR(isf);
				mov(kfr.isf, isf.isf, sizeof(isf.isf));
				fare(fisf, &isf);
				cxLIFName->Caption = OEMtoWS(isf.name, sizeof(isf.name));

				cxLSubNum->Caption = OEMtoWS(kfr.sbker, sizeof(kfr.sbker));
				CLR(sbker);
				mov(kfr.sbker, sbker.subkesr, sizeof(sbker.subkesr));
				fare(fsbker, &sbker);
				cxLSubName->Caption = OEMtoWS(sbker.name, sizeof(sbker.name));

				cxLTipfNum->Caption = OEMtoWS(kfr.tf, sizeof(kfr.tf));
				CLR(tf);
				mov(kfr.tf, tf.tf, sizeof(tf.tf));
				fare(ftf, &tf);
				cxLTipfName->Caption = OEMtoWS(tf.name, sizeof(tf.name));

				cxLTipsNum->Caption = OEMtoWS(kfr.ts, sizeof(kfr.ts));
				CLR(ts);
				mov(kfr.ts, ts.ts, sizeof(ts.ts));
				fare(fts, &ts);
				cxLTipsName->Caption = OEMtoWS(ts.name, sizeof(ts.name));

				cxLMerNum->Caption = OEMtoWS(kfr.mrp, sizeof(kfr.mrp));
				CLR(mrp);
				mov(kfr.mrp, mrp.mrp, sizeof(mrp.mrp));
				fare(fmrp, &mrp);
				cxLMerName->Caption = OEMtoWS(mrp.name, sizeof(mrp.name));

				CLR(op);
				op.kd = kfr.kd;
				op.ko = kfr.ko;
				op.ks = kfr.ks;
				if (farel(fop, &op, sizeof(op)) == 0) {

					// дебет и кредит
					CLR(bsn);
					mov(&op.srd, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(debet, "%s", s);

					CLR(ss);
					sprintf(ss, "Дебет: %s", s);
					dxLayoutControl1Item13->CaptionOptions->Text = ss;

					// кредит
					mov(&op.srk, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(kredit, "%s", s);

					CLR(ss);
					sprintf(ss, "Кредит: %s", s);
					dxLayoutControl1Item12->CaptionOptions->Text = ss;
				}

			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::cxCBGKExit(TObject *Sender) {
	if (cxBEKO->Text == "") {
		cxCBGK->ItemIndex = 0;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::cxBEJOPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	if (AButtonIndex == 1) {
		cxBEJO->Text = "";
		cxBEJO->SetFocus();
		jo = 0;

	}
	else {
		struct zpsppard sppard;
		CLR(kmo5);
		CLR(sppard);
		sppard.gpar = 1;
		if (IniSpr0010(&kmo5, &sppard) == 1) {
			cxBEJO->SetFocus();
			cxBEJO->Text = OEMtoWS(kmo5.n, sizeof(kmo5.n)); // наименование
			jo = kmo5.npp;

		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::cxBOkClick(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	char s[10];
	ushort swkdkfr;
	bool Ok = true;
	ii = dc->FocusedRecordIndex;
	fdate yy;

	if (knu == 0 && kod == 0) { // !!!
		armerr(2, "Выберете Н/У");
		cxBENU->SetFocus();
		Ok = false;
	}

	if (Ok) {

		CLR(stzn);
		// swb(&fdnst, &stzn.fd, 2);
		yy = fdnst;
		stzn.fin = tfin;
		stzn.kdtp = ttp;
		stzn.kod = kod;
		stzn.knu = knu;
		stzn.kdkfr = kdkfr;
		stzn.npp = jo;

		if (cxCBGK->ItemIndex == 1) {
			stzn.pgk = 1;
		}
		else {
			stzn.pgk = 0;
		}

		if (prNew == 1) {
			ii = dc->AppendRecord();
			CLR(s);
			sprintf(s, "%2.2d.%2.2d", stzn.kod, stzn.knu);
			dc->Values[ii][VwVidKod->Index] = s;
			dc->Values[ii][VwVidNU->Index] = stzn.kod;
			dc->Values[ii][VwKodNU->Index] = stzn.knu;
			dc->Values[ii][VwVKName->Index] = nuname;
		}

		for (int i = yy.fd_mm; i <= 12; i++) {
			yy.fd_mm = i;
			swb(&yy, &stzn.fd, 2);

			farwl(fstzn, &stzn, sizeof(stzn));
		}

		if (cxCBGK->ItemIndex == 1) {
			dc->Values[ii][VwGK->Index] = "Да";
		}
		else {
			dc->Values[ii][VwGK->Index] = "Нет";
		}

		dc->Values[ii][VwDebet->Index] = debet;
		dc->Values[ii][VwKredit->Index] = kredit;
		swb(&kdkfr, &swkdkfr, sizeof(kdkfr));
		dc->Values[ii][VwKO->Index] = swkdkfr;
		dc->Values[ii][VwJO->Index] = jo;
		dc->Values[ii][VwJOName->Index] = cxBEJO->Text;

		dxLCNew->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		dxLayoutControl1Item2->Enabled = true;
		dxLayoutControl1Item6->Enabled = true;
		dxLayoutControl1Item5->Enabled = true;

		aNew->Enabled = true;
		aDel->Enabled = true;
		aKor->Enabled = true;
		aExit->Enabled = true;
		aKor->Enabled = true;
		aNewCopy->Enabled = true;
		aPrnStr->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr->SetFocus();
		dc->FocusedRecordIndex = ii;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	uchar tmpkod; // Код накоплений и удержаний
	uchar tmpknu; // вид накоплений и удержаний
	int ii, kk, i;
	fdate yy;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {

				tmpkod = dc->Values[kk][VwVidNU->Index];
				tmpknu = dc->Values[kk][VwKodNU->Index];
				yy = fdnst;
				for (i = yy.fd_mm; i <= 12; i++) {
					CLR(stzn);
					stzn.kod = tmpkod;
					stzn.knu = tmpknu;
					stzn.fin = tfin;
					stzn.kdtp = ttp;
					yy.fd_mm = i;
					swb(&yy, &stzn.fd, 2);
					if (farel(fstzn, &stzn, sizeof(stzn)) == 0) {
						fard(fstzn, &stzn);
						if ((unsigned)i == fdnst.fd_mm) {
							dc->DeleteFocused();

							if (dc->RecordCount == 0) {
								cxGr->RootLevelOptions->DetailFrameWidth = 2;
							}
						}
					}

				}

			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	char ss[100];
	fdate fdt;
	ushort nr;

	ushort qq;
	char s[10];

	fdt = fdnst;
	fdt.fd_dd = 1;
	fdt.fd_mm = 1;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			prNew = 0;

			dxLCNew->Visible = true;
			cxBENU->Enabled = false;

			cxBEKO->SetFocus(); //
			dxLayoutControl1Item2->Enabled = false;
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item6->Enabled = false;
			dxLayoutControl1Item5->Enabled = false;

			dxLayoutControl1Item7->Enabled = false;
			dxLayoutControl1Item7->Visible = false;

			aNew->Enabled = false;
			aDel->Enabled = false;
			aKor->Enabled = false;
			// cxOk->Enabled = false;
			aNewCopy->Enabled = false;
			aExit->Enabled = false;
			aExit->ShortCut = 0;
			aPrnStr->Enabled = false;
			// f = false;

			kk = dc->FocusedRecordIndex;
			//
			kod = dc->Values[kk][VwVidNU->Index]; // н/у
			knu = dc->Values[kk][VwKodNU->Index];

			if (dc->Values[kk][VwGK->Index] == "Да") { // ГК
				cxCBGK->ItemIndex = 1;
			}
			else {
				cxCBGK->ItemIndex = 0;
			}

			jo = dc->Values[kk][VwJO->Index]; // жо6
			cxBEJO->Text = dc->Values[kk][VwJOName->Index];
			// ko
			// +++++++Чистим старые значения+++++++++++++
			cxLIFName->Caption = "";
			cxLIFNum->Caption = "";
			cxLKName->Caption = "";
			cxLKNum->Caption = "";
			cxLMerName->Caption = "";
			cxLMerNum->Caption = "";
			cxLSubName->Caption = "";
			cxLSubNum->Caption = "";
			cxLTipfName->Caption = "";
			cxLTipfNum->Caption = "";
			cxLTipsName->Caption = "";
			cxLTipsNum->Caption = "";

			dxLayoutControl1Item13->CaptionOptions->Text = "Дебет";
			dxLayoutControl1Item12->CaptionOptions->Text = "Кредит";
			CLR(debet);
			CLR(kredit);
			cxBEKO->Text = "";
			// +++++++++++++++++++++++++++++++++++++++++++

			qq = dc->Values[kk][VwKO->Index];
			swb(&qq, &kdkfr, 2);
			CLR(kfr);
			swb(&fdt, &kfr.fdg, 2);
			kfr.kdkfr = kdkfr;

			if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

				cxBEKO->Text = qq;

				cxLKNum->Caption = OEMtoWS(kfr.ker, sizeof(kfr.ker));

				CLR(ker);
				mov(kfr.ker, ker.ker, sizeof(ker.ker));
				fare(fker, &ker);
				cxLKName->Caption = OEMtoWS(ker.name, sizeof(ker.name));

				cxLIFNum->Caption = OEMtoWS(kfr.isf, sizeof(kfr.isf));
				CLR(isf);
				mov(kfr.isf, isf.isf, sizeof(isf.isf));
				fare(fisf, &isf);
				cxLIFName->Caption = OEMtoWS(isf.name, sizeof(isf.name));

				cxLSubNum->Caption = OEMtoWS(kfr.sbker, sizeof(kfr.sbker));
				CLR(sbker);
				mov(kfr.sbker, sbker.subkesr, sizeof(sbker.subkesr));
				fare(fsbker, &sbker);
				cxLSubName->Caption = OEMtoWS(sbker.name, sizeof(sbker.name));

				cxLTipfNum->Caption = OEMtoWS(kfr.tf, sizeof(kfr.tf));
				CLR(tf);
				mov(kfr.tf, tf.tf, sizeof(tf.tf));
				fare(ftf, &tf);
				cxLTipfName->Caption = OEMtoWS(tf.name, sizeof(tf.name));

				cxLTipsNum->Caption = OEMtoWS(kfr.ts, sizeof(kfr.ts));
				CLR(ts);
				mov(kfr.ts, ts.ts, sizeof(ts.ts));
				fare(fts, &ts);
				cxLTipsName->Caption = OEMtoWS(ts.name, sizeof(ts.name));

				cxLMerNum->Caption = OEMtoWS(kfr.mrp, sizeof(kfr.mrp));
				CLR(mrp);
				mov(kfr.mrp, mrp.mrp, sizeof(mrp.mrp));
				fare(fmrp, &mrp);
				cxLMerName->Caption = OEMtoWS(mrp.name, sizeof(mrp.name));

				CLR(op);
				op.kd = kfr.kd;
				op.ko = kfr.ko;
				op.ks = kfr.ks;
				if (farel(fop, &op, sizeof(op)) == 0) {

					// дебет и кредит
					CLR(bsn);
					mov(&op.srd, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(debet, "%s", s);

					CLR(ss);
					sprintf(ss, "Дебет: %s", s);
					dxLayoutControl1Item13->CaptionOptions->Text = ss;

					// кредит
					mov(&op.srk, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(kredit, "%s", s);

					CLR(ss);
					sprintf(ss, "Кредит: %s", s);
					dxLayoutControl1Item12->CaptionOptions->Text = ss;
				}

			}

			////////////
			cxBENU->Text = dc->Values[kk][VwVidKod->Index];
			cxBENU->Text = cxBENU->Text + " ";
			cxBENU->Text = cxBENU->Text + dc->Values[kk][VwVKName->Index];
			cxBENU->Enabled = false;

		}
		else {
			armerr(2, "Выберете запись!");
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::cxKopSPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	struct zpsppar par;
	CLR(par);
	char ss[100];
	fdate fdt;
	ushort nr;

	ushort qq;
	char s[10];

	fdt = fdnst;
	fdt.fd_dd = 1;
	fdt.fd_mm = 1;

  if (l_call("ZPSPR1", "GKNUSN", &par) == 1) {
		cxKopS->SetFocus();
		CLR(ss);
		sprintf(ss, "%2.2u.%2.2u %s", par.par1, par.par2, par.nm);
		cxKopS->Text = AS(ss);

		CLR(stzn);
		stzn.kod = (uchar)par.par1;
		stzn.knu = (uchar) par.par2;
		swb(&fdnst, &stzn.fd, 2);
		stzn.fin = tfin;
		stzn.kdtp = ttp;

		// --------------------
		jo = 0;
		kdkfr = 0;
		CLR(debet);
		CLR(kredit);
		cxBEJO->Text = "";
		cxBEKO->Text = "";
		cxCBGK->ItemIndex = 0;

		cxLIFName->Caption = "";
		cxLIFNum->Caption = "";
		cxLKName->Caption = "";
		cxLKNum->Caption = "";
		cxLMerName->Caption = "";
		cxLMerNum->Caption = "";
		cxLSubName->Caption = "";
		cxLSubNum->Caption = "";
		cxLTipfName->Caption = "";
		cxLTipfNum->Caption = "";
		cxLTipsName->Caption = "";
		cxLTipsNum->Caption = "";
		dxLayoutControl1Item13->CaptionOptions->Text = "Дебет";
		dxLayoutControl1Item12->CaptionOptions->Text = "Кредит";

		// -----------------------

		if (farel(fstzn, &stzn, sizeof(stzn)) == 0) {
			CLR(kmo5); // ЖО6
			kmo5.npp = stzn.npp;
			if (farel(fkmo5, &kmo5, sizeof(kmo5)) == 0) {
				cxBEJO->Text = OEMtoWS(kmo5.n, sizeof(kmo5.n));
				jo = kmo5.npp;
			}

			// гк
			if (stzn.pgk == 1) { // ГК
				cxCBGK->ItemIndex = 1;
			}
			else {
				cxCBGK->ItemIndex = 0;
			}

			// ko

			kdkfr = stzn.kdkfr;

			CLR(kfr);
			swb(&fdt, &kfr.fdg, 2);
			kfr.kdkfr = kdkfr;
			swb(&kdkfr, &qq, 2);
			if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

				cxBEKO->Text = qq;

				cxLKNum->Caption = OEMtoWS(kfr.ker, sizeof(kfr.ker));

				CLR(ker);
				mov(kfr.ker, ker.ker, sizeof(ker.ker));
				fare(fker, &ker);
				cxLKName->Caption = OEMtoWS(ker.name, sizeof(ker.name));

				cxLIFNum->Caption = OEMtoWS(kfr.isf, sizeof(kfr.isf));
				CLR(isf);
				mov(kfr.isf, isf.isf, sizeof(isf.isf));
				fare(fisf, &isf);
				cxLIFName->Caption = OEMtoWS(isf.name, sizeof(isf.name));

				cxLSubNum->Caption = OEMtoWS(kfr.sbker, sizeof(kfr.sbker));
				CLR(sbker);
				mov(kfr.sbker, sbker.subkesr, sizeof(sbker.subkesr));
				fare(fsbker, &sbker);
				cxLSubName->Caption = OEMtoWS(sbker.name, sizeof(sbker.name));

				cxLTipfNum->Caption = OEMtoWS(kfr.tf, sizeof(kfr.tf));
				CLR(tf);
				mov(kfr.tf, tf.tf, sizeof(tf.tf));
				fare(ftf, &tf);
				cxLTipfName->Caption = OEMtoWS(tf.name, sizeof(tf.name));

				cxLTipsNum->Caption = OEMtoWS(kfr.ts, sizeof(kfr.ts));
				CLR(ts);
				mov(kfr.ts, ts.ts, sizeof(ts.ts));
				fare(fts, &ts);
				cxLTipsName->Caption = OEMtoWS(ts.name, sizeof(ts.name));

				cxLMerNum->Caption = OEMtoWS(kfr.mrp, sizeof(kfr.mrp));
				CLR(mrp);
				mov(kfr.mrp, mrp.mrp, sizeof(mrp.mrp));
				fare(fmrp, &mrp);
				cxLMerName->Caption = OEMtoWS(mrp.name, sizeof(mrp.name));

				CLR(op);
				op.kd = kfr.kd;
				op.ko = kfr.ko;
				op.ks = kfr.ks;
				if (farel(fop, &op, sizeof(op)) == 0) {

					// дебет и кредит
					CLR(bsn);
					mov(&op.srd, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(debet, "%s", s);

					CLR(ss);
					sprintf(ss, "Дебет: %s", s);
					dxLayoutControl1Item13->CaptionOptions->Text = ss;

					// кредит
					mov(&op.srk, &bsn, 6);
					fare(fbsn, &bsn);
					CLR(s);
					SW(bsn.ko, nr);
					if (bsn.is)
						sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
					else
						sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

					sprintf(kredit, "%s", s);

					CLR(ss);
					sprintf(ss, "Кредит: %s", s);
					dxLayoutControl1Item12->CaptionOptions->Text = ss;
				}

			}

		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::aNewCopyExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		if (ttp != 0) {

			prNew = 1;
			dxLCNew->Visible = true;
			cxBENU->Enabled = true;
			cxBENU->SetFocus();
			dxLayoutControl1Item2->Enabled = false;
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item6->Enabled = false;
			dxLayoutControl1Item5->Enabled = false;
			aNewCopy->Enabled = false;
			aNew->Enabled = false;
			aDel->Enabled = false;
			aKor->Enabled = false;
			aExit->Enabled = false;
			aExit->ShortCut = 0;
			aPrnStr->Enabled = false;
			// cxOk->Enabled = false;
			cxBENU->Clear();
			cxBEJO->Clear();
			cxBEKO->Clear();
			cxCBGK->ItemIndex = 0;

			dxLayoutControl1Item7->Enabled = true;
			dxLayoutControl1Item7->Visible = true;
			cxKopS->Text = "";

			///label'ы
			cxLIFName->Caption = "";
			cxLIFNum->Caption = "";
			cxLKName->Caption = "";
			cxLKNum->Caption = "";
			cxLMerName->Caption = "";
			cxLMerNum->Caption = "";
			cxLSubName->Caption = "";
			cxLSubNum->Caption = "";
			cxLTipfName->Caption = "";
			cxLTipfNum->Caption = "";
			cxLTipsName->Caption = "";
			cxLTipsNum->Caption = "";

			dxLayoutControl1Item13->CaptionOptions->Text = "Дебет";
			dxLayoutControl1Item12->CaptionOptions->Text = "Кредит";

			jo = 0;

			knu = 0;
			kod = 0;
			kdkfr = 0;
			CLR(nuname);
			CLR(debet);
			CLR(kredit);
		}
		else {
			armerr(2, "Укажите тип персонала");
		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0014::VwFocusedRecordChanged(TcxCustomGridTableView *Sender, TcxCustomGridRecord *APrevFocusedRecord,
		TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged) {
	TcxGridDataController* dc = Vw->DataController;
	fdate fdt;
	int kk;
	ushort qq;
	char p[70];
	short l;
	char s[100], ss[10]; // ts[6];
	char ts;

	ulong lo;

	l = sizeof(p);

	fdt = fdnst;
	fdt.fd_dd = 1;
	fdt.fd_mm = 1;

	if (dc->FocusedRecordIndex > -1) {

		kk = dc->FocusedRecordIndex;
		qq = dc->Values[kk][VwKO->Index];

		CLR(kfr);
		swb(&qq, &kfr.kdkfr, 2);
		swb(&fdt, &kfr.fdg, 2);
		CLR(ss);
		if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

			// sprintf(ss,"%s-%s-%s-%s-%s-%s",kfr.ker,kfr.sbker,kfr.isf,kfr.tf,kfr.ts,kfr.mrp);
			CLR(s);
			clr(p, l);
			CLR(ss);
			mov(&kfr.ker, &ss, 3);
			if (ss[0] == 0)
				strcat(s, "000");
			strcat(s, ss);
			strcat(s, "-");

			CLR(ss);
			mov(&kfr.sbker, &ss, 7);
			if (ss[0] == 0)
				strcat(s, "0000000");
			strcat(s, ss);
			strcat(s, "-");

			CLR(ss);
			mov(&kfr.isf, &ss, 3);
			if (ss[0] == 0)
				strcat(s, "000");
			strcat(s, ss);
			strcat(s, "-");

			CLR(ss);
			mov(&kfr.tf, &ss, 3);
			if (ss[0] == 0)
				strcat(s, "000");
			strcat(s, ss);
			strcat(s, "-");

			CLR(ss);
			CLR(ts);
			mov(&kfr.ts, &ts, 6);
			sld(&ts, &lo, 0);
			if (lo)
				l_call_bud("put_ts", " ", &lo, ss, sizeof(ss));
			else
				strcat(s, "0");
			strcat(s, ss);
			strcat(s, "-");

			CLR(ss);
			mov(&kfr.mrp, &ss, 7);
			strcat(s, ss);
		}
		else
			CLR(s);
	}
	mov(s, p, l);

	cxTextEdit1->Text = p;

}
//
int mopenf(char *mpath, char *AFileName, char *AFileExt, char *pref, char *spath);

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0014::aPrnStrExecute(TObject *Sender) {
	// Выгрузка в Excel
	char sdir[256];

	char FileName[256], FileExt[10], fFileName[256], pref[20];
	AnsiString AFileName, NFileName, AFileExt;

	bool AExpand;
	bool AUseNativeFormat;

	CLR(sdir);
	getcwd(sdir, 256);
	strcat(sdir, "\\");

	CLR(FileName);
	strcat(FileName, "Бухгалтерские проводки Дебет-Кредит");
	CLR(FileExt);
	strcat(FileExt, "xls");
	CLR(fFileName);
	CLR(pref);

	AExpand = true;
	AUseNativeFormat = false;
	if (mopenf(sdir, FileName, FileExt, pref, fFileName) == 0) {
		AFileExt = FileExt;
		AFileName = fFileName;
		NFileName = AFileName.SubString(1, AFileName.Pos(AFileExt) - 2);
		try {
			if (!IsOLEObjectInstalled("Excel.Application")) {
				armerr(1, "Загрузить Microsoft Excel не удалось");
				return;
			}
			ExportGridToExcel(NFileName, cxGr, AExpand, true, AUseNativeFormat, AFileExt);

			ShellExecuteA(0, NULL, fFileName, NULL, NULL, SW_SHOWNORMAL);
		}
		catch (...) {
			armerr(1, "Ошибка !!!");
		}
	}

}
// ---------------------------------------------------------------------------
