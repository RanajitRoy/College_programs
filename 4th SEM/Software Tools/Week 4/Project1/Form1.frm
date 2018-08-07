VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Shape Selection"
   ClientHeight    =   1965
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   5265
   LinkTopic       =   "Form1"
   ScaleHeight     =   1965
   ScaleWidth      =   5265
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1 
      Height          =   1035
      ItemData        =   "Form1.frx":0000
      Left            =   360
      List            =   "Form1.frx":0002
      TabIndex        =   0
      Top             =   480
      Width           =   1575
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Shape"
      Height          =   255
      Left            =   3120
      TabIndex        =   2
      Top             =   120
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "List"
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   120
      Width           =   1215
   End
   Begin VB.Shape Shape1 
      BorderWidth     =   3
      Height          =   1095
      Left            =   2640
      Top             =   480
      Width           =   2175
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
List1.AddItem ("Rectangle")
List1.AddItem ("Square")
List1.AddItem ("Oval")
List1.AddItem ("Circle")
Shape1.Visible = False
End Sub

Private Sub List1_Click()
Shape1.Visible = True
If List1.ListIndex = 0 Then
Shape1.Shape = 0
ElseIf List1.ListIndex = 1 Then
Shape1.Shape = 1
ElseIf List1.ListIndex = 2 Then
Shape1.Shape = 2
ElseIf List1.ListIndex = 3 Then
Shape1.Shape = 3
End If
End Sub
