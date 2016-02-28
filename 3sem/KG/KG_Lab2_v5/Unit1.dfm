object Form1: TForm1
  Left = 389
  Top = 418
  Width = 885
  Height = 545
  Caption = #1060#1088#1072#1082#1090#1072#1083#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object btn1: TButton
    Left = 552
    Top = 464
    Width = 89
    Height = 25
    Caption = #1042#1087#1077#1088#1077#1076' >>'
    TabOrder = 0
    OnClick = btn1Click
  end
  object grp1: TGroupBox
    Left = 16
    Top = 8
    Width = 833
    Height = 441
    Caption = #1060#1088#1072#1082#1090#1072#1083': '#1051#1080#1089#1090#1086#1082' '#1087#1072#1087#1086#1088#1086#1090#1110
    TabOrder = 1
    object paintbox1: TPaintBox
      Left = 16
      Top = 16
      Width = 809
      Height = 417
      Color = clWhite
      ParentColor = False
    end
  end
  object LE1: TLabeledEdit
    Left = 16
    Top = 464
    Width = 121
    Height = 21
    EditLabel.Width = 71
    EditLabel.Height = 13
    EditLabel.Caption = #1050'-'#1089#1090#1100' '#1110#1090#1077#1088#1072#1094#1110#1081
    TabOrder = 2
    OnExit = LE1Exit
  end
  object StartX: TLabeledEdit
    Left = 144
    Top = 464
    Width = 57
    Height = 21
    EditLabel.Width = 6
    EditLabel.Height = 13
    EditLabel.Caption = 'X'
    TabOrder = 3
    OnExit = StartXExit
  end
  object StartY: TLabeledEdit
    Left = 208
    Top = 464
    Width = 57
    Height = 21
    EditLabel.Width = 6
    EditLabel.Height = 13
    EditLabel.Caption = 'Y'
    TabOrder = 4
    OnExit = StartYExit
  end
  object stat1: TStatusBar
    Left = 0
    Top = 489
    Width = 852
    Height = 19
    Panels = <>
  end
  object btn2: TButton
    Left = 456
    Top = 464
    Width = 89
    Height = 25
    Caption = '<< '#1053#1072#1079#1072#1076
    TabOrder = 6
    OnClick = btn2Click
  end
  object btn3: TButton
    Left = 648
    Top = 464
    Width = 89
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1080
    TabOrder = 7
    OnClick = btn3Click
  end
  object msec: TLabeledEdit
    Left = 272
    Top = 464
    Width = 57
    Height = 21
    EditLabel.Width = 48
    EditLabel.Height = 13
    EditLabel.Caption = #1047#1072#1090#1088#1080#1084#1082#1072
    TabOrder = 8
    OnExit = msecExit
  end
end
