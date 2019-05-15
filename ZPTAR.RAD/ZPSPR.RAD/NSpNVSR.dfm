inherited frSpNVSR: TfrSpNVSR
  Caption = #1053#1072#1083#1086#1075#1086#1074#1099#1077' '#1074#1099#1095#1077#1090#1099' '#1087#1086' '#1074#1080#1076#1072#1084' '#1076#1086#1093#1086#1076#1086#1074
  ClientHeight = 541
  ClientWidth = 733
  OnShow = FormShow
  ExplicitWidth = 749
  ExplicitHeight = 580
  PixelsPerInch = 96
  TextHeight = 15
  inherited dxStatusBar1: TdxStatusBar
    Top = 518
    Width = 733
    ExplicitTop = 518
    ExplicitWidth = 733
  end
  object dxLayoutControl1: TdxLayoutControl [1]
    Left = 0
    Top = 66
    Width = 733
    Height = 452
    Align = alClient
    FocusOnClick = False
    TabOrder = 6
    LayoutLookAndFeel = dxLayoutCxLookAndFeel1
    object cxGrid1: TcxGrid
      Left = 0
      Top = 223
      Width = 733
      Height = 229
      TabOrder = 8
      OnEnter = cxGrid1Enter
      object cxGridTVw: TcxGridTableView
        OnDblClick = cxGridTVwDblClick
        OnKeyDown = cxGridTVwKeyDown
        Navigator.Buttons.CustomButtons = <>
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.ImmediateEditor = False
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnHidingOnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsCustomize.ColumnSorting = False
        OptionsData.CancelOnExit = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsSelection.InvertSelect = False
        OptionsView.GroupByBox = False
        OptionsView.Indicator = True
        Styles.IncSearch = cxStyleIncSearch
        object cxGridTVwKOD: TcxGridColumn
          Caption = #1050#1086#1076
          DataBinding.ValueType = 'Word'
          FooterAlignmentHorz = taCenter
          HeaderAlignmentHorz = taCenter
          HeaderGlyphAlignmentHorz = taCenter
          Width = 70
        end
        object cxGridTVwNM: TcxGridColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          FooterAlignmentHorz = taCenter
          HeaderAlignmentHorz = taCenter
          HeaderGlyphAlignmentHorz = taCenter
          Width = 200
        end
        object cxGridTVwKODRF: TcxGridColumn
          Caption = #1050#1086#1076' '#1087#1086' '#1056#1060
          DataBinding.ValueType = 'Integer'
          FooterAlignmentHorz = taCenter
          HeaderAlignmentHorz = taCenter
          HeaderGlyphAlignmentHorz = taCenter
          Width = 80
        end
        object cxGridTVwSK: TcxGridColumn
          Caption = #1053#1044#1060#1051
          DataBinding.ValueType = 'Currency'
          PropertiesClassName = 'TcxCurrencyEditProperties'
          Properties.Alignment.Horz = taRightJustify
          Properties.DecimalPlaces = 2
          Properties.DisplayFormat = ',0.00;-,0.00; '
          FooterAlignmentHorz = taCenter
          HeaderAlignmentHorz = taCenter
          HeaderGlyphAlignmentHorz = taCenter
          Width = 120
        end
        object cxGridTVwSKE: TcxGridColumn
          DataBinding.ValueType = 'Currency'
          PropertiesClassName = 'TcxCurrencyEditProperties'
          Properties.Alignment.Horz = taRightJustify
          Properties.DecimalPlaces = 2
          Properties.DisplayFormat = ',0.00;-,0.00; '
          FooterAlignmentHorz = taCenter
          HeaderAlignmentHorz = taCenter
          HeaderGlyphAlignmentHorz = taCenter
          Width = 149
          IsCaptionAssigned = True
        end
      end
      object cxGridLv: TcxGridLevel
        GridView = cxGridTVw
      end
    end
    object cxTxtEdNM: TcxTextEdit
      Left = 151
      Top = 77
      Style.HotTrack = False
      StyleDisabled.TextColor = clBtnText
      TabOrder = 2
      Text = 'cxTxtEdNM'
      Width = 568
    end
    object cxCEdKODRF: TcxCurrencyEdit
      Left = 151
      Top = 103
      Properties.DecimalPlaces = 0
      Properties.DisplayFormat = ',0;-,0;'
      Style.HotTrack = False
      TabOrder = 3
      OnKeyDown = cxCEdKODRFKeyDown
      Width = 160
    end
    object cxCEdSK: TcxCurrencyEdit
      Left = 151
      Top = 129
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = ',0.00;-,0.00'
      Style.HotTrack = False
      TabOrder = 4
      OnKeyDown = cxCEdKODRFKeyDown
      Width = 160
    end
    object cxCEdSKE: TcxCurrencyEdit
      Left = 151
      Top = 155
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = ',0.00;-,0.00'
      Style.HotTrack = False
      TabOrder = 5
      OnKeyDown = cxCEdKODRFKeyDown
      Width = 160
    end
    object cxOk: TcxButton
      Left = 423
      Top = 181
      Width = 140
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 6
      OnClick = cxOkClick
    end
    object cxCancel: TcxButton
      Left = 579
      Top = 181
      Width = 140
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      LookAndFeel.NativeStyle = False
      TabOrder = 7
      OnClick = cxCancelClick
    end
    object cxSpinKod: TcxSpinEdit
      Left = 151
      Top = 51
      Style.HotTrack = False
      TabOrder = 1
      Width = 568
    end
    object cxDate: TcxDateEdit
      Left = 57
      Top = 4
      Properties.DisplayFormat = 'yyyy'
      Properties.EditFormat = 'yyyy'
      Style.HotTrack = False
      StyleDisabled.TextColor = clBlack
      TabOrder = 0
      OnEnter = cxDateEnter
      OnExit = cxDateExit
      OnKeyDown = cxDateKeyDown
      Width = 121
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
    object dxLayoutED: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = #1050#1086#1088#1088#1077#1082#1090#1080#1088#1086#1074#1082#1072
      Visible = False
      ButtonOptions.Buttons = <>
      Index = 1
    end
    object dxLayoutControl1Item6: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = 'cxSpinEdit1'
      Visible = False
      Control = cxSpinKod
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item3: TdxLayoutItem
      Parent = dxLayoutED
      CaptionOptions.Text = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      Control = cxTxtEdNM
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutControl1Item4: TdxLayoutItem
      Parent = dxLayoutED
      AlignHorz = ahLeft
      CaptionOptions.Text = #1050#1086#1076' '#1056#1060
      Control = cxCEdKODRF
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 160
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item5: TdxLayoutItem
      Parent = dxLayoutED
      AlignHorz = ahLeft
      CaptionOptions.Text = #1057#1091#1084#1084#1072' '#1089#1082#1080#1076#1082#1080' '#1087#1086' '#1053#1044#1060#1051
      Control = cxCEdSK
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 160
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object dxLayoutControlSKE: TdxLayoutItem
      Parent = dxLayoutED
      AlignHorz = ahLeft
      CaptionOptions.Text = #1057#1091#1084#1084#1072' '#1089#1082#1080#1076#1082#1080' '#1087#1086' '#1045#1057#1053
      Control = cxCEdSKE
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 160
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object dxLayoutControl1Group2: TdxLayoutGroup
      Parent = dxLayoutED
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      Index = 5
    end
    object dxLayoutControl1Item7: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahRight
      CaptionOptions.Text = '  '
      Control = cxOk
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutControl1Item8: TdxLayoutItem
      Parent = dxLayoutControl1Group2
      AlignHorz = ahRight
      CaptionOptions.Text = '   '
      Control = cxCancel
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 140
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutGRID: TdxLayoutGroup
      Parent = dxLayoutControl1Group_Root
      AlignVert = avClient
      CaptionOptions.Text = 'New Group'
      CaptionOptions.Visible = False
      ButtonOptions.Buttons = <>
      ShowBorder = False
      Index = 2
    end
    object dxLayoutControl1Item2: TdxLayoutItem
      Parent = dxLayoutGRID
      AlignVert = avClient
      CaptionOptions.Text = 'cxGrid1'
      CaptionOptions.Visible = False
      CaptionOptions.Layout = clTop
      Control = cxGrid1
      ControlOptions.OriginalHeight = 200
      ControlOptions.OriginalWidth = 250
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object dxLayoutItem1: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahLeft
      CaptionOptions.Text = #1044#1072#1090#1072'('#1075#1075#1075#1075')'
      Offsets.Right = 4
      Offsets.Top = 4
      Control = cxDate
      ControlOptions.OriginalHeight = 23
      ControlOptions.OriginalWidth = 121
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  inherited dxRibbonA: TdxRibbon
    Width = 733
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
    Left = 280
    Top = 88
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
