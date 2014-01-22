#ifndef ReportH
#define ReportH
#include "Report.h"
using namespace modeling;
Report::Report()
{
 Archivo1 = NULL;
 Archivo1 = new char[255];
 Archivo2 = NULL;
 Archivo2 = new char[255];
 DMProd   = NULL;
 DMProd   = new char[255];
 DMProdResume = NULL;
 DMProdResume = new char[255];
 variety = NULL;
 variety = new char[20];
 CleanVariables();
}
Report::~Report()
{
 if (Archivo1 != NULL)
 {
  delete [ ]Archivo1;
  Archivo1=NULL;
 }
 if (Archivo2 != NULL)
 {
  delete [ ]Archivo2;
  Archivo2=NULL;
 }
 if (DMProd != NULL)
 {
  delete [ ]DMProd;
  DMProd=NULL;
 }
 if (DMProdResume != NULL)
 {
  delete [ ]DMProdResume;
  DMProdResume=NULL;
 }
 if (variety != NULL)
 {
  delete [ ]variety;
  variety=NULL;
 }
}
void Report::CleanVariables()
{
  strcpy(Archivo1,"");
  strcpy(Archivo2,"");
  strcpy(DMProd,"");
  strcpy(DMProdResume,"");
}
void Report::DeleteReports()
{
  DeleteFile(Archivo1);
  DeleteFile(Archivo2);
  DeleteFile(DMProd);
  DeleteFile(DMProdResume);
}
void Report::GenerateTextReport()
{
  GenerateDMProd();
  GenerateDMProdResume();
}
void Report::GenerateDMProd()
{
  FILE * pFileOutput=NULL;
  pFileOutput = fopen (DMProd,"w");
  FILE * pFile=NULL;
  pFile = fopen (Archivo1,"r");
  ifstream in(Archivo1);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  int day;
  double dwtot,dwtbf;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  fprintf(pFileOutput,"%s\n","        DRY MATTER PRODUCTION");
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario             :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location             :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety              :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Day start            :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Total days simulated :",time->duration);
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s\n"," Simulation       Total        Tuber            ");
  fprintf(pFileOutput,"%s\n","    day        Dry matter    Dry matter         ");
  fprintf(pFileOutput,"%s\n","                  t/ha         t/ha            ");
  fprintf(pFileOutput,"%s\n","  ");
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s\n",&data1,&data2);
    dwtot=strtod(data1,NULL);
    dwtbf=strtod(data2,NULL);
    fprintf(pFileOutput,"    %s          %s       %s\n",FormatFloat("000",float(i)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtbf));
  }
  in.close();
  fclose(pFile);
  fclose(pFileOutput);
}
void Report::GenerateDMProdResume()
{
  FILE * pFileOutput=NULL;
  pFileOutput = fopen (DMProdResume,"a");
  FILE * pFile=NULL;
  pFile = fopen (Archivo1,"r");
  ifstream in(Archivo1);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  int day;
  double dwtot,dwtbf;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  double DMCont=strtod(data1,NULL);
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario                   :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location                   :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety                    :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Day start                  :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Total days simulated       :",time->duration);
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s\n",&data1,&data2);
    dwtot=strtod(data1,NULL);
    dwtbf=strtod(data2,NULL);
//    fprintf(pFileOutput,"    %s          %s       %s\n",FormatFloat("000",float(i)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtbf));
  }
  in.close();
  fprintf(pFileOutput,"%s %s\n","Total dry   matter         :",FormatFloat("00.00",dwtot));
  fprintf(pFileOutput,"%s %s\n","Total Tuber dry   matter   :",FormatFloat("00.00",dwtbf));
  fprintf(pFileOutput,"%s %s\n","Tuber fresh matter         :",FormatFloat("00.00",dwtbf/DMCont));
  fprintf(pFileOutput,"%s\n","  ");
  fclose(pFile);
  fclose(pFileOutput);
}
#endif
