inherited frSpKfrEd: TfrSpKfrEd
  Caption = #1053#1086#1074#1086#1077'/'#1050#1086#1088#1088#1077#1082#1090#1080#1088#1086#1074#1082#1072
  ClientHeight = 480
  ClientWidth = 818
  OnShow = FormShow
  ExplicitWidth = 834
  ExplicitHeight = 519
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 457
    Width = 818
    ExplicitTop = 457
    ExplicitWidth = 818
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 818
    Height = 391
    Align = alClient
    FocusOnClick = False
    TabOrder = 9
    object cxBtEdBSD: TcxButtonEdit
      Left = 12
      Top = 33
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxBtEdBSDPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 0
      Text = 'cxBtEdBSD'
      OnKeyPress = cxBtEdBSDKeyPress
      Width = 594
    end
    object cxTxtEDker: TcxButtonEdit
      Left = 170
      Top = 90
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDkerPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 3
      Text = 'cxTxtEDker'
      OnExit = cxTxtEDkerExit
      OnKeyPress = cxTxtEDkerKeyPress
      Width = 121
    end
    object cxTxtEDisf: TcxButtonEdit
      Left = 170
      Top = 120
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDisfPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 5
      Text = 'cxTxtEDisf'
      OnExit = cxTxtEDisfExit
      OnKeyPress = cxTxtEDisfKeyPress
      Width = 121
    end
    object cxTxtEDsbker: TcxButtonEdit
      Left = 170
      Top = 150
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDsbkerPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 7
      Text = 'cxTxtEDsbker'
      OnExit = cxTxtEDsbkerExit
      OnKeyPress = cxTxtEDsbkerKeyPress
      Width = 121
    end
    object cxTxtEDtf: TcxButtonEdit
      Left = 170
      Top = 180
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDtfPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 9
      Text = 'cxTxtEDtf'
      OnExit = cxTxtEDtfExit
      OnKeyPress = cxTxtEDtfKeyPress
      Width = 121
    end
    object cxTxtEDts: TcxButtonEdit
      Left = 170
      Top = 210
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDtsPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 11
      Text = 'cxTxtEDts'
      OnExit = cxTxtEDtsExit
      OnKeyPress = cxTxtEDtsKeyPress
      Width = 121
    end
    object cxTxtEDmrp: TcxButtonEdit
      Left = 170
      Top = 240
      Properties.Alignment.Horz = taRightJustify
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.OnButtonClick = cxTxtEDmrpPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 13
      Text = 'cxTxtEDmrp'
      OnExit = cxTxtEDmrpExit
      OnKeyPress = cxTxtEDmrpKeyPress
      Width = 121
    end
    object cxLbKER: TcxLabel
      Left = 298
      Top = 90
      Caption = 'cxLbKER'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxLbISF: TcxLabel
      Left = 298
      Top = 120
      Caption = 'cxLbISF'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxLbSBKER: TcxLabel
      Left = 298
      Top = 150
      Caption = 'cxLbSBKER'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxLbTF: TcxLabel
      Left = 298
      Top = 180
      Caption = 'cxLbTF'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxLbTS: TcxLabel
      Left = 298
      Top = 210
      Caption = 'cxLbTS'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxLbMRP: TcxLabel
      Left = 298
      Top = 240
      Caption = 'cxLbMRP'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      Properties.LabelStyle = cxlsRaised
    end
    object cxBtEdBSK: TcxButtonEdit
      Left = 613
      Top = 33
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxBtEdBSDPropertiesButtonClick
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      TabOrder = 1
      Text = 'cxBtEdBSK'
      OnKeyPress = cxBtEdBSKKeyPress
      Width = 193
    end
    object cxLbBSDBSK: TcxLabel
      Left = 12
      Top = 63
      Caption = 'cxLbBSDBSK'
      Style.HotTrack = False
      StyleDisabled.Color = clBtnFace
      StyleDisabled.TextColor = clBlack
      Properties.Alignment.Horz = taCenter
      Properties.LabelStyle = cxlsRaised
      AnchorX = 409
    end
    object dxLayoutControl1Group_Root: TdxLayoutGroup
      AlignHorz = ahParentManaged
      AlignVert = avParentManaged
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = -1
    end
    object dxLayoutControl1Group7: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Group8: TdxLayoutGroup
      Parent = dxLayoutControl1Group7
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item1: TdxLayoutItem
      Parent = dxLayoutControl1Group8
      AlignHorz = ahClient
      CaptionOptions.Text = #1044#1077#1073#1077#1090
      CaptionOptions.Layout = clTop
      Control = cxBtEdBSD
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 405
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item14: TdxLayoutItem
      Parent = dxLayoutControl1Group8
      AlignHorz = ahClient
      CaptionOptions.Text = #1050#1088#1077#1076#1080#1090
      CaptionOptions.Layout = clTop
      Control = cxBtEdBSK
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 132
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item15: TdxLayoutItem
      Parent = dxLayoutControl1Group7
      CaptionOptions.Text = 'cxLabel7'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxLbBSDBSK
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group1: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item2: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = #1050#1069#1056
      Control = cxTxtEDker
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item8: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel1'
      CaptionOptions.Visible = False
      Control = cxLbKER
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = #1048#1089#1090#1086#1095#1085#1080#1082' '#1092#1080#1085#1072#1085#1089#1080#1088#1086#1074#1072#1085#1080#1103
      Control = cxTxtEDisf
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item9: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel2'
      CaptionOptions.Visible = False
      Control = cxLbISF
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group3: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 3
    end
    object dxLayoutControl1Item4: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = #1057#1091#1073#1050#1069#1057#1056
      Control = cxTxtEDsbker
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item10: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel3'
      CaptionOptions.Visible = False
      Control = cxLbSBKER
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group4: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 4
    end
    object dxLayoutControl1Item5: TdxLayoutItem
      Parent = dxLayoutControl1Group4
      CaptionOptions.Text = #1058#1080#1087' '#1092#1080#1085#1072#1085#1089#1080#1088#1086#1074#1072#1085#1080#1103
      Control = cxTxtEDtf
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item11: TdxLayoutItem
      Parent = dxLayoutControl1Group4
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel4'
      CaptionOptions.Visible = False
      Control = cxLbTF
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group5: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 5
    end
    object dxLayoutControl1Item6: TdxLayoutItem
      Parent = dxLayoutControl1Group5
      CaptionOptions.Text = #1058#1080#1087' '#1089#1088#1077#1076#1089#1090#1074
      Control = cxTxtEDts
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item12: TdxLayoutItem
      Parent = dxLayoutControl1Group5
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel5'
      CaptionOptions.Visible = False
      Control = cxLbTS
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group6: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 6
    end
    object dxLayoutControl1Item7: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      CaptionOptions.Text = #1052#1077#1088#1086#1087#1088#1080#1103#1090#1080#1103
      Control = cxTxtEDmrp
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item13: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxLabel6'
      CaptionOptions.Visible = False
      Control = cxLbMRP
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
  end
  object cxTxtEdKD: TcxTextEdit [2]
    Left = 12
    Top = 432
    Enabled = False
    TabOrder = 6
    Text = 'cxTxtEdKD'
    Visible = False
    Width = 121
  end
  object cxTxtEdKO: TcxTextEdit [3]
    Left = 139
    Top = 432
    Enabled = False
    TabOrder = 7
    Text = 'cxTxtEdKO'
    Visible = False
    Width = 121
  end
  object cxTxtEdKS: TcxTextEdit [4]
    Left = 266
    Top = 432
    Enabled = False
    TabOrder = 8
    Text = 'cxTxtEdKS'
    Visible = False
    Width = 121
  end
  inherited dxRibbonA: TdxRibbon
    Width = 818
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
    end
  end
  inherited alfr: TActionList
    Left = 432
    Top = 304
    inherited aSave: TAction
      Enabled = True
      Visible = True
    end
  end
  inherited BarManager: TdxBarManager
    Left = 504
    Top = 200
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
end
