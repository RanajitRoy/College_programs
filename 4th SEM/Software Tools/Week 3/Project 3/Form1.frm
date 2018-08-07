VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Image"
   ClientHeight    =   4395
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   4455
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4395
   ScaleWidth      =   4455
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Load"
      Height          =   495
      Left            =   1560
      TabIndex        =   1
      Top             =   3720
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      Height          =   375
      Left            =   720
      TabIndex        =   0
      Top             =   3240
      Width           =   3015
   End
   Begin VB.Image Image1 
      BorderStyle     =   1  'Fixed Single
      Height          =   2775
      Left            =   720
      Stretch         =   -1  'True
      Top             =   240
      Width           =   3015
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
adr = "C:\Users\Ranajit\Pictures\"
Image1.Picture = LoadPicture(adr + Text1.Text)
End Sub
