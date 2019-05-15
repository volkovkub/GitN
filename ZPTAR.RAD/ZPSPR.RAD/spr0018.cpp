// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"

#include "spr0017.h"
#include "spr0018.h"
#include "SpKfrEd.h"
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
TfrSpKfr *frSpKfr;

// ---------------------------------------------------------------------------
__fastcall TfrSpKfr::TfrSpKfr(TComponent* Owner) : Tfraspr03(Owner) {
	aRefresh->Hint = "Обновить данные по шаблону";
	aRefresh->Caption = "Обновить данные по шаблону";
}

// ---------------------------------------------------------------------------
int IniSpr0018(int Vspr, struct zpsppar *par, struct fdate *fdpar) {
	int ret = -1;
	ushort rr;

	frSpKfr = new TfrSpKfr(Application);
	try {
		frSpKfr->dxLCGroupED->Visible = false;
		frSpKfr->b = (struct bsp*)c_p->b_sp;
		frSpKfr->fcnst = fafo(c_p->b_zp, "const");
		frSpKfr->prKor = true;

		CLR(frSpKfr->cnst);
		strcpy(frSpKfr->cnst.n, "KLIENT");
		if (fare(frSpKfr->fcnst, &frSpKfr->cnst) == 0) {
			if (strcmp(frSpKfr->cnst.ct, "1") == 0) {
				frSpKfr->prKor = false;
			}
		}
		fafc(frSpKfr->fcnst);
		if (frSpKfr->prKor == true) {
			if (frSpKfr->b->sts[4] == '8') {
				frSpKfr->prKor = true; // корректировка разрешена
			}
			else {
				frSpKfr->prKor = false; // корректировка запрещена
			}
		}
		frSpKfr->fdkfr.fd_dd = 1;
		frSpKfr->fdkfr.fd_mm = 1;
		frSpKfr->fdkfr.fd_yy = fdpar->fd_yy;
		frSpKfr->nfdyy.fd_dd = 1;
		frSpKfr->nfdyy.fd_mm = 1;
		frSpKfr->nfdyy.fd_yy = fdpar->fd_yy;

		if (frSpKfr->nfdyy.fd_yy <= frSpKfr->b->uyy.yy) {
			frSpKfr->dtprKor = true;
		}
		else {
			frSpKfr->dtprKor = false;
		}
		frSpKfr->DBDateEd->EditValue = EncodeDate(frSpKfr->fdkfr.fd_yy + 1980, 1, 1);
		frSpKfr->fpstzn = fafonc(c_p->b_nc, "zppstzn");
		frSpKfr->fzpkfr = fafonc(c_p->b_nc, "zpkfr");
		frSpKfr->fkfrs = fafonc(c_p->b_nc, "zpkfrs");
		frSpKfr->fop = fafonc(c_p->b_nc, "spop");

		if ((int &)Vspr == 1) {
			frSpKfr->prVspr = true;
			frSpKfr->DBDateEd->Enabled = true;
		}
		if ((int &)Vspr == 0) {
			frSpKfr->prVspr = false;
			frSpKfr->DBDateEd->Enabled = false;
		}
		frSpKfr->aPrnStr->Execute();
		frSpKfr->ShowModal();
		ret = frSpKfr->aRet;
		if (ret == 1) {
			TcxGridDataController* dc = frSpKfr->cxGridKFRTabVw->DataController;
			rr = (unsigned short)dc->Values[dc->FocusedRecordIndex][frSpKfr->cxGridKFRTabVwKDKFR->Index];
			par->par1 = rr;
			CLR(par->nm);
			CLR(par->nm1);
		}
	}
	catch (...) {
	}
	fafc(frSpKfr->fpstzn);
	fafc(frSpKfr->fzpkfr);
	fafc(frSpKfr->fop);
	delete frSpKfr;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSpKfr::aRefreshExecute(TObject *Sender) {

	if (armerr(-1, "Обновить данные по шаблону ?") == 0) {
		swb(&nfdyy, &fdfl, 2);
		CLR(zpkfr);
		swb(&nfdyy, &zpkfr.fdg, 2);
		while (fargl(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0 && cmp(&zpkfr.fdg, &fdfl, 2) == 0) {
			CLR(kfrs);
			swb(&nfdyy, &kfrs.fdg, 2);
			kfrs.npp = zpkfr.npp;
			if (farel(fkfrs, &kfrs, sizeof(kfrs)) == 0) {
				mov(&kfrs.ker, &zpkfr.ker, sizeof(zpkfr.ker));
				mov(&kfrs.sbker, &zpkfr.sbker, sizeof(zpkfr.sbker));
				mov(&kfrs.isf, &zpkfr.isf, sizeof(zpkfr.isf));
				mov(&kfrs.tf, &zpkfr.tf, sizeof(zpkfr.tf));
				mov(&kfrs.ts, &zpkfr.ts, sizeof(zpkfr.ts));
				mov(&kfrs.mrp, &zpkfr.mrp, sizeof(zpkfr.mrp));
				mov(&kfrs.subs, &zpkfr.subs, sizeof(zpkfr.subs));
				mov(&kfrs.cels, &zpkfr.cels, sizeof(zpkfr.cels));
				farwl(fzpkfr, &zpkfr, sizeof(zpkfr));
			}
		}
		aPrnStr->Execute();
	}
	/*
	 int ii;
	 AnsiString ssKER, ssSBKER, ssISF, ssTF, ssTS, ssMRP, ssBSD, ssBSK;
	 ushort kdkfr, ko, npp;
	 char bsd[10], bsk[10];

	 TcxGridDataController* dc = cxGridKFRTabVw->DataController;

	 if (dc->RecordCount != 0) {
	 cxGridKFRTabVw->OptionsSelection->MultiSelect = true;
	 dc->SelectAll();
	 dc->DeleteSelection();
	 }
	 cxGridKFRTabVw->OptionsSelection->MultiSelect = false;

	 dc->BeginFullUpdate();
	 swb(&nfdyy, &fdfl, 2);
	 CLR(zpkfr);
	 swb(&nfdyy, &zpkfr.fdg, 2);
	 while (fargl(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0 && cmp(&zpkfr.fdg, &fdfl,
	 2) == 0) {
	 ii = dc->AppendRecord();
	 swb(&zpkfr.kdkfr, &kdkfr, 2);
	 swb(&zpkfr.ko, &ko, 2);

	 dc->Values[ii][cxGridKFRTabVwKDKFR->Index] = kdkfr;
	 dc->Values[ii][cxGridKFRTabVwKD->Index] = zpkfr.kd;
	 dc->Values[ii][cxGridKFRTabVwKO->Index] = ko;
	 dc->Values[ii][cxGridKFRTabVwKS->Index] = zpkfr.ks;

	 ssKER = OEMtoAL(zpkfr.ker, sizeof(zpkfr.ker));
	 dc->Values[ii][cxGridKFRTabVwKER->Index] = ssKER;

	 ssSBKER = OEMtoAL(zpkfr.sbker, sizeof(zpkfr.sbker));
	 dc->Values[ii][cxGridKFRTabVwSBKER->Index] = ssSBKER;

	 ssISF = OEMtoAL(zpkfr.isf, sizeof(zpkfr.isf));
	 dc->Values[ii][cxGridKFRTabVwISF->Index] = ssISF;

	 ssTF = OEMtoAL(zpkfr.tf, sizeof(zpkfr.tf));
	 dc->Values[ii][cxGridKFRTabVwTF->Index] = ssTF;

	 ssTS = OEMtoAL(zpkfr.ts, sizeof(zpkfr.ts));
	 dc->Values[ii][cxGridKFRTabVwTS->Index] = ssTS;

	 ssMRP = OEMtoAL(zpkfr.mrp, sizeof(zpkfr.mrp));
	 dc->Values[ii][cxGridKFRTabVwMRP->Index] = ssMRP;

	 dc->Values[ii][cxGridKFRTabVwSUBS->Index] =
	 OEMtoAL(zpkfr.subs, sizeof(zpkfr.subs));
	 dc->Values[ii][cxGridKFRTabVwCELS->Index] =
	 OEMtoAL(zpkfr.cels, sizeof(zpkfr.cels));
	 swb(&zpkfr.npp, &npp, 2);
	 dc->Values[ii][cxGridKFRTabVwNPP->Index] = npp;

	 CLR(bsd);
	 CLR(bsk);

	 CLR(op);
	 op.kd = zpkfr.kd;
	 op.ko = zpkfr.ko;
	 op.ks = zpkfr.ks;
	 if (farel(fop, &op, sizeof(op)) == 0) {
	 CLR(bsn);
	 mov(&op.srd, &bsn, 6);
	 l_call("put_bs", " ", &bsn, bsd, 10);
	 ssBSD = OEMtoAL(bsd, sizeof(bsd));
	 dc->Values[ii][cxGridKFRTabVwBSD->Index] = ssBSD;
	 mov(&op.srk, &bsn, 6);
	 l_call("put_bs", " ", &bsn, bsk, 10);
	 ssBSK = OEMtoAL(bsk, sizeof(bsk));
	 dc->Values[ii][cxGridKFRTabVwBSK->Index] = ssBSK;
	 }

	 }
	 dc->EndFullUpdate();
	 dc->FocusedRecordIndex = 0;
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxGridKFREnter(TObject *Sender) {
	aExit->Enabled = false;
	aExit->Visible = false;
	aExit->ShortCut = 0;

	if (prKor) {
		if (dtprKor) {
			aRefresh->Visible = true;
			aRefresh->Enabled = true;
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

	if (cxGridKFRTabVw->DataController->RecordCount == 0) {
		aDel->Visible = false;
		aDel->Enabled = false;
		cxGridKFR->RootLevelOptions->DetailFrameWidth = 2;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxGridKFRTabVwMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos,
		bool &Handled) {
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

void __fastcall TfrSpKfr::cxGridKFRTabVwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::aKorExecute(TObject *Sender) {
	//
	int n;
	ushort  rr;

	TcxGridDataController* dc = cxGridKFRTabVw->DataController;
	if (dc->RecordCount > 0) {
		DBDateEd->Enabled = false;
		n = dc->FocusedRecordIndex;
		//nkdkfr = (unsigned short)dc->Values[n][cxGridKFRTabVwKDKFR->Index];
		dxLCGroupED->Visible = true;
		cxBtEdBSD->Clear();
		cxBtEdBSK->Clear();
		cxBtSpr->Clear();
		cxTxtEDker->Clear();
		cxTxtEDisf->Clear();
		cxTxtEDsbker->Clear();
		cxTxtEDtf->Clear();
		cxTxtEDts->Clear();
		cxTxtEDmrp->Clear();
		EDsubs->Clear();
		EDcels->Clear();
		// frSpKfr->op.kd=(uchar)dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index];

		if (!dc->Values[n][cxGridKFRTabVwKD->Index].IsNull())
			cxTxtEdKD->Text = (uchar)dc->Values[n][cxGridKFRTabVwKD->Index];
		if (!dc->Values[n][cxGridKFRTabVwKO->Index].IsNull())
			cxTxtEdKO->Text = (ushort)dc->Values[n][cxGridKFRTabVwKO->Index];
		if (!dc->Values[n][cxGridKFRTabVwKS->Index].IsNull())
			cxTxtEdKS->Text = (uchar)dc->Values[n][cxGridKFRTabVwKS->Index];
		if (!dc->Values[n][cxGridKFRTabVwBSD->Index].IsNull())
			cxBtEdBSD->Text = dc->Values[n][cxGridKFRTabVwBSD->Index];
		if (!dc->Values[n][cxGridKFRTabVwBSK->Index].IsNull())
			cxBtEdBSK->Text = dc->Values[n][cxGridKFRTabVwBSK->Index];
		cxBtEdBSD->SetFocus();
		if (!dc->Values[n][cxGridKFRTabVwNPP->Index].IsNull()) {
			cxBtSpr->Text = dc->Values[n][cxGridKFRTabVwNPP->Index];
			rr = dc->Values[n][cxGridKFRTabVwNPP->Index];
			CLR(kfrs);
			swb(&nfdyy, &kfrs.fdg, 2);
			swb(&rr, &kfrs.npp, 2);
			farel(fkfrs, &kfrs, sizeof(kfrs));
			cxTxtEDker->Text = OEMtoAL(kfrs.ker, sizeof(kfrs.ker));
			cxTxtEDisf->Text = OEMtoAL(kfrs.isf, sizeof(kfrs.isf));
			cxTxtEDsbker->Text = OEMtoAL(kfrs.sbker, sizeof(kfrs.sbker));
			cxTxtEDsbker->Text = OEMtoAL(kfrs.sbker, sizeof(kfrs.sbker));
			cxTxtEDtf->Text = OEMtoAL(kfrs.tf, sizeof(kfrs.tf));
			cxTxtEDts->Text = OEMtoAL(kfrs.ts, sizeof(kfrs.ts));
			cxTxtEDmrp->Text = OEMtoAL(kfrs.mrp, sizeof(kfrs.mrp));
			EDsubs->Text = OEMtoAL(kfrs.subs, sizeof(kfrs.subs));
			EDcels->Text = OEMtoAL(kfrs.cels, sizeof(kfrs.cels));
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::aNewExecute(TObject *Sender) {
	int jj = -1;
	int LL;
	ushort ii;

	hold(c_p->b_nc, "zpkfr");
	CLR(zpkfr);
	swb(&nfdyy, &zpkfr.fdg, 2);
	for (ii = 1; ii < 65000; ii++) {
		jj = 0;
		swb(&ii, &zpkfr.kdkfr, 2);
		if (farel(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0) {
			jj = -1;
		}
		else {
			break;
		}
	}
	unhold(c_p->b_nc, "zpkfr");
	if (jj == 0) {
		CLR(zpkfr);
		swb(&nfdyy, &zpkfr.fdg, 2);
		swb(&ii, &zpkfr.kdkfr, 2);
		farwl(fzpkfr, &zpkfr, sizeof(zpkfr));

		TcxGridDataController* dc = cxGridKFRTabVw->DataController;
		LL = dc->AppendRecord();
		dc->Values[LL][cxGridKFRTabVwKDKFR->Index] = ii;
		dc->FocusedRecordIndex = LL;

		// IniSpKfrEd(Kor,ii,(fdate*)&nfdyy);
	}
	else {
		armerr(1, "Ошибка создания нового кода !!!");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::aDelExecute(TObject *Sender) {
	//
	AnsiString ss;
	struct fdate rfd;
	bool prDel;
	ushort rkdkfr, rr;
	int n;
	TcxGridDataController* dc = cxGridKFRTabVw->DataController;
	TcxCustomDataController* dCus = cxGridKFRTabVw->DataController;
	aDel->Enabled = false;
	aDel->Visible = false;
	if (dc->RecordCount > 0) {
		if (armerr(-1, "Удалить запись ?") == 0) {
			n = dc->FocusedRecordIndex;
			rr = (unsigned short)dc->Values[n][cxGridKFRTabVwKDKFR->Index];
			swb(&rr, &rkdkfr, 2);
			prDel = true;
			CLR(pstzn);
			swb(&nfdyy, &pstzn.fd, 2);
			while (fargl(fpstzn, &pstzn, sizeof(pstzn)) == 0) {
				swb(&pstzn.fd, &rfd, 2);
				if (rfd.fd_yy == nfdyy.fd_yy) {
					if (pstzn.kdkfr == rkdkfr) {
						prDel = false;
						break;
					}
				}
			}
			if (prDel) {
				CLR(zpkfr);
				swb(&nfdyy, &zpkfr.fdg, 2);
				zpkfr.kdkfr = rkdkfr;
				if (farel(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0) {
					fard(fzpkfr, &zpkfr);
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
	aDel->Enabled = true;
	aDel->Visible = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::DBDateEdExit(TObject *Sender) {
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
				aPrnStr->Execute();
			}
		}
		else {
			DBDateEd->EditValue = EncodeDate(fdkfr.fd_yy + 1980, 1, 1);
			// aRefresh->Execute();
		}
	}
	else {
		DBDateEd->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::DBDateEdEnter(TObject *Sender) {
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

void __fastcall TfrSpKfr::cxGridKFRTabVwKeyPress(TObject *Sender, char &Key) {
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

void __fastcall TfrSpKfr::DBDateEdKeyPress(TObject *Sender, char &Key) {
/*	if (Key == VK_RETURN) {
		if (!DBDateEd->CalendarVisible) {
			SelectNext(ActiveControl, true, true);
		}
	}*/
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxGridKFRExit(TObject *Sender) {
	aNew->Visible = false;
	aNew->Enabled = false;
	aRefresh->Visible = false;
	aRefresh->Enabled = false;
	aKor->Visible = false;
	aKor->Enabled = false;
	aDel->Visible = false;
	aDel->Enabled = false;
	aOk->Enabled = false;
	aOk->Visible = false;

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxGridKFRTabVwDblClick(TObject *Sender) {
	aOk->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxBtEdBSDPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	//
	char bsd[10], bsk[10];
	ushort ko;
	CLR(bsd);
	CLR(bsk);

	CLR(op);
	op.kd = 85;
	if (l_call("G_OPN", "GOP", &op, 1) != -1) {
		CLR(bsn);
		mov(&op.srd, &bsn, 6);
		l_call("put_bs", " ", &bsn, bsd, 10);
		cxBtEdBSD->Text = OEMtoAL(bsd, sizeof(bsd));
		mov(&op.srk, &bsn, 6);
		l_call("put_bs", " ", &bsn, bsk, 10);
		cxBtEdBSK->Text = OEMtoAL(bsk, sizeof(bsk));

		cxTxtEdKD->Text = op.kd;
		swb(&op.ko, &ko, 2);
		cxTxtEdKO->Text = ko;
		cxTxtEdKS->Text = op.ks;
	}
	cxBtEdBSK->SetFocus();

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxBtSprPropertiesButtonClick(TObject *Sender, int AButtonIndex) {
	//
	short rr;

	CLR(kfrs);
	swb(&nfdyy, &kfrs.fdg, 2);
	if (cxBtSpr->Text.Length() > 0) {
		kfrs.npp = StrToIntDef(cxBtSpr->Text, 0);
	}
	if ((rr = IniSpr0017(0, &kfrs, &nfdyy)) != -1) {
		cxBtSpr->Text = rr;
		CLR(kfrs);
		swb(&nfdyy, &kfrs.fdg, 2);
		swb(&rr, &kfrs.npp, 2);
		farel(fkfrs, &kfrs, sizeof(kfrs));
		cxTxtEDker->Text = OEMtoAL(kfrs.ker, sizeof(kfrs.ker));
		cxTxtEDisf->Text = OEMtoAL(kfrs.isf, sizeof(kfrs.isf));
		cxTxtEDsbker->Text = OEMtoAL(kfrs.sbker, sizeof(kfrs.sbker));
		cxTxtEDsbker->Text = OEMtoAL(kfrs.sbker, sizeof(kfrs.sbker));
		cxTxtEDtf->Text = OEMtoAL(kfrs.tf, sizeof(kfrs.tf));
		cxTxtEDts->Text = OEMtoAL(kfrs.ts, sizeof(kfrs.ts));
		cxTxtEDmrp->Text = OEMtoAL(kfrs.mrp, sizeof(kfrs.mrp));
		EDsubs->Text = OEMtoAL(kfrs.subs, sizeof(kfrs.subs));
		EDcels->Text = OEMtoAL(kfrs.cels, sizeof(kfrs.cels));
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxBtCancelClick(TObject *Sender) {
	DBDateEd->Enabled = true;
	cxGridKFR->SetFocus();
	dxLCGroupED->Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpKfr::cxBtOkClick(TObject *Sender) {
	//
	int n;
	ushort nkdkfr, rr, ko, npp;
	char dss[100];
	AnsiString Rss;

	TcxGridDataController* dc = cxGridKFRTabVw->DataController;
	if (dc->RecordCount > 0) {
		n = dc->FocusedRecordIndex;
		nkdkfr = (unsigned short)dc->Values[n][cxGridKFRTabVwKDKFR->Index];

		CLR(zpkfr);
		swb(&nfdyy, &zpkfr.fdg, 2);
		swb(&nkdkfr, &zpkfr.kdkfr, 2);
		if (farel(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0) {
			zpkfr.kd = (uchar)cxTxtEdKD->Text.ToIntDef(0);
			ko = (unsigned short)cxTxtEdKO->Text.ToIntDef(0);
			swb(&ko, &zpkfr.ko, 2);
			zpkfr.ks = (uchar)cxTxtEdKS->Text.ToIntDef(0);
			npp = (unsigned short)cxBtSpr->Text.ToIntDef(0);
			swb(&npp, &zpkfr.npp, 2);

			CLR(dss);
			Rss = cxTxtEDker->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.ker);

			CLR(dss);
			Rss = cxTxtEDsbker->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.sbker);

			CLR(dss);
			Rss = cxTxtEDisf->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.isf);

			CLR(dss);
			Rss = cxTxtEDtf->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.tf);

			CLR(dss);
			Rss = cxTxtEDts->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.ts);

			CLR(dss);
			Rss = cxTxtEDmrp->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.mrp);

			CLR(dss);
			Rss = EDsubs->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.subs);

			CLR(dss);
			Rss = EDcels->Text;
			strcat(dss, Rss.c_str());
			MV(dss, zpkfr.cels);

			farwl(fzpkfr, &zpkfr, sizeof(zpkfr));
			dc->Edit();
			if (!VarIsNull(AS(cxTxtEdKD->Text)))
				dc->Values[n][cxGridKFRTabVwKD->Index] = cxTxtEdKD->Text;
			if (!VarIsNull(cxTxtEdKO->Text))
				dc->Values[n][cxGridKFRTabVwKO->Index] = cxTxtEdKO->Text;
			if (!VarIsNull(cxTxtEdKS->Text))
				dc->Values[n][cxGridKFRTabVwKS->Index] = cxTxtEdKS->Text;
			if (!VarIsNull(cxBtEdBSD->Text))
				dc->Values[n][cxGridKFRTabVwBSD->Index] = cxBtEdBSD->Text;
			if (!VarIsNull(cxBtEdBSK->Text))
				dc->Values[n][cxGridKFRTabVwBSK->Index] = cxBtEdBSK->Text;
			if (!VarIsNull(cxTxtEDker->Text))
				dc->Values[n][cxGridKFRTabVwKER->Index] = cxTxtEDker->Text;
			if (!VarIsNull(cxTxtEDisf->Text))
				dc->Values[n][cxGridKFRTabVwISF->Index] = cxTxtEDisf->Text;
			if (!VarIsNull(cxTxtEDsbker->Text))
				dc->Values[n][cxGridKFRTabVwSBKER->Index] = cxTxtEDsbker->Text;
			if (!VarIsNull(cxTxtEDtf->Text))
				dc->Values[n][cxGridKFRTabVwTF->Index] = cxTxtEDtf->Text;
			if (!VarIsNull(cxTxtEDts->Text))
				dc->Values[n][cxGridKFRTabVwTS->Index] = cxTxtEDts->Text;
			if (!VarIsNull(cxTxtEDmrp->Text))
				dc->Values[n][cxGridKFRTabVwMRP->Index] = cxTxtEDmrp->Text;
			if (!VarIsNull(cxTxtEDmrp->Text))
				dc->Values[n][cxGridKFRTabVwMRP->Index] = cxTxtEDmrp->Text;
			if (!VarIsNull(EDsubs->Text))
				dc->Values[n][cxGridKFRTabVwSUBS->Index] = EDsubs->Text;
			if (!VarIsNull(EDcels->Text))
				dc->Values[n][cxGridKFRTabVwCELS->Index] = EDcels->Text;
			if (!VarIsNull(cxBtSpr->Text))
				dc->Values[n][cxGridKFRTabVwNPP->Index] = cxBtSpr->Text;
			dc->Post();
		}
	}
	DBDateEd->Enabled = true;
	cxGridKFR->SetFocus();
	dxLCGroupED->Visible = false;

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpKfr::aPrnStrExecute(TObject *Sender) {
	int ii;
	AnsiString ssKER, ssSBKER, ssISF, ssTF, ssTS, ssMRP, ssBSD, ssBSK;
	ushort kdkfr, ko, npp;
	char bsd[10], bsk[10];

	TcxGridDataController* dc = cxGridKFRTabVw->DataController;

	if (dc->RecordCount != 0) {
		cxGridKFRTabVw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
	}
	cxGridKFRTabVw->OptionsSelection->MultiSelect = false;

	dc->BeginFullUpdate();
	swb(&nfdyy, &fdfl, 2);
	CLR(zpkfr);
	swb(&nfdyy, &zpkfr.fdg, 2);
	while (fargl(fzpkfr, &zpkfr, sizeof(zpkfr)) == 0 && cmp(&zpkfr.fdg, &fdfl, 2) == 0) {
		ii = dc->AppendRecord();
		swb(&zpkfr.kdkfr, &kdkfr, 2);
		swb(&zpkfr.ko, &ko, 2);

		dc->Values[ii][cxGridKFRTabVwKDKFR->Index] = kdkfr;
		dc->Values[ii][cxGridKFRTabVwKD->Index] = zpkfr.kd;
		dc->Values[ii][cxGridKFRTabVwKO->Index] = ko;
		dc->Values[ii][cxGridKFRTabVwKS->Index] = zpkfr.ks;

		ssKER = OEMtoAL(zpkfr.ker, sizeof(zpkfr.ker));
		dc->Values[ii][cxGridKFRTabVwKER->Index] = ssKER;

		ssSBKER = OEMtoAL(zpkfr.sbker, sizeof(zpkfr.sbker));
		dc->Values[ii][cxGridKFRTabVwSBKER->Index] = ssSBKER;

		ssISF = OEMtoAL(zpkfr.isf, sizeof(zpkfr.isf));
		dc->Values[ii][cxGridKFRTabVwISF->Index] = ssISF;

		ssTF = OEMtoAL(zpkfr.tf, sizeof(zpkfr.tf));
		dc->Values[ii][cxGridKFRTabVwTF->Index] = ssTF;

		ssTS = OEMtoAL(zpkfr.ts, sizeof(zpkfr.ts));
		dc->Values[ii][cxGridKFRTabVwTS->Index] = ssTS;

		ssMRP = OEMtoAL(zpkfr.mrp, sizeof(zpkfr.mrp));
		dc->Values[ii][cxGridKFRTabVwMRP->Index] = ssMRP;

		dc->Values[ii][cxGridKFRTabVwSUBS->Index] = OEMtoAL(zpkfr.subs, sizeof(zpkfr.subs));
		dc->Values[ii][cxGridKFRTabVwCELS->Index] = OEMtoAL(zpkfr.cels, sizeof(zpkfr.cels));
		swb(&zpkfr.npp, &npp, 2);
		dc->Values[ii][cxGridKFRTabVwNPP->Index] = npp;

		CLR(bsd);
		CLR(bsk);

		CLR(op);
		op.kd = zpkfr.kd;
		op.ko = zpkfr.ko;
		op.ks = zpkfr.ks;
		if (farel(fop, &op, sizeof(op)) == 0) {
			CLR(bsn);
			mov(&op.srd, &bsn, 6);
			l_call("put_bs", " ", &bsn, bsd, 10);
			ssBSD = OEMtoAL(bsd, sizeof(bsd));
			dc->Values[ii][cxGridKFRTabVwBSD->Index] = ssBSD;
			mov(&op.srk, &bsn, 6);
			l_call("put_bs", " ", &bsn, bsk, 10);
			ssBSK = OEMtoAL(bsk, sizeof(bsk));
			dc->Values[ii][cxGridKFRTabVwBSK->Index] = ssBSK;
		}
	}
	dc->EndFullUpdate();
	dc->FocusedRecordIndex = 0;
}
// ---------------------------------------------------------------------------
