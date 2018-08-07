VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4395
   ClientLeft      =   225
   ClientTop       =   555
   ClientWidth     =   3705
   LinkTopic       =   "Form1"
   ScaleHeight     =   4395
   ScaleWidth      =   3705
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   100
      Left            =   0
      Top             =   0
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Start"
      Height          =   495
      Left            =   1200
      TabIndex        =   0
      Top             =   3600
      Width           =   1215
   End
   Begin VB.Shape Shape3 
      BorderColor     =   &H000000FF&
      BorderWidth     =   3
      Height          =   855
      Left            =   1320
      Shape           =   3  'Circle
      Top             =   2520
      Width           =   975
   End
   Begin VB.Shape Shape2 
      BorderColor     =   &H0000FFFF&
      BorderWidth     =   3
      Height          =   855
      Left            =   1320
      Shape           =   3  'Circle
      Top             =   1440
      Width           =   975
   End
   Begin VB.Shape Shape1 
      BorderColor     =   &H0000C000&
      BorderWidth     =   3
      Height          =   855
      Left            =   1320
      Shape           =   3  'Circle
      Top             =   360
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim co As Integer
Dim incr As Boolean

Private Sub Command1_Click()
Timer1.Enabled = True
End Sub

Private Sub Form_Load()
co = 0
incr = True
Shape1.FillColor = vbGreen
Shape2.FillColor = vbYellow
Shape3.FillColor = vbRed
Timer1.Interval = 1000
End Sub

Private Sub Timer1_Timer()
If co >= 0 Then
If co < 4 Then
Shape1.FillStyle = 0
Shape2.FillStyle = 1
Shape3.FillStyle = 1
End If
End If
If co >= 4 Then
If co < 6 Then
Shape1.FillStyle = 1
Shape2.FillStyle = 0
Shape3.FillStyle = 1
End If
End If
If co >= 6 Then
If co <= 9 Then
Shape1.FillStyle = 1
Shape2.FillStyle = 1
Shape3.FillStyle = 0
End If
End If
If co = 0 Then
incr = True
End If
If co = 9 Then
incr = False
End If
If incr = True Then
co = co + 1
Else
co = co - 1
End If
End Sub
