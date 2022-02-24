object InputForm: TInputForm
  Left = 190
  Top = 110
  BorderStyle = bsDialog
  Caption = #1042#1074#1086#1076
  ClientHeight = 144
  ClientWidth = 329
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object OKButton: TButton
    Left = 168
    Top = 112
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 248
    Top = 112
    Width = 75
    Height = 25
    Caption = '&'#1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 313
    Height = 97
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
    TabOrder = 2
    object RMaskEdit: TMaskEdit
      Left = 16
      Top = 24
      Width = 205
      Height = 32
      EditMask = '0000 0000 0000 0000;1;_'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      MaxLength = 19
      ParentFont = False
      TabOrder = 0
      Text = '0000 0000 0000 0000'
      OnChange = RMaskEditChange
      OnKeyPress = RMaskEditKeyPress
    end
    object CheckBox0: TCheckBox
      Left = 280
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 1
      OnClick = CheckBoxClick
    end
    object CheckBox1: TCheckBox
      Left = 264
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 2
      OnClick = CheckBoxClick
    end
    object CheckBox2: TCheckBox
      Left = 248
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 3
      OnClick = CheckBoxClick
    end
    object CheckBox3: TCheckBox
      Left = 232
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 4
      OnClick = CheckBoxClick
    end
    object CheckBox4: TCheckBox
      Left = 208
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 5
      OnClick = CheckBoxClick
    end
    object CheckBox5: TCheckBox
      Left = 192
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 6
      OnClick = CheckBoxClick
    end
    object CheckBox6: TCheckBox
      Left = 176
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 7
      OnClick = CheckBoxClick
    end
    object CheckBox7: TCheckBox
      Left = 160
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 8
      OnClick = CheckBoxClick
    end
    object CheckBox8: TCheckBox
      Left = 136
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 9
      OnClick = CheckBoxClick
    end
    object CheckBox9: TCheckBox
      Left = 120
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 10
      OnClick = CheckBoxClick
    end
    object CheckBox10: TCheckBox
      Left = 104
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 11
      OnClick = CheckBoxClick
    end
    object CheckBox11: TCheckBox
      Left = 88
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 12
      OnClick = CheckBoxClick
    end
    object CheckBox12: TCheckBox
      Left = 64
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 13
      OnClick = CheckBoxClick
    end
    object CheckBox13: TCheckBox
      Left = 48
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 14
      OnClick = CheckBoxClick
    end
    object CheckBox14: TCheckBox
      Left = 32
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 15
      OnClick = CheckBoxClick
    end
    object CheckBox15: TCheckBox
      Left = 16
      Top = 64
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 16
      OnClick = CheckBoxClick
    end
    object RDecMaskEdit: TMaskEdit
      Left = 232
      Top = 24
      Width = 61
      Height = 32
      EditMask = '00000;1;_'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 17
      Text = '00000'
      OnChange = RDecMaskEditChange
    end
  end
end
