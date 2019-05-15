// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#define fafct(x) if(x) {fafc(x);x=NULL;}

#pragma pack(push,1)
#include "wtzp.h"
#pragma pack(pop)

#include "GADR.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
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
#pragma link "cxProgressBar"
#pragma link "cxPropertiesStore"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
/* enum{
 tvSTRStrN=0,tvSTRStrK=1,
 tvREGRegN=0,tvREGRegK=1,
 tvRAIRaiN=0,tvRAIRegK=1,tvRAIRaiK=2,tvRAIRegN=3,
 tvGORGorN=0,tvGORRegK=1,tvGORRaiK=2,tvGORGorK=3,tvGORRegN=4,tvGORRaiN=5,
 tvNASNasN=0,tvNASRegK=1,tvNASRaiK=2,tvNASGorK=3,tvNASNasK=4,tvNASRegN=5,tvNASRaiN=6,tvNASGorN=7,
 tvULUlN=0,tvULIndex=1,tvULRegK=2,tvULRaiK=3,tvULGorK=4,tvULNasK=5,tvULUlK=6,tvULRegN=7,tvULRaiN=8,tvULGorN=9,tvULNasN=10
 }; */
enum {
	RUS_STR = 643
};
Tfraspr1 *fraspr1;

// ---------------------------------------------------------------------------
__fastcall Tfraspr1::Tfraspr1(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int Ini(struct bcb *b_ka, struct paradrn *adr, uchar vspr, uchar call) {
	int ret = -1;
	struct strkl sstrkl;
	FCB fstrkl = NULL;

	if (vspr > 5) {
		ShowMessage("Неверный вид справочника VSPR=" + IntToStr(vspr) +
				"\r\nСуществуют следующие виды справочников:\r\n    0 - Справочник стран;\r\n    1 - Справочник регионов;" "\r\n    2 - Справочник районов;\r\n    3 - Справочник городов;\r\n    4 - Справочник нас. пунктов;"
				"\r\n    5 - Справочник улиц.");
		return ret;
	}
	fraspr1 = new Tfraspr1(Application);
	fraspr1->OnRun = false;
	try {
		if (call == 1) {
			fraspr1->aOk->ShortCut = ShortCut(VK_RETURN, TShiftState());
			if (vspr == 5) {
				fraspr1->aFiltrStart->Enabled = true;
				fraspr1->aFiltrStart->Visible = true;
			}
		}
		else {
			fraspr1->aFiltrStart->Enabled = false;
			fraspr1->aFiltrStart->Visible = false;
		}
		fraspr1->b_ka = b_ka;
		// fraspr1->fadr=adr;
		fraspr1->fadrn = (struct paradrn*)adr;
		fraspr1->fstr = fraspr1->fadrn->str;
		if (vspr > 0) {
			if (adr->reg)
				fraspr1->freg = adr->reg;
			else
				fraspr1->freg = 23;
		}

		fraspr1->frai = adr->rai;
		fraspr1->fgor = adr->gor;
		fraspr1->fnas = adr->nas;
		fraspr1->ful = adr->ul;
		fraspr1->fspr = vspr;
		if (vspr == 0) {
			fraspr1->Caption = "Справочник стран";
			fraspr1->cxGridLv->GridView = fraspr1->tvSTR;
			fraspr1->lciREG->Visible = false;
			fraspr1->lciRAI->Visible = false;
			fraspr1->lciGOR->Visible = false;
			fraspr1->lciNAS->Visible = false;
		}
		if (vspr == 1) {
			fraspr1->Caption = "Справочник регионов";
			fraspr1->cxGridLv->GridView = fraspr1->tvREG;
			fraspr1->lciREG->Visible = false;
			fraspr1->lciRAI->Visible = false;
			fraspr1->lciGOR->Visible = false;
			fraspr1->lciNAS->Visible = false;
		}
		if (vspr == 2) {
			fraspr1->Caption = "Справочник районов";
			fraspr1->cxGridLv->GridView = fraspr1->tvRAI;
			fraspr1->lciRAI->Visible = false;
			fraspr1->lciGOR->Visible = false;
			fraspr1->lciNAS->Visible = false;
		}
		if (vspr == 3) {
			fraspr1->Caption = "Справочник городов";
			fraspr1->cxGridLv->GridView = fraspr1->tvGOR;
			fraspr1->lciGOR->Visible = false;
			fraspr1->lciNAS->Visible = false;
		}
		if (vspr == 4) {
			fraspr1->Caption = "Справочник населенных пунктов";
			fraspr1->cxGridLv->GridView = fraspr1->tvNAS;
			fraspr1->lciNAS->Visible = false;
		}
		if (vspr == 5) {
			fraspr1->Caption = "Справочник улиц";
			fraspr1->cxGridLv->GridView = fraspr1->tvUL;
		}
		fraspr1->ActView = (TcxGridTableView*)fraspr1->cxGridLv->GridView;
		fstrkl = fafo(fraspr1->b_ka, "strkl");
		CLR(fraspr1->RUS_STRN);
		if (fstrkl) {
			CLR(sstrkl);
			ushort sw = RUS_STR;
			swb(&sw, &sstrkl.str, 2);
			if (fare(fstrkl, &sstrkl) == 0)
				OemToCharBuffA(sstrkl.name, fraspr1->RUS_STRN, sizeof(fraspr1->RUS_STRN) - 1);
			fafct(fstrkl);
		}
		if (fraspr1->fnas == 0) {
			fraspr1->cxNAS->Properties->Buttons->Items[0]->Visible = false;
		}
		if (fraspr1->fgor == 0) {
			fraspr1->cxGOR->Properties->Buttons->Items[0]->Visible = false;
		}
		if (fraspr1->frai == 0) {
			fraspr1->cxRAI->Properties->Buttons->Items[0]->Visible = false;
		}
		fraspr1->ShowModal();
		ret = fraspr1->aRet;
	}
	catch (...) {
	}
	delete fraspr1;

	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr1::LoadData() {
	struct paradr radr;
	ushort rreg, rrai, rgor, rnas, rstr, rul;
	int razCmp;
	TcxCustomDataController* dc;

	fstrkl = fafo(b_ka, "strkl");
	fregkl = fafo(b_ka, "regkl");
	fraikl = fafo(b_ka, "raikl");
	fgorkl = fafo(b_ka, "gorkl");
	fnaskl = fafo(b_ka, "naskl");
	fulkl = fafo(b_ka, "ulkl");
	fnaskl = fafo(b_ka, "naskl");

	char str_str[256], str_reg[256], str_rai[256], str_gor[256], str_nas[256], str_ul[256], str_ind[256];
	int ARecordIndex, prc_10;
	ActView->DataController->BeginFullUpdate();
	ActView->DataController->MultiSelect = true;
	ActView->DataController->SelectAll();
	ActView->DataController->DeleteSelection();
	ActView->DataController->MultiSelect = false;
	lciPB->Visible = true;
	if (fspr == 0) { // вызов справочника стран
		dc = tvSTR->DataController;
		CLR(strkl);
		rec = 0;
		while (fargl(fstrkl, &strkl, sizeof(strkl)) == 0)
			++rec;
		if (rec) {
			cxPB->Position = 0;
			cxPB->Properties->Max = rec;
			rec = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			CLR(strkl);
			while (fargl(fstrkl, &strkl, sizeof(strkl)) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				Application->ProcessMessages();
				try {
					ARecordIndex = dc->AppendRecord();
					CLR(str_str);
					MV(strkl.name, str_str);
					OemToCharBuffA(str_str, str_str, sizeof(str_str));
					swb(&strkl.str, &rstr, 2);
					dc->Values[ARecordIndex][tvSTRStrK->Index] = rstr;
					dc->Values[ARecordIndex][tvSTRStrN->Index] = str_str;
					if (rstr == fstr)
						strncpy(str_f, str_str, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
	}
	if (fspr == 1) { // вызов справочника регионов
		dc = tvREG->DataController;
		CLR(regkl);
		rec = 0;
		while (fargl(fregkl, &regkl, sizeof(regkl)) == 0)
			++rec;
		if (rec) {
			cxPB->Position = 0;
			cxPB->Properties->Max = rec;
			rec = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			CLR(regkl);
			while (fargl(fregkl, &regkl, sizeof(regkl)) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				Application->ProcessMessages();
				try {
					ARecordIndex = dc->AppendRecord();
					CLR(str_reg);
					MV(regkl.name, str_reg);
					OemToCharBuffA(str_reg, str_reg, sizeof(str_reg));
					swb(&regkl.reg, &rreg, 2);
					dc->Values[ARecordIndex][tvREGRegK->Index] = rreg;
					dc->Values[ARecordIndex][tvREGRegN->Index] = str_reg;
					if (rreg == freg)
						strncpy(str_f, str_reg, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
	}
	if (fspr == 2) { // вызов справочника районов
		dc = tvRAI->DataController;
		CLR(raikl);
		CLR(radr);
		SW(freg, radr.reg);
		razCmp = GetRazCmp(&radr, fspr);
		mov(&radr, &raikl, razCmp);
		rec = 0;
		while (fargl(fraikl, &raikl, sizeof(raikl)) == 0 && cmp(&raikl, &radr, razCmp) == 0)
			++rec;
		if (rec) {
			cxPB->Position = 0;
			cxPB->Properties->Max = rec;
			rec = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			CLR(raikl);
			CLR(radr);
			SW(freg, radr.reg);
			mov(&radr, &raikl, razCmp);
			while (fargl(fraikl, &raikl, sizeof(raikl)) == 0 && cmp(&raikl, &radr, razCmp) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				try {
					ARecordIndex = dc->AppendRecord();
					CLR(regkl);
					regkl.reg = raikl.reg;

					CLR(str_reg);
					rreg = 0;
					if (fare(fregkl, &regkl) == 0) {
						MV(regkl.name, str_reg);
						OemToCharBuffA(str_reg, str_reg, sizeof(str_reg));
						swb(&regkl.reg, &rreg, 2);
					}

					CLR(str_rai);
					MV(raikl.name, str_rai);
					OemToCharBuffA(str_rai, str_rai, sizeof(str_rai));
					swb(&raikl.rai, &rrai, 2);
					dc->Values[ARecordIndex][tvRAIRegK->Index] = rreg;
					dc->Values[ARecordIndex][tvRAIRaiK->Index] = rrai;
					dc->Values[ARecordIndex][tvRAIRegN->Index] = str_reg;
					dc->Values[ARecordIndex][tvRAIRaiN->Index] = str_rai;
					if (rreg == freg && rrai == frai)
						strncpy(str_f, str_rai, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
	}
	if (fspr == 3) { // вызов справочника городов
		dc = tvGOR->DataController;
		CLR(gorkl);
		CLR(radr);
		SW(freg, radr.reg);
		SW(frai, radr.rai);
		razCmp = GetRazCmp(&radr, fspr);
		mov(&radr, &gorkl, razCmp);
		rec = 0;
		while (fargl(fgorkl, &gorkl, sizeof(gorkl)) == 0 && cmp(&gorkl, &radr, razCmp) == 0)
			++rec;
		if (rec) {
			cxPB->Position = 0;
			cxPB->Properties->Max = rec;
			rec = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			CLR(gorkl);
			CLR(radr);
			SW(freg, radr.reg);
			SW(frai, radr.rai);
			mov(&radr, &gorkl, razCmp);
			while (fargl(fgorkl, &gorkl, sizeof(gorkl)) == 0 && cmp(&gorkl, &radr, razCmp) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				try {
					ARecordIndex = dc->AppendRecord();
					CLR(regkl);
					regkl.reg = gorkl.reg;
					CLR(str_reg);
					rreg = 0;
					if (fare(fregkl, &regkl) == 0) {
						MV(regkl.name, str_reg);
						OemToCharBuffA(str_reg, str_reg, sizeof(str_reg));
						swb(&regkl.reg, &rreg, 2);
					}
					CLR(raikl);
					raikl.reg = gorkl.reg;
					raikl.rai = gorkl.rai;
					CLR(str_rai);
					rrai = 0;
					if (fare(fraikl, &raikl) == 0) {
						MV(raikl.name, str_rai);
						OemToCharBuffA(str_rai, str_rai, sizeof(str_rai));
						swb(&raikl.rai, &rrai, 2);
					}
					CLR(str_gor);
					MV(gorkl.name, str_gor);
					OemToCharBuffA(str_gor, str_gor, sizeof(str_gor));
					swb(&gorkl.gor, &rgor, 2);

					dc->Values[ARecordIndex][tvGORRegK->Index] = rreg;
					dc->Values[ARecordIndex][tvGORRaiK->Index] = rrai;
					dc->Values[ARecordIndex][tvGORGorK->Index] = rgor;
					dc->Values[ARecordIndex][tvGORRegN->Index] = str_reg;
					dc->Values[ARecordIndex][tvGORRaiN->Index] = str_rai;
					dc->Values[ARecordIndex][tvGORGorN->Index] = str_gor;

					if (rreg == freg && rrai == frai && rgor == fgor)
						strncpy(str_f, str_gor, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
		cxGrid->SetFocus();
	}

	if (fspr == 4) { // вызов справочника населенных пунктов
		dc = tvNAS->DataController;
		CLR(naskl);
		CLR(radr);
		SW(freg, radr.reg);
		SW(frai, radr.rai);
		SW(fgor, radr.gor);
		razCmp = GetRazCmp(&radr, fspr);
		mov(&radr, &naskl, razCmp);
		rec = 0;
		while (fargl(fnaskl, &naskl, sizeof(naskl)) == 0 && cmp(&naskl, &radr, razCmp) == 0)
			++rec;
		if (rec) {
			cxPB->Position = 0;
			cxPB->Properties->Max = rec;
			rec = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			CLR(naskl);
			CLR(radr);
			SW(freg, radr.reg);
			SW(frai, radr.rai);
			SW(fgor, radr.gor);
			mov(&radr, &naskl, razCmp);
			while (fargl(fnaskl, &naskl, sizeof(naskl)) == 0 && cmp(&naskl, &radr, razCmp) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				try {
					ARecordIndex = dc->AppendRecord();
					CLR(regkl);
					regkl.reg = naskl.reg;
					CLR(str_reg);
					rreg = 0;
					if (fare(fregkl, &regkl) == 0) {
						MV(regkl.name, str_reg);
						OemToCharBuffA(str_reg, str_reg, sizeof(str_reg));
						swb(&regkl.reg, &rreg, 2);
					}
					CLR(raikl);
					raikl.reg = naskl.reg;
					raikl.rai = naskl.rai;
					CLR(str_rai);
					rrai = 0;
					if (fare(fraikl, &raikl) == 0) {
						MV(raikl.name, str_rai);
						OemToCharBuffA(str_rai, str_rai, sizeof(str_rai));
						swb(&raikl.rai, &rrai, 2);
					}
					CLR(gorkl);
					gorkl.reg = naskl.reg;
					gorkl.rai = naskl.rai;
					gorkl.gor = naskl.gor;
					CLR(str_gor);
					rgor = 0;
					if (fare(fgorkl, &gorkl) == 0) {
						MV(gorkl.name, str_gor);
						OemToCharBuffA(str_gor, str_gor, sizeof(str_gor));
						swb(&gorkl.gor, &rgor, 2);
					}
					CLR(str_nas);
					MV(naskl.name, str_nas);
					OemToCharBuffA(str_nas, str_nas, sizeof(str_nas));
					swb(&naskl.nas, &rnas, 2);

					dc->Values[ARecordIndex][tvNASRegK->Index] = rreg;
					dc->Values[ARecordIndex][tvNASRaiK->Index] = rrai;
					dc->Values[ARecordIndex][tvNASGorK->Index] = rgor;
					dc->Values[ARecordIndex][tvNASNasK->Index] = rnas;
					dc->Values[ARecordIndex][tvNASRegN->Index] = str_reg;
					dc->Values[ARecordIndex][tvNASRaiN->Index] = str_rai;
					dc->Values[ARecordIndex][tvNASGorN->Index] = str_gor;
					dc->Values[ARecordIndex][tvNASNasN->Index] = str_nas;

					if (rreg == freg && rrai == frai && rgor == fgor && rnas == fnas)
						strncpy(str_f, str_nas, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
		cxGrid->SetFocus();
	}

	if (fspr == 5) { // вызов справочника улиц
		dc = tvUL->DataController;
		rec = 0;
		CLR(ulkl);
		CLR(radr);
		SW(freg, radr.reg);
		SW(frai, radr.rai);
		SW(fgor, radr.gor);
		SW(fnas, radr.nas);
		// ulkl.reg=freg;
		razCmp = GetRazCmp(&radr, fspr);
		mov(&radr, &ulkl, razCmp);
		while (fargl(fulkl, &ulkl, sizeof(ulkl)) == 0 && cmp(&ulkl, &radr, razCmp) == 0)
			++rec;
		if (rec) {
			CLR(ulkl);
			CLR(radr);
			SW(freg, radr.reg);
			SW(frai, radr.rai);
			SW(fgor, radr.gor);
			SW(fnas, radr.nas);
			// ulkl.reg=freg;
			mov(&radr, &ulkl, razCmp);
			cxPB->Properties->Max = rec;
			rec = 0;
			cxPB->Position = 0;
			prc_10 = cxPB->Properties->Max / 10;
			if (prc_10 == 0)
				prc_10 = 1;
			while (fargl(fulkl, &ulkl, sizeof(ulkl)) == 0 && cmp(&ulkl, &radr, razCmp) == 0) {
				if ((++rec % prc_10) == 0)
					cxPB->Position = rec;
				Application->ProcessMessages();
				try {
					ARecordIndex = dc->AppendRecord();

					CLR(regkl);
					regkl.reg = ulkl.reg;
					CLR(str_reg);
					rreg = 0;
					if (fare(fregkl, &regkl) == 0) {
						MV(regkl.name, str_reg);
						OemToCharBuffA(str_reg, str_reg, sizeof(str_reg));
						swb(&regkl.reg, &rreg, 2);
					}
					CLR(raikl);
					raikl.reg = ulkl.reg;
					raikl.rai = ulkl.rai;
					CLR(str_rai);
					rrai = 0;
					if (fare(fraikl, &raikl) == 0) {
						MV(raikl.name, str_rai);
						OemToCharBuffA(str_rai, str_rai, sizeof(str_rai));
						swb(&raikl.rai, &rrai, 2);
					}
					CLR(gorkl);
					gorkl.reg = ulkl.reg;
					gorkl.rai = ulkl.rai;
					gorkl.gor = ulkl.gor;
					CLR(str_gor);
					rgor = 0;
					if (fare(fgorkl, &gorkl) == 0) {
						MV(gorkl.name, str_gor);
						OemToCharBuffA(str_gor, str_gor, sizeof(str_gor));
						swb(&gorkl.gor, &rgor, 2);
					}
					CLR(naskl);
					naskl.reg = ulkl.reg;
					naskl.rai = ulkl.rai;
					naskl.gor = ulkl.gor;
					naskl.nas = ulkl.nas;
					CLR(str_nas);
					rnas = 0;
					if (fare(fnaskl, &naskl) == 0) {
						MV(naskl.name, str_nas);
						OemToCharBuffA(str_nas, str_nas, sizeof(str_nas));
						swb(&naskl.nas, &rnas, 2);
					}
					CLR(str_ul);
					MV(ulkl.name, str_ul);
					OemToCharBuffA(str_ul, str_ul, sizeof(str_ul));
					CLR(str_ind);
					MV(ulkl.ind, str_ind);
					swb(&ulkl.ul, &rul, 2);

					dc->Values[ARecordIndex][tvULRegK->Index] = rreg;
					dc->Values[ARecordIndex][tvULRaiK->Index] = rrai;
					dc->Values[ARecordIndex][tvULGorK->Index] = rgor;
					dc->Values[ARecordIndex][tvULNasK->Index] = rnas;
					dc->Values[ARecordIndex][tvULUlK->Index] = rul;
					dc->Values[ARecordIndex][tvULRegN->Index] = str_reg;
					dc->Values[ARecordIndex][tvULRaiN->Index] = str_rai;
					dc->Values[ARecordIndex][tvULGorN->Index] = str_gor;
					dc->Values[ARecordIndex][tvULNasN->Index] = str_nas;
					dc->Values[ARecordIndex][tvULIndex->Index] = str_ind;
					dc->Values[ARecordIndex][tvULUlN->Index] = str_ul;
					if (rreg == freg && rrai == frai && rgor == fgor && rnas == fnas && rul == ful)
						strncpy(str_f, str_ul, sizeof(str_f) - 1);
				}
				catch (...) {
				}
			}
		}
	}
	ActView->DataController->EndFullUpdate();
	if (dc->RecordCount == 0) {
		if (freg) {
			CLR(regkl);
			SW(freg, regkl.reg);
			if (fare(fregkl, &regkl) == 0) {
				OemToCharBuffA(regkl.name, regkl.name, sizeof(regkl.name));
				cxREG->Text = regkl.name;
			}
		}
		if (frai) {
			CLR(raikl);
			SW(freg, raikl.reg);
			SW(frai, raikl.rai);
			if (fare(fraikl, &raikl) == 0) {
				OemToCharBuffA(raikl.name, raikl.name, sizeof(raikl.name));
				cxRAI->Text = raikl.name;
			}
		}
		if (fgor) {
			CLR(gorkl);
			SW(freg, gorkl.reg);
			SW(frai, gorkl.rai);
			SW(fgor, gorkl.gor);
			if (fare(fgorkl, &gorkl) == 0) {
				OemToCharBuffA(gorkl.name, gorkl.name, sizeof(gorkl.name));
				cxGOR->Text = gorkl.name;
			}
		}
		if (fnas) {
			CLR(naskl);
			SW(freg, naskl.reg);
			SW(frai, naskl.rai);
			SW(fgor, naskl.gor);
			SW(fnas, naskl.nas);
			if (fare(fnaskl, &naskl) == 0) {
				OemToCharBuffA(naskl.name, naskl.name, sizeof(naskl.name));
				cxNAS->Text = naskl.name;
			}
		}
	}
	else {
		Locate();
	}
	lciPB->Visible = false;
	Application->ProcessMessages();
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr1::tvFocusedRecordChanged(TcxCustomGridTableView *Sender, TcxCustomGridRecord *APrevFocusedRecord,
		TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged) {
	Variant v1, v2, v3, v4;
	if (AFocusedRecord) {
		TcxCustomDataController* pDC = Sender->DataController;
		if (fspr == 2) {
			v1 = pDC->Values[AFocusedRecord->RecordIndex][tvRAIRegN->Index];
		}
		if (fspr == 3) {
			v1 = pDC->Values[AFocusedRecord->RecordIndex][tvGORRegN->Index];
			v2 = pDC->Values[AFocusedRecord->RecordIndex][tvGORRaiN->Index];
		}
		if (fspr == 4) {
			v1 = pDC->Values[AFocusedRecord->RecordIndex][tvNASRegN->Index];
			v2 = pDC->Values[AFocusedRecord->RecordIndex][tvNASRaiN->Index];
			v3 = pDC->Values[AFocusedRecord->RecordIndex][tvNASGorN->Index];
		}
		if (fspr == 5) {
			v1 = pDC->Values[AFocusedRecord->RecordIndex][tvULRegN->Index];
			v2 = pDC->Values[AFocusedRecord->RecordIndex][tvULRaiN->Index];
			v3 = pDC->Values[AFocusedRecord->RecordIndex][tvULGorN->Index];
			v4 = pDC->Values[AFocusedRecord->RecordIndex][tvULNasN->Index];
		}
	}
	cxREG->Text = v1;
	cxRAI->Text = v2;
	cxGOR->Text = v3;
	cxNAS->Text = v4;
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::FormActivate(TObject *Sender) {
	if (OnRun == false) {
		OnRun = true;
		ActView->BeginUpdate();
		try {
			LoadData();
		}
		__finally {
			ActView->EndUpdate();
			Locate();
		}
		ActView->NavigatorButtons->Next->Click();
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvULColumn10PropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	if (AButtonIndex == 0) {
		// ActView->FilterRow->ApplyChanges=fracImmediately;
		aFiltrStartExecute(Sender);
	}
	else if (AButtonIndex == 1) {
		// ActView->FilterRow->ApplyChanges=fracOnCellExit;
		ActView->DataController->Filter->Active = false;
		ActView->DataController->Filter->Clear();
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvULMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) {
	if (ActView->Controller->FocusedRow) {
		if (ActView->Controller->FocusedRow->IsFilterRow)
			ActView->Controller->EditingController->ShowEdit();
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvULInitEditValue(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem, TcxCustomEdit *AEdit,
		Variant &AValue) {
	String EditingText;

	if (Sender->Controller->FocusedRecord == ActView->OptionsView->GridView->ViewData->FilterRow) { // Filter row is focused
		EditingText = ((TcxTextEdit*)AEdit)->EditingText;
		TReplaceFlags Flg;
		Flg << rfReplaceAll << rfIgnoreCase;
		EditingText = StringReplace(EditingText, "%", "", Flg);
		((TcxTextEdit *)AEdit)->EditingText = EditingText;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvULEditValueChanged(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem) {
	/*
	 if (Sender->Controller->FocusedRecord == ActView->OptionsView->GridView->ViewData->FilterRow) { // Filter row is focused
	 FilterString = ((TcxTextEdit*)Sender->Controller->EditingController->Edit)->EditValue;
	 TReplaceFlags Flg;
	 Flg << rfReplaceAll << rfIgnoreCase;
	 FilterString = StringReplace(FilterString, "%", "", Flg);
	 PostMessage(Handle, CM_APPLYFILTER, Integer(Sender->DataController->Filter), Integer(AItem));
	 }
	 */
}

/*
 void __fastcall Tfraspr1::OnCM_APPLYFILTER(TMessage& Msg) {
 TcxDBDataFilterCriteria *FilterC;

 // if (((TObject *)Msg.WParam) == FilterC){
 // with TObject(Msg.WParam) as TcxDBDataFilterCriteria do

 // ActView->DataController->Filter->BeginUpdate();
 // try {
 ActView->DataController->Filter->Root->Clear();
 if (FilterString.Length()) {
 FilterString = "%" + FilterString + "%";
 ActView->DataController->Filter->Root->AddItem((TObject *)Msg.LParam, foLike, FilterString, FilterString);
 }
 // } __finally {
 // ActView->DataController->Filter->EndUpdate();
 // ActView->DataController->Filter->Active=true;
 // }

 // ActView->DataController->Filter->Clear();
 // FilterString =  "%" + FilterString + "%";

 // ActView->DataController->Filter->BoolOperatorKind = fboAnd;
 // ActView->DataController->Filter->Root->AddItem((TObject *)Msg.LParam, foLike, FilterString, FilterString);
 // }
 };
 */
void __fastcall Tfraspr1::aOkExecute(TObject *Sender) {
	TcxCustomDataController *pDC = ActView->ViewData->DataController;
	AnsiString rAS;
	int ind = pDC->GetFocusedRecordIndex();
	if ((pDC->RecordCount > 0) && (fspr != 5 || (ind >= 0 && !tvUL->Controller->IsFilterRowFocused()))) {
		CLR(*fadrn);
		if (fspr == 0) {
			fadrn->str = pDC->Values[ind][tvSTRStrK->Index];
			strncpy(fadrn->nstr, ((AnsiString)pDC->Values[ind][tvSTRStrN->Index].VOleStr).c_str(), sizeof(fadrn->nstr));
		}
		else if (fspr == 1) {
			fadrn->str = RUS_STR;
			fadrn->reg = pDC->Values[ind][tvREGRegK->Index];
			rAS = pDC->Values[ind][tvREGRegN->Index];
			strncpy(fadrn->nreg, rAS.c_str(), sizeof(fadrn->nreg));
			strncpy(fadrn->nstr, RUS_STRN, sizeof(fadrn->nstr));
		}
		else if (fspr == 2) {
			fadrn->str = RUS_STR;
			fadrn->reg = pDC->Values[ind][tvRAIRegK->Index];
			fadrn->rai = pDC->Values[ind][tvRAIRaiK->Index];
			rAS = pDC->Values[ind][tvRAIRegN->Index];
			strncpy(fadrn->nreg, rAS.c_str(), sizeof(fadrn->nreg));
			rAS = pDC->Values[ind][tvRAIRaiN->Index];
			strncpy(fadrn->nrai, rAS.c_str(), sizeof(fadrn->nrai));
			strncpy(fadrn->nstr, RUS_STRN, sizeof(fadrn->nstr));
		}
		else if (fspr == 3) {
			fadrn->str = RUS_STR;
			fadrn->reg = pDC->Values[ind][tvGORRegK->Index];
			fadrn->rai = pDC->Values[ind][tvGORRaiK->Index];
			fadrn->gor = pDC->Values[ind][tvGORGorK->Index];
			rAS = pDC->Values[ind][tvGORRegN->Index];
			strncpy(fadrn->nreg, rAS.c_str(), sizeof(fadrn->nreg));
			rAS = pDC->Values[ind][tvGORRaiN->Index];
			strncpy(fadrn->nrai, rAS.c_str(), sizeof(fadrn->nrai));
			rAS = pDC->Values[ind][tvGORGorN->Index];
			strncpy(fadrn->ngor, rAS.c_str(), sizeof(fadrn->ngor));
			strncpy(fadrn->nstr, RUS_STRN, sizeof(fadrn->nstr));
		}
		else if (fspr == 4) {
			fadrn->str = RUS_STR;
			fadrn->reg = pDC->Values[ind][tvNASRegK->Index];
			fadrn->rai = pDC->Values[ind][tvNASRaiK->Index];
			fadrn->gor = pDC->Values[ind][tvNASGorK->Index];
			fadrn->nas = pDC->Values[ind][tvNASNasK->Index];
			rAS = pDC->Values[ind][tvNASRegN->Index];
			strncpy(fadrn->nreg, rAS.c_str(), sizeof(fadrn->nreg));
			rAS = pDC->Values[ind][tvNASRaiN->Index];
			strncpy(fadrn->nrai, rAS.c_str(), sizeof(fadrn->nrai));
			rAS = pDC->Values[ind][tvNASGorN->Index];
			strncpy(fadrn->ngor, rAS.c_str(), sizeof(fadrn->ngor));
			rAS = pDC->Values[ind][tvNASNasN->Index];
			strncpy(fadrn->nnas, rAS.c_str(), sizeof(fadrn->nnas));
			strncpy(fadrn->nstr, RUS_STRN, sizeof(fadrn->nstr));
		}
		else if (fspr == 5) {
			fadrn->str = RUS_STR;
			fadrn->reg = pDC->Values[ind][tvULRegK->Index];
			fadrn->rai = pDC->Values[ind][tvULRaiK->Index];
			fadrn->gor = pDC->Values[ind][tvULGorK->Index];
			fadrn->nas = pDC->Values[ind][tvULNasK->Index];
			fadrn->ul = pDC->Values[ind][tvULUlK->Index];
			rAS = pDC->Values[ind][tvULRegN->Index];
			strncpy(fadrn->nreg, rAS.c_str(), sizeof(fadrn->nreg));
			rAS = pDC->Values[ind][tvULRaiN->Index];
			strncpy(fadrn->nrai, rAS.c_str(), sizeof(fadrn->nrai));
			rAS = pDC->Values[ind][tvULGorN->Index];
			strncpy(fadrn->ngor, rAS.c_str(), sizeof(fadrn->ngor));
			rAS = pDC->Values[ind][tvULNasN->Index];
			strncpy(fadrn->nnas, rAS.c_str(), sizeof(fadrn->nnas));
			rAS = pDC->Values[ind][tvULIndex->Index];
			strncpy(fadrn->ind, rAS.c_str(), sizeof(fadrn->ind));
			rAS = pDC->Values[ind][tvULUlN->Index];
			strncpy(fadrn->nul, rAS.c_str(), sizeof(fadrn->nul));
			strncpy(fadrn->nstr, RUS_STRN, sizeof(fadrn->nstr));
		}
		Tfraspr03::aOkExecute(Sender);
		// Close();
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr1::tvULMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	TcxGridSite * gs = dynamic_cast<TcxGridSite*>(Sender);
	if (gs) {
		Handled = true;
		TcxGridTableView *tv = (TcxGridTableView*)gs->GridView;
		if (WheelDelta < 0) {
			for (int i = 0; i < -WheelDelta / 120; ++i) {
				if (!tv->DataController->IsEOF())
					tv->NavigatorButtons->Next->Click();
				else
					break;
			}
		}
		else if (WheelDelta > 0) {
			for (int i = 0; i < WheelDelta / 120; ++i)
				if (!tv->DataController->IsBOF())
					tv->NavigatorButtons->Prior->Click();
				else
					break;
		}
	}
}

// ---------------------------------------------------------------------------
int Tfraspr1::GetRazCmp(struct paradr *radr, uchar vspr) {
	int ret = 0;
	if (radr->nas) {
		ret = 8;
	}
	else if (radr->gor) {
		ret = 6;
	}
	else if (radr->rai) {
		ret = 4;
	}
	else if (radr->reg) {
		ret = 2;
	}
	if (vspr == 1 && ret > 2)
		ret = 2;
	else if (vspr == 2 && ret > 4)
		ret = 4;
	else if (vspr == 3 && ret > 6)
		ret = 6;
	else if (vspr == 4 && ret > 8)
		ret = 8;
	else if (vspr == 5 && ret > 10)
		ret = 10;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr1::aFiltrStartExecute(TObject *Sender) {
	if (ActView->Controller->EditingController->Edit) {
		ActView->Controller->EditingController->Edit->EditValue = ActView->Controller->EditingController->Edit->EditingValue;
		ActView->DataController->Filter->Active = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr1::cxRAIPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	cxRAI->Properties->Buttons->Items[0]->Enabled = false;
	cxGOR->Properties->Buttons->Items[0]->Enabled = false;
	cxNAS->Properties->Buttons->Items[0]->Enabled = false;
	if (Sender == cxRAI) {
		cxRAI->Clear();
		cxGOR->Clear();
		cxNAS->Clear();
		frai = 0;
		fgor = 0;
		fnas = 0;
		cxRAI->Properties->Buttons->Items[0]->Visible = false;
		cxGOR->Properties->Buttons->Items[0]->Visible = false;
		cxNAS->Properties->Buttons->Items[0]->Visible = false;
	}
	else if (Sender == cxGOR) {
		cxGOR->Clear();
		cxNAS->Clear();
		fgor = 0;
		fnas = 0;
		cxGOR->Properties->Buttons->Items[0]->Visible = false;
		cxNAS->Properties->Buttons->Items[0]->Visible = false;
	}
	else if (Sender == cxNAS) {
		cxNAS->Clear();
		fnas = 0;
		cxNAS->Properties->Buttons->Items[0]->Visible = false;
	}
	LoadData();
	cxRAI->Properties->Buttons->Items[0]->Enabled = true;
	cxGOR->Properties->Buttons->Items[0]->Enabled = true;
	cxNAS->Properties->Buttons->Items[0]->Enabled = true;
}

// ---------------------------------------------------------------------------
void Tfraspr1::Locate() {
	TcxGridColumn *col;

	if (fspr == 0)
		col = tvSTRStrN;
	if (fspr == 1)
		col = tvREGRegN;
	else if (fspr == 2)
		col = tvRAIRaiN;
	else if (fspr == 3)
		col = tvGORGorN;
	else if (fspr == 4)
		col = tvNASNasN;
	else if (fspr == 5)
		col = tvULUlN;
	if (ActView->DataController->Search->Locate(col->Index, str_f)) {
		--ActView->DataController->FocusedRowIndex;
	}
}

void __fastcall Tfraspr1::FormClose(TObject *Sender, TCloseAction &Action) {
	fafct(fstrkl);
	fafct(fregkl);
	fafct(fraikl);
	fafct(fgorkl);
	fafct(fnaskl);
	fafct(fulkl);
	fafct(fnaskl);
	Tfraspr03::FormClose(Sender, Action);
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvULCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvREGCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvRAICustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvGORCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvNASCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr1::tvSTRCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------
