//---------------------------------------------------------------------------

#ifndef ustawieniaH
#define ustawieniaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TTrackBar *TrackBar1;
        TLabel *Label1;
        TLabeledEdit *LabeledEdit1;
        TSpeedButton *SpeedButton1;
        TCheckBox *CheckBox3;
        TTrackBar *TrackBar2;
        TLabel *Label2;
        TSpeedButton *SpeedButton3;
        TLabeledEdit *LabeledEdit2;
        TOpenDialog *OpenDialog1;
        TCheckBox *CheckBox4;
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
