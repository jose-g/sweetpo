//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop

#include "UCCGraph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmCCGraph *frmCCGraph;
//---------------------------------------------------------------------------
__fastcall TfrmCCGraph::TfrmCCGraph(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmCCGraph::EnterInformation(char* _cond)
{
filename=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCCGraph::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCCGraph::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCCGraph::FormShow(TObject *Sender)
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
  char data7[20];
  char data8[20];
  char data9[20];
  int day;
  double dwtot,dwtb,LC1_dwtot,LC2_dwtot,LC1_dwtb,LC2_dwtb,dflinti,LC1_dflinti,LC2_dflinti;
//  wchar_t * titulo = new wchar_t[2];
  AnsiString titulo;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  double DMCont=strtod(data1,NULL);
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  tch1->Series[2]->Clear();
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s %s %s %s %s %s %s\n",&data1,&data2,&data3,&data4,&data5,&data6,&data7,&data8,&data9);
    LC1_dflinti=strtod(data7,NULL);
    dflinti=strtod(data8,NULL);
    LC2_dflinti=strtod(data9,NULL);
    dwtot=strtod(data2,NULL);
    dwtb=strtod(data5,NULL);
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,dflinti,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,LC1_dflinti,titulo,tch1->Series[1]->Color);
    tch1->Series[2]->AddXY(i,LC2_dflinti,titulo,tch1->Series[2]->Color);
  }
  in.close();
  fclose(pFile);
  Edit1->Text=i-1;
  Edit2->Text=FormatFloat("0.00",float(dwtot));
  Edit3->Text=FormatFloat("0.00",float(dwtb));
  Edit4->Text=FormatFloat("0.00",float(dwtb/DMCont));
}
//---------------------------------------------------------------------------


