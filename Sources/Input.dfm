object InputForm: TInputForm
  Left = 190
  Top = 110
  BorderStyle = bsDialog
  Caption = #1042#1074#1086#1076
  ClientHeight = 144
  ClientWidth = 356
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object OKButton: TButton
    Left = 193
    Top = 111
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 273
    Top = 111
    Width = 75
    Height = 25
    Caption = '&'#1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 340
    Height = 97
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
    TabOrder = 2
    object RMaskEdit: TMaskEdit
      Left = 17
      Top = 24
      Width = 218
      Height = 38
      EditMask = '0000 0000 0000 0000;1;_'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      MaxLength = 19
      ParentFont = False
      TabOrder = 0
      Text = '0000 0000 0000 0000'
      OnChange = RMaskEditChange
      OnKeyPress = RMaskEditKeyPress
    end
    object CheckBox0: TCheckBox
      Left = 314
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 1
      OnClick = CheckBoxClick
    end
    object CheckBox1: TCheckBox
      Left = 296
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 2
      OnClick = CheckBoxClick
    end
    object CheckBox2: TCheckBox
      Left = 278
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 3
      OnClick = CheckBoxClick
    end
    object CheckBox3: TCheckBox
      Left = 260
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 4
      OnClick = CheckBoxClick
    end
    object CheckBox4: TCheckBox
      Left = 233
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 5
      OnClick = CheckBoxClick
    end
    object CheckBox5: TCheckBox
      Left = 215
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 6
      OnClick = CheckBoxClick
    end
    object CheckBox6: TCheckBox
      Left = 197
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 7
      OnClick = CheckBoxClick
    end
    object CheckBox7: TCheckBox
      Left = 179
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 8
      OnClick = CheckBoxClick
    end
    object CheckBox8: TCheckBox
      Left = 152
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 9
      OnClick = CheckBoxClick
    end
    object CheckBox9: TCheckBox
      Left = 134
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 10
      OnClick = CheckBoxClick
    end
    object CheckBox10: TCheckBox
      Left = 116
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 11
      OnClick = CheckBoxClick
    end
    object CheckBox11: TCheckBox
      Left = 98
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 12
      OnClick = CheckBoxClick
    end
    object CheckBox12: TCheckBox
      Left = 71
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 13
      OnClick = CheckBoxClick
    end
    object CheckBox13: TCheckBox
      Left = 53
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 14
      OnClick = CheckBoxClick
    end
    object CheckBox14: TCheckBox
      Left = 35
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 15
      OnClick = CheckBoxClick
    end
    object CheckBox15: TCheckBox
      Left = 17
      Top = 68
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 16
      OnClick = CheckBoxClick
    end
    object RDecMaskEdit: TMaskEdit
      Left = 264
      Top = 24
      Width = 66
      Height = 38
      EditMask = '00000;1;_'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 17
      Text = '00000'
      OnChange = RDecMaskEditChange
    end
  end
end
