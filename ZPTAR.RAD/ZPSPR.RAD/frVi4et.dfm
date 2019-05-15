inherited frVV: TfrVV
  Caption = #1042#1080#1076#1099' '#1074#1099#1095#1077#1090#1086#1074
  ClientWidth = 574
  ExplicitWidth = 590
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Width = 574
    ExplicitWidth = 574
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 574
    Height = 448
    Align = alClient
    TabOrder = 6
    LayoutLookAndFeel = dxLCF
    HighlightRoot = False
    object cxGr: TcxGrid
      Left = 0
      Top = 0
      Width = 574
      Height = 448
      TabOrder = 0
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
          HeaderAlignmentHorz = taCenter
          Width = 59
        end
        object Vw_kodrf: TcxGridColumn
          Caption = #1050#1086#1076' '#1056#1060
          Width = 55
        end
        object Vw_name: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          Width = 439
        end
      end
      object Lv: TcxGridLevel
        GridView = Vw
      end
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
      ControlOptions.OriginalHeight = 446
      ControlOptions.OriginalWidth = 574
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 574
    ExplicitWidth = 574
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
