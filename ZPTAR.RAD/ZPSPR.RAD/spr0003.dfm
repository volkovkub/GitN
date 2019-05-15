inherited frSpr0003: TfrSpr0003
  Caption = #1058#1080#1087' '#1092#1086#1088#1084#1099
  ClientHeight = 448
  ClientWidth = 736
  Constraints.MinHeight = 300
  Constraints.MinWidth = 500
  ExplicitWidth = 752
  ExplicitHeight = 487
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 425
    Width = 736
    ExplicitTop = 425
    ExplicitWidth = 736
  end
  object cxGr: TcxGrid [1]
    Left = 0
    Top = 66
    Width = 736
    Height = 359
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
      OptionsView.CellAutoHeight = True
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      Styles.IncSearch = cxStyleIncSearch
      object Vw_tf: TcxGridColumn
        Caption = #1050#1086#1076
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
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
        Width = 49
      end
      object Vw_nm: TcxGridColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1092#1086#1088#1084#1099
        HeaderAlignmentHorz = taCenter
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
        Width = 640
      end
    end
    object Lv: TcxGridLevel
      GridView = Vw
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 736
    ExplicitWidth = 736
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
