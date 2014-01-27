//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include <Report.cpp>
#include "UReportGraphMenuPG.h"
#include "UDMProd.h"
#include "UCCGraph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportGraphMenuPG *frmReportGraphMenuPG;
//---------------------------------------------------------------------------
__fastcall TfrmReportGraphMenuPG::TfrmReportGraphMenuPG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportGraphMenuPG::EnterInformation(Report* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::butCCClick(TObject *Sender)
{
  int existe=access(cond->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmCCGraph *frm = new TfrmCCGraph(this);
    frm->EnterInformation(cond->Archivo4);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::butTotalDMClick(TObject *Sender)
{
  int existe=access(cond->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmDMProd *frm = new TfrmDMProd(this);
    frm->EnterInformation(cond->Archivo4);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

