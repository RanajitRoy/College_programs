VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Notepad"
   ClientHeight    =   7530
   ClientLeft      =   150
   ClientTop       =   780
   ClientWidth     =   13395
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   7530
   ScaleWidth      =   13395
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   12960
      Top             =   -120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox Text1 
      Height          =   7575
      Left            =   0
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   0
      Width           =   13455
   End
   Begin VB.Menu FileM 
      Caption         =   "File"
      Begin VB.Menu OpenM 
         Caption         =   "Open..."
         Shortcut        =   ^O
      End
      Begin VB.Menu Newm 
         Caption         =   "New..."
         Shortcut        =   ^N
      End
      Begin VB.Menu SaveasM 
         Caption         =   "Save As"
         Shortcut        =   ^S
      End
      Begin VB.Menu ExitM 
         Caption         =   "Exit"
         Shortcut        =   ^Q
      End
   End
   Begin VB.Menu HelpM 
      Caption         =   "Help"
      Begin VB.Menu AboutM 
         Caption         =   "About"
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub AboutM_Click()
Call MsgBox("Created by Ranajit Roy...", vbOKOnly, "About")
End Sub

Private Sub ExitM_Click()
Unload Me
End Sub

Private Sub Form_Load()
Form1.Caption = "Notepad - New Text Doc"
End Sub

Private Sub Newm_Click()
Text.Text = ""
Form1.Caption = "Notepad - New Text Doc"
End Sub

Private Sub OpenM_Click()
Dim a As String
CommonDialog1.Filter = "Text File (*.txt)|*.txt"
CommonDialog1.ShowOpen
Form1.Caption = "Notepad - " + CommonDialog1.FileTitle
Open CommonDialog1.FileName For Input As #1
Text1.Text = ""
Do
Input #1, a
Text1.Text = Text1.Text + a + vbCrLf
Loop Until EOF(1)
Close #1
End Sub

Private Sub SaveasM_Click()
CommonDialog1.Filter = "Text File (*.txt)|*.txt"
CommonDialog1.ShowOpen
Open CommonDialog1.FileName For Output As #1
Print #1, Text1.Text
Close #1
End Sub
