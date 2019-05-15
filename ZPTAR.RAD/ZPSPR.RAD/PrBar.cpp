//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrBar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxProgressBar"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TProgressBarForm *ProgressBarForm;
//---------------------------------------------------------------------------
__fastcall TProgressBarForm::TProgressBarForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


