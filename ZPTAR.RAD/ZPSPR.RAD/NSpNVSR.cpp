//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "parzp.h"
#include "spr.h"
#include "bsp.h"
#include "tarn.h"
#include "kth.h"
#include "tzp.h"
#include "..\SERVIS\armerrw.h"
#include "dopfunc.h"

extern struct compar *c_p;

#include "NSpNVSR.h"
//---------------------------------------------------------------------------
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
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrSpNVSR *frSpNVSR;
//---------------------------------------------------------------------------
__fastcall TfrSpNVSR::TfrSpNVSR(TComponent* Owner)
	: Tfraspr03(Owner)
{
}
//---------------------------------------------------------------------------
int IniSpNVSR(int d,int g,struct zpsppar *par,struct fdate *fdpar){ //Инициализация
int ret=-1;
AnsiString Rss;

  frSpNVSR = new TfrSpNVSR(Application);
  try{
	  frSpNVSR->b=(struct bsp *)c_p->b_sp;
	  frSpNVSR->flusr=d;
    frSpNVSR->flSPR=g;
    frSpNVSR->ShowModal();
		ret=frSpNVSR->aRet;
    if(ret==1){
			TcxGridDataController* dc = frSpNVSR->cxGridTVw->DataController;
			int ii;
      ii=dc->FocusedRecordIndex;
      par->par1=(char)dc->Values[ii][frSpNVSR->cxGridTVwKOD->Index];
      par->tn  =(long)dc->Values[ii][frSpNVSR->cxGridTVwKODRF->Index];
			CLR(par->nm);
			Rss=dc->Values[ii][frSpNVSR->cxGridTVwNM->Index];
			strcat(par->nm,Rss.c_str());
    }
  }
  catch(...){
  }
  delete frSpNVSR;
return ret;
}
//---------------------------------------------------------------------------
void __fastcall TfrSpNVSR::FormShow(TObject *Sender)
{
//
	CLR(fduyy);
  CLR(ofduyy);
	fd=EncodeDate(b->uyy.yy+1980,1,1);
	cxDate->Date=fd;
	fvsr  = fafonc(c_p->b_nc,"zpvsr");
	fcnst = fafo(c_p->b_zp,"const");
	CLR(cnst);
  strcpy(cnst.n ,"KLIENT");
	if(farel(fcnst,&cnst,sizeof(cnst))==0){
  	if(strcmp(cnst.ct,"1")==0){
				flusr=0;
		}
  }
	fafc(fcnst);
	if(flSPR==1){
		cxDateExit(cxDate);
//    DBDate->OnExit;
		cxDate->Enabled=false;
		aRefresh->Execute();
	}

}
//---------------------------------------------------------------------------
/*
void __fastcall TfrSpNVSR::DBDateKeyDown(TObject *Sender, WORD &Key,
			TShiftState Shift)
{
unsigned short dd,mm,yy;
TDateTime rDate;

if(Key==VK_RETURN){

	if(DBDate->Value.IsNull()){
		DBDate->Value=EncodeDate(b->uyy.yy+1980,1,1);
	}
	if(!DBDate->Value.IsNull()){
		DecodeDate(DBDate->Value,yy,mm,dd);
		fduyy.fd_dd=1;
		fduyy.fd_mm=1;
		fduyy.fd_yy=yy-1980;
	}
	if(cmp(&fduyy,&ofduyy,2)!=0){
		mov(&fduyy,&ofduyy,2);
		aRefresh->Execute();
	}
}
}
//---------------------------------------------------------------------------
*/
void __fastcall TfrSpNVSR::aRefreshExecute(TObject *Sender)
{
//
TcxGridDataController* dc = cxGridTVw->DataController;
int ii;
struct fdate fdsw;

	swb(&fduyy,&fdsw,sizeof(struct fdate));
	dc->BeginFullUpdate();
	if(dc->RecordCount != 0){
		cxGridTVw->OptionsSelection->MultiSelect = true;
		dc->SelectAll();
		dc->DeleteSelection();
		cxGridTVw->OptionsSelection->MultiSelect = false;
	}
	CLR(vsr);
	mov(&fdsw,&vsr.fd,sizeof(struct fdate));
	while(fargl(fvsr,&vsr,sizeof(vsr)) == 0 && cmpdt((struct fdt *)&fdsw,(struct fdt *)&vsr.fd,2)==0){
			ii = dc->AppendRecord();
			dc->Values[ii][cxGridTVwKOD->Index]    = vsr.kod;
			dc->Values[ii][cxGridTVwKODRF->Index]  = vsr.kodrf;
			dc->Values[ii][cxGridTVwSK->Index]     = vsr.sk;
			dc->Values[ii][cxGridTVwSKE->Index]    = vsr.ske;
			dc->Values[ii][cxGridTVwNM->Index]     = OEMtoAL(vsr.n,sizeof(vsr.n));
	}
	if(fduyy.fd_yy>=30){
  	cxGridTVwSKE->Caption="скидка по взносам";
  }
  else{
  	cxGridTVwSKE->Caption="скидка по ЕСН";
  }
  dc->EndFullUpdate();
  cxGrid1->SetFocus();
	if(dc->RecordCount>0){
		cxGrid1->RootLevelOptions->DetailFrameWidth=0;
		dc->FocusedRecordIndex = 0;
  }
  else{
		cxGrid1->RootLevelOptions->DetailFrameWidth=2;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxGrid1Enter(TObject *Sender)
{
//
if(flSPR==1){
	aOk->Enabled=true;
	aOk->Visible=true;
}
else{
aExit->Enabled=false;
aExit->Visible=false;
aExit->ShortCut=0;
}
if(flusr==1){
	aKor->Enabled=true;
	aKor->Visible=true;
  aDel->Visible=true;
  aDel->Enabled=true;
}
}
//---------------------------------------------------------------------------


void __fastcall TfrSpNVSR::aKorExecute(TObject *Sender)
{
TcxGridDataController* dc = cxGridTVw->DataController;
int ii;

if(dc->RecordCount>0){
	if(fduyy.fd_yy<30){
  	dxLayoutControlSKE->Caption="Сумма скидки по ЕСН";
  }
  else{
  	dxLayoutControlSKE->Caption="Сумма скидки по взносам";
  }
	aKor->Visible=false;
	aKor->Enabled=false;
	aDel->Visible=false;
	aDel->Enabled=false;

	dxLayoutGRID->Visible=false;
  ii=dc->FocusedRecordIndex;

	cxSpinKod->Value   =(unsigned char)dc->Values[ii][cxGridTVwKOD->Index];
	cxTxtEdNM->Text    =dc->Values[ii][cxGridTVwNM->Index];
	cxCEdKODRF->Value  =(long)dc->Values[ii][cxGridTVwKODRF->Index];
	cxCEdSK->Value     =(double)dc->Values[ii][cxGridTVwSK->Index];
	cxCEdSKE->Value    =(double)dc->Values[ii][cxGridTVwSKE->Index];
	dxLayoutED->Visible=true;
  cxCEdKODRF->SetFocus();
  cxDate->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxCEdKODRFKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if(Key==VK_RETURN){
   	Key=0;
		SelectNext(ActiveControl,true,true);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxCancelClick(TObject *Sender)
{
aKor->Visible=true;
aKor->Enabled=true;
aDel->Visible=true;
aDel->Enabled=true;

  cxDate->Enabled=true;

	dxLayoutGRID->Visible=true;
	dxLayoutED->Visible=false;
  cxGrid1->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxGridTVwKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(flSPR==0){
	if(Key==VK_ESCAPE){
  	cxDate->SetFocus();
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxGridTVwDblClick(TObject *Sender)
{
if(flSPR==1){
	aOk->Execute();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxOkClick(TObject *Sender)
{
//
TcxGridDataController* dc = cxGridTVw->DataController;
struct fdate fdsw;

int ii;
ii=dc->FocusedRecordIndex;

swb(&fduyy,&fdsw,sizeof(struct fdate));

	CLR(vsr);
	mov(&fdsw,&vsr.fd,sizeof(struct fdate));
  vsr.kod=(unsigned char)cxSpinKod->Value;
	if(farel(fvsr,&vsr,sizeof(vsr)) == 0){
  	vsr.kodrf=(long)cxCEdKODRF->Value;
  	vsr.sk=cxCEdSK->Value;
  	vsr.ske=cxCEdSKE->Value;
    farwl(fvsr,&vsr,sizeof(vsr));

    dc->Edit();
		dc->Values[ii][cxGridTVwKODRF->Index]  = (long)cxCEdKODRF->Value;
		dc->Values[ii][cxGridTVwSK->Index]     = cxCEdSK->Value;;
		dc->Values[ii][cxGridTVwSKE->Index]    = cxCEdSKE->Value;
    dc->Post();
	}
  cxDate->Enabled=true;
	dxLayoutGRID->Visible=true;
	dxLayoutED->Visible=false;
  cxGrid1->SetFocus();

}
//---------------------------------------------------------------------------


void __fastcall TfrSpNVSR::cxDateExit(TObject *Sender)
{
unsigned short dd,mm,yy;
TDateTime rDate;

	if(cxDate->EditValue.IsNull()){
		cxDate->Date=EncodeDate(b->uyy.yy+1980,1,1);
	}
	if(!cxDate->EditValue.IsNull()){
		DecodeDate(cxDate->Date,yy,mm,dd);
		fduyy.fd_dd=1;
		fduyy.fd_mm=1;
		fduyy.fd_yy=yy-1980;
	}
	if(cmp(&fduyy,&ofduyy,2)!=0){
		mov(&fduyy,&ofduyy,2);
		aRefresh->Execute();
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxDateEnter(TObject *Sender)
{
aExit->Enabled=true;
aExit->Visible=true;
aExit->ShortCut=VK_ESCAPE;

}
//---------------------------------------------------------------------------

void __fastcall TfrSpNVSR::cxDateKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN)
    Key = VK_TAB;
}
//---------------------------------------------------------------------------

