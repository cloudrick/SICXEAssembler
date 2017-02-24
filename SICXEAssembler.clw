; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SICXEAssembler.h"
LastPage=0

ClassCount=7
Class1=CSICXEAssemblerApp
Class2=CSICXEAssemblerDoc
Class3=CSICXEAssemblerView
Class4=CMainFrame

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDR_DLGVIEW_TMPL
Resource3=IDR_DLGVIEW_TMPL (Chinese (Taiwan))
Resource4=IDR_MAINFRAME (Chinese (Taiwan))
Resource5=IDD_ABOUTBOX (Chinese (Taiwan))
Class5=CAboutDlg
Class6=CDlgView
Class7=CSplashWnd
Resource6=IDD_DLGVIEW_FORM (Chinese (Taiwan))
Resource7=IDD_ABOUTBOX
Resource8=IDD_DLGVIEW_FORM

[CLS:CSICXEAssemblerApp]
Type=0
HeaderFile=SICXEAssembler.h
ImplementationFile=SICXEAssembler.cpp
Filter=N

[CLS:CSICXEAssemblerDoc]
Type=0
HeaderFile=SICXEAssemblerDoc.h
ImplementationFile=SICXEAssemblerDoc.cpp
Filter=N
LastObject=CSICXEAssemblerDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CSICXEAssemblerView]
Type=0
HeaderFile=SICXEAssemblerView.h
ImplementationFile=SICXEAssemblerView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC
LastObject=CSICXEAssemblerView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=SICXEAssembler.cpp
ImplementationFile=SICXEAssembler.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_MENUPASS1
Command16=ID_MENUPASS2
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME (Chinese (Taiwan))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (Chinese (Taiwan))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_MENUPASS1
Command16=ID_MENUPASS2
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME (Chinese (Taiwan))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (Chinese (Taiwan))]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_DLGVIEW_FORM (Chinese (Taiwan))]
Type=1
Class=CDlgView
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LIST1,SysListView32,1350631429
Control3=IDC_LIST2,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350633600
Control7=IDC_EDIT2,edit,1350633668
Control8=IDC_STATIC,static,1342308352

[CLS:CDlgView]
Type=0
HeaderFile=DlgView.h
ImplementationFile=DlgView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=VWC

[MNU:IDR_DLGVIEW_TMPL (Chinese (Taiwan))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd

[MNU:IDR_DLGVIEW_TMPL]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[DLG:IDD_DLGVIEW_FORM]
Type=1
Class=?
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LIST1,SysListView32,1350631429
Control3=IDC_LIST2,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350633600
Control7=IDC_EDIT2,edit,1350633668
Control8=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

