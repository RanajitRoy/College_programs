VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4290
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   8160
   LinkTopic       =   "Form1"
   ScaleHeight     =   4290
   ScaleWidth      =   8160
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame4 
      Caption         =   "Fill Style"
      Height          =   3495
      Left            =   3720
      TabIndex        =   3
      Top             =   360
      Width           =   1455
      Begin VB.OptionButton Option13 
         Caption         =   "Solid"
         Height          =   495
         Left            =   120
         TabIndex        =   21
         Top             =   360
         Width           =   1215
      End
      Begin VB.OptionButton Option14 
         Caption         =   "Transparent"
         Height          =   495
         Left            =   120
         TabIndex        =   20
         Top             =   840
         Width           =   1215
      End
      Begin VB.OptionButton Option15 
         Caption         =   "Horizontal Line"
         Height          =   495
         Left            =   120
         TabIndex        =   19
         Top             =   1320
         Width           =   1215
      End
      Begin VB.OptionButton Option16 
         Caption         =   "Vertical Line"
         Height          =   495
         Left            =   120
         TabIndex        =   18
         Top             =   1800
         Width           =   1215
      End
      Begin VB.OptionButton Option17 
         Caption         =   "Diagonal"
         Height          =   495
         Left            =   120
         TabIndex        =   17
         Top             =   2280
         Width           =   1215
      End
      Begin VB.OptionButton Option18 
         Caption         =   "Cross"
         Height          =   495
         Left            =   120
         TabIndex        =   16
         Top             =   2760
         Width           =   1215
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Border Colour"
      Height          =   1695
      Left            =   2040
      TabIndex        =   2
      Top             =   2160
      Width           =   1455
      Begin VB.OptionButton Option10 
         Caption         =   "Red"
         ForeColor       =   &H000000FF&
         Height          =   375
         Left            =   120
         TabIndex        =   15
         Top             =   360
         Width           =   1215
      End
      Begin VB.OptionButton Option11 
         Caption         =   "Green"
         ForeColor       =   &H0000C000&
         Height          =   495
         Left            =   120
         TabIndex        =   14
         Top             =   720
         Width           =   1215
      End
      Begin VB.OptionButton Option12 
         Caption         =   "Blue"
         ForeColor       =   &H00FF0000&
         Height          =   375
         Left            =   120
         TabIndex        =   13
         Top             =   1200
         Width           =   1215
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Fill Colour"
      Height          =   1695
      Left            =   2040
      TabIndex        =   1
      Top             =   360
      Width           =   1455
      Begin VB.OptionButton Option7 
         Caption         =   "Red"
         ForeColor       =   &H000000FF&
         Height          =   375
         Left            =   120
         TabIndex        =   12
         Top             =   360
         Width           =   1095
      End
      Begin VB.OptionButton Option8 
         Caption         =   "Green"
         ForeColor       =   &H0000C000&
         Height          =   495
         Left            =   120
         TabIndex        =   11
         Top             =   720
         Width           =   1095
      End
      Begin VB.OptionButton Option9 
         Caption         =   "Blue"
         ForeColor       =   &H00FF0000&
         Height          =   375
         Left            =   120
         TabIndex        =   10
         Top             =   1200
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Shape"
      Height          =   3495
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   1575
      Begin VB.OptionButton Option1 
         Caption         =   "Rectangle"
         Height          =   495
         Left            =   120
         TabIndex        =   9
         Top             =   360
         Value           =   -1  'True
         Width           =   1215
      End
      Begin VB.OptionButton Option2 
         Caption         =   "Square"
         Height          =   495
         Left            =   120
         TabIndex        =   8
         Top             =   840
         Width           =   1215
      End
      Begin VB.OptionButton Option3 
         Caption         =   "Oval"
         Height          =   495
         Left            =   120
         TabIndex        =   7
         Top             =   1320
         Width           =   1215
      End
      Begin VB.OptionButton Option4 
         Caption         =   "Circle"
         Height          =   495
         Left            =   120
         TabIndex        =   6
         Top             =   1800
         Width           =   1215
      End
      Begin VB.OptionButton Option5 
         Caption         =   "Rounded Square"
         Height          =   495
         Left            =   120
         TabIndex        =   5
         Top             =   2280
         Width           =   1215
      End
      Begin VB.OptionButton Option6 
         Caption         =   "Rounded Rectangle"
         Height          =   495
         Left            =   120
         TabIndex        =   4
         Top             =   2760
         Width           =   1215
      End
   End
   Begin VB.Shape Shape1 
      BorderWidth     =   2
      FillStyle       =   7  'Diagonal Cross
      Height          =   2895
      Left            =   5760
      Top             =   720
      Width           =   1935
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Option1_Click()
Shape1.Shape = 0
End Sub

Private Sub Option2_Click()
Shape1.Shape = 1
End Sub

Private Sub Option3_Click()
Shape1.Shape = 2
End Sub

Private Sub Option4_Click()
Shape1.Shape = 3
End Sub

Private Sub Option5_Click()
Shape1.Shape = 5
End Sub

Private Sub Option6_Click()
Shape1.Shape = 4
End Sub

Private Sub Option7_Click()
Shape1.FillColor = &HFF&
End Sub

Private Sub Option8_Click()
Shape1.FillColor = &HC000&
End Sub

Private Sub Option9_Click()
Shape1.FillColor = &HFF0000
End Sub

Private Sub Option10_Click()
Shape1.BorderColor = &HFF&
End Sub

Private Sub Option11_Click()
Shape1.BorderColor = &HC000&
End Sub

Private Sub Option12_Click()
Shape1.BorderColor = &HFF0000
End Sub

Private Sub Option13_Click()
Shape1.FillStyle = 0
End Sub

Private Sub Option14_Click()
Shape1.FillStyle = 1
End Sub

Private Sub Option15_Click()
Shape1.FillStyle = 2
End Sub

Private Sub Option16_Click()
Shape1.FillStyle = 3
End Sub

Private Sub Option17_Click()
Shape1.FillStyle = 5
End Sub

Private Sub Option18_Click()
Shape1.FillStyle = 7
End Sub

