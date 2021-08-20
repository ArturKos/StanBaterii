//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ustawienia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TrackBar1Change(TObject *Sender)
{
Label1->Caption = IntToStr(TrackBar1->Position)+" %";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TrackBar2Change(TObject *Sender)
{
 Label2->Caption = IntToStr(TrackBar2->Position)+" %";       
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton3Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
if(OpenDialog1->Execute())
  if(FileExists(OpenDialog1->FileName))
   LabeledEdit1->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
