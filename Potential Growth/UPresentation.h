//---------------------------------------------------------------------------

#ifndef UPresentationH
#define UPresentationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfrmPresentation : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TGroupBox *GroupBox1;
        TImage *Image1;
        TButton *Button1;
        TLabel *Label2;
        TPanel *Panel1;
        TImage *Image3;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmPresentation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPresentation *frmPresentation;
//---------------------------------------------------------------------------
#endif
