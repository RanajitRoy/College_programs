VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3405
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   3405
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Read"
      Height          =   495
      Left            =   1080
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
      Width           =   2415
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim a As String
Text1.Text = ""
Open "C:\Users\royra\Google Drive\IEM programs\4th SEM\Software Tools\Week 7\prac.txt" For Input As #1
Do
Input #1, a
Text1.Text = Text1.Text + a + vbCrLf
Loop Until EOF(1)
Close #1
End Sub
