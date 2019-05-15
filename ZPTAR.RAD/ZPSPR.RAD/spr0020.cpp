// ---------------------------------------------------------------------------
// Таблица входимости
// Власова М. 26.07.12
//BG 04/06/02018 - замена zpvvch1 на zpvvch2
// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

#include "spr0027.h"
#include "spr0031.h"
#include "frVi4et_1.h"
#include "spr0008.h"
#include "progress.h"

#include "..\SERVIS\armerrw.h"

extern struct compar *c_p;
#include "spr0020.h"
#include "PrBar.h"
#include "NSpNVSR.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
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
#pragma link "cxSpinEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxBar"
#pragma link "dxCore"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutControlAdapters"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxStatusBar"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma resource "*.dfm"
TfrSpr0020 *frSpr0020;
// ---------------------------------------------------------------------------
__fastcall TfrSpr0020::TfrSpr0020(TComponent* Owner) : Tfraspr03(Owner) {
}
// ---------------------------------------------------------------------------
int IniSpr0020() {
	int ret = -1;
//	AnsiString fName;
	try {
		frSpr0020 = new TfrSpr0020(Application);
		writebspzp(&frSpr0020->bzp);
		frSpr0020->b = (struct bsp*)c_p->b_sp;
		frSpr0020->dxLCKor->Visible = false;
		frSpr0020->ret = &ret;
		frSpr0020->Rkodknu="%2.2d.%2.2d";

 //		frSpr0020->llpos = 0;
		frSpr0020->fduyy.fd_dd = 1;
		frSpr0020->fduyy.fd_mm = frSpr0020->bzp.uyy.mm;
		frSpr0020->fduyy.fd_yy = frSpr0020->bzp.uyy.yy;
		swb(&frSpr0020->fduyy, &frSpr0020->fduyy_sw, 2);
	 //	swb(&frSpr0020->fduyy, &frSpr0020->fduyy_sw2, 2);
		frSpr0020->cxDE->Date = EncodeDate(frSpr0020->fduyy.fd_yy + 1980,
				frSpr0020->fduyy.fd_mm, frSpr0020->fduyy.fd_dd);

		frSpr0020->fcnst = fafo(c_p->b_zp, "const");

		frSpr0020->prKor = true;
		frSpr0020->aKor->Visible = true;
		frSpr0020->aKor->Enabled = true;
		frSpr0020->aNew->Visible = true;
		frSpr0020->aNew->Enabled = true;
		frSpr0020->aNewCopy->Visible = true;
		frSpr0020->aNewCopy->Enabled = true;
		frSpr0020->chek->Options->Editing = true;

		CLR(frSpr0020->cnst);
		strcpy(frSpr0020->cnst.n, "KLIENT");
		if (fare(frSpr0020->fcnst, &frSpr0020->cnst) == 0) {
			if (strcmp(frSpr0020->cnst.ct, "1") == 0) {
				frSpr0020->prKor = false;
				frSpr0020->aKor->Visible = false;
				frSpr0020->aKor->Enabled = false;
				frSpr0020->aNew->Visible = false;
				frSpr0020->aNew->Enabled = false;
				frSpr0020->aNewCopy->Visible = false;
				frSpr0020->aNewCopy->Enabled = false;
				frSpr0020->chek->Options->Editing = false;
			}
		}
		fafc(frSpr0020->fcnst);

		if (frSpr0020->prKor == true) {
			if (frSpr0020->b->sts[6] == '8') {
				frSpr0020->prKor = true; // корректировка разрешена
			}
			else {
				frSpr0020->aKor->Visible = false;
				frSpr0020->aKor->Enabled = false;
				frSpr0020->aNew->Visible = false;
				frSpr0020->aNew->Enabled = false;
				frSpr0020->aNewCopy->Visible = false;
				frSpr0020->aNewCopy->Enabled = false;
				frSpr0020->chek->Options->Editing = false;
				frSpr0020->prKor = false; // корректировка запрещена
			}
		}

		frSpr0020->aChek->Enabled = true;
		frSpr0020->aChek->Visible = true;

		frSpr0020->fknus = fafo(c_p->b_nc, "zpknus");
		frSpr0020->fmask = fafonc(c_p->b_nc, "zpmask");
		frSpr0020->fzpknu = fafo(c_p->b_nc, "zpknu");
		frSpr0020->fknu2 = fafo(c_p->b_nc, "zpknu2");
		frSpr0020->fpnal = fafonc(c_p->b_nc, "zppnal");
		frSpr0020->fnalvch = fafonc(c_p->b_nc, "zpnalvch");
		frSpr0020->fvsr = fafo(c_p->b_nc, "zpvsr");
		frSpr0020->fmaskf = fafonc(c_p->b_nc, "zpmaskf");
		frSpr0020->fvdoh = fafo(c_p->b_nc, "zpvdoh1");
		frSpr0020->fvvch = fafo(c_p->b_nc, "zpvvch2");

		frSpr0020->cxTE_N->Properties->MaxLength = sizeof(frSpr0020->knus.n) - 1;
		frSpr0020->start = true;
		frSpr0020->ShowModal();

		fafc(frSpr0020->fknus);
		fafc(frSpr0020->fzpknu);
		fafc(frSpr0020->fvsr);
		fafc(frSpr0020->fmaskf);
		fafc(frSpr0020->fmask);
		fafc(frSpr0020->fpnal);
		fafc(frSpr0020->fvdoh);
		fafc(frSpr0020->fknu2);
		fafc(frSpr0020->fvvch);
		fafc(frSpr0020->fnalvch);
		delete frSpr0020;
	}
	catch (...) {
	}


	return ret;
}
// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::aRefreshExecute(TObject *Sender) {
	//
//  cxGr1->BeginUpdate(lsimImmediate);
	TcxGridDataController* dc1 = Vw1->DataController;
	TcxGridDataController* dc2 = Vw2->DataController;
	TDateTime date;
	int ii;
 //	AnsiString fName;
	unsigned short dd, mm, yy;
	char Rmask[100];
	CLR(Rmask);
	if (dc2->RecordCount != 0) {
		Vw2->OptionsSelection->MultiSelect = true;
		dc2->SelectAll();
		dc2->DeleteSelection();
		Vw2->OptionsSelection->MultiSelect = false;
	}
	if (start) {
		ProgressBarForm = new TProgressBarForm(Application);
		ProgressBarForm->ProgressBar1->Position = 0;
		ProgressBarForm->ProgressBar1->Properties->Max = 500;
		ProgressBarForm->Show();

	}
	CLR(maskf);
	while (fargl(fmaskf, &maskf, sizeof(maskf)) == 0) {
		kol++;
	}

	cxG2->BeginUpdate(lsimImmediate);
	dc2->BeginFullUpdate();
	CLR(mask);
	while (fargl(fmask, &mask, sizeof(mask)) == 0) {

		ii = dc2->AppendRecord();
		dc2->Values[ii][chek->Index] = 0;
		dc2->Values[ii][mask_np->Index] = mask.np;
		dc2->Values[ii][mask_nm->Index] = FmToUn(mask.n, sizeof(mask.n), PgDos);

	}

	dc2->EndFullUpdate();
	cxG2->EndUpdate();
	if (dc2->RecordCount != 0) {
		dc2->GotoFirst();
	}

	if (dc1->RecordCount != 0) {
		Vw1->OptionsSelection->MultiSelect = true;
		dc1->SelectAll();
		dc1->DeleteSelection();
		Vw1->OptionsSelection->MultiSelect = false;
	}
	dc1->BeginFullUpdate();

	CLR(knus);
//	CLR(zpknu);
	cxGr1->BeginUpdate(lsimImmediate);

	while (fargl(fknus, &knus, sizeof(knus)) == 0 /*&& fargl(fzpknu, &zpknu,
			sizeof(zpknu)) == 0*/) {

		if (start)
			ProgressBarForm->ProgressBar1->Position++;

		ii = dc1->AppendRecord();
		TVarRec args[] = {knus.kod, knus.knu, 0};
		dc1->Values[ii][skod->Index] = Format(Rkodknu, args, 10);
		dc1->Values[ii][kod->Index] = knus.kod;

		dc1->Values[ii][knu->Index] = knus.knu;
		dc1->Values[ii][nm->Index] = FmToUn(knus.n, sizeof(knus.n), PgDos);
		CLR(zpknu);
		swb(&fduyy, &fduyy_sw, 2);
		mov(&fduyy_sw, &zpknu.fd, 2);
		zpknu.kod = dc1->Values[ii][kod->Index];
		zpknu.knu = dc1->Values[ii][knu->Index];

		CLR(Rmask);
		if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {
		   mov(&zpknu.mask, &Rmask, sizeof(zpknu.mask));

			if (knus.knu != 0 && zpknu.knu != 0) {
				if(zpknu.kod < 99)
					dc1->Values[ii][podnal->Index] = zpknu.pr;
				if(zpknu.ks != 0)
					dc1->Values[ii][sk->Index] = zpknu.ks;
				if(zpknu.kotr != 0)
					dc1->Values[ii][prem->Index] = zpknu.kotr;
			 }
		}

	}
	if (start) {
		delete ProgressBarForm;
		start = false;
	}


	dc1->EndFullUpdate();
  cxGr1->EndUpdate();

	if (dc1->RecordCount != 0) {
		dc1->GotoFirst();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::FormKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == ',')
		Key = '.';

	if (dxLCKor->Visible == true && Key == VK_ESCAPE)
		cxCancelClick(Sender);

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::Vw1FocusedRecordChanged
		(TcxCustomGridTableView *Sender, TcxCustomGridRecord *APrevFocusedRecord,
		TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged) {
	//
	TcxGridDataController* dc1 = Vw1->DataController;
	TcxGridDataController* dc2 = Vw2->DataController;
	uchar Rkod, Rknu;
	char Rmask[100];
	int ii, tecind;
	AnsiString vv;
	CLR(Rmask);
	if (dc1->RecordCount != 0) {
		Rkod = (unsigned char)AFocusedRecord->Values[kod->Index];
		Rknu = (unsigned char)AFocusedRecord->Values[knu->Index];
	}
	if (Sender->Controller->FocusedRecord ==
			Vw1->OptionsView->GridView->ViewData->FilterRow)
	{ // Filter row is focused
		cxG2->Visible = false;
	}
	else {
		if (Rknu == 0 || Rkod > 98) {
			Lv2->GridView = VwNull;
			cxG2->Visible = false;
		}
		else {
			if (cxG2->Visible == false) {
				cxG2->Visible = true;
			}
			Lv2->GridView = Vw2;
			CLR(zpknu);
			swb(&fduyy, &fduyy_sw, 2);
			mov(&fduyy_sw, &zpknu.fd, 2);
			zpknu.kod = Rkod;
			zpknu.knu = Rknu;
			if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {
				mov(&zpknu.mask, &Rmask, sizeof(zpknu.mask));
			}

			tecind = dc2->FocusedRecordIndex;
			dc2->BeginFullUpdate();
			for (int ii = 0;(unsigned)ii < sizeof(zpknu.mask); ii++) {
				dc2->FocusedRecordIndex = dc2->FindRecordIndexByText(0, mask_np->Index,
						IntToStr(ii + 1), false, true, true);

				if (Rmask[ii] == 'ы') {
					dc2->Values[dc2->FocusedRecordIndex][chek->Index] = 1;

				}
				else {
					dc2->Values[dc2->FocusedRecordIndex][chek->Index] = 0;

				}
			}
			dc2->EndFullUpdate();
		 	dc2->FocusedRecordIndex = tecind;
		}
	}
}
// ---------------------------------------------------------------------------


void __fastcall TfrSpr0020::Vw1StylesGetContentStyle
		(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
		TcxCustomGridTableItem *AItem, TcxStyle *&AStyle) {
	if (!ARecord->Values[knu->Index].IsNull()) {
		if ((int)ARecord->Values[knu->Index] == 0) {
			AStyle = AKnuStyle;
		}
		else {
			if (Sender->ViewInfo->GridView->Focused && ARecord->Focused) {
				AStyle = ATecStyle;
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::FormShow(TObject *Sender) {
	aRefresh->Execute();
	AKnuStyle = new TcxStyle(this);
	AKnuStyle->Color = ((TColor)0x00A4CCA4);
	AKnuStyle->TextColor = clBlack;
	AKnuStyle->Font = this->Font;
	AKnuStyle->Font->Size = this->Font->Size + 2;
	AKnuStyle->Font->Style = TFontStyles() << fsItalic;

	ATecStyle = new TcxStyle(this);
	ATecStyle->Color = clSkyBlue;
	// ATecStyle->Color = clGradientActiveCaption;
	ATecStyle->TextColor = clBlack;
	ATecStyle->Font = this->Font;

	Vw1->FindItemByName("skod")->ApplyBestFit();
	cxG2->Visible = false;

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::Vw2StylesGetContentStyle
		(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
		TcxCustomGridTableItem *AItem, TcxStyle *&AStyle) {
	if (Sender->ViewInfo->GridView->Focused && ARecord->Focused) {
		AStyle = ATecStyle;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::Vw1EditValueChanged(TcxCustomGridTableView *Sender,
		TcxCustomGridTableItem *AItem) {
	if (Sender->Controller->FocusedRecord ==
			Vw1->OptionsView->GridView->ViewData->FilterRow)
	{ // Filter row is focused
		FilterString = ((TcxTextEdit*)Sender->Controller->EditingController->Edit)
				->EditValue;
		TReplaceFlags Flg;
		Flg << rfReplaceAll << rfIgnoreCase;
		FilterString = StringReplace(FilterString, "*", "", Flg);
		PostMessage(Handle, CM_APPLYFILTER, Integer(Sender->DataController->Filter),
				Integer(AItem));
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::OnCM_APPLYFILTER(TMessage& Msg) {
/*
	TcxDBDataFilterCriteria *FilterC;

	Vw1->DataController->Filter->Root->Clear();
	if (FilterString.Length()) {
		FilterString = "*" + FilterString + "*";
		Vw1->DataController->Filter->Root->AddItem((TObject *)Msg.LParam, foLike,
				FilterString, FilterString);
	}
*/
};

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::nmCustomDrawCell(TcxCustomGridTableView *Sender,
		TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	TRect R;
	String FltStr, FltStrUp;
	String text, text1, text2, TxtUp, TxtFlt;
	int pos, pos1;
	int MyCount;

	if (FilterString.Length()) {
		MyCount = 0;
		pos = 0;
		FltStr = FilterString.SubString(2, FilterString.Length() - 2);
		FltStrUp = FltStr.UpperCase();
		if (AViewInfo->Value.IsNull() != true) {
			text = AViewInfo->Value;
			TxtUp = text.UpperCase();

			pos = TxtUp.Pos(FltStrUp);
			R = AViewInfo->Bounds;
			ACanvas->Canvas->FillRect(AViewInfo->Bounds);
			R.Top = AViewInfo->Bounds.Top;
			R.Left = AViewInfo->Bounds.Left;
			ACanvas->Font->Color = clBlack;
			ACanvas->DrawTexT(AViewInfo->Value, R, cxAlignLeft);

			text1 = text.SubString(0, pos - 1);
			R.Left = R.Left + ACanvas->TextWidth(text1);
			ACanvas->Font->Color = clRed;
			TxtFlt = text.SubString(pos, FltStr.Length());
			ACanvas->DrawTexT(TxtFlt, R, cxAlignLeft);
			if (MyCount == 2) {
				text1 = text.SubString(pos + FltStr.Length(), text.Length());
				TxtUp = text1.UpperCase();
				pos1 = TxtUp.Pos(FltStrUp);
				text2 = text.SubString(0, pos - 1 + FltStr.Length()) + text1.SubString
						(0, pos1 - 1);
				TxtFlt = text1.SubString(pos1, FltStr.Length());
				R.Left = AViewInfo->Bounds.Left + ACanvas->TextWidth(text2);
				ACanvas->DrawTexT(TxtFlt, R, cxAlignLeft);
			}
			ADone = true;
		}
	}
	else {
		ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
	}

}
// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::chekPropertiesChange(TObject *Sender) {
	TcxGridDataController* dc1 = Vw1->DataController;
	TcxGridDataController* dc2 = Vw2->DataController;
	bool f1 = false, f2 = false;
	int t;
	char Rmask[100];
	CLR(Rmask);
	int m, m1;
	unsigned short dd, mm, yy;

	cxDE->Date.DecodeDate(&yy, &mm, &dd);
	m1 = mm;

	CLR(zpknu);
	mov(&fduyy_sw, &zpknu.fd, 2);
	zpknu.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
	zpknu.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];

	CLR(knus);

	knus.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
	knus.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];

	if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {
		mov(&zpknu.mask, &Rmask, sizeof(zpknu.mask));
	}
	t = dc2->Values[dc2->FocusedRecordIndex][chek->Index];
	if (t == 1)
		Rmask[dc2->FocusedRecordIndex] = 'ы';
	else
		Rmask[dc2->FocusedRecordIndex] = '0';

	for (int i = 1; i < 3; i++) {
		t = dc2->Values[i][chek->Index];
		if (dc2->Values[i][mask_np->Index] == 2 && t == 0)
			f1 = true;
	}

	for (int k = 3; k < 9; k++) {
		t = dc2->Values[k][chek->Index];
		if (dc2->Values[k][mask_np->Index] == 7 && t == 0)
			f2 = true;
	}

	if (f1 == true && f2 == true){
		//dc1->Values[dc1->FocusedRecordIndex][prem->Index] = 0;
    zpknu.kotr = 0;
	}

	if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {

		zpknu.mask[dc2->FocusedRecordIndex] = Rmask[dc2->FocusedRecordIndex];
		farwl(fzpknu, &zpknu, sizeof(zpknu));
	}

	CLR(mask);
	mask.np = dc2->Values[dc2->FocusedRecordIndex][mask_np->Index];

	if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {

		for (m = m1; m < 13; m++) {

			fduyy.fd_mm = m;
			swb(&fduyy, &fduyy_sw, 2);

			mov(&fduyy_sw, &zpknu.fd, 2);
			zpknu.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
			zpknu.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];

			farwl(fzpknu, &zpknu, sizeof(zpknu));
			mov(&Rmask, &zpknu.mask, sizeof(zpknu.mask));

		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfrSpr0020::cxDEEnter(TObject *Sender) {

	TcxGridDataController* dc1 = Vw1->DataController;
	mov(&fduyy, &fduyy_sw, 2);
	poz = dc1->FocusedRecordIndex;
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxDEExit(TObject *Sender) {

	TcxGridDataController* dc1 = Vw1->DataController;
	unsigned short dd, mm, yy;
	if (!cxDE->EditValue.IsNull()) {
		cxDE->Date.DecodeDate(&yy, &mm, &dd);
		fduyy.fd_dd = 1;
		fduyy.fd_mm = mm;
		fduyy.fd_yy = yy - 1980;
		cxDE->Date = EncodeDate(fduyy.fd_yy + 1980, fduyy.fd_mm, fduyy.fd_dd);

		if (cmpdt((struct fdt*)&fduyy, (struct fdt*)&fduyy_sw, 2) != 0)
			aRefresh->Execute();
		dc1->FocusedRecordIndex = poz;
	}
	else
		cxDE->SetFocus();

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::aKorExecute(TObject *Sender) {
	TcxGridDataController* dc1 = Vw1->DataController;
	TcxGridDataController* dc2 = Vw2->DataController;

	int kk;
	bool f = false;
	int t;
	unsigned short dd, mm, yy;
	Kor=true;
	NewCopy=false;
	if (Vw1->IsControlFocused) {
    Clear();
		dxLCKor->Visible = true;
		cxTE_VK->Enabled = false;

    dxLayoutControl1Item1->Enabled = false;
		dxLayoutControl1Item2->Enabled = false;
		cxDE->Enabled = false;
		aKor->Enabled = false;
		aNew->Enabled = false;
		aNewCopy->Enabled = false;
		aChek->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;

		knu1 = dc1->Values[dc1->FocusedRecordIndex][knu->Index];
		if(knu1 != 0){
			cxDE->Date.DecodeDate(&yy, &mm, &dd);
			CLR(zpknu);
			zpknu.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
			zpknu.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];
			mov(&fduyy,&fduyy2,2);
			fduyy2.fd_mm -= 1;
			CLR(fduyy_sw2);
			swb(&fduyy2, &fduyy_sw2, 2);
			mov(&fduyy_sw2, &zpknu.fd, 2);
		if (mm == 1 && bzp.uyy.mm==1 || farel(fzpknu,&zpknu,sizeof(zpknu)) != 0){
			cxTE_S->Enabled = true;
			cxTE_P->Enabled = true;
			cxME_NDFL->Enabled = true;
			cxME_NDFL->SetFocus();
		}
		else{
			cxME_NDFL->Enabled = false;
			cxTE_S->Enabled = false;
			cxTE_P->Enabled = false;
		 }

		if (!dc1->Values[dc1->FocusedRecordIndex][podnal->Index].IsNull())
			ndfl = dc1->Values[dc1->FocusedRecordIndex][podnal->Index];
		else
			ndfl = 0;


		if (dc1->Values[dc1->FocusedRecordIndex][kod->Index] < 98) {
			cxME_NDFL->Properties->Buttons->Items[1]->Enabled = false;
		}
		else {
			cxME_NDFL->Properties->Buttons->Items[1]->Enabled = true;
		}
	 }

		if (dc1->FocusedRecordIndex > -1) {
			kk = dc1->FocusedRecordIndex;

			cxTE_K->Text = dc1->Values[kk][kod->Index];
			cxTE_Kn->Text = dc1->Values[kk][knu->Index];
			cxTE_VK->Text = dc1->Values[kk][skod->Index];
			cxTE_N->Text = dc1->Values[kk][nm->Index];

		if(knu1 != 0){
			if (!dc1->Values[kk][podnal->Index].IsNull() ||
					!dc1->Values[kk][sk->Index].IsNull() ||
					!dc1->Values[kk][prem->Index].IsNull()) {

			 if (!dc1->Values[kk][podnal->Index].IsNull())
				kkod = dc1->Values[kk][podnal->Index];
			 else
			 kkod = 0;
			 if (!dc1->Values[kk][sk->Index].IsNull())
				sk1 = dc1->Values[kk][sk->Index];
			 else
				sk1=0;

				CLR(pnal);
				while (fargl(fpnal, &pnal, sizeof(pnal)) == 0) {
					if (pnal.k == kkod) {
						cxME_NDFL->Text = IntToStr(pnal.k) + " " + FmToUn(pnal.n,
								sizeof(pnal.n), PgDos);

					}
				}

				if (dc1->Values[kk][podnal->Index] != 3) {
					cxTE_S->Text = "";
					cxTE_S->Enabled = false;
				}
				else {
					cxTE_S->Enabled = true;

					CLR(vsr);
					mov(&fduyy, &fdt, sizeof(struct fdate));
					fdt.fd_dd = 1;
					fdt.fd_mm = 1;
					swb(&fdt, &fdt_sw, 2);

					while (fargl(fvsr, &vsr, sizeof(vsr)) == 0) {
						if (cmpdt((struct fdt*)&vsr.fd, (struct fdt*)&fdt_sw,
								2) == 0 && vsr.kod == sk1) {
							cxTE_S->Text = IntToStr(sk1) + " " + FmToUn(vsr.n,
									sizeof(vsr.n), PgDos);
						}
					}
				}

				if (dc1->Values[kk][podnal->Index] == 0) {
					cxME_NDFL->Text = "";
				}

				if (dc1->Values[kk][sk->Index] == 0) {
					cxTE_S->Text = "";
				}

				for (int ii = 1; ii < 9; ii++) {
					t = dc2->Values[ii][chek->Index];
					if ((dc2->Values[ii][mask_np->Index] == 2 ||
							dc2->Values[ii][mask_np->Index] == 7) && t == 1) {
						f = true;
					}
				}
				if (f == false) {
					cxTE_P->Text = 0;
					cxTE_P->Enabled = false;
				}
				else {
					cxTE_P->Enabled = true;
					if(!dc1->Values[kk][prem->Index].IsNull())
						cxTE_P->Text = dc1->Values[kk][prem->Index];
					else
						cxTE_P->Text = 0;
				}
			}
			CLR(knu2);
      CLR(fduyy2);
			fduyy2.fd_mm = 1;
			fduyy2.fd_dd = 1;
      fduyy2.fd_yy = bzp.uyy.yy;
			swb(&fduyy2,&knu2.fd,2);

			knu2.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
			knu2.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];
			if(farel(fknu2,&knu2,sizeof(knu2))==0){
				 cxSEKodDoh->Value = knu2.dho;
				 CLR(vdoh);
				 swb(&knu2.dho,&vdoh.kod,sizeof(vdoh.kod));
				 if(farel(fvdoh,&vdoh,sizeof(vdoh))==0){
					 cxBEDoh->Text = OEMtoWS(vdoh.n, sizeof(vdoh.n));
				 }
				 cxSEKodV->Value = knu2.sk;
				 CLR(vsr);
				 mov(&knu2.fd,&vsr.fd,2);
				 vsr.kod = knu2.sk;
				 if(farel(fvsr,&vsr,sizeof(vsr))==0){
					 cxBESk->Text = OEMtoWS(vsr.n, sizeof(vsr.n));
				 }
				 else{
					CLR(vvch);
					mov(&knu2.fd,&vvch.fd,2);
					vvch.kod = knu2.sk;
					if(farel(fvvch,&vvch,sizeof(vvch))==0){
					 cxBESk->Text = vvch.nm;
					}
				 else{
					CLR(nalvch);
					nalvch.kod = knu2.sk;
					swb(&knu2.sk,&nalvch.kod,sizeof(nalvch.kod));
					if(farel(fnalvch,&nalvch,sizeof(nalvch))==0){
					 cxBESk->Text = OEMtoWS(nalvch.nm, sizeof(nalvch.nm));
					}
				 }
				}
				 if(knu2.muld == 0)
						cxCBDoh->ItemIndex = 2;
				 if(knu2.muld == 1)
						cxCBDoh->ItemIndex = 1;
				 if(knu2.muls == 0)
						cxCBSk->ItemIndex = 0;
				 if(knu2.muls == 1)
						cxCBSk->ItemIndex = 1;
			}
		 }
		 else{
			dxLayoutControl1Item3->Visible = false;
			dxLayoutControl1Item4->Visible = false;
			dxLayoutControl1Item5->Visible = false;
      dxLCKor3->Visible = false;
		 }
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxCancelClick(TObject *Sender) {

  if(knu1 == 0){
			dxLayoutControl1Item3->Visible = true;
			dxLayoutControl1Item4->Visible = true;
			dxLayoutControl1Item5->Visible = true;
			dxLCKor3->Visible = true;
		}

	dxLCKor->Visible = false;
	dxLayoutControl1Item1->Enabled = true;
	dxLayoutControl1Item2->Enabled = true;
	cxDE->Enabled = true;
	aKor->Enabled = true;
	aNew->Enabled = true;
	aNewCopy->Enabled = true;
	aChek->Enabled = true;
	aExit->Enabled = true;
	aExit->ShortCut = VK_ESCAPE;
	cxGr1->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxOkClick(TObject *Sender) {

	TcxGridDataController* dc1 = Vw1->DataController;
	int ii,ind1;
	int m, m1,kkod;
	unsigned short dd, mm, yy;
	AnsiString nkod;

	cxDE->Date.DecodeDate(&yy, &mm, &dd);
	m1 = mm;

	bool Ok = true;
	ii = dc1->FocusedRecordIndex;

	if (cxTE_N->Text.IsEmpty()){
	 	armerr(2, "Введите наименование нового кода/вида начисления/удержания!");
		cxTE_N->SetFocus();
		Ok = false;
	}
 if(!NewCopy && knu1 != 0){
	kkod = StrToInt(cxTE_K->Text);
	if (kkod<99 && cxME_NDFL->Text.IsEmpty()){
		 armerr(2, "Введите код удержания НДФЛ!");
		 cxME_NDFL->SetFocus();
		 Ok = false;
 }
	if (ndfl == 3 && cxTE_S->Text.IsEmpty()) {
		armerr(2, "Введите код скидки!");
		cxTE_S->SetFocus();
		Ok = false;
	}
 }
	if (Ok) {
	 if(knu1 != 0){
		for (m = m1; m < 13; m++) {
			CLR(zpknu);
			fduyy.fd_mm = m;
			swb(&fduyy, &fduyy_sw, 2);
			mov(&fduyy_sw, &zpknu.fd, 2);
			zpknu.kod = cxTE_K->EditValue;
			zpknu.knu = cxTE_Kn->EditValue;

		 if(Kor && farel(fzpknu, &zpknu, sizeof(zpknu))==0 || !Kor){
			if(!NewCopy){
				if (cxME_NDFL->Text.IsEmpty())
					zpknu.pr = 0;
				else
					zpknu.pr = ndfl;

				if (cxTE_S->Text.IsEmpty())
					zpknu.ks = 0;
				else
					zpknu.ks = sk1;

				if (cxTE_P->Text.IsEmpty())
					zpknu.kotr = 0;
				else
					zpknu.kotr = cxTE_P->EditValue;
			}
				farwl(fzpknu, &zpknu, sizeof(zpknu));
		 }
	}
  if(!NewCopy){
      CLR(fduyy2);
			fduyy2.fd_mm = 1;
			fduyy2.fd_dd = 1;
			fduyy2.fd_yy = bzp.uyy.yy;
			CLR(knu2);
			swb(&fduyy2, &knu2.fd, 2);
			knu2.kod = cxTE_K->EditValue;
			knu2.knu = cxTE_Kn->EditValue;

		 if(Kor && farel(fknu2, &knu2, sizeof(knu2))==0 || !Kor){
       knu2.dho = (long)cxSEKodDoh->Value;
			 knu2.sk = (long)cxSEKodV->Value;
			 if (cxCBDoh->ItemIndex==2)
					knu2.muld = 255;
			 else
					knu2.muld = cxCBDoh->ItemIndex;

			 if (cxCBSk->ItemIndex==2)
					knu2.muls = 255;
			 if(cxCBSk->ItemIndex ==0 || cxCBSk->ItemIndex == 1)
				 	knu2.muls = cxCBSk->ItemIndex;

			 farwl(fknu2, &knu2, sizeof(knu2));
		 }
		}
 }
		CLR(knus);
		knus.kod = cxTE_K->EditValue;
		knus.knu = cxTE_Kn->EditValue;
		if(Kor && farel(fknus, &knus, sizeof(knus))==0 || !Kor){
			nkod = cxTE_N->Text;
			CharToOemA(nkod.c_str(),knus.n);
			farwl(fknus, &knus, sizeof(knus));
		}
			if(!Kor){
				aRefresh->Execute();
				dc1->FocusedRecordIndex=ind+1;
			}
			else{
				dc1->FocusedRecordIndex = ii;
				dc1->Values[ii][skod->Index] = cxTE_VK->Text;
				dc1->Values[ii][nm->Index] =  cxTE_N->Text;
			 if(knu1 != 0){
				if (cxME_NDFL->Text.IsEmpty())
					dc1->Values[ii][podnal->Index] = 0;
				else
					dc1->Values[ii][podnal->Index] = ndfl;

				if (!cxTE_S->Text.IsEmpty())
					dc1->Values[ii][sk->Index] = sk1;
				else
					dc1->Values[ii][sk->Index] = 0;

				if (!cxTE_P->Text.IsEmpty())
					dc1->Values[ii][prem->Index] = cxTE_P->Text;
				else
					dc1->Values[ii][prem->Index] = 0;
			 }
		 }

		if(knu1 == 0){
			dxLayoutControl1Item3->Visible = true;
			dxLayoutControl1Item4->Visible = true;
			dxLayoutControl1Item5->Visible = true;
			dxLCKor3->Visible = true;
		}
		dxLCKor->Visible = false;
		dxLayoutControl1Item1->Enabled = true;
		dxLayoutControl1Item2->Enabled = true;
		cxDE->Enabled = true;
		aKor->Enabled = true;
		aNew->Enabled = true;
		aNewCopy->Enabled = true;
		aChek->Enabled = true;
		aExit->Enabled = true;
		aExit->ShortCut = VK_ESCAPE;
		cxGr1->SetFocus();
	}

}

// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxTE_NDFLPropertiesButtonClick(TObject *Sender,
		int AButtonIndex)
{
	if (AButtonIndex == 1) {
		cxME_NDFL->Text = "";
	}
	else {
			CLR(pnal);
			if (IniSpr0027(&pnal) == 1) {
				kkod = pnal.k;
		cxME_NDFL->Text = IntToStr(pnal.k) + " " + FmToUn(pnal.n,
						sizeof(pnal.n), PgDos);
				 ndfl = kkod;

				if (kkod == 3) {
					cxTE_S->Enabled = true;
				}
				else {
					cxTE_S->Text = "";
					cxTE_S->Enabled = false;
					sk1 = 0;
				}
			}
	}
	cxME_NDFL->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxTE_SPropertiesButtonClick(TObject *Sender,
		int AButtonIndex)
{
	struct zpsppar sppar;
	if (AButtonIndex == 1) {
		cxTE_S->Text = "";
		cxTE_S->SetFocus();
	}
	else {
//		IniSpNVSR(1,1,&sppar,&fduyy);
//		if (l_call("ZPSPRSWN", "GVSR",&sppar) == 1) {
		if (IniSpNVSR(1,1,&sppar,&fduyy) == 1) {
			cxTE_S->SetFocus();
			sk1 = sppar.par1;
			cxTE_S->Text = IntToStr(sk1) + " " + sppar.nm;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxDEKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_RETURN) {
		cxGr1->SetFocus();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::aChekExecute(TObject *Sender) {
     TcxGridDataController* dc1 = Vw1->DataController;

	int m, m1;
	unsigned short dd, mm, yy;
	char Rmask2[sizeof(zpknu.rez)];
	bool maska[30];
	CLR(Rmask2);
	CLR(zpknu);
	CLR(maska);

	cxDE->Date.DecodeDate(&yy, &mm, &dd);
	m1 = mm;

	if (Vw1->IsControlFocused) {

		swb(&fduyy, &fduyy_sw, 2);
		mov(&fduyy_sw, &zpknu.fd, 2);
		zpknu.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
		zpknu.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];

		if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {
			mov(&zpknu.rez, &Rmask2, sizeof(zpknu.rez));
		}

		for (int kk = 0; kk < kol; kk++) {

			if (Rmask2[kk] == 'ы') {
				maska[kk] = true;
			}
			else {
				maska[kk] = false;
			}

		}
  Application->ProcessMessages();
	if (IniSpr0031(maska) == 1){
  Application->ProcessMessages();

			for (int kk = 0; kk < kol; kk++) {

				if (frSpr0031->maska[kk])
					Rmask2[kk] = 'ы';
				else
					Rmask2[kk] = '0';
			}

		}

		if (farel(fzpknu, &zpknu, sizeof(zpknu)) == 0) {

			for (m = m1; m < 13; m++) {

				fduyy.fd_mm = m;
				swb(&fduyy, &fduyy_sw, 2);
				mov(&fduyy_sw, &zpknu.fd, 2);

				zpknu.kod = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
				zpknu.knu = dc1->Values[dc1->FocusedRecordIndex][knu->Index];

				mov(&Rmask2, &zpknu.rez, sizeof(zpknu.rez));
				farwl(fzpknu, &zpknu, sizeof(zpknu));
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrSpr0020::aNewCopyExecute(TObject *Sender)
{
	TcxGridDataController* dc1 = Vw1->DataController;
	uchar kkod;
	Kor=false;
	NewCopy=true;
	if (Vw1->IsControlFocused) {
		dxLCKor->Visible = true;
		dxLCKor2->Visible = false;
		dxLCKor3->Visible = false;
		cxTE_VK->Enabled = false;
    Clear();
		cxTE_N->SetFocus();

		dxLayoutControl1Item1->Enabled = false;
		dxLayoutControl1Item2->Enabled = false;
		cxDE->Enabled = false;
		aKor->Enabled = false;
		aNew->Enabled = false;
		aNewCopy->Enabled = false;
		aChek->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;
		ind=0;

		if (dc1->FocusedRecordIndex > -1) {
			CLR(knus);
			if ((uchar)dc1->Values[dc1->FocusedRecordIndex][kod->Index] <99){
				kkod=0;
				knus.kod = 1;
				}
			else{
			 if  ((uchar)dc1->Values[dc1->FocusedRecordIndex][kod->Index] <200){
				kkod=98;
				knus.kod = 99;
			 }
			 else{
				kkod=199;
				knus.kod = 200;
			 }
			}
      knus.knu = 0;
			while (fargl(fknus,&knus,sizeof(knus))==0){
				if(knus.kod-kkod != 1 && knus.kod!=kkod)
					break;
			 if(kkod != knus.kod)
				kkod = knus.kod;

				ind++;
			}

			cxTE_K->Text = kkod+1;
			cxTE_Kn->Text = 0;
			cxTE_VK->Text = cxTE_K->Text + "." + cxTE_Kn->Text;

		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrSpr0020::aNewExecute(TObject *Sender)
{
	TcxGridDataController* dc1 = Vw1->DataController;
	uchar kknu,kkod1;
	Kor=false;
	NewCopy=false;
	if (Vw1->IsControlFocused) {
		dxLCKor->Visible = true;
		dxLCKor2->Visible = true;
    dxLCKor3->Visible = true;
		cxTE_VK->Enabled = false;
		cxTE_S->Enabled = true;
		cxTE_P->Enabled = true;
		cxME_NDFL->Enabled = true;
    Clear();
		cxTE_N->SetFocus();

		dxLayoutControl1Item1->Enabled = false;
		dxLayoutControl1Item2->Enabled = false;
		cxDE->Enabled = false;
		aKor->Enabled = false;
		aNew->Enabled = false;
		aNewCopy->Enabled = false;
		aChek->Enabled = false;
		aExit->Enabled = false;
		aExit->ShortCut = 0;

		if (dc1->Values[dc1->FocusedRecordIndex][kod->Index] < 98) {
			cxME_NDFL->Properties->Buttons->Items[1]->Enabled = false;
		}
		else {
			cxME_NDFL->Properties->Buttons->Items[1]->Enabled = true;
		}

		if (dc1->FocusedRecordIndex > -1) {
			kknu=0;

			cxTE_K->Text = dc1->Values[dc1->FocusedRecordIndex][kod->Index];
			kkod1=dc1->Values[dc1->FocusedRecordIndex][kod->Index];
			ind=0;
			while(dc1->Values[ind][kod->Index] != kkod1){
				ind++;
			}

			CLR(knus);
			knus.kod = (uchar)dc1->Values[dc1->FocusedRecordIndex][kod->Index];

			while (fargl(fknus,&knus,sizeof(knus))==0 && knus.kod==(uchar)dc1->Values[dc1->FocusedRecordIndex][kod->Index]){
				if(knus.knu-kknu != 1)
					break;
				kknu = knus.knu;
				ind++;
			}
			cxTE_Kn->Text = kknu+1;
			knu1 = kknu+1;
			cxTE_VK->Text = cxTE_K->Text + "." + cxTE_Kn->Text;

		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0020::podnalCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
					TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
	AnsiString Astr;
	if (!AViewInfo->Value.IsNull()){
		Astr = AViewInfo->Value;
	if (Astr == "0")
		ACanvas->Font->Color = clRed;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrSpr0020::cxSEKodDohExit(TObject *Sender)
{
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
			cxBEDoh->Text = OEMtoWS(vdoh.n, sizeof(vdoh.n));
		}
		else
			cxBEDoh->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxSEKodVExit(TObject *Sender)
{
if (cxSEKodV->Value == 0) {
		cxBESk->Text = "";
		sk2 = 0;
		kodrf = 0;
		cxCBSk->ItemIndex = 0;
	}
	else {
		sk2 = cxSEKodV->Value;
		cxBESk->Text = "";
		kodrf = 0;
		CLR(fdt);
		mov(&fduyy,&fdt,2);
		fdt.fd_mm = 1;
		CLR(vsr);
		swb(&fdt, &vsr.fd, 2);
		vsr.kod = sk2;
		if(farel(fvsr,&vsr,sizeof(vsr))==0){
		 cxBESk->Text = vsr.n;
		 kodrf = vsr.kodrf;
		}
		else
			cxBESk->Text = "";

	}
}
//---------------------------------------------------------------------------
void __fastcall TfrSpr0020::cxBEDohPropertiesButtonClick(TObject *Sender, int AButtonIndex)
{
if (AButtonIndex == 1) {
		cxBEDoh->Text = "";
		cxBEDoh->SetFocus();
		dho1 = 0;
		cxCBDoh->ItemIndex = 0;
		cxSEKodDoh->Value = 0;
	}
	else {
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
//---------------------------------------------------------------------------
void __fastcall TfrSpr0020::cxBESkPropertiesButtonClick(TObject *Sender, int AButtonIndex)
{
AnsiString name = "";
int  kod1 = 0;
long kod2 = 0;

if (AButtonIndex == 1) {
		cxBESk->Text = "";
		cxBESk->SetFocus();
		sk2 = 0;
		kodrf = 0;
		cxCBSk->ItemIndex = 0;
		cxSEKodV->Value = sk2;
	}
	else {
		CLR(fdt);
		mov(&fduyy,&fdt,2);
		fdt.fd_mm = 1;
		if (IniVV1(&fdt, &kod1, &kod2, &name,0,0) == 1) {
			cxBESk->Text = name;
			sk2 = kod1;
			kodrf = kod2;
			cxSEKodV->Value = kod1;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxCBDohExit(TObject *Sender)
{
if (cxSEKodDoh->Value == 0)
		cxCBDoh->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0020::cxCBSkExit(TObject *Sender)
{
if (cxSEKodV->Value == 0)
		cxCBSk->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrSpr0020::Clear(){
		cxTE_K->Clear();
		cxTE_Kn->Clear();
		cxTE_VK->Clear();
		cxTE_N->Clear();
		cxME_NDFL->Clear();
		cxTE_S->Clear();
		cxTE_P->Clear();
		cxBEDoh->Clear();
		cxBESk->Clear();
		cxSEKodDoh->Clear();
		cxSEKodV->Clear();
		cxCBDoh->Clear();
		cxCBSk->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrSpr0020::Vw1CustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)

{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
//---------------------------------------------------------------------------

