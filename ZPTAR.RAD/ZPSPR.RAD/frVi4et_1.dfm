inherited frVV1: TfrVV1
  Caption = #1042#1080#1076#1099' '#1074#1099#1095#1077#1090#1086#1074
  ClientHeight = 511
  ClientWidth = 449
  ExplicitWidth = 465
  ExplicitHeight = 550
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 488
    Width = 449
    ExplicitTop = 488
    ExplicitWidth = 449
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 449
    Height = 422
    Align = alClient
    TabOrder = 6
    LayoutLookAndFeel = dxLCF
    HighlightRoot = False
    object cxGr: TcxGrid
      Left = 0
      Top = 203
      Width = 449
      Height = 219
      TabOrder = 7
      object Vw: TcxGridTableView
        Navigator.Buttons.CustomButtons = <>
        OnCellDblClick = VwCellDblClick
        OnCustomDrawCell = VwCustomDrawCell
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.DragOpening = False
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.CellAutoHeight = True
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        OptionsView.HeaderAutoHeight = True
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object Vw_kv: TcxGridColumn
          Caption = #1082#1086#1076' '#1074#1080#1076#1072' '#1074#1099#1095#1077#1090#1072
          DataBinding.ValueType = 'Integer'
          Visible = False
          HeaderAlignmentHorz = taCenter
          SortIndex = 0
          SortOrder = soAscending
          Width = 107
        end
        object Vw_kod: TcxGridColumn
          Caption = #1050#1086#1076
          Visible = False
          HeaderAlignmentHorz = taCenter
          Width = 62
        end
        object Vw_kodrf: TcxGridColumn
          Caption = #1050#1086#1076' '#1056#1060
          HeaderAlignmentHorz = taCenter
          Width = 58
        end
        object Vw_name: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          HeaderAlignmentHorz = taCenter
          Width = 282
        end
        object Vw_ndfl: TcxGridColumn
          Caption = #1053#1044#1060#1051
          DataBinding.ValueType = 'Float'
          Visible = False
          HeaderAlignmentHorz = taCenter
          Width = 157
        end
        object Vw_sk: TcxGridColumn
          Caption = #1057#1082#1080#1076#1082#1072' '#1087#1086' '#1074#1079#1085#1086#1089#1072#1084
          DataBinding.ValueType = 'Float'
          Visible = False
          HeaderAlignmentHorz = taCenter
          Width = 160
        end
        object Vw_sum: TcxGridColumn
          Caption = #1057#1091#1084#1084#1072
          DataBinding.ValueType = 'Float'
          Visible = False
          HeaderAlignmentHorz = taCenter
        end
        object Vw_pr: TcxGridColumn
          Caption = #1055#1088#1077#1076#1077#1083
          DataBinding.ValueType = 'Float'
          Visible = False
          HeaderAlignmentHorz = taCenter
        end
      end
      object Lv: TcxGridLevel
        GridView = Vw
      end
    end
    object cxOk: TcxButton
      Left = 168
      Top = 133
      Width = 131
      Height = 23
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 4
    end
    object cxCancel: TcxButton
      Left = 304
      Top = 133
      Width = 131
      Height = 23
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 5
    end
    object cxTE_N: TcxTextEdit
      Left = 103
      Top = 21
      Style.HotTrack = False
      StyleDisabled.TextColor = clWindowText
      TabOrder = 0
      Text = 'cxTE_N'
      Width = 332
    end
    object cxCE_SNDFL: TcxCurrencyEdit
      Left = 14
      Top = 77
      Style.HotTrack = False
      TabOrder = 2
      Width = 421
    end
    object cxCE_SV: TcxCurrencyEdit
      Left = 14
      Top = 105
      Style.HotTrack = False
      TabOrder = 3
      Width = 421
    end
    object cxCE_KodRF: TcxCurrencyEdit
      Left = 103
      Top = 49
      EditValue = 1.000000000000000000
      Properties.DisplayFormat = '0'
      Properties.MinValue = 1.000000000000000000
      Style.HotTrack = False
      StyleDisabled.TextColor = clWindowText
      TabOrder = 1
      Width = 332
    end
    object cxDE: TcxDateEdit
      Left = 31
      Top = 175
      Properties.DisplayFormat = 'YYYY'
      Properties.EditFormat = 'YYYY'
      Style.HotTrack = False
      StyleDisabled.TextColor = clWindowText
      TabOrder = 6
      Width = 121
    end
    object dxLayoutControl1Group_Root: TdxLayoutGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = -1
    end
    object dxLayoutControl1Item1: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avClient
      Control = cxGr
      ControlOptions.OriginalHeight = 416
      ControlOptions.OriginalWidth = 536
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLCNew: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = #1053#1086#1074#1086#1077'\'#1050#1086#1088#1088#1077#1082#1090#1080#1088#1086#1074#1082#1072
      ButtonOptions.Buttons = <>
      Index = 0
    end
    object dxLayoutItem3: TdxLayoutItem
      Parent = dxLayoutAutoCreatedGroup1
      AlignHorz = ahRight
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = cxOk
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 131
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutItem4: TdxLayoutItem
      Parent = dxLayoutAutoCreatedGroup1
      AlignHorz = ahRight
      CaptionOptions.Text = 'cxButton2'
      CaptionOptions.Visible = False
      Control = cxCancel
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 131
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutAutoCreatedGroup1: TdxLayoutAutoCreatedGroup
      Parent = dxLCNew
      LayoutDirection = ldHorizontal
      Index = 4
      AutoCreated = True
    end
    object dxLayoutItem2: TdxLayoutItem
      Parent = dxLCNew
      AlignHorz = ahClient
      CaptionOptions.Text = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      Control = cxTE_N
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutItem5: TdxLayoutItem
      Parent = dxLCNew
      Control = cxCE_SNDFL
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutItem6: TdxLayoutItem
      Parent = dxLCNew
      Control = cxCE_SV
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object dxLayoutItem1: TdxLayoutItem
      Parent = dxLCNew
      CaptionOptions.Text = #1050#1086#1076' '#1056#1060
      Control = cxCE_KodRF
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutItem7: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahLeft
      CaptionOptions.Text = #1044#1072#1090#1072
      Control = cxDE
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 449
    ExplicitWidth = 449
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
    end
  end
  inherited alfr: TActionList
    inherited aRefresh: TAction
      Enabled = True
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
  object dxLayoutLookAndFeelList1: TdxLayoutLookAndFeelList
    Left = 536
    Top = 80
    object dxLCF: TdxLayoutCxLookAndFeel
      GroupOptions.Color = clMoneyGreen
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ItemOffset = 3
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
  end
end
