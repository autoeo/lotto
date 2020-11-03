// DlgGetNumberList.cpp : implementation file
//

#include "stdafx.h"
#include "LT.h"
#include "DlgGetNumberList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGetNumberList dialog

#define C_FONC_ADD_CHECKED_NUMBER(x,id)	\
	if( m_bNumber_##x ) \
		m_aryBytes.Add( id-IDC_CHK_NUMBER_01+1)

CDlgGetNumberList::CDlgGetNumberList(CWnd* pParent, const CByteArray& ary )
	: CDialog(CDlgGetNumberList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGetNumberList)
	m_bNumber_01 = IsExistNumberInArray( ary, 1 );
	m_bNumber_02 = IsExistNumberInArray( ary, 2 );
	m_bNumber_03 = IsExistNumberInArray( ary, 3 );
	m_bNumber_04 = IsExistNumberInArray( ary, 4 );
	m_bNumber_05 = IsExistNumberInArray( ary, 5 );
	m_bNumber_06 = IsExistNumberInArray( ary, 6 );
	m_bNumber_07 = IsExistNumberInArray( ary, 7 );
	m_bNumber_08 = IsExistNumberInArray( ary, 8 );
	m_bNumber_09 = IsExistNumberInArray( ary, 9 );
	m_bNumber_10 = IsExistNumberInArray( ary, 10 );
	m_bNumber_11 = IsExistNumberInArray( ary, 11 );
	m_bNumber_12 = IsExistNumberInArray( ary, 12 );
	m_bNumber_13 = IsExistNumberInArray( ary, 13 );
	m_bNumber_14 = IsExistNumberInArray( ary, 14 );
	m_bNumber_15 = IsExistNumberInArray( ary, 15 );
	m_bNumber_16 = IsExistNumberInArray( ary, 16 );
	m_bNumber_17 = IsExistNumberInArray( ary, 17 );
	m_bNumber_18 = IsExistNumberInArray( ary, 18 );
	m_bNumber_19 = IsExistNumberInArray( ary, 19 );
	m_bNumber_20 = IsExistNumberInArray( ary, 20 );
	m_bNumber_21 = IsExistNumberInArray( ary, 21 );
	m_bNumber_22 = IsExistNumberInArray( ary, 22 );
	m_bNumber_23 = IsExistNumberInArray( ary, 23 );
	m_bNumber_24 = IsExistNumberInArray( ary, 24 );
	m_bNumber_25 = IsExistNumberInArray( ary, 25 );
	m_bNumber_26 = IsExistNumberInArray( ary, 26 );
	m_bNumber_27 = IsExistNumberInArray( ary, 27 );
	m_bNumber_28 = IsExistNumberInArray( ary, 28 );
	m_bNumber_29 = IsExistNumberInArray( ary, 29 );
	m_bNumber_30 = IsExistNumberInArray( ary, 30 );
	m_bNumber_31 = IsExistNumberInArray( ary, 31 );
	m_bNumber_32 = IsExistNumberInArray( ary, 32 );
	m_bNumber_33 = IsExistNumberInArray( ary, 33 );
	m_bNumber_34 = IsExistNumberInArray( ary, 34 );
	m_bNumber_35 = IsExistNumberInArray( ary, 35 );
	m_bNumber_36 = IsExistNumberInArray( ary, 36 );
	m_bNumber_37 = IsExistNumberInArray( ary, 37 );
	m_bNumber_38 = IsExistNumberInArray( ary, 38 );
	m_bNumber_39 = IsExistNumberInArray( ary, 39 );
	m_bNumber_40 = IsExistNumberInArray( ary, 40 );
	m_bNumber_41 = IsExistNumberInArray( ary, 41 );
	m_bNumber_42 = IsExistNumberInArray( ary, 42 );
	m_bNumber_43 = IsExistNumberInArray( ary, 43 );
	m_bNumber_44 = IsExistNumberInArray( ary, 44 );
	m_bNumber_45 = IsExistNumberInArray( ary, 45 );
	//}}AFX_DATA_INIT

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
	lstrcpy((LPSTR)m_logFont.lfFaceName, "¸¼Àº °íµñ");
	
	m_font_Normal.CreateFontIndirect(&m_logFont);

	m_logFont.lfHeight = 32;
	m_font_Large.CreateFontIndirect(&m_logFont);
}


void CDlgGetNumberList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGetNumberList)
	DDX_Check(pDX, IDC_CHK_NUMBER_01, m_bNumber_01);
	DDX_Check(pDX, IDC_CHK_NUMBER_02, m_bNumber_02);
	DDX_Check(pDX, IDC_CHK_NUMBER_03, m_bNumber_03);
	DDX_Check(pDX, IDC_CHK_NUMBER_04, m_bNumber_04);
	DDX_Check(pDX, IDC_CHK_NUMBER_05, m_bNumber_05);
	DDX_Check(pDX, IDC_CHK_NUMBER_06, m_bNumber_06);
	DDX_Check(pDX, IDC_CHK_NUMBER_07, m_bNumber_07);
	DDX_Check(pDX, IDC_CHK_NUMBER_08, m_bNumber_08);
	DDX_Check(pDX, IDC_CHK_NUMBER_09, m_bNumber_09);
	DDX_Check(pDX, IDC_CHK_NUMBER_10, m_bNumber_10);
	DDX_Check(pDX, IDC_CHK_NUMBER_11, m_bNumber_11);
	DDX_Check(pDX, IDC_CHK_NUMBER_12, m_bNumber_12);
	DDX_Check(pDX, IDC_CHK_NUMBER_13, m_bNumber_13);
	DDX_Check(pDX, IDC_CHK_NUMBER_14, m_bNumber_14);
	DDX_Check(pDX, IDC_CHK_NUMBER_15, m_bNumber_15);
	DDX_Check(pDX, IDC_CHK_NUMBER_16, m_bNumber_16);
	DDX_Check(pDX, IDC_CHK_NUMBER_17, m_bNumber_17);
	DDX_Check(pDX, IDC_CHK_NUMBER_18, m_bNumber_18);
	DDX_Check(pDX, IDC_CHK_NUMBER_19, m_bNumber_19);
	DDX_Check(pDX, IDC_CHK_NUMBER_20, m_bNumber_20);
	DDX_Check(pDX, IDC_CHK_NUMBER_21, m_bNumber_21);
	DDX_Check(pDX, IDC_CHK_NUMBER_22, m_bNumber_22);
	DDX_Check(pDX, IDC_CHK_NUMBER_23, m_bNumber_23);
	DDX_Check(pDX, IDC_CHK_NUMBER_24, m_bNumber_24);
	DDX_Check(pDX, IDC_CHK_NUMBER_25, m_bNumber_25);
	DDX_Check(pDX, IDC_CHK_NUMBER_26, m_bNumber_26);
	DDX_Check(pDX, IDC_CHK_NUMBER_27, m_bNumber_27);
	DDX_Check(pDX, IDC_CHK_NUMBER_28, m_bNumber_28);
	DDX_Check(pDX, IDC_CHK_NUMBER_29, m_bNumber_29);
	DDX_Check(pDX, IDC_CHK_NUMBER_30, m_bNumber_30);
	DDX_Check(pDX, IDC_CHK_NUMBER_31, m_bNumber_31);
	DDX_Check(pDX, IDC_CHK_NUMBER_32, m_bNumber_32);
	DDX_Check(pDX, IDC_CHK_NUMBER_33, m_bNumber_33);
	DDX_Check(pDX, IDC_CHK_NUMBER_34, m_bNumber_34);
	DDX_Check(pDX, IDC_CHK_NUMBER_35, m_bNumber_35);
	DDX_Check(pDX, IDC_CHK_NUMBER_36, m_bNumber_36);
	DDX_Check(pDX, IDC_CHK_NUMBER_37, m_bNumber_37);
	DDX_Check(pDX, IDC_CHK_NUMBER_38, m_bNumber_38);
	DDX_Check(pDX, IDC_CHK_NUMBER_39, m_bNumber_39);
	DDX_Check(pDX, IDC_CHK_NUMBER_40, m_bNumber_40);
	DDX_Check(pDX, IDC_CHK_NUMBER_41, m_bNumber_41);
	DDX_Check(pDX, IDC_CHK_NUMBER_42, m_bNumber_42);
	DDX_Check(pDX, IDC_CHK_NUMBER_43, m_bNumber_43);
	DDX_Check(pDX, IDC_CHK_NUMBER_44, m_bNumber_44);
	DDX_Check(pDX, IDC_CHK_NUMBER_45, m_bNumber_45);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGetNumberList, CDialog)
	//{{AFX_MSG_MAP(CDlgGetNumberList)
	ON_BN_CLICKED(IDC_BTN_SELECT_ALL, OnBtnSelectAll)
	ON_BN_CLICKED(IDC_BTN_DESELECT_ALL, OnBtnDeselectAll)
	ON_BN_CLICKED(IDC_BTN_SELECT_ODD_NUMBER, OnBtnSelectOddNumber)
	ON_BN_CLICKED(IDC_BTN_DESELECT_ODD_NUMBER, OnBtnDeselectOddNumber)
	ON_BN_CLICKED(IDC_BTN_SELECT_EVEN_NUMBER, OnBtnSelectEvenNumber)
	ON_BN_CLICKED(IDC_BTN_DESELECT_EVEN_NUMBER, OnBtnDeselectEvenNumber)
	ON_BN_CLICKED(IDC_BTN_SELECT_MULTI_OF_3, OnBtnSelectMultiOf3)
	ON_BN_CLICKED(IDC_BTN_DESELECT_MULTI_OF_3, OnBtnDeselectMultiOf3)
	ON_BN_CLICKED(IDC_BTN_SELECT_MULTI_OF_5, OnBtnSelectMultiOf5)
	ON_BN_CLICKED(IDC_BTN_DESELECT_MULTI_OF_5, OnBtnDeselectMultiOf5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGetNumberList message handlers

BOOL CDlgGetNumberList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	for( int i=0 ; i<45 ; i++ )
	{
		GetDlgItem( IDC_CHK_NUMBER_01 + i )->SetFont( &m_font_Normal );
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgGetNumberList::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgGetNumberList::OnOK() 
{
	UpdateData( );

	m_aryBytes.RemoveAll();

	C_FONC_ADD_CHECKED_NUMBER(01,IDC_CHK_NUMBER_01);
	C_FONC_ADD_CHECKED_NUMBER(02,IDC_CHK_NUMBER_02);
	C_FONC_ADD_CHECKED_NUMBER(03,IDC_CHK_NUMBER_03);
	C_FONC_ADD_CHECKED_NUMBER(04,IDC_CHK_NUMBER_04);
	C_FONC_ADD_CHECKED_NUMBER(05,IDC_CHK_NUMBER_05);
	C_FONC_ADD_CHECKED_NUMBER(06,IDC_CHK_NUMBER_06);
	C_FONC_ADD_CHECKED_NUMBER(07,IDC_CHK_NUMBER_07);
	C_FONC_ADD_CHECKED_NUMBER(08,IDC_CHK_NUMBER_08);
	C_FONC_ADD_CHECKED_NUMBER(09,IDC_CHK_NUMBER_09);
	C_FONC_ADD_CHECKED_NUMBER(10,IDC_CHK_NUMBER_10);
	C_FONC_ADD_CHECKED_NUMBER(11,IDC_CHK_NUMBER_11);
	C_FONC_ADD_CHECKED_NUMBER(12,IDC_CHK_NUMBER_12);
	C_FONC_ADD_CHECKED_NUMBER(13,IDC_CHK_NUMBER_13);
	C_FONC_ADD_CHECKED_NUMBER(14,IDC_CHK_NUMBER_14);
	C_FONC_ADD_CHECKED_NUMBER(15,IDC_CHK_NUMBER_15);
	C_FONC_ADD_CHECKED_NUMBER(16,IDC_CHK_NUMBER_16);
	C_FONC_ADD_CHECKED_NUMBER(17,IDC_CHK_NUMBER_17);
	C_FONC_ADD_CHECKED_NUMBER(18,IDC_CHK_NUMBER_18);
	C_FONC_ADD_CHECKED_NUMBER(19,IDC_CHK_NUMBER_19);
	C_FONC_ADD_CHECKED_NUMBER(20,IDC_CHK_NUMBER_20);
	C_FONC_ADD_CHECKED_NUMBER(21,IDC_CHK_NUMBER_21);
	C_FONC_ADD_CHECKED_NUMBER(22,IDC_CHK_NUMBER_22);
	C_FONC_ADD_CHECKED_NUMBER(23,IDC_CHK_NUMBER_23);
	C_FONC_ADD_CHECKED_NUMBER(24,IDC_CHK_NUMBER_24);
	C_FONC_ADD_CHECKED_NUMBER(25,IDC_CHK_NUMBER_25);
	C_FONC_ADD_CHECKED_NUMBER(26,IDC_CHK_NUMBER_26);
	C_FONC_ADD_CHECKED_NUMBER(27,IDC_CHK_NUMBER_27);
	C_FONC_ADD_CHECKED_NUMBER(28,IDC_CHK_NUMBER_28);
	C_FONC_ADD_CHECKED_NUMBER(29,IDC_CHK_NUMBER_29);
	C_FONC_ADD_CHECKED_NUMBER(30,IDC_CHK_NUMBER_30);
	C_FONC_ADD_CHECKED_NUMBER(31,IDC_CHK_NUMBER_31);
	C_FONC_ADD_CHECKED_NUMBER(32,IDC_CHK_NUMBER_32);
	C_FONC_ADD_CHECKED_NUMBER(33,IDC_CHK_NUMBER_33);
	C_FONC_ADD_CHECKED_NUMBER(34,IDC_CHK_NUMBER_34);
	C_FONC_ADD_CHECKED_NUMBER(35,IDC_CHK_NUMBER_35);
	C_FONC_ADD_CHECKED_NUMBER(36,IDC_CHK_NUMBER_36);
	C_FONC_ADD_CHECKED_NUMBER(37,IDC_CHK_NUMBER_37);
	C_FONC_ADD_CHECKED_NUMBER(38,IDC_CHK_NUMBER_38);
	C_FONC_ADD_CHECKED_NUMBER(39,IDC_CHK_NUMBER_39);
	C_FONC_ADD_CHECKED_NUMBER(40,IDC_CHK_NUMBER_40);
	C_FONC_ADD_CHECKED_NUMBER(41,IDC_CHK_NUMBER_41);
	C_FONC_ADD_CHECKED_NUMBER(42,IDC_CHK_NUMBER_42);
	C_FONC_ADD_CHECKED_NUMBER(43,IDC_CHK_NUMBER_43);
	C_FONC_ADD_CHECKED_NUMBER(44,IDC_CHK_NUMBER_44);
	C_FONC_ADD_CHECKED_NUMBER(45,IDC_CHK_NUMBER_45);


	CDialog::OnOK();
}

BOOL			CDlgGetNumberList::IsExistNumberInArray( const CByteArray& ary, BYTE bNumber )
{
	int i, nCount ;
	nCount = ary.GetSize();
	BYTE byteValue;
	for( i=0 ; i<nCount ; i++ )
	{
		byteValue = ary.GetAt(i);
		if( byteValue == bNumber )
			return TRUE;
	}
	return FALSE;
}
void CDlgGetNumberList::OnBtnSelectAll() 
{
	CButton* pButton = NULL;
	for( int i=0 ; i<45 ; i++ )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( TRUE );
	}
	
	
}

void CDlgGetNumberList::OnBtnDeselectAll() 
{
	CButton* pButton = NULL;
	for( int i=0 ; i<45 ; i++ )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( FALSE );
	}
	
}

void CDlgGetNumberList::OnBtnSelectOddNumber() 
{
	CButton* pButton = NULL;
	for( int i=0 ; i<45 ; i+=2 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( TRUE );
	}
	
}

void CDlgGetNumberList::OnBtnDeselectOddNumber() 
{
	CButton* pButton = NULL;
	for( int i=0 ; i<45 ; i+=2 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( FALSE );
	}
	
}

void CDlgGetNumberList::OnBtnSelectEvenNumber() 
{
	CButton* pButton = NULL;
	for( int i=1 ; i<45 ; i+=2 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( TRUE );
	}
	
}

void CDlgGetNumberList::OnBtnDeselectEvenNumber() 
{
	CButton* pButton = NULL;
	for( int i=1 ; i<45 ; i+=2 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( FALSE );
	}
	
}

void CDlgGetNumberList::OnBtnSelectMultiOf3() 
{
	CButton* pButton = NULL;
	for( int i=2 ; i<45 ; i+=3 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( TRUE );
	}
	
}

void CDlgGetNumberList::OnBtnDeselectMultiOf3() 
{
	CButton* pButton = NULL;
	for( int i=2 ; i<45 ; i+=3 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( FALSE );
	}
	
}

void CDlgGetNumberList::OnBtnSelectMultiOf5() 
{
	CButton* pButton = NULL;
	for( int i=4 ; i<45 ; i+=5 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( TRUE );
	}
	
}

void CDlgGetNumberList::OnBtnDeselectMultiOf5() 
{
	CButton* pButton = NULL;
	for( int i=4 ; i<45 ; i+=5 )
	{
		pButton = (CButton*)GetDlgItem( IDC_CHK_NUMBER_01 + i );
		pButton->SetCheck( FALSE );
	}
	
}

