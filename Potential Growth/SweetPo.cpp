//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("USimulationTime.cpp", frmSimulationTime);
USEFORM("UCampo.cpp", frmCampo);
USEFORM("UReportTXT.cpp", frmReportTXT);
USEFORM("UReportTXTMenu.cpp", frmReportTXTMenu);
USEFORM("UAbout.cpp", frmAbout);
USEFORM("UClimate.cpp", frmClimate);
USEFORM("UMain.cpp", frmMain);
USEFORM("UCropParameter.cpp", frmCropParameter);
USEFORM("UDMProd.cpp", frmDMProd);
USEFORM("UPresentation.cpp", frmPresentation);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "SweetPo";
                 Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
