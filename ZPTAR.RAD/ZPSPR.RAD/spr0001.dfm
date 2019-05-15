inherited frSpr0001: TfrSpr0001
  Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1103' '#1087#1083#1072#1089#1090#1080#1082#1086#1074#1099#1093' '#1082#1072#1088#1090
  ClientWidth = 501
  ExplicitWidth = 517
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Width = 501
    ExplicitWidth = 501
  end
  object cxGr: TcxGrid [1]
    Left = 0
    Top = 66
    Width = 501
    Height = 448
    Align = alClient
    TabOrder = 6
    object Vw: TcxGridTableView
      OnDblClick = VwDblClick
      Navigator.Buttons.CustomButtons = <>
      OnCustomDrawCell = VwCustomDrawCell
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnFiltering = False
      OptionsCustomize.ColumnGrouping = False
      OptionsCustomize.ColumnHidingOnGrouping = False
      OptionsCustomize.ColumnMoving = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      Styles.IncSearch = cxStyleIncSearch
      object Vw_snm: TcxGridColumn
        Caption = #1058#1080#1087' '#1082#1072#1088#1090#1099
        Options.Editing = False
        Options.Filtering = False
        Options.FilteringFilteredItemsList = False
        Options.FilteringMRUItemsList = False
        Options.FilteringPopup = False
        Options.FilteringPopupMultiSelect = False
        Options.GroupFooters = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
        Width = 80
      end
      object Vw_fnm: TcxGridColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1103' '#1087#1083#1072#1089#1090#1080#1082#1086#1074#1099#1093' '#1082#1072#1088#1090
        Options.Editing = False
        Options.Filtering = False
        Options.IncSearch = False
        Options.FilteringFilteredItemsList = False
        Options.FilteringMRUItemsList = False
        Options.FilteringPopup = False
        Options.FilteringPopupMultiSelect = False
        Options.GroupFooters = False
        Options.Grouping = False
        Options.Sorting = False
        Width = 250
      end
    end
    object Lv: TcxGridLevel
      GridView = Vw
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 501
    ExplicitWidth = 501
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
    DesignInfo = 528
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
