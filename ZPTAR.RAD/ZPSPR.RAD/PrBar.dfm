object ProgressBarForm: TProgressBarForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1077#1084#1085#1086#1075#1086' '#1087#1086#1076#1086#1078#1076#1080#1090#1077'...'
  ClientHeight = 17
  ClientWidth = 535
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object dxStatusBar: TdxStatusBar
    Left = 0
    Top = -3
    Width = 535
    Height = 20
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarContainerPanelStyle'
        PanelStyle.Container = dxStatusBarContainer0
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    object dxStatusBarContainer0: TdxStatusBarContainerControl
      Left = 2
      Top = 4
      Width = 531
      Height = 14
      object ProgressBar1: TcxProgressBar
        Left = 0
        Top = 0
        Align = alClient
        Properties.AnimationPath = cxapPingPong
        Properties.BarStyle = cxbsAnimationLEDs
        Properties.BeginColor = 54056
        Properties.ShowText = False
        TabOrder = 0
        Width = 531
      end
    end
  end
end
