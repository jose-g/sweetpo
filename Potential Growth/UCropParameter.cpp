//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Crop.cpp>
#include "UCropParameter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCropParameter *frmCropParameter;
//---------------------------------------------------------------------------
__fastcall TfrmCropParameter::TfrmCropParameter(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmCropParameter::EnterInformation(Crop* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::cmdApplyClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    SaveData();
    Close();
  }
}
//---------------------------------------------------------------------------
bool TfrmCropParameter::Validate()
{
  TEdit *casilla=new TEdit(this);
  int cod=0; //0 : indica que no hay errores
  casilla = FindDataError(&cod);
  if(cod!=0)
  {
    ShowMessageError(cod);
    casilla->SetFocus();
    return false;
  }
  else
  {
    return true;
  }
}
//---------------------------------------------------------------------------
TEdit* TfrmCropParameter::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
  try
  {
    datod=edPlantDensity->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPlantDensity;
  }
  try
  {
    datod=edMaxgc->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxgc;
  }
  try
  {
    datod=edIniLig->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edIniLig;
  }
  try
  {
    datod=edIniGro->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edIniGro;
  }
  try
  {
    datod=edDurLeaf->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDurLeaf;
  }
  try
  {
    datod=edThermal->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edThermal;
  }
  try
  {
    datod=edMaxHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxHI;
  }
  try
  {
    datod=edAsyHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAsyHI;
  }
  try
  {
    datod=edSlopeHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edSlopeHI;
  }
  try
  {
    datod=edDMContent->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDMContent;
  }
  try
  {
    datod=edAveLight->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAveLight;
  }
  try
  {
    datoi=edEmDay->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edEmDay;
  }
  try
  {
    datod=edDMIVar->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDMIVar;
  }
  try
  {
    datod=edBaseTemp->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edBaseTemp;
  }
  return edBaseTemp;
}
//---------------------------------------------------------------------------
void TfrmCropParameter::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer!", "Warning!", MB_OK);
  }
  if(_cod==2)
  {
    Application->MessageBox("The value should be a real!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmCropParameter::SaveData()
{
   cond->SelectedCrop = cbCrop->ItemIndex;
   cond->plant->N=edPlantDensity->Text.ToDouble();
   cond->plant->fcl=edMaxgc->Text.ToDouble();
   cond->plant->F0=edIniLig->Text.ToDouble();
   cond->plant->R0=edIniGro->Text.ToDouble();
   cond->plant->d=edDurLeaf->Text.ToDouble();
   cond->plant->t50=edThermal->Text.ToDouble();
   cond->plant->LUE=edAveLight->Text.ToDouble();
   cond->plant->EDay=edEmDay->Text.ToInt();
   cond->plant->v=edDMIVar->Text.ToDouble();
   cond->plant->t0=edBaseTemp->Text.ToDouble();
   cond->tuber->M=edMaxHI->Text.ToDouble();
   cond->tuber->A=edAsyHI->Text.ToDouble();
   cond->tuber->b=edSlopeHI->Text.ToDouble();
   cond->tuber->DMCont=edDMContent->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<cond->CropNumber;i++)
  {
     cbCrop->Items->Add(cond->CropList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCropParameter::PutValuesOnForm()
{
   cbCrop->ItemIndex=cond->SelectedCrop;
   ItemSelected=cond->SelectedCrop;
   edPlantDensity->Text=cond->plant->N;
   edMaxgc->Text=cond->plant->fcl;
   edIniLig->Text=cond->plant->F0;
   edIniGro->Text=cond->plant->R0;
   edDurLeaf->Text=cond->plant->d;
   edThermal->Text=cond->plant->t50;
   edAveLight->Text=cond->plant->LUE;
   edEmDay->Text=cond->plant->EDay;
   edDMIVar->Text=cond->plant->v;
   edBaseTemp->Text=cond->plant->t0;
   edMaxHI->Text=cond->tuber->M;
   edAsyHI->Text=cond->tuber->A;
   edSlopeHI->Text=cond->tuber->b;
   edDMContent->Text=cond->tuber->DMCont;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::cbCropClick(TObject *Sender)
{
  int sel;
  sel=cbCrop->ItemIndex;
  if(ItemSelected!=sel)
  {
    Crop *temp=new Crop();
    temp->DefaultValuesForKindOfCrop(sel);
    edMaxgc->Text=temp->plant->fcl;
    edIniLig->Text=temp->plant->F0;
    edIniGro->Text=temp->plant->R0;
    edDurLeaf->Text=temp->plant->d;
    edThermal->Text=temp->plant->t50;
    edAveLight->Text=temp->plant->LUE;
    edPlantDensity->Text=temp->plant->N;
    edMaxHI->Text=temp->tuber->M;
    edAsyHI->Text=temp->tuber->A;
    edSlopeHI->Text=temp->tuber->b;
    edDMContent->Text=temp->tuber->DMCont;
    delete temp;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameter::cbCropChange(TObject *Sender)
{
  ItemSelected=cbCrop->ItemIndex;
}
//---------------------------------------------------------------------------

