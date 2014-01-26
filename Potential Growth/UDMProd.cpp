//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop

#include "UDMProd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmDMProd *frmDMProd;
//---------------------------------------------------------------------------
__fastcall TfrmDMProd::TfrmDMProd(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmDMProd::EnterInformation(char* _cond)
{
filename=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProd::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProd::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProd::chbTuberDMClick(TObject *Sender)
{
  tch1->Series[1]->Marks->Visible=chbTuberDM->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProd::FormShow(TObject *Sender)
{
  tc1->Panel=tch1;
  FILE * pFile;
  pFile = fopen (filename,"r");
  ifstream in(filename);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  char data4[20];
  char data5[20];
  char data6[20];
  int day;
  double dwtot,dwtb,LC1_dwtot,LC2_dwtot,LC1_dwtb,LC2_dwtb;
//  wchar_t * titulo = new wchar_t[2];
  AnsiString titulo;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  double DMCont=strtod(data1,NULL);
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  tch1->Series[2]->Clear();
  tch1->Series[3]->Clear();
  tch1->Series[4]->Clear();
  tch1->Series[5]->Clear();
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s %s %s %s\n",&data1,&data2,&data3,&data4,&data5,&data6);
    LC1_dwtot=strtod(data1,NULL);
    dwtot=strtod(data2,NULL);
    LC2_dwtot=strtod(data3,NULL);
    LC1_dwtb=strtod(data4,NULL);
    dwtb=strtod(data5,NULL);
    LC2_dwtb=strtod(data6,NULL);
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,dwtot,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,dwtb,titulo,tch1->Series[1]->Color);
    tch1->Series[2]->AddXY(i,LC1_dwtot,titulo,tch1->Series[2]->Color);
    tch1->Series[3]->AddXY(i,LC2_dwtot,titulo,tch1->Series[3]->Color);
    tch1->Series[4]->AddXY(i,LC1_dwtb,titulo,tch1->Series[4]->Color);
    tch1->Series[5]->AddXY(i,LC2_dwtb,titulo,tch1->Series[5]->Color);
  }
  in.close();
  fclose(pFile);
  Edit1->Text=i-1;
  Edit2->Text=FormatFloat("0.00",float(dwtot));
  Edit3->Text=FormatFloat("0.00",float(dwtb));
  Edit4->Text=FormatFloat("0.00",float(dwtb/DMCont));
}
//---------------------------------------------------------------------------


