//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "CGAUGES.h"
#include "trayicon.h"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupMenu1;
        TCGauge *bateria;
        TTimer *Timer1;
        TMenuItem *Ustawienia1;
        TMenuItem *N1;
        TMenuItem *Zamknij1;
        TTrayIcon *TrayIcon1;
        TImageList *ImageList1;
        TProgressBar *ProgressBar1;
        TTimer *Timer2;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Zamknij1Click(TObject *Sender);
        void __fastcall Ustawienia1Click(TObject *Sender);
         void __fastcall zapisz_konf(void);
          void __fastcall wczytaj_konf(void);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
        void __fastcall Przesun(TMouseButton Button);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
