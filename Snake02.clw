; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSnakStatic
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Snake02.h"

ClassCount=4
Class1=CSnake02App
Class2=CSnake02Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CSnakStatic
Resource3=IDD_SNAKE02_DIALOG

[CLS:CSnake02App]
Type=0
HeaderFile=Snake02.h
ImplementationFile=Snake02.cpp
Filter=W
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CSnake02App

[CLS:CSnake02Dlg]
Type=0
HeaderFile=Snake02Dlg.h
ImplementationFile=Snake02Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSnake02Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Snake02Dlg.h
ImplementationFile=Snake02Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SNAKE02_DIALOG]
Type=1
Class=CSnake02Dlg
ControlCount=4
Control1=IDOK,button,1342242816
Control2=IDC_COURTY,static,1342374144
Control3=ID_BEGIN,button,1342242816
Control4=ID_STOP,button,1342242816

[CLS:CSnakStatic]
Type=0
HeaderFile=SnakStatic.h
ImplementationFile=SnakStatic.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CSnakStatic

