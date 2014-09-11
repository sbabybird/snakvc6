// Snake02.h : main header file for the SNAKE02 application
//

#if !defined(AFX_SNAKE02_H__DE948D18_BB2B_4A33_ACD6_BE387AEA0762__INCLUDED_)
#define AFX_SNAKE02_H__DE948D18_BB2B_4A33_ACD6_BE387AEA0762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnake02App:
// See Snake02.cpp for the implementation of this class
//

class CSnake02App : public CWinApp
{
public:
	CSnake02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnake02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSnake02App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKE02_H__DE948D18_BB2B_4A33_ACD6_BE387AEA0762__INCLUDED_)
