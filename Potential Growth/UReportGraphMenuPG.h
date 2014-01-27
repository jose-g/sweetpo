//---------------------------------------------------------------------------

#ifndef UReportGraphMenuPGH
#define UReportGraphMenuPGH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmReportGraphMenuPG : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TButton *butCC;
        TButton *butTotalDM;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall butCCClick(TObject *Sender);
        void __fastcall butTotalDMClick(TObject *Sender);
private:	// User declarations
        Report *cond;
public:		// User declarations
        __fastcall TfrmReportGraphMenuPG(TComponent* Owner);
        void EnterInformation(Report*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportGraphMenuPG *frmReportGraphMenuPG;
//---------------------------------------------------------------------------
#endif
