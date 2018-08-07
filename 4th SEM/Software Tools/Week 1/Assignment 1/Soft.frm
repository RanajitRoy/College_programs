VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4965
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   7695
   LinkTopic       =   "Form1"
   ScaleHeight     =   4965
   ScaleWidth      =   7695
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   3000
      TabIndex        =   13
      ToolTipText     =   "Enter the salary"
      Top             =   1200
      Width           =   2055
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   3000
      TabIndex        =   12
      ToolTipText     =   "Enter the Name"
      Top             =   600
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Generate Pay Slip"
      Height          =   495
      Left            =   5760
      TabIndex        =   11
      Top             =   4200
      Width           =   1575
   End
   Begin VB.Label Label11 
      Caption         =   "Basic + DA + HRA + TA"
      Height          =   255
      Left            =   3000
      TabIndex        =   10
      Top             =   3600
      Width           =   1935
   End
   Begin VB.Label Label10 
      Caption         =   "10% of Basic"
      Height          =   255
      Left            =   3000
      TabIndex        =   9
      Top             =   3000
      Width           =   1935
   End
   Begin VB.Label Label9 
      Caption         =   "20% of Basic"
      Height          =   255
      Left            =   3000
      TabIndex        =   8
      Top             =   2400
      Width           =   1935
   End
   Begin VB.Label Label8 
      Caption         =   "40% of Basic"
      Height          =   255
      Left            =   3000
      TabIndex        =   7
      Top             =   1800
      Width           =   1935
   End
   Begin VB.Label Label7 
      Caption         =   "Total Salary:"
      Height          =   255
      Left            =   240
      TabIndex        =   6
      Top             =   3600
      Width           =   1935
   End
   Begin VB.Label Label6 
      Caption         =   "TA:"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   3000
      Width           =   1935
   End
   Begin VB.Label Label5 
      Caption         =   "HRA:"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   2400
      Width           =   1935
   End
   Begin VB.Label Label4 
      Caption         =   "DA:"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   1800
      Width           =   1935
   End
   Begin VB.Label Label3 
      Caption         =   "Basic Salary:"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1200
      Width           =   1935
   End
   Begin VB.Label Label2 
      Caption         =   "Employee Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   1935
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "ABC Company"
      Height          =   255
      Left            =   3360
      TabIndex        =   0
      Top             =   0
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form2.Label12.Caption = Text1.Text
Form2.Label13.Caption = Text2.Text
Form2.Show
End Sub
Private Sub Text2_Change()
Form2.Label8.Caption = 0.4 * Val(Text2.Text)
Form2.Label9.Caption = 0.2 * Val(Text2.Text)
Form2.Label10.Caption = 0.1 * Val(Text2.Text)
Form2.Label11.Caption = Val(Form2.Label8.Caption) + Val(Form2.Label9.Caption) + Val(Form2.Label10.Caption)
End Sub
