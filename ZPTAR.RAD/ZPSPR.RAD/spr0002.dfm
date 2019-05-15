inherited frSpr0002: TfrSpr0002
  Caption = #1042#1099#1073#1086#1088' '#1082#1086#1076#1086#1074' '#1085#1072#1095#1080#1089#1083#1077#1085#1080#1103'/'#1091#1076#1077#1088#1078#1072#1085#1080#1103
  ClientHeight = 627
  ClientWidth = 488
  ExplicitWidth = 504
  ExplicitHeight = 666
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 604
    Width = 488
    ExplicitTop = 604
    ExplicitWidth = 488
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 488
    Height = 538
    Align = alClient
    Constraints.MinHeight = 300
    Constraints.MinWidth = 300
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxGr: TcxGrid
      Left = 0
      Top = 0
      Width = 488
      Height = 538
      TabOrder = 0
      object cxGrTbl: TcxGridTableView
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.Filter.Visible = True
        OnCustomDrawCell = cxGrTblCustomDrawCell
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object cxGrTblpr: TcxGridColumn
          DataBinding.ValueType = 'Boolean'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.OnEditValueChanged = cxGrTblprPropertiesEditValueChanged
          Width = 51
        end
        object cxGrTblsknu: TcxGridColumn
          Caption = #1050#1086#1076
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Width = 68
        end
        object cxGrTbln: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Width = 283
        end
        object cxGrTblkod: TcxGridColumn
          Caption = #1042#1080#1076
          Visible = False
        end
        object cxGrTblknu: TcxGridColumn
          Caption = #1050#1086#1076
          Visible = False
        end
      end
      object cxGrLv: TcxGridLevel
        GridView = cxGrTbl
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
      CaptionOptions.Text = 'cxGrid1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGr
      ControlOptions.OriginalHeight = 536
      ControlOptions.OriginalWidth = 488
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 488
    ExplicitWidth = 488
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
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
    DesignInfo = -523744
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
    Left = 80
    Top = 408
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      Offsets.ItemOffset = 3
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
  end
end
