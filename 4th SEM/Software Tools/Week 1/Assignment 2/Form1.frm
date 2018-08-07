VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Generate Marksheet"
   ClientHeight    =   4860
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4815
   LinkTopic       =   "Form1"
   ScaleHeight     =   4860
   ScaleWidth      =   4815
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text6 
      Height          =   285
      Left            =   2160
      TabIndex        =   12
      Top             =   3480
      Width           =   1215
   End
   Begin VB.TextBox Text5 
      Height          =   285
      Left            =   2160
      TabIndex        =   11
      Top             =   2880
      Width           =   1215
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   2160
      TabIndex        =   10
      Top             =   2280
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   2160
      TabIndex        =   9
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   2160
      TabIndex        =   8
      Top             =   1080
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      Height          =   315
      Left            =   1920
      TabIndex        =   7
      Top             =   360
      Width           =   2175
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Generate Marksheet"
      Height          =   495
      Left            =   2760
      TabIndex        =   6
      Top             =   4080
      Width           =   1815
   End
   Begin VB.Label Label6 
      Caption         =   "Computer Science:"
      Height          =   255
      Left            =   360
      TabIndex        =   5
      Top             =   3480
      Width           =   1455
   End
   Begin VB.Label Label5 
      Caption         =   "Chemistry:"
      Height          =   255
      Left            =   360
      TabIndex        =   4
      Top             =   2880
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "Physics:"
      Height          =   255
      Left            =   360
      TabIndex        =   3
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Mathematics:"
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   1680
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "English:"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   1080
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Student Name:"
      Height          =   255
      Left            =   600
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form2.Label2.Caption = Text1.Text
Form2.Label5.Caption = "You are promoted"
Dim flag As Integer
flag = 0
If Val(Text2.Text) < 40 Then
flag = flag + 1
End If
If Val(Text3.Text) < 40 Then
flag = flag + 1
End If
If Val(Text4.Text) < 40 Then
flag = flag + 1
End If
If Val(Text5.Text) < 40 Then
flag = flag + 1
End If

Dim total As Integer
total = Val(Text2.Text) + Val(Text3.Text) + Val(Text4.Text) + Val(Text5.Text) + Val(Text6.Text)
If total >= 300 Then
Form2.Label4.Caption = "1st"
ElseIf total >= 250 Then Form2.Label4.Caption = "2nd"
ElseIf total >= 200 Then Form2.Label4.Caption = "3rd"
Else: Form2.Label4.Caption = "FAIL"
Form2.Label5.Caption = "You are not promoted"
End If

If flag > 2 Then
Form2.Label4.Caption = "FAIL"
Form2.Label5.Caption = "You are not promoted"
End If
Form2.Show
End Sub
