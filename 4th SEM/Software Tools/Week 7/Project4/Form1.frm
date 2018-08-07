VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4110
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   5445
   LinkTopic       =   "Form1"
   ScaleHeight     =   4110
   ScaleWidth      =   5445
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   5040
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Save Record"
      Height          =   495
      Left            =   3840
      TabIndex        =   9
      Top             =   3120
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Choose File"
      Height          =   375
      Left            =   480
      TabIndex        =   8
      Top             =   3120
      Width           =   1575
   End
   Begin VB.TextBox Text4 
      Height          =   405
      Left            =   2040
      TabIndex        =   6
      Top             =   840
      Width           =   2895
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   2040
      TabIndex        =   2
      Top             =   2280
      Width           =   2895
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2040
      TabIndex        =   1
      Top             =   1560
      Width           =   2895
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2040
      TabIndex        =   0
      Top             =   120
      Width           =   2895
   End
   Begin VB.Label Label5 
      Caption         =   "No File Chosen"
      Height          =   375
      Left            =   600
      TabIndex        =   10
      Top             =   3720
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No.:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   360
      TabIndex        =   7
      Top             =   960
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Roll:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   360
      TabIndex        =   5
      Top             =   2400
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "Dept.:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   360
      TabIndex        =   4
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "Name:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   360
      TabIndex        =   3
      Top             =   240
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim dest As String

Private Sub Command1_Click()
CommonDialog1.Filter = "Text Files(*.txt)|*.txt"
CommonDialog1.ShowOpen
dest = CommonDialog1.FileName
Label5.Caption = CommonDialog1.FileTitle
End Sub

Private Sub Command2_Click()
Open dest For Append As #1
Print #1, vbCrLf + "Name: " + Text1.Text + vbCrLf + "Mobile No.: " + Text4.Text + vbCrLf + "Dept.: " + Text2.Text + vbCrLf + "Roll: " + Text3.Text
Close #1
End Sub
