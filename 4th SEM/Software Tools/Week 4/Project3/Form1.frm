VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form Form1 
   Caption         =   "Progess"
   ClientHeight    =   1740
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   5325
   LinkTopic       =   "Form1"
   ScaleHeight     =   1740
   ScaleWidth      =   5325
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.ProgressBar ProgressBar1 
      Height          =   375
      Left            =   360
      TabIndex        =   0
      Top             =   960
      Width           =   4575
      _ExtentX        =   8070
      _ExtentY        =   661
      _Version        =   327682
      Appearance      =   1
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   120
      Top             =   120
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Loading..."
      Height          =   255
      Left            =   2040
      TabIndex        =   1
      Top             =   480
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Timer1_Timer()
ProgressBar1.Value = ProgressBar1.Value + 10
If ProgressBar1.Value = ProgressBar1.Max Then
Timer1.Enabled = False
Form2.Show
Unload Me
End If
End Sub
