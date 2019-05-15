//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"

#include "spr0018.h"
#include "SpKfrEd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxImageList"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxPropertiesStore"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TfrSpKfrEd *frSpKfrEd;
//---------------------------------------------------------------------------
__fastcall TfrSpKfrEd::TfrSpKfrEd(TComponent* Owner)
	: Tfraspr03(Owner)
{
}
//---------------------------------------------------------------------------
int IniSpKfrEd(int pr,ushort nkdkfr,struct fdate *fdpar){
int ret=-1;
ushort n,ko;
char dss[100];

	frSpKfrEd = new TfrSpKfrEd(Application);
	TcxGridDataController* dc = frSpKfr->cxGridKFRTabVw->DataController;

	frSpKfrEd->fker   = fafonc(c_p->b_nc,"spker");
	frSpKfrEd->fisf   = fafonc(c_p->b_nc,"spisf");
	frSpKfrEd->fsbker = fafonc(c_p->b_nc,"spsbker");
	frSpKfrEd->ftf    = fafonc(c_p->b_nc,"sptf");
	frSpKfrEd->fts    = fafonc(c_p->b_nc,"spts");
	frSpKfrEd->fmrp   = fafonc(c_p->b_nc,"spmrp");

	try{

		frSpKfrEd->cxTxtEdKD->Clear();
		frSpKfrEd->cxTxtEdKO->Clear();
		frSpKfrEd->cxTxtEdKS->Clear();

		frSpKfrEd->cxBtEdBSD->Clear();
		frSpKfrEd->cxBtEdBSK->Clear();
		frSpKfrEd->cxLbBSDBSK->Clear();
		frSpKfrEd->cxTxtEDker->Clear();
		frSpKfrEd->cxTxtEDisf->Clear();
		frSpKfrEd->cxTxtEDsbker->Clear();
		frSpKfrEd->cxTxtEDtf->Clear();
		frSpKfrEd->cxTxtEDts->Clear();
		frSpKfrEd->cxTxtEDmrp->Clear();
		frSpKfrEd->cxLbBSDBSK->Clear();
		frSpKfrEd->cxLbKER->Clear();
		frSpKfrEd->cxLbISF->Clear();
		frSpKfrEd->cxLbSBKER->Clear();
		frSpKfrEd->cxLbTF->Clear();
		frSpKfrEd->cxLbTS->Clear();
		frSpKfrEd->cxLbMRP->Clear();

		n=dc->FocusedRecordIndex;
		//frSpKfrEd->DBEditEhKDKFR->Value=nkdkfr;

//		if(pr==-1){


			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index]))
				frSpKfrEd->cxTxtEdKD->Text=dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index];
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index]))
				frSpKfrEd->cxTxtEdKO->Text=dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index];
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKS->Index]))
				frSpKfrEd->cxTxtEdKS->Text=dc->Values[n][frSpKfr->cxGridKFRTabVwKS->Index];


			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwBSD->Index]))
				frSpKfrEd->cxBtEdBSD->Text=dc->Values[n][frSpKfr->cxGridKFRTabVwBSD->Index];
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwBSK->Index]))
				frSpKfrEd->cxBtEdBSK->Text		=dc->Values[n][frSpKfr->cxGridKFRTabVwBSK->Index];

			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index]) && !VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index])){
				CLR(frSpKfr->op);
				frSpKfr->op.kd=(uchar)dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index];
				ko=(ushort)dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index];
				swb(&ko,&frSpKfr->op.ko,2);
				frSpKfr->op.ks=(uchar)dc->Values[n][frSpKfr->cxGridKFRTabVwKS->Index];
				if(farel(frSpKfr->fop,&frSpKfr->op,sizeof(frSpKfr->op))==0){
					frSpKfrEd->cxLbBSDBSK->Caption="Участок выписки : " + dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index] +
																				 " код операции "  + dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index] +
																				 " наименование " + "'" + OEMtoAL(frSpKfr->op.n,sizeof(frSpKfr->op.n))+"'";
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwKER->Index])){
				frSpKfrEd->cxTxtEDker->Text   =dc->Values[n][frSpKfr->cxGridKFRTabVwKER->Index];
				CLR(frSpKfrEd->spker);
				strcat(frSpKfrEd->spker.ker,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwKER->Index])).c_str());
				if(farel(frSpKfrEd->fker,&frSpKfrEd->spker,sizeof(frSpKfrEd->spker))==0){
					frSpKfrEd->cxLbKER->Caption=OEMtoAL(frSpKfrEd->spker.name,sizeof(frSpKfrEd->spker.name));
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwISF->Index])){
				frSpKfrEd->cxTxtEDisf->Text   =VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwISF->Index]);
				CLR(frSpKfrEd->spisf);
				strcat(frSpKfrEd->spisf.isf,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwISF->Index])).c_str());
				if(farel(frSpKfrEd->fisf,&frSpKfrEd->spisf,sizeof(frSpKfrEd->spisf))==0){
					frSpKfrEd->cxLbISF->Caption=OEMtoAL(frSpKfrEd->spisf.name,sizeof(frSpKfrEd->spisf.name));
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwSBKER->Index])){
				frSpKfrEd->cxTxtEDsbker->Text =VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwSBKER->Index]);
				CLR(frSpKfrEd->spsbker);
				strcat(frSpKfrEd->spsbker.subkesr,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwSBKER->Index])).c_str());
				if(farel(frSpKfrEd->fsbker,&frSpKfrEd->spsbker,sizeof(frSpKfrEd->spsbker))==0){
					frSpKfrEd->cxLbSBKER->Caption=OEMtoAL(frSpKfrEd->spsbker.name,sizeof(frSpKfrEd->spsbker.name));
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwTF->Index])){
				frSpKfrEd->cxTxtEDtf->Text    =VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwTF->Index]);
				CLR(frSpKfrEd->sptf);
				strcat(frSpKfrEd->sptf.tf,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwTF->Index])).c_str());
				if(farel(frSpKfrEd->ftf,&frSpKfrEd->sptf,sizeof(frSpKfrEd->sptf))==0){
					frSpKfrEd->cxLbTF->Caption=OEMtoAL(frSpKfrEd->sptf.name,sizeof(frSpKfrEd->sptf.name));
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwTS->Index])){
				frSpKfrEd->cxTxtEDts->Text    =VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwTS->Index]);
				CLR(frSpKfrEd->spts);
				strcat(frSpKfrEd->spts.ts,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwTS->Index])).c_str());
				if(farel(frSpKfrEd->fts,&frSpKfrEd->spts,sizeof(frSpKfrEd->spts))==0){
					frSpKfrEd->cxLbTS->Caption=OEMtoAL(frSpKfrEd->spts.name,sizeof(frSpKfrEd->spts.name));
				}
			}
			if(!VarIsNull(dc->Values[n][frSpKfr->cxGridKFRTabVwMRP->Index])){
				frSpKfrEd->cxTxtEDmrp->Text   =VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwMRP->Index]);
				CLR(frSpKfrEd->spmrp);
				strcat(frSpKfrEd->spmrp.mrp,AS(VarToStr(dc->Values[n][frSpKfr->cxGridKFRTabVwMRP->Index])).c_str());
				if(farel(frSpKfrEd->fmrp,&frSpKfrEd->spmrp,sizeof(frSpKfrEd->spmrp))==0){
					frSpKfrEd->cxLbMRP->Caption=OEMtoAL(frSpKfrEd->spmrp.name,sizeof(frSpKfrEd->spmrp.name));
				}
			}
//		}
		frSpKfrEd->ShowModal();
		ret=frSpKfrEd->aRet;
		if(ret==1){
				CLR(frSpKfr->zpkfr);
				swb(fdpar,&frSpKfr->zpkfr.fdg,2);
				swb(&nkdkfr,&frSpKfr->zpkfr.kdkfr,2);
				if(farel(frSpKfr->fzpkfr,&frSpKfr->zpkfr,sizeof(frSpKfr->zpkfr))==0){
					frSpKfr->zpkfr.kd=(uchar)frSpKfrEd->cxTxtEdKD->Text.ToIntDef(0);
					ko=(unsigned short)frSpKfrEd->cxTxtEdKO->Text.ToIntDef(0);
					swb(&ko,&frSpKfr->zpkfr.ko,2);
					frSpKfr->zpkfr.ks=(uchar)frSpKfrEd->cxTxtEdKS->Text.ToIntDef(0);
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDker->Text).c_str());
					MV(dss,frSpKfr->zpkfr.ker);
//					strcat(frSpKfr->zpkfr.ker,frSpKfrEd->cxTxtEDker->Text.c_str());
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDsbker->Text).c_str());
					MV(dss,frSpKfr->zpkfr.sbker);
//					strcat(frSpKfr->zpkfr.sbker,frSpKfrEd->cxTxtEDsbker->Text.c_str());
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDisf->Text).c_str());
					MV(dss,frSpKfr->zpkfr.isf);
//					strcat(frSpKfr->zpkfr.isf,frSpKfrEd->cxTxtEDisf->Text.c_str());
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDtf->Text).c_str());
					MV(dss,frSpKfr->zpkfr.tf);
//					strcat(frSpKfr->zpkfr.tf,frSpKfrEd->cxTxtEDtf->Text.c_str());
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDts->Text).c_str());
					MV(dss,frSpKfr->zpkfr.ts);
//					strcat(frSpKfr->zpkfr.ts,frSpKfrEd->cxTxtEDts->Text.c_str());
					CLR(dss);
					strcat(dss,AS(frSpKfrEd->cxTxtEDmrp->Text).c_str());
					MV(dss,frSpKfr->zpkfr.mrp);
//					strcat(frSpKfr->zpkfr.mrp,frSpKfrEd->cxTxtEDmrp->Text.c_str());
					farwl(frSpKfr->fzpkfr,&frSpKfr->zpkfr,sizeof(frSpKfr->zpkfr));
					dc->Edit();
					if(!VarIsNull(frSpKfrEd->cxTxtEdKD->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwKD->Index]    = (AnsiString)frSpKfrEd->cxTxtEdKD->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEdKO->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwKO->Index]    = (AnsiString)frSpKfrEd->cxTxtEdKO->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEdKS->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwKS->Index]    = (AnsiString)frSpKfrEd->cxTxtEdKS->Text;
					if(!VarIsNull(frSpKfrEd->cxBtEdBSD->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwBSD->Index]   = (AnsiString)frSpKfrEd->cxBtEdBSD->Text;
					if(!VarIsNull(frSpKfrEd->cxBtEdBSK->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwBSK->Index]   = (AnsiString)frSpKfrEd->cxBtEdBSK->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDker->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwKER->Index]   = (AnsiString)frSpKfrEd->cxTxtEDker->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDisf->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwISF->Index]   = (AnsiString)frSpKfrEd->cxTxtEDisf->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDsbker->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwSBKER->Index] = (AnsiString)frSpKfrEd->cxTxtEDsbker->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDtf->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwTF->Index]    = (AnsiString)frSpKfrEd->cxTxtEDtf->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDts->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwTS->Index]    = (AnsiString)frSpKfrEd->cxTxtEDts->Text;
					if(!VarIsNull(frSpKfrEd->cxTxtEDmrp->Text))
						dc->Values[n][frSpKfr->cxGridKFRTabVwMRP->Index]   = (AnsiString)frSpKfrEd->cxTxtEDmrp->Text;
					dc->Post();
				}
		}
		else{
			if(pr==0){
				TcxCustomDataController* dCus = frSpKfr->cxGridKFRTabVw->DataController;
				CLR(frSpKfr->zpkfr);
				swb(fdpar,&frSpKfr->zpkfr.fdg,2);
				swb(&nkdkfr,&frSpKfr->zpkfr.kdkfr,2);
				if(farel(frSpKfr->fzpkfr,&frSpKfr->zpkfr,sizeof(frSpKfr->zpkfr))==0){
					fard(frSpKfr->fzpkfr,&frSpKfr->zpkfr);
					dCus->DeleteRecord(n);
					if((n-1)!=-1){
						dc->FocusedRecordIndex = (n-1);
					}
					else{
          	;
          }
				}
			}
		}
	}
	catch(...){
	}
	delete frSpKfrEd;
return ret;
}
void __fastcall TfrSpKfrEd::cxBtEdBSDPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
char bsd[10],bsk[10];
ushort ko;
CLR(bsd);
CLR(bsk);

//	Application->Handle = c_p->hw;
	CLR(frSpKfr->op);
	frSpKfr->op.kd=85;
	if(l_call("G_OPN","GOP",&frSpKfr->op,1)!=-1){
		CLR(bsn);
		mov(&frSpKfr->op.srd,&bsn,6);
		l_call("put_bs"," ",&bsn,bsd,10);
		cxBtEdBSD->Text   = OEMtoAL(bsd,sizeof(bsd));
		mov(&frSpKfr->op.srk,&bsn,6);
		l_call("put_bs"," ",&bsn,bsk,10);
		cxBtEdBSK->Text   = OEMtoAL(bsk,sizeof(bsk));

		cxTxtEdKD->Text=frSpKfr->op.kd;
		swb(&frSpKfr->op.ko,&ko,2);
		cxTxtEdKO->Text=ko;
		cxTxtEdKS->Text=frSpKfr->op.ks;
	}
	cxBtEdBSK->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDkerExit(TObject *Sender)
{
struct spker ker;

	CLR(spker);
	strcat(spker.ker,((AnsiString)cxTxtEDker->Text).c_str());
	if(farel(fker,&spker,sizeof(spker))==0){
		cxTxtEDker->Text=OEMtoAL(spker.ker,sizeof(spker.ker));
		cxLbKER->Caption=OEMtoAL(spker.name,sizeof(spker.name));
	}
	else{
		CLR(ker);
		if(l_call("BUDSPR","GKER",&ker)==1){
			cxTxtEDker->Text=OEMtoAL(ker.ker,sizeof(ker.ker));
			cxLbKER->Caption=ker.name;
		}
	}
	//
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDkerPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct spker ker;

	CLR(ker);
	if(l_call("BUDSPR","GKER",&ker)==1){
		cxTxtEDker->Text=OEMtoAL(ker.ker,sizeof(ker.ker));
		cxLbKER->Caption=ker.name;
	}
}
//---------------------------------------------------------------------------



void __fastcall TfrSpKfrEd::cxTxtEDisfPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct spisf isf;

	CLR(isf);
	if(l_call("BUDSPR","GISF",&isf)==1){
		cxTxtEDisf->Text=OEMtoAL(isf.isf,sizeof(isf.isf));
		cxLbISF->Caption=isf.name;
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDisfExit(TObject *Sender)
{
struct spisf isf;

	CLR(spisf);
	strcat(spisf.isf,((AnsiString)cxTxtEDisf->Text).c_str());
	if(farel(fisf,&spisf,sizeof(spisf))==0){
		cxTxtEDisf->Text=OEMtoAL(spisf.isf,sizeof(spisf.isf));
		cxLbISF->Caption=OEMtoAL(spisf.name,sizeof(spisf.name));
	}
	else{
		CLR(isf);
		if(l_call("BUDSPR","GISF",&isf)==1){
			cxTxtEDisf->Text=OEMtoAL(isf.isf,sizeof(isf.isf));
			cxLbISF->Caption=isf.name;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDsbkerExit(TObject *Sender)
{
struct spsbker sbker;

	CLR(spsbker);
	strcat(spsbker.subkesr,((AnsiString)cxTxtEDsbker->Text).c_str());
	if(farel(fsbker,&spsbker,sizeof(spsbker))==0){
		cxTxtEDsbker->Text=OEMtoAL(spsbker.subkesr,sizeof(spsbker.subkesr));
		cxLbSBKER->Caption=OEMtoAL(spsbker.name,sizeof(spsbker.name));
	}
	else{
		CLR(sbker);
		if(l_call("BUDSPR","GSBKER",&sbker)==1){
			cxTxtEDsbker->Text=OEMtoAL(sbker.subkesr,sizeof(sbker.subkesr));
			cxLbSBKER->Caption=sbker.name;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDsbkerPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct spsbker sbker;
	CLR(sbker);
	if(l_call("BUDSPR","GSBKER",&sbker)==1){
		cxTxtEDsbker->Text=OEMtoAL(sbker.subkesr,sizeof(sbker.subkesr));
		cxLbSBKER->Caption=sbker.name;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrSpKfrEd::cxTxtEDtfPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct sptf tf;

	CLR(tf);
	if(l_call("BUDSPR","GSPTF",&tf)==1){
		cxTxtEDtf->Text=OEMtoAL(tf.tf,sizeof(tf.tf));
		cxLbTF->Caption=tf.name;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrSpKfrEd::cxTxtEDtfExit(TObject *Sender)
{

struct sptf tf;

	CLR(sptf);
	strcat(sptf.tf,((AnsiString)cxTxtEDtf->Text).c_str());
	if(farel(ftf,&sptf,sizeof(sptf))==0){
		cxTxtEDtf->Text=OEMtoAL(sptf.tf,sizeof(sptf.tf));
		cxLbTF->Caption=OEMtoAL(sptf.name,sizeof(sptf.name));
	}
	else{
		CLR(tf);
		if(l_call("BUDSPR","GSPTF",&tf)==1){
			cxTxtEDtf->Text=OEMtoAL(tf.tf,sizeof(tf.tf));
			cxLbTF->Caption=tf.name;
		}
	}


}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDtsExit(TObject *Sender)
{
struct spts ts;

	CLR(spts);
	strcat(spts.ts,((AnsiString)cxTxtEDts->Text).c_str());
	if(farel(fts,&spts,sizeof(spts))==0){
		cxTxtEDts->Text=OEMtoAL(spts.ts,sizeof(spts.ts));
		cxLbTS->Caption=OEMtoAL(spts.name,sizeof(spts.name));
	}
	else{
		CLR(ts);
		if(l_call("BUDSPR","GSPTS",&ts)==1){
			cxTxtEDts->Text=OEMtoAL(ts.ts,sizeof(ts.ts));
			cxLbTS->Caption=ts.name;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDtsPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct spts ts;

CLR(ts);
if(l_call("BUDSPR","GSPTS",&ts)==1){
	cxTxtEDts->Text=OEMtoAL(ts.ts,sizeof(ts.ts));
	cxLbTS->Caption=ts.name;
}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDmrpExit(TObject *Sender)
{
struct spmrp mrp;

	CLR(spmrp);
	strcat(spmrp.mrp,((AnsiString)cxTxtEDmrp->Text).c_str());
	if(farel(fmrp,&spmrp,sizeof(spmrp))==0){
		cxTxtEDmrp->Text=OEMtoAL(spmrp.mrp,sizeof(spmrp.mrp));
		cxLbMRP->Caption=OEMtoAL(spmrp.name,sizeof(spmrp.name));
	}
	else{
		CLR(mrp);
		if(l_call("BUDSPR","GMRP",&mrp)==1){
			cxTxtEDmrp->Text=OEMtoAL(mrp.mrp,sizeof(mrp.mrp));
			cxLbMRP->Caption=mrp.name;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDmrpPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct spmrp mrp;

	CLR(mrp);
	if(l_call("BUDSPR","GMRP",&mrp)==1){
		cxTxtEDmrp->Text=OEMtoAL(mrp.mrp,sizeof(mrp.mrp));
		cxLbMRP->Caption=mrp.name;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::aSaveExecute(TObject *Sender)
{
//Запись
	aRet=1;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::FormShow(TObject *Sender)
{
	cxBtEdBSD->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::aExitExecute(TObject *Sender)
{
	aRet=-1;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxBtEdBSDKeyPress(TObject *Sender, char &Key)
{
//
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxBtEdBSKKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDkerKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDisfKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDsbkerKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDtfKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDtsKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrSpKfrEd::cxTxtEDmrpKeyPress(TObject *Sender, char &Key)
{
	if(Key==VK_RETURN){
		SelectNext(ActiveControl,true,true);
	}
}
//---------------------------------------------------------------------------

