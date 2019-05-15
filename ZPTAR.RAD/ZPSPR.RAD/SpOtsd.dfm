inherited frSpOtsd: TfrSpOtsd
  Caption = #1054#1090#1088#1072#1089#1083#1077#1074#1099#1077' '#1089#1077#1090#1082#1080
  ClientHeight = 698
  ClientWidth = 824
  ExplicitWidth = 840
  ExplicitHeight = 737
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 675
    Width = 824
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end>
    ExplicitTop = 675
    ExplicitWidth = 824
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 824
    Height = 609
    Align = alClient
    FocusOnClick = False
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxDate: TcxDateEdit
      Left = 30
      Top = 2
      Properties.DisplayFormat = 'mm.yyyy'
      Properties.EditFormat = 'mm.yyyy'
      Properties.OnEditValueChanged = cxDatePropertiesEditValueChanged
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      TabOrder = 0
      OnEditing = cxDateEditing
      OnEnter = cxDateEnter
      OnKeyDown = cxDateKeyDown
      Width = 120
    end
    object cxBtEdOTS: TcxButtonEdit
      Left = 253
      Top = 28
      Properties.AutoSelect = False
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.UseLeftAlignmentOnEditing = False
      Properties.ViewStyle = vsHideCursor
      Properties.OnButtonClick = cxButtonEdit1PropertiesButtonClick
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      TabOrder = 1
      OnEnter = cxBtEdOTSEnter
      OnKeyDown = cxBtEdOTSKeyDown
      Width = 569
    end
    object cxTEDnm: TcxTextEdit
      Left = 108
      Top = 101
      Style.HotTrack = False
      TabOrder = 4
      Text = 'cxTEDnm'
      Width = 702
    end
    object cxMaskEdFR: TcxMaskEdit
      Left = 108
      Top = 75
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      TabOrder = 2
      Width = 121
    end
    object cxMaskEDfrnew: TcxMaskEdit
      Left = 342
      Top = 75
      Properties.Alignment.Horz = taLeftJustify
      Properties.MaskKind = emkRegExprEx
      Properties.EditMask = '\d\d'
      Properties.MaxLength = 0
      Style.HotTrack = False
      TabOrder = 3
      Width = 60
    end
    object cxCEDkf: TcxCurrencyEdit
      Left = 108
      Top = 153
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = ',0.00;-,0.00'
      Properties.UseDisplayFormatWhenEditing = True
      Style.HotTrack = False
      TabOrder = 6
      Width = 702
    end
    object cxCEDsum: TcxCurrencyEdit
      Left = 108
      Top = 127
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = ',0.00;-,0.00'
      Style.HotTrack = False
      TabOrder = 5
      Width = 702
    end
    object cxCEDsumkf: TcxCalcEdit
      Left = 108
      Top = 179
      EditValue = 0.000000000000000000
      Properties.DisplayFormat = ',0.00;-,0.00'
      Style.HotTrack = False
      TabOrder = 7
      Width = 702
    end
    object cxOk: TcxButton
      Left = 527
      Top = 205
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 8
      OnClick = cxOkClick
    end
    object cxCancel: TcxButton
      Left = 670
      Top = 205
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 9
      OnClick = cxCancelClick
    end
    object cxGr: TcxGrid
      Left = 0
      Top = 247
      Width = 824
      Height = 362
      TabOrder = 10
      OnEnter = cxGrEnter
      OnExit = cxGrExit
      object Vw: TcxGridTableView
        OnDblClick = VwDblClick
        OnKeyDown = VwKeyDown
        Navigator.Buttons.CustomButtons = <>
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
        OptionsView.CellAutoHeight = True
        OptionsView.GroupByBox = False
        OptionsView.HeaderAutoHeight = True
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object Vw_kod: TcxGridColumn
          Caption = #1043#1088#1091#1087#1087#1072
          DataBinding.ValueType = 'Word'
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 30
        end
        object Vw_kodst: TcxGridColumn
          Caption = #1059#1053#1044
          DataBinding.ValueType = 'Word'
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
        end
        object Vw_fr: TcxGridColumn
          Caption = #1050#1086#1076
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 109
        end
        object Vw_nm: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 300
        end
        object Vw_sum: TcxGridColumn
          Caption = #1057#1091#1084#1084#1072
          DataBinding.ValueType = 'Currency'
          PropertiesClassName = 'TcxCurrencyEditProperties'
          Properties.DecimalPlaces = 2
          Properties.DisplayFormat = ',0.00;-,0.00; '
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 120
        end
        object Vw_kf: TcxGridColumn
          Caption = #1050#1060
          DataBinding.ValueType = 'Currency'
          PropertiesClassName = 'TcxCurrencyEditProperties'
          Properties.DecimalPlaces = 2
          Properties.DisplayFormat = ',0.00;-,0.00; '
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 60
        end
        object Vw_sumkf: TcxGridColumn
          Caption = #1048#1090#1086#1075#1086#1074#1072#1103' '#1089#1091#1084#1084#1072
          DataBinding.ValueType = 'Currency'
          PropertiesClassName = 'TcxCurrencyEditProperties'
          Properties.DecimalPlaces = 2
          Properties.DisplayFormat = ',0.00;-,0.00; '
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringAddValueItems = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 120
        end
        object Vw_it: TcxGridColumn
          DataBinding.ValueType = 'Word'
          Visible = False
          VisibleForCustomization = False
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
    object dxLayoutControlDate: TdxLayoutItem
      Parent = dxLayoutAutoCreatedGroup1
      AlignHorz = ahLeft
      CaptionOptions.Text = #1044#1072#1090#1072
      Offsets.Left = 1
      Offsets.Top = 2
      Control = cxDate
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 120
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControlSp: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = #1054#1090#1088#1072#1089#1083#1077#1074#1099#1077' '#1089#1077#1090#1082#1080' '#1082#1074#1072#1083#1080#1092#1080#1082#1072#1094#1080#1086#1085#1085#1099#1093' '#1075#1088#1091#1087#1087
      Offsets.Left = 2
      Offsets.Right = 2
      Control = cxBtEdOTS
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutED: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Index = 2
    end
    object dxLayoutControl1Group3: TdxLayoutGroup
      Parent = dxLayoutED
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControlFR: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = #1050#1086#1076' '#1091#1088#1086#1074#1085#1103
      Control = cxMaskEdFR
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControlFRNEW: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = #1042#1074#1086#1076#1080#1084#1099#1081' '#1091#1088#1086#1074#1077#1085#1100
      Control = cxMaskEDfrnew
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 60
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item1: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      Control = cxTEDnm
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControlSUM: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = #1057#1091#1084#1084#1072
      Control = cxCEDsum
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutControlKF: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090
      Control = cxCEDkf
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object dxLayoutControlSUMKF: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = #1057#1091#1084#1084#1072' '#1080#1090#1086#1075#1086#1074#1072#1103
      Control = cxCEDsumkf
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutED
      AlignHorz = ahRight
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 5
    end
    object dxLayoutControl1Item8: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = cxOk
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item9: TdxLayoutItem
      Parent = dxLayoutControl1Group2
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
      Index = 3
    end
    object dxLayoutSplitterItem1: TdxLayoutSplitterItem
      Parent = dxLayoutAutoCreatedGroup1
      CaptionOptions.Text = 'Splitter'
      SizeOptions.AssignedValues = [sovSizableHorz, sovSizableVert]
      SizeOptions.SizableHorz = False
      SizeOptions.SizableVert = False
      Index = 1
    end
    object dxLayoutAutoCreatedGroup1: TdxLayoutAutoCreatedGroup
      Parent = dxLayoutControl1Group_Root
      LayoutDirection = ldHorizontal
      Index = 0
      AutoCreated = True
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 824
    ExplicitWidth = 824
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
    DesignInfo = 1573200
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
    Left = 712
    Top = 24
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ControlOffsetHorz = 2
      Offsets.ControlOffsetVert = 2
      Offsets.ItemOffset = 2
      Offsets.RootItemsAreaOffsetHorz = 0
      Offsets.RootItemsAreaOffsetVert = 0
      PixelsPerInch = 96
    end
  end
end
