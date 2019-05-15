inherited fraspr1: Tfraspr1
  Caption = 'fraspr1'
  ClientHeight = 682
  ClientWidth = 852
  OnActivate = FormActivate
  ExplicitWidth = 868
  ExplicitHeight = 721
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 659
    Width = 852
    ExplicitTop = 659
    ExplicitWidth = 852
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 852
    Height = 593
    Align = alClient
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxREG: TcxTextEdit
      Left = 111
      Top = 29
      TabStop = False
      Enabled = False
      Style.HotTrack = False
      StyleDisabled.Color = 8310261
      StyleDisabled.TextColor = clBlack
      TabOrder = 1
      Width = 738
    end
    object cxRAI: TcxButtonEdit
      Left = 111
      Top = 55
      TabStop = False
      Enabled = False
      Properties.Buttons = <
        item
          Glyph.SourceDPI = 96
          Glyph.Data = {
            424D360400000000000036000000280000001000000010000000010020000000
            000000000000C40E0000C40E000000000000000000007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFF7F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFFCCCCCCFFCCCCCCFF7F7F
            7F007F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF000080FF000080FFCCCCCCFFCCCC
            CCFF7F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF0033FFFF0033FFFF0033CCFF000080FFB2B2
            B2FF800000FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFB2B2B2FF00CCFFFF0033FFFF0033CCFFB2B2B2FF8000
            00FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FF800000FFB2B2B2FF000080FFB2B2B2FF800000FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CC3333FF800000FF800000FF7F7F7F00800000FF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CC3333FF800000FF800000FFB2B2B2FFCCCCCCFF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF800000FF800000FF800000FFB2B2B2FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CBCBCBFF800000FF800000FFB2B2B2FFCC3333FF800000FFCCCC
            CCFFCBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFCC3333FFB2B2B2FF0033FFFFB2B2B2FFB2B2B2FFCC33
            33FF7F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FFCC3333FFB2B2B2FF0033FFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF0033CCFF0033CCFF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F000033CCFF7F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00}
          Kind = bkGlyph
          LeftAlignment = True
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxRAIPropertiesButtonClick
      Style.Color = 8310261
      Style.HotTrack = False
      StyleDisabled.Color = 8310261
      StyleDisabled.TextColor = clBlack
      TabOrder = 2
      Width = 738
    end
    object cxGrid: TcxGrid
      Left = 3
      Top = 133
      Width = 846
      Height = 457
      TabOrder = 5
      object tvUL: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseDown = tvULMouseDown
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.Cancel.Visible = True
        FilterBox.Visible = fvNever
        FindPanel.DisplayMode = fpdmAlways
        OnCustomDrawCell = tvULCustomDrawCell
        OnEditValueChanged = tvULEditValueChanged
        OnFocusedRecordChanged = tvFocusedRecordChanged
        OnInitEditValue = tvULInitEditValue
        DataController.Filter.Options = [fcoCaseInsensitive]
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        Filtering.MRUItemsList = False
        Filtering.ColumnMRUItemsList = False
        FilterRow.InfoText = #1057#1090#1088#1086#1082#1072' '#1092#1080#1083#1100#1090#1088#1072
        OptionsBehavior.PostponedSynchronization = False
        OptionsBehavior.CopyCaptionsToClipboard = False
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.CopyPreviewToClipboard = False
        OptionsBehavior.ExpandMasterRowOnDblClick = False
        OptionsBehavior.ImmediateEditor = False
        OptionsBehavior.PullFocusing = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object tvULUlN: TcxGridColumn
          Caption = #1059#1083#1080#1094#1072
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Glyph.SourceDPI = 96
              Glyph.Data = {
                424D360400000000000036000000280000001000000010000000010020000000
                000000000000C40E0000C40E0000000000000000000000000000000000000000
                000000000000000000000000000086653F478B6F52FF8B6F52FF8866414C0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFC3AC8FFFC2AC8FFF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFC7B195FFC7B094FF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFCAB499FFC9B398FF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFCDB89EFFCCB89EFF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFD0BDA4FFCFBCA3FF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFD3C1A9FFD3C1A9FF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFD6C5AFFFD6C5AEFF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000008B6F52FFD9C9B4FFD9C9B4FF8B6F52FF0000
                0000000000000000000000000000000000000000000000000000A07B4F089273
                519F8F7151CD8C7051EC8C7051EC8B6F52FFD4BEA3FFD3BEA3FF8B6F52FF8E6B
                3F2B0000000000000000000000000000000000000000A27F530D957550CD9E7A
                4E12815C31027D582D1C8B6F52FFDFCEB6FFD2BCA1FFD2BCA0FFDFCEB7FF8B6F
                52FF8C693D2B000000000000000000000000000000009476549BA17C50440000
                00008B673B028B6F52FFE5D6C1FFDDCCB4FFE1D2BCFFE1D1BCFFDDCBB4FFE5D6
                C2FF8B6F52FF8C693D2B0000000000000000000000008F7252C69F7A4D388B66
                3A018B6F52FFE8DAC7FFE2D3BEFFE7DBC8FFE9DFCDFFE9DFCDFFE6DAC7FFE1D2
                BCFFE8D9C6FF8B6F52FF8C693C2B00000000000000008D705271987244B18B6F
                52FFEADDCAFFE6DAC7FFEDE3D4FFF1EADEFFF4EEE5FFF4EEE5FFF1EBDEFFEDE3
                D4FFE6D9C6FFEADECBFF8B6F52FF8B673B2B00000000987449268B6F52FFF2E9
                D8FFF0E5D6FFF4ECDEFFF8F2E8FFFCF7F0FFFFFBF7FFFFFBF7FFFCF7F0FFF8F2
                E8FFF4ECDFFFF0E5D5FFF4EADAFF8B6F52FF937148398B6F52FF8B6F52FF8B6F
                52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF8B6F
                52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF8B6F52FF}
              Kind = bkGlyph
            end
            item
              Glyph.SourceDPI = 96
              Glyph.Data = {
                424D360400000000000036000000280000001000000010000000010020000000
                000000000000C40E0000C40E000000000000000000007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFF7F7F7F007F7F
                7F007F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFFCCCCCCFFCCCCCCFF7F7F
                7F007F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F000033CCFF000080FF000080FFCCCCCCFFCCCC
                CCFF7F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F000033CCFF0033FFFF0033FFFF0033CCFF000080FFB2B2
                B2FF800000FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F00CC3333FF800000FFB2B2B2FF00CCFFFF0033FFFF0033CCFFB2B2B2FF8000
                00FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F00CC3333FF800000FF800000FFB2B2B2FF000080FFB2B2B2FF800000FF7F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F00CC3333FF800000FF800000FF7F7F7F00800000FF7F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F00CC3333FF800000FF800000FFB2B2B2FFCCCCCCFF7F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F00CBCBCBFF800000FF800000FF800000FFB2B2B2FF7F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F00CBCBCBFF800000FF800000FFB2B2B2FFCC3333FF800000FFCCCC
                CCFFCBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F00CC3333FF800000FFCC3333FFB2B2B2FF0033FFFFB2B2B2FFB2B2B2FFCC33
                33FF7F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F00CC3333FFCC3333FFB2B2B2FF0033FFFF0033FFFF0033CCFF000080FFCCCC
                CCFF7F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FFCCCC
                CCFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FF7F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F000033CCFF0033CCFF0033CCFF7F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F000033CCFF7F7F7F007F7F7F007F7F
                7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00}
              Kind = bkGlyph
              LeftAlignment = True
            end>
          Properties.IncrementalSearch = False
          Properties.OnButtonClick = tvULColumn10PropertiesButtonClick
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          SortIndex = 0
          SortOrder = soAscending
          Width = 300
        end
        object tvULIndex: TcxGridColumn
          Caption = #1048#1085#1076#1077#1082#1089
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IgnoreTimeForFiltering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
        end
        object tvULRegK: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 60
        end
        object tvULRaiK: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 60
        end
        object tvULGorK: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 60
        end
        object tvULNasK: TcxGridColumn
          Caption = #1053#1072#1089'.'#1087#1091#1085#1082#1090
          DataBinding.ValueType = 'Word'
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IgnoreTimeForFiltering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 70
        end
        object tvULUlK: TcxGridColumn
          Caption = #1059#1083#1080#1094#1072
          Visible = False
          Width = 21
        end
        object tvULRegN: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          Visible = False
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 160
        end
        object tvULRaiN: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          Visible = False
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 160
        end
        object tvULGorN: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
          Visible = False
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 160
        end
        object tvULNasN: TcxGridColumn
          Caption = #1053#1072#1089#1077#1083#1077#1085#1085#1099#1081' '#1087#1091#1085#1082#1090
          Visible = False
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 160
        end
      end
      object tvREG: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvREGCustomDrawCell
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.PostponedSynchronization = False
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.ImmediateEditor = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object tvREGRegN: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
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
          Width = 300
        end
        object tvREGRegK: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 48
        end
      end
      object tvRAI: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvRAICustomDrawCell
        OnFocusedRecordChanged = tvFocusedRecordChanged
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.PostponedSynchronization = False
        OptionsBehavior.CopyCaptionsToClipboard = False
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.CopyPreviewToClipboard = False
        OptionsBehavior.ImmediateEditor = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.GroupRowStyle = grsOffice11
        OptionsView.GroupSummaryLayout = gslAlignWithColumns
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object tvRAIRaiN: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          SortIndex = 0
          SortOrder = soAscending
          Width = 300
        end
        object tvRAIRegK: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          DataBinding.ValueType = 'Word'
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 48
        end
        object tvRAIRaiK: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 49
        end
        object tvRAIRegN: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          Visible = False
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Focusing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Sorting = False
          Width = 200
        end
      end
      object tvGOR: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvGORCustomDrawCell
        OnFocusedRecordChanged = tvFocusedRecordChanged
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        Styles.IncSearch = cxStyleIncSearch
        object tvGORGorN: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          SortIndex = 0
          SortOrder = soAscending
          Width = 300
        end
        object tvGORRegK: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 46
        end
        object tvGORRaiK: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 43
        end
        object tvGORGorK: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
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
          Options.Sorting = False
          Width = 41
        end
        object tvGORRegN: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          Visible = False
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
          Options.Sorting = False
          Width = 160
        end
        object tvGORRaiN: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          Visible = False
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IgnoreTimeForFiltering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 160
        end
      end
      object tvNAS: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvNASCustomDrawCell
        OnFocusedRecordChanged = tvFocusedRecordChanged
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        Styles.IncSearch = cxStyleIncSearch
        object tvNASNasN: TcxGridColumn
          Caption = #1053#1072#1089'. '#1087#1091#1085#1082#1090
          Options.Sorting = False
          SortIndex = 0
          SortOrder = soAscending
          Width = 300
        end
        object tvNASRegK: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
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
          Options.Sorting = False
        end
        object tvNASRaiK: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
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
          Options.Sorting = False
        end
        object tvNASGorK: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
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
          Options.Sorting = False
        end
        object tvNASNasK: TcxGridColumn
          Caption = #1053#1072#1089'. '#1087#1091#1085#1082#1090
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
          Options.Sorting = False
        end
        object tvNASRegN: TcxGridColumn
          Caption = #1056#1077#1075#1080#1086#1085
          Visible = False
          Options.Editing = False
          Options.Filtering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
        end
        object tvNASRaiN: TcxGridColumn
          Caption = #1056#1072#1081#1086#1085
          Visible = False
          Options.Editing = False
          Options.Filtering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
        end
        object tvNASGorN: TcxGridColumn
          Caption = #1043#1086#1088#1086#1076
          Visible = False
          Options.Editing = False
          Options.Filtering = False
          Options.IncSearch = False
          Options.FilteringFilteredItemsList = False
          Options.FilteringMRUItemsList = False
          Options.FilteringPopup = False
          Options.FilteringPopupMultiSelect = False
          Options.GroupFooters = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
        end
      end
      object tvSTR: TcxGridTableView
        OnDblClick = aOkExecute
        OnMouseDown = tvULMouseDown
        OnMouseWheel = tvULMouseWheel
        Navigator.Buttons.CustomButtons = <>
        OnCustomDrawCell = tvSTRCustomDrawCell
        OnEditValueChanged = tvULEditValueChanged
        OnFocusedRecordChanged = tvFocusedRecordChanged
        OnInitEditValue = tvULInitEditValue
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.PostponedSynchronization = False
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.IncSearch = True
        OptionsBehavior.ImmediateEditor = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.NoDataToDisplayInfoText = ' '
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object tvSTRStrN: TcxGridColumn
          Caption = #1057#1090#1088#1072#1085#1072
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
          Width = 300
        end
        object tvSTRStrK: TcxGridColumn
          Caption = #1057#1090#1088#1072#1085#1072
          DataBinding.ValueType = 'Word'
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
          Options.Sorting = False
          Width = 54
        end
      end
      object cxGridLv: TcxGridLevel
        GridView = tvUL
      end
    end
    object cxGOR: TcxButtonEdit
      Left = 111
      Top = 81
      TabStop = False
      Enabled = False
      Properties.Buttons = <
        item
          Glyph.SourceDPI = 96
          Glyph.Data = {
            424D360400000000000036000000280000001000000010000000010020000000
            000000000000C40E0000C40E000000000000000000007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFF7F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFFCCCCCCFFCCCCCCFF7F7F
            7F007F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF000080FF000080FFCCCCCCFFCCCC
            CCFF7F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF0033FFFF0033FFFF0033CCFF000080FFB2B2
            B2FF800000FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFB2B2B2FF00CCFFFF0033FFFF0033CCFFB2B2B2FF8000
            00FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FF800000FFB2B2B2FF000080FFB2B2B2FF800000FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CC3333FF800000FF800000FF7F7F7F00800000FF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CC3333FF800000FF800000FFB2B2B2FFCCCCCCFF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF800000FF800000FF800000FFB2B2B2FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CBCBCBFF800000FF800000FFB2B2B2FFCC3333FF800000FFCCCC
            CCFFCBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFCC3333FFB2B2B2FF0033FFFFB2B2B2FFB2B2B2FFCC33
            33FF7F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FFCC3333FFB2B2B2FF0033FFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF0033CCFF0033CCFF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F000033CCFF7F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00}
          Kind = bkGlyph
          LeftAlignment = True
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxRAIPropertiesButtonClick
      Style.Color = 8310261
      Style.HotTrack = False
      StyleDisabled.Color = 8310261
      StyleDisabled.TextColor = clBlack
      TabOrder = 3
      Width = 738
    end
    object cxNAS: TcxButtonEdit
      Left = 111
      Top = 107
      TabStop = False
      Enabled = False
      Properties.Buttons = <
        item
          Glyph.SourceDPI = 96
          Glyph.Data = {
            424D360400000000000036000000280000001000000010000000010020000000
            000000000000C40E0000C40E000000000000000000007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFF7F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F00CCCCCCFFCCCCCCFFCCCCCCFF7F7F
            7F007F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF000080FF000080FFCCCCCCFFCCCC
            CCFF7F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF0033FFFF0033FFFF0033CCFF000080FFB2B2
            B2FF800000FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFB2B2B2FF00CCFFFF0033FFFF0033CCFFB2B2B2FF8000
            00FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FF800000FFB2B2B2FF000080FFB2B2B2FF800000FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CC3333FF800000FF800000FF7F7F7F00800000FF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CC3333FF800000FF800000FFB2B2B2FFCCCCCCFF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F00CBCBCBFF800000FF800000FF800000FFB2B2B2FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F00CBCBCBFF800000FF800000FFB2B2B2FFCC3333FF800000FFCCCC
            CCFFCBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FF800000FFCC3333FFB2B2B2FF0033FFFFB2B2B2FFB2B2B2FFCC33
            33FF7F7F7F007F7F7F00CBCBCBFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F00CC3333FFCC3333FFB2B2B2FF0033FFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F00CC3333FF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FFCCCC
            CCFF7F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F000033CCFF00CCFFFF0033FFFF0033CCFF000080FF7F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F000033CCFF0033CCFF0033CCFF7F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F000033CCFF7F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F00}
          Kind = bkGlyph
          LeftAlignment = True
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxRAIPropertiesButtonClick
      Style.Color = 8310261
      Style.HotTrack = False
      StyleDisabled.Color = 8310261
      StyleDisabled.TextColor = clBlack
      TabOrder = 4
      Width = 738
    end
    object cxPB: TcxProgressBar
      Left = 3
      Top = 3
      Properties.Max = 30000.000000000000000000
      TabOrder = 0
      Width = 846
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
    object lciPB: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = '1'
      CaptionOptions.Visible = False
      Control = cxPB
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Group5: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignVert = avClient
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group3: TdxLayoutGroup
      Parent = dxLayoutControl1Group5
      AlignHorz = ahClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Enabled = False
      ShowBorder = False
      Index = 0
    end
    object lciREG: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = #1056#1077#1075#1080#1086#1085
      Control = cxREG
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 300
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object lciRAI: TdxLayoutItem
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = #1056#1072#1081#1086#1085
      Control = cxRAI
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutControl1Group3
      CaptionOptions.Text = 'Hidden Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = 2
    end
    object lciGOR: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = #1043#1086#1088#1086#1076
      Control = cxGOR
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object lciNAS: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      CaptionOptions.Text = #1053#1072#1089#1077#1083#1077#1085#1085#1099#1081' '#1087#1091#1085#1082#1090
      Control = cxNAS
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Group1: TdxLayoutGroup
      Parent = dxLayoutControl1Group5
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = dxLayoutControl1Group1
      AlignVert = avClient
      CaptionOptions.Text = 'cxCurrencyEdit1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGrid
      ControlOptions.OriginalHeight = 461
      ControlOptions.OriginalWidth = 848
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 852
    ExplicitWidth = 852
    inherited dxRibbon1Tab1: TdxRibbonTab
      Index = 0
    end
  end
  inherited alfr: TActionList
    inherited aOk: TAction
      Enabled = True
      Visible = True
    end
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
    Left = 304
    Top = 480
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
      ItemOptions.CaptionOptions.TextDisabledColor = clBlack
      Offsets.ControlOffsetHorz = 2
      Offsets.ControlOffsetVert = 2
      Offsets.ItemOffset = 2
      Offsets.RootItemsAreaOffsetHorz = 2
      Offsets.RootItemsAreaOffsetVert = 2
      PixelsPerInch = 96
    end
  end
end
