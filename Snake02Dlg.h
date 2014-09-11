// Snake02Dlg.h : header file
//

#if !defined(AFX_SNAKE02DLG_H__902B937D_8351_492C_B0E4_C647EDEA823B__INCLUDED_)
#define AFX_SNAKE02DLG_H__902B937D_8351_492C_B0E4_C647EDEA823B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SnakStatic.h"

/////////////////////////////////////////////////////////////////////////////
// CSnake02Dlg dialog

class CSnake02Dlg : public CDialog
{
// Construction
public:
	CSnake02Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSnake02Dlg)
	enum { IDD = IDD_SNAKE02_DIALOG };
	CSnakStatic	m_SnakCourty;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnake02Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSnake02Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBegin();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKE02DLG_H__902B937D_8351_492C_B0E4_C647EDEA823B__INCLUDED_)
