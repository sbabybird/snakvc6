#if !defined(AFX_SNAKSTATIC_H__67448EEE_1B2D_4713_AD58_EE0CAA225754__INCLUDED_)
#define AFX_SNAKSTATIC_H__67448EEE_1B2D_4713_AD58_EE0CAA225754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SnakStatic.h : header file
//
#include "Afxtempl.h"
/////////////////////////////////////////////////////////////////////////////
// CSnakStatic window

class CSnakStatic : public CWnd
{
	typedef struct _SNAKE
	{
		_SNAKE()
		{
			x = 0;
			y = 0; 
			t = 0;
		}
		
		_SNAKE(int a, int b, int c)
		{
			x = a;
			y = b;
			t = c;
		}
		
		int x;
		int y;
		int t;
	}SNAKE;
// Construction
public:
	CSnakStatic();

// Attributes
public:

// Operations
public:
	void Begin();
	void Stop();
	void KeyDown(int iKeyCode);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakStatic)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnakStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSnakStatic)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CBitmap m_FoodBitmap;

	CBitmap m_BodyBitmap;

	CArray<_SNAKE,_SNAKE> m_BodyArr;

	CArray<_SNAKE,_SNAKE> m_FoodArr;

	int m_Arrow;

private:
	void DrawSnake(CDC* dc);

	void InitGame();

	void Promsta();

	void CreateFood();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKSTATIC_H__67448EEE_1B2D_4713_AD58_EE0CAA225754__INCLUDED_)
