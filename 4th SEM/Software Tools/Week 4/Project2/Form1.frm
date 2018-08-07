VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox Combo1 
      Height          =   315
      Left            =   960
      TabIndex        =   0
      Text            =   "Country"
      Top             =   360
      Width           =   2655
   End
   Begin VB.Image Image1 
      Height          =   1815
      Left            =   600
      Top             =   960
      Width           =   3375
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Combo1_Click()
If Combo1.ListIndex = 0 Then
Image1.Picture = LoadPicture("C:\Users\Sayantan\Desktop\Ranajit\Project2\India.jpg")
ElseIf Combo1.ListIndex = 1 Then
Image1.Picture = LoadPicture("C:\Users\Sayantan\Desktop\Ranajit\Project2\England.jpg")
ElseIf Combo1.ListIndex = 2 Then
Image1.Picture = LoadPicture("C:\Users\Sayantan\Desktop\Ranajit\Project2\USA.jpg")
ElseIf Combo1.ListIndex = 3 Then
Image1.Picture = LoadPicture("C:\Users\Sayantan\Desktop\Ranajit\Project2\Bangladesh.jpg")
End If
End Sub

Private Sub Form_Load()
Combo1.AddItem ("India")
Combo1.AddItem ("England")
Combo1.AddItem ("USA")
Combo1.AddItem ("Bangladesh")
Image1.Stretch = True
End Sub
