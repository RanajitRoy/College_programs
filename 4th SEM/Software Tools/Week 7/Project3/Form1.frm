VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3735
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   3735
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Append"
      Height          =   495
      Left            =   1320
      TabIndex        =   1
      Top             =   2160
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   1455
      Left            =   480
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   360
      Width           =   2775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Open "C:\Users\royra\Google Drive\IEM programs\4th SEM\Software Tools\Week 7\prac.txt" For Append As #1
Print #1, Text1.Text
Close #1
End Sub
