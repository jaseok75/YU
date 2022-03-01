
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "CDCLab.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for (int i = 0; i < cnt; i++)
	{
		if (rect[i].left == '\0')
			continue;
		dc.Rectangle(rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnLButtonDown(nFlags, point);

	CClientDC dc(this);
	rect[cnt].left = point.x - 20;
	rect[cnt].top = point.y - 20;
	rect[cnt].right = point.x + 20;
	rect[cnt].bottom = point.y + 20;
	dc.Ellipse(rect[cnt].left, rect[cnt].top, rect[cnt].right, rect[cnt].bottom);
	cnt += 1;
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnRButtonDown(nFlags, point);

	CClientDC dc(this);
	dc.SetROP2(R2_WHITE);
	/*CBrush brush(RGB(255, 0, 0));
	CBrush *pOldBrush = dc.SelectObject(&brush);*/
	int flag = 0;

	for (int i = cnt - 1; i >= 0; i--)
	{
		if ((point.x >= rect[i].left) && (point.x <= rect[i].right) && (point.y <= rect[i].bottom) && (point.y >= rect[i].top))
		{
			dc.Ellipse(rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
			rect[i].left = '\0';
			rect[i].top = '\0';
			rect[i].right = '\0';
			rect[i].bottom = '\0';
			flag = 1;
			break;
		}
	}

	dc.SetROP2(R2_COPYPEN);

	for (int i = 0; i < cnt; i++)
	{
		if (rect[i].left == '\0')
			continue;
		dc.Ellipse(rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
	}

	/*CWnd::Invalidate(TRUE);

	for (int i = 0; i < cnt; i++)
	{
		if ((point.x >= rect[i].left) && (point.x <= rect[i].right) && (point.y <= rect[i].bottom) && (point.y >= rect[i].top))
			continue;
		dc.Rectangle(rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
	}*/
}
