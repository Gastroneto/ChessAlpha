
// шахматы a1Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "шахматы a1.h"
#include "шахматы a1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно Cшахматыa1Dlg



Cшахматыa1Dlg::Cшахматыa1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_A1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cшахматыa1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cшахматыa1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()	ON_BN_CLICKED(IDC_STARTGAME, &Cшахматыa1Dlg::OnBnClickedStartgame)
	ON_BN_CLICKED(IDC_RESTART, &Cшахматыa1Dlg::OnBnClickedRestart)
END_MESSAGE_MAP()


// обработчики сообщений Cшахматыa1Dlg

BOOL Cшахматыa1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	mybmp_wnd.Create(_T("My Static"), WS_CHILD | WS_VISIBLE | SS_BITMAP,
		CRect(0, 0, 100, 100), this);
	bitmap.Load(L"C://Users//1//Desktop//chess//square2Jpeg.jpg");
	mybmp_wnd.SetBitmap(bitmap);
	set_start_pos(Square);
	whos_turn = white;
	for (int i = 0; i < 27; i++) {
		turns[i] = { 9, 9};
	}
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Cшахматыa1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Cшахматыa1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Cшахматыa1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cшахматыa1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	//dc->SelectObject(pen1);
	CPoint pt;
	dc = mybmp_wnd.GetDC();
	if (is_in(point)) { //если нажатие в поле
		pt = get_place(point);
			if (!is_taken && (Square[pt.y][pt.x].color_of_fig == whos_turn)) { //если не трогали - задаём стартовую фигуру
				StartPoint = pt;

				is_taken = 1;
			}
			else
			{
				FinishPoint = pt;
				if (Square[FinishPoint.y][FinishPoint.x].color_of_fig != Square[StartPoint.y][StartPoint.x].color_of_fig) {//если ходим не на наш цвет
					is_taken = 0;
				}
				else {
					StartPoint = FinishPoint;
					for (int i = 0; i < 27; i++) {
						if (turns[i].x == 9)
							break;
						paint_fig(dc, Square[turns[i].y][turns[i].x].fig, turns[i]); //ставим сюда то, что было
						turns[i] = { 9,9 };
					}
				}
			}

			if (is_taken) { //рисуем точки, если взяли
				Get_turns(StartPoint, Square, turns);
				show_moves(dc, turns);
			}
			else { //если поставить фигуру можно.
				if (can_we_move(FinishPoint, turns)) {
					move(Square, StartPoint, FinishPoint); //перемещаем фигуру
					draw_move(dc, Square, StartPoint, FinishPoint); //рисуем ход
					whos_turn = !(whos_turn - 1)+1;
				}
				//обнуляем
				for (int i = 0; i < 27; i++) {
					if (turns[i].x == 9)
						break;
					paint_fig(dc, Square[turns[i].y][turns[i].x].fig, turns[i]); //ставим сюда фигуру
					turns[i] = { 9 ,9 };
				}


			}
			if (whos_turn == black) {
				CPoint turn[2];
				int res=get_bot_turn(Square, turn, black);
				move(Square, turn[0], turn[1]);
				draw_move(dc, Square, turn[0], turn[1]); //рисуем ход
				whos_turn = !(whos_turn - 1) + 1;
				if (abs(res) > 9000) {
					MessageBoxW(L"Конец игры", L"Спасибо за игру");
					OnBnClickedRestart();
				}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void Cшахматыa1Dlg::OnBnClickedStartgame()
{
	dc = mybmp_wnd.GetDC();
	CPoint pt;
	for (pt.y = 0; pt.y < 8; pt.y++) {
		for (pt.x = 0; pt.x < 8; pt.x++) {
			paint_fig(dc, ' ' , pt);
			paint_fig(dc, Square[pt.y][pt.x].fig, pt); //ставим сюда фигуру
		}
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void Cшахматыa1Dlg::OnBnClickedRestart()
{
	set_start_pos(Square);
	OnBnClickedStartgame();
	// TODO: добавьте свой код обработчика уведомлений
}
