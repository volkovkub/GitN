// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "progress.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxProgressBar"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma resource "*.dfm"
TfrProgress *frProgress;

// ---------------------------------------------------------------------------
__fastcall TfrProgress::TfrProgress(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------
