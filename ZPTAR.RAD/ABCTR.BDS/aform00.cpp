#include <vcl.h>
#pragma hdrstop

#pragma pack(push, 1)
#include "deff.hpp"
#include "spr.h"
#include "bsp.h"
#pragma pack(pop)

extern struct compar *c_p;

#include "aform00.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxImageList"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxPropertiesStore"
#pragma link "dxBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxStatusBar"
#pragma link "cxStyles"
#pragma link "dxRibbon"
#pragma link "dxRibbonCustomizationForm"
#pragma link "dxRibbonSkins"
#pragma resource "*.dfm"
Tfrform00 *frform00;

//---------------------------------------------------------------------------
Dxribbonskins::TdxRibbonBorderIcons __fastcall Tfrform00::GetFormBorderIcons(void){
	return TdxRibbonForm::GetFormBorderIcons() >> rbiDisplayOptions;
}
// ---------------------------------------------------------------------------
void __fastcall Tfrform00::WndProc(Messages::TMessage &Message) {
	bool need_df = true;
	switch (Message.Msg) {
	case WM_SYSCOMMAND: {
			switch (Message.WParam) {
			case SC_MINIMIZE:
				need_df = false;
				for (int ii = (sizeof(c_p->mwnd) / sizeof(c_p->mwnd[0]))-1; ii>=0; ii--) {
					if (c_p->mwnd[ii] != 0) {
						if (c_p->mpwnd[ii] != 2) {;
							ShowWindow((HWND)c_p->mwnd[ii], SW_HIDE);
						}
						else {
							ShowWindow((HWND)c_p->mwnd[ii], SW_MINIMIZE);
						}
					}
				}
				break;
			default:
				break;
			} // switch syscommand
		} // case WM_SYSCOMMAND - Message.WParam
		break;
	default:
		break;
	} // switch(Message.Msg)
	if (need_df)
		TdxRibbonForm::WndProc(Message);
}

// ---------------------------------------------------------------------------
void Tfrform00::MyFonts() {
	if (((struct bsp*)c_p->b_sp)->FntSize) {
		this->Font->Size = ((struct bsp*)c_p->b_sp)->FntSize;
		this->Font->Name = ((struct bsp*)c_p->b_sp)->FntName;
	}
}

// ---------------------------------------------------------------------------
__fastcall Tfrform00::Tfrform00(TComponent* Owner) : TdxRibbonForm(Owner) {
	DisableAero = True;
  if(cxLook->SkinName.Length()){
		dxRibbonA->ColorSchemeName = cxLook->SkinName;
  }
	for (unsigned int ii = 0; ii < (sizeof(c_p->mwnd) / sizeof(c_p->mwnd[0])); ii++) {
		if (c_p->mwnd[ii] == 0) {
			c_p->mwnd[ii] = (int)this->Handle;
			c_p->mpwnd[ii] = 3;
			break;
		}
	}
	cxPropertiesStore->StorageName = ExtractFilePath(Application->ExeName) + "DSK\\"+this->Name + ".ini";
//	aRet = 0;
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::FormClose(TObject *Sender, TCloseAction &Action) {
	for (unsigned int ii = 0; ii < (sizeof(c_p->mwnd) / sizeof(c_p->mwnd[0])); ii++) {
		if ((void*)c_p->mwnd[ii] == this->Handle) {
			c_p->mwnd[ii] = 0;
			c_p->mpwnd[ii] = 0;
		}
	}
}

// ---------------------------------------------------------------------------
/*
 int frasprShow(){
 int ret=-1;
 Application->CreateForm(__classid(Tfraspr03), &fraspr03);
 try{
 fraspr03->ShowModal();
 }
 catch(...){
 }
 delete fraspr03;
 return ret;
 }
 */
void __fastcall Tfrform00::aNewExecute(TObject *Sender) {
	// ShowMessage("aNewExecute");
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aKorExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aDelExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aFiltrStartExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aFiltrFinishExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aPrnJurExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aPrnStrExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aOkExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
	aRet = 1;
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aExitExecute(TObject *Sender) {
	// ShowMessage("aExitExecute");
	// armerr(((TAction *)Sender)->Caption);
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aNewCopyExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aSaveExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aHelpExecute(TObject *Sender) {
	// armerr(((TAction *)Sender)->Caption);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aRefreshExecute(TObject *Sender) {
	// PostMessage(ActiveControl->Handle,WM_KEYDOWN,VK_F6,0);
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aFontExecute(TObject *Sender) {
	MyFonts();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aChekExecute(TObject *Sender) {
	//
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aUnCheckExecute(TObject *Sender) {
	//
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::psStorageAfterLoadProps(TObject *Sender) {
//	MyFonts();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::aExcelExecute(TObject *Sender) {
	//
}

// ---------------------------------------------------------------------------
void __fastcall Tfrform00::psStorageBeforeLoadProps(TObject *Sender) {
	// MyFonts();
}
// ---------------------------------------------------------------------------

void __fastcall Tfrform00::FormCreate(TObject *Sender) {
  AdjustLayoutForNonClientDrawing=false;
	MyFonts();
	TcxPropertiesStoreComponent* My = cxPropertiesStore->Components->Add();
	My->Component = this;
	My->Properties->Add("Height");
	My->Properties->Add("Left");
//	My->Properties->Add("PixelsPerInch");
	My->Properties->Add("Top");
	My->Properties->Add("Width");
	My->Properties->Add("WindowState");
	cxPropertiesStore->Active = true;
	cxPropertiesStore->RestoreFrom();
}
// ---------------------------------------------------------------------------

