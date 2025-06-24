/*
 * Copyright (C) 2005-2024 X584 developers
 *
 * This file is part of X584.
 *
 * X584 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * X584 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with X584. If not, see <https://www.gnu.org/licenses/>.
 */

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "Version.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
    VersionLabel->Caption = L"X584 версия " + UnicodeString(X584_VERSION);
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormShow(TObject *Sender)
{
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    MemLabel->Caption = UIntToStr(static_cast<size_t>(ms.dwTotalPhys) / 1024) + L" КБ";
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::RepositoryLabelClick(TObject *Sender)
{
    wchar_t url[256];
    wcscpy(url, RepositoryLabel->Caption.c_str());
    ShellExecuteW(NULL, NULL, url, NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
