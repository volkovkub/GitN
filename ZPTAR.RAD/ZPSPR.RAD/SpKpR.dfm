inherited fraspr2: Tfraspr2
  Caption = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077'/'#1057#1086#1090#1088#1091#1076#1085#1080#1082
  ClientHeight = 727
  ClientWidth = 1094
  OnShow = FormShow
  ExplicitWidth = 1110
  ExplicitHeight = 766
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 704
    Width = 1094
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        Width = 100
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        Width = 100
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end>
    ExplicitTop = 704
    ExplicitWidth = 1094
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 1094
    Height = 638
    Align = alClient
    FocusOnClick = False
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    OptionsItem.AutoControlTabOrders = False
    object cxGrid: TcxGrid
      Left = 490
      Top = 356
      Width = 601
      Height = 279
      TabOrder = 13
      TabStop = False
      OnEnter = cxGridEnter
      OnExit = cxGridExit
      object VwKDKP: TcxGridDBTableView
        Tag = 2
        OnDblClick = VwKDKPDblClick
        OnKeyDown = VwKDKPKeyDown
        OnMouseWheel = VwKDKPMouseWheel
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
        FilterBox.CustomizeDialog = False
        FilterBox.Visible = fvNever
        OnCustomDrawCell = VwKDKPuwCustomDrawCell
        DataController.DataModeController.SmartRefresh = True
        DataController.DataSource = tbKDRKPN
        DataController.KeyFieldNames = 'kdkp'
        DataController.Options = [dcoAnsiSort]
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        Filtering.ColumnMRUItemsList = False
        FilterRow.InfoText = #1060#1080#1083#1100#1090#1088
        FilterRow.SeparatorWidth = 10
        OptionsBehavior.DragOpening = False
        OptionsBehavior.DragScrolling = False
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.ExpandMasterRowOnDblClick = False
        OptionsBehavior.ImmediateEditor = False
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnHidingOnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object VwKDKPuw: TcxGridDBColumn
          DataBinding.FieldName = 'uw'
          PropertiesClassName = 'TcxImageComboBoxProperties'
          Properties.Images = cxImageList4
          Properties.Items = <
            item
              ImageIndex = 0
              Value = 0
            end
            item
              ImageIndex = 1
              Value = 1
            end
            item
              ImageIndex = 2
              Value = 2
            end>
          Properties.ReadOnly = True
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          MinWidth = 30
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.ShowCaption = False
          SortIndex = 0
          SortOrder = soAscending
          Width = 30
        end
        object VwKDKPkdkp: TcxGridDBColumn
          DataBinding.FieldName = 'kdkp'
          Visible = False
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
        end
        object VwKDKPowner: TcxGridDBColumn
          DataBinding.FieldName = 'owner'
          Visible = False
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
        end
        object VwKDKPsname: TcxGridDBColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' ('#1082#1088#1072#1090#1082#1086#1077')'
          DataBinding.FieldName = 'sname'
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          MinWidth = 200
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          SortIndex = 1
          SortOrder = soAscending
          Width = 290
        end
        object VwKDKPdeptup: TcxGridDBColumn
          DataBinding.FieldName = 'deptup'
          PropertiesClassName = 'TcxImageComboBoxProperties'
          Properties.Images = cxImageList2
          Properties.Items = <
            item
              ImageIndex = 0
              Value = 0
            end
            item
              Description = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
              ImageIndex = 1
              Value = 1
            end
            item
              Description = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
              ImageIndex = 2
              Value = 2
            end>
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.ShowCaption = False
          Options.Sorting = False
          Width = 114
        end
        object VwKDKPtn: TcxGridDBColumn
          Caption = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
          DataBinding.FieldName = 'tn'
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          Width = 90
        end
        object VwKDKPfname: TcxGridDBColumn
          DataBinding.FieldName = 'fname'
          Visible = False
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
        end
        object VwKDKPkdnm: TcxGridDBColumn
          Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100
          DataBinding.FieldName = 'kdnm'
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          MinWidth = 200
          Options.Editing = False
          Options.Filtering = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
        end
        object VwKDKPfdp: TcxGridDBColumn
          Caption = #1055#1088#1080#1085#1103#1090
          DataBinding.FieldName = 'fdp'
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
        end
        object VwKDKPfdu: TcxGridDBColumn
          Caption = #1059#1074#1086#1083#1077#1085
          DataBinding.FieldName = 'fdu'
          OnCustomDrawCell = VwKDKPuwCustomDrawCell
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
        end
        object VwKDKPknp: TcxGridDBColumn
          DataBinding.FieldName = 'knp'
          Visible = False
        end
      end
      object cxGridLevel1: TcxGridLevel
        GridView = VwKDKP
      end
    end
    object cxOwnerNm: TcxTextEdit
      Left = 3
      Top = 298
      TabStop = False
      Enabled = False
      Properties.ReadOnly = False
      Style.Color = clBlack
      Style.HotTrack = False
      Style.Shadow = True
      StyleDisabled.BorderColor = 10501385
      StyleDisabled.BorderStyle = ebsSingle
      StyleDisabled.Color = clBlack
      StyleDisabled.TextColor = 4707838
      TabOrder = 0
      Width = 1088
    end
    object cxDBTextEdit1: TcxDBTextEdit
      Left = 490
      Top = 327
      TabStop = False
      DataBinding.DataField = 'fname'
      DataBinding.DataSource = tbKDRKPN
      Enabled = False
      Style.Color = clBlack
      Style.HotTrack = False
      Style.Shadow = True
      Style.TextColor = clBlack
      Style.TextStyle = []
      StyleDisabled.BorderColor = 10501385
      StyleDisabled.BorderStyle = ebsSingle
      StyleDisabled.Color = clBlack
      StyleDisabled.TextColor = 4707838
      StyleDisabled.TextStyle = []
      TabOrder = 15
      Width = 601
    end
    object edNameFind: TcxTextEdit
      Left = 349
      Top = 132
      Properties.CharCase = ecUpperCase
      Style.HotTrack = False
      TabOrder = 9
      Width = 235
    end
    object edFamFind: TcxTextEdit
      Left = 72
      Top = 132
      Properties.CharCase = ecUpperCase
      Style.HotTrack = False
      TabOrder = 8
      Width = 246
    end
    object edOtchFind: TcxTextEdit
      Left = 642
      Top = 132
      Properties.CharCase = ecUpperCase
      Style.HotTrack = False
      TabOrder = 10
      Width = 200
    end
    object edTNFind: TcxMaskEdit
      Left = 865
      Top = 132
      Properties.CharCase = ecUpperCase
      Properties.MaskKind = emkRegExprEx
      Properties.EditMask = '\d+'
      Properties.MaxLength = 0
      Style.HotTrack = False
      TabOrder = 11
      Width = 134
    end
    object bnFind: TcxButton
      Left = 1002
      Top = 132
      Width = 75
      Height = 25
      Caption = #1048#1089#1082#1072#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 14
      OnClick = bnFindClick
    end
    object grFind: TcxGrid
      Left = 17
      Top = 160
      Width = 1060
      Height = 98
      TabOrder = 12
      TabStop = False
      object tvFind: TcxGridTableView
        Navigator.Buttons.CustomButtons = <>
        OnCellDblClick = tvFindCellDblClick
        OnCustomDrawCell = tvFindCustomDrawCell
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.CellSelect = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        Styles.IncSearch = cxStyleIncSearch
        object tvFindTN: TcxGridColumn
          Caption = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#8470
          DataBinding.ValueType = 'Integer'
          Width = 98
        end
        object tvFindFIO: TcxGridColumn
          Caption = #1060#1048#1054
          Width = 409
        end
        object tvFindOwner: TcxGridColumn
          Caption = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
          Width = 488
        end
        object tvFindKP: TcxGridColumn
          DataBinding.ValueType = 'Integer'
          Visible = False
        end
        object tvFindOw: TcxGridColumn
          DataBinding.ValueType = 'Integer'
          Visible = False
        end
      end
      object grFindLevel1: TcxGridLevel
        GridView = tvFind
      end
    end
    object pbFind: TcxProgressBar
      Left = 17
      Top = 261
      TabStop = False
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -9
      Style.Font.Name = 'Courier New'
      Style.Font.Style = []
      Style.LookAndFeel.NativeStyle = True
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 16
      Width = 1060
    end
    object edFam: TcxTextEdit
      Left = 17
      Top = 43
      Properties.CharCase = ecUpperCase
      Properties.OnChange = edOtchPropertiesChange
      Style.HotTrack = False
      TabOrder = 1
      Width = 193
    end
    object edName: TcxTextEdit
      Left = 213
      Top = 43
      Properties.CharCase = ecUpperCase
      Properties.OnChange = edOtchPropertiesChange
      Style.HotTrack = False
      TabOrder = 2
      Width = 244
    end
    object edOtch: TcxTextEdit
      Left = 460
      Top = 43
      Properties.CharCase = ecUpperCase
      Properties.OnChange = edOtchPropertiesChange
      Style.HotTrack = False
      TabOrder = 3
      Width = 228
    end
    object edFIO: TcxTextEdit
      Left = 691
      Top = 43
      Properties.CharCase = ecUpperCase
      Style.HotTrack = False
      TabOrder = 4
      Width = 260
    end
    object bnSaveFIO: TcxButton
      Left = 211
      Top = 69
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 6
      OnClick = bnSaveFIOClick
    end
    object bnCancelFIO: TcxButton
      Left = 743
      Top = 69
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
      LookAndFeel.NativeStyle = False
      TabOrder = 7
      OnClick = bnCancelFIOClick
    end
    object edTn: TcxMaskEdit
      Left = 954
      Top = 43
      Properties.MaskKind = emkRegExpr
      Properties.EditMask = '\d+'
      Properties.MaxLength = 0
      Style.HotTrack = False
      StyleDisabled.Color = 8310261
      StyleDisabled.TextColor = clBlack
      TabOrder = 5
      Width = 123
    end
    object cxGrid1: TcxGrid
      Left = 3
      Top = 327
      Width = 480
      Height = 308
      TabOrder = 17
      OnEnter = cxGrid1Enter
      LookAndFeel.Kind = lfUltraFlat
      LookAndFeel.NativeStyle = False
      object cxGrid1DBTableView1: TcxGridDBTableView
        Tag = 1
        OnDblClick = cxGrid1DBTableView1DblClick
        OnKeyDown = cxGrid1DBTableView1KeyDown
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.Insert.Enabled = False
        Navigator.Buttons.Insert.Visible = False
        Navigator.Buttons.Append.Enabled = False
        Navigator.Buttons.Delete.Enabled = False
        Navigator.Buttons.Delete.Visible = False
        Navigator.Buttons.Edit.Enabled = False
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Post.Visible = False
        Navigator.Buttons.Cancel.Enabled = False
        Navigator.Buttons.Cancel.Visible = False
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Enabled = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Enabled = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.Visible = True
        DataController.DataModeController.GridMode = True
        DataController.DataSource = tbRKPNM
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnHidingOnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsCustomize.ColumnSorting = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object cxGrid1DBTableView1kdkp: TcxGridDBColumn
          DataBinding.FieldName = 'kdkp'
          Visible = False
        end
        object cxGrid1DBTableView1owner: TcxGridDBColumn
          DataBinding.FieldName = 'owner'
          Visible = False
        end
        object cxGrid1DBTableView1tn: TcxGridDBColumn
          DataBinding.FieldName = 'tn'
          Visible = False
        end
        object cxGrid1DBTableView1sname: TcxGridDBColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077'('#1082#1088#1072#1090#1082#1086#1077')'
          DataBinding.FieldName = 'sname'
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
          Width = 300
        end
        object cxGrid1DBTableView1deptup: TcxGridDBColumn
          DataBinding.FieldName = 'deptup'
          PropertiesClassName = 'TcxImageComboBoxProperties'
          Properties.Images = cxImageList2
          Properties.Items = <
            item
              ImageIndex = 0
              Value = 0
            end
            item
              Description = #1059#1095#1088#1077#1078#1076#1077#1085#1080#1077
              ImageIndex = 1
              Value = 1
            end
            item
              Description = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077
              ImageIndex = 2
              Value = 2
            end>
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.ShowCaption = False
          Width = 130
        end
        object cxGrid1DBTableView1fname: TcxGridDBColumn
          DataBinding.FieldName = 'fname'
          Visible = False
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
    object dxLayoutControl1Group_Root: TdxLayoutGroup
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = -1
    end
    object lgEdFIO: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avTop
      CaptionOptions.Text = #1050#1086#1088#1088#1077#1082#1090#1080#1088#1086#1074#1082#1072
      Visible = False
      ButtonOptions.Buttons = <>
      Index = 0
    end
    object dxLayoutControl1Group1: TdxLayoutGroup
      Parent = lgEdFIO
      CaptionOptions.Text = #1057#1082#1088#1099#1090#1072#1103' '#1075#1088#1091#1087#1087#1072
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item11: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      AlignHorz = ahClient
      CaptionOptions.Text = #1060#1072#1084#1080#1083#1080#1103
      CaptionOptions.Layout = clTop
      Control = edFam
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 127
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item12: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      AlignHorz = ahClient
      CaptionOptions.Text = #1048#1084#1103
      CaptionOptions.Layout = clTop
      Control = edName
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 161
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item13: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      AlignHorz = ahClient
      CaptionOptions.Text = #1054#1095#1077#1089#1090#1074#1086
      CaptionOptions.Layout = clTop
      Control = edOtch
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 150
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Group9: TdxLayoutGroup
      Parent = dxLayoutControl1Group1
      CaptionOptions.Text = #1057#1082#1088#1099#1090#1072#1103' '#1075#1088#1091#1087#1087#1072
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 3
    end
    object dxLayoutControl1Item14: TdxLayoutItem
      Parent = dxLayoutControl1Group9
      AlignHorz = ahClient
      CaptionOptions.Text = #1050#1088#1072#1090#1082#1086#1077' '#1060#1048#1054
      CaptionOptions.Layout = clTop
      Control = edFIO
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 260
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item17: TdxLayoutItem
      Parent = dxLayoutControl1Group9
      AlignVert = avTop
      CaptionOptions.Text = #1058#1072#1073#1077#1083#1100#1085#1099#1081' '#1085#1086#1084#1077#1088
      CaptionOptions.Layout = clTop
      Control = edTn
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 123
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group5: TdxLayoutGroup
      Parent = lgEdFIO
      CaptionOptions.Text = #1057#1082#1088#1099#1090#1072#1103' '#1075#1088#1091#1087#1087#1072
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group7: TdxLayoutGroup
      Parent = dxLayoutControl1Group5
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item15: TdxLayoutItem
      Parent = dxLayoutControl1Group7
      AlignHorz = ahCenter
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = bnSaveFIO
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Group8: TdxLayoutGroup
      Parent = dxLayoutControl1Group5
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item16: TdxLayoutItem
      Parent = dxLayoutControl1Group8
      AlignHorz = ahCenter
      CaptionOptions.Text = 'cxButton2'
      CaptionOptions.Visible = False
      Control = bnCancelFIO
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object cgFind: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = #1055#1086#1080#1089#1082
      Visible = False
      ButtonOptions.Buttons = <>
      Index = 1
    end
    object dxLayoutControl1Group6: TdxLayoutGroup
      Parent = cgFind
      CaptionOptions.Text = #1057#1082#1088#1099#1090#1072#1103' '#1075#1088#1091#1087#1087#1072
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item5: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahClient
      CaptionOptions.Text = #1060#1072#1084#1080#1083#1080#1103
      Control = edFamFind
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 153
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item1: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahClient
      CaptionOptions.Text = #1048#1084#1103
      Control = edNameFind
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 154
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item6: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahClient
      CaptionOptions.Text = #1054#1090#1095#1077#1089#1090#1074#1086
      Control = edOtchFind
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item7: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahRight
      CaptionOptions.Text = #1058#1053
      Control = edTNFind
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 134
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object dxLayoutControl1Item8: TdxLayoutItem
      Parent = dxLayoutControl1Group6
      AlignHorz = ahRight
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = bnFind
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object dxLayoutControl1Item9: TdxLayoutItem
      Parent = cgFind
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid2'
      CaptionOptions.Visible = False
      Control = grFind
      ControlOptions.OriginalHeight = 118
      ControlOptions.OriginalWidth = 998
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item10: TdxLayoutItem
      Parent = cgFind
      AlignVert = avBottom
      CaptionOptions.Text = 'cxProgressBar1'
      CaptionOptions.Visible = False
      Control = pbFind
      ControlOptions.OriginalHeight = 20
      ControlOptions.OriginalWidth = 998
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object lcSpr: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = lcSpr
      AlignHorz = ahClient
      AlignVert = avTop
      CaptionOptions.Text = 'cxTextEdit1'
      CaptionOptions.Visible = False
      Control = cxOwnerNm
      ControlOptions.OriginalHeight = 26
      ControlOptions.OriginalWidth = 992
      ControlOptions.ShowBorder = False
      Enabled = False
      Index = 0
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = lcSpr
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group4: TdxLayoutGroup
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item4: TdxLayoutItem
      Parent = dxLayoutControl1Group4
      AlignHorz = ahClient
      CaptionOptions.Text = 'cxDBTextEdit1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxDBTextEdit1
      ControlOptions.OriginalHeight = 26
      ControlOptions.OriginalWidth = 489
      ControlOptions.ShowBorder = False
      Enabled = False
      Index = 0
    end
    object dxLayoutControl1Item2: TdxLayoutItem
      Parent = dxLayoutControl1Group4
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid2'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGrid
      ControlOptions.OriginalHeight = 200
      ControlOptions.OriginalWidth = 600
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControlcxGrid1: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGrid1
      ControlOptions.OriginalHeight = 344
      ControlOptions.OriginalWidth = 480
      ControlOptions.ShowBorder = False
      Index = 0
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
    Width = 1094
    ExplicitWidth = 1094
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
    end
  end
  inherited alfr: TActionList
    Left = 48
    Top = 456
    inherited aOk: TAction
      Enabled = True
      Visible = True
    end
    inherited aExit: TAction
      Visible = False
    end
    inherited aRefresh: TAction
      Enabled = True
    end
    object acFind: TAction
      Category = #1055#1086#1080#1089#1082
      AutoCheck = True
      Caption = #1055#1086#1080#1089#1082
      ImageIndex = 19
      OnExecute = acFindExecute
    end
    object acSelFind: TAction
      Category = #1055#1086#1080#1089#1082
      Caption = #1042#1099#1073#1086#1088
      OnExecute = acSelFindExecute
    end
  end
  inherited BarManager: TdxBarManager
    Left = 136
    Top = 464
    PixelsPerInch = 96
    inherited BarManagerBar2: TdxBar
      ItemLinks = <
        item
          Visible = True
          ItemName = 'dxBarButtonaNew'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaNewCopy'
        end
        item
          UserDefine = [udPaintStyle]
          Visible = True
          ItemName = 'dxBarButtonaKor'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaDel'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaOk'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaSave'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaExit'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaFiltrStart'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaFiltrFinish'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaPrnJur'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaPrnStr'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaExcel'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonRefresh'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaHelp'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaCheck'
        end
        item
          Visible = True
          ItemName = 'dxBarButtonaUnCheck'
        end
        item
          Visible = True
          ItemName = 'dxBarButton2'
        end>
    end
    object dxBarButton2: TdxBarButton [5]
      Action = acFind
      Category = 0
      LargeGlyph.SourceDPI = 96
      LargeGlyph.Data = {
        424D361000000000000036000000280000002000000020000000010020000000
        000000000000C40E0000C40E0000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000001000000030000
        0006000000080000000B0000000D0000000E0000000F0000000F000000100000
        000F0000000E0000000C00000009000000050000000100000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000003081A1341143F
        2E921B543CBD1F5E43D3257553FF247353FF247251FF247151FF237051FF2370
        4FFF1C593FD6184E37C1123A2999071710490000000600000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000000000072A8260FF36A7
        80FF34B186FF33B589FF34C192FF33BF90FF31BD8DFF30BC8CFF2FBA8AFF2EB9
        89FF2CAA7DFF2AA378FF2A976FFF257353FF0000000D00000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000000000062A7E5FE973D9
        BDFF5AD4B0FF43CCA1FF40C99DFF3EC79AFF3BC598FF38C295FF36C092FF34BE
        90FF32BD8EFF3ABF93FF42BE95FF247153EE0000000C00000000000000000000
        0000000000000000000100000001000000010000000100000001000000010000
        00000000000000000000000000000000000000000000000000031845357C48A7
        87FF74CEB4FF83E5CBFF57CEABFF2F9773FF207D5DFF1B7859FF218966FF42BF
        98FF5AD1ADFF4BB996FF349674FF154030880000000600000000000000000000
        0001000000020000000400000005000000070000000700000006000000040000
        0002000000010000000000000000000000000000000100000002000000070B22
        1A41256B53B545A987FF53AC90FF63A9B1FF71A7CCFF5D8CB7FF367489FF2C8E
        73FF3A9D7BFF22664DBA0B201946000000070000000100000000000000000000
        00030000000900000010000000170000001B0000001B00000017000000100000
        0009000000040000000100000000000000000000000300000009000000100000
        00180000001E091B15482D7A61D15588ABFF325994FF2C538FFF34608EFF2873
        5CCD091A14360000000700000003000000010000000000000001000000040000
        000C0302021F33262186584238CD74564AFF735549FF574038CF31251F870302
        02200000000D0000000500000002000000040000000C0302021F332621865843
        3ACF7F6459FFA4928BFF69707DED4572ACFF659FD7FF629CD6FF3968A5FF0C1C
        2C700000000800000000000000000000000000000000000000030000000B0D0A
        0934644C42DA937A6FFFC4B2A9FFDBCEC5FFDBCEC4FFC3B2A9FF8F776BFF5E46
        3CDB0C0908360000000C000000060000000B0D0A0934644C42DA8F7568FFB9A3
        97FFD9CCC1FFDAD0CAFF5F789EFF79AFDAFF90CCF5FF77B4E8FF5991CBFF1D3A
        66CB0000000E00000001000000000000000000000000000000070302021B6750
        45DAAE9A90FFE2D1C6FFC09879FFB3815CFFB4845CFFC49D7DFFE3D2C7FFAB96
        8CFF5F473DDB0202011F0000000F0302021C675045DAA89084FFD6BFB1FFBB91
        71FFD2B6A0FF787D8EFF3D5F92FFBAE1F6FFBDE6FCFF8CC9F2FF69A5DBFF2144
        7AF70D193495010101030000000000000000000000000000000C382B26829A82
        77FFDDCCBEFFAC7753FFCDA678FFE8D09DFFE9D2A2FFD2AE80FFB8855FFFE0CE
        C0FF91796EFF271C168500000019382C2783967C70FFD2BCADFFAB7652FFCDA6
        78FFF0E4CAFF456695FF385F95FFD5F0FBFFD1EDFBFF94CFF3FF6DA7DDFF2446
        7DFF172C59E20101010500000000000000000000000000000011665147CFD3C5
        BDFFB98C73FFC59263FFE5BC83FFE7C28AFFEAC895FFECCFA1FFD0A47AFFC59C
        82FFCFC1B9FF473329D100000023675248D0C8B7ACFFB5876CFFC59263FFE5BC
        83FFF0DDC0FF3D68A2FF3C6CA8FFBAD7E9FF698EB7FF325A91FF2B5086FF2851
        8FFE1D3869FA0101010500000000000000000000000000000013846B5EFAE7DD
        D7FFA26448FFDAA16EFFEFD0B8FFF6E3DAFFEDCAACFFE7BA8CFFE4BA8FFFB77A
        5CFFE8DED7FF583E33F50000002682685BF5DECFC6FFA16347FFDAA16EFFEFD0
        B8FFF7EEE9FF5A84B5FF539CE0FF497BB7FF5390CDFF4E8FD3FF3C76C1FF396C
        B1FF223F72FF01010105000000000000000000000000000000128B7064FFE9E1
        DAFF9E5E44FFD89667FFFBF0F3FFFAECEEFFF6E1DCFFE2A67BFFE3AF89FFB676
        5CFFE9E0DAFF5E4437FF000000268B7064FFE1D5CAFF9E5D43FFD89667FFFBF0
        F3FFFBF3F4FFC5CDDDFF5890CCFF7FB9E7FF86BDE9FF8DC4EEFF75A8DAFF5683
        B8FF1C335AC0010101040000000000000000000000000000000F897062F6EEE6
        E2FFB68471FFBB714DFFEDC4B1FFFCF4FAFFEDC5B2FFE0996EFFCB8B6CFFC695
        83FFF1EBE8FF5F4538FF1C13106C8F7567FFEAE1DBFFB3806CFFBB714DFFEDC4
        B1FFFCF6FBFFF4DFD5FFD5C0B8FF7E9EC5FF658EC1FF4276B3FF4C6E9DFE1D32
        519B03050816000000010000000000000000000000000000000B645249B7C0B2
        AAFFE4D4CCFF9F5B45FFBB6F4DFFD6875DFFD78860FFC57E5EFFB5715DFFE7D5
        CEFFD9D3D1FF61473AFF412D25C992786BFFDFD7D4FFDDC9BFFF9F5A44FFBB6F
        4DFFD6875DFFDA906BFFD8AA94FFD1A99DFFEDE2DEFFDBD3CFFF837672D10101
        0110000000040000000000000000000000000000000000000006110E0D2E947C
        6FFEF7F5F2FFE9DCD6FFBB8978FFA96954FFAD6C59FFC29281FFEBDED8FFF8F5
        F3FF75645EFF644A3DFF9B887DFF967D6FFF95837AFFF5F1EFFFE3D3CBFFB886
        74FFA86853FFAC6B58FFBF8E7CFFE4D4CDFFF3EFECFF8B7165FE0C0807300000
        00080000000200000000000000000000000000000000000000030000000C7360
        56C7B7A79EFFFCFBFAFFF7F3F0FFF4EFEBFFF4EFEBFFF7F3F0FFFCFBFAFFA89D
        97FF654B41FF684D40FF785D51FF9A8074FF897467FFD6CEC8FFFAF8F7FFF3EC
        E8FFEFE6E1FFEFE6E1FFF3ECE8FFFAF8F6FFB3A298FF6B564CC80000000E0000
        0004000000010000000000000000000000000000000000000001000000073930
        2B68978073FFCCBEB7FFF3F0EEFFFFFFFFFFF7F5F4FFDAD2CEFF88776FFF6E57
        4BFF7C6358FF6A5043FF66473BFF9E8478FF9B877AFFC5B7B0FFFFFFFFFFFAF8
        F7FFF6F3F2FFF1EEEDFFCAC4C2FF887770FF987F72FF342B266A000000080000
        0002000000000000000000000000000000000000000000000001000000040605
        0415977F74F4BFADA3FFD7CAC4FFFFFFFEFFD1C1BBFFA4877BFF877066FF7F69
        60FF917B6EFF6F5447FF67483BFFA1897CFFA49086FFD5CAC3FFFFFFFFFFEDE8
        E5FFAA9286FF7F685FFF5E4C44FF967D72FF8F776AF405040417000000050000
        0001000000000000000000000000000000000000000000000000000000020000
        0008675750A9B5A095FFE0D5D0FFF8F6F5FFEAE3DFFFC5B1A6FFA18980FF8772
        67FFAD988BFF73584BFF63453AFFA58D7FFFB2A095FFDDD3CEFFFFFFFFFFF0EB
        E8FFBFAA9EFF947E74FF7B665DFFAD978AFF615149AA00000009000000020000
        0000000000000000000000000000000000000000000000000000000000010000
        00042D27234EAA9487FFDDD3CCFFF2EEEBFFF2EEECFFD1C2B8FFB29D96FF907B
        71FFBEADA0FF775D50FF4E3A31C4A89183FFC4B4ABFFE6DFDAFFFFFFFFFFEFE9
        E6FFBEA99EFF917C74FF8D7870FFA99286FF2A24205000000005000000010000
        0000000000000000000000000000000000000000000000000000000000000000
        00020202020B988175E6D3C5BBFFEEE9E6FFF7F5F4FFDCCFC8FFC0ABA2FF9987
        7DFFBEABA1FF7C6255FF17100D4DAD9587FFD7CAC3FFEDE7E3FFFFFFFFFFEEE7
        E4FFBCA8A0FF917F78FFA7958AFF917C70E60202010C00000003000000010000
        0000000000000000000000000000000000000000000000000000000000000000
        0001000000055D504990C1B0A4FFEBE3DFFFFBF9F8FFE6DDD7FFCAB7B0FFA592
        88FFBCA8A1FF81685BFF00000010B0988BFFE0D7D1FFF2EDEAFFFFFFFFFFEDE5
        E2FFBDABA3FF94847DFFB8A499FF594C45900000000600000001000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0001000000031F1B1834AF978AFFE4DBD5FFFAF8F6FFEBE4E1FFD9C9C1FFB19F
        95FFB7A49CFF876E61FF0000000CB39C8FFFE4DBD5FFF5F1EFFFFFFFFFFFEFE9
        E6FFBBA9A2FFA08E87FFAB9385FF1E1A17340000000300000001000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000010000000477685FAED1C2B8FFF8F5F4FFF3EEEBFFE2D8D0FFC5B4
        ADFFBAA89FFF604F46B1000000087C6D64B1D3C5BDFFF7F4F2FFFFFFFFFFF3ED
        EBFFCBBFB9FFB5A399FF75655CAF000000050000000100000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000021C18162BA79387EED7CBC3FFF2EEECFFECE4E0FFC9B9
        B0FFA28D7FEE1814122F000000041E1B192EAC988BEED9CCC5FFF7F5F3FFECE4
        E0FFC3B3AAFFA69385EE1B18162C000000020000000100000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000001000000021311101F786960AAA18D80E5A18C80E57566
        5DAA13100F1F0000000200000002000000021412101E7A6C63AAA49185E5A490
        84E5786961AA13110F1F00000002000000010000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000010000000200000003000000030000
        0002000000010000000100000000000000000000000100000002000000020000
        0002000000020000000100000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000}
    end
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
    Left = 808
  end
  inherited cxStyleRepositoryVDS: TcxStyleRepository
    PixelsPerInch = 96
  end
  inherited cxImageLst16: TcxImageList
    FormatVersion = 1
  end
  object tbKDRKPN: TDataSource
    DataSet = fdsRKPN
    Left = 752
    Top = 504
  end
  object fdsRKPN: TFamDataSet
    Base = DMXE10.FbWrk
    FileName = 'RKPN'
    AfterScroll = fdsRKPNAfterScroll
    Left = 664
    Top = 504
    object fdsRKPNkdkp: TWordField
      FieldName = 'kdkp'
      Required = True
    end
    object fdsRKPNowner: TWordField
      FieldName = 'owner'
    end
    object fdsRKPNtn: TIntegerField
      FieldName = 'tn'
    end
    object fdsRKPNdeptup: TWordField
      FieldName = 'deptup'
    end
    object fdsRKPNsname: TStringField
      FieldName = 'sname'
      Size = 40
    end
    object fdsRKPNfname: TStringField
      FieldName = 'fname'
      Size = 160
    end
    object fdsRKPNuw: TWordField
      FieldName = 'uw'
    end
    object fdsRKPNkdnm: TStringField
      FieldName = 'kdnm'
      Size = 40
    end
    object fdsRKPNfdp: TDateField
      FieldName = 'fdp'
    end
    object fdsRKPNfdu: TDateField
      FieldName = 'fdu'
    end
    object fdsRKPNknp: TWordField
      FieldName = 'knp'
    end
  end
  object cxImageList2: TcxImageList
    SourceDPI = 96
    FormatVersion = 1
    DesignInfo = 30933272
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
  object cxGridPopupMenu1: TcxGridPopupMenu
    Grid = cxGrid
    PopupMenus = <>
    Left = 544
    Top = 488
  end
  object fdsKDRKPN_D: TFamDataSet
    Base = DMXE10.FbZp
    FileName = 'KDRKPN'
    Left = 552
    Top = 304
    object fdsKDRKPN_Dkdkp: TWordField
      FieldName = 'kdkp'
      Required = True
    end
    object fdsKDRKPN_Downer: TWordField
      FieldName = 'owner'
    end
    object fdsKDRKPN_Dtn: TIntegerField
      FieldName = 'tn'
    end
    object fdsKDRKPN_Ddeptup: TWordField
      FieldName = 'deptup'
    end
    object fdsKDRKPN_Dsname: TStringField
      FieldName = 'sname'
      Size = 40
    end
    object fdsKDRKPN_Dfname: TStringField
      FieldName = 'fname'
      Size = 160
    end
  end
  object fdsRKPNM: TFamDataSet
    Base = DMXE10.FbWrk
    FileName = 'RKPNM'
    AfterScroll = fdsRKPNMAfterScroll
    Left = 40
    Top = 544
    object fdsRKPNMkdkp: TWordField
      FieldName = 'kdkp'
      Required = True
    end
    object fdsRKPNMowner: TWordField
      FieldName = 'owner'
    end
    object fdsRKPNMtn: TIntegerField
      FieldName = 'tn'
    end
    object fdsRKPNMdeptup: TWordField
      FieldName = 'deptup'
    end
    object fdsRKPNMsname: TStringField
      FieldName = 'sname'
      Size = 40
    end
    object fdsRKPNMfname: TStringField
      FieldName = 'fname'
      Size = 160
    end
  end
  object tbRKPNM: TDataSource
    DataSet = fdsRKPNM
    Left = 112
    Top = 544
  end
  object dxLayoutLookAndFeelList1: TdxLayoutLookAndFeelList
    Left = 352
    Top = 472
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      Offsets.ControlOffsetHorz = 2
      Offsets.ControlOffsetVert = 2
      Offsets.ItemOffset = 2
      Offsets.RootItemsAreaOffsetHorz = 2
      Offsets.RootItemsAreaOffsetVert = 2
      PixelsPerInch = 96
    end
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
end
