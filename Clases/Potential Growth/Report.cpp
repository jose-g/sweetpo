#ifndef ReportH
#define ReportH
#include <SysUtils.hpp>
#include "Report.h"
using namespace modeling;
Report::Report()
{
 Archivo1 = NULL;
 Archivo1 = new char[255];
 Archivo2 = NULL;
 Archivo2 = new char[255];
 Archivo3 = NULL;
 Archivo3 = new char[255];
 Archivo4 = NULL;
 Archivo4 = new char[255];
 DMProd   = NULL;
 DMProd   = new char[255];
 DMProdResume = NULL;
 DMProdResume = new char[255];
 RunsReport = NULL;
 RunsReport = new char[255];

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
 if (Archivo3 != NULL)
 {
  delete [ ]Archivo3;
  Archivo3=NULL;
 }
 if (Archivo4 != NULL)
 {
  delete [ ]Archivo4;
  Archivo4=NULL;
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
 if (RunsReport != NULL)
 {
  delete [ ]RunsReport;
  RunsReport=NULL;
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
  strcpy(Archivo3,"");
  strcpy(Archivo4,"");
  strcpy(DMProd,"");
  strcpy(DMProdResume,"");
  strcpy(RunsReport,"");
}
void Report::DeleteReports()
{
  DeleteFile(Archivo1);
  DeleteFile(Archivo2);
  DeleteFile(Archivo3);
  DeleteFile(Archivo4);
  DeleteFile(DMProd);
  DeleteFile(DMProdResume);
  DeleteFile(RunsReport);
}
void Report::GenerateTextReport()
{
  GenerateDMProd();
  GenerateDMProdResume();
  GenerateRunsReport();
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
  double dwtot,dwtb;
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
    dwtb=strtod(data2,NULL);
//    fprintf(pFileOutput,"    %s          %s       %s\n",FormatFloat("000",float(i)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtbf));
  }
  in.close();
  fprintf(pFileOutput,"%s %s\n","Total dry   matter         :",FormatFloat("00.00",dwtot));
  fprintf(pFileOutput,"%s %s\n","Total Tuber dry   matter   :",FormatFloat("00.00",dwtb));
  fprintf(pFileOutput,"%s %s\n","Tuber fresh matter         :",FormatFloat("00.00",dwtb/DMCont));
  fprintf(pFileOutput,"%s\n","  ");
  fclose(pFile);
  fclose(pFileOutput);
}
void Report::GenerateRunsReport()
{
  FILE * pFileOutput=NULL;
  pFileOutput = fopen (RunsReport,"a");
  FILE * pFile=NULL;
  pFile = fopen (Archivo3,"r");
  ifstream in(Archivo3);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  int day;
  double dwtot,dwtb,dwtbf;
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario                   :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location                   :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety                    :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Day start                  :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Total days simulated       :",time->duration);
  fprintf(pFileOutput,"%s\n","  ");

  fprintf(pFileOutput,"%s\n"," Repetition       Total        Tuber         Tuber");
  fprintf(pFileOutput,"%s\n","   number      Dry matter    Dry matter   Fresh matter");
  fprintf(pFileOutput,"%s\n","                  t/ha         t/ha          t/ha");
  fprintf(pFileOutput,"%s\n","  ");

  for(i=1;i<=time->repetitions ;i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s\n",&data1,&data2,&data3);
    dwtot=strtod(data1,NULL);
    dwtb=strtod(data2,NULL);
    dwtbf=strtod(data3,NULL);
    fprintf(pFileOutput,"    %s          %s       %s        %s\n",FormatFloat("000",float(i)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtb),FormatFloat("00.000",dwtbf));
  }

  in.close();
  fclose(pFile);
  fclose(pFileOutput);
}
#endif
