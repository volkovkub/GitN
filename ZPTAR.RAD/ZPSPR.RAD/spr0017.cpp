// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"

#include "spr0017.h"
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
TfrSp0017 *frSp0017;

// ---------------------------------------------------------------------------
__fastcall TfrSp0017::TfrSp0017(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0017(int Vspr, struct zpkfrs *kfrs, struct fdate *fdpar) {
	int ret = -1;
	ushort rr;

	frSp0017 = new TfrSp0017(Application);
	try {
		frSp0017->b = (struct bsp*)c_p->b_sp;
		frSp0017->fcnst = fafo(c_p->b_zp, "const");
		frSp0017->prKor = true;

		CLR(frSp0017->cnst);
		strcpy(frSp0017->cnst.n, "KLIENT");
		if (fare(frSp0017->fcnst, &frSp0017->cnst) == 0) {
			if (strcmp(frSp0017->cnst.ct, "1") == 0) {
				frSp0017->prKor = false;
			}
		}
		fafc(frSp0017->fcnst);
		if (frSp0017->prKor == true) {
			if (frSp0017->b->sts[4] == '8') {
				frSp0017->prKor = true; // корректировка разрешена
			}
			else {
				frSp0017->prKor = false; // корректировка запрещена
			}
		}
		if ((int &)Vspr == 1) {
			fdpar->fd_dd = 1;
			fdpar->fd_mm = 1;
			fdpar->fd_yy = frSp0017->b->fd.yy;

			frSp0017->prVspr = true;
			frSp0017->DBDateEd->Enabled = true;
		}
		if ((int &)Vspr == 0) {
			frSp0017->prVspr = false;
			frSp0017->DBDateEd->Enabled = true;
		}
		if ((int &)Vspr == 0) {
			frSp0017->prVspr = false;
			frSp0017->DBDateEd->Enabled = false;
		}
		frSp0017->fdkfr.fd_dd = 1;
		frSp0017->fdkfr.fd_mm = 1;
		frSp0017->fdkfr.fd_yy = fdpar->fd_yy;
		frSp0017->nfdyy.fd_dd = 1;
		frSp0017->nfdyy.fd_mm = 1;
		frSp0017->nfdyy.fd_yy = fdpar->fd_yy;

		if (frSp0017->nfdyy.fd_yy <= frSp0017->b->uyy.yy) {
			frSp0017->dtprKor = true;
		}
		else {
			frSp0017->dtprKor = false;
		}
		frSp0017->DBDateEd->EditValue = EncodeDate(frSp0017->fdkfr.fd_yy + 1980, 1, 1);
		frSp0017->fzpkfrs = fafonc(c_p->b_nc, "zpkfrs");

		frSp0017->aRefresh->Execute();
		frSp0017->ShowModal();
		ret = frSp0017->aRet;
		if (ret == 1) {
			TcxGridDataController* dc = frSp0017->cxGridKFRSTabVw->DataController;
			ret = (unsigned short)dc->Values[dc->FocusedRecordIndex][frSp0017->cxGridKFRSTabVwNPP->Index];
		}
	}
	catch (...) {
	}
	fafc(frSp0017->fzpkfrs);
	delete frSp0017;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSp0017::aRefreshExecute(TObject *Sender) {
	int ii;
	AnsiString ssKER, ssSBKER, ssISF, ssTF, ssTS, ssMRP, ssSUBS, ssCELS;
	ushort npp;

	TcxGridDataController* dc = cxGridKFRSTabVw->DataController;

	if (dc->RecordCount != 0) {
		cxGridKFRSTabVw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
	}
	cxGridKFRSTabVw->OptionsSelection->MultiSelect = false;

	dc->BeginFullUpdate();
	swb(&nfdyy, &fdfl, 2);
	CLR(zpkfrs);
	swb(&nfdyy, &zpkfrs.fdg, 2);
	while (fargl(fzpkfrs, &zpkfrs, sizeof(zpkfrs)) == 0 && cmp(&zpkfrs.fdg, &fdfl, 2) == 0) {
		ii = dc->AppendRecord();
		swb(&zpkfrs.npp, &npp, 2);

		dc->Values[ii][cxGridKFRSTabVwNPP->Index] = npp;

		ssKER = OEMtoAL(zpkfrs.ker, sizeof(zpkfrs.ker));
		dc->Values[ii][cxGridKFRSTabVwKER->Index] = ssKER;

		ssSBKER = OEMtoAL(zpkfrs.sbker, sizeof(zpkfrs.sbker));
		dc->Values[ii][cxGridKFRSTabVwSBKER->Index] = ssSBKER;

		ssISF = OEMtoAL(zpkfrs.isf, sizeof(zpkfrs.isf));
		dc->Values[ii][cxGridKFRSTabVwISF->Index] = ssISF;

		ssTF = OEMtoAL(zpkfrs.tf, sizeof(zpkfrs.tf));
		dc->Values[ii][cxGridKFRSTabVwTF->Index] = ssTF;

		ssTS = OEMtoAL(zpkfrs.ts, sizeof(zpkfrs.ts));
		dc->Values[ii][cxGridKFRSTabVwTS->Index] = ssTS;

		ssMRP = OEMtoAL(zpkfrs.mrp, sizeof(zpkfrs.mrp));
		dc->Values[ii][cxGridKFRSTabVwMRP->Index] = ssMRP;

		ssSUBS = OEMtoAL(zpkfrs.subs, sizeof(zpkfrs.subs));
		dc->Values[ii][cxGridKFRSTabVwSUBS->Index] = ssSUBS;

		ssCELS = OEMtoAL(zpkfrs.cels, sizeof(zpkfrs.cels));
		dc->Values[ii][cxGridKFRSTabVwCELS->Index] = ssCELS;
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::cxGridKFRSEnter(TObject *Sender) {
	aExit->Enabled = false;
	aExit->Visible = false;
	aExit->ShortCut = 0;

	if (prKor) {
		if (dtprKor) {
			aNew->Visible = true;
			aNew->Enabled = true;
			aKor->Visible = true;
			aKor->Enabled = true;
			aDel->Visible = true;
			aDel->Enabled = true;
		}
	}
	aOk->Enabled = true;
	aOk->Visible = true;

	if (cxGridKFRSTabVw->DataController->RecordCount == 0) {
		aDel->Visible = false;
		aDel->Enabled = false;
		cxGridKFRS->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::cxGridKFRSTabVwMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
		TPoint &MousePos, bool &Handled) {
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

void __fastcall TfrSp0017::aKorExecute(TObject *Sender) {

	int n;
//	ushort nkdkfr;

	TcxGridDataController* dc = cxGridKFRSTabVw->DataController;

	dxaKor->Enabled = true;
	dxaKor->Visible = true;
	prNew = 0;

	if (dc->RecordCount > 0) {
		n = dc->FocusedRecordIndex;
//		nkdkfr = (unsigned short)dc->Values[n][frSp0017->cxGridKFRSTabVwNPP->Index];
		dxaKor->Visible = true;

		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwKER->Index])) {
			EDker->Text = dc->Values[n][cxGridKFRSTabVwKER->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwISF->Index])) {
			EDisf->Text = dc->Values[n][cxGridKFRSTabVwISF->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwSBKER->Index])) {
			EDsbker->Text = dc->Values[n][cxGridKFRSTabVwSBKER->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwTF->Index])) {
			EDtf->Text = dc->Values[n][cxGridKFRSTabVwTF->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwTS->Index])) {
			EDts->Text = dc->Values[n][cxGridKFRSTabVwTS->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwMRP->Index])) {
			EDmrp->Text = dc->Values[n][cxGridKFRSTabVwMRP->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwSUBS->Index])) {
			EDsubs->Text = dc->Values[n][cxGridKFRSTabVwSUBS->Index];
		}
		if (!VarIsNull(dc->Values[n][cxGridKFRSTabVwCELS->Index])) {
			EDcels->Text = dc->Values[n][cxGridKFRSTabVwCELS->Index];
		}
		npp = dc->Values[n][cxGridKFRSTabVwNPP->Index];
		EDker->SetFocus();
		dxTable->Enabled = false;
		dxDate->Enabled = false;
	} // record count
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::aNewExecute(TObject *Sender) {
	prNew = 1;

//	int n, ii;
//	ushort nkdkfr;

	TcxGridDataController* dc = cxGridKFRSTabVw->DataController;

	dxaKor->Enabled = true;
	dxaKor->Visible = true;

	if (dc->RecordCount > 0) {
//		n = dc->FocusedRecordIndex;
//		nkdkfr = (unsigned short)dc->Values[n][frSp0017->cxGridKFRSTabVwNPP->Index];
		dxaKor->Visible = true;

		EDker->Text = "";
		EDisf->Text = "";
		EDsbker->Text = "";
		EDtf->Text = "";
		EDts->Text = "";
		EDmrp->Text = "";
		EDsubs->Text = "";
		EDcels->Text = "";

		EDker->SetFocus();
		dxTable->Enabled = false;
		dxDate->Enabled = false;
	} // record count
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::aDelExecute(TObject *Sender) {

	AnsiString ss;
	struct fdate rfd;
	bool prDel;
	ushort rkdkfr, rr;
	int n;
	struct zpkfr kfr;
	FCB fkfr;

	fkfr = fafonc(c_p->b_nc, "zpkfr");
	TcxGridDataController* dc = cxGridKFRSTabVw->DataController;
	TcxCustomDataController* dCus = frSp0017->cxGridKFRSTabVw->DataController;
	aDel->Enabled = false;
	aDel->Visible = false;
	if (dc->RecordCount > 0) {
		if (armerr(-1, "Удалить запись ?") == 0) {
			n = dc->FocusedRecordIndex;
			rr = (unsigned short)dc->Values[n][cxGridKFRSTabVwNPP->Index];
			swb(&rr, &rkdkfr, 2);
			prDel = true;
			CLR(kfr);
			swb(&nfdyy, &kfr.fdg, 2);
			while (fargl(fkfr, &kfr, sizeof(kfr)) == 0) {
				swb(&kfr.fdg, &rfd, 2);
				if (rfd.fd_yy == nfdyy.fd_yy) {
					if (kfr.npp == rkdkfr) {
						prDel = false;
						break;
					}
				}
			}
			if (prDel) {
				CLR(zpkfrs);
				swb(&nfdyy, &zpkfrs.fdg, 2);
				zpkfrs.npp = rkdkfr;
				if (farel(fzpkfrs, &zpkfrs, sizeof(zpkfrs)) == 0) {
					fard(fzpkfrs, &zpkfrs);
					dCus->DeleteRecord(n);
					if ((n - 1) != -1) {
						dc->FocusedRecordIndex = (n - 1);
					}
					else {;
					}
				}
			}
			else {
				armerr(2, "Используется !!! Удаление невозможно");
			}
		}

	}
	fafc(fkfr);
	aRefresh->Execute();
	aDel->Enabled = true;
	aDel->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::DBDateEdExit(TObject *Sender) {
	//
	unsigned short dd, mm, yy;

	if (!DBDateEd->EditValue.IsNull()) {
		if (prVspr == true) {
			dyy = VarToDateTime(DBDateEd->EditValue);
			DecodeDate(dyy, yy, mm, dd);
			nfdyy.fd_dd = 1;
			nfdyy.fd_mm = 1;
			nfdyy.fd_yy = yy - 1980;
			if (nfdyy.fd_yy <= b->uyy.yy) {
				dtprKor = true;
			}
			else {
				dtprKor = false;
			}

			if (cmp(&fdkfr, &nfdyy, 2) != 0) {
				aRefresh->Execute();
			}
		}
		else {
			DBDateEd->EditValue = EncodeDate(fdkfr.fd_yy + 1980, 1, 1);
			aRefresh->Execute();
		}
	}
	else {
		DBDateEd->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::DBDateEdEnter(TObject *Sender) {
	unsigned short dd, mm, yy;

	if (!DBDateEd->EditValue.IsNull()) {
		dyy = VarToDateTime(DBDateEd->EditValue);
		DecodeDate(dyy, yy, mm, dd);
		fdkfr.fd_dd = 1;
		fdkfr.fd_mm = 1;
		fdkfr.fd_yy = yy - 1980;
	}
	aExit->Enabled = true;
	aExit->Visible = true;
	aExit->ShortCut = VK_ESCAPE;

}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::cxGridKFRSTabVwKeyPress(TObject *Sender, char &Key) {
	if (prVspr) {
		if (Key == VK_ESCAPE) {
			Key = 0;
			DBDateEd->SetFocus();
		}
	}
	else {
		if (Key == VK_ESCAPE) {
			aRet = 0;
			Close();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::cxGridKFRSExit(TObject *Sender) {
	aNew->Visible = false;
	aNew->Enabled = false;
	aKor->Visible = false;
	aKor->Enabled = false;
	aDel->Visible = false;
	aDel->Enabled = false;
	aOk->Enabled = false;
	aOk->Visible = false;

}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::cxGridKFRSTabVwDblClick(TObject *Sender) {
	aOk->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDkerPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	struct spker ker;
	char rss[100];

	if (AButtonIndex == 1) {
		EDker->Text = "";
		EDker->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRKESR", &rss);
		EDker->Text = rss;
/*
		CLR(ker);
		if (l_call("ZPSPR1", "GKER", &ker) == 1) {
			EDker->Text = OEMtoAL(ker.ker, sizeof(ker.ker));
		}
*/
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDisfPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[100];
	struct spisf isf;

	if (AButtonIndex == 1) {
		EDisf->Text = "";
		EDisf->SetFocus();
	}
	else {
		char rss[100];
		l_call("BDW", "SPRDB", &rss);
		EDisf->Text = rss;
/*
		CLR(isf);
		if (l_call("ZPSPR1", "GISF", &isf) == 1) {
			EDisf->Text = OEMtoAL(isf.isf, sizeof(isf.isf));
		}
*/
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDsbkerPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[100];
	struct spsbker sbker;

	if (AButtonIndex == 1) {
		EDsbker->Text = "";
		EDsbker->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRSKESR", &rss);
		CLR(sbker);
    EDsbker->Text = rss;
/*
		if (l_call("ZPSPR1", "GSBKER", &sbker) == 1) {
			EDsbker->Text = OEMtoAL(sbker.subkesr, sizeof(sbker.subkesr));
		}
*/
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDtfPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[100];
	struct sptf tf;

	if (AButtonIndex == 1) {
		EDtf->Text = "";
		EDtf->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRTPF", &rss);
		EDtf->Text = rss;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDtsPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[100];
	struct spts ts;

	if (AButtonIndex == 1) {
		EDts->Text = "";
		EDts->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRTPS", &rss);
		EDts->Text = rss;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDmrpPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[100];
	struct spmrp mrp;

	if (AButtonIndex == 1) {
		EDmrp->Text = "";
		EDmrp->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRMR", &rss);
		EDmrp->Text = rss;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::aCancel(TObject *Sender) {
	dxaKor->Visible = false;
	dxTable->Enabled = true;
	dxDate->Enabled = true;

	aNew->Enabled = true;
	aDel->Enabled = true;
	aKor->Enabled = true;
	aNewCopy->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	aPrnStr->Enabled = true;
	cxGridKFRS->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::aSaveExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGridKFRSTabVw->DataController;
	int ii;
	char s[10];
//	bool Ok = true;
	ii = dc->FocusedRecordIndex;
	struct zpkfrs skfrs;

	fzpkfrs = fafonc(c_p->b_nc, "zpkfrs");

	if (prNew == 1) {
		CLR(skfrs);
		setmem(&skfrs, 4, 0xFF);
		farl(fzpkfrs, &skfrs);
		swb(&skfrs.npp, &npp, 2);
		npp++;
	}
	CLR(skfrs);
	swb(&nfdyy, &skfrs.fdg, 2);
	swb(&npp, &skfrs.npp, 2);
	MVCTOL(UnToFm(EDker->Text.w_str(), PgWin), skfrs.ker, sizeof(skfrs.ker));
	MVCTOL(UnToFm(EDisf->Text.w_str(), PgWin), skfrs.isf, sizeof(skfrs.isf));
	MVCTOL(UnToFm(EDsbker->Text.w_str(), PgWin), skfrs.sbker, sizeof(skfrs.sbker));
	MVCTOL(UnToFm(EDtf->Text.w_str(), PgWin), skfrs.tf, sizeof(skfrs.tf));
	MVCTOL(UnToFm(EDts->Text.w_str(), PgWin), skfrs.ts, sizeof(skfrs.ts));
	MVCTOL(UnToFm(EDmrp->Text.w_str(), PgWin), skfrs.mrp, sizeof(skfrs.mrp));
	MVCTOL(UnToFm(EDsubs->Text.w_str(), PgWin), skfrs.subs, sizeof(skfrs.subs));
	MVCTOL(UnToFm(EDcels->Text.w_str(), PgWin), skfrs.cels, sizeof(skfrs.cels));

	farwl(fzpkfrs, &skfrs, sizeof(skfrs));
	fafc(fzpkfrs);

	dxaKor->Enabled = false;
	dxaKor->Visible = false;
	dxTable->Enabled = true;
	dxDate->Enabled = true;

	aNew->Enabled = true;
	aDel->Enabled = true;
	aKor->Enabled = true;
	aExit->Enabled = true;
	aKor->Enabled = true;
	aNewCopy->Enabled = true;
	aPrnStr->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	aRefresh->Execute();
	dc->FocusedRecordIndex = ii;
	cxGridKFRS->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfrSp0017::EDsubsPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[10];

	if (AButtonIndex == 1) {
		EDsubs->Text = "";
		EDsubs->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRSUBS", &rss);
		EDsubs->Text = rss;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSp0017::EDcelsPropertiesButtonClick(TObject *Sender, int AButtonIndex)

{
	char rss[10];

	if (AButtonIndex == 1) {
		EDcels->Text = "";
		EDcels->SetFocus();
	}
	else {
		CLR(rss);
		l_call("BDW", "SPRCS", &rss);
		EDcels->Text = rss;
	}
}
// ---------------------------------------------------------------------------
