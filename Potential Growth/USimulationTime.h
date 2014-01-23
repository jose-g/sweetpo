//---------------------------------------------------------------------------
#ifndef USimulationTimeH
#define USimulationTimeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmSimulationTime : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *edTime;
        TComboBox *cbMonth;
        TBitBtn *cmdCancel;
        TBitBtn *cmdSimulate;
        TEdit *Edit3;
        TEdit *edDay;
        TEdit *Edit4;
        TEdit *edLocation;
        TEdit *Edit8;
        TEdit *edNumSim;
        void __fastcall cmdSimulateClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        modeling::Time *cond;
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
public:		// User declarations
        __fastcall TfrmSimulationTime(TComponent* Owner);
        void EnterInformation(modeling::Time*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSimulationTime *frmSimulationTime;
//---------------------------------------------------------------------------
#endif
