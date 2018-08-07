VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2475
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3630
   LinkTopic       =   "Form1"
   ScaleHeight     =   2475
   ScaleWidth      =   3630
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Save"
      Height          =   495
      Left            =   1200
      TabIndex        =   1
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   1095
      Left            =   360
      MultiLine       =   -1  'True
      TabIndex        =   0
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
Open "C:\Users\royra\Google Drive\IEM programs\4th SEM\Software Tools\Week 7\prac.txt" For Output As #1
Print #1, Text1.Text
Close #1
End Sub
