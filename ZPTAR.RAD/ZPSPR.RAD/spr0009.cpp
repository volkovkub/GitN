// ---------------------------------------------------------------------------
//BG 04/06/02018 - замена zpvvch1 на zpvvch2
// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "spr0009.h"
#include "spr0008.h"
#include "frVi4et.h"
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
#pragma link "cxGridCustomPopupMenu"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridPopupMenu"
#pragma link "cxGridTableView"
#pragma link "cxImageList"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxNavigator"
#pragma link "cxPropertiesStore"
#pragma link "cxSpinEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxBar"
#pragma link "dxBarBuiltInMenu"
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
TfrSpr0009 *frSpr0009;

// ---------------------------------------------------------------------------
__fastcall TfrSpr0009::TfrSpr0009(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0009(struct zpknu2 *par, struct zpsppard *pard) {
	int ret = -1;
	try {
	frSpr0009 = new TfrSpr0009(Application);
		if (frSpr0009->StringGrid1 != NULL)
			delete frSpr0009->StringGrid1;
		frSpr0009->StringGrid1 = new TStringGrid(frSpr0009);

		writebspzp(&frSpr0009->bzp);
		frSpr0009->fdnst.fd_dd = 1;
		frSpr0009->fdnst.fd_mm = 1;
		frSpr0009->fdnst.fd_yy = frSpr0009->bzp.uyy.yy;

		frSpr0009->fd11 = frSpr0009->fdnst;

		frSpr0009->cxDE->Date = EncodeDate(frSpr0009->fdnst.fd_yy + 1980, frSpr0009->fdnst.fd_mm, frSpr0009->fdnst.fd_dd);

		frSpr0009->dxLCNew->Visible = false;
		frSpr0009->ret = &ret;
		frSpr0009->par = par;
		// frSpr0009->cxTE_N->Properties->MaxLength=sizeof(frSpr0008->vdoh.n)-1;
		frSpr0009->aNew->Enabled = true;
		frSpr0009->aKor->Enabled = true;
		frSpr0009->aDel->Enabled = true;
		frSpr0009->aNewCopy->Enabled = true;

		frSpr0009->aNew->Visible = true;
		frSpr0009->aKor->Visible = true;
		frSpr0009->aDel->Visible = true;
		frSpr0009->aNewCopy->Visible = true;

		// frSpr0008->tbank = ((struct zpsppar*)frSpr0008->par)->par1;
		if (pard == NULL) {
			frSpr0009->aOk->Enabled = false;
			frSpr0009->aOk->Visible = false;
			frSpr0009->aOk->ShortCut = 0;
		}
		else {
			frSpr0009->aOk->Enabled = true;
			frSpr0009->aOk->Visible = true;
		}
		frSpr0009->fknu2 = fafo(c_p->b_nc, "zpknu2");
		frSpr0009->fvdoh = fafo(c_p->b_nc, "zpvdoh1");
		frSpr0009->fknus = fafo(c_p->b_nc, "zpknus");
		frSpr0009->fvsr = fafo(c_p->b_nc, "zpvsr");
		frSpr0009->fvvch = fafo(c_p->b_nc, "zpvvch2");
		frSpr0009->fnalvch = fafo(c_p->b_nc, "zpnalvch");

		if (frSpr0009->fknu2 == 0) {
			armerr(1, "Нет структуры соответствия кодов ZP и РФ!");
		}
		else if (frSpr0009->fnalvch == 0) {
			armerr(1, "Нет структуры zpnalvch!");
		}
		else {
			frSpr0009->aRefresh->Execute();
			frSpr0009->ShowModal();
			fafc(frSpr0009->fknu2);
		}
	}
	catch (...) {
	}
	delete frSpr0009;
	return ret;
}

// ------------------------------------
void __fastcall TfrSpr0009::cxDEEnter(TObject *Sender) {
	mov(&fdnst, &fduu, 2);
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0009::cxDEExit(TObject *Sender) {
	unsigned short dd, mm, yy;
	if (!cxDE->EditValue.IsNull()) {
		cxDE->Date.DecodeDate(&yy, &mm, &dd);
		fdnst.fd_dd = 1;
		fdnst.fd_mm = 1;
		fdnst.fd_yy = yy - 1980;
		// cxDE->Date.
		fd11 = fdnst;

		cxDE->Date = EncodeDate(fdnst.fd_yy + 1980, fdnst.fd_mm, fdnst.fd_dd);

		mov(&fdnst, &yy1, 2);
		if (cmpdt((struct fdt*)&fdnst, (struct fdt*)&fduu, 2) != 0) {
			aRefresh->Execute();
		}

	}
	else {
		cxDE->SetFocus();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0009::aRefreshExecute(TObject *Sender) {
	ushort d1, m1, y1;
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ulong kod;
	char s[10];
	struct fdate fdt, fdt1;
	ushort kodv;
	// TListItem *item;

	/* ********ВЫЧЕТЫ************ */
	// ListView1->Clear();
	int i = 0;
	StringGrid1->RowCount = 0;
	CLR(vsr);
	swb(&fd11, &vsr.fd, 2);
	swb(&fd11, &fdt1, 2);
	while (fargl(fvsr, &vsr, sizeof(vsr)) == 0 && cmp(&fdt1, &vsr.fd, 2) == 0) {
		i++;
		StringGrid1->RowCount++;
		// item=ListView1->Items->Add();
		StringGrid1->Cells[0][i] = 1;
		// item->Caption="1";
		int a = vsr.kod;
		StringGrid1->Cells[1][i] = a;
		StringGrid1->Cells[2][i] = vsr.kodrf;
		StringGrid1->Cells[3][i] = OEMtoWS(vsr.n, sizeof(vsr.n));

		// item->SubItems->Add(a);
		// item->SubItems->Add(vsr.kodrf);
		// item->SubItems->Add(OEMtoWS(vsr.n, sizeof(vsr.n)));

	}

	CLR(vvch);
	swb(&fd11, &vvch.fd, 2);
	swb(&fd11, &fdt1, 2);
	while (fargl(fvvch, &vvch, sizeof(vvch)) == 0 && cmp(&fdt1, &vvch.fd, 2) == 0) {
		i++;
		StringGrid1->RowCount++;
		StringGrid1->Cells[0][i] = 2;
		int a = vvch.kod;
		StringGrid1->Cells[1][i] = a;
		StringGrid1->Cells[2][i] = vvch.kodrf;
		StringGrid1->Cells[3][i] = vvch.nm;

		// item=ListView1->Items->Add();
		// item->Caption="2";
		// item->SubItems->Add(a);
		// item->SubItems->Add(a);
		// item->SubItems->Add(OEMtoWS(vvch1.n, sizeof(vvch1.n)));

	}
	/* BG 14/03/2016 заменено на zpnalvch
	 i++;
	 StringGrid1->RowCount++;
	 StringGrid1->Cells[0][i] = 3;
	 int a = 311;
	 StringGrid1->Cells[1][i] = a;
	 StringGrid1->Cells[2][i] = a;
	 StringGrid1->Cells[3][i] = "Имущественный вычет";

	 i++;
	 StringGrid1->RowCount++;
	 StringGrid1->Cells[0][i] = 3;
	 a = 312;
	 StringGrid1->Cells[1][i] = a;
	 StringGrid1->Cells[2][i] = a;
	 StringGrid1->Cells[3][i] = "Имущественный вычет";
	 */
	CLR(nalvch);
	while (fargl(fnalvch, &nalvch, sizeof(nalvch)) == 0) {
		i++;
		StringGrid1->RowCount++;
		StringGrid1->Cells[0][i] = 3;
		swb(&nalvch.kod, &kodv, 2);
		StringGrid1->Cells[1][i] = kodv;
		StringGrid1->Cells[2][i] = kodv;
		StringGrid1->Cells[3][i] = OEMtoWS(nalvch.nm, sizeof(nalvch.nm));

		// item=ListView1->Items->Add();
		// item->Caption="2";
		// item->SubItems->Add(a);
		// item->SubItems->Add(a);
		// item->SubItems->Add(OEMtoWS(vvch1.n, sizeof(vvch1.n)));

	}

	/* item=ListView1->Items->Add();
	 item->Caption="3";
	 int a=311;
	 item->SubItems->Add(a);
	 item->SubItems->Add(a);
	 item->SubItems->Add("Имущественный вычет");

	 item=ListView1->Items->Add();
	 item->Caption="3";
	 a=312;
	 item->SubItems->Add(a);
	 item->SubItems->Add(a);
	 item->SubItems->Add("Имущественный вычет");
	 */

	/* ************ВЫЧЕТЫ******** */

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();

	CLR(knu2);
	swb(&fdnst, &knu2.fd, 2);
	swb(&fdnst, &fdt1, 2);
	while (fargl(fknu2, &knu2, sizeof(knu2)) == 0 && cmp(&fdt1, &knu2.fd, 2) == 0) {

		ii = dc->AppendRecord();
		CLR(s);
		sprintf(s, "%2.2d.%2.2d", knu2.kod, knu2.knu);

		dc->Values[ii][VwVidKod->Index] = s;
		dc->Values[ii][VwVidNU->Index] = knu2.kod;
		dc->Values[ii][VwKodNU->Index] = knu2.knu;
		CLR(knus);
		knus.kod = knu2.kod;
		knus.knu = knu2.knu;
		if (farel(fknus, &knus, sizeof(knus)) == 0) {
			dc->Values[ii][VwVKName->Index] = OEMtoWS(knus.n, sizeof(knus.n));
		}

		CLR(vdoh);
		kod = knu2.dho;
		swb(&kod, &vdoh.kod, 4);
		if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
			dc->Values[ii][VwNDoh->Index] = OEMtoWS(vdoh.n, sizeof(vdoh.n));
		}
		else {
			dc->Values[ii][VwNDoh->Index] = "";
		}
		dc->Values[ii][VwKodDoh->Index] = knu2.dho;
		dc->Values[ii][VwKodSk->Index] = knu2.sk;
		CLR(vsr);
		swb(&fd11, &vsr.fd, 2);
		vsr.kod = knu2.sk;

		AnsiString str = knu2.sk;
		dc->Values[ii][VwKodSkRF->Index] = 0;
		for (int i = 1; i <= StringGrid1->RowCount - 1; i++) {
			if (StringGrid1->Cells[1][i] == str) {
				dc->Values[ii][VwKodSkRF->Index] = StringGrid1->Cells[2][i];
			}
		}

		/*
		 if (farel(fvsr, &vsr, sizeof(vsr)) == 0) {
		 dc->Values[ii][VwKodSkRF->Index] = vsr.kodrf;
		 }
		 else {
		 dc->Values[ii][VwKodSkRF->Index] = 0;
		 }
		 */

		dc->Values[ii][VwUDoh->Index] = knu2.muld;
		dc->Values[ii][VwUSk->Index] = knu2.muls;

	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::aNewExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		CLR(knu2);
		prNew = 1;
		dho1 = 0;
		sk1 = 0;
		kodrf = 0;
		dxLCNew->Visible = true;
		cxBENU->Enabled = true;
		cxBENU->SetFocus();
		dxLayoutControl1Item2->Enabled = false;
		dxLayoutControl1Item1->Enabled = false;
		aNewCopy->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;

		// cxOk->Enabled = false;
		cxBENU->Clear();
		cxBEDoh->Clear();
		cxBESk->Clear();
		cxCBDoh->ItemIndex = 0;
		cxCBSk->ItemIndex = 0;
		cxSEKodDoh->Value = dho1;
		cxSEKodV->Value = sk1;

		dxLayoutControl1Item10->Enabled = false;
		dxLayoutControl1Item10->Visible = false;

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBCancelClick(TObject *Sender) {
	dxLCNew->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	aNew->Enabled = true;
	aDel->Enabled = true;
	aKor->Enabled = true;
	aNewCopy->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	cxGr->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBEDohPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	if (AButtonIndex == 1) {
		cxBEDoh->Text = "";
		cxBEDoh->SetFocus();
		dho1 = 0;
		cxCBDoh->ItemIndex = 0;
		cxSEKodDoh->Value = 0;
	}
	else {
		struct zpsppard sppard;
		CLR(vdoh);
		CLR(sppard);
		sppard.gpar = 1;
		if (IniSpr0008(&vdoh, &sppard) == 1) {
			cxBEDoh->SetFocus();
			cxBEDoh->Text = OEMtoWS(vdoh.n, sizeof(vdoh.n)); // наименование
			swb(&vdoh.kod, &dho1, 4);
			cxSEKodDoh->Value = dho1;

		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBENUPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{

	struct zpsppar par;
	char ss[60];

	CLR(par);
	if (l_call("ZPSPR1", "GKNUSN", &par) == 1) {
		cxBENU->SetFocus();

		knu2.kod = (uchar)par.par1;
		knu2.knu = (uchar) par.par2;

		CLR(ss);
		CLR(nuname);
		sprintf(ss, "%2.2u.%2.2u %s", par.par1, par.par2, par.nm);
		cxBENU->Text = AS(ss);
		sprintf(nuname, "%s", par.nm);

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBESkPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{

	if (AButtonIndex == 1) {
		cxBESk->Text = "";
		cxBESk->SetFocus();
		sk1 = 0;
		kodrf = 0;
		cxCBSk->ItemIndex = 0;
		cxSEKodV->Value = sk1;

	}
	else { // PEREDELAT NA NOVIY SPRAVO4NIK
		/* struct zpsppar par1;
		 char ss[60];

		 CLR(par1);

		 if (l_call("ZPSPRSWN", "GVSR", 0, 1, &par1, &fdnst) == 1) {
		 cxBESk->SetFocus();

		 CLR(ss);
		 sprintf(ss, "%2.2u - %2.2u %s", par1.par1, par1.tn, par1.nm);
		 cxBESk->Text = AS(ss);
		 sk1 = par1.par1;
		 kodrf = par1.tn;
		 } */
		AnsiString name = "";
		long kod1 = 0, kod2 = 0;
		if (IniVV(StringGrid1, &kod1, &kod2, &name) == 1) {
			cxBESk->Text = name;
			sk1 = kod1;
			kodrf = kod2;
			cxSEKodV->Value = sk1;
		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::aNewCopyExecute(TObject *Sender) {
	if (Vw->IsControlFocused) {
		prNew = 1;
		CLR(knu2);
		dho1 = 0;
		sk1 = 0;
		kodrf = 0;
		dxLCNew->Visible = true;
		cxBENU->Enabled = true;
		cxBENU->SetFocus();
		cxBEZaS->Text = "";
		dxLayoutControl1Item2->Enabled = false;
		dxLayoutControl1Item1->Enabled = false;

		aNewCopy->Enabled = false;
		aNew->Enabled = false;
		aDel->Enabled = false;
		aKor->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;

		// cxOk->Enabled = false;
		cxBENU->Clear();
		cxBEDoh->Clear();
		cxBESk->Clear();
		cxCBDoh->ItemIndex = 0;
		cxCBSk->ItemIndex = 0;
		cxSEKodDoh->Value = dho1;
		cxSEKodV->Value = sk1;

		dxLayoutControl1Item10->Enabled = true;
		dxLayoutControl1Item10->Visible = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBOkClick(TObject *Sender) {

	TcxGridDataController* dc = Vw->DataController;
	int ii;
	char s[10];

	bool Ok = true;
	ii = dc->FocusedRecordIndex;

	if (knu2.kod == 0 && knu2.knu == 0) {
		armerr(2, "Выберете Н/У");
		cxBENU->SetFocus();
		Ok = false;
	}

	if (Ok) {

		swb(&fdnst, &knu2.fd, 2);

		if (prNew == 1) {

			if (farel(fknu2, &knu2, sizeof(knu2)) == 0) {
				armerr(2, "Данное Н/У уже введено");
				cxBENU->SetFocus();
			}
			else {

				// if (cxBEDoh->Text == "") { 21.03.2011 DDA
				// knu2.dho = 0;
				// }
				// else {
				knu2.dho = dho1;
				// }
				knu2.sk = sk1;
				knu2.muld = 0;
				knu2.muls = 0;

				if (cxCBDoh->ItemIndex == 1) {
					knu2.muld = 1;
				}
				if (cxCBDoh->ItemIndex == 2) {
					knu2.muld = -1;
				}

				if (cxCBSk->ItemIndex == 1) {
					knu2.muls = 1;
				}
				if (cxCBSk->ItemIndex == 2) {
					knu2.muls = -1;
				}

				farwl(fknu2, &knu2, sizeof(knu2));
				ii = dc->AppendRecord();
				CLR(s);
				sprintf(s, "%2.2d.%2.2d", knu2.kod, knu2.knu);
				dc->Values[ii][VwVidKod->Index] = s;
				dc->Values[ii][VwVidNU->Index] = knu2.kod;
				dc->Values[ii][VwKodNU->Index] = knu2.knu;
				dc->Values[ii][VwNDoh->Index] = cxBEDoh->Text;
				dc->Values[ii][VwKodDoh->Index] = knu2.dho;
				dc->Values[ii][VwKodSk->Index] = knu2.sk;
				dc->Values[ii][VwUDoh->Index] = knu2.muld;
				dc->Values[ii][VwUSk->Index] = knu2.muls;
				dc->Values[ii][VwVKName->Index] = nuname;

				dc->Values[ii][VwKodSkRF->Index] = kodrf;

			}
		}
		else {
			knu2.kod = dc->Values[ii][VwVidNU->Index];
			knu2.knu = dc->Values[ii][VwKodNU->Index];
			if (farel(fknu2, &knu2, sizeof(knu2)) == 0) {
				// if (cxBEDoh->Text == "") {      21.03.2012 DDA
				// knu2.dho = 0;
				// }
				// else {
				knu2.dho = dho1;
				// }
				knu2.sk = sk1;
				knu2.muld = 0;
				knu2.muls = 0;

				if (cxCBDoh->ItemIndex == 1) {
					knu2.muld = 1;
				}
				if (cxCBDoh->ItemIndex == 2) {
					knu2.muld = -1;
				}

				if (cxCBSk->ItemIndex == 1) {
					knu2.muls = 1;
				}
				if (cxCBSk->ItemIndex == 2) {
					knu2.muls = -1;
				}

				farwl(fknu2, &knu2, sizeof(knu2));
				dc->Values[ii][VwNDoh->Index] = cxBEDoh->Text;
				dc->Values[ii][VwKodDoh->Index] = knu2.dho;
				dc->Values[ii][VwKodSk->Index] = knu2.sk;
				dc->Values[ii][VwUDoh->Index] = knu2.muld;
				dc->Values[ii][VwUSk->Index] = knu2.muls;
				if (kodrf != 0) {
					dc->Values[ii][VwKodSkRF->Index] = kodrf;
				}
				else {
					dc->Values[ii][VwKodSkRF->Index] = "";
				}

			}

		}

		dxLCNew->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		dxLayoutControl1Item2->Enabled = true;

		aNew->Enabled = true;
		aDel->Enabled = true;
		aKor->Enabled = true;
		aExit->Enabled = true;
		aKor->Enabled = true;
		aNewCopy->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr->SetFocus();
		dc->FocusedRecordIndex = ii;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int kk;
	char ss[100];

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			prNew = 0;
			CLR(knu2);
			dxLCNew->Visible = true;
			cxBENU->Enabled = false;
			cxBEDoh->Clear();
			cxBESk->Clear();
			cxBEDoh->SetFocus();
			dxLayoutControl1Item1->Enabled = false;
			dxLayoutControl1Item2->Enabled = false;

			aNew->Enabled = false;
			aDel->Enabled = false;
			aKor->Enabled = false;
			// cxOk->Enabled = false;
			aNewCopy->Enabled = false;
			aExit->Enabled = false;
			aExit->ShortCut = 0;
			// f = false;

			kk = dc->FocusedRecordIndex;
			sk1 = dc->Values[kk][VwKodSk->Index];
			dho1 = dc->Values[kk][VwKodDoh->Index];

			if (sk1 != 0) {
				kodrf = dc->Values[kk][VwKodSkRF->Index];
			}
			else {
				kodrf = 0;
			}

			knu2.kod = dc->Values[kk][VwVidNU->Index]; // н/у
			knu2.knu = dc->Values[kk][VwKodNU->Index];

			cxBENU->Text = dc->Values[kk][VwVidKod->Index];
			cxBENU->Text = cxBENU->Text + " ";
			cxBENU->Text = cxBENU->Text + dc->Values[kk][VwVKName->Index];

			cxBEDoh->Text = dc->Values[kk][VwNDoh->Index];
			cxSEKodDoh->Value = dho1;
			cxSEKodV->Value = sk1;

			CLR(vsr);
			// swb(&fdnst, &vsr.fd, 2);
			swb(&fd11, &vsr.fd, 2);

			/*
			 vsr.kod = (char)dc->Values[kk][VwKodSk->Index];

			 if (farel(fvsr, &vsr, sizeof(vsr)) == 0) {
			 CLR(ss);
			 sprintf(ss, "%2.2u - %2.2u %s", vsr.kod, vsr.kodrf, vsr.n);

			 cxBESk->Text = OEMtoWS(ss, sizeof(ss));
			 }
			 */
			AnsiString str = dc->Values[kk][VwKodSk->Index];
			for (int i = 1; i <= StringGrid1->RowCount - 1; i++) {
				if (StringGrid1->Cells[1][i] == str) {
					cxBESk->Text = StringGrid1->Cells[3][i];
				}
			}

			cxCBDoh->ItemIndex = 0;
			if (dc->Values[kk][VwUDoh->Index] == 1) {
				cxCBDoh->ItemIndex = 1;
			}
			if (dc->Values[kk][VwUDoh->Index] == -1) {
				cxCBDoh->ItemIndex = 2;
			}

			cxCBSk->ItemIndex = 0;
			if (dc->Values[kk][VwUSk->Index] == 1) {
				cxCBSk->ItemIndex = 1;
			}
			if (dc->Values[kk][VwUSk->Index] == -1) {
				cxCBSk->ItemIndex = 2;
			}

			cxBENU->Enabled = false;
			dxLayoutControl1Item10->Enabled = false;
			dxLayoutControl1Item10->Visible = false;

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0009::aDelExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	int ii, kk;

	if (Vw->IsControlFocused) {
		if (dc->FocusedRecordIndex > -1) {
			kk = dc->FocusedRecordIndex;
			if (armerr(-2, "Удалить выбранную запись ?") == 0) {

				CLR(knu2);
				knu2.kod = dc->Values[kk][VwVidNU->Index];
				knu2.knu = dc->Values[kk][VwKodNU->Index];
				swb(&fdnst, &knu2.fd, 2);

				if (farel(fknu2, &knu2, sizeof(knu2)) == 0) {
					fard(fknu2, &knu2);
					dc->DeleteFocused();
					if (dc->RecordCount == 0) {
						cxGr->RootLevelOptions->DetailFrameWidth = 2;
					}
				}

			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxBEZaSPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	struct zpsppar par;
	char ss[60];
	uchar tmpkod, tmpknu;
	CLR(par);
	tmpkod = knu2.kod;
	tmpknu = knu2.knu;
	if (l_call("ZPSPR1", "GKNUSN", &par) == 1) {
		cxBEZaS->SetFocus();

		knu2.kod = (uchar)par.par1;
		knu2.knu = (uchar) par.par2;
		swb(&fdnst, &knu2.fd, 2);
		CLR(ss);
		sprintf(ss, "%2.2u.%2.2u %s", par.par1, par.par2, par.nm);
		cxBEZaS->Text = AS(ss);
		if (farel(fknu2, &knu2, sizeof(knu2)) == 0) {

			///
			CLR(vsr);
			// swb(&fdnst, &vsr.fd, 2);
			swb(&fd11, &vsr.fd, 2);
			vsr.kod = knu2.sk;

			/* if (farel(fvsr, &vsr, sizeof(vsr)) == 0) {     21.03.2012  DDA
			 CLR(ss);
			 sprintf(ss, "%2.2u - %2.2u %s", vsr.kod, vsr.kodrf, vsr.n);
			 cxBESk->Text = OEMtoWS(ss, sizeof(ss));
			 kodrf = vsr.kodrf;
			 sk1 = vsr.kod;

			 } */

			AnsiString str = knu2.sk;
			sk1 = knu2.sk;
			cxSEKodV->Value = sk1;
			kodrf = 0;
			for (int i = 1; i <= StringGrid1->RowCount - 1; i++) {
				if (StringGrid1->Cells[1][i] == str) {
					cxBESk->Text = StringGrid1->Cells[3][i];
					kodrf = StrToInt(StringGrid1->Cells[2][i]);
				}
			}

			CLR(vdoh);
			dho1 = knu2.dho;
			cxSEKodDoh->Value = dho1;
			swb(&dho1, &vdoh.kod, 4);
			if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
				cxBEDoh->Text = OEMtoWS(vdoh.n, sizeof(vdoh.n));
			}

			cxCBDoh->ItemIndex = 0;
			if (knu2.muld == 1) {
				cxCBDoh->ItemIndex = 1;
			}
			if (knu2.muld == -1) {
				cxCBDoh->ItemIndex = 2;
			}

			cxCBSk->ItemIndex = 0;
			if (knu2.muls == 1) {
				cxCBSk->ItemIndex = 1;
			}
			if (knu2.muls == -1) {
				cxCBSk->ItemIndex = 2;
			}

		}

	}

	knu2.kod = tmpkod;
	knu2.knu = tmpknu;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxCBDohExit(TObject *Sender) {
	if (dho1 == 0) {
		cxCBDoh->ItemIndex = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxCBSkExit(TObject *Sender) {
	if (sk1 == 0) {
		cxCBSk->ItemIndex = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxGrEnter(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	if (dc->RecordCount == 0) {
		cxGr->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxGrExit(TObject *Sender) {
	cxGr->RootLevelOptions->DetailFrameWidth = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0009::cxSEKodDohExit(TObject *Sender) {
	if (cxSEKodDoh->Value == 0) {
		cxBEDoh->Text = "";

		dho1 = 0;
		cxCBDoh->ItemIndex = 0;

	}
	else {

		dho1 = cxSEKodDoh->Value;
		CLR(vdoh);
		swb(&dho1, &vdoh.kod, 4);

		if (farel(fvdoh, &vdoh, sizeof(vdoh)) == 0) {
			cxBEDoh->Text = OEMtoWS(vdoh.n, sizeof(vdoh.n)); // наименование
		}
		else
			cxBEDoh->Text = "";

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::cxSEKodVExit(TObject *Sender) {
	if (cxSEKodV->Value == 0) {
		cxBESk->Text = "";

		sk1 = 0;
		kodrf = 0;
		cxCBSk->ItemIndex = 0;

	}
	else {
		sk1 = cxSEKodV->Value;

		cxBESk->Text = "";
		kodrf = 0;
		AnsiString str = sk1;
		for (int i = 1; i <= StringGrid1->RowCount - 1; i++) {
			if (StringGrid1->Cells[1][i] == str) {
				cxBESk->Text = StringGrid1->Cells[3][i];
				kodrf = StrToInt(StringGrid1->Cells[2][i]);
			}
		}

	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0009::FormShow(TObject *Sender) {
	cxGr->SetFocus();
}
// ---------------------------------------------------------------------------
