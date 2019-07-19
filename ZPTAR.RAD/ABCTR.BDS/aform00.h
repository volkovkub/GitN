// ---------------------------------------------------------------------------

#ifndef aform00H
#define aform00H
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxImageList.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPropertiesStore.hpp"
#include "dxBar.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "dxLayoutLookAndFeels.hpp"
#include "dxStatusBar.hpp"
#include <System.Actions.hpp>
#include <System.Classes.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ImgList.hpp>
#include "cxStyles.hpp"
#include "dxRibbon.hpp"
#include "dxRibbonCustomizationForm.hpp"
#include "dxRibbonSkins.hpp"
// ---------------------------------------------------------------------------

class Tfrform00 : public TdxRibbonForm {
__published: // IDE-managed Components

	TActionList *alfr;
	TAction *aNew;
	TAction *aKor;
	TAction *aDel;
	TAction *aFiltrStart;
	TAction *aPrnJur;
	TAction *aPrnStr;
	TAction *aOk;
	TAction *aExit;
	TAction *aFiltrFinish;
	TAction *aNewCopy;
	TAction *aSave;
	TAction *aHelp;
	TAction *aRefresh;
	TdxBarManager *BarManager;
	TdxBarButton *dxBarButtonaNew;
	TdxBarButton *dxBarButtonaNewCopy;
	TdxBarButton *dxBarButtonaDel;
	TdxBarButton *dxBarButtonaKor;
	TdxBarButton *dxBarButtonaFiltrStart;
	TdxBarButton *dxBarButtonaFiltrFinish;
	TdxBarButton *dxBarButtonaPrnJur;
	TdxBarButton *dxBarButtonaPrnStr;
	TdxBarButton *dxBarButtonaOk;
	TdxBarButton *dxBarButtonaSave;
	TdxBarButton *dxBarButtonaHelp;
	TdxBarButton *dxBarButtonaExit;
	TdxBarButton *dxBarButtonaExcel;
	TdxBarButton *dxBarButtonRefresh;
	TdxStatusBar *dxStatusBar1;
	TAction *aFont;
	TAction *aChek;
	TdxBarButton *dxBarButtonaCheck;
	TAction *aUnCheck;
	TdxBarButton *dxBarButtonaUnCheck;
	TcxImageList *cxImageLst32;
	TcxLookAndFeelController *cxLook;
	TAction *aExcel;
	TcxPropertiesStore *cxPropertiesStore;
	TdxLayoutGroup *dxLCGroup_Root;
	TdxLayoutControl *dxLC;
	TdxLayoutLookAndFeelList *dxLook;
	TdxLayoutCxLookAndFeel *dxLCF;
	TcxStyleRepository *cxStyleRepositoryVDS;
	TcxStyle *cxStyleIncSearch;
	TdxRibbon *dxRibbonA;
	TdxRibbonTab *dxRibbon1Tab1;

	void __fastcall aNewExecute(TObject *Sender);
	void __fastcall aKorExecute(TObject *Sender);
	void __fastcall aDelExecute(TObject *Sender);
	void __fastcall aFiltrStartExecute(TObject *Sender);
	void __fastcall aFiltrFinishExecute(TObject *Sender);
	void __fastcall aPrnJurExecute(TObject *Sender);
	void __fastcall aPrnStrExecute(TObject *Sender);
	void __fastcall aOkExecute(TObject *Sender);
	void __fastcall aExitExecute(TObject *Sender);
	void __fastcall aNewCopyExecute(TObject *Sender);
	void __fastcall aSaveExecute(TObject *Sender);
	void __fastcall aHelpExecute(TObject *Sender);
	void __fastcall aRefreshExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall aFontExecute(TObject *Sender);
	void __fastcall aChekExecute(TObject *Sender);
	void __fastcall aUnCheckExecute(TObject *Sender);
	void __fastcall psStorageAfterLoadProps(TObject *Sender);
	void __fastcall aExcelExecute(TObject *Sender);
	void __fastcall psStorageBeforeLoadProps(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
	void MyFonts();
	virtual void __fastcall WndProc(Messages::TMessage &Message);

public: // User declarations
	__fastcall Tfrform00(TComponent* Owner);
	virtual Dxribbonskins::TdxRibbonBorderIcons __fastcall GetFormBorderIcons(void);
	int aRet;
};

// ---------------------------------------------------------------------------
extern PACKAGE Tfrform00 *frform00;
// ---------------------------------------------------------------------------
#endif
