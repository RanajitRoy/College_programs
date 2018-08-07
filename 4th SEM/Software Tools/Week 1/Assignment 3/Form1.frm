VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Steel Grade"
   ClientHeight    =   2550
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4620
   LinkTopic       =   "Form1"
   ScaleHeight     =   2550
   ScaleWidth      =   4620
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Find Grade"
      Height          =   495
      Left            =   3120
      TabIndex        =   7
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox Tens 
      Height          =   285
      Left            =   1920
      TabIndex        =   6
      Top             =   1920
      Width           =   855
   End
   Begin VB.TextBox Carbon 
      Height          =   285
      Left            =   1920
      TabIndex        =   5
      Top             =   1320
      Width           =   855
   End
   Begin VB.TextBox Hard 
      Height          =   285
      Left            =   1920
      TabIndex        =   4
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label4 
      Caption         =   "Tensile strength:"
      Height          =   255
      Left            =   480
      TabIndex        =   3
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Carbon content:"
      Height          =   255
      Left            =   480
      TabIndex        =   2
      Top             =   1320
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Hardness:"
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   720
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Steel Characteristics"
      Height          =   255
      Left            =   1440
      TabIndex        =   0
      Top             =   120
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
If Hard.Text = "" Or Carbon.Text = "" Or Tens.Text = "" Then
MsgBox ("Invalid Input")
ElseIf Val(Hard.Text) > 50 And Val(Carbon.Text) < 0.7 And Val(Tens.Text) > 5600 Then
MsgBox ("Steel Grade is 10")
ElseIf Val(Hard.Text) > 50 And Val(Carbon.Text) < 0.7 Then
MsgBox ("Steel Grade is 9")
ElseIf Val(Carbon.Text) < 0.7 And Val(Tens.Text) > 5600 Then
MsgBox ("Steel Grade is 8")
ElseIf Val(Hard.Text) > 50 And Val(Tens.Text) > 5600 Then
MsgBox ("Steel Grade is 7")
ElseIf Val(Hard.Text) > 50 Or Val(Carbon.Text) < 0.7 Or Val(Tens.Text) > 5600 Then
MsgBox ("Steel Grade is 6")
Else
MsgBox ("Steel Grade is 5")
End If
End Sub
