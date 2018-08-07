VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2355
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4530
   LinkTopic       =   "Form1"
   ScaleHeight     =   2355
   ScaleWidth      =   4530
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text3 
      Alignment       =   1  'Right Justify
      Height          =   495
      Left            =   3240
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   720
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1200
      MultiLine       =   -1  'True
      TabIndex        =   2
      Top             =   720
      Width           =   1815
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   360
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   720
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Read"
      Height          =   495
      Left            =   1560
      TabIndex        =   0
      Top             =   1560
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Department:"
      Height          =   255
      Left            =   3240
      TabIndex        =   6
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "Student Name:"
      Height          =   255
      Left            =   1200
      TabIndex        =   5
      Top             =   360
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "Roll:"
      Height          =   255
      Left            =   360
      TabIndex        =   4
      Top             =   360
      Width           =   615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim conn As New ADODB.Connection
Dim rs As New ADODB.Recordset
Dim sqlStr As String

Private Sub Command1_Click()
rs.Open (sqlStr), conn, adOpenStatic, adLockReadOnly
rs.Filter = "Department like 'IT'"
Text1.Text = rs.Fields("Roll")
Text2.Text = rs.Fields("Student Name")
Text3.Text = rs.Fields("Department")
rs.Close
End Sub

Private Sub Form_Load()
sqlStr = "select * from Student"
conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0.;Data Source=C:\Users\royra\Google Drive\IEM programs\4th SEM\Software Tools\Week 8\Database.mdb;Persist Security Info=False"
conn.Open
End Sub
