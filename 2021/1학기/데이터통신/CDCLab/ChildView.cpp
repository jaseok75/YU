
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	for (int i = 0; i < cnt; i++)
	{
		if (rect[i].left == '\0')
			continue;
		dc.Rectangle(rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
	}
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
