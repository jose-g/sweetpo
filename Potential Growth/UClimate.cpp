//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>

#pragma hdrstop
#include <Climate.cpp>
#include <FileUtility.cpp>
#include "UClimate.h"
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmClimate *frmClimate;
//---------------------------------------------------------------------------
__fastcall TfrmClimate::TfrmClimate(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmClimate::EnterInformation(ClimateFile *_cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Warning!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      num=util->GetFieldsName(List,cond->FileName);
      delete util;
    }
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmClimate::PutValuesOnForm()
{
   edPathFile->Text=cond->FileName;
   edMinTemp->Text=cond->TitTMin;
   edMaxTemp->Text=cond->TitTMax;
   edPrecip->Text=cond->TitPrec;
   edRad->Text=cond->TitRad;
   sgClimate->Cells[0][1]="Day";
   sgClimate->Cells[1][0]="Minimun Temp";
   sgClimate->Cells[2][0]="Maximun Temp";
   sgClimate->Cells[3][0]="Precipitation";
   sgClimate->Cells[4][0]="Radiation";
   sgClimate->Cells[1][1]="oC";
   sgClimate->Cells[2][1]="oC";
   sgClimate->Cells[3][1]="mm";
   sgClimate->Cells[4][1]="MJ*m2";
   int i;
   sgClimate->RowHeights[0]=18;
   sgClimate->RowHeights[1]=18;
   sgClimate->ColWidths[0]=30;
   sgClimate->ColWidths[1]=80;
   sgClimate->ColWidths[2]=80;
   for(i=1;i<=365;i++)
   {
     sgClimate->RowHeights[i+1] = 18;
     sgClimate->Cells[0][i+1]   = i;
     sgClimate->Cells[1][i+1]   = cond->MinTemp[i-1];
     sgClimate->Cells[2][i+1]   = cond->MaxTemp[i-1];
     sgClimate->Cells[3][i+1]   = cond->Precipit[i-1];
     sgClimate->Cells[4][i+1]   = cond->Radiation[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::cmdApplyClick(TObject *Sender)
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
bool TfrmClimate::Validate()
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
TEdit* TfrmClimate::FindDataError(int* _cod)
{
//  int datoi;
//  try
//  {
//    datoi=edInput1->Text.ToInt();
//  }
//  catch(...)
//  {
//    *_cod=1; // 1: No es un valor entero
//    return edInput1;
//  }
//  double datod=0.0;
//  try
//  {
//    datod=edInput2->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput2;
//  }
//  try
//  {
//    datod=edInput3->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput3;
//  }
  return edPathFile;
}
//---------------------------------------------------------------------------
void TfrmClimate::ShowMessageError(int _cod)
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
void TfrmClimate::SaveData()
{
   char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
   strcpy( cp1, edPathFile->Text.c_str() );
   cond->FileName=cp1;
   char* cp2 = new char[ edMinTemp->Text.Length() + 1 ];
   strcpy( cp2, edMinTemp->Text.c_str() );
   cond->TitTMin=cp2;
   char* cp3 = new char[ edMaxTemp->Text.Length() + 1 ];
   strcpy( cp3, edMaxTemp->Text.c_str() );
   cond->TitTMax=cp3;
   char* cp4 = new char[ edPrecip->Text.Length() + 1 ];
   strcpy( cp4, edPrecip->Text.c_str() );
   cond->TitPrec=cp4;
   char* cp5 = new char[ edRad->Text.Length() + 1 ];
   strcpy( cp5, edRad->Text.c_str() );
   cond->TitRad=cp5;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::cmdOpenClimateClick(TObject *Sender)
{
  if(odClimate->Execute())
  {
     edPathFile -> Text = odClimate->FileName;
     char* cp1 = new char[ odClimate->FileName.Length() + 1 ];
     strcpy(cp1, odClimate->FileName.c_str());
     FileData *util=new FileData();
     num=0;
     num = util->GetFieldsName(List,cp1);
     if(num>0)
     {
       edMinTemp  -> Text = "";
       edMaxTemp  -> Text = "";
       edPrecip   -> Text = "";
       edRad      -> Text = "";
       int i,j;
       for(i=2;i<=366;i++)
       {
         for(j=1;j<=4;j++)
         {
           sgClimate->Cells[j][i]="";
         }
       }
     }
     delete cp1;
     delete util;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::cmdMinTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Minimun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMinTemp->Text=frm->ReturnInformation();
    char* dato = new char[edMinTemp->Text.Length() + 1 ];
    strcpy(dato, edMinTemp->Text.c_str());
    cond->TitTMin=dato;
    char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
    strcpy(cp1, edPathFile->Text.c_str());
    cond->GetColumnData(cp1,cond->TitTMin,cond->MinTemp);
    int i;
    for(i=1;i<=365;i++)
    {
     sgClimate->Cells[1][i+1]=cond->MinTemp[i-1];
    }
    delete cp1;
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::SpeedButton3Click(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Maximun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMaxTemp->Text=frm->ReturnInformation();
    char* dato = new char[edMaxTemp->Text.Length() + 1 ];
    strcpy(dato, edMaxTemp->Text.c_str());
    cond->TitTMax=dato;
    char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
    strcpy(cp1, edPathFile->Text.c_str());
    cond->GetColumnData(cp1,cond->TitTMax,cond->MaxTemp);
    int i;
    for(i=1;i<=365;i++)
    {
     sgClimate->Cells[2][i+1]=cond->MaxTemp[i-1];
    }
    delete cp1;
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::SpeedButton4Click(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Precipitation");
  if(frm->ShowModal()==mrOk)
  {
    edPrecip->Text=frm->ReturnInformation();
    char* dato = new char[edPrecip->Text.Length() + 1 ];
    strcpy(dato, edPrecip->Text.c_str());
    cond->TitPrec=dato;
    char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
    strcpy(cp1, edPathFile->Text.c_str());
    cond->GetColumnData(cp1,cond->TitPrec,cond->Precipit);
    int i;
    for(i=1;i<=365;i++)
    {
     sgClimate->Cells[3][i+1]=cond->Precipit[i-1];
    }
    delete cp1;
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimate::SpeedButton5Click(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Radiation");
  if(frm->ShowModal()==mrOk)
  {
    edRad->Text=frm->ReturnInformation();
    char* dato = new char[edRad->Text.Length() + 1 ];
    strcpy(dato, edRad->Text.c_str());
    cond->TitRad=dato;
    char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
    strcpy(cp1, edPathFile->Text.c_str());
    cond->GetColumnData(cp1,cond->TitRad,cond->Radiation);
    int i;
    for(i=1;i<=365;i++)
    {
     sgClimate->Cells[4][i+1]=cond->Radiation[i-1];
    }
    delete cp1;
  }
  delete frm;
}
//---------------------------------------------------------------------------

