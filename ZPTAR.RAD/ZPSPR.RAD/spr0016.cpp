// ---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"
#include "l_call_bud.h"

extern struct compar *c_p;

#include "spr0016.h"
#include "spr0010.h"
#include "spr0017.h"
#include "spr0018.h"
#include "spr0055.h"
#include "progress.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
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
Tfrspr0016 *frspr0016;

// ---------------------------------------------------------------------------
__fastcall Tfrspr0016::Tfrspr0016(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
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

int IniSpr0016(struct zppstzn *par, struct zpsppard *pard) {
	int ret = -1;
	frspr0016 = new Tfrspr0016(Application);
	CoInitialize(NULL);
	try {

		frspr0016->cxBEFin->Text = "Основной источник финансирования";

		frspr0016->tfin = 0;
		frspr0016->ttp = 0;

		frspr0016->b = (struct bsp*)c_p->b_sp;
		frspr0016->fdnst.fd_dd = 1;
		frspr0016->fdnst.fd_mm = frspr0016->b->uyy.mm;
		frspr0016->fdnst.fd_yy = frspr0016->b->uyy.yy;

		frspr0016->cxDE->Date = EncodeDate(frspr0016->fdnst.fd_yy + 1980, frspr0016->fdnst.fd_mm, frspr0016->fdnst.fd_dd);

		frspr0016->dxLCNew->Visible = false;
		frspr0016->ret = &ret;
		frspr0016->par = par;


		frspr0016->fcnst = fafo(c_p->b_zp, "const");
		frspr0016->prKor = true;
		CLR(frspr0016->cnst);
		strcpy(frspr0016->cnst.n, "KLIENT");
		if (fare(frspr0016->fcnst, &frspr0016->cnst) == 0) {
			if (strcmp(frspr0016->cnst.ct, "1") == 0) {
				frspr0016->prKor = false;
			}
		}
		fafc(frspr0016->fcnst);
		if (frspr0016->prKor == true) {
			if (frspr0016->b->sts[6] == '8') {
				frspr0016->prKor = true; // корректировка разрешена
			}
			else {
				frspr0016->prKor = false; // корректировка запрещена
			}
		}

		if (frspr0016->prKor ==true) {
			frspr0016->aNew->Enabled = true;
			frspr0016->aKor->Enabled = true;
			frspr0016->aDel->Enabled = true;
			frspr0016->aNewCopy->Enabled = true;

			frspr0016->aNew->Visible = true;
			frspr0016->aKor->Visible = true;
			frspr0016->aDel->Visible = true;
			frspr0016->aNewCopy->Visible = true;

			frspr0016->aPrnStr->Enabled = true;
			frspr0016->aPrnStr->Visible = true;
			frspr0016->aPrnStr->Caption = "Выгрузка в Excel";
			frspr0016->aPrnStr->Hint = "Выгрузка в Excel";

		}

		if (pard == NULL) {
			frspr0016->aOk->Enabled = false;
			frspr0016->aOk->Visible = false;
			frspr0016->aOk->ShortCut = 0;
		}
		else {
			frspr0016->aOk->Enabled = true;
			frspr0016->aOk->Visible = true;
		}

		frspr0016->fknus = fafonc(c_p->b_nc, "zpknus"); // н/у
		frspr0016->ffin = fafonc(c_p->b_nc, "zpfin"); // и.ф.
		frspr0016->ftp = fafonc(c_p->b_nc, "zptp"); // тип пер
		frspr0016->fstzn = fafonc(c_p->b_nc, "zppstzn"); //
		frspr0016->fkmo5 = fafonc(c_p->b_nc, "zpkmo5"); // строки в мо 5
		frspr0016->fkfr = fafonc(c_p->b_nc, "zpkfr"); // ко
		frspr0016->fop = fafonc(c_p->b_nc, "spop"); // справочник операций
		frspr0016->fbsn = fafonc(c_p->b_nc, "spbsn");
		frspr0016->fker = fafonc(c_p->b_nc, "spker");
		frspr0016->fisf = fafonc(c_p->b_nc, "spisf");
		frspr0016->fsbker = fafonc(c_p->b_nc, "spsbker");
		frspr0016->ftf = fafonc(c_p->b_nc, "sptf");
		frspr0016->fts = fafonc(c_p->b_nc, "spts");
		frspr0016->fmrp = fafonc(c_p->b_nc, "spmrp");

		if (frspr0016->fstzn == 0) {
			armerr(1, "Нет структуры");
			/// дописать
		}
		else {
			frspr0016->aRefresh->Execute();
			frspr0016->ShowModal();
			fafc(frspr0016->fstzn);
		}
	}
	catch (...) {
	}
	delete frspr0016;
	CoUninitialize();
	return ret;

}

void __fastcall Tfrspr0016::cxBEFinPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
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
		//if (l_call("ZPSPR", "GFIN", &par, &bzp) == 1)	{
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
void __fastcall Tfrspr0016::cxBEPerPropertiesButtonClick(TObject *Sender, int AButtonIndex)

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
void __fastcall Tfrspr0016::cxDEEnter(TObject *Sender) {

	mov(&fdnst, &fduu, 2);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::cxDEExit(TObject *Sender) {
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
void __fastcall Tfrspr0016::aRefreshExecute(TObject *Sender) { // доделать
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
		while (fargl(fstzn, &stzn, sizeof(stzn)) == 0 && cmp(&fdt1, &stzn.fd,
				2) == 0 && stzn.fin == tfin && stzn.kdtp == ttp) {

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
void __fastcall Tfrspr0016::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		if (ttp != 0) {

			prNew = 1;
			dxLCNew->Visible = true;
			cxBENU->Enabled = true;
			cxBENU->SetFocus();
			dxLayoutControl1Item2->Enabled = false;
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item35->Enabled = false;
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

			cxLbSUBS->Caption = "";
			cxLbCELS->Caption = "";

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

void __fastcall Tfrspr0016::cxBCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item35->Enabled = true;
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

void __fastcall Tfrspr0016::cxBENUPropertiesButtonClick(TObject *Sender, int AButtonIndex)

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

void __fastcall Tfrspr0016::FormShow(TObject *Sender) {
	cxBEFin->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::cxGrEnter(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::cxGrExit(TObject *Sender) {
	cxGr->RootLevelOptions->DetailFrameWidth = 0;
}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::cxBEKOPropertiesButtonClick(TObject *Sender, int AButtonIndex)

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

		cxLbSUBS->Caption = "";
		cxLbCELS->Caption = "";

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
			// if (l_call("ZPSPRSW", "GIKFR", 1, &sppar, &fdt) == 1) {
			swb(&sppar.par1, &kdkfr, 2);
			/////

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

				/* ***************** */
				cxLbSUBS->Caption = OEMtoWS(kfr.subs, sizeof(kfr.subs));
				cxLbCELS->Caption = OEMtoWS(kfr.cels, sizeof(kfr.cels));
				/* ********* */
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
void __fastcall Tfrspr0016::cxCBGKExit(TObject *Sender) {
	if (cxBEKO->Text == "") {
		cxCBGK->ItemIndex = 0;
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfrspr0016::cxBEJOPropertiesButtonClick(TObject *Sender, int AButtonIndex)

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

void __fastcall Tfrspr0016::cxBOkClick(TObject *Sender) {
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
		dxLayoutControl1Item35->Enabled = true;
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
		if (prNew != 1) {
			PrRefresh();

		}

	}

}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::aDelExecute(TObject *Sender) {
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

void __fastcall Tfrspr0016::aKorExecute(TObject *Sender) {
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
			dxLayoutControl1Item35->Enabled = false;
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
			cxLbSUBS->Caption = "";
			cxLbCELS->Caption = "";

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

				/* ***************** */
				cxLbSUBS->Caption = OEMtoWS(kfr.subs, sizeof(kfr.subs));
				cxLbCELS->Caption = OEMtoWS(kfr.cels, sizeof(kfr.cels));
				/* ********* */

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
void __fastcall Tfrspr0016::cxKopSPropertiesButtonClick(TObject *Sender, int AButtonIndex)

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
		cxLbSUBS->Caption = "";
		cxLbCELS->Caption = "";
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

				/* ***************** */
				cxLbSUBS->Caption = OEMtoWS(kfr.subs, sizeof(kfr.subs));
				cxLbCELS->Caption = OEMtoWS(kfr.cels, sizeof(kfr.cels));
				/* ********* */

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

void __fastcall Tfrspr0016::aNewCopyExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		if (ttp != 0) {

			prNew = 1;
			dxLCNew->Visible = true;
			cxBENU->Enabled = true;
			cxBENU->SetFocus();
			dxLayoutControl1Item2->Enabled = false;
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item35->Enabled = false;
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
			cxLbSUBS->Caption = "";
			cxLbCELS->Caption = "";

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

void __fastcall Tfrspr0016::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void Tfrspr0016::PrRefresh() {
	TcxGridDataController* dc = Vw->DataController;
	TcxGridDataController* dc2 = Vw2->DataController;
	fdate fdt;
	int kk, pp;
	ushort qq, nr;
	char p[70];
	short l;
	char s[100], ss[10]; // ts[6];
	char ts;

	ulong lo;

	l = sizeof(p);

	fdt = fdnst;
	fdt.fd_dd = 1;
	fdt.fd_mm = 1;

	if (dc2->RecordCount != 0) { // очистка дебет/кредит
		Vw2->OptionsSelection->MultiSelect = true;
		dc2->SelectAll();
		dc2->DeleteSelection();
		Vw2->OptionsSelection->MultiSelect = false;
	}
	if (dc->FocusedRecordIndex > -1) {

		kk = dc->FocusedRecordIndex;
		qq = dc->Values[kk][VwKO->Index];

		CLR(kfr);
		swb(&qq, &kfr.kdkfr, 2);
		swb(&fdt, &kfr.fdg, 2);
		CLR(ss);
		if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

			// ---заполнение грида дебет/кредит--------------------------

			CLR(op);
			op.kd = kfr.kd;
			// op.ko = kfr.ko;
			while (fargl(fop, &op, sizeof(op)) == 0 && op.kd == kfr.kd) {
				if (op.ko == kfr.ko) {
					dc2->BeginFullUpdate();
					pp = dc2->AppendRecord();
					// дебет и кредит
					CLR(bsn);
					mov(&op.srd, &bsn, 6);
					if (fare(fbsn, &bsn) == 0) {
						CLR(s);
						SW(bsn.ko, nr);
						if (bsn.is)
							sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
						else
							sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);
						dc2->Values[pp][VwDeb->Index] = s;
					}
					// кредит
					CLR(bsn);
					mov(&op.srk, &bsn, 6);
					if (fare(fbsn, &bsn) == 0) {
						CLR(s);
						SW(bsn.ko, nr);
						if (bsn.is)
							sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
						else
							sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);
						dc2->Values[pp][VwKred->Index] = s;
					}
					dc2->EndFullUpdate();
				}
			}
			if (dc2->RecordCount != 0) {
				dc2->GotoFirst();
			}

			// ----------------------------------

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
			/* ********* */
			strcat(s, "-");
			AnsiString subs = "";
			CLR(ss);
			mov(&kfr.subs, &ss, 9);
			subs = ss;
			if (subs != "") {
				subs.Insert(".", 4);
				subs.Insert(".", 7);
			}
			else
				subs = "XXX.XX.XXXX";

			strcat(s, subs.c_str());
			strcat(s, "-");

			CLR(ss);
			mov(&kfr.cels, &ss, 9);
			subs = ss;
			if (subs != "") {
				subs.Insert(".", 2);
				subs.Insert(".", 5);
				subs.Insert(".", 9);
			}
			else
				subs = "X.XX.XXX.XXX";

			strcat(s, subs.c_str());

			/* ********* */
		}
		else
			CLR(s);
	}

	mov(s, p, l);

	cxTextEdit1->Text = p;

}

void __fastcall Tfrspr0016::VwFocusedRecordChanged(TcxCustomGridTableView *Sender,
		TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged) {
	PrRefresh();
}
//
int mopenf(char *mpath, char *AFileName, char *AFileExt, char *pref, char *spath);

// ---------------------------------------------------------------------------
void __fastcall Tfrspr0016::aPrnStrExecute(TObject *Sender) {
	// Выгрузка в Excel

	Variant Docxls, Bookxls, Sheetxls, Cellxls;
	String SGCellValue, range;
	int i, j;
	char sdir[256];
	char FileName[256], FileExt[10], fFileName[256], pref[20];
	int hfile;
	fdate fdt;
	int kk;
	ushort qq, nr;
	char p[70];
	short l;
	char s[100], ss[10]; // ts[6];
	char ts;
	ulong lo;

	l = sizeof(p);

	TcxGridDataController* dc = Vw->DataController;
	try {

		if (!IsOLEObjectInstalled("Excel.Application")) {
			armerr(1, "Загрузить Microsoft Excel не удалось");
			return;
		}

		Docxls = CreateOleObject("Excel.Application");
		Docxls.OlePropertySet("Visible", false);

		CLR(sdir);
		getcwd(sdir, 256);
		strcat(sdir, "\\");

		CLR(FileName);
		strcat(FileName, "Бухгалтерские проводки Дебет-Кредит");
		CLR(FileExt);
		strcat(FileExt, "xls");
		CLR(fFileName);
		CLR(pref);

		if (mopenf(sdir, FileName, FileExt, pref, fFileName) == 0) {
			hfile = FileCreate(fFileName);
			FileClose(hfile);
			Bookxls = Docxls.OlePropertyGet("Workbooks").OlePropertyGet("Open", fFileName);
			Sheetxls = Bookxls.OlePropertyGet("Worksheets", 1);

			Cellxls = Sheetxls.OlePropertyGet("Range", "A1:I1");
			Cellxls.OleProcedure("Merge");
			Cellxls.OlePropertySet("HorizontalAlignment", 3);
			Cellxls.OlePropertyGet("Interior").OlePropertySet("ColorIndex", 4);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Size", 12);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Bold", true);

			Cellxls.OlePropertySet("Value", WideString("Бухгалтерские проводки Дебет/Кредит " + cxDE->Date));

			Cellxls = Sheetxls.OlePropertyGet("Range", "A2:I2");
			Cellxls.OleProcedure("Merge");
			Cellxls.OlePropertySet("HorizontalAlignment", 1);
			Cellxls.OlePropertyGet("Interior").OlePropertySet("ColorIndex", 0);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Size", 12);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Bold", true);

			Cellxls.OlePropertySet("Value", WideString("Источник финансирования: " + cxBEFin->Text));

			Cellxls = Sheetxls.OlePropertyGet("Range", "A3:I3");
			Cellxls.OleProcedure("Merge");
			Cellxls.OlePropertySet("HorizontalAlignment", 1);
			Cellxls.OlePropertyGet("Interior").OlePropertySet("ColorIndex", 0);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Size", 12);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Bold", true);

			Cellxls.OlePropertySet("Value", WideString("Тип персонала: " + cxBEPer->Text));

			Cellxls = Sheetxls.OlePropertyGet("Range", "A5:I5");
			Cellxls.OlePropertySet("HorizontalAlignment", 3);
			Cellxls.OlePropertyGet("Interior").OlePropertySet("ColorIndex", 3);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Size", 10);
			Cellxls.OlePropertyGet("Font").OlePropertySet("Bold", true);

			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 1);
			Cellxls.OlePropertySet("ColumnWidth", VwVidKod->Width / 7);
			Cellxls.OlePropertySet("Value", WideString("Вид-Код Н/У"));
			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 2);
			Cellxls.OlePropertySet("ColumnWidth", VwVKName->Width / 7);
			Cellxls.OlePropertySet("Value", WideString("Наименование Н/У"));
			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 3);
			Cellxls.OlePropertySet("Value", WideString("ГК"));
			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 4);
			Cellxls.OlePropertySet("Value", WideString("КО"));
			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 5);
			Cellxls.OlePropertySet("Value", WideString("ЖО6"));
			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 6);
			Cellxls.OlePropertySet("ColumnWidth", VwJOName->Width / 7);
			Cellxls.OlePropertySet("Value", WideString("Наименование ЖО6"));

			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 7);
			Cellxls.OlePropertySet("ColumnWidth", 35);
			Cellxls.OlePropertySet("Value", WideString("КФКР"));

			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 8);
			Cellxls.OlePropertySet("ColumnWidth", 15);
			Cellxls.OlePropertySet("Value", WideString("Дебет"));

			Cellxls = Sheetxls.OlePropertyGet("Cells", 5, 9);
			Cellxls.OlePropertySet("ColumnWidth", 15);
			Cellxls.OlePropertySet("Value", WideString("Кредит"));

			frProgress = new TfrProgress(Application);
			frProgress->cxProgressBar1->Position = 0;
			frProgress->cxProgressBar1->Properties->Max = dc->RecordCount;
			frProgress->Show();
			frspr0016->Enabled = false;

			int sdvig = 0;
			for (i = 0; i < dc->RecordCount; i++) {
				frProgress->cxProgressBar1->Position++;
				// установить формат ячеек  для н/у
				range = "A" + IntToStr(i + 6 + sdvig) + ":A" + IntToStr(i + 6 + sdvig);
				Sheetxls.OlePropertyGet("Range", WideString(range)).OlePropertySet("HorizontalAlignment", -4152);

				Sheetxls.OlePropertyGet("Range", WideString(range)).OlePropertySet("NumberFormat", "@");
				//

				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 1);
				SGCellValue = dc->Values[i][VwVidKod->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));
				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 2);
				SGCellValue = dc->Values[i][VwVKName->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));
				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 3);
				SGCellValue = dc->Values[i][VwGK->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));
				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 4);
				SGCellValue = dc->Values[i][VwKO->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));
				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 5);
				SGCellValue = dc->Values[i][VwJO->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));
				Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 6);
				SGCellValue = dc->Values[i][VwJOName->Index];
				Cellxls.OlePropertySet("Value", WideString(SGCellValue));

				///----------------------Дебет/кредит, KFKR--------------------
				fdt = fdnst;
				fdt.fd_dd = 1;
				fdt.fd_mm = 1;

				kk = i;

				qq = dc->Values[kk][VwKO->Index];

				CLR(kfr);
				swb(&qq, &kfr.kdkfr, 2);
				swb(&fdt, &kfr.fdg, 2);

				if (farel(fkfr, &kfr, sizeof(kfr)) == 0) {

					/////////////////////  KFKR
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

					mov(s, p, l);
					Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 7);
					Cellxls.OlePropertySet("Value", WideString(p));

					////////////////

					CLR(op);
					op.kd = kfr.kd;
					while (fargl(fop, &op, sizeof(op)) == 0 && op.kd == kfr.kd)
						if (op.ko == kfr.ko) {
							// дебет
							CLR(bsn);
							mov(&op.srd, &bsn, 6);
							fare(fbsn, &bsn);
							CLR(s);
							SW(bsn.ko, nr);
							if (bsn.is)
								sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
							else
								sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

							Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 8);
							Cellxls.OlePropertySet("Value", WideString(s));

							// кредит
							mov(&op.srk, &bsn, 6);
							fare(fbsn, &bsn);
							CLR(s);
							SW(bsn.ko, nr);
							if (bsn.is)
								sprintf(s, "%d%2.2d%2.2d%3.3d%2.2d", bsn.sr, bsn.ss, bsn.as, nr, bsn.is);
							else
								sprintf(s, "%d%2.2d%2.2d%3.3d", bsn.sr, bsn.ss, bsn.as, nr);

							Cellxls = Sheetxls.OlePropertyGet("Cells", i + 6 + sdvig, 9);
							Cellxls.OlePropertySet("Value", WideString(s));

							sdvig++;
						}
					sdvig--;
				}

			}

			range = "A5:I" + IntToStr(i + 5 + sdvig);
			for (int q = 1; q <= 4; q++)
				Sheetxls.OlePropertyGet("Range", WideString(range)).OlePropertyGet("Borders").OlePropertyGet("Item", q)
						.OlePropertySet("LineStyle", 1);

			Sheetxls.OlePropertyGet("Range", WideString(range)).OlePropertySet("WrapText", true);

			delete frProgress;
			frspr0016->Enabled = true;
			Docxls.OlePropertySet("Visible", 1);
		}

	}

	catch (...) {
		armerr(1, "Загрузить Microsoft Excel не удалось");
	}

}
// ---------------------------------------------------------------------------

void __fastcall Tfrspr0016::Vw2CustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
