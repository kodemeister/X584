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

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *HeaderPanel;
    TImage *InfoImage;
    TLabel *AboutLabel;
    TImage *IconImage;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TImage *WinXPImage;
    TLabel *DeveloperLabel1;
    TLabel *DeveloperLabel2;
    TLabel *Label9;
    TLabel *RepositoryLabel;
    TPanel *Panel1;
    TLabel *MemCaptionLabel;
    TButton *OKButton;
    TLabel *MemLabel;
    TLabel *Label7;
    TLabel *DeveloperLabel3;
    TLabel *GroupLabel1;
    TLabel *GroupLabel2;
    TLabel *GroupLabel3;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RepositoryLabelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
