
// ������� a1Dlg.h : ���� ���������
//

#pragma once
#include "Draw_s.h"
#include "Any_acts.h"
#include "moves.h"
// ���������� ���� C�������a1Dlg
class C�������a1Dlg : public CDialogEx
{
// ��������
public:
	C�������a1Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint StartPoint;
	CPoint FinishPoint;
	bool is_taken=0;
	CStatic mybmp_wnd;
	CImage bitmap;
	square Square[8][8];//���� ����
	CDC *dc;
	int whos_turn; //��� ���
//���������� �� ���������� �� ������.
	CPoint turns[27];//��������� ����.
	afx_msg void OnBnClickedStartgame();
	afx_msg void OnBnClickedRestart();
};
