VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Load Pic"
   ClientHeight    =   3135
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   6450
   LinkTopic       =   "Form1"
   ScaleHeight     =   3135
   ScaleWidth      =   6450
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Load Picture"
      Height          =   495
      Left            =   2520
      TabIndex        =   1
      Top             =   2400
      Width           =   1335
   End
   Begin VB.PictureBox Picture1 
      Height          =   1575
      Left            =   3360
      ScaleHeight     =   1515
      ScaleWidth      =   2715
      TabIndex        =   0
      Top             =   480
      Width           =   2775
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Picture Box"
      Height          =   375
      Left            =   4200
      TabIndex        =   3
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Image Box"
      Height          =   375
      Left            =   1080
      TabIndex        =   2
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Image Image1 
      Height          =   1575
      Left            =   360
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
Private Sub Command1_Click()
Image1.Picture = LoadPicture("C:\Users\Ranajit\Pictures\barca.jpg")
Picture1.Picture = LoadPicture("C:\Users\Ranajit\Pictures\barca.jpg")
End Sub
