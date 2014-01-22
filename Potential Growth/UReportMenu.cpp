//---------------------------------------------------------------------------

#include <vcl.h>
#include <Report.cpp>
#pragma hdrstop

#include "UReportMenu.h"
#include "UReportTXT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportMenu *frmReportMenu;
//---------------------------------------------------------------------------
__fastcall TfrmReportMenu::TfrmReportMenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportMenu::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportMenu::EnterInformation(Report* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportMenu::Button1Click(TObject *Sender)
{
  int existe=access(cond->DMProd, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->DMProd,"Text report : Dry matter production");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportMenu::Button2Click(TObject *Sender)
{
  int existe=access(cond->DMProdResume, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->DMProdResume,"Text report : Dry matter production resume");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
