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

#ifndef InputH
#define InputH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include "Main.h"
//---------------------------------------------------------------------------
class TInputForm : public TForm
{
__published:	// IDE-managed Components
    TButton *OKButton;
    TButton *CancelButton;
    TGroupBox *GroupBox1;
    TMaskEdit *RMaskEdit;
    TCheckBox *CheckBox0;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox8;
    TCheckBox *CheckBox9;
    TCheckBox *CheckBox10;
    TCheckBox *CheckBox11;
    TCheckBox *CheckBox12;
    TCheckBox *CheckBox13;
    TCheckBox *CheckBox14;
    TCheckBox *CheckBox15;
    TMaskEdit *RDecMaskEdit;    
    void __fastcall RMaskEditKeyPress(TObject *Sender, char &Key);
    void __fastcall RMaskEditChange(TObject *Sender);
    void __fastcall RDecMaskEditChange(TObject *Sender);
    void __fastcall CheckBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int Value;      //введенное значение
    __fastcall TInputForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInputForm *InputForm;
//---------------------------------------------------------------------------
#endif
