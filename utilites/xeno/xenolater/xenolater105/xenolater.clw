; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "xenolater.h"
LastPage=0

ClassCount=5
Class1=CXenolaterApp
Class2=CXenolaterDoc
Class3=CXenolaterView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CXenolaterApp]
Type=0
HeaderFile=xenolater.h
ImplementationFile=xenolater.cpp
Filter=N

[CLS:CXenolaterDoc]
Type=0
HeaderFile=xenolaterDoc.h
ImplementationFile=xenolaterDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CXenolaterView]
Type=0
HeaderFile=xenolaterView.h
ImplementationFile=xenolaterView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=xenolater.cpp
ImplementationFile=xenolater.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STATIC_SAD

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308481
Control2=IDC_STATIC,static,1342308353
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342181390
Control5=IDC_STATIC,static,1342181390
Control6=IDC_STATIC,static,1342308353
Control7=IDC_STATIC_SAD,static,1342308609
Control8=IDC_STATIC,button,1342177287

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_UNCOMP
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_MODIFICA_SELEZIONATUTTO
Command13=ID_SCRIPT_ESPORTA
Command14=ID_SCRIPT_IMPORTA
Command15=ID_SCRIPT_CONTEGGIOAUTOMATICO
Command16=ID_TABLE_DECODE_DEFAULT
Command17=ID_DECODE_RECENT1
Command18=ID_DECODE_RECENT2
Command19=ID_DECODE_RECENT3
Command20=ID_TABLE_DECODE_OTHER
Command21=ID_TABLE_ENCODE_NONE
Command22=ID_ENCODE_RECENT1
Command23=ID_ENCODE_RECENT2
Command24=ID_ENCODE_RECENT3
Command25=ID_TABLE_ENCODE_OTHER
Command26=ID_VIEW_TOOLBAR
Command27=ID_VIEW_STATUS_BAR
Command28=ID_APP_ABOUT
CommandCount=28

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

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

