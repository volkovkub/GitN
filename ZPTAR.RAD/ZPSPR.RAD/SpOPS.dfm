inherited fmSpOPS: TfmSpOPS
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1050#1069#1056'"'
  ClientHeight = 596
  ClientWidth = 547
  ExplicitWidth = 563
  ExplicitHeight = 635
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 573
    Width = 547
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end>
    ExplicitTop = 573
    ExplicitWidth = 547
  end
  object lc: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 547
    Height = 507
    Align = alClient
    TabOrder = 1
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object dbgSpr: TcxGrid
      Left = 0
      Top = 116
      Width = 547
      Height = 391
      TabOrder = 4
      OnEnter = dbgSprEnter
      object tv: TcxGridTableView
        OnDblClick = tvDblClick
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvCustomDrawCell
        OnFocusedRecordChanged = tvFocusedRecordChanged
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object tvKod: TcxGridColumn
          Caption = #1050#1086#1076
          Width = 101
        end
        object tvName: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          Width = 469
        end
      end
      object dbgSprLevel1: TcxGridLevel
        GridView = tv
      end
    end
    object edKod: TcxMaskEdit
      Left = 103
      Top = 21
      Properties.AlwaysShowBlanksAndLiterals = True
      Properties.CharCase = ecUpperCase
      Properties.MaxLength = 0
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      TabOrder = 0
      Width = 133
    end
    object edName: TcxTextEdit
      Left = 103
      Top = 49
      Properties.CharCase = ecUpperCase
      Properties.MaxLength = 40
      Style.HotTrack = False
      TabOrder = 1
      Width = 430
    end
    object bnSave: TcxButton
      Left = 72
      Top = 77
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 2
      OnClick = bnSaveClick
    end
    object bnCancel: TcxButton
      Left = 334
      Top = 77
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
      LookAndFeel.NativeStyle = False
      TabOrder = 3
      OnClick = bnCancelClick
    end
    object lcGroup_Root: TdxLayoutGroup
      AlignHorz = ahParentManaged
      AlignVert = avParentManaged
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = -1
    end
    object lcEdit: TdxLayoutGroup
      Parent = lcGroup_Root
      CaptionOptions.Text = #1044#1086#1073#1072#1074#1080#1090#1100'/'#1050#1086#1088#1088#1077#1082#1090#1080#1088#1086#1074#1072#1090#1100
      LayoutLookAndFeel = dxLayoutCxLookAndFeel2
      ButtonOptions.Buttons = <>
      Index = 0
    end
    object lcitKod: TdxLayoutItem
      Parent = lcEdit
      AlignHorz = ahLeft
      CaptionOptions.Text = #1050#1086#1076
      Control = edKod
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 133
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object lcitName: TdxLayoutItem
      Parent = lcEdit
      CaptionOptions.Text = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      Control = edName
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 429
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object lcGroup1: TdxLayoutGroup
      Parent = lcEdit
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 2
    end
    object lcGroup2: TdxLayoutGroup
      Parent = lcGroup1
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 0
    end
    object lcItem2: TdxLayoutItem
      Parent = lcGroup2
      AlignHorz = ahCenter
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = bnSave
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object lcGroup3: TdxLayoutGroup
      Parent = lcGroup1
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object lcItem3: TdxLayoutItem
      Parent = lcGroup3
      AlignHorz = ahCenter
      CaptionOptions.Text = 'cxButton2'
      CaptionOptions.Visible = False
      Control = bnCancel
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object lcSpr: TdxLayoutGroup
      Parent = lcGroup_Root
      AlignVert = avClient
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object lcItem1: TdxLayoutItem
      Parent = lcSpr
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid1'
      CaptionOptions.Visible = False
      Control = dbgSpr
      ControlOptions.OriginalHeight = 391
      ControlOptions.OriginalWidth = 547
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 547
    ExplicitWidth = 547
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
    end
  end
  inherited alfr: TActionList
    Left = 120
    Top = 472
    inherited aNew: TAction
      Enabled = True
      Visible = True
    end
    inherited aKor: TAction
      Visible = True
    end
    inherited aDel: TAction
      Visible = True
    end
    inherited aOk: TAction
      Visible = True
    end
    object acFind: TAction
      Category = #1055#1086#1080#1089#1082
      AutoCheck = True
      Caption = #1055#1086#1080#1089#1082
      Enabled = False
      ImageIndex = 19
      Visible = False
    end
    object acSelFind: TAction
      Category = #1055#1086#1080#1089#1082
      Caption = #1042#1099#1073#1086#1088
    end
  end
  inherited BarManager: TdxBarManager
    PixelsPerInch = 96
  end
  inherited cxImageLst32: TcxImageList
    FormatVersion = 1
  end
  inherited cxImageListD: TcxImageList
    FormatVersion = 1
  end
  inherited cxPropertiesStore: TcxPropertiesStore
    Components = <
      item
        Component = fraspr03.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'PixelsPerInch'
          'Top'
          'Width'
          'WindowState')
      end>
  end
  inherited cxStyleRepositoryVDS: TcxStyleRepository
    PixelsPerInch = 96
  end
  inherited cxImageLst16: TcxImageList
    FormatVersion = 1
  end
  object cxImageList4: TcxImageList
    SourceDPI = 96
    FormatVersion = 1
    DesignInfo = 30933408
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000050F0B1214382B45205D46752472
          5598217253A2186849A20E493382051C13350000000000000000000000000000
          00000000000000000000133A2B4E359471B84ED0A0F455DCABFF50D9A7FF46CA
          99FF3ABB8BFF2CA97AFF1F996BFF178E60FF06291B5600000000000000000000
          0000000000001B57417742C594FF4CD4A1FF5DE1B0FF68E2B6FF59E0AFFF4AD0
          9FFF3DBF8EFF30AF7FFF23A070FF17875AFF0523174900000000000000000000
          000000000000226E529732B181FF4BD09FFF56DDABFF61E0B2FF56DEACFF4AD0
          9EFF3DBF8EFF2EAC7DFF1A9265FF127A53FF03130C2600000000000000000000
          0000000000001549356A1B9366FF34AF80FF4CC395FF53CFA1FF4DD0A0FF42C5
          94FF34B483FF219D6DFF41B488FF298B64DF0002010400000000000000000000
          0000000000000921183044BF90F759C99EFF4DB88DFF42B88AFF39B888FF30AF
          7FFF28A675FF26A775FF89E1C0FF1944326C0000000000000000000000000000
          000000000000000000000A2219311D64488C27936AD11C9869FD209A6CFF24A1
          71FF47C998FF41B588E8092D204C000000000000000000000000000000000000
          0000000000000000000000000000081B142927574476329D73EF158C5FFF2FAE
          7EFF2A7D5EAC0107050D00000000000000000000000000000000000000000000
          0000000000000000000000000000156947C6249D6FFF3DAF83FF269C6EFF2498
          6BFC03120C1E0000000000000000000000000000000000000000000000000000
          0000000000000000000004150E2817714CFF178C5FFF22A06FFF24A171FF1783
          58FF03150E270000000000000000000000000000000000000000000000000000
          000000000000000000000D30215C175F40FF116E49FF1B9567FF22A06FFF23A0
          6FFF082F1F640000000000000000000000000000000000000000000000000000
          00000000000000000000123B2A7A146A49FF0F6544FF106A45FF13784FFF1278
          4FFF0A432CA70000000000000000000000000000000000000000000000000000
          000000000000000000000E32237337B684FF35AF80FF106C46FF0F5D3EFF1B89
          5CFF0E4830C50000000000000000000000000000000000000000000000000000
          0000000000000000000005130D4089E6C1FFAAEFD1FF249569FF157A52FF4CC5
          96FF144530AE0000000000000000000000000000000000000000000000000000
          00000000000000000000000000002544368A57C299FF1C8158FF269469FF9CDE
          C5F609130D3D0000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000020A073E051C128D0621157B040A
          081D000000000000000000000000000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FC030000F0010000E0010000E0010000E0010000E0030000F0070000F80F
          0000F81F0000F01F0000F01F0000F01F0000F01F0000F01F0000F81F0000FC3F
          0000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000D0D0D123A3A3A4E6666668C7A7A
          7AB5767676BD666666BB45454593181818360000000000000000000000000000
          0000000000000000000036363650919191C5C1C1C1F8CDCDCDFFC6C6C6FFBBBB
          BBFFA9A9A9FF969696FF828282FF747474FF2222225800000000000000000000
          00000000000050505079B4B4B4FFC3C3C3FFD5D5D5FFE2E2E2FFD3D3D3FFBEBE
          BEFFAFAFAFFF9C9C9CFF8B8B8BFF6E6E6EFF1C1C1C4A00000000000000000000
          0000000000006565659A9D9D9DFFC1C1C1FFD0D0D0FFDADADAFFD0D0D0FFC0C0
          C0FFB1B1B1FF9B9B9BFF757575FF616161FF0F0F0F2600000000000000000000
          0000000000004444446E6F6F6FFF979797FFBABABAFFC8C8C8FFC6C6C6FFB8B8
          B8FFA0A0A0FF7D7D7DFFACACACFF7F7F7FE00202020400000000000000000000
          0000000000001E1E1E31BCBCBCFAD4D4D4FFB4B4B4FFB3B3B3FFABABABFF9999
          99FF858585FF868686FFEDEDEDFF4141416D0000000000000000000000000000
          000000000000000000001F1F1F32767676C0949494F7656565FF7E7E7EFF7D7D
          7DFFC6C6C6FFB3B3B3ED2626264D000000000000000000000000000000000000
          00000000000000000000000000001919192972727290A2A2A2FF545454FFA3A3
          A3FF909090CA0606060D00000000000000000000000000000000000000000000
          0000000000000000000000000000646464FD818181FFBBBBBBFF888888FF8B8B
          8BFE0F0F0F1E0000000000000000000000000000000000000000000000000000
          0000000000000000000012121228555555FF747474FF8B8B8BFF939393FF5F5F
          5FFF111111270000000000000000000000000000000000000000000000000000
          0000000000000000000044444487454545FF4A4A4AFF888888FF949494FF9C9C
          9CFF2E2E2E790000000000000000000000000000000000000000000000000000
          000000000000000000004D4D4DA3484848FF404040FF4A4A4AFF616161FF5B5B
          5BFF3A3A3AC00000000000000000000000000000000000000000000000000000
          0000000000000000000034343486A9A9A9FFA3A3A3FF4B4B4BFF3E3E3EFF7777
          77FF3D3D3DD40000000000000000000000000000000000000000000000000000
          000000000000000000000F0F0F42EEEEEEFFFFFFFFFF828282FF606060FFC1C1
          C1FF404040B60000000000000000000000000000000000000000000000000000
          00000000000000000000000000004C4C4C8BC1C1C1FF707070FF838383FFF1F1
          F1F61313133D0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000101013E0C0C0C8D1717177C0B0B
          0B1D000000000000000000000000000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FC030000F0010000E0010000E0010000E0010000E0030000F0070000F80F
          0000F81F0000F01F0000F01F0000F01F0000F01F0000F01F0000F81F0000FC3F
          0000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000040711120F1A4245182A6E761931
          8999152F8DA30C2684A304176183000926350000000000000000000000000000
          000000000000000000000D19474F2744AEB93C63EEF4436AFCFF3E66F9FF335B
          EEFF274FE2FF1840D3FF0B33C6FF022ABCFF000D3A5700000000000000000000
          00000000000012256A782F57EAFF3A63F6FF4D74FFFF5B7EFFFF4970FFFF375F
          F3FF2A52E5FF1D45D8FF0F38CCFF0329B4FF000B314A00000000000000000000
          000000000000182F879A1E47DAFF3A62F5FF456EFEFF5377FEFF446DFEFF3861
          F4FF2B53E6FF1D45D8FF0427BCFF001FA6FF00061A2600000000000000000000
          0000000000000D1F5E6E0528BBFF1D45D5FF3B60E7FF466BF4FF3F66F6FF3159
          EDFF224ADDFF072EC2FF3156DDFF1C3DB4E30001030400000000000000000000
          000000000000060D2931375DE8F95878EFFF4565D7FF3559DEFF2950E2FF1B44
          D7FF0C34C7FF092BCBFF9AB1FAFF132359720000000000000000000000000000
          00000000000000000000060E2A31142F93AA1039D0EE011DBCFF0931C3FF042C
          C1FF436BF9FF4165E9F3030E3D51000000000000000000000000000000000000
          0000000000000000000000000000060C22292D3D7989284CD1FD0011A9FF234B
          E1FF2F4FC5D600020A0D00000000000000000000000000000000000000000000
          0000000000000000000000000000032398DD0731CAFF3E60DFFF153CC5FF123B
          C8FE0106171E0000000000000000000000000000000000000000000000000000
          0000000000000000000001071D28082799FF0128BEFF0C36D0FF123AD2FF0224
          A5FF00061C270000000000000000000000000000000000000000000000000000
          00000000000000000000081443600C2785FF001F97FF0731CBFF103AD3FF143E
          D8FF01114A730000000000000000000000000000000000000000000000000000
          000000000000000000000C1C527E042094FF00188BFF002092FF0125A6FF0022
          A4FF001666B20000000000000000000000000000000000000000000000000000
          0000000000000000000008154674244DDFFF2149DBFF002095FF001C85FF082E
          B7FF03196CC90000000000000000000000000000000000000000000000000000
          0000000000000000000002081D407F9CFCFFA6BCFFFF1137C1FF0325A6FF3D62
          E9FF0C1E62B00000000000000000000000000000000000000000000000000000
          0000000000000000000000000000212D588B496BE4FF0B2EAEFF1439BFFF96A9
          EFF6070C1C3D0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000002123E000A308D010D357C0306
          0F1D000000000000000000000000000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FC030000F0010000E0010000E0010000E0010000E0030000F0070000F80F
          0000F81F0000F01F0000F01F0000F01F0000F01F0000F01F0000F81F0000FC3F
          0000}
      end>
  end
  object cxImageList2: TcxImageList
    SourceDPI = 96
    FormatVersion = 1
    DesignInfo = 30933304
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000100000007000000090000
          0004000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000B090704492D20138948311EA949341FAA2F22
          148F0A0804560000001800000001000000000000000000000000000000000000
          0000000000000302012A614328BAD29859FED39755FFBC6E45FFB25A3DFFBF6C
          46FFC68358FF6A4E35C40504023D000000000000000000000000000000000000
          00000302011E955A3AE2C17C4BFFB67946FFB17745FFB47C49FF892C23FF8829
          28FFAB635CFFD18F77FFA5754DE80403022C0000000000000000000000000000
          000077432CC6AC603FFFB9834EFFC38F59FFCDA369FFD2AA6EFFAA5032FF9B32
          27FFA2544FFF9E5756FFB15C45FF805332C90000000100000000000000005332
          216BA03E34FFAE6244FFD7B375FFE2C483FFDC9662FFD45735FFD14D2AFFC348
          2BFFB0412BFF952B25FF7B191CFFAE5E3DFF5540256A040302051B0F0A26803A
          2CCAAC5747FFCC8256FFE7AD71FFE99459FFE96E30FFEB793CFFE7793FFFE369
          37FFCF4123FFC6814FFFAC7047FF9E5A36FFA97D47C83729183F391F14559E5B
          3FF0D29974FFD77C4BFFE48C52FFEF984EFFF2AA56FFF4AE57FFEDA353FFED8B
          49FFDF5C2DFFEBDB95FFD0A366FFB47A46FFBA834BF0604628735138206EBE8A
          57FDE6A888FFEC8F57FFF09F4FFFF5C064FFF7CD6EFFF6CC68FFF5C563FFF4AC
          5BFFE68245FFF8E8A4FFDAAE70FFBA844FFFBB834BFA6B4E2C87412B195AB784
          54F3F0DBB4FFFCE9B5FFF5C368FFFBDA6AFFFCEC74FFFCE374FFF8D46EFFF5C1
          63FFEC8A40FFF0C383FFDFB977FFAC6945FF975735F2482C1B7A20160E2E9B6F
          45D0EFD7ACFFFFFAD2FFFAEA97FFFBF07CFFFFFD80FFFFF97AFFFCE576FFF6C8
          67FFF09B4CFFEAA86EFFD29261FFAA643FFF8C5935D12C190F49000000005943
          2E75E3BD84FFFFEEAAFFFBF7B9FFF6FDBFFFFCFEE1FFFFFF8FFFFCEB75FFF6C9
          69FFF0A055FFE38C57FFD29E66FFBA844EFF4D2D1C7506030209000000000101
          0101B28F62D5F2BD86FFFCECCEFFFBFED9FFFFFFB3FFFDF57CFFFADB6EFFF4B8
          5FFFEE904CFFE16F3FFFB65838FF956644D40200000400000000000000000000
          000029231C31D1A477ECF3C395FFFEF7D4FFFDF2BBFFFAF0B0FFF5C371FFEEA5
          5DFFE77E47FFCB4E2EFFA04F40EC1E110D320000000000000000000000000000
          0000000000001B15121FA3836AB5EFAD85FFF3BC96FFFCF0CDFFF9E6BFFFEABE
          98FFDB9076FF8F6359B6140F0E21000000000000000000000000000000000000
          0000000000000000000000000000281F1C2D655347739C8D76A89A8C77A96960
          537328221F2D0000000000000000000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FC3F0000F0070000E0070000C0030000C001000080000000000000000000
          00000000000000000000000000008000000080010000C0030000E0070000F81F
          0000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000090909103636365C626262B1767676E7707070FA727272FA7A7A
          7AE7656565B23636365C09090910000000000000000000000000000000000000
          0000272727426A6A6AB5A5A5A5FFB3B3B3FFA5A5A5FF949494FF959595FFA9A9
          A9FFB9B9B9FFA7A7A7FF6C6C6CB6272727420000000000000000000000002222
          223A7F7F7FD1CBCBCBFFC0C0C0FFB9B9B9FFCFCFCFFFDCDCDCFFDCDCDCFFCFCF
          CFFFBFBFBFFFC1C1C1FFCACACAFF808080D12222223A00000000000000006161
          619DC0C0C0FF7A7A7AFF767676FF828282FF7F7F7FFF6B6B6BFF6D6D6DFF8383
          83FF848484FF777777FF7C7C7CFFB6B6B6FF666666A200000000000000004949
          497A888888FF6D6D6DFFAAAAAAFFB8B8B8FFBBBBBBFF9D9D9DFF9E9E9EFFBFBF
          BFFFBEBEBEFFADADADFF6E6E6EFF888888FF3E3E3E6900000000000000006363
          63E9AAAAAAFFCECECEFFBCBCBCFFB3B3B3FFB0B0B0FFAFAFAFFFAFAFAFFFAEAE
          AEFFB2B2B2FFBDBDBDFFCACACAFFA9A9A9FF5C5C5CEB00000000000000005C5C
          5CC0BFBFBFFF747474FF747474FF828282FF7F7F7FFF696969FF6A6A6AFF8383
          83FF858585FF767676FF767676FFB7B7B7FF5B5B5BC700000000000000002F2F
          2F59888888FF777777FFB2B2B2FFBEBEBEFFBBBBBBFFA5A5A5FFA5A5A5FFB7B7
          B7FFC3C3C3FFB4B4B4FF787878FF888888FF2222224200000000000000006363
          63EFB0B0B0FFCBCBCBFFBCBCBCFFCDCDCDFFDEDEDEFFEAEAEAFFEAEAEAFFDEDE
          DEFFCDCDCDFFBCBCBCFFC6C6C6FFAEAEAEFF606060F000000000000000007272
          72F4B8B8B8FF818181FFA8A8A8FFC3C3C3FFD1D1D1FFD7D7D7FFD7D7D7FFD1D1
          D1FFC4C4C4FFAAAAAAFF838383FFB1B1B1FF6E6E6EF500000000000000009696
          96F5909090FF8F8F8FFFA1A1A1FFBBBBBBFFC9C9C9FFD0D0D0FFD0D0D0FFCACA
          CAFFBBBBBBFFA1A1A1FF8F8F8FFF909090FF969696F700000000000000009393
          93EEAAAAAAFFBCBCBCFFBCBCBCFFBFBFBFFFC6C6C6FFCACACAFFCCCCCCFFC7C7
          C7FFBFBFBFFFBCBCBCFFBCBCBCFFABABABFF8D8D8DF000000000000000006060
          60A1BABABAFFDDDDDDFFD6D6D6FFD6D6D6FFD5D5D5FFD4D4D4FFD4D4D4FFD5D5
          D5FFD6D6D6FFD6D6D6FFDDDDDDFFB9B9B9FF656565A700000000000000002121
          213A7E7E7ED2D2D2D2FFECECECFFECECECFFEBEBEBFFEAEAEAFFEAEAEAFFEBEB
          EBFFECECECFFECECECFFD6D6D6FF7E7E7ED32121213A00000000000000000000
          0000252525426C6C6CB6C7C7C7FFE8E8E8FFF3F3F3FFFBFBFBFFFBFBFBFFF5F5
          F5FFE9E9E9FFC9C9C9FF6D6D6DB6252525420000000000000000000000000000
          000000000000090909103434345B737373AEA8A8A8E4B1B1B1FAB1B1B1FAA9A9
          A9E5757575AF3434345C09090910000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00E0070000C003000080010000800100008001000080010000800100008001
          0000800100008001000080010000800100008001000080010000C0030000E007
          0000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000090909103535355A616161AE777777E4747474F9757575F97A7A
          7AE4696969BE3535355A09090910000000000000000000000000000000000000
          000027272742656565AD949494FF959595FF909090FF7D7D7DFF808080FF9797
          97FF9B9B9BFF969696FF656565AD272727420000000000000000000000002222
          223A767676CABABABAFFC6C6C6FFCBCBCBFFD7D7D7FFE4E4E4FFE4E4E4FFD2D2
          D2FFCDCDCDFFC8C8C8FFB1B1B1FF767676C92222223A00000000000000005858
          5896B4B4B4FFA3A3A3FF929292FF8E8E8EFF8C8C8CFF868686FF878787FF8C8C
          8CFF8E8E8EFF939393FFA2A2A2FFB1B1B1FF5959599800000000000000009292
          92E4999999FF626262FF838383FF979797FF929292FF808080FF828282FF9898
          98FF9D9D9DFF868686FF656565FF939393FF979797E600000000000000006969
          69E78D8D8DFFB2B2B2FFC8C8C8FFD4D4D4FFDDDDDDFFE8E8E8FFE8E8E8FFDEDE
          DEFFD0D0D0FFC9C9C9FFAFAFAFFF929292FF6B6B6BEA00000000000000005757
          57C0C2C2C2FFA5A5A5FFACACACFFC3C3C3FFCFCFCFFFD4D4D4FFD4D4D4FFD0D0
          D0FFC3C3C3FFADADADFFA5A5A5FFBDBDBDFF565656C600000000000000006565
          65BE9C9C9CFF868686FFA9A9A9FFC0C0C0FFCDCDCDFFD3D3D3FFD3D3D3FFCDCD
          CDFFC1C1C1FFAAAAAAFF878787FF979797FF636363C300000000000000009595
          95E79A9A9AFFA2A2A2FFA9A9A9FFBBBBBBFFC8C8C8FFCFCFCFFFCFCFCFFFC9C9
          C9FFBBBBBBFFA9A9A9FFA1A1A1FF9A9A9AFF9B9B9BEA00000000000000009292
          92E5BBBBBBFFCBCBCBFFC9C9C9FFC8C8C8FFCACACAFFCCCCCCFFCCCCCCFFCACA
          CAFFC8C8C8FFC9C9C9FFCBCBCBFFBBBBBBFF959595E800000000000000005C5C
          5C9AC4C4C4FFDEDEDEFFDFDFDFFFDEDEDEFFDEDEDEFFDEDEDEFFDEDEDEFFDEDE
          DEFFDEDEDEFFDFDFDFFFDFDFDFFFC0C0C0FF6161619E00000000000000002222
          223A7B7B7BCBD6D6D6FFE9E9E9FFF1F1F1FFF2F2F2FFF1F1F1FFF1F1F1FFF2F2
          F2FFF1F1F1FFEAEAEAFFD7D7D7FF7B7B7BCB2222223A00000000000000000000
          000027272742656565ADBDBDBDFFDEDEDEFFE7E7E7FFECECECFFECECECFFE8E8
          E8FFE0E0E0FFC0C0C0FF656565AD272727420000000000000000000000000000
          000000000000090909103535355A888888B9C2C2C2EEC4C4C4FCC4C4C4FCC3C3
          C3EE8A8A8AB93535355A09090910000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        Mask.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FFFF0000E0070000C0030000800100008001000080010000800100008001
          00008001000080010000800100008001000080010000C0030000E0070000FFFF
          0000}
      end>
  end
  object dxLayoutLookAndFeelList1: TdxLayoutLookAndFeelList
    Left = 352
    Top = 472
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ItemOffset = 0
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
    object dxLayoutCxLookAndFeel2: TdxLayoutCxLookAndFeel
      GroupOptions.CaptionOptions.TextDisabledColor = clBlack
      GroupOptions.Color = clMoneyGreen
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ItemOffset = 3
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
  end
end
