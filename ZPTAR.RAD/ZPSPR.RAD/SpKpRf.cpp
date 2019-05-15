//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"

extern struct compar *c_p;

#include "wtzp.h"
#include "UDM.h"
#include "SpKpRf.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataControllerConditionalFormattingRulesManagerDialog"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxImageComboBox"
#pragma link "cxImageList"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
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
#pragma link "FamTableXe10LC"
#pragma resource "*.dfm"
TSpKpRf *SpKpRf;
//---------------------------------------------------------------------------
__fastcall TSpKpRf::TSpKpRf(TComponent* Owner)
	: Tfraspr03(Owner)
{
}
//---------------------------------------------------------------------------
short fmafw(struct ffcb *f,char *nk,char t,char l,char ll,char *n){
	atoem(n,n);
	return fmaf(f,nk,t,l,ll,n);
}
//---------------------------------------------------------------------------
int IniRfi(struct zpsppar *par,struct fdate *fdpar,int dpruw,uchar dfin){
int ret=-1;

	SpKpRf = new TSpKpRf(Application);


	Application->ProcessMessages();
 	try{
		SpKpRf->yyu.fd_yy=fdpar->fd_yy;
  	SpKpRf->yyu.fd_mm=fdpar->fd_mm;
  	SpKpRf->yyu.fd_dd=1;
		SpKpRf->ukdkp=0;
  	SpKpRf->pruw=dpruw;
  	SpKpRf->prfin=dfin;
		SpKpRf->Tec_owner=0;
	  if(par->par1){
			SpKpRf->fkdrkpn=fafo(c_p->b_zp,"kdrkpn");
			CLR(SpKpRf->kdrkpn);
  	  swb(&par->par1,&SpKpRf->kdrkpn.kdkp,2);
			if(farel(SpKpRf->fkdrkpn,&SpKpRf->kdrkpn,sizeof(SpKpRf->kdrkpn))==0){
				swb(&SpKpRf->kdrkpn.kdkp,&SpKpRf->Tec_owner,2);
			  swb(&SpKpRf->kdrkpn.kdkp,&SpKpRf->ukdkp,2);
				SpKpRf->cxOwnerNm->Text=FmToUn(SpKpRf->kdrkpn.fname, sizeof(SpKpRf->kdrkpn.fname),PgDos);
			  SpKpRf->aRefresh->Execute();
    	}
			fafc(SpKpRf->fkdrkpn);
  	}
  	if(SpKpRf->Tec_owner && SpKpRf->flkol){
		  SpKpRf->fdsRKPN->Active=true;
    }
    else{
    	SpKpRf->aOk->Enabled=false;
    	SpKpRf->aOk->Visible=false;
    	SpKpRf->aExit->Enabled=false;
    	SpKpRf->aExit->Visible=false;
    }
   	SpKpRf->aExit->Enabled=true;
   	SpKpRf->aExit->Visible=true;


    SpKpRf->ShowModal();
    ret=SpKpRf->aRet;
    if(ret==1){
    	if(SpKpRf->MyTag==2){
      	 par->par1=SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->AsInteger;
	       par->par2=SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
  	     par->tn=SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("tn")->AsInteger;
    	   CLR(par->nm);
				 strcat(par->nm,SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("fname")->AsAnsiString.c_str());
				 CLR(par->nm1);
  	     strcat(par->nm1,SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("sname")->AsAnsiString.c_str());
				 CLR(par->nm2);
				 strcat(par->nm2,SpKpRf->cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("kdnm")->AsAnsiString.c_str());
				 SpKpRf->fdsRKPN->Active=false;
      }
   	}
 	}
 	catch(...){
 	}
  SpKpRf->fdsRKPN->Close();
	fafd(c_p->b_wrk,"rkpn");
	delete SpKpRf;
return ret;
}
//---------------------------------------------------------------------------
void __fastcall TSpKpRf::fdsRKPNAfterScroll(TDataSet *DataSet)
{
if(MyTag==2){
	cxDBfname->Text=cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("fname")->AsString;
	dxStatusBar1->Panels->Items[0]->Text=cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->AsString;
 	dxStatusBar1->Panels->Items[1]->Text=cxGridDBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->AsString;
}
}
//---------------------------------------------------------------------------

void __fastcall TSpKpRf::aRefreshExecute(TObject *Sender)
{
//
AnsiString rAss;
ushort rrowner;
swb(&SpKpRf->ukdkp,&rrowner,2);
//START RKPN

fafd(c_p->b_wrk,"rkpn");
fafe(c_p->b_wrk,"rkpn",0,2,252);
if((SpKpRf->ff=fafo(c_p->b_wrk,"rkpn"))!=0){     // Проверка на открытие структуры
	fmdf(SpKpRf->ff);                          // Удаление описания структуры
// описание структуры
	fmafw(SpKpRf->ff,"kdkp"  ,'d',5,0,"код уникальный");

	fmafw(SpKpRf->ff,"owner" ,'i',5,0,"код родителя");
	fmafw(SpKpRf->ff,"tn"    ,'l',8,0,"табельный номер");
	fmafw(SpKpRf->ff,"sname" ,'s',40,0,"краткое наименование");
	fmafw(SpKpRf->ff,"fname" ,'s',160,0,"полное наименование");
	fmafw(SpKpRf->ff,"uw"    ,'u',3,0,"признак увольнения");
	fmafw(SpKpRf->ff,"kdnm"  ,'s',40,0,"наименование должности");
	fmafw(SpKpRf->ff,"fdp"   ,'D',8,1,"Дата поступления");
	fmafw(SpKpRf->ff,"fdu"   ,'D',8,1,"Дата увольнения");
	fmafw(SpKpRf->ff,"knp"   ,'u',3,0,"признак увольнения");

  if(fmchdf(SpKpRf->ff)!=0){
  	armerr(1,"Ошибка описания стркутуры rkpn");
  }

	SpKpRf->fkdrnkp=fafo(c_p->b_zp,"kdrnkp");

	SpKpRf->fkdrkpn=fafo(c_p->b_zp,"kdrkpn");
	SpKpRf->fzplsfi=fafo(c_p->b_zp,"zplsfi");
	SpKpRf->fzpls=fafo(c_p->b_zp,"zpls");
	SpKpRf->fzpsek=fafo(c_p->b_zp,"zpsek");
	SpKpRf->fzpkd=fafo(c_p->b_nc,"zpkd");
	SpKpRf->fzpstag=fafo(c_p->b_zp,"zpstag");


	  CLR(SpKpRf->kdrnkp);
    SpKpRf->kdrnkp.owner=rrowner;//Tec_owner;
  	while(fargl(SpKpRf->fkdrnkp,&SpKpRf->kdrnkp,sizeof(SpKpRf->kdrnkp))==0){
    	if(SpKpRf->kdrnkp.owner==rrowner){
  	  	if(SpKpRf->kdrnkp.tn){
        	if(SpKpRf->prfin){
		  			CLR(SpKpRf->zplsfi);
	  	      SpKpRf->zplsfi.kp=SpKpRf->kdrnkp.kdkp;
  	  	    swb(&SpKpRf->yyu,&SpKpRf->zplsfi.fd,2);
    	      SpKpRf->zplsfi.fin=SpKpRf->prfin;
      		  if(fare(SpKpRf->fzplsfi,&SpKpRf->zplsfi)==0){
        			CLR(SpKpRf->rkpn);
//    		     	MV(ss,SpKpRf->rkpn.kdnm);
      		    SpKpRf->rkpn.owner=SpKpRf->kdrnkp.owner;
	        	  SpKpRf->rkpn.kdkp=SpKpRf->kdrnkp.kdkp;
  	        	SpKpRf->rkpn.uw=SpKpRf->zplsfi.uw;
  	        	SpKpRf->rkpn.knp=SpKpRf->zplsfi.knp;
							SpKpRf->rkpn.tn=SpKpRf->kdrnkp.tn;
		  	  		MV(SpKpRf->kdrnkp.sname,SpKpRf->rkpn.sname);
  	    	  	CLR(SpKpRf->zpstag);
    	    	  SpKpRf->zpstag.kp=SpKpRf->kdrnkp.kdkp;
	    	    	if(fare(SpKpRf->fzpstag,&SpKpRf->zpstag)==0){
	  	  				mov(&SpKpRf->zpstag.fd2,&SpKpRf->rkpn.fdu,sizeof(SpKpRf->rkpn.fdu));
		  	  			mov(&SpKpRf->zpstag.fd1,&SpKpRf->rkpn.fdp,sizeof(SpKpRf->rkpn.fdp));
  	        	}
	    	      if(SpKpRf->zplsfi.dol){
					  		CLR(SpKpRf->zpkd);
  		    	  	swb(&SpKpRf->zplsfi.dol,&SpKpRf->zpkd.d,2);
	  		    	  if(fare(SpKpRf->fzpkd,&SpKpRf->zpkd)==0){
		  		  			MV(SpKpRf->zpkd.n,SpKpRf->rkpn.kdnm);
	        		  }
  	        	}
	    	      else{
								rAss=" НЕТ ДОЛЖНОСТИ В ЛС";
								OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
							}
  	  				farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
	    	    }
  	    	  else{
    	    		CLR(SpKpRf->rkpn);
							rAss=" !!!НЕТ ЛИЦЕВОГО СЧЕТА";
							OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
							SpKpRf->rkpn.owner=SpKpRf->kdrnkp.owner;
        		  SpKpRf->rkpn.kdkp=SpKpRf->kdrnkp.kdkp;
          		SpKpRf->rkpn.uw=2;
		          SpKpRf->rkpn.tn=SpKpRf->kdrnkp.tn;
			    		MV(SpKpRf->kdrnkp.sname,SpKpRf->rkpn.sname);
      		  	CLR(SpKpRf->zpstag);
        		  SpKpRf->zpstag.kp=SpKpRf->kdrnkp.kdkp;
			        if(fare(SpKpRf->fzpstag,&SpKpRf->zpstag)==0){
			  	  		mov(&SpKpRf->zpstag.fd2,&SpKpRf->rkpn.fdu,sizeof(SpKpRf->rkpn.fdu));
	  			  		mov(&SpKpRf->zpstag.fd1,&SpKpRf->rkpn.fdp,sizeof(SpKpRf->rkpn.fdp));
      		    	SpKpRf->yyr.fd_dd=1;
        		  	SpKpRf->yyr.fd_mm=SpKpRf->zpstag.fd2.fd_mm;
	          		SpKpRf->yyr.fd_yy=SpKpRf->zpstag.fd2.fd_yy;
					  		CLR(SpKpRf->zplsfi);
  		  		    SpKpRf->zplsfi.kp=SpKpRf->kdrnkp.kdkp;
	    	    		swb(&SpKpRf->yyr,&SpKpRf->zplsfi.fd,2);
			          SpKpRf->zplsfi.fin=SpKpRf->prfin;
			  	      if(fare(SpKpRf->fzplsfi,&SpKpRf->zplsfi)==0){
		  	  	      if(SpKpRf->zplsfi.dol){
							  		CLR(SpKpRf->zpkd);
  	  			  	  	swb(&SpKpRf->zplsfi.dol,&SpKpRf->zpkd.d,2);
			      			  if(fare(SpKpRf->fzpkd,&SpKpRf->zpkd)==0){
  	  	      	  		MV(SpKpRf->zpkd.n,SpKpRf->rkpn.kdnm);
    	  	      	  }
      	  	      }
        	  	    else{
										rAss=" НЕТ ДОЛЖНОСТИ В ЛС";
										OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
    	  	        }
				  	  		farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
      	    	  }
	        	  }
  		      }
    	    }
          else{ //if(SpKpRf->prfin)
		  			CLR(SpKpRf->zpls);
	  	      SpKpRf->zpls.kp=SpKpRf->kdrnkp.kdkp;
  	  	    swb(&SpKpRf->yyu,&SpKpRf->zpls.fd,2);
      		  if(farel(SpKpRf->fzpls,&SpKpRf->zpls,sizeof(zpls))==0){
        			CLR(SpKpRf->rkpn);
      		    SpKpRf->rkpn.owner=SpKpRf->kdrnkp.owner;
	        	  SpKpRf->rkpn.kdkp=SpKpRf->kdrnkp.kdkp;
  	        	SpKpRf->rkpn.uw=SpKpRf->zpls.uw;
  	        	SpKpRf->rkpn.knp=SpKpRf->zpls.knp;
							SpKpRf->rkpn.tn=SpKpRf->kdrnkp.tn;
		  	  		MV(SpKpRf->kdrnkp.sname,SpKpRf->rkpn.sname);
  	    	  	CLR(SpKpRf->zpstag);
    	    	  SpKpRf->zpstag.kp=SpKpRf->kdrnkp.kdkp;
	    	    	if(fare(SpKpRf->fzpstag,&SpKpRf->zpstag)==0){
	  	  				mov(&SpKpRf->zpstag.fd2,&SpKpRf->rkpn.fdu,sizeof(SpKpRf->rkpn.fdu));
		  	  			mov(&SpKpRf->zpstag.fd1,&SpKpRf->rkpn.fdp,sizeof(SpKpRf->rkpn.fdp));
  	        	}
	    	      if(SpKpRf->zpls.dol){
					  		CLR(SpKpRf->zpkd);
  		    	  	swb(&SpKpRf->zpls.dol,&SpKpRf->zpkd.d,2);
	  		    	  if(fare(SpKpRf->fzpkd,&SpKpRf->zpkd)==0){
		  		  			MV(SpKpRf->zpkd.n,SpKpRf->rkpn.kdnm);
	        		  }
  	        	}
	    	      else{
								rAss=" НЕТ ДОЛЖНОСТИ В ЛС";
								OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
	        	  }
  	  				farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
	    	    }
  	    	  else{//fmre(SpKpRf->fzpls,&SpKpRf->zpls)
							CLR(SpKpRf->rkpn);
							rAss=" !!!НЕТ ЛИЦЕВОГО СЧЕТА";
							OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
      		    SpKpRf->rkpn.owner=SpKpRf->kdrnkp.owner;
        		  SpKpRf->rkpn.kdkp=SpKpRf->kdrnkp.kdkp;
          		SpKpRf->rkpn.uw=2;
		          SpKpRf->rkpn.tn=SpKpRf->kdrnkp.tn;
			    		MV(SpKpRf->kdrnkp.sname,SpKpRf->rkpn.sname);
//	  		  		MV(SpKpRf->kdrkpn.fname,SpKpRf->rkpn.fname);
      		  	CLR(SpKpRf->zpstag);
        		  SpKpRf->zpstag.kp=SpKpRf->kdrnkp.kdkp;
			        if(fare(SpKpRf->fzpstag,&SpKpRf->zpstag)==0){
			  	  		mov(&SpKpRf->zpstag.fd2,&SpKpRf->rkpn.fdu,sizeof(SpKpRf->rkpn.fdu));
	  			  		mov(&SpKpRf->zpstag.fd1,&SpKpRf->rkpn.fdp,sizeof(SpKpRf->rkpn.fdp));
      		    	SpKpRf->yyr.fd_dd=1;
        		  	SpKpRf->yyr.fd_mm=SpKpRf->zpstag.fd2.fd_mm;
	          		SpKpRf->yyr.fd_yy=SpKpRf->zpstag.fd2.fd_yy;
					  		CLR(SpKpRf->zpls);
  		  		    SpKpRf->zpls.kp=SpKpRf->kdrnkp.kdkp;
	    	    		swb(&SpKpRf->yyr,&SpKpRf->zpls.fd,2);
			  	      if(fare(SpKpRf->fzpls,&SpKpRf->zpls)==0){
		  	  	      if(SpKpRf->zpls.dol){
							  		CLR(SpKpRf->zpkd);
  	  			  	  	swb(&SpKpRf->zpls.dol,&SpKpRf->zpkd.d,2);
			      			  if(fare(SpKpRf->fzpkd,&SpKpRf->zpkd)==0){
  	  	      	  		MV(SpKpRf->zpkd.n,SpKpRf->rkpn.kdnm);
    	  	      	  }
      	  	      }
        	  	    else{
										rAss=" НЕТ ДОЛЖНОСТИ В ЛС";
										OemToCharBuffA(rAss.c_str(),SpKpRf->rkpn.kdnm,sizeof(SpKpRf->rkpn.kdnm));
    	  	        }
				  	  		farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
      	    	  }
	        	  }
  		      }
          }
	      }
    	}
      else{
      	break;
      }
		}
    flkol=0;
 		CLR(SpKpRf->rkpn);
    while(fargl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn))==0){
    	flkol++;
			CLR(SpKpRf->zpls);
      SpKpRf->zpls.kp=SpKpRf->rkpn.kdkp;
 	    swb(&SpKpRf->yyu,&SpKpRf->zpls.fd,2);
   	  if(fare(SpKpRf->fzpls,&SpKpRf->zpls)==0){
	     	SpKpRf->rkpn.uw=SpKpRf->zpls.uw;
    		farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
      }
      else{
	     	SpKpRf->rkpn.uw=2;
    		farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
      }
	 		CLR(SpKpRf->kdrkpn);
      SpKpRf->kdrkpn.kdkp=SpKpRf->rkpn.kdkp;
   	  if(fare(SpKpRf->fkdrkpn,&SpKpRf->kdrkpn)==0){
	  		MV(SpKpRf->kdrkpn.fname,SpKpRf->rkpn.fname);
      	farwl(SpKpRf->ff,&SpKpRf->rkpn,sizeof(SpKpRf->rkpn));
      }
    }

		CLR(rkpn);
		while(fargl(ff,&rkpn,sizeof(rkpn))==0){
			if(pruw && rkpn.uw==2){
				fard(ff,&rkpn);
			}
		}

		fafc(SpKpRf->fkdrkpn);
		fafc(SpKpRf->fzpls);
		fafc(SpKpRf->fzplsfi);
		fafc(SpKpRf->fzpkd);
 		fafc(SpKpRf->fzpstag);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSpKpRf::cxGridDBTableView1MouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
	if(WheelDelta>0){
		Handled=true;
		cxGridDBTableView1->NavigatorButtons->Prior->Click();
  }
  else{
		Handled=true;
		cxGridDBTableView1->NavigatorButtons->Next->Click();
  }
}
//---------------------------------------------------------------------------

void __fastcall TSpKpRf::FormShow(TObject *Sender)
{
	if(flkol){
		cxGridDBTableView1->NavigatorButtons->First->Click();
		cxGrid->SetFocus();
		MyTag=2;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSpKpRf::cxGridDBTableView1CustomDrawCell(
			TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
			TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
	TRect ARect;
	int vv;
	vv = AViewInfo->GridRecord->Values[cxGridDBTableView1knp->Index];
	if( vv==4){
		if(!AViewInfo->GridRecord->Focused){
			ACanvas->SetBrushColor(clBtnFace);
			ACanvas->Font->Color = clBlack;
		}
		if(AViewInfo->GridRecord->Focused && !AViewInfo->Selected){
			ACanvas->FillRect(AViewInfo->Bounds,clBtnFace);
			ACanvas->DrawTexT(AViewInfo->Text,AViewInfo->Bounds,cxAlignLeft);
		}
	}
	else{
		if(AViewInfo->GridRecord->Focused && !AViewInfo->Selected){
			ACanvas->FillRect(AViewInfo->Bounds,(TColor)0x00FEECDD);
			ACanvas->DrawTexT(AViewInfo->Text,AViewInfo->Bounds,cxAlignLeft);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSpKpRf::cxGridDBTableView1DblClick(TObject *Sender)
{
	aOk->Execute();	
}
//---------------------------------------------------------------------------

