//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <IniFiles.hpp>
//#define _WIN32_WINNT 0x0400
#include "Unit1.h"
#include "ustawienia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma link "trayicon"
#pragma resource "*.dfm"
void __fastcall TForm1::Przesun(TMouseButton Button)
{
if (Button == mbLeft)
   {
     SendMessage(Handle, WM_LBUTTONUP, 0, 0);
     SendMessage(Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
   }
}
TForm1 *Form1;__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::zapisz_konf(void)
{
TIniFile *ini;
AnsiString path = ExtractFilePath(Application->ExeName);
 if(path[path.Length()]!='\\') path+='\\';
 ini = new TIniFile(ChangeFileExt(Application->ExeName,".INI"));
 ini->WriteInteger("mainwindow","left",Left);
 ini->WriteInteger("mainwindow","top",Top);
 ini->WriteInteger("mainwindow","height",Height);
 ini->WriteInteger("mainwindow","width",Width);
 ini->WriteBool("mainwindow","ontop",Form2->CheckBox1->Checked);
 ini->WriteBool("mainwindow","winstart",Form2->CheckBox4->Checked);
 ini->WriteBool("mainwindow","playsound",Form2->CheckBox2->Checked);
 ini->WriteInteger("mainwindow","percenttoplay",Form2->TrackBar1->Position);
 ini->WriteString("mainwindow","playfile",Form2->LabeledEdit1->Text);
 ini->WriteBool("mainwindow","showinfo",Form2->CheckBox3->Checked);
 ini->WriteInteger("mainwindow","percenttoshowinfo",Form2->TrackBar2->Position);
 ini->WriteString("mainwindow","message",Form2->LabeledEdit2->Text);
delete ini;
}
void __fastcall TForm1::wczytaj_konf(void)
{
TIniFile *ini;
AnsiString path = ExtractFilePath(Application->ExeName);
 if(path[path.Length()]!='\\') path+='\\';
 ini = new TIniFile(ChangeFileExt(Application->ExeName,".INI"));

 Left = ini->ReadInteger("mainwindow","left",100);
 Top = ini->ReadInteger("mainwindow","top",100);
 Height = ini->ReadInteger("mainwindow","height",126);
 Width = ini->ReadInteger("mainwindow","width",297);
 Form2->CheckBox1->Checked = ini->ReadBool("mainwindow","ontop",true);
 Form2->CheckBox4->Checked = ini->ReadBool("mainwindow","winstart",true);
 Form2->CheckBox2->Checked = ini->ReadBool("mainwindow","playsound",false);
 Form2->TrackBar1->Position = ini->ReadInteger("mainwindow","percenttoplay",10);
 Form2->LabeledEdit1->Text = ini->ReadString("mainwindow","playfile","");
 Form2->CheckBox3->Checked = ini->ReadBool("mainwindow","showinfo",true);
 Form2->TrackBar2->Position = ini->ReadInteger("mainwindow","percenttoshowinfo",10);
 Form2->LabeledEdit2->Text = ini->ReadString("mainwindow","message","Bateria na wyczerpaniu");
delete ini;
}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

static bool sound = false;
static bool dlg = false;
if(Form2->Active) return;
SYSTEM_POWER_STATUS stan;
GetSystemPowerStatus(&stan);
if((stan.BatteryFlag & 128)!=128)
 {
  AnsiString hint;
  if((stan.BatteryFlag & 8)==8)
   {
     Timer2->Enabled = true;
     ProgressBar1->Visible = true;
     hint = "£adowanie w toku...\n";
     ImageList1->Draw(Form1->Canvas,0,0,1,true);

    } else
     {
      Timer2->Enabled = false;
      ProgressBar1->Visible = false;
      ImageList1->Draw(Form1->Canvas,0,0,0,true);
     }
  bateria->Progress = stan.BatteryLifePercent;
static int apr=stan.BatteryLifePercent,approx = stan.BatteryLifePercent;
static int sec=0,czas = 0;

if(stan.BatteryLifePercent<apr)
 {
   czas = ((sec/1000)*stan.BatteryLifePercent)/(approx-stan.BatteryLifePercent);
   apr = stan.BatteryLifePercent;
 //  sec = 0;
  }else
  sec+=100;
  if((stan.ACLineStatus)==1)
   {
    bateria->ForeColor = clLime;
    sound = false;
    dlg = false;
    hint += "Zrodlo zasilania: siec\n";
   }
  if((stan.ACLineStatus)==0)
   {
    bateria->ForeColor = clRed;
    if((!sound)&&(stan.BatteryLifePercent<=Form2->TrackBar1->Position)&&
        (Form2->CheckBox2->Checked)) {
      ShowMessage("sound");
      sound = true;
      }
      if((!dlg)&&(stan.BatteryLifePercent<=Form2->TrackBar2->Position)&&
        (Form2->CheckBox3->Checked)) {
      ShowMessage("sound");
      dlg = true;
      }
    hint += "Zrodlo zasilania: bateria\n";
   }
  if((stan.ACLineStatus)==255)
   hint += "Zrodlo zasilania: nieznane\n";
//  if(stan.BatteryLifeTime!=-1)
   if(czas==0)
      hint += "Przewidywany czas pracy na baterii: szacowanie";else
      {
        hint += "Przewidywany czas pracy na baterii: ";
        hint += czas/3600; hint+=" godzin i ";
        hint += (czas&3600)/60; hint+=" minut";
      //  hint += (czas&3600)%60;
      }
  Form1->Hint = hint;
  if(Form2->CheckBox1->Checked)
  Form1->FormStyle = fsStayOnTop; else
  Form1->FormStyle = fsNormal;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zamknij1Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ustawienia1Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
zapisz_konf();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
wczytaj_konf();            
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
if((ProgressBar1->Position)>=3)
    ProgressBar1->Position = 0;else ProgressBar1->Position++;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
Przesun(Button);        
}
//---------------------------------------------------------------------------

