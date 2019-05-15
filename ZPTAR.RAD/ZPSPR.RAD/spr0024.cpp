// ---------------------------------------------------------------------------
// Выбор Источников финансирования с переносом закрытых ИФ
#include <vcl.h>
#pragma hdrstop

#include "deff.hpp"
#include "wtzp.h"
#include "..\ZPBANK.RAD\banks.h"

extern struct compar *c_p;

#include "spr0024.h"
#include "spr0025.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
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
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxPropertiesStore"
#pragma link "cxStyles"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrNRfinPer *frNRfinPer;

// ---------------------------------------------------------------------------
__fastcall TfrNRfinPer::TfrNRfinPer(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniSpr0024(struct par_fcb *par_fcb) {
	int ret = -1, ii;
	frNRfinPer = new TfrNRfinPer(Application);
	try {
		frNRfinPer->Rpar_fcb.fwrk1 = par_fcb->fwrk1;
		frNRfinPer->Rpar_fcb.fwrk2 = par_fcb->fwrk2;
		frNRfinPer->Rpar_fcb.fwrk3 = par_fcb->fwrk3;
		// Таблица создается в модуле, откуда вызывается справочник
		//frNRfinPer->frfin = fmfo(c_p->b_wrk, "rfino");
		frNRfinPer->frfin = par_fcb->fwrk3;
		if (frNRfinPer->frfin == 0) {
			armerr(1, "Не открыта рабочая таблица rfino!");
		}
		else {
			//frNRfinPer->frfinp = fmfo(c_p->b_wrk, "rfinop");
			frNRfinPer->frfinp = par_fcb->fwrk1;
			if (frNRfinPer->frfinp == 0) {
				armerr(1, "Не открыта рабочая таблица rfinop!");
			}
			else {
				frNRfinPer->RefreshFinP();

				frNRfinPer->ShowModal();

				frNRfinPer->CloseFinP();
				ret = frNRfinPer->aRet;

				//fmfc(frNRfinPer->frfin);
				//fmfc(frNRfinPer->frfinp);
			}
		}
	}
	catch (...) {
	}
	delete frNRfinPer;
	return ret;
}
// ---------------------------------------------------------------------------

void TfrNRfinPer::RefreshFinP() {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	if (dc->RecordCount != 0) {
		cxGrFinTbl->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGrFinTbl->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	CLR(rfin);
	while (fargl(frfin, &rfin, sizeof(rfin)) == 0) {
		if(rfin.np!=1)
			continue;
		ii = dc->AppendRecord();
		dc->Values[ii][cxGrFinTblnp->Index] = rfin.np;
		dc->Values[ii][cxGrFinTblfin->Index] = rfin.fin;
		OemToCharBuffA(rfin.n, rfin.n,sizeof(rfin.n));
		dc->Values[ii][cxGrFinTbln->Index] = rfin.n;
		dc->Values[ii][cxGrFinTblp->Index] = rfin.p;
		dc->Values[ii][cxGrFinTblnpp->Index] = "";
		dc->Values[ii][cxGrFinTblkfinp->Index] = "";
		dc->Values[ii][cxGrFinTblnfinp->Index] = "";
		dc->Values[ii][cxGrFinTblprclose->Index] = "";
		CLR(rfinp);
		rfinp.np=rfin.np;
		rfinp.fin=rfin.fin;
		if(farel(frfinp, &rfinp, sizeof(rfinp)) == 0){
			dc->Values[ii][cxGrFinTblnpp->Index] = rfinp.npp;
			dc->Values[ii][cxGrFinTblkfinp->Index] = rfinp.finp;
			CLR(rfin1);
      rfin1.np=rfinp.npp;
      rfin1.fin=rfinp.finp;
      if(farel(frfin, &rfin1, sizeof(rfin)) == 0){
       	OemToCharBuffA(rfin1.n, rfin1.n,sizeof(rfin1.n));
				dc->Values[ii][cxGrFinTblnfinp->Index] = rfin1.n;
      }
      if(rfinp.prz==1)
				dc->Values[ii][cxGrFinTblprclose->Index] = "Да";
    }
	}
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->FocusedRecordIndex = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfinPer::cxGrFinTblCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}

// ---------------------------------------------------------------------------
void TfrNRfinPer::CloseFinP() {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;
	bool vp = true;

	ii = 0;
	while (ii < dc->RecordCount) {
		Application->ProcessMessages();
		CLR(rfin);
		rfin.np = (unsigned char)dc->Values[ii][cxGrFinTblnp->Index];
		rfin.fin = (unsigned char)dc->Values[ii][cxGrFinTblfin->Index];
		if (farel(frfin, &rfin, sizeof(rfin)) == 0) {

			vp = (bool)dc->Values[ii][cxGrFinTblp->Index];
			if (vp == true)
				rfin.p = 1;
			else
				rfin.p = 0;
			farwl(frfin, &rfin, sizeof(rfin));
      CLR(rfinp);
      mov(&rfin,&rfinp,2);
      farel(frfinp, &rfinp, sizeof(rfinp));
			rfinp.p = rfin.p;
      farwl(frfinp, &rfinp, sizeof(rfinp));
		}
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfinPer::cxGrFinTblpPropertiesEditValueChanged(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii, k, pr;

	ii = dc->FocusedRecordIndex;
	k = (int)dc->Values[ii][cxGrFinTblnp->Index];
	if (k > 0) {
		pr = (int)dc->Values[ii][cxGrFinTblp->Index];
		if (pr == 0)
			dc->Values[ii][cxGrFinTblp->Index] = 1;
		else
			dc->Values[ii][cxGrFinTblp->Index] = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfinPer::aChekExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	ii = 0;
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrFinTblp->Index] = 1;
		ii++;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfrNRfinPer::aUnCheckExecute(TObject *Sender) {
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;

	ii = 0;
	while (ii < dc->RecordCount) {
		// Application->ProcessMessages();
		dc->Values[ii][cxGrFinTblp->Index] = 0;
		ii++;
	}

}
// ---------------------------------------------------------------------------
void __fastcall TfrNRfinPer::cxGrFinTblnfinpPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
	TcxGridDataController* dc = cxGrFinTbl->DataController;
	int ii;
  uchar	kfin, kfinp, np, npp;
  struct zpsppar	par;

	ii = dc->FocusedRecordIndex;
	np = (uchar)dc->Values[ii][cxGrFinTblnp->Index];
	kfin = (uchar)dc->Values[ii][cxGrFinTblfin->Index];
	if (np > 0) {
    if (AButtonIndex == 1) {
      dc->Values[ii][cxGrFinTblnpp->Index]="";
      dc->Values[ii][cxGrFinTblkfinp->Index]="";
      dc->Values[ii][cxGrFinTblnfinp->Index]="";
      CLR(rfinp);
      rfinp.np=np;
      rfinp.fin=kfin;
      if(farel(frfinp, &rfinp, sizeof(rfinp)) == 0){
      	rfinp.npp=0;
      	rfinp.finp=0;
        farwl(frfinp, &rfinp, sizeof(rfinp));
      }
    }
    else {
      CLR(par);
			if (IniSpr0025(&par,&Rpar_fcb) == 1) {
      	dc->Values[ii][cxGrFinTblnpp->Index] = par.par1;
        dc->Values[ii][cxGrFinTblkfinp->Index] = par.par2;
        dc->Values[ii][cxGrFinTblnfinp->Index] = par.nm;
    		npp = (uchar)dc->Values[ii][cxGrFinTblnpp->Index];
		    kfinp = (uchar)dc->Values[ii][cxGrFinTblkfinp->Index];
        CLR(rfinp);
        rfinp.np=np;
        rfinp.fin=kfin;
        if(farel(frfinp, &rfinp, sizeof(rfinp)) == 0){
          rfinp.npp=npp;
          rfinp.finp=kfinp;
          farwl(frfinp, &rfinp, sizeof(rfinp));
        }
      }
    }
	}

}
//---------------------------------------------------------------------------

