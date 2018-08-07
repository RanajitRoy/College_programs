VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Font Style"
   ClientHeight    =   2250
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4410
   LinkTopic       =   "Form1"
   ScaleHeight     =   2250
   ScaleWidth      =   4410
   StartUpPosition =   3  'Windows Default
   Begin VB.OptionButton Option2 
      Caption         =   "Bold"
      Height          =   495
      Left            =   1560
      TabIndex        =   2
      Top             =   1560
      Width           =   1215
   End
   Begin VB.OptionButton Option1 
      Caption         =   "Normal"
      Height          =   375
      Left            =   1560
      TabIndex        =   1
      Top             =   1080
      Value           =   -1  'True
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   3015
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Option1_Click()
If Option1.Value = True Then
Text1.FontBold = False
End If
End Sub

Private Sub Option2_Click()
If Option2.Value = True Then
Text1.FontBold = True
End If
End Sub
