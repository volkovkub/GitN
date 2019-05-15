// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "deff.hpp"
#include "wtzp.h"

extern struct compar *c_p;

#include "..\DM_RAD10\UDM.h"
#include "VSkpn.h"
#include "SpKpR.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "aspr03"
#pragma link "cxButtons"
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
#pragma link "cxGridCustomPopupMenu"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridPopupMenu"
#pragma link "cxGridTableView"
#pragma link "cxImageComboBox"
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
#pragma link "dxBarBuiltInMenu"
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
Tfraspr2 *fraspr2;

short fmafw(struct ffcb *f, char *nk, char t, char l, char ll, char *n) {
	atoem(n, n);
	return fmaf(f, nk, t, l, ll, n);
}

// ---------------------------------------------------------------------------
__fastcall Tfraspr2::Tfraspr2(TComponent* Owner) : Tfraspr03(Owner) {

	fafd(c_p->b_wrk, "rkpn");
	fafe(c_p->b_wrk, "rkpn", 0, 2, 253);
	if ((ff = fafo(c_p->b_wrk, "rkpn")) != 0) { // Проверка на открытие структуры
		fmdf(ff); // Удаление описания структуры
		// описание структуры
		fmafw(ff, "kdkp", 'd', 5, 0, "код уникальный");

		fmafw(ff, "owner", 'i', 5, 0, "код родителя");
		fmafw(ff, "tn", 'l', 8, 0, "табельный номер");
		fmafw(ff, "deptup", 'u', 3, 0, "тип подразделения");
		fmafw(ff, "sname", 's', 40, 0, "краткое наименование");
		fmafw(ff, "fname", 's', 160, 0, "полное наименование");
		fmafw(ff, "uw", 'u', 3, 0, "признак увольнения");
		fmafw(ff, "kdnm", 's', 40, 0, "наименование должности");
		fmafw(ff, "fdp", 'D', 8, 1, "Дата поступления");
		fmafw(ff, "fdu", 'D', 8, 1, "Дата увольнения");
		fmafw(ff, "knp", 'u', 3, 0, "признак увольнения");
		if (fmchdf(ff) != 0) {
			armerr(1, "Ошибка описания стркутуры rkpn");
		}

		fafd(c_p->b_wrk, "rkpnm");
		fafe(c_p->b_wrk, "rkpnm", 0, 42, 167);
		if ((ffm = fafo(c_p->b_wrk, "rkpnm")) != 0) { // Проверка на открытие структуры
			fmdf(ffm); // Удаление описания структуры
			// описание структуры
			fmafw(ffm, "sname", 's', 40, 0, "краткое наименование");
			fmafw(ffm, "kdkp", 'd', 5, 0, "код уникальный");

			fmafw(ffm, "owner", 'i', 5, 0, "код родителя");
			fmafw(ffm, "tn", 'l', 8, 0, "табельный номер");
			fmafw(ffm, "deptup", 'u', 3, 0, "тип подразделения");
			fmafw(ffm, "fname", 's', 160, 0, "полное наименование");

			if (fmchdf(ffm) != 0) {
				armerr(1, "Ошибка описания стркутуры RKPNM");
			}
		}
		fkpn = fafo(c_p->b_zp, "kdrkpn");
		fzpls = fafo(c_p->b_zp, "zpls");
		fzpsek = fafo(c_p->b_zp, "zpsek");
		fzpkd = fafo(c_p->b_nc, "zpkd");
		fzpstag = fafo(c_p->b_zp, "zpstag");
		ftn = fafo(c_p->b_zp,"kdrtn");
		fnkp = fafo(c_p->b_zp,"kdrnkp");

	}
}

// ---------------------------------------------------------------------------
// void sss();
// AnsiString TextToFirstUpperCase(AnsiString S);
// void StringToUpper2(AnsiChar *strToConvert);

int Ini2(struct zpsppar *par, int dpruw, int dpru) {
	int ret = -1;
	char ss[160];
	int vv;
	try {
		fraspr2 = new Tfraspr2(Application);
		writebspzp(&fraspr2->bzp);
		fraspr2->KdkpPar1 = 0;
		fraspr2->ukdkp = 0;
		fraspr2->pruw = dpruw;
		fraspr2->pru = dpru;

		// frVSkpn = new TfrVSkpn(Application);
		// frVSkpn->Show();
		// sss();
		// frVSkpn->Close();

		fraspr2->Tec_owner = 0;
		fraspr2->KdkpOwner = par->par2;
		if (par->par1 || par->par2) {
			if (dpru == 1) { // Выбираем Учреждение
				CLR(fraspr2->kpn);
				swb(&par->par1, &fraspr2->kpn.kdkp, 2);
				if (farel(fraspr2->fkpn, &fraspr2->kpn, sizeof(fraspr2->kpn)) == 0) {
					swb(&fraspr2->kpn.owner, &fraspr2->Tec_owner, 2);
					swb(&fraspr2->kpn.kdkp, &fraspr2->ukdkp, 2);
					CLR(fraspr2->usname);
					MV(fraspr2->kpn.sname, fraspr2->usname);
					OemToCharBuffA(fraspr2->usname, fraspr2->usname, sizeof(fraspr2->usname));

					CLR(fraspr2->kpn);
					swb(&fraspr2->Tec_owner, &fraspr2->kpn.kdkp, 2);
					if (farel(fraspr2->fkpn, &fraspr2->kpn, sizeof(fraspr2->kpn)) == 0) {
						fraspr2->cxOwnerNm->Text = FmToUn(fraspr2->kpn.fname, sizeof(fraspr2->kpn.fname), PgDos);
					}
				}
			}
			if (dpru == 2) { // Выбираем Сотрудника
				if (par->par1) { // Выбран сотрудник
				}
				if (par->par2) { // Выбрано Учреждение
					CLR(fraspr2->kpn);
					swb(&par->par2, &fraspr2->kpn.kdkp, 2);
					if (farel(fraspr2->fkpn, &fraspr2->kpn, sizeof(fraspr2->kpn)) == 0) {
						swb(&fraspr2->kpn.owner, &fraspr2->Tec_owner, 2);
						swb(&fraspr2->kpn.kdkp, &fraspr2->ukdkp, 2);
						CLR(fraspr2->usname);
						MV(fraspr2->kpn.sname, fraspr2->usname);
						OemToCharBuffA(fraspr2->usname, fraspr2->usname, sizeof(fraspr2->usname));
						fraspr2->cxOwnerNm->Text = FmToUn(fraspr2->kpn.fname, sizeof(fraspr2->kpn.fname), PgDos);
					}
				}
			}
		}
		frVSkpn = new TfrVSkpn(NULL);
		frVSkpn->dxActivityIndicator1->Active=true;
		frVSkpn->Show();
		fraspr2->aRefresh->Execute();
		frVSkpn->dxActivityIndicator1->Active=false;
		frVSkpn->Free();
//		delete frVSkpn;

		fraspr2->fdsRKPN->Active = true;
		if (fraspr2->Tec_owner) {
			fraspr2->aExit->Enabled = false;
		}
		else {
			fraspr2->aExit->Enabled = true;
		}
		fraspr2->fdsRKPNM->Filter = "[owner]=" + IntToStr(fraspr2->Tec_owner);
		fraspr2->fdsRKPNM->Filtered = true;
		fraspr2->fdsRKPNM->Active = true;
		if (par->par1 || par->par2) {
			if (dpru == 1) { // Выбираем Учреждение
				fraspr2->varqry[0] = fraspr2->usname;
				fraspr2->varqry[1] = fraspr2->ukdkp;
				fraspr2->fdsRKPNM->Locate("sname;kdkp", VarArrayOf(fraspr2->varqry, 2), TLocateOptions());
			}
			if (dpru == 2) { // Выбираем Служащего
				if (par->par1) { // Выбран сотрудник
					if (fraspr2->fdsRKPN->Locate("kdkp", par->par1, TLocateOptions())) {
						fraspr2->KdkpPar1 = par->par1;
					}
					fraspr2->dxLayoutControlcxGrid1->Visible=false;
				}
				if (par->par2) { // Выбрано Учреждение
					fraspr2->varqry[0] = fraspr2->usname;
					fraspr2->varqry[1] = fraspr2->ukdkp;
					fraspr2->fdsRKPNM->Locate("sname;kdkp", VarArrayOf(fraspr2->varqry, 2), TLocateOptions());
				}
				//fraspr2->dxLayoutControlcxGrid1->Visible = false;
			}
		}
		if (fraspr2->fdsRKPNMtn->Value) {
			if (fraspr2->cxGrid1DBTableView1deptup->Visible)
				fraspr2->cxGrid1DBTableView1deptup->Visible = false;
			if (fraspr2->cxGrid1DBTableView1tn->Visible == false)
				fraspr2->cxGrid1DBTableView1tn->Visible = true;
		}
		else {
			if (fraspr2->cxGrid1DBTableView1tn->Visible)
				fraspr2->cxGrid1DBTableView1tn->Visible = false;
			if (fraspr2->cxGrid1DBTableView1deptup->Visible == false)
				fraspr2->cxGrid1DBTableView1deptup->Visible = true;
		}
		fraspr2->ShowModal();
		ret = fraspr2->aRet;
		if (ret == 1) {
			if (fraspr2->MyTag == 1 && fraspr2->pru == 2) {
				ret = -1;
			}
			if (fraspr2->MyTag == 2 && fraspr2->pru == 1) {
				ret = -1;
			}
			if (fraspr2->MyTag == 1 && fraspr2->pru == 1) {
				par->par1 = fraspr2->cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->AsInteger;
				par->par2 = fraspr2->cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
				par->tn = fraspr2->cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("tn")->AsInteger;
				CLR(par->nm);
				strcat(par->nm, fraspr2->cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("fname")->AsAnsiString.c_str());
				CLR(par->nm1);
				strcat(par->nm1, fraspr2->cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("sname")->AsAnsiString.c_str());
			}
			if (fraspr2->MyTag == 2 && fraspr2->pru == 2) {
				if(fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("tn")->AsInteger){
					par->par1 = fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("kdkp")->AsInteger;
					par->par2 = fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
					par->tn = fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("tn")->AsInteger;
					CLR(par->nm);
					strcat(par->nm, fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("fname")->AsAnsiString.c_str());
					CLR(par->nm1);
					strcat(par->nm1, fraspr2->VwKDKP->DataController->DataSource->DataSet->FieldByName("sname")->AsAnsiString.c_str());
				}
			}
		}
	}
	catch (...) {
	}
	fraspr2->fdsRKPN->Active = false;
	fafd(c_p->b_wrk, "rkpn");
	fraspr2->fdsRKPNM->Active = false;
	fafd(c_p->b_wrk, "rkpnm");
	delete fraspr2;
	return ret;
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	TShiftState MShift;
	MShift = Shift;
	if (Key == VK_RETURN) {
		if (Count) {
//			Key = 0;
			Tec_owner = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->AsInteger;
			cxOwnerNm->Text = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("fname")->AsString;
			if (Tec_owner) {
				aExit->Enabled = false;
			}
			else {
				aExit->Enabled = true;
			}
			if (Owner_tn == 0) {
				fdsRKPNM->Active = false;
				fdsRKPNM->Filter = "[owner]=" + IntToStr(Tec_owner);
				fdsRKPNM->Filtered = true;
				fdsRKPNM->Active = true;
			}
			else {
				dxLayoutControlcxGrid1->Visible = false;
				aKor->Enabled = true;
				aKor->Visible = true;
				acFind->Enabled = !aKor->Visible;
				if (dxLayoutControlcxGrid1->Visible) {
					lgEdFIO->Visible = false;
				}
				dxLayoutControl1Item2->Enabled = true;
				cxGrid->Enabled = true;
				cxGrid->TabStop = true;
				cxGrid->Enabled = true;
				cxGrid->SetFocus();
			}
		}
	}
	if (Key == VK_ESCAPE) {
		Key = 0;
		int kp;
		Tec_owner = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
		if (Tec_owner) {
			aExit->Enabled = false;

			TcxGridDBDataController* dc1 = cxGrid1DBTableView1->DataController;
			dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, cxGrid1DBTableView1kdkp->Index, IntToStr(kp), false, true, true);

			kp = (int)cxGrid1DBTableView1->DataController->Values[cxGrid1DBTableView1->DataController->FocusedRecordIndex]
					[cxGrid1DBTableView1owner->Index];

			cxOwnerNm->Clear();
			fdsKDRKPN_D->Active = true;
			Old_owner = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
			if (fdsKDRKPN_D->Locate("kdkp", Old_owner, TLocateOptions())) {
				Old_owner = fdsKDRKPN_Downer->Value;
				if (fdsKDRKPN_D->Locate("kdkp", Old_owner, TLocateOptions()))
					cxOwnerNm->Text = fdsKDRKPN_Dfname->AsString;
			}
			fdsKDRKPN_D->Active = false;
			fdsRKPNM->Active = false;
			fdsRKPNM->Filter = "[owner]=" + IntToStr(Old_owner);
			fdsRKPNM->Filtered = true;
			fdsRKPNM->Active = true;
		}
		else {
			aExit->Enabled = true;
			Close();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::VwKDKPKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {

	if (Key == VK_ESCAPE && KdkpOwner == 0) {
		unsigned short kp = VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPowner->Index];

		fdsKDRKPN_D->Active = false;

		fdsKDRKPN_D->Active = true;
		Old_owner = VwKDKP->DataController->DataSource->DataSet->FieldByName("owner")->AsInteger;
		if (fdsKDRKPN_D->Locate("kdkp", Old_owner, TLocateOptions())) {
			Old_owner = fdsKDRKPN_Downer->Value;
			if (fdsKDRKPN_D->Locate("kdkp", Old_owner, TLocateOptions()))
				cxOwnerNm->Text = fdsKDRKPN_Dfname->AsString;
		}
		fdsKDRKPN_D->Active = false;
		fdsRKPNM->Active = false;
		fdsRKPNM->Filter = "[owner]=" + IntToStr(Old_owner);
		fdsRKPNM->Filtered = true;
		fdsRKPNM->Active = true;
		dxLayoutControlcxGrid1->Visible = true;
		dxLayoutControlcxGrid1->Enabled = true;
		aKor->Enabled = false;
		aKor->Visible = false;
		acFind->Enabled = !aKor->Visible;
		if (dxLayoutControlcxGrid1->Visible) {
			lgEdFIO->Visible = false;
		}
		cxGrid1->Visible = true;
		cxGrid1->Enabled = true;
		cxGrid1->SetFocus();
		cxGrid->Enabled = false;
		cxGrid->TabStop = false;

		TcxGridDBDataController* dc1 = cxGrid1DBTableView1->DataController;
		dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, cxGrid1DBTableView1kdkp->Index, IntToStr(kp), false, true, true);
	}
}

// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::fdsRKPNAfterScroll(TDataSet *DataSet) {
	if (MyTag == 2) {
		dxStatusBar1->Panels->Items[0]->Text = VwKDKP->DataController->DataSource->DataSet->FieldByName("kdkp")->AsString;
		dxStatusBar1->Panels->Items[1]->Text = VwKDKP->DataController->DataSource->DataSet->FieldByName("owner")->AsString;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::cxGridEnter(TObject *Sender) {
	dxLayoutControl1Item4->Visible = true;
	dxLayoutControl1Group4->Visible = true;
	dxLayoutControl1Item2->Visible = true;
  acFind->Enabled=false;
	MyTag = 2;
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::cxGridExit(TObject *Sender) {
	dxLayoutControl1Item4->Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::fdsRKPNMAfterScroll(TDataSet *DataSet) {
	//
	Variant Vowner;
	AnsiString Sowner;

	Variant Vuw;
	AnsiString Suw;

	// TcxGridDBColumn *ARecord = (TcxGridDBColumn*)cxGrid1DBTableView1->;
	dxStatusBar1->Panels->Items[0]->Text = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->Value;
	dxStatusBar1->Panels->Items[1]->Text = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("owner")->Value;
	Vowner = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->Value;
	Sowner = cxGrid1DBTableView1->DataController->DataSource->DataSet->FieldByName("kdkp")->AsString;
	VwKDKP->DataController->Filter->BeginUpdate();
	try {
		VwKDKP->DataController->Filter->Root->Clear();
		VwKDKP->DataController->Filter->Root->AddItem(VwKDKPowner, foEqual, Vowner, Sowner);
	}
	__finally {
		VwKDKP->DataController->Filter->EndUpdate();
		VwKDKP->DataController->Filter->Active = true;
	}
	Count = VwKDKP->ViewData->RecordCount;
	if (VwKDKP->DataController->DataSource->DataSet->FieldByName("tn")->Value) {
		Owner_tn = 1;
		if (VwKDKPdeptup->Visible)
			VwKDKPdeptup->Visible = false;
		if (VwKDKPtn->Visible == false)
			VwKDKPtn->Visible = true;
		if (VwKDKPuw->Visible == false)
			VwKDKPuw->Visible = true;
		if (VwKDKPkdnm->Visible == false)
			VwKDKPkdnm->Visible = true;
		if (VwKDKPfdp->Visible == false)
			VwKDKPfdp->Visible = true;
		if (VwKDKPfdu->Visible == false)
			VwKDKPfdu->Visible = true;
		if (pruw == 1) { // Показывать работающих
			Vuw = 2;
			Suw = "2";
			VwKDKP->DataController->Filter->BeginUpdate();
			try {
				VwKDKP->DataController->Filter->Root->Clear();
				VwKDKP->DataController->Filter->Root->AddItem(VwKDKPowner, foEqual, Vowner, Sowner);
				VwKDKP->DataController->Filter->Root->AddItem(VwKDKPuw, foNotEqual, Vuw, Suw);
			}
			__finally {
				VwKDKP->DataController->Filter->EndUpdate();
				VwKDKP->DataController->Filter->Active = true;
			}
		}
	}
	else {
		Owner_tn = 0;
		if (VwKDKPdeptup->Visible == false)
			VwKDKPdeptup->Visible = true;
		if (VwKDKPtn->Visible)
			VwKDKPtn->Visible = false;
		if (VwKDKPuw->Visible)
			VwKDKPuw->Visible = false;
		if (VwKDKPkdnm->Visible)
			VwKDKPkdnm->Visible = false;
		if (VwKDKPfdp->Visible)
			VwKDKPfdp->Visible = false;
		if (VwKDKPfdu->Visible)
			VwKDKPfdu->Visible = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::cxGrid1Enter(TObject *Sender) {
  acFind->Enabled=true;
	MyTag = 1;
	dxLayoutControl1Item4->Visible = false;
  dxLayoutControl1Group4->Visible=true;
	if (ukdkp && pru == 2) {
		WORD MKey = VK_RETURN;
		TShiftState MShift;
		cxGrid1DBTableView1KeyDown(cxGrid1DBTableView1, MKey, MShift);
		ukdkp = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::VwKDKPuwCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
		TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	TRect ARect;
	int vv;
	vv = AViewInfo->GridRecord->Values[VwKDKPknp->Index];
	if (vv == 4) {
		if (!AViewInfo->GridRecord->Focused) {
			ACanvas->SetBrushColor(clBtnFace);
			ACanvas->Font->Color = clBlack;
		}
		if (AViewInfo->GridRecord->Focused && !AViewInfo->Selected) {
			ACanvas->FillRect(AViewInfo->Bounds, clBtnFace);
			ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
		}
	}
	else {
		if (AViewInfo->GridRecord->Focused && !AViewInfo->Selected) {
			ACanvas->FillRect(AViewInfo->Bounds, (TColor)0x00FEECDD);
			ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::VwKDKPMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	if (WheelDelta > 0) {
		Handled = true;
		VwKDKP->NavigatorButtons->Prior->Click();
	}
	else {
		Handled = true;
		VwKDKP->NavigatorButtons->Next->Click();
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::acFindExecute(TObject *Sender) {
	cgFind->Visible = acFind->Checked;
	lcSpr->Visible = !acFind->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::bnFindClick(TObject *Sender) {
	// bnFind->Enabled = false;
	if (PrzFind) {
		PrzFind = false;
	}
	else {
		PrzFind = true;
		acFind->Enabled = false;
		bnFind->Caption = "Стоп";
		if (!edFamFind->Text.IsEmpty() || !edNameFind->Text.IsEmpty() || !edOtchFind->Text.IsEmpty() || !edTNFind->Text.IsEmpty()) {
			int i = 0;
			unsigned short sw;
			AnsiString Fam, Name, Otch, FIO, TN;
			struct kdrkpn kpnow;
//			struct zpsek zpsek;
			TcxGridDataController* dc = tvFind->DataController;

			dc->MultiSelect = true;
			dc->SelectAll();
			dc->DeleteSelection();
			dc->MultiSelect = false;
			pbFind->Position = 0;

			CLR(kpn);
			while (fargl(fkpn, &kpn, sizeof(kpn)) == 0) {
				Application->ProcessMessages();
				if (!PrzFind)
					break;
				CLR(zpsek);
				MV(((struct bsp *)c_p->b_sp)->fio, zpsek.fio);
				zpsek.owner = kpn.owner;
				if (fare(fzpsek, &zpsek) == 0) {
					TN = IntToStr((int)kpn.tn);
					OemToCharBuffA(kpn.fname, kpn.fname, sizeof(kpn.fname));
					FNameToFIO(kpn.fname, Fam, Name, Otch);
					Fam = Fam.UpperCase();
					Name = Name.UpperCase();
					Otch = Otch.UpperCase();
					if ((edFamFind->Text.IsEmpty() || Fam.Pos(edFamFind->Text) == 1) && (edNameFind->Text.IsEmpty() || Name.Pos(edNameFind->Text)
							== 1) && (edOtchFind->Text.IsEmpty() || Otch.Pos(edOtchFind->Text) == 1) && (edTNFind->Text.IsEmpty() ||
							TN.Pos(edTNFind->Text) == 1)) {
						++i;
					}
				}
			}
			if (i > 0) {
				pbFind->Properties->Max = i;
				CLR(kpn);
				while (fargl(fkpn, &kpn, sizeof(kpn)) == 0) {
					Application->ProcessMessages();
					if (!PrzFind)
						break;

					CLR(zpsek);
					MV(((struct bsp *)c_p->b_sp)->fio, zpsek.fio);
					zpsek.owner = kpn.owner;
					if (fare(fzpsek, &zpsek) == 0) {
						TN = IntToStr((int)kpn.tn);
						OemToCharBuffA(kpn.fname, kpn.fname, sizeof(kpn.fname));
						FNameToFIO(kpn.fname, Fam, Name, Otch);
						Fam = Fam.UpperCase();
						Name = Name.UpperCase();
						Otch = Otch.UpperCase();
						if ((edFamFind->Text.IsEmpty() || Fam.Pos(edFamFind->Text) == 1) && (edNameFind->Text.IsEmpty() ||
								Name.Pos(edNameFind->Text) == 1) && (edOtchFind->Text.IsEmpty() || Otch.Pos(edOtchFind->Text) == 1) &&
								(edTNFind->Text.IsEmpty() || TN.Pos(edTNFind->Text) == 1)) {
							CLR(kpnow);
							kpnow.kdkp = kpn.owner;
							fare(fkpn, &kpnow);
							OemToCharBuffA(kpnow.fname, kpnow.fname, sizeof(kpnow.fname));
							i = dc->AppendRecord();
							dc->Values[i][tvFindOwner->Index] = ((AnsiString)kpnow.fname).SubString(1, sizeof(kpnow.fname));
							dc->Values[i][tvFindTN->Index] = kpn.tn;
							dc->Values[i][tvFindFIO->Index] = ((AnsiString)kpn.fname).SubString(1, sizeof(kpn.fname));
							swb(&kpn.kdkp, &sw, sizeof(sw));
							dc->Values[i][tvFindKP->Index] = sw;
							swb(&kpn.owner, &sw, sizeof(sw));
							dc->Values[i][tvFindOw->Index] = sw;
							pbFind->Position = pbFind->Position + 1;
						}
					}
				}
			}
			bnFind->Caption = "Искать";
			PrzFind = false;
		}
		acFind->Enabled = true;
	}
	// bnFind->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::FNameToFIO(AnsiString fname, AnsiString &Fam, AnsiString &Name, AnsiString &Otch) {
	uchar pos;

	Fam = "";
	Name = "";
	Otch = "";
	if (fname.Length() > 0) {
		pos = fname.Pos(" ");
		if (pos == 0)
			pos = fname.Pos(".");
		if (pos > 0) {
			Fam = fname.SubString(1, pos - 1).Trim();
			fname = fname.Delete(1, pos).Trim();
		}
		else {
			Fam = fname.Trim();
			fname = "";
		}
		if (!fname.IsEmpty()) {
			pos = fname.Pos(" ");
			if (pos == 0)
				pos = fname.Pos(".");
			if (pos > 0) {
				Name = fname.SubString(1, pos - 1).Trim();
				fname = fname.Delete(1, pos).Trim();
			}
			else {
				Name = fname.Trim();
				fname = "";
			}
			if (!fname.IsEmpty()) {
				pos = fname.Pos(".");
				if (pos > 0) {
					Otch = fname.SubString(1, pos - 1).Trim();
					fname = fname.Delete(1, pos);
				}
				else {
					Otch = fname.Trim();
					fname = "";
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::acSelFindExecute(TObject *Sender) {
	TcxGridDataController* dc = tvFind->DataController;
	TcxGridDBDataController* dc1;
	unsigned short sw, ow, kp;
	struct kdrkpn kpn;

	FCB fkpn = fafo(c_p->b_zp, "kdrkpn");
	ow = (int)dc->Values[dc->FocusedRecordIndex][tvFindOw->Index];
	CLR(kpn);
	swb(&ow, &kpn.kdkp, sizeof(kpn.kdkp));
	fare(fkpn, &kpn);
	fafc(fkpn);

	swb(&kpn.owner, &sw, sizeof(sw));
	Tec_owner = sw;
	OemToCharBuffA(kpn.fname, kpn.fname, sizeof(kpn.fname));
	cxOwnerNm->Text = ((AnsiString)kpn.fname).SubString(1, sizeof(kpn.fname));

	fdsRKPNM->Active = false;
	fdsRKPNM->Filter = "[owner]=" + IntToStr(Tec_owner);
	fdsRKPNM->Filtered = true;
	fdsRKPNM->Active = true;

	dc1 = cxGrid1DBTableView1->DataController;
	dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, cxGrid1DBTableView1kdkp->Index, IntToStr(ow), false, true, true);

	// cxGrid1DBTableView1->DataController->Search->Locate(cxGrid1DBTableView1kdkp->Index,IntToStr(ow));
	kp = (int)dc->Values[dc->FocusedRecordIndex][tvFindKP->Index];

	dc1 = VwKDKP->DataController;
	dc1->FocusedRecordIndex = dc1->FindRecordIndexByText(0, VwKDKPkdkp->Index, IntToStr(kp), false, true, true);
	// VwKDKP->DataController->Search->Locate(cxGridDBTableView1kdkp->Index,IntToStr(kp));
	MyTag = 2;
	fdsRKPNAfterScroll(fdsRKPN);
	// dxStatusBar1->Panels->Items[0]->Text=IntToStr(kp);
	// dxStatusBar1->Panels->Items[1]->Text=IntToStr(ow);
	acFind->Checked = false;
	cgFind->Visible = false;
	lcSpr->Visible = true;

	dxLayoutControlcxGrid1->Visible = false;
	dxLayoutControl1Item4->Visible = !dxLayoutControlcxGrid1->Visible;
	aKor->Enabled = !dxLayoutControlcxGrid1->Visible;
	aKor->Visible = !dxLayoutControlcxGrid1->Visible;
	acFind->Enabled = !aKor->Visible;
	if (dxLayoutControlcxGrid1->Visible) {
		lgEdFIO->Visible = false;
	}
	cxGrid->Enabled = true;
	cxGrid->TabStop = true;
	if (Tec_owner) {
		aExit->Enabled = false;
	}
	else {
		aExit->Enabled = true;
	}
	cxGrid->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::tvFindCellDblClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
		TMouseButton AButton, TShiftState AShift, bool &AHandled) {
	acSelFind->Execute();
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::tvFindCustomDrawCell(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		bool &ADone) {
	if (AViewInfo->GridRecord->Focused && !AViewInfo->Selected) {
		ACanvas->FillRect(AViewInfo->Bounds, (TColor)0x00FEECDD);
		ACanvas->DrawTexT(AViewInfo->Text, AViewInfo->Bounds, cxAlignLeft);
		// ADone=true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::bnCancelFIOClick(TObject *Sender) {
	lgEdFIO->Visible = false;
	cxGrid->Enabled = true;
	acFind->Enabled = !aKor->Visible;
	cxGrid->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::bnSaveFIOClick(TObject *Sender) {
	AnsiString NFfio, NSfio, rAss,rMyaStr,R_F,R_I,R_O;
	if (edTn->Text.ToIntDef(0) == 0) {
		armerr(1, "Не указан или указан неправильный табельный номер!");
		return;
	}
//	struct kdrkpn kpn;
	struct kdrnkp nkp;
	struct kdrtn stn;
//	FCB ftn = fmfo(c_p->b_zp, "kdrtn");
//	FCB fkpn = fmfo(c_p->b_zp, "kdrkpn");

	bool tnok = true;
	long swtn = edTn->Text.ToIntDef(0);
	ushort swkp;
	CLR(stn);
	swb(&swtn, &stn.tn, sizeof(stn.tn));
	if (fare(ftn, &stn) == 0) {
		SW(stn.kdkp, swkp);
		if (kped != swkp) {
			tnok = false;
			armerr(1, "Указанный табельный номер закреплен в системе за другим сотрудником!");
		}
	}

	if (tnok) {
		CLR(kpn);
		swb(&kped, &kpn.kdkp, sizeof(kpn.kdkp));
		if (fare(fkpn, &kpn) == 0) {
			TcxGridDBDataController* dc = VwKDKP->DataController;
			swtn = (long)dc->Values[dc->FocusedRecordIndex][VwKDKPtn->Index];
			CLR(stn);
			swb(&swtn, &stn.tn, sizeof(stn.tn));
			if (fare(ftn, &stn) == 0) {
				fard(ftn, &stn);
			}
			swtn = edTn->Text.ToIntDef(0);
			CLR(stn);
			swb(&swtn, &stn.tn, sizeof(stn.tn));
			swb(&kped, &stn.kdkp, sizeof(stn.kdkp));
			farw(ftn, &stn);

			FCB fnkp = fafo(c_p->b_zp, "kdrnkp");
			CLR(nkp);
			nkp.owner = kpn.owner;
			strncpy(nkp.sname, kpn.sname, sizeof(kpn.sname));
			nkp.kdkp = kpn.kdkp;
			fard(fnkp, &nkp);
			nkp.tn = edTn->Text.ToIntDef(0);
			CLR(nkp.sname);
			rAss = edFIO->Text;
			MVCTOL(rAss.UpperCase().c_str(), nkp.sname, sizeof(nkp.sname));
			farw(fnkp, &nkp);
			fafc(fnkp);

			struct zpkpn zpkpn;
			FCB fzpkpn;
			fzpkpn = fafo(c_p->b_zp, "zpkpn");
			CLR(zpkpn);
			zpkpn.kdkp=kpn.kdkp;
			R_F=edFam->Text.Trim();
			R_I=edName->Text.Trim();
			R_O=edOtch->Text;
			zpkpn.kodz=8;
			rMyaStr=R_F + ";" + R_I + ";" + R_O;
			CharToOemBuffA(rMyaStr.c_str(),zpkpn.nm,(unsigned)rMyaStr.Length()>sizeof(zpkpn.nm)?sizeof(zpkpn.nm):(unsigned)rMyaStr.Length());
			farwl(fzpkpn,&zpkpn,sizeof(zpkpn));
			fafc(fzpkpn);

			CLR(kpn.fname);
			NFfio = edFam->Text + " " + edName->Text + " " + edOtch->Text;

			MVCTOL(NFfio.UpperCase().c_str(), kpn.fname, sizeof(kpn.fname));
			CLR(kpn.sname);
			rAss = edFIO->Text;
			MVCTOL(rAss.UpperCase().c_str(), kpn.sname, sizeof(kpn.sname));
			kpn.tn = edTn->Text.ToIntDef(0);
			farw(fkpn, &kpn);
			fdsRKPN->Edit();
			fdsRKPN->FieldByName("FNAME")->AsString = (edFam->Text + " " + edName->Text + " " + edOtch->Text).UpperCase();
			fdsRKPN->FieldByName("SNAME")->AsString = edFIO->Text.UpperCase();
			fdsRKPN->FieldByName("TN")->AsInteger = edTn->Text.ToIntDef(0);
			fdsRKPN->Post();

			lgEdFIO->Visible = false;
			cxGrid->Enabled = true;
			acFind->Enabled = !aKor->Visible;
			cxGrid->SetFocus();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::aKorExecute(TObject *Sender) {
	AnsiString Fam, Name, Otch;

	kped = VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPkdkp->Index];
	FNameToFIO(VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPfname->Index], Fam, Name, Otch);
	edFam->Text = Fam;
	edName->Text = Name;
	edOtch->Text = Otch;
	if (!VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPsname->Index].IsNull())
		edFIO->Text = VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPsname->Index];
	else
		edFIO->Clear();
	if (!VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPtn->Index].IsNull())
		edTn->Text = VwKDKP->DataController->Values[VwKDKP->DataController->FocusedRecordIndex][VwKDKPtn->Index];
	else
		edTn->Clear();
	lgEdFIO->Visible = true;
	cxGrid->Enabled = false;
	acFind->Enabled = !aKor->Visible;
	edFam->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::edOtchPropertiesChange(TObject *Sender) {
	edFIO->Text = edFam->Text + " " + edName->Text + " " + edOtch->Text;
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::cxGrid1DBTableView1DblClick(TObject *Sender) {
	SendMessage(ActiveControl->Handle, WM_KEYDOWN, VK_RETURN, 0);
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::VwKDKPDblClick(TObject *Sender) {
	aOk->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall Tfraspr2::FormShow(TObject *Sender) {
	if (KdkpPar1 != 0) {
		cxGrid->Enabled = true;
		cxGrid->SetFocus();
		cxGrid->TabStop = true;
		fdsRKPN->Locate("kdkp", KdkpPar1, TLocateOptions());
	}
}

// ---------------------------------------------------------------------------
void __fastcall Tfraspr2::aRefreshExecute(TObject *Sender) {
	int RR, PR;
	AnsiString rAss;

	CLR(kpn);
	while (fargl(fkpn, &kpn, sizeof(kpn)) == 0) {
		Application->ProcessMessages();
		if (kpn.tn) {
			CLR(zpsek);
			MV(bzp.fio, zpsek.fio);
			zpsek.owner = kpn.owner;
			if (fare(fzpsek, &zpsek) == 0) {
				CLR(zpls);
				zpls.kp = kpn.kdkp;
				swb(&bzp.uyy, &zpls.fd, 2);
				if (fare(fzpls, &zpls) == 0) {
					CLR(rkpn);
					rkpn.owner = kpn.owner;
					rkpn.kdkp = kpn.kdkp;
					rkpn.uw = zpls.uw;
					rkpn.knp = zpls.knp;
					rkpn.tn = kpn.tn;
					MV(kpn.sname, rkpn.sname);
					MV(kpn.fname, rkpn.fname);
					CLR(zpstag);
					zpstag.kp = kpn.kdkp;
					if (fare(fzpstag, &zpstag) == 0) {
						mov(&zpstag.fd2, &rkpn.fdu, 2);
						mov(&zpstag.fd1, &rkpn.fdp, 2);
					}
					if (zpls.dol) {
						CLR(zpkd);
						swb(&zpls.dol, &zpkd.d, 2);
						if (fare(fzpkd, &zpkd) == 0) {
							MV(zpkd.n, rkpn.kdnm);
						}
					}
					else {
						rAss = " НЕТ ДОЛЖНОСТИ В ЛС ";
						CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
					}
					farwl(ff, &rkpn, sizeof(rkpn));
				}
				else {
					if (farl(fzpls, &zpls) == 0 && zpls.kp == kpn.kdkp) {
						CLR(rkpn);
						rkpn.owner = kpn.owner;
						rkpn.kdkp = kpn.kdkp;
						rkpn.uw = zpls.uw;
						rkpn.tn = kpn.tn;
						MV(kpn.sname, rkpn.sname);
						MV(kpn.fname, rkpn.fname);
						CLR(zpstag);
						zpstag.kp = kpn.kdkp;
						if (fare(fzpstag, &zpstag) == 0) {
							mov(&zpstag.fd2, &rkpn.fdu, sizeof(rkpn.fdu));
							mov(&zpstag.fd1, &rkpn.fdp, sizeof(rkpn.fdp));
						}
						if (zpls.dol) {
							CLR(zpkd);
							swb(&zpls.dol, &zpkd.d, 2);
							if (fare(fzpkd, &zpkd) == 0) {
								MV(zpkd.n, rkpn.kdnm);
							}
						}
						else {
							rAss = " НЕТ ДОЛЖНОСТИ В ЛС ";
							CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
						}
						farwl(ff, &rkpn, sizeof(rkpn));
					}
					else {
						CLR(rkpn);
						rAss = " !!!НЕТ ЛИЦЕВОГО СЧЕТА ";
						CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
						rkpn.owner = kpn.owner;
						rkpn.kdkp = kpn.kdkp;
						rkpn.uw = 2;
						rkpn.tn = kpn.tn;
						MV(kpn.sname, rkpn.sname);
						MV(kpn.fname, rkpn.fname);
						CLR(zpstag);
						zpstag.kp = kpn.kdkp;
						if (fare(fzpstag, &zpstag) == 0) {
							mov(&zpstag.fd2, &rkpn.fdu, 2);
							mov(&zpstag.fd1, &rkpn.fdp, 2);

							yyr.fd_dd = 1;
							yyr.fd_mm = 12; // fraspr2->zpstag.fd2.fd_mm;
							yyr.fd_yy = zpstag.fd2.fd_yy;
							CLR(zpls);
							zpls.kp = kpn.kdkp;
							swb(&yyr, &zpls.fd, 2);
							if (fare(fzpls, &zpls) == 0) {
								if (zpls.dol) {
									CLR(zpkd);
									swb(&zpls.dol, &zpkd.d, 2);
									if (fare(fzpkd, &zpkd) == 0) {
										MV(zpkd.n, rkpn.kdnm);
									}
								}
								else {
									rAss = " НЕТ ДОЛЖНОСТИ В ЛС ";
									CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
								}
							}
							else {
								RR = zpstag.fd2.fd_yy;
								PR = 0;
								for (RR; RR <= bzp.uyy.yy; RR++) {
									yyr.fd_dd = 1;
									yyr.fd_mm = 12; // fraspr2->zpstag.fd2.fd_mm;
									yyr.fd_yy = RR;
									CLR(zpls);
									zpls.kp = kpn.kdkp;
									swb(&yyr, &zpls.fd, 2);
									if (fare(fzpls, &zpls) == 0) {
										PR = 1;
										if (zpls.dol) {
											CLR(zpkd);
											swb(&zpls.dol, &zpkd.d, 2);
											if (fare(fzpkd, &zpkd) == 0) {
												MV(zpkd.n, rkpn.kdnm);
											}
										}
										else {
											rAss = " НЕТ ДОЛЖНОСТИ В ЛС ";
											CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
										}
									}
								}
								if (PR == 0) {
									rAss = " !!!НЕТ ЛИЦЕВОГО СЧЕТА ";
									CharToOemBuffA(rAss.c_str(), rkpn.kdnm, sizeof(rkpn.kdnm));
								}
							}
						}
						farwl(ff, &rkpn, sizeof(rkpn));
					}
				}
			}
		} // if(fraspr2->kdrkpn.tn)
		else {
			CLR(zpsek);
			MV(bzp.fio, zpsek.fio);
			zpsek.owner = kpn.kdkp;
			if (fare(fzpsek, &zpsek) == 0) {
				CLR(rkpn);
				rkpn.kdkp = kpn.kdkp;
				rkpn.owner = kpn.owner;
				rkpn.deptup = kpn.deptup;
				rkpn.uw = 4;
				MV(kpn.sname, rkpn.sname);
				MV(kpn.fname, rkpn.fname);
				farwl(ff, &rkpn, sizeof(rkpn));
			}
			CLR(zpsek);
			MV(bzp.fio, zpsek.fio);
			zpsek.owner = kpn.kdkp;
			if (fare(fzpsek, &zpsek) == 0) {
				CLR(rkpnm);
				rkpnm.kdkp = kpn.kdkp;
				rkpnm.owner = kpn.owner;
				rkpnm.deptup = kpn.deptup;
				MV(kpn.sname, rkpnm.sname);
				MV(kpn.fname, rkpnm.fname);
				farwl(ffm, &rkpnm, sizeof(rkpnm));
			}
		}
	} // while(fmrg(fraspr2->fkdrkpn,&fraspr2->kdrkpn)==0)
}
// ---------------------------------------------------------------------------
