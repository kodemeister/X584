//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormShow(TObject *Sender)
{
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    MemLabel->Caption = IntToStr(ms.dwTotalPhys / 1024) + " КБ";
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::RepositoryLabelClick(TObject *Sender)
{
    char url[256];
    strcpy(url, RepositoryLabel->Caption.c_str());
    ShellExecute(NULL, NULL, url, NULL, NULL, 0);
}
//---------------------------------------------------------------------------
