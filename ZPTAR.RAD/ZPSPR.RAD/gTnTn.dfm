inherited frTNTN: TfrTNTN
  Caption = #1057#1086#1086#1090#1074#1077#1090#1089#1090#1074#1080#1077' '#1089#1086#1090#1088#1091#1076#1085#1080#1082#1086#1074
  ClientHeight = 570
  ClientWidth = 992
  ExplicitWidth = 1008
  ExplicitHeight = 609
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 547
    Width = 992
    ExplicitTop = 547
    ExplicitWidth = 992
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 992
    Height = 481
    Align = alClient
    FocusOnClick = False
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxGrid1: TcxGrid
      Left = 2
      Top = 223
      Width = 491
      Height = 256
      Constraints.MinWidth = 200
      TabOrder = 10
      OnEnter = cxGrid1Enter
      object cxGrid1DBTableView1: TcxGridDBTableView
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.Insert.Enabled = False
        Navigator.Buttons.Insert.Visible = False
        Navigator.Buttons.Append.Enabled = False
        Navigator.Buttons.Delete.Enabled = False
        Navigator.Buttons.Delete.Visible = False
        Navigator.Buttons.Edit.Enabled = False
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Post.Enabled = False
        Navigator.Buttons.Post.Visible = False
        Navigator.Buttons.Cancel.Enabled = False
        Navigator.Buttons.Cancel.Visible = False
        Navigator.Buttons.Refresh.Enabled = False
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Enabled = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Enabled = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Enabled = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.Visible = True
        OnCustomDrawCell = cxGrid1DBTableView1CustomDrawCell
        OnFocusedRecordChanged = cxGrid1DBTableView1FocusedRecordChanged
        DataController.DataSource = dsRTNO
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.ImmediateEditor = False
        OptionsCustomize.ColumnFiltering = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.CellAutoHeight = True
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object cxGrid1DBTableView1glavn: TcxGridDBColumn
          DataBinding.FieldName = 'glavn'
          Visible = False
        end
        object cxGrid1DBTableView1o_glavn: TcxGridDBColumn
          DataBinding.FieldName = 'o_glavn'
          Visible = False
        end
        object cxGrid1DBTableView1u_glavn: TcxGridDBColumn
          DataBinding.FieldName = 'u_glavn'
          Visible = False
        end
        object cxGrid1DBTableView1tn_glavn: TcxGridDBColumn
          Caption = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
          DataBinding.FieldName = 'tn_glavn'
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
          Width = 90
        end
        object cxGrid1DBTableView1nm_glavn: TcxGridDBColumn
          Caption = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
          DataBinding.FieldName = 'nm_glavn'
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
          SortIndex = 0
          SortOrder = soAscending
          Width = 200
        end
        object cxGrid1DBTableView1nmu_glav: TcxGridDBColumn
          Caption = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
          DataBinding.FieldName = 'nmu_glav'
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Width = 200
        end
        object cxGrid1DBTableView1nmo_glav: TcxGridDBColumn
          Caption = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
          DataBinding.FieldName = 'nmo_glav'
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
          Width = 200
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
    object cxGrid2: TcxGrid
      Left = 500
      Top = 223
      Width = 490
      Height = 256
      TabOrder = 11
      object cxGrid2DBTableView1: TcxGridDBTableView
        OnMouseWheel = cxGrid2DBTableView1MouseWheel
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.Prior.Visible = True
        Navigator.Buttons.Insert.Enabled = False
        Navigator.Buttons.Insert.Visible = False
        Navigator.Buttons.Append.Enabled = False
        Navigator.Buttons.Delete.Enabled = False
        Navigator.Buttons.Delete.Visible = False
        Navigator.Buttons.Edit.Enabled = False
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Post.Enabled = False
        Navigator.Buttons.Post.Visible = False
        Navigator.Buttons.Cancel.Enabled = False
        Navigator.Buttons.Cancel.Visible = False
        Navigator.Buttons.Refresh.Enabled = False
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Enabled = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Enabled = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Enabled = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.Visible = True
        FilterBox.Visible = fvNever
        OnCustomDrawCell = cxGrid1DBTableView1CustomDrawCell
        DataController.DataSource = dsRTNS
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.CopyCaptionsToClipboard = False
        OptionsBehavior.IncSearch = True
        OptionsBehavior.CopyPreviewToClipboard = False
        OptionsBehavior.ImmediateEditor = False
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
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
        object cxGrid2DBTableView1glavn: TcxGridDBColumn
          DataBinding.FieldName = 'glavn'
          Visible = False
        end
        object cxGrid2DBTableView1vspom: TcxGridDBColumn
          DataBinding.FieldName = 'vspom'
          Visible = False
        end
        object cxGrid2DBTableView1o_vspom: TcxGridDBColumn
          DataBinding.FieldName = 'o_vspom'
          Visible = False
        end
        object cxGrid2DBTableView1u_vspom: TcxGridDBColumn
          DataBinding.FieldName = 'u_vspom'
          Visible = False
        end
        object cxGrid2DBTableView1tn_vspom: TcxGridDBColumn
          Caption = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
          DataBinding.FieldName = 'tn_vspom'
          HeaderAlignmentHorz = taCenter
          Width = 90
        end
        object cxGrid2DBTableView1nm_vspom: TcxGridDBColumn
          Caption = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
          DataBinding.FieldName = 'nm_vspom'
          HeaderAlignmentHorz = taCenter
          SortIndex = 0
          SortOrder = soAscending
          Width = 200
        end
        object cxGrid2DBTableView1nmu_vspo: TcxGridDBColumn
          Caption = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
          DataBinding.FieldName = 'nmu_vspo'
          HeaderAlignmentHorz = taCenter
          Width = 200
        end
        object cxGrid2DBTableView1nmo_vspo: TcxGridDBColumn
          Caption = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
          DataBinding.FieldName = 'nmo_vspo'
          HeaderAlignmentHorz = taCenter
          Width = 200
        end
      end
      object cxGrid2Level1: TcxGridLevel
        GridView = cxGrid2DBTableView1
      end
    end
    object cxBTotn: TcxButtonEdit
      Left = 16
      Top = 45
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.ViewStyle = vsHideCursor
      Properties.OnButtonClick = cxBTotnPropertiesButtonClick
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 0
      Text = 'cxBTotn'
      OnKeyDown = cxBTotnKeyDown
      Width = 120
    end
    object cxBTo_fio: TcxButtonEdit
      Left = 139
      Top = 45
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.ViewStyle = vsHideCursor
      Properties.OnButtonClick = cxBTotnPropertiesButtonClick
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 1
      Text = 'cxBTofio'
      OnKeyDown = cxBTotnKeyDown
      Width = 250
    end
    object cxTEDu_glavn: TcxTextEdit
      Left = 481
      Top = 23
      Properties.ReadOnly = True
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 2
      Text = 'cxTEDu_glavn'
      Width = 495
    end
    object cxTEDo_glavn: TcxTextEdit
      Left = 481
      Top = 49
      Properties.ReadOnly = True
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 3
      Text = 'cxTEDo_glavn'
      Width = 495
    end
    object cxBTstn: TcxButtonEdit
      Left = 16
      Top = 132
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.ViewStyle = vsHideCursor
      Properties.OnButtonClick = cxBTstnPropertiesButtonClick
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      TabOrder = 4
      Text = 'cxBTstn'
      OnKeyDown = cxBTotnKeyDown
      Width = 120
    end
    object cxBTs_fio: TcxButtonEdit
      Left = 139
      Top = 132
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 32
      Properties.ReadOnly = True
      Properties.ViewStyle = vsHideCursor
      Properties.OnButtonClick = cxBTstnPropertiesButtonClick
      Style.Color = clMoneyGreen
      Style.HotTrack = False
      TabOrder = 5
      Text = 'cxBTs_fio'
      OnKeyDown = cxBTotnKeyDown
      Width = 250
    end
    object cxTEDu_vspom: TcxTextEdit
      Left = 481
      Top = 110
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 6
      Text = 'cxTEDu_vspom'
      Width = 495
    end
    object cxTEDo_vspom: TcxTextEdit
      Left = 481
      Top = 136
      Style.HotTrack = False
      StyleDisabled.Color = 4707838
      StyleDisabled.TextColor = clBlack
      TabOrder = 7
      Text = 'cxTEDo_vspom'
      Width = 495
    end
    object cxOk: TcxButton
      Left = 685
      Top = 176
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 8
      OnClick = cxOkClick
    end
    object cxCancel: TcxButton
      Left = 850
      Top = 176
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      TabOrder = 9
      OnClick = cxCancelClick
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
    object dxLayoutControl1Group1: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Group3: TdxLayoutGroup
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = #1054#1089#1085#1086#1074#1085#1086#1081' '#1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      Index = 0
    end
    object dxLayoutControl1Group7: TdxLayoutGroup
      Parent = dxLayoutControl1Group3
      AlignVert = avCenter
      CaptionOptions.Text = '1'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = dxLayoutControl1Group7
      CaptionOptions.Text = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      CaptionOptions.Layout = clTop
      Control = cxBTotn
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 120
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item5: TdxLayoutItem
      Parent = dxLayoutControl1Group7
      CaptionOptions.Text = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
      CaptionOptions.Layout = clTop
      Control = cxBTo_fio
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 250
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group5: TdxLayoutGroup
      Parent = dxLayoutControl1Group3
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item4: TdxLayoutItem
      Parent = dxLayoutControl1Group5
      CaptionOptions.Text = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
      Control = cxTEDu_glavn
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item6: TdxLayoutItem
      Parent = dxLayoutControl1Group5
      CaptionOptions.AlignHorz = taCenter
      CaptionOptions.Text = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
      Control = cxTEDo_glavn
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group4: TdxLayoutGroup
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = #1042#1089#1087#1086#1084#1086#1075#1072#1090#1077#1083#1100#1085#1099#1081' '#1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      Index = 1
    end
    object dxLayoutControl1Group6: TdxLayoutGroup
      Parent = dxLayoutControl1Group4
      AlignHorz = ahLeft
      AlignVert = avCenter
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item7: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      CaptionOptions.Text = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      CaptionOptions.Layout = clTop
      Control = cxBTstn
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 120
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item8: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      CaptionOptions.Text = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
      CaptionOptions.Layout = clTop
      Control = cxBTs_fio
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 250
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group8: TdxLayoutGroup
      Parent = dxLayoutControl1Group4
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item9: TdxLayoutItem
      Parent = dxLayoutControl1Group8
      CaptionOptions.Text = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
      Control = cxTEDu_vspom
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item10: TdxLayoutItem
      Parent = dxLayoutControl1Group8
      CaptionOptions.AlignHorz = taCenter
      CaptionOptions.Text = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
      Control = cxTEDo_vspom
      ControlOptions.OriginalHeight = 21
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group9: TdxLayoutGroup
      Parent = dxLayoutControl1Group1
      AlignHorz = ahRight
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item11: TdxLayoutItem
      Parent = dxLayoutControl1Group9
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = cxOk
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item12: TdxLayoutItem
      Parent = dxLayoutControl1Group9
      CaptionOptions.Text = '      '
      Control = cxCancel
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignVert = avClient
      CaptionOptions.Text = #1057#1082#1088#1099#1090#1072#1103' '#1075#1088#1091#1087#1087#1072
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item1: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.AlignHorz = taCenter
      CaptionOptions.Text = #1054#1089#1085#1086#1074#1085#1086#1081' '#1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      CaptionOptions.Layout = clTop
      Control = cxGrid1
      ControlOptions.MinWidth = 200
      ControlOptions.OriginalHeight = 407
      ControlOptions.OriginalWidth = 492
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item2: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.AlignHorz = taCenter
      CaptionOptions.Text = #1042#1089#1087#1086#1084#1086#1075#1072#1090#1077#1083#1100#1085#1099#1081' '#1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
      CaptionOptions.Layout = clTop
      Control = cxGrid2
      ControlOptions.OriginalHeight = 407
      ControlOptions.OriginalWidth = 492
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutSplitterItem1: TdxLayoutSplitterItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = #1055#1086#1076#1074#1080#1078#1085#1099#1081' '#1088#1072#1079#1076#1077#1083#1080#1090#1077#1083#1100
      SizeOptions.AssignedValues = [sovSizableHorz, sovSizableVert]
      SizeOptions.SizableHorz = False
      SizeOptions.SizableVert = False
      Index = 1
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 992
    ExplicitWidth = 992
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
  object fdsRTNO: TFamDataSet
    Base = DMXE10.FbWrk
    FileName = 'RTNO'
    Left = 56
    Top = 344
    object fdsRTNOglavn: TWordField
      FieldName = 'glavn'
      Required = True
    end
    object fdsRTNOo_glavn: TWordField
      FieldName = 'o_glavn'
    end
    object fdsRTNOu_glavn: TWordField
      FieldName = 'u_glavn'
    end
    object fdsRTNOtn_glavn: TIntegerField
      FieldName = 'tn_glavn'
    end
    object fdsRTNOnm_glavn: TStringField
      FieldName = 'nm_glavn'
      Size = 40
    end
    object fdsRTNOnmo_glav: TStringField
      FieldName = 'nmo_glav'
      Size = 40
    end
    object fdsRTNOnmu_glav: TStringField
      FieldName = 'nmu_glav'
      Size = 40
    end
  end
  object dsRTNO: TDataSource
    DataSet = fdsRTNO
    Left = 128
    Top = 344
  end
  object dsRTNS: TDataSource
    DataSet = fdsRTNS
    Left = 600
    Top = 344
  end
  object fdsRTNS: TFamDataSet
    Base = DMXE10.FbWrk
    FileName = 'RTNS'
    Left = 560
    Top = 344
    object fdsRTNSglavn: TWordField
      FieldName = 'glavn'
      Required = True
    end
    object fdsRTNSvspom: TWordField
      FieldName = 'vspom'
      Required = True
    end
    object fdsRTNSo_vspom: TWordField
      FieldName = 'o_vspom'
    end
    object fdsRTNSu_vspom: TWordField
      FieldName = 'u_vspom'
    end
    object fdsRTNStn_vspom: TIntegerField
      FieldName = 'tn_vspom'
    end
    object fdsRTNSnm_vspom: TStringField
      FieldName = 'nm_vspom'
      Size = 40
    end
    object fdsRTNSnmo_vspo: TStringField
      FieldName = 'nmo_vspo'
      Size = 40
    end
    object fdsRTNSnmu_vspo: TStringField
      FieldName = 'nmu_vspo'
      Size = 40
    end
  end
  object dxLayoutLookAndFeelList1: TdxLayoutLookAndFeelList
    Left = 536
    Top = 424
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ControlOffsetHorz = 2
      Offsets.ControlOffsetVert = 2
      Offsets.ItemOffset = 2
      Offsets.RootItemsAreaOffsetHorz = 1
      Offsets.RootItemsAreaOffsetVert = 1
      PixelsPerInch = 96
    end
  end
  object ActionList1: TActionList
    Left = 320
    Top = 480
    object aDopI: TAction
      Caption = 'aDopI'
      OnExecute = aDopIExecute
    end
    object aDopC: TAction
      Caption = 'aDopC'
      OnExecute = aDopCExecute
    end
  end
end
