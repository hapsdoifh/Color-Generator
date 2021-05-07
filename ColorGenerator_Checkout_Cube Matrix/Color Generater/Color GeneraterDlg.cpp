
// Color GeneraterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Color Generater.h"
#include "Color GeneraterDlg.h"
#include "afxdialogex.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CColorGeneraterDlg dialog



CColorGeneraterDlg::CColorGeneraterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COLORGENERATER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColorGeneraterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CColorGeneraterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, &CColorGeneraterDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CColorGeneraterDlg message handlers

BOOL CColorGeneraterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CColorGeneraterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
int G = 63;
void CColorGeneraterDlg::OnPaint()
{
	//Assign start and end positions
	CPaintDC Paintdc(this);
	RECT assignposition;
	RECT DrawingBox;
	CBrush ColorBrush;
	int BoxHeight = 0;
	int BoxWidth = 0;
	int ColorAmt = 64;
	int R = 63, B=63;
	int ColorChange = 63;
	int PaletteHeight = 0;

	GetClientRect(&assignposition); //initializing Color block positions
	BoxHeight = assignposition.bottom / cbrt((double)ColorAmt);
	BoxWidth = assignposition.right / cbrt((double)ColorAmt);
	DrawingBox.right = 0;
	DrawingBox.bottom = 0;
	DrawingBox.top = 0;
	DrawingBox.left = 0;

	if (G > 255) {
		G = 63;
	}
	while (DrawingBox.bottom <= assignposition.bottom && DrawingBox.right <= assignposition.right) {
		while (DrawingBox.right <= assignposition.right) {
			DrawingBox.bottom = DrawingBox.top + BoxHeight;
			DrawingBox.right = DrawingBox.left + BoxWidth;
			ColorBrush.CreateSolidBrush(RGB(R, G, B));
			Paintdc.SelectObject(&ColorBrush);
			Paintdc.Rectangle(&DrawingBox);
			CString str;
			str.Format(_T("%d,"), R);
			Paintdc.TextOutW(DrawingBox.left+10, DrawingBox.top+10,str);
			str.Format(_T("%d,"), G);
			Paintdc.TextOutW(DrawingBox.left + 50, DrawingBox.top + 10, str);
			str.Format(_T("%d,"), B);
			Paintdc.TextOutW(DrawingBox.left + 90, DrawingBox.top + 10, str);
			ColorBrush.DeleteObject();
			DrawingBox.right += BoxWidth;
			DrawingBox.left += BoxWidth;
			R += ColorChange;
		}
		R = 63;
		B += ColorChange;
		DrawingBox.right = 0;
		DrawingBox.left = 0;
		DrawingBox.top += BoxHeight;
	}
	
	int times = 0;

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CColorGeneraterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CColorGeneraterDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	this->Invalidate();
	// TODO: Add your message handler code here
}


void CColorGeneraterDlg::OnBnClickedButton1()
{
	G += 63;
	this->Invalidate();
	// TODO: Add your control notification handler code here
}
