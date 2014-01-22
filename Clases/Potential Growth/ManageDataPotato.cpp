#ifndef ManageDataPotatoH
#define ManageDataPotatoH
#include "ManageDataPotato.h"
using namespace modeling;
ManageDataPotato::ManageDataPotato()
{
  climate = NULL;
  climate = new ClimateFile(365);
  time    = NULL;
  time    = new Time();
  crop    = NULL;
  crop    = new Crop();
  report  = NULL;
  report  = new Report();
  simulation = NULL;
  simulation = new Simulation();
  workdir=NULL;
  workdir = new char[255];
}
ManageDataPotato::~ManageDataPotato()
{
 if (climate != NULL)
 {
  delete climate;
  climate=NULL;
 }
 if (time != NULL)
 {
  delete time;
  time=NULL;
 }
 if (crop != NULL)
 {
  delete crop;
  crop=NULL;
 }
 if (report != NULL)
 {
  delete report;
  report=NULL;
 }
 if (simulation != NULL)
 {
  delete simulation;
  simulation=NULL;
 }
 if (workdir != NULL)
 {
  delete workdir;
  workdir=NULL;
 }
}
void ManageDataPotato::CleanCondition()
{
  climate->CleanVariables();
  time->CleanVariables();
  crop->CleanVariables();
  simulation->CleanVariables();
  report->DeleteReports();
}
void ManageDataPotato::DefaultCondition()
{
  time->DayStart    = 7;
  time->MonthStart  = 5;
  time->duration    = 130;
  strcpy(time->location,"Africa");

  char clima[255];
  strcpy(clima,workdir);
  strncat(clima,"climate.prn",11);
  strcpy(climate->FileName,clima);

  strcpy(climate->TitTMin,"Tmin");
  strcpy(climate->TitTMax,"Tmax");
  strcpy(climate->TitPrec,"Prec");
  strcpy(climate->TitRad,"Rad");

  climate->LoadClimateInformation();
  crop->DefaultValuesForKindOfCrop(1);
//  crop->plant->N=4.76;
//  crop->plant->EDay=36;
  crop->plant->EDay=5;
  crop->plant->v=0.075;
  crop->plant->t0=12.0;
}
bool ManageDataPotato::DoSimulation()
{
    simulation->climate=climate;
    simulation->crop=crop;
    simulation->time=time;
    simulation->report=report;
    bool finished=simulation->simulate();
    return finished;
}
bool ManageDataPotato::SaveCondition(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false; // problema al abrir el archivo
  }
  rewind(stream);
// clima
  fprintf(stream,"%s\n",climate->FileName);
  fprintf(stream,"%s\n",climate->TitTMin);
  fprintf(stream,"%s\n",climate->TitTMax);
  fprintf(stream,"%s\n",climate->TitPrec);
  fprintf(stream,"%s\n",climate->TitRad);
//crop
  fprintf(stream,"%i\n",crop->SelectedCrop);
  fprintf(stream,"%f %f\n",float(crop->plant->N),float(crop->plant->fcl));
  fprintf(stream,"%f %f\n",float(crop->plant->F0),float(crop->plant->R0));
  fprintf(stream,"%f %f\n",float(crop->plant->d),float(crop->plant->t50));
  fprintf(stream,"%f %f\n",float(crop->plant->LUE),float(crop->plant->v));
  fprintf(stream,"%i %f\n",crop->plant->EDay,float(crop->plant->t0));
  fprintf(stream,"%f %f\n",float(crop->tuber->M),float(crop->tuber->A));
  fprintf(stream,"%f %f\n",float(crop->tuber->b),float(crop->tuber->DMCont));
  fprintf(stream,"%i %i %i\n",time->DayStart,time->MonthStart,time->duration);
  fclose(stream);
  return true; // se abrio correctamente el archivo y se guardo los datos
}
bool ManageDataPotato::LoadCondition(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"r");
  if (stream==NULL)
  {
     fclose(stream);
     return false; // problema al abrir el archivo
  }
  rewind(stream);
  char data1[20];
  char data2[20];
  char data3[255];
// clima
  fscanf(stream,"%s",&data3);
  strcpy(climate->FileName,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitTMin,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitTMax,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitPrec,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitRad,data3);
  climate->LoadClimateInformation();
// crop
  fscanf(stream,"%i\n",&crop->SelectedCrop);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->N=strtod(data1,NULL);
  crop->plant->fcl=strtod(data2,NULL);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->F0=strtod(data1,NULL);
  crop->plant->R0=strtod(data2,NULL);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->d=strtod(data1,NULL);
  crop->plant->t50=strtod(data2,NULL);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->LUE=strtod(data1,NULL);
  crop->plant->v=strtod(data2,NULL);
  fscanf(stream,"%i %s\n",&crop->plant->EDay,&data2);
  crop->plant->t0=strtod(data2,NULL);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->tuber->M=strtod(data1,NULL);
  crop->tuber->A=strtod(data2,NULL);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->tuber->b=strtod(data1,NULL);
  crop->tuber->DMCont=strtod(data2,NULL);
  fscanf(stream,"%i %i %i\n",&time->DayStart,&time->MonthStart,&time->duration);
  fclose(stream);
  return true; // se abrio correctamente el archivo y se levanto los datos
}
void ManageDataPotato::GetWorkDir(char* workDir)
{
  strcpy(workdir,workDir);
}

#endif
