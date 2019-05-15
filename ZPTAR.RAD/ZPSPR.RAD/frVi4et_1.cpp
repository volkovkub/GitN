//---------------------------------------------------------------------------
//BG 04/06/02018 - замена zpvvch1 на zpvvch2
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"
#include "frVi4et_1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtons"
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

// ---------------------------------------------------------------------------
__fastcall TfrVV1::TfrVV1(TComponent* Owner) : Tfraspr03(Owner) {
}

// ---------------------------------------------------------------------------
int IniVV1(struct fdate *fdpar, int *kod1, long *kod2, AnsiString *name1, int mode, int par) {
	TfrVV1 *frVV1;
	int ret = -1;
	char errtb[20];
	try {
		frVV1 = new TfrVV1(Application);
		frVV1->ok = false;
		CLR(errtb);
		if ((frVV1->fvsr = fafo(c_p->b_nc, strcpy(errtb, "zpvsr"))) != 0) {
			if ((frVV1->fvvch = fafo(c_p->b_nc, strcpy(errtb, "zpvvch2"))) != 0) {
				if ((frVV1->fnalvch = fafo(c_p->b_nc, strcpy(errtb, "zpnalvch"))) != 0) {
						frVV1->ok = true;
				 }
			}
		}
	if (frVV1->ok) {
		frVV1->ret = &ret;
		frVV1->fdt.fd_dd = 1;
		frVV1->fdt.fd_mm = 1;
		frVV1->fdt.fd_yy = fdpar->fd_yy;
		frVV1->dxLCNew->Visible = false;
		frVV1->mode = mode;
		frVV1->par1 = par;
		if(par==0)
			 frVV1->cxDE->Enabled = false;
		else
			 frVV1->cxDE->Enabled = true;
		frVV1->cxDE->Date = EncodeDate(fdpar->fd_yy+1980,1,1);
		if(mode==1){
			frVV1->Vw_ndfl->Visible = true;
			frVV1->Vw_sk->Visible = true;
		}
		if(mode==2){
			frVV1->Vw_sum->Visible = true;
			frVV1->Vw_pr->Visible = true;
		}
			frVV1->aRefresh->Execute();
		if (frVV1->par1 == 1) {
			frVV1->Show();
		}
		if (frVV1->par1 == 0) {
      frVV1->aOk->Enabled = true;
			frVV1->aOk->Visible = true;
			frVV1->ShowModal();
			  *kod1 = frVV1->kod;
			if(mode==0)
				*kod2 = frVV1->kodrf;
				*name1 = frVV1->name;
			delete frVV1;
		}
	}
  else {
			armerr(1, "Невозможно открыть таблицу : " + AS(errtb));
			frVV1->Close();
		}
	}
	catch (const Exception &e) {
		AnsiString ss = e.Message +
				" Модуль frVi4et  содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
		armerr(1, ss.c_str());
		ExitProcess(1);
	}
	catch (...) {
		AnsiString ss;
		unsigned long dwError = GetLastError();
		if (dwError != 0)
			ss = SysErrorMessage(dwError);
		else
			ss = "Не определенная ошибка";
		ss = ss + " Модуль frVi4et содержит ошибку, завершаем работу, оповестите разработчиков ПП Управление персоналом";
		armerr(1, ss.c_str());
		ExitProcess(1);
	}

	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall TfrVV1::aRefreshExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;
	int ii;
	ushort nalkod;

	if (dc->RecordCount != 0) {
		Vw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		Vw->OptionsSelection->MultiSelect = false;
	}
	dc->BeginFullUpdate();
	 CLR(fdt1);
	 swb(&fdt,&fdt1,2);
	 if(par1==0 || par1==1 && mode==1){
   	Vw_kod->Visible = true;
		CLR(vsr);
		swb(&fdt,&vsr.fd,2);
		nkod=0;
		while(fargl(fvsr,&vsr,sizeof(vsr))==0 && cmpdt((struct fdt*)&vsr.fd,(struct fdt*)&fdt1,2) == 0){
			ii = dc->AppendRecord();
			dc->Values[ii][Vw_kod->Index]= vsr.kod;
      nkod++;
			dc->Values[ii][Vw_kodrf->Index]= vsr.kodrf;
			dc->Values[ii][Vw_name->Index]= FmToUn(vsr.n, sizeof(vsr.n), PgDos);
			if(mode==1){
			dc->Values[ii][Vw_ndfl->Index]= vsr.sk;
			dc->Values[ii][Vw_sk->Index]= vsr.ske;
		 }
		}
	 }
	if(mode!=1){
		if(mode==0 || mode==2){
			CLR(vvch);
			swb(&fdt,&vvch.fd,2);
			while(fargl(fvvch,&vvch,sizeof(vvch))==0 && cmpdt((struct fdt*)&vvch.fd,(struct fdt*)&fdt1,2) == 0){
				ii = dc->AppendRecord();
				dc->Values[ii][Vw_kod->Index] = vvch.kod;
				dc->Values[ii][Vw_kodrf->Index]= vvch.kodrf;
				dc->Values[ii][Vw_sum->Index]= vvch.sum;
				dc->Values[ii][Vw_pr->Index]= vvch.sump;
				dc->Values[ii][Vw_name->Index]= vvch.nm;
			}
		 }
		if(mode==0 || mode==3){
			CLR(nalvch);
			while(fargl(fnalvch,&nalvch,sizeof(nalvch))==0){
				ii = dc->AppendRecord();
				swb(&nalvch.kod,&nalkod,sizeof(nalvch.kod));
				dc->Values[ii][Vw_kod->Index] = nalkod;
				dc->Values[ii][Vw_kodrf->Index]= nalkod;
				dc->Values[ii][Vw_name->Index]= FmToUn(nalvch.nm, sizeof(nalvch.nm), PgDos);
			}
		 }
   }
	dc->EndFullUpdate();
	if (dc->RecordCount != 0) {
		dc->GotoFirst();
	}

}
// ---------------------------------------------------------------------------
void __fastcall TfrVV1::VwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrVV1::aOkExecute(TObject *Sender) {
	TcxGridDataController* dc = Vw->DataController;

	if (dc->RecordCount != 0) {
		kod = dc->Values[dc->FocusedRecordIndex][Vw_kod->Index];
		kodrf = dc->Values[dc->FocusedRecordIndex][Vw_kodrf->Index];
		name = dc->Values[dc->FocusedRecordIndex][Vw_name->Index];

		*ret = 1;
	}
	else {
		*ret = 0;
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfrVV1::VwCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	if (aOk->Enabled) {
		aOk->Execute();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrVV1::FormClose(TObject *Sender, TCloseAction &Action)
{
 if(ok){
	fafc(fvsr);
	fafc(fvvch);
	fafc(fnalvch);
 }
}
//---------------------------------------------------------------------------



