object Form2: TForm2
  Left = 184
  Top = 248
  Width = 425
  Height = 388
  BorderStyle = bsSizeToolWin
  Caption = 'StanBaterii: ustawienia'
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
  object Label1: TLabel
    Left = 336
    Top = 88
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object SpeedButton1: TSpeedButton
    Left = 328
    Top = 128
    Width = 65
    Height = 22
    Caption = 'Przegladaj'
    Flat = True
    OnClick = SpeedButton1Click
  end
  object Label2: TLabel
    Left = 336
    Top = 200
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object SpeedButton3: TSpeedButton
    Left = 144
    Top = 296
    Width = 97
    Height = 33
    Caption = 'OK'
    OnClick = SpeedButton3Click
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 16
    Width = 145
    Height = 17
    Caption = 'Zawsze na wierzchu'
    Checked = True
    State = cbChecked
    TabOrder = 0
  end
  object CheckBox2: TCheckBox
    Left = 16
    Top = 48
    Width = 329
    Height = 17
    Caption = 'Odtwarzaj d'#378'wiek kiedy poziom naladowania baterii spadnie do'
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object TrackBar1: TTrackBar
    Left = 8
    Top = 80
    Width = 321
    Height = 25
    Max = 100
    Orientation = trHorizontal
    Frequency = 1
    Position = 50
    SelEnd = 0
    SelStart = 0
    TabOrder = 2
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object LabeledEdit1: TLabeledEdit
    Left = 16
    Top = 128
    Width = 297
    Height = 21
    EditLabel.Width = 92
    EditLabel.Height = 13
    EditLabel.Caption = 'Plik do odtworzenia'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 3
  end
  object CheckBox3: TCheckBox
    Left = 16
    Top = 160
    Width = 329
    Height = 17
    Caption = 'Wyswietl okno informacyjne gdy stan naladowania spadnie do'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object TrackBar2: TTrackBar
    Left = 16
    Top = 192
    Width = 313
    Height = 45
    Max = 100
    Orientation = trHorizontal
    Frequency = 1
    Position = 50
    SelEnd = 0
    SelStart = 0
    TabOrder = 5
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar2Change
  end
  object LabeledEdit2: TLabeledEdit
    Left = 16
    Top = 256
    Width = 313
    Height = 21
    EditLabel.Width = 85
    EditLabel.Height = 13
    EditLabel.Caption = 'Tresc komunikatu'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 6
    Text = 
      'Niski stan naladowania baterii. Podlacz szybko  inne '#378'rodlo zasi' +
      'lania!'
  end
  object CheckBox4: TCheckBox
    Left = 160
    Top = 16
    Width = 193
    Height = 17
    Caption = 'Uruchamiaj przy starcie Windows'
    TabOrder = 7
  end
  object OpenDialog1: TOpenDialog
    Filter = 'WAV|*.wav'
    Left = 344
    Top = 160
  end
end
