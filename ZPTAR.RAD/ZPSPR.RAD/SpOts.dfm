inherited frSpOts: TfrSpOts
  Caption = #1054#1090#1088#1072#1089#1083#1077#1074#1099#1077' '#1089#1077#1090#1082#1080' '#1082#1074#1072#1083#1080#1092#1080#1082#1072#1094#1080#1086#1085#1085#1099#1093' '#1075#1088#1091#1087#1087
  ClientHeight = 633
  ClientWidth = 542
  ExplicitWidth = 558
  ExplicitHeight = 672
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 610
    Width = 542
    ExplicitTop = 610
    ExplicitWidth = 542
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 542
    Height = 544
    Align = alClient
    FocusOnClick = False
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxCEdkod: TcxCurrencyEdit
      Left = 14
      Top = 40
      Properties.DecimalPlaces = 0
      Properties.DisplayFormat = ',0;-,0; '
      Properties.ReadOnly = True
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      TabOrder = 0
      Width = 60
    end
    object cxTEDnm: TcxTextEdit
      Left = 77
      Top = 40
      Properties.MaxLength = 100
      Style.HotTrack = False
      TabOrder = 1
      Text = 'cxTEDnm'
      Width = 451
    end
    object cxOk: TcxButton
      Left = 245
      Top = 66
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 2
      OnClick = cxOkClick
    end
    object cxCancel: TcxButton
      Left = 388
      Top = 66
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 3
      OnClick = cxCancelClick
    end
    object cxGr: TcxGrid
      Left = 0
      Top = 108
      Width = 542
      Height = 436
      TabOrder = 4
      object Vw: TcxGridTableView
        Navigator.Buttons.CustomButtons = <>
        OnCellDblClick = VwCellDblClick
        OnCustomDrawCell = VwCustomDrawCell
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object Vw_kod: TcxGridColumn
          Caption = #1050#1086#1076
          DataBinding.ValueType = 'Word'
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.IncSearch = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          SortIndex = 0
          SortOrder = soAscending
        end
        object Vw_nm: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.IncSearch = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 285
        end
      end
      object Lv: TcxGridLevel
        GridView = Vw
      end
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
    object dxLayoutControlTop: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avTop
      CaptionOptions.Text = 'Top'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Index = 0
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutControlTop
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item2: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = #1050#1086#1076
      CaptionOptions.Layout = clTop
      Control = cxCEdkod
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 60
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      CaptionOptions.Text = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      CaptionOptions.Layout = clTop
      Control = cxTEDnm
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group1: TdxLayoutGroup
      Parent = dxLayoutControlTop
      AlignHorz = ahRight
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item4: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = cxOk
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item5: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = 'cxButton2'
      CaptionOptions.Visible = False
      Control = cxCancel
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutItem1: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGr
      ControlOptions.OriginalHeight = 200
      ControlOptions.OriginalWidth = 250
      ControlOptions.ShowBorder = False
      Index = 1
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 542
    ExplicitWidth = 542
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
    Left = 376
    Top = 416
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      Offsets.ControlOffsetHorz = 2
      Offsets.ControlOffsetVert = 2
      Offsets.ItemOffset = 2
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
  end
end
