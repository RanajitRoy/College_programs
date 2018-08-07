VERSION 5.00
Begin VB.MDIForm MDIForm1 
   BackColor       =   &H8000000C&
   Caption         =   "MDIForm1"
   ClientHeight    =   3030
   ClientLeft      =   9570
   ClientTop       =   4515
   ClientWidth     =   4590
   LinkTopic       =   "MDIForm1"
   Begin VB.Menu show1 
      Caption         =   "Show The Form"
   End
End
Attribute VB_Name = "MDIForm1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub show1_Click()
Form1.Show
End Sub
