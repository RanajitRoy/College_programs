VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form"
   ClientHeight    =   1200
   ClientLeft      =   10155
   ClientTop       =   5685
   ClientWidth     =   3660
   LinkTopic       =   "Form1"
   MDIChild        =   -1  'True
   ScaleHeight     =   1200
   ScaleWidth      =   3660
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "This is a Child form for the MDI Form"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   480
      TabIndex        =   0
      Top             =   240
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
