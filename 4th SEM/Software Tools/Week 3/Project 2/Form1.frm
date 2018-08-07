VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Jersey"
   ClientHeight    =   4050
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   4815
   LinkTopic       =   "Form1"
   ScaleHeight     =   4050
   ScaleWidth      =   4815
   StartUpPosition =   3  'Windows Default
   Begin VB.OptionButton Option3 
      Caption         =   "England"
      Height          =   495
      Left            =   360
      TabIndex        =   2
      Top             =   2400
      Width           =   1215
   End
   Begin VB.OptionButton Option2 
      Caption         =   "Australia"
      Height          =   495
      Left            =   360
      TabIndex        =   1
      Top             =   1680
      Width           =   1215
   End
   Begin VB.OptionButton Option1 
      Caption         =   "India"
      Height          =   495
      Left            =   360
      TabIndex        =   0
      Top             =   960
      Width           =   1215
   End
   Begin VB.Image Image1 
      Height          =   3135
      Left            =   1920
      Stretch         =   -1  'True
      Top             =   480
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Option1_Click()
Image1.Picture = LoadPicture("C:\Users\Ranajit\Pictures\india.jpg")
End Sub

Private Sub Option2_Click()
Image1.Picture = LoadPicture("C:\Users\Ranajit\Pictures\australia.jpg")
End Sub

Private Sub Option3_Click()
Image1.Picture = LoadPicture("C:\Users\Ranajit\Pictures\england.jpg")
End Sub

