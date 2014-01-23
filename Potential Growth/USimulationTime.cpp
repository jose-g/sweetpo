//---------------------------------------------------------------------------
#include <vcl.h>
#include <Time2.cpp>
#pragma hdrstop
#include "USimulationTime.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSimulationTime *frmSimulationTime;
//---------------------------------------------------------------------------
__fastcall TfrmSimulationTime::TfrmSimulationTime(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::EnterInformation(modeling::Time *_cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSimulationTime::cmdSimulateClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    SaveData();
  }
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::PutValuesOnForm()
{
  cbMonth->ItemIndex=cond->MonthStart-1;
  edDay->Text=cond->DayStart;
  edTime->Text=cond->duration;
  edLocation->Text=cond->location;
  edNumSim->Text=cond->repetitions;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSimulationTime::FormShow(TObject *Sender)
{
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
bool TfrmSimulationTime::Validate()
{
  TEdit *box=new TEdit(this);
  int cod=0; //0 : indica que no hay errores
  box = FindDataError(&cod);
  if(cod!=0)
  {
    ShowMessageError(cod);
    box->SetFocus();
    return false;
  }
  else
  {
    return true;
  }
}
//---------------------------------------------------------------------------
TEdit* TfrmSimulationTime::FindDataError(int* _cod)
{
  int datoi;
  try
  {
    datoi=edTime->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edTime;
  }
  try
  {
    datoi=edDay->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edDay;
  }
  return edTime;
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::SaveData()
{
  cond->MonthStart = cbMonth->ItemIndex+1;
  cond->DayStart   = edDay->Text.ToInt();
  cond->duration   = edTime->Text.ToInt();
  char* cp1 = new char[ edLocation->Text.Length() + 1 ];
  strcpy( cp1, edLocation->Text.c_str() );
  cond->location=cp1;
  char* cp2 = new char[ cbMonth->Text.Length() + 1 ];
  strcpy( cp2, cbMonth->Text.c_str() );
  cond->Month=cp2;
  cond->repetitions   = edNumSim->Text.ToInt();
}
//---------------------------------------------------------------------------




