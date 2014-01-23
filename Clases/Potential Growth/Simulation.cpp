#ifndef SimulationH
#define SimulationH
#include "Simulation.h"
using namespace modeling;
Simulation::Simulation()
{
  NumberScenario=0;
}
Simulation::~Simulation()
{
}
bool Simulation::simulate()
{
  bool finished;

// inicialización de variables independientes
  double N      = crop->plant->N;
  double fcl    = crop->plant->fcl;
  double F0     = crop->plant->F0;
  double R0     = crop->plant->R0;
  double d      = crop->plant->d;
  double t50    = crop->plant->t50;
  double M      = crop->tuber->M;
  double A      = crop->tuber->A;
  double b      = crop->tuber->b;
  double DMCont = crop->tuber->DMCont;
  double LUE    = crop->plant->LUE;
  int    EDay   = crop->plant->EDay;
  double v      = crop->plant->v;
  double t0     = crop->plant->t0;
  double MinTemp[366];
  double MaxTemp[366];
  double Precipit[366];
  double Radiation[366];
  for(int i=1;i<=365;i++)
  {
    MinTemp[i]   = climate->MinTemp[i-1];
    MaxTemp[i]   = climate->MaxTemp[i-1];
    Precipit[i]  = climate->Precipit[i-1];
    Radiation[i] = climate->Radiation[i-1];
  }
  int totaldays=time->duration;
  int mm=time->MonthStart;
  int dd=time->DayStart;
  int numrep=time->repetitions;

// inicio de repeticiones
  for(int irep=0;irep<numrep;irep++)
  {
// inicialización de variables auxiliares
  finished=false;
// inicialización de variables dependientes
  double Flinti=0.0;
  double Flint2=0.0;
  double HI=0.0;
  double dWtb=0.0;
  double dWtbf=0.0;
  int SDate=0;
  int day=0;
  int SDay=0;
  double DAE=0.0;
  double Flint1=0.0;
  double Flint=0.0;
  double Tmax=0.0;
  double Tmin = 0.0;
  double PAR = 0.0;
  double dW = 0.0;
  double t=0.0;
  double rdm=0.0;
  double Tx=0.0;
  double Tm=0.0;
  double To=0.0;
  double W=0.0;
  double Te=0.0;
// inicialización de variables contenedoras
  double t_ac=0.001;
  double dWtot=0.0;
// modelo matemático
  switch (mm)
  {
    case 1:
      SDate=dd+0;
      break;
    case 2:
      SDate=dd+31;
      break;
    case 3:
      SDate=dd+59;
      break;
    case 4:
      SDate=dd+90;
      break;
    case 5:
      SDate=dd+120;
      break;
    case 6:
      SDate=dd+151;
      break;
    case 7:
      SDate=dd+181;
      break;
    case 8:
      SDate=dd+212;
      break;
    case 9:
      SDate=dd+243;
      break;
    case 10:
      SDate=dd+273;
      break;
    case 11:
      SDate=dd+304;
      break;
    case 12:
      SDate=dd+334;
      break;
    default:
      return finished;
  }
  day=SDate-1;

  for(int i=1;i<=totaldays;i++)
  {
    SDay=i;
    if(day==365){day=1;}
    else{day++;}
    Flinti = (fcl*N*F0*exp(R0*t_ac))/(N*F0*exp(R0*t_ac)+1-N*F0);
//    Flint2 = 0.5-(t_ac-t50)/d;
    HI = M/(1.0+pow(t_ac/A,b));
    dWtb = dWtot*HI;
    dWtbf = dWtb/DMCont;
    if(SDay>=EDay){DAE=SDay-EDay;}else{DAE=0;}
    rdm=Random();
    Flint1 = rdm*v*Flinti+Flinti;
//    if(Flint2<=0.0)
//    {
//      Flint=0.0;
//    }
//    else
//    {
//      if(Flint1<Flint2)
//    {
//      Flint=Flint1;
//    }
//    else
//    {
//      if(Flint2>0.0)
//      {
//        Flint=Flint2;
//      }
//      else
//      {
//        Flint=Flint1;
//      }
//    }
//  }
    Tmax = MaxTemp[day];
    Tmin = MinTemp[day];
    PAR  = Radiation[day]*0.5;
    Tx=(Tmax+Tmin)/2.0;    // Mean temperature (ºC)
    Tm=40.0;  // Maximum Temperature (oC)
    To=23.0;  // Optimum temperature (oC)
    //dW = (LUE*Flint*PAR)/100.0;
    dW=(LUE*Flint1*PAR)/100.0;
    if(Tx>=t0 && Tx<To)
    {
      W=1-pow(((Tx-To)/(To-t0)),2); // Weighted factor for effective temperature
    }
    else
    {
      if(Tx>=To && Tx<=Tm)
      {
        W=-1*((Tx-Tm)/(Tm-To));
      }
      else
      {
        W=0.0;
      }
    }
    if(DAE<=0.0)
    {
      Te=0.0;  // Effective temperature
    }
    else
    {
      if(DAE>0.0 && Tx<t0)
      {
        Te=0.0;
      }
      else
      {
        if(Tx>=t0 && Tx<=Tm)
        {
          Te=(Tx-t0)*W;
        }
        else
        {
          Te=0.0;
        }
      }
    }
//    if(DAE>0)
//    {
//      t=(Tmax+Tmin)/2.0-t0;
//    }
//    else
//    {
//      t=0.0;
//    }
//    t_ac=t_ac+t;
    t_ac=t_ac+Te;
    dWtot=dWtot+dW;

    dWtot_mat[irep][i]=dWtot;
    dWtb_mat[irep][i]=dWtb;
    dWtbf_mat[irep][i]=dWtbf;

  }
  finished=true;
  } // fin de irep

// Se abre reportes
  FILE *stream1=NULL;
  FILE *stream2=NULL;
  stream1=fopen(report->Archivo1,"w");
  rewind(stream1);
  stream2=fopen(report->Archivo2,"w");
  rewind(stream2);

  fprintf(stream1,"%f\n",float(DMCont));
// aqui me quede
  double XdWtot=0.0;
  double XdWtb=0.0;
  double XdWtbf=0.0;

  for(int i=1;i<=totaldays;i++)
  {
    for(int irep=0;irep<numrep;irep++)
    {
        XdWtot=XdWtot+dWtot_mat[irep][i];
        XdWtb=XdWtb+dWtb_mat[irep][i];
        XdWtbf=XdWtbf+dWtbf_mat[irep][i];
    }
    XdWtot=XdWtot/numrep;
    XdWtb=XdWtb/numrep;
    XdWtbf=XdWtbf/numrep;


    if(i==totaldays)
    {
      fprintf(stream1,"%f %f",float(XdWtot),float(XdWtb));
      fprintf(stream2,"%f",float(XdWtbf));
    }
    else
    {
      fprintf(stream1,"%f %f\n",float(XdWtot),float(XdWtb));
      fprintf(stream2,"%f\n",float(XdWtbf));
    }
  }

// cerramos reportes
  fclose(stream1);
  fclose(stream2);
// se contabiliza un nuevo escenario
  NumberScenario++;
  return finished;
}
int Simulation::Month(int day)
{
  int month=0;
  if(day<=31)           {month= 1;}
  if(day>31&&day<=59)   {month= 2;}
  if(day>59&&day<=90)   {month= 3;}
  if(day>90&&day<=120)  {month= 4;}
  if(day>120&&day<=151) {month= 5;}
  if(day>151&&day<=181) {month= 6;}
  if(day>181&&day<=212) {month= 7;}
  if(day>212&&day<=243) {month= 8;}
  if(day>243&&day<=273) {month= 9;}
  if(day>273&&day<=304) {month=10;}
  if(day>304&&day<=334) {month=11;}
  if(day>334)           {month=12;}
  return month;
}
double Simulation::Random()
{
  int valor=0.0;
  double ran=0.0;
  double Z0=0.0,Z1=0.0,Z2=0.0;
  begin:
  Randomize;
  valor=random(50001);
  ran=double(valor)/50000.00;
  Z0=2*ran-1;
  if(Z0==1.0){goto begin;}
  if(Z0==-1.0){goto begin;}
  Z2=(1+Z0)/(1-Z0);
  Z1=log10(Z2)/1.82;
  return Z1;
}
void Simulation::CleanVariables()
{
  NumberScenario=0;
}
#endif
