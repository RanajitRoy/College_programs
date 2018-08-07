VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox Check3 
      Caption         =   "Small"
      Height          =   255
      Left            =   1680
      TabIndex        =   3
      Top             =   2280
      Width           =   1215
   End
   Begin VB.CheckBox Check2 
      Caption         =   "Block"
      Height          =   255
      Left            =   1680
      TabIndex        =   2
      Top             =   1800
      Width           =   1215
   End
   Begin VB.CheckBox Check1 
      Caption         =   "Normal"
      Height          =   255
      Left            =   1680
      TabIndex        =   1
      Top             =   1320
      Value           =   1  'Checked
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      Height          =   405
      Left            =   720
      TabIndex        =   0
      ToolTipText     =   "enter here"
      Top             =   600
      Width           =   3015
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Check1_Click()
If Check1.Value = 1 Then
Check2.Value = 0
Check3.Value = 0
End If
End Sub

Private Sub Check2_Click()
If Check2.Value = 1 Then
Text1.Text = UCase(Text1.Text)
Check1.Value = 0
Check3.Value = 0
End If
End Sub

Private Sub Check3_Click()
If Check3.Value = 1 Then
Text1.Text = LCase(Text1.Text)
Check2.Value = 0
Check1.Value = 0
End If
End Sub
