VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2175
   ClientLeft      =   3330
   ClientTop       =   3030
   ClientWidth     =   3735
   LinkTopic       =   "Form1"
   ScaleHeight     =   2175
   ScaleWidth      =   3735
   Begin VB.CommandButton Command1 
      Caption         =   "Click"
      Height          =   495
      Left            =   960
      TabIndex        =   0
      Top             =   600
      Width           =   1815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Call MsgBox("This is a message box", vbOKOnly, "this is the title")
End Sub
