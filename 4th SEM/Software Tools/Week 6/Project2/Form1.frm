VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5115
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4395
   LinkTopic       =   "Form1"
   ScaleHeight     =   5115
   ScaleWidth      =   4395
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   -120
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Change Font"
      Height          =   375
      Left            =   1440
      TabIndex        =   3
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Change Colour"
      Height          =   375
      Left            =   1440
      TabIndex        =   2
      Top             =   3960
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Load Picture"
      Height          =   375
      Left            =   1440
      TabIndex        =   1
      Top             =   3360
      Width           =   1335
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Image Name "
      Height          =   255
      Left            =   960
      TabIndex        =   0
      Top             =   2880
      Width           =   2415
   End
   Begin VB.Image Image1 
      Height          =   2415
      Left            =   720
      Top             =   240
      Width           =   2895
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
CommonDialog1.Filter = "Image Files |*.jpg;*.jpeg;*.png;*bmp;*.gif"
CommonDialog1.ShowOpen
Label1.Caption = CommonDialog1.FileTitle
Image1.Picture = LoadPicture(CommonDialog1.FileName)
End Sub

Private Sub Command2_Click()
CommonDialog1.ShowColor
Label1.ForeColor = CommonDialog1.Color
End Sub

Private Sub Command3_Click()
CommonDialog1.ShowFont
Label1.Font = CommonDialog1.FontName
End Sub

Private Sub Form_Load()
Image1.Stretch = True
End Sub
