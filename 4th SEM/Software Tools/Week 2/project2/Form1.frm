VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2355
   ClientLeft      =   7560
   ClientTop       =   3825
   ClientWidth     =   3210
   LinkTopic       =   "Form1"
   ScaleHeight     =   2355
   ScaleWidth      =   3210
   Begin VB.CommandButton Command1 
      Caption         =   "Try!"
      Height          =   495
      Left            =   960
      TabIndex        =   1
      Top             =   1320
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "click to try!"
      Height          =   495
      Left            =   960
      TabIndex        =   0
      Top             =   360
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
x = InputBox("Enter a character", "Character input")
If Len(x) > 1 Or x = "" Then
Label1.Caption = "Enter one character"
Else
v = Asc(x)
If v >= 65 And v <= 90 Then
If v = 65 Or v = 69 Or v = 73 Or v = 79 Or v = 85 Then
Label1.Caption = "Vowel!"
Else
Label1.Caption = "Consonant!"
End If
ElseIf v >= 97 And v <= 122 Then
If v = 97 Or v = 101 Or v = 105 Or v = 111 Or v = 117 Then
Label1.Caption = "Vowel!"
Else
Label1.Caption = "Consonant!"
End If
Else
Label1.Caption = "Special character!"
End If
End If
End Sub
