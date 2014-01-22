#ifndef ClimateH
#define ClimateH
#include "Climate.h"
#include <fstream>
#include "vector.h"
#include "sstream.h"
using namespace modeling;
//------------------------------------------------------------------------------
//  Climate class
//------------------------------------------------------------------------------
Climate::Climate(int rec)
{
 RecNum=rec;
 MinTemp=NULL;
 MaxTemp=NULL;
 Precipit=NULL;
 Radiation=NULL;
 MinTemp=new double[RecNum];
 MaxTemp=new double[RecNum];
 Precipit=new double[RecNum];
 Radiation=new double[RecNum];
 CleanVariables();
}
//------------------------------------------------------------------------------
Climate::~Climate()
{
 if (MinTemp != NULL)
 {
  delete [ ]MinTemp;
  MinTemp=NULL;
 }
 if (MaxTemp != NULL)
 {
  delete [ ]MaxTemp;
  MaxTemp=NULL;
 }
 if (Precipit != NULL)
 {
  delete [ ]Precipit;
  Precipit=NULL;
 }
 if (Radiation != NULL)
 {
  delete [ ]Radiation;
  Radiation=NULL;
 }
}
//------------------------------------------------------------------------------
void Climate::CleanVariables()
{
  // limpia variables igualandolas a cero
  int i=0;
  for(i=0;i<RecNum;i++)
  {
    MinTemp[i]=0.0;
    MaxTemp[i]=0.0;
    Precipit[i]=0.0;
    Radiation[i]=0.0;
  }
}
//------------------------------------------------------------------------------
//  ClimateFile class
//------------------------------------------------------------------------------
ClimateFile::ClimateFile(int rec):Climate(rec)
{
  FileName = NULL;
  TitTMin  = NULL;
  TitTMax  = NULL;
  TitPrec  = NULL;
  TitRad   = NULL;
  FileName = new char[255];
  TitTMin  = new char[255];
  TitTMax  = new char[255];
  TitPrec  = new char[255];
  TitRad   = new char[255];
  CleanVariables();
}
//------------------------------------------------------------------------------
ClimateFile::~ClimateFile()
{
 if (FileName != NULL)
 {
  delete [ ]FileName;
  FileName=NULL;
 }
 if (TitTMin != NULL)
 {
  delete [ ]TitTMin;
  TitTMin=NULL;
 }
 if (TitTMax != NULL)
 {
  delete [ ]TitTMax;
  TitTMax=NULL;
 }
 if (TitPrec != NULL)
 {
  delete [ ]TitPrec;
  TitPrec=NULL;
 }
 if (TitRad != NULL)
 {
  delete [ ]TitRad;
  TitRad=NULL;
 }
}
//------------------------------------------------------------------------------
void ClimateFile::CleanVariables()
{
  strcpy (FileName, "");
  strcpy (TitTMin, "");
  strcpy (TitTMax, "");
  strcpy (TitPrec, "");
  strcpy (TitRad, "");
  Climate::CleanVariables();
}
//------------------------------------------------------------------------------
int ClimateFile::DeterminePosition(char* archivo,char* campo)
{
  fstream FicheroGrafo;
  FicheroGrafo.open(archivo, ios::in);
  char p[100];
  int tam=strlen(campo);
  char valor[100]="";
  int i,j,z;
  FicheroGrafo.getline(p,100);
  int contPal=0;
  int OrdenCampo=0;
  bool encontro=false;
  bool finalizo=false;
  for (i=0;i<100;i++)
  {
     if(p[i] == '\0'){finalizo=true;}
     if (p[i] != ' ' && p[i] != '\0')
     {
       contPal++;
       valor[contPal-1]=p[i];
     }
     else
     {
       if(contPal>0)
       {
          OrdenCampo++;
          encontro=false;
          if(tam==contPal)
          {
            for(j=0;j<tam;j++)
            {
              if(valor[j]!=campo[j])
              {
                encontro=false;
                break;
              }
              encontro=true;
            }
          }
          for(z=0;z<contPal;z++){valor[z]=' ';}
          contPal=0;
       }
     }
     if(encontro){break;}
     if(finalizo && !encontro){OrdenCampo=0;break;}
  }
  FicheroGrafo.close();
  return OrdenCampo;
}
//------------------------------------------------------------------------------
int ClimateFile::GetColumnData(char* FileName,char* FieldName,double* vect)
{
  int pos=DeterminePosition(FileName,FieldName);
  FILE *pFile=NULL;
  pFile = fopen (FileName,"r");
  if (pFile==NULL)
  {
     fclose(pFile);
     return -1; // problema al abrir el archivo
  }
  fclose(pFile);
  ifstream in(FileName);
  string linea;
  vector<string> v;
  string buffer;
  char* pEnd=NULL;
  int i,j=0,ContCol=0;
  getline(in,linea,'\n');
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      ContCol=0;
      while(!aStream.eof())
      {
         ContCol++;
         j++;
         buffer="";
         aStream >> buffer;
         v.push_back(buffer);
         if(ContCol==pos)
         {
           vect[i-1]=strtod(v[j-1].c_str(),&pEnd);
         }
      }
  }
  in.close();
  return 0;
}
//------------------------------------------------------------------------------
void ClimateFile::LoadClimateInformation()
{
  GetColumnData(FileName , TitTMin , MinTemp  );
  GetColumnData(FileName , TitTMax , MaxTemp  );
  GetColumnData(FileName , TitPrec , Precipit );
  GetColumnData(FileName , TitRad  , Radiation);
}
//------------------------------------------------------------------------------
#endif
