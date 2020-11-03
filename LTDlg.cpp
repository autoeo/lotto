// LTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LT.h"
#include "LTDlg.h"
#include "DlgGetNumberList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define C_FUNCTION_SET_OPTION(x)	\
	if( m_bOption##x )\
		dwOptions |= C_FLAGS_OPTION_##x

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strInfoFrom;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_strInfoFrom = _T("필터 자료 출처 : http://blog.naver.com/ads226/221382960435");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_EDT_LABEL, m_strInfoFrom);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLTDlg dialog

CLTDlg::CLTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLTDlg::IDD, pParent) 


{
	//{{AFX_DATA_INIT(CLTDlg)
	m_nParam_01 = 0;
	m_nParam_02 = 0;
	m_nParam_03 = 0;
	m_nTotalListCount = 0;
	m_bOption1 = TRUE;
	m_bOption2 = TRUE;
	m_bOption3 = TRUE;
	m_bOption4 = TRUE;
	m_bOption5 = TRUE;
	m_bOption6 = TRUE;
	m_bOption7 = TRUE;
	m_bOption8 = TRUE;
	m_bOption9 = TRUE;
	m_bOption10 = TRUE;
	m_bOption11 = TRUE;
	m_nLessNum = 80;
	m_nOverNum = 201;
	m_nIncludeNumber_1 = 0;
	m_nIncludeNumber_2 = 0;
	m_nIncludeNumber_3 = 0;
	m_strFilterInfoFrom = _T("필터 자료 출처 : \r\n-> http://blog.naver.com/ads226/221382960435");
	m_bChkEnableRecentThNumber = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_logFont.lfWidth = 0;
	m_logFont.lfHeight = 24;
	m_logFont.lfEscapement = 0;
	m_logFont.lfOrientation = 0;
	m_logFont.lfWeight = FW_BOLD;
	m_logFont.lfItalic = 0;
	m_logFont.lfUnderline = 0;
	m_logFont.lfStrikeOut = 0 ;
	m_logFont.lfCharSet = ANSI_CHARSET;
	m_logFont.lfOutPrecision = OUT_STROKE_PRECIS;
	m_logFont.lfClipPrecision = CLIP_STROKE_PRECIS;
	m_logFont.lfQuality = PROOF_QUALITY;
	m_logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_SWISS;
	lstrcpy((LPSTR)m_logFont.lfFaceName, "맑은 고딕");
	
	m_font_Normal.CreateFontIndirect(&m_logFont);

	m_logFont.lfHeight = 32;
	m_font_Large.CreateFontIndirect(&m_logFont);
}

void CLTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLTDlg)
	DDX_Control(pDX, IDC_CMB_RECENT_TH_NUMBER, m_ctrlCmbRecentThNumber);
	DDX_Control(pDX, IDC_LIST_NUMBER, m_ctrlListNumAll);
	DDX_Control(pDX, IDC_LIST_NUM_COUNT, m_ctrlListNumCount);
	DDX_Text(pDX, IDC_EDT_PARAM_01, m_nParam_01);
	DDV_MinMaxUInt(pDX, m_nParam_01, 0, 45);
	DDX_Text(pDX, IDC_EDT_PARAM_02, m_nParam_02);
	DDV_MinMaxUInt(pDX, m_nParam_02, 0, 45);
	DDX_Text(pDX, IDC_EDT_PARAM_03, m_nParam_03);
	DDV_MinMaxUInt(pDX, m_nParam_03, 0, 45);
	DDX_Text(pDX, IDC_EDT_TOTAL_COUNT, m_nTotalListCount);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_1, m_bOption1);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_2, m_bOption2);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_3, m_bOption3);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_4, m_bOption4);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_5, m_bOption5);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_6, m_bOption6);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_7, m_bOption7);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_8, m_bOption8);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_9, m_bOption9);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_10, m_bOption10);
	DDX_Check(pDX, IDC_CHK_FILTER_OPTION_11, m_bOption11);
	DDX_Text(pDX, IDC_EDT_LESS_NUM, m_nLessNum);
	DDX_Text(pDX, IDC_EDT_OVER_NUM, m_nOverNum);
	DDX_Text(pDX, IDC_EDT_INCLUDE_NUMBER_1, m_nIncludeNumber_1);
	DDX_Text(pDX, IDC_EDT_INCLUDE_NUMBER_2, m_nIncludeNumber_2);
	DDX_Text(pDX, IDC_EDT_INCLUDE_NUMBER_3, m_nIncludeNumber_3);
	DDX_Text(pDX, IDC_EDT_FILTER_INFO_FROM, m_strFilterInfoFrom);
	DDX_Check(pDX, IDC_CHK_RECENT_TH_NUMBER, m_bChkEnableRecentThNumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLTDlg, CDialog)
	//{{AFX_MSG_MAP(CLTDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GET_MOST_USED, OnBtnGetMostUsed)
	ON_BN_CLICKED(IDC_BTN_GET_INCLUDED, OnBtnGetIncluded)
	ON_BN_CLICKED(IDC_BTN_SORT_BY_SUM, OnBtnSortBySum)
	ON_BN_CLICKED(IDC_BTN_SAVE_RESULT_TO_CSV, OnBtnSaveResultToCsv)
	ON_BN_CLICKED(IDC_BTN_GET_ALL_NUMBER, OnBtnGetAllNumber)
	ON_BN_CLICKED(IDC_BTN_CONVERT_EXCEL_TO_BIN, OnBtnConvertExcelToBin)
	ON_BN_CLICKED(IDC_BTN_SET_EXCEPT_NUMBERS, OnBtnSetExceptNumbers)
	ON_BN_CLICKED(IDC_CHK_FILTER_OPTION_8, OnChkFilterOption8)
	ON_BN_CLICKED(IDC_CHK_RECENT_TH_NUMBER, OnChkRecentThNumber)
	ON_BN_CLICKED(IDC_BTN_SAVE_WITHOUT_RESULT_TO_CSV, OnBtnSaveWithoutResultToCsv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLTDlg message handlers

BOOL CLTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	CWnd* pWnd = GetDlgItem( IDC_EDT_TOTAL_COUNT );
	pWnd->SetFont( &m_font_Large );

	pWnd = GetDlgItem( IDC_BTN_GET_ALL_NUMBER );
	pWnd->SetFont( &m_font_Normal );

	pWnd = GetDlgItem( IDC_STC_LABEL_TOTAL_COUNT );
	pWnd->SetFont( &m_font_Normal );
	

	m_ctrlListNumCount.InitListCtrl_SortOfCount();
	m_ctrlListNumAll.InitListCtrl();

	m_ctrlListNumAll.UpdateListCtrl( &m_stLoader.m_ary );
	m_ctrlCmbRecentThNumber.InitCmbCtrl(0);
	OnChkRecentThNumber();
//	InitExceptNumbers();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLTDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLTDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLTDlg::OnOK() 
{
	
}

void CLTDlg::OnBtnGetMostUsed() 
{
	MapSortNum* pMap = NULL;
	int nCount = GetRecentNumberCount();
	pMap = m_stLoader.GetMaxUsedNum( nCount );	
	m_ctrlListNumCount.UpdateListCtrl( pMap );
}

void CLTDlg::OnBtnGetIncluded() 
{
	MapSortNum* pMap = NULL;

	int nCount = GetRecentNumberCount();

	UpdateData();

	if( m_nParam_01 != 0 && m_nParam_02 != 0 && m_nParam_03 != 0 )
	{
		pMap = m_stLoader.GetMaxIncludedNum( nCount, m_nParam_01, m_nParam_02, m_nParam_03 );
	}
	else if( m_nParam_01 != 0 && m_nParam_02 != 0 && m_nParam_03 == 0 )
	{
		pMap = m_stLoader.GetMaxIncludedNum( nCount, m_nParam_01, m_nParam_02 );
	}
	else if( m_nParam_01 != 0 && m_nParam_02 == 0 && m_nParam_03 == 0 )
	{
		pMap = m_stLoader.GetMaxIncludedNum( nCount, m_nParam_01 );
	}
	else
	{
		m_ctrlListNumCount.DeleteAllItems();
		UpdateData( FALSE );
		return;
	}

	m_ctrlListNumCount.UpdateListCtrl( pMap );
	UpdateData( FALSE );
}

void CLTDlg::OnBtnSortBySum() 
{
	
}


void CLTDlg::OnBtnSaveResultToCsv() 
{
	UpdateData();
	
	CString strFilePath;
	strFilePath = AfxGetApp()->GetProfileString(_T("LT"), _T("LT_SAVE_CSV"), "" );
	TCHAR tszBuffer[260];
	_stprintf(tszBuffer, _T("%s"), (LPTSTR)(LPCTSTR)strFilePath);
	OPENFILENAME OFN;
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = m_hWnd;
	OFN.lpstrFilter = _T("CSV 파일(*.csv 콤파구분)\0*.csv\0");
	OFN.lpstrInitialDir = (LPTSTR)(LPCTSTR)strFilePath;
	OFN.lpstrFile = tszBuffer;
	OFN.nMaxFile = 260;
	OFN.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;
	if (!GetSaveFileName(&OFN))
		return;

	strFilePath = OFN.lpstrFile;
	AfxGetApp()->WriteProfileString(_T("LT"), _T("LT_SAVE_CSV"), OFN.lpstrFile );

	BYTE * pData = NULL;
	AfxGetApp()->BeginWaitCursor();

	pData = new BYTE[ C_INT_FULL_DATA_COUNT * 6 ];

	m_stLoader.SetOption( GetOption() );
	m_stLoader.SetLessNum( m_nLessNum );
	m_stLoader.SetOverNum( m_nOverNum );

	m_nTotalListCount = m_stLoader.CreateAllNumber( pData, C_INT_FULL_DATA_COUNT * 6, FALSE );

	m_stLoader.SaveCSV( strFilePath, pData, m_nTotalListCount );

	delete []pData ;

	AfxGetApp()->EndWaitCursor();
	
	UpdateData(FALSE );
}

void CLTDlg::OnBtnSaveWithoutResultToCsv() 
{
	UpdateData();
	
	CString strFilePath;
	strFilePath = AfxGetApp()->GetProfileString(_T("LT"), _T("LT_SAVE_FILTERED_NUMBER_CSV"), "" );
	TCHAR tszBuffer[260];
	_stprintf(tszBuffer, _T("%s"), (LPTSTR)(LPCTSTR)strFilePath);
	OPENFILENAME OFN;
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = m_hWnd;
	OFN.lpstrFilter = _T("CSV 파일(*.csv 콤파구분)\0*.csv\0");
	OFN.lpstrInitialDir = (LPTSTR)(LPCTSTR)strFilePath;
	OFN.lpstrFile = tszBuffer;
	OFN.nMaxFile = 260;
	OFN.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;
	if (!GetSaveFileName(&OFN))
		return;

	strFilePath = OFN.lpstrFile;
	AfxGetApp()->WriteProfileString(_T("LT"), _T("LT_SAVE_FILTERED_NUMBER_CSV"), OFN.lpstrFile );

	BYTE * pData = NULL;
	AfxGetApp()->BeginWaitCursor();

	pData = new BYTE[ C_INT_FULL_DATA_COUNT * 6 ];

	m_stLoader.SetOption( GetOption() );
	m_stLoader.SetLessNum( m_nLessNum );
	m_stLoader.SetOverNum( m_nOverNum );

	m_nTotalListCount = m_stLoader.CreateAllNumber( pData, C_INT_FULL_DATA_COUNT * 6, TRUE );

	m_stLoader.SaveCSV( strFilePath, pData, m_nTotalListCount );

	delete []pData ;

	AfxGetApp()->EndWaitCursor();
	
	UpdateData(FALSE );
}


void CLTDlg::OnBtnGetAllNumber() 
{
	UpdateData();
	BYTE * pData = NULL;
	AfxGetApp()->BeginWaitCursor();

	pData = new BYTE[ C_INT_FULL_DATA_COUNT * 6 ];

	m_stLoader.SetOption( GetOption() );
	m_stLoader.SetLessNum( m_nLessNum );
	m_stLoader.SetOverNum( m_nOverNum );
	m_stLoader.SetExceptNumbers( m_aryExceptNumbers );

	SetAcceptNumbers();
	m_stLoader.SetAcceptNumbers( m_aryAcceptNumbers );

	m_nTotalListCount = m_stLoader.CreateAllNumber( pData, C_INT_FULL_DATA_COUNT * 6, FALSE );

	m_ctrlListNumAll.DeleteAllItems();
	
	if( m_nTotalListCount <= 30000 )
		m_ctrlListNumAll.UpdateListCtrl( pData, m_nTotalListCount );
	else
		m_ctrlListNumAll.UpdateListCtrl( pData, 1000 );

	delete []pData ;

	AfxGetApp()->EndWaitCursor();

	UpdateData( FALSE );
	
}

void CLTDlg::OnBtnConvertExcelToBin() 
{
	// Select Excel File
	CString strFilePath;
	strFilePath = AfxGetApp()->GetProfileString(_T("LT"), _T("LT_EXCEL_FILE"), "" );
	TCHAR tszBuffer[260];
	_stprintf(tszBuffer, _T("%s"), (LPTSTR)(LPCTSTR)strFilePath);
	OPENFILENAME OFN;
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = m_hWnd;
	OFN.lpstrFilter = _T("Excel 파일(*.xls,*.xlsx)\0*.xls;*.xlsx\0");
	OFN.lpstrInitialDir = (LPTSTR)(LPCTSTR)strFilePath;
	OFN.lpstrFile = tszBuffer;
	OFN.nMaxFile = 260;
	OFN.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;
	if (!GetOpenFileName(&OFN))
		return;

	strFilePath = OFN.lpstrFile;
	AfxGetApp()->WriteProfileString(_T("LT"), _T("LT_EXCEL_FILE"), OFN.lpstrFile );

	AfxGetApp()->BeginWaitCursor();

	m_stLoader.Load( strFilePath );
	m_ctrlCmbRecentThNumber.InitCmbCtrl(m_stLoader.m_ary.GetSize());
	AfxGetApp()->EndWaitCursor();


	
}

DWORD				CLTDlg::GetOption			()
{
	UpdateData();

	DWORD dwOptions = 0;

	C_FUNCTION_SET_OPTION(1);
	C_FUNCTION_SET_OPTION(2);
	C_FUNCTION_SET_OPTION(3);
	C_FUNCTION_SET_OPTION(4);
	C_FUNCTION_SET_OPTION(5);
	C_FUNCTION_SET_OPTION(6);
	C_FUNCTION_SET_OPTION(7);
	C_FUNCTION_SET_OPTION(8);
	C_FUNCTION_SET_OPTION(9);
	C_FUNCTION_SET_OPTION(10);
	C_FUNCTION_SET_OPTION(11);

	return dwOptions;
}

void CLTDlg::SetAcceptNumbers	()
{
	UpdateData();
	m_aryAcceptNumbers.RemoveAll();
	if( m_nIncludeNumber_1 )
		m_aryAcceptNumbers.Add( m_nIncludeNumber_1 );
	if( m_nIncludeNumber_2 )
		m_aryAcceptNumbers.Add( m_nIncludeNumber_2 );
	if( m_nIncludeNumber_3 )
		m_aryAcceptNumbers.Add( m_nIncludeNumber_3 );

}

int CLTDlg::GetRecentNumberCount()
{
	int nCount = m_stLoader.m_ary.GetSize();
	if( m_bChkEnableRecentThNumber == TRUE )
		nCount = m_ctrlCmbRecentThNumber.GetSelectedItemNumber();

	return nCount;
}

void CLTDlg::OnBtnSetExceptNumbers() 
{
	CDlgGetNumberList dlg(this, m_aryExceptNumbers);

	if( dlg.DoModal() != IDOK )
		return;

	m_aryExceptNumbers.RemoveAll();
	m_aryExceptNumbers.Copy( dlg.m_aryBytes );
	
}


void CLTDlg::OnChkFilterOption8() 
{
	UpdateData();
	GetDlgItem( IDC_EDT_INCLUDE_NUMBER_1 )->EnableWindow( m_bOption8 );
	GetDlgItem( IDC_EDT_INCLUDE_NUMBER_2 )->EnableWindow( m_bOption8 );
	GetDlgItem( IDC_EDT_INCLUDE_NUMBER_3 )->EnableWindow( m_bOption8 );
	
}


void CLTDlg::OnChkRecentThNumber() 
{
	UpdateData();
	GetDlgItem( IDC_CMB_RECENT_TH_NUMBER )->EnableWindow( m_bChkEnableRecentThNumber );
	GetDlgItem( IDC_STC_MSG_RECENT_TH_NUMBER )->EnableWindow( m_bChkEnableRecentThNumber );
}

