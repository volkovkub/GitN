//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "UDM.h"
#include "SpKpR.h"
#include "gTnTn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataControllerConditionalFormattingRulesManagerDialog"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
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
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutControlAdapters"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma link "dxStatusBar"
#pragma link "FamTableXe10LC"
#pragma resource "*.dfm"
TfrTNTN *frTNTN;
//---------------------------------------------------------------------------
__fastcall TfrTNTN::TfrTNTN(TComponent* Owner)
	: Tfraspr03(Owner)
{
	aNew->Hint="Создать новый основной Табельный №";
	aNew->Caption="Создать новый основной Табельный №";
	aNewCopy->Hint="Создать новый вспомогательный Табельный №";
	aNewCopy->Caption="Создать новый вспомогательный Табельный №";


}
//---------------------------------------------------------------------------
short fmafw(struct ffcb *f,char *nk,char t,char l,char ll,char *n){
 atoem(n,n);
return fmaf(f,nk,t,l,ll,n);
}
//---------------------------------------------------------------------------
int I_TnTn(){
int ret=-1;
	try{
		frTNTN = new TfrTNTN(Application);
		writebspzp(&frTNTN->bzp);
		frTNTN->aRefresh->Execute();
		frTNTN->ShowModal();
		ret=frTNTN->aRet;
		if(ret!=1){
			fafc(frTNTN->ftntn);
			fafc(frTNTN->fkdrtn);
			fafc(frTNTN->fkpn);
			frTNTN->fdsRTNO->Active=false;
			fafc(frTNTN->frtno);
			fafd(c_p->b_wrk,"rtno");
			frTNTN->fdsRTNS->Active=false;
			fafc(frTNTN->frtns);
			fafd(c_p->b_wrk,"rtns");
		}
	}
	catch(...){
	}
	delete frTNTN;
return ret;
}
void __fastcall TfrTNTN::aRefreshExecute(TObject *Sender)
{
//
struct rtno1 rtno;
struct rtns1 rtns;

	fdsRTNO->Close();
	fdsRTNS->Close();

	fafd(c_p->b_wrk,"rtno");
	fafe(c_p->b_wrk,"rtno",0,2,128);
	if((frtno=fafo(c_p->b_wrk,"rtno"))!=0){     // Проверка на открытие структуры
		fmdf(frtno);                          // Удаление описания структуры
// описание структуры
		fmafw(frtno,"glavn",'d',5,0,"главный kdkp");

		fmafw(frtno,"o_glavn",'i',5,0,"owner главного kdkp");
		fmafw(frtno,"u_glavn",'i',5,0,"учреждение главного kdkp");
		fmafw(frtno,"tn_glavn",'l',8,0,"табельный номер главного kdkp");
		fmafw(frtno,"nm_glavn",'s',40,0,"сотрудник");
		fmafw(frtno,"nmo_glavn",'s',40,0,"подразделение сотрудника");
		fmafw(frtno,"nmu_glavn",'s',40,0,"учреждение сотрудника");
		if(fmchdf(frtno)!=0){
			armerr(1,"Ошибка описания структуры RTNO");
		}
		ftntn  =fafo(c_p->b_zp,"zptntn");
		fkdrtn =fafo(c_p->b_zp,"kdrtn");
		fkpn	 =fafo(c_p->b_zp,"kdrkpn");

		CLR(tntn);
		while(fargl(ftntn,&tntn,sizeof(tntn))==0){
			CLR(kdrtn);
			kdrtn.tn=tntn.glavn;
			if(farel(fkdrtn,&kdrtn,sizeof(kdrtn))==0){
				CLR(rtno);
				rtno.glavn=kdrtn.kdkp;
				CLR(kpn);
				kpn.kdkp=kdrtn.kdkp;
				if(farel(fkpn,&kpn,sizeof(kpn))==0){
					rtno.o_glavn=kpn.owner;				// учреждение или подразделение
					rtno.tn_glavn=kpn.tn;					// табельный номер
					MV(kpn.sname,rtno.nm_glavn);	//ФИО
					CLR(kpn1);
					kpn1.kdkp=kpn.owner;
					if(farel(fkpn,&kpn1,sizeof(kpn1))==0){
						if(kpn1.deptup==1){					// если учреждение
							rtno.u_glavn=kpn1.kdkp;    // учреждение
							MV(kpn1.sname,rtno.nmu_glavn);//наименование учреждения
						}
						else{
							MV(kpn1.sname,rtno.nmo_glavn);//наименование подразделения
							kdpasp(&kpn1);
							farel(fkpn,&kpn1,sizeof(kpn1));
							rtno.u_glavn=kpn1.kdkp;
							MV(kpn1.sname,rtno.nmu_glavn);//наименование учреждения
						}
					}
					farwl(frtno,&rtno,sizeof(rtno));
				}
			}
		}
	}
	fafd(c_p->b_wrk,"rtns");
	fafe(c_p->b_wrk,"rtns",0,4,128);
	if((frtns=fafo(c_p->b_wrk,"rtns"))!=0){     // Проверка на открытие структуры
		fmdf(frtns);                          // Удаление описания структуры
// описание структуры
		fmafw(frtns,"glavn",'d',5,0,"главный kdkp");
		fmafw(frtns,"vspom",'d',5,0,"вспомогательный kdkp");

		fmafw(frtns,"o_vspom",'i',5,0,"owner главного kdkp");
		fmafw(frtns,"u_vspom",'i',5,0,"учреждение главного kdkp");
		fmafw(frtns,"tn_vspom",'l',8,0,"табельный номер главного kdkp");
		fmafw(frtns,"nm_vspom",'s',40,0,"сотрудник");
		fmafw(frtns,"nmo_vspom",'s',40,0,"подразделение сотрудника");
		fmafw(frtns,"nmu_vspom",'s',40,0,"учреждение сотрудника");
		if(fmchdf(frtns)!=0){
			armerr(1,"Ошибка описания структуры RTNS");
		}

		CLR(tntn);
		while(fargl(ftntn,&tntn,sizeof(tntn))==0){
			CLR(kdrtn);
			kdrtn.tn=tntn.glavn;
			if(farel(fkdrtn,&kdrtn,sizeof(kdrtn))==0){
				CLR(kdrtn1);
				kdrtn1.tn=tntn.vspom;
				if(farel(fkdrtn,&kdrtn1,sizeof(kdrtn1))==0){
					CLR(rtns);
					rtns.glavn=kdrtn.kdkp;
					rtns.vspom=kdrtn1.kdkp;
					CLR(kpn);
					kpn.kdkp=kdrtn1.kdkp;
					if(farel(fkpn,&kpn,sizeof(kpn))==0){
						rtns.o_vspom = kpn.owner;				// учреждение или подразделение
						rtns.tn_vspom= kpn.tn;					// табельный номер
						MV(kpn.sname,rtns.nm_vspom);	//ФИО
						CLR(kpn1);
						kpn1.kdkp = kpn.owner;
						if(farel(fkpn,&kpn1,sizeof(kpn1))==0){
							if(kpn1.deptup==1){							 // если учреждение
								rtns.u_vspom=kpn1.kdkp;    		 // учреждение
								MV(kpn1.sname,rtns.nmu_vspom); //наименование учреждения
							}
							else{
								MV(kpn1.sname,rtns.nmo_vspom); //наименование подразделения
								kdpasp(&kpn1);
								farel(fkpn,&kpn1,sizeof(kpn1));
								rtns.u_vspom=kpn1.kdkp;
								MV(kpn1.sname,rtns.nmu_vspom); //наименование учреждения
							}
						}
					}
					farwl(frtns,&rtns,sizeof(rtns));
				}
			}
		}
	}
	fdsRTNS->Open();
	cxGrid2DBTableView1->NavigatorButtons->First->Click();
	cxGrid2DBTableView1->ApplyBestFit(NULL,True,True);

	fdsRTNO->Open();
//	cxGrid1DBTableView1->ViewData->Expand(false);
	cxGrid1DBTableView1->NavigatorButtons->First->Click();
	cxGrid1DBTableView1->ApplyBestFit(NULL,True,True);
}
//---------------------------------------------------------------------------
void __fastcall TfrTNTN::cxGrid1DBTableView1CustomDrawCell(
			TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
			TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
	if ((!AViewInfo->Selected) && AViewInfo->GridRecord->Focused) {
		ACanvas->Brush->Color = clGradientInactiveCaption;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxGrid2DBTableView1MouseWheel(TObject *Sender,
			TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
	if(WheelDelta>0){
		Handled=true;
		cxGrid2DBTableView1->NavigatorButtons->Prior->Click();
	}
	else{
		Handled=true;
		cxGrid2DBTableView1->NavigatorButtons->Next->Click();
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrTNTN::cxGrid1Enter(TObject *Sender)
{
	aNew->Enabled=true;
	aNew->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxGrid1DBTableView1FocusedRecordChanged(
			TcxCustomGridTableView *Sender, TcxCustomGridRecord *APrevFocusedRecord,
			TcxCustomGridRecord *AFocusedRecord, bool ANewItemRecordFocusingChanged)
{
Variant Glavn;

if(cxGrid1DBTableView1->DataController->RecordCount){
	if(AFocusedRecord->IsData){
		aDel->Enabled=true;
		aDel->Visible=true;
		aNewCopy->Enabled=true;
		aNewCopy->Visible=true;
		Glavn=cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("glavn")->Value;
		cxGrid2DBTableView1->DataController->Filter->BeginUpdate();
		try {
			cxGrid2DBTableView1->DataController->Filter->Root->Clear();
			cxGrid2DBTableView1->DataController->Filter->Root->AddItem(cxGrid2DBTableView1glavn, foEqual, Glavn,Glavn);
		}__finally {
			cxGrid2DBTableView1->DataController->Filter->EndUpdate();
			cxGrid2DBTableView1->DataController->Filter->Active=true;
		}
	}
	else{
		aDel->Enabled=false;
		aDel->Visible=false;
		aNewCopy->Enabled=false;
		aNewCopy->Visible=false;
		Glavn=0;
		cxGrid2DBTableView1->DataController->Filter->BeginUpdate();
		try {
			cxGrid2DBTableView1->DataController->Filter->Root->Clear();
			cxGrid2DBTableView1->DataController->Filter->Root->AddItem(cxGrid2DBTableView1glavn, foEqual, Glavn,Glavn);
		}__finally {
			cxGrid2DBTableView1->DataController->Filter->EndUpdate();
			cxGrid2DBTableView1->DataController->Filter->Active=true;
		}
	}
}
else{
	aDel->Enabled=false;
	aDel->Visible=false;
	aNewCopy->Enabled=false;
	aNewCopy->Visible=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxBTotnPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
struct zpsppar par;
	GLAVN=0;
	CLR(par);
	if(Ini2(&par,0,2)==1){
		swb(&par.par1,&GLAVN,2);
		TN_GLAVN=par.tn;
		CLR(kpn);
		swb(&par.par2,&kpn.kdkp,2);
		if(farel(fkpn,&kpn,sizeof(kpn))==0){
			if(kpn.deptup==1){
				O_GLAVN=kpn.kdkp;
				U_GLAVN=kpn.kdkp;
				CLR(NMU_GLAVN);
				MV(kpn.sname,NMU_GLAVN);//наименование учреждения
			}
			else{
				O_GLAVN=kpn.kdkp;
				CLR(NMO_GLAVN);
				MV(kpn.sname,NMO_GLAVN);//наименование подразделения
				kdpasp(&kpn);
				farel(fkpn,&kpn,sizeof(kpn));
				U_GLAVN=kpn.kdkp;
				CLR(NMU_GLAVN);
				MV(kpn.sname,NMU_GLAVN);//наименование учреждения
			}
		}
		cxBTotn->Text=par.tn;
		cxBTo_fio->Text=par.nm;
		cxTEDu_glavn->Text=OEMtoAL(NMU_GLAVN,sizeof(NMU_GLAVN));
		cxTEDo_glavn->Text=OEMtoAL(NMO_GLAVN,sizeof(NMO_GLAVN));
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::aNewExecute(TObject *Sender)
{
	aDopC->Execute();
	flKor=0;
	dxLayoutControl1Group3->Visible=true;
	dxLayoutControl1Group9->Visible=true;
  dxLayoutControl1Group7->Enabled=true;
	cxGrid1->Enabled=false;
	cxGrid2->Enabled=false;
	cxBTotn->Clear();
	cxBTotn->Enabled=true;
	cxBTotn->SetFocus();
	cxBTo_fio->Clear();
	cxBTo_fio->Enabled=true;
	cxTEDu_glavn->Clear();
	cxTEDu_glavn->Enabled=false;
	cxTEDo_glavn->Clear();
	cxTEDo_glavn->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxOkClick(TObject *Sender)
{
Variant vv;
ushort rr;
ulong gltn,vstn;
struct rtno1 rtno;
struct rtns1 rtns;

	aDopI->Execute();
	priz=0;
	//Записать
	if(flKor){ // запись всомогательного
		CLR(rtno);
		rtno.glavn=VSPOM;
		if(farel(frtno,&rtno,sizeof(rtno))==0){
			priz=1;
		}
		CLR(rtns);
		while(fargl(frtns,&rtns,sizeof(rtns))==0){
			if(rtns.vspom==VSPOM){
				priz=2;
			}
		}
		if(priz==0 && VSPOM!=0){	//выбранного сотрудника нет в основном и вспомогательном списке
			gltn=fdsRTNOtn_glavn->Value;
			fdsRTNS->Insert();
			fdsRTNSglavn->Value=fdsRTNOglavn->Value;
			swb(&VSPOM,&rr,2);
			fdsRTNSvspom->AsInteger=rr;
			swb(&O_VSPOM,&rr,2);
			fdsRTNSo_vspom->AsInteger=rr;
			swb(&U_VSPOM,&rr,2);
			fdsRTNSu_vspom->AsInteger=rr;
			fdsRTNStn_vspom->Value=TN_VSPOM;
			vstn=fdsRTNStn_vspom->Value;
			fdsRTNSnm_vspom->AsString=cxBTs_fio->Text;
			fdsRTNSnmo_vspo->AsString=cxTEDo_vspom->Text;
			fdsRTNSnmu_vspo->AsString=cxTEDu_vspom->Text;
			fdsRTNS->Post();
			CLR(tntn);
			swb(&gltn,&tntn.glavn,4);
			swb(&vstn,&tntn.vspom,4);
			farwl(ftntn,&tntn,sizeof(tntn));
		}
	}
	else{		// запись основного
		CLR(rtno);
		rtno.glavn=GLAVN;
		if(farel(frtno,&rtno,sizeof(rtno))==0){
			priz=1;
		}
		CLR(rtns);
		while(fargl(frtns,&rtns,sizeof(rtns))==0){
			if(rtns.vspom==GLAVN){
				priz=2;
			}
		}
		if(priz==0 && GLAVN!=0){	//выбранного сотрудника нет в основном и вспомогательном списке
			fdsRTNO->Insert();
			swb(&GLAVN,&rr,2);
			fdsRTNOglavn->AsInteger=rr;
			swb(&O_GLAVN,&rr,2);
			fdsRTNOo_glavn->AsInteger=rr;
			swb(&U_GLAVN,&rr,2);
			fdsRTNOu_glavn->AsInteger=rr;
			fdsRTNOtn_glavn->Value=TN_GLAVN;
			fdsRTNOnm_glavn->AsString=cxBTo_fio->Text;
			fdsRTNOnmo_glav->AsString=cxTEDo_glavn->Text;
			fdsRTNOnmu_glav->AsString=cxTEDu_glavn->Text;
			fdsRTNO->Post();
		}
	}
	cxGrid1->Enabled=true;
	cxGrid2->Enabled=true;
	dxLayoutControl1Group3->Visible=false;
	dxLayoutControl1Group4->Visible=false;
	dxLayoutControl1Group9->Visible=false;
	if(flKor){
		cxGrid2DBTableView1->ApplyBestFit(NULL,True,True);
		vv=TN_VSPOM;
		cxGrid2DBTableView1->DataController->Search->Locate(4,vv);
		cxGrid2->SetFocus();
	}
	else{
		cxGrid1DBTableView1->ApplyBestFit(NULL,True,True);
		vv=TN_GLAVN;
		cxGrid1DBTableView1->DataController->Search->Locate(3,vv);
		cxGrid1->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxCancelClick(TObject *Sender)
{
//Выход без записи
	aDopI->Execute();
	cxGrid1->Enabled=true;
	cxGrid2->Enabled=true;
	dxLayoutControl1Group3->Visible=false;
	dxLayoutControl1Group3->Enabled=true;
	dxLayoutControl1Group4->Visible=false;
	dxLayoutControl1Group9->Visible=false;
	cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::aNewCopyExecute(TObject *Sender)
{
//Новый вспомогательный
ushort Owner,Owner_sw;
	aExit->Visible=false;
	aExit->Enabled=false;
	aExit->ShortCut=0;
	flKor=1;
	dxLayoutControl1Group9->Visible=true;
	dxLayoutControl1Group3->Visible=true;
	cxBTotn->Text=fdsRTNOtn_glavn->Value;
	cxBTotn->Enabled=false;
	cxBTo_fio->Text=fdsRTNOnm_glavn->Value;
	cxBTo_fio->Enabled=false;
	cxTEDu_glavn->Text=fdsRTNOnmu_glav->Value;
	cxTEDo_glavn->Text=fdsRTNOnmo_glav->Value;

	CLR(kpn1);
	Owner=fdsRTNOu_glavn->Value;
	swb(&Owner,&Owner_sw,2);
	kpn1.kdkp=Owner_sw;
	kdpasp(&kpn1);
	cxTEDu_glavn->Tag=kpn1.kdkp;

	dxLayoutControl1Group5->Enabled=false;
	dxLayoutControl1Group7->Enabled=false;
	dxLayoutControl1Group4->Visible=true;
	cxBTstn->Clear();
	cxBTstn->Enabled=true;
	cxBTstn->SetFocus();
	cxBTs_fio->Clear();
	cxBTs_fio->Enabled=true;
	cxTEDu_vspom->Clear();
	cxTEDu_vspom->Enabled=false;
	cxTEDo_vspom->Clear();
	cxTEDo_vspom->Enabled=false;
	cxGrid1->Enabled=false;
	cxGrid2->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxBTstnPropertiesButtonClick(TObject *Sender,
			int AButtonIndex)
{
//Выбор вспомогательного табельного номера
struct zpsppar par;
char ss[40];
ushort Owner_sw;
	VSPOM=0;
	Owner_sw=cxTEDu_glavn->Tag;
	CLR(par);
	if(Ini2(&par,0,2)==1){
		swb(&par.par1,&VSPOM,2);
		TN_VSPOM=par.tn;
		CLR(kpn);
		swb(&par.par2,&kpn.kdkp,2);
		if(farel(fkpn,&kpn,sizeof(kpn))==0){
			if(kpn.deptup==1){
				if(kpn.kdkp==Owner_sw){
					O_VSPOM=kpn.kdkp;
					U_VSPOM=kpn.kdkp;
					CLR(NMU_VSPOM);
					MV(kpn.sname,NMU_VSPOM);//наименование учреждения
					cxOk->Enabled=true;
				}
				else{
					armerr(2,"Выбран сотрудник с другого учреждения");
					cxOk->Enabled=false;
				}
			}
			else{
				O_VSPOM=kpn.kdkp;
				CLR(NMO_VSPOM);
				MV(kpn.sname,NMO_VSPOM);//наименование подразделения
				kdpasp(&kpn);
				if(kpn.kdkp==Owner_sw){
					farel(fkpn,&kpn,sizeof(kpn));
					U_VSPOM=kpn.kdkp;
					CLR(NMU_VSPOM);
					MV(kpn.sname,NMU_VSPOM);//наименование учреждения
					cxOk->Enabled=true;
				}
				else{
					armerr(2,"Выбран сотрудник с другого учреждения");
					cxOk->Enabled=false;
				}
			}
		}
		cxBTstn->Text=par.tn;
		cxBTs_fio->Text=par.nm;
		cxTEDu_vspom->Text=OEMtoAL(NMU_VSPOM,sizeof(NMU_VSPOM));
		cxTEDo_vspom->Text=OEMtoAL(NMO_VSPOM,sizeof(NMO_VSPOM));
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::aDelExecute(TObject *Sender)
{
//
ulong rvsTn,rosTn;
ulong vsTn;
ulong osTn;

ushort glavn,vspom;

	if(cxGrid1DBTableView1->IsControlFocused){
		if(armerr(-1,"Удалить основной Табельный Номер и всю связанную с ним информацию\r\n"
							+ fdsRTNOtn_glavn->AsString + " " + fdsRTNOnm_glavn->AsString + "?")==0){
			rosTn=cxGrid1DBTableView1->DataController->DataSet->FieldByName("tn_glavn")->AsInteger;
			if(rosTn){
				swb(&rosTn,&osTn,4);
				CLR(tntn);
				tntn.glavn=osTn;
				while(fargl(ftntn,&tntn,sizeof(tntn))==0 && tntn.glavn==osTn){
					fard(ftntn,&tntn);
				}
				while(cxGrid2DBTableView1->DataController->FilteredRecordCount!=0){
					fdsRTNS->Delete();
				}
				fdsRTNO->Delete();
				if(cxGrid1DBTableView1->DataController->DataSetRecordCount>0){
					cxGrid1DBTableView1->NavigatorButtons->First->Click();
				}
			}
		}
	}


	if(cxGrid2DBTableView1->IsControlFocused){
		if(armerr(-1,"Удалить дополнительный Табельный Номер\r\n"
							+ fdsRTNStn_vspom->AsString + " " + fdsRTNSnm_vspom->AsString + "?")==0){
			rosTn=cxGrid1DBTableView1->DataController->DataSet->FieldByName("tn_glavn")->AsInteger;
			rvsTn=cxGrid2DBTableView1->DataController->DataSet->FieldByName("tn_vspom")->AsInteger;
			if(rvsTn){
				swb(&rosTn,&osTn,4);
				swb(&rvsTn,&vsTn,4);
				CLR(tntn);
				tntn.glavn=osTn;
				tntn.vspom=vsTn;
				if(farel(ftntn,&tntn,sizeof(tntn))==0){
					fard(ftntn,&tntn);
					fdsRTNS->Delete();
					if(cxGrid2DBTableView1->DataController->FilteredRecordCount==0){
						fdsRTNO->Delete();
						cxGrid1->SetFocus();
						cxGrid1DBTableView1->NavigatorButtons->First->Click();
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::cxBTotnKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if(Key==VK_ESCAPE){
  	cxCancel->Click();
	}
	if(Key==VK_RETURN){
  	Key=VK_TAB;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::aDopIExecute(TObject *Sender)
{
	aNew->Enabled=true;
	aNew->Visible=true;
	aNewCopy->Enabled=true;
	aNewCopy->Visible=true;
	aExit->Enabled=true;
	aExit->Visible=true;
	aExit->ShortCut=VK_ESCAPE;
}
//---------------------------------------------------------------------------

void __fastcall TfrTNTN::aDopCExecute(TObject *Sender)
{
	aDel->Enabled=false;
	aDel->Visible=false;
	aNew->Enabled=false;
	aNew->Visible=false;
	aNewCopy->Enabled=false;
	aNewCopy->Visible=false;
	aExit->Enabled=false;
	aExit->Visible=false;
	aExit->ShortCut=0;

}
//---------------------------------------------------------------------------



