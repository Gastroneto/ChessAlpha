
// ������� a1Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "������� a1.h"
#include "������� a1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� C�������a1Dlg



C�������a1Dlg::C�������a1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_A1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�������a1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�������a1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()	ON_BN_CLICKED(IDC_STARTGAME, &C�������a1Dlg::OnBnClickedStartgame)
	ON_BN_CLICKED(IDC_RESTART, &C�������a1Dlg::OnBnClickedRestart)
END_MESSAGE_MAP()


// ����������� ��������� C�������a1Dlg

BOOL C�������a1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	mybmp_wnd.Create(_T("My Static"), WS_CHILD | WS_VISIBLE | SS_BITMAP,
		CRect(0, 0, 100, 100), this);
	bitmap.Load(L"C://Users//1//Desktop//chess//square2Jpeg.jpg");
	mybmp_wnd.SetBitmap(bitmap);
	set_start_pos(Square);
	whos_turn = white;
	for (int i = 0; i < 27; i++) {
		turns[i] = { 9, 9};
	}
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void C�������a1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void C�������a1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR C�������a1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�������a1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	//dc->SelectObject(pen1);
	CPoint pt;
	dc = mybmp_wnd.GetDC();
	if (is_in(point)) { //���� ������� � ����
		pt = get_place(point);
			if (!is_taken && (Square[pt.y][pt.x].color_of_fig == whos_turn)) { //���� �� ������� - ����� ��������� ������
				StartPoint = pt;

				is_taken = 1;
			}
			else
			{
				FinishPoint = pt;
				if (Square[FinishPoint.y][FinishPoint.x].color_of_fig != Square[StartPoint.y][StartPoint.x].color_of_fig) {//���� ����� �� �� ��� ����
					is_taken = 0;
				}
				else {
					StartPoint = FinishPoint;
					for (int i = 0; i < 27; i++) {
						if (turns[i].x == 9)
							break;
						paint_fig(dc, Square[turns[i].y][turns[i].x].fig, turns[i]); //������ ���� ��, ��� ����
						turns[i] = { 9,9 };
					}
				}
			}

			if (is_taken) { //������ �����, ���� �����
				Get_turns(StartPoint, Square, turns);
				show_moves(dc, turns);
			}
			else { //���� ��������� ������ �����.
				if (can_we_move(FinishPoint, turns)) {
					move(Square, StartPoint, FinishPoint); //���������� ������
					draw_move(dc, Square, StartPoint, FinishPoint); //������ ���
					whos_turn = !(whos_turn - 1)+1;
				}
				//��������
				for (int i = 0; i < 27; i++) {
					if (turns[i].x == 9)
						break;
					paint_fig(dc, Square[turns[i].y][turns[i].x].fig, turns[i]); //������ ���� ������
					turns[i] = { 9 ,9 };
				}


			}
			if (whos_turn == black) {
				CPoint turn[2];
				int res=get_bot_turn(Square, turn, black);
				move(Square, turn[0], turn[1]);
				draw_move(dc, Square, turn[0], turn[1]); //������ ���
				whos_turn = !(whos_turn - 1) + 1;
				if (abs(res) > 9000) {
					MessageBoxW(L"����� ����", L"������� �� ����");
					OnBnClickedRestart();
				}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void C�������a1Dlg::OnBnClickedStartgame()
{
	dc = mybmp_wnd.GetDC();
	CPoint pt;
	for (pt.y = 0; pt.y < 8; pt.y++) {
		for (pt.x = 0; pt.x < 8; pt.x++) {
			paint_fig(dc, ' ' , pt);
			paint_fig(dc, Square[pt.y][pt.x].fig, pt); //������ ���� ������
		}
	}
	// TODO: �������� ���� ��� ����������� �����������
}


void C�������a1Dlg::OnBnClickedRestart()
{
	set_start_pos(Square);
	OnBnClickedStartgame();
	// TODO: �������� ���� ��� ����������� �����������
}
