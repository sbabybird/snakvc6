// SnakStatic.cpp : implementation file
//

#include "stdafx.h"
#include "Snake02.h"
#include "SnakStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnakStatic

const int IMAGESIZE = 16;
const int S_UP = 0;
const int S_DOWN = 1;
const int S_LEFT = 2;
const int S_RIGHT = 3;

CSnakStatic::CSnakStatic()
{
	//设置随机数种子
	srand((unsigned)time(NULL));

	m_BodyBitmap.LoadBitmap(IDB_FOOD1);

	m_FoodBitmap.LoadBitmap(IDB_FOOD1);
}

CSnakStatic::~CSnakStatic()
{
}


BEGIN_MESSAGE_MAP(CSnakStatic, CWnd)
	//{{AFX_MSG_MAP(CSnakStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakStatic message handlers

BOOL CSnakStatic::OnEraseBkgnd(CDC* pDC) 
{
	return NULL;
}

void CSnakStatic::KeyDown(int iKeyCode)
{
	switch(iKeyCode) 
	{
		case VK_UP:
		{
			if (m_Arrow != S_DOWN)
				m_Arrow = S_UP;
			break;
		}
	
		case VK_DOWN:
		{
			if (m_Arrow != S_UP)
				m_Arrow = S_DOWN;
			break;
		}
		case VK_LEFT:
		{
			if (m_Arrow != S_RIGHT)
				m_Arrow = S_LEFT;
			break;
		}
		case VK_RIGHT:
		{
			if (m_Arrow != S_LEFT)
				m_Arrow = S_RIGHT;
			break;
		}
	
		default: break;
	}
}

void CSnakStatic::Begin()
{
	InitGame();

	this->SetFocus();
	
	SetTimer(1, 200, NULL);
}

void CSnakStatic::Stop()
{
	KillTimer(1);
}

void CSnakStatic::OnPaint() 
{
	CPaintDC dc(this);

	CRect clientrect;

	GetClientRect(&clientrect);

	CDC memdc;

	CBitmap membitmap;
	
	membitmap.CreateCompatibleBitmap(&dc, clientrect.Width(), clientrect.Height());

	memdc.CreateCompatibleDC(&dc);

	memdc.SelectObject(&membitmap);

	memdc.FillSolidRect(&clientrect, RGB(255, 255, 255));

	DrawSnake(&memdc);

	dc.BitBlt(0, 0, clientrect.Width(), clientrect.Height(), &memdc, 0, 0, SRCCOPY);
}

void CSnakStatic::DrawSnake(CDC* dc)
{
	CDC snakdc;

	snakdc.CreateCompatibleDC(dc);

	snakdc.SelectObject(&m_BodyBitmap);
	
	for (int i = 0; i<m_BodyArr.GetSize(); i++)
	{
		_SNAKE a = m_BodyArr.GetAt(i);

		if (a.t == 0)
		{
			dc->StretchBlt(a.x*IMAGESIZE, a.y*IMAGESIZE, IMAGESIZE,IMAGESIZE,&snakdc,0,0,32,32,SRCCOPY);
		}
	}

	snakdc.SelectObject(&m_FoodBitmap);

	for (i = 0; i<m_FoodArr.GetSize(); i++)
	{
		_SNAKE a = m_FoodArr.GetAt(i);

		if (a.t == 0)
		{
			dc->StretchBlt(a.x*IMAGESIZE, a.y*IMAGESIZE, IMAGESIZE,IMAGESIZE,&snakdc,0,0,32,32,SRCCOPY);
		}
	}
}

void CSnakStatic::OnDestroy() 
{
	KillTimer(1);
	
	CWnd::OnDestroy();	
}

void CSnakStatic::OnTimer(UINT nIDEvent) 
{
	CreateFood();

	Promsta();
	
	this->Invalidate();
	
	CWnd::OnTimer(nIDEvent);
}

void CSnakStatic::InitGame()
{
	m_BodyArr.RemoveAll();

	m_FoodArr.RemoveAll();

	_SNAKE a(1, 1, 0);

	m_BodyArr.InsertAt(0, a);

	a.y = 2;
	m_BodyArr.InsertAt(0, a);

	a.y = 3;
	m_BodyArr.InsertAt(0, a);

	m_Arrow = S_DOWN;
}

void CSnakStatic::Promsta()
{
	if (m_BodyArr.GetSize()>0)
	{
		_SNAKE cur = m_BodyArr.GetAt(0);
	
		int x,y;
		
		switch (m_Arrow)
		{
		case S_UP:
			x = cur.x;
			y = cur.y-1;
			break;
		case S_DOWN:
			x = cur.x;
			y = cur.y+1;
			break;
		case S_LEFT:
			x = cur.x-1;
			y = cur.y;
			break;
		case S_RIGHT:
			x = cur.x+1;
			y = cur.y;
		default: break;
		}

		CRect rect;
		
		GetClientRect(&rect);
		
		if (x<0)
		{
			x = x+rect.Width()/IMAGESIZE;
		}
		else
		{
			x = x%(rect.Width()/IMAGESIZE);
		}
		
		if (y<0)
		{
			y = y+ rect.Height()/IMAGESIZE;
		}
		else
		{
			y = y%(rect.Height()/IMAGESIZE);
		}
		
		_SNAKE a(x, y, 0);
		
		m_BodyArr.InsertAt(0, a);
		
		cur = m_FoodArr.GetAt(0);
		
		if (cur.x == x && cur.y == y)
		{
			m_FoodArr.RemoveAt(0);
		}
		else
		{
			m_BodyArr.RemoveAt(m_BodyArr.GetSize()-1);
		}
	}
}

void CSnakStatic::CreateFood()
{
	if (m_FoodArr.GetSize()<1)
	{
		int x = rand();

		int y = rand();

		CRect rect;

		GetClientRect(&rect);

		if (x<0)
		{
			x = x+rect.Width()/IMAGESIZE;
		}
		else
		{
			x = x%(rect.Width()/IMAGESIZE);
		}
		
		if (y<0)
		{
			y = y+ rect.Height()/IMAGESIZE;
		}
		else
		{
			y = y%(rect.Height()/IMAGESIZE);
		}

		_SNAKE a(x, y, 0);

		m_FoodArr.InsertAt(0, a);
	}
}

BOOL CSnakStatic::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		KeyDown(pMsg->wParam);
		
		return TRUE;
	}
	
	return CWnd::PreTranslateMessage(pMsg);
}
