//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPresentation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPresentation *frmPresentation;
//---------------------------------------------------------------------------
__fastcall TfrmPresentation::TfrmPresentation(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPresentation::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
