object frmCCGraph: TfrmCCGraph
  Left = 354
  Top = 246
  BorderStyle = bsDialog
  Caption = 'Graph : Canopy cover'
  ClientHeight = 566
  ClientWidth = 908
  Color = 2561029
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object tch1: TChart
    Left = 10
    Top = 50
    Width = 887
    Height = 503
    BottomWall.Color = 8454143
    Legend.Bevel = bvRaised
    Legend.CheckBoxes = True
    Legend.Color = 3677447
    Legend.CustomPosition = True
    Legend.Font.Style = [fsBold]
    Legend.FontSeriesColor = True
    Legend.Frame.Width = 2
    Legend.Left = 562
    Legend.ResizeChart = False
    Legend.Top = 41
    Legend.Visible = False
    MarginLeft = 1
    MarginRight = 25
    Title.Brush.Color = clWhite
    Title.Color = 3083785
    Title.Font.Color = clYellow
    Title.Font.Height = -16
    Title.Font.Style = [fsBold]
    Title.Font.Shadow.Color = clBlack
    Title.Text.Strings = (
      'CANOPY COVER')
    Title.Transparent = False
    BottomAxis.Axis.Color = clWhite
    BottomAxis.LabelsFont.Color = clWhite
    BottomAxis.LabelsFont.Style = [fsBold]
    BottomAxis.LabelStyle = talValue
    BottomAxis.Title.Caption = 'days'
    BottomAxis.Title.Font.Color = clLime
    BottomAxis.Title.Font.Style = [fsBold]
    LeftAxis.Axis.Color = clWhite
    LeftAxis.LabelsFont.Color = clWhite
    LeftAxis.LabelsFont.Style = [fsBold]
    LeftAxis.Title.Caption = 'tn / ha'
    LeftAxis.Title.Font.Color = clLime
    LeftAxis.Title.Font.Style = [fsBold]
    View3D = False
    Zoom.Animated = True
    Color = 6369292
    TabOrder = 2
    PrintMargins = (
      15
      24
      15
      24)
    object Label1: TLabel
      Left = 682
      Top = 246
      Width = 60
      Height = 16
      Caption = 'Last day'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 682
      Top = 278
      Width = 96
      Height = 16
      Caption = 'Total dry matter '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 848
      Top = 278
      Width = 28
      Height = 16
      Caption = 't / ha'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 848
      Top = 310
      Width = 28
      Height = 16
      Caption = 't / ha'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 682
      Top = 310
      Width = 94
      Height = 16
      Caption = 'Root dry matter '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 682
      Top = 340
      Width = 104
      Height = 16
      Caption = 'Root fresh matter '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 848
      Top = 340
      Width = 28
      Height = 16
      Caption = 't / ha'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object GroupBox1: TGroupBox
      Left = 692
      Top = 51
      Width = 182
      Height = 111
      Color = 3677447
      ParentColor = False
      TabOrder = 0
      object RichEdit7: TRichEdit
        Left = 15
        Top = 6
        Width = 109
        Height = 27
        TabStop = False
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        BorderStyle = bsNone
        Color = clBlack
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
      object RichEdit6: TRichEdit
        Left = 10
        Top = 0
        Width = 109
        Height = 27
        TabStop = False
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Color = 12713983
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6369292
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Show values')
        ParentBiDiMode = False
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object chbTotalDM: TCheckBox
        Left = 26
        Top = 57
        Width = 139
        Height = 21
        Caption = 'Canopy cover'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = chbTotalDMClick
      end
    end
    object Edit1: TEdit
      Left = 793
      Top = 242
      Width = 50
      Height = 24
      TabStop = False
      ReadOnly = True
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 793
      Top = 276
      Width = 50
      Height = 24
      TabStop = False
      ReadOnly = True
      TabOrder = 2
    end
    object Edit3: TEdit
      Left = 793
      Top = 308
      Width = 50
      Height = 24
      TabStop = False
      ReadOnly = True
      TabOrder = 3
    end
    object Edit4: TEdit
      Left = 793
      Top = 340
      Width = 50
      Height = 24
      TabStop = False
      ReadOnly = True
      TabOrder = 4
    end
    object Series1: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.DrawEvery = 20
      Marks.Style = smsValue
      Marks.Visible = False
      SeriesColor = clYellow
      Title = 'Canopy cover'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {
        0019000000000000000000364000000000000051400000000000C05040000000
        00004066400000000000004D4000000000000052400000000000804940000000
        00000042400000000000804F4000000000000051400000000000805740000000
        0000804940000000000040574000000000004067400000000000507340000000
        0000E074400000000000D076400000000000D074400000000000307B40000000
        0000607840000000000020714000000000007077400000000000607440000000
        00007075400000000000107740}
    end
    object Series3: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      SeriesColor = clWhite
      Title = 'LC1'
      LinePen.Style = psDot
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      SeriesColor = clLime
      Title = 'LC2'
      LinePen.Style = psDot
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object GroupBox2: TGroupBox
    Left = 788
    Top = 443
    Width = 96
    Height = 92
    Caption = 'GroupBox2'
    Color = 6369292
    ParentColor = False
    TabOrder = 0
    object SpeedButton4: TSpeedButton
      Left = 27
      Top = 37
      Width = 43
      Height = 43
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00330000000000
        03333377777777777F333301BBBBBBBB033333773F3333337F3333011BBBBBBB
        0333337F73F333337F33330111BBBBBB0333337F373F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337FF3337F33330111B0BBBB
        0333337F337733337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F3F7F33337F333301E10BBBBB0333337F7F7F33337F333301EE0BBBBB
        0333337F777FFFFF7F3333000000000003333377777777777333}
      NumGlyphs = 2
      ParentFont = False
      OnClick = SpeedButton4Click
    end
    object RichEdit2: TRichEdit
      Left = 15
      Top = 6
      Width = 70
      Height = 27
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      BorderStyle = bsNone
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object RichEdit1: TRichEdit
      Left = 10
      Top = 0
      Width = 70
      Height = 27
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Color = 12713983
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6369292
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Lines.Strings = (
        'Close')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
  end
  object tc1: TTeeCommander
    Left = 10
    Top = 10
    Width = 887
    Height = 40
    Panel = tch1
    Color = 9586706
    ParentShowHint = False
    TabOrder = 1
  end
  object SeriesTextSource1: TSeriesTextSource
    Fields = <>
    FieldSeparator = ','
  end
end
