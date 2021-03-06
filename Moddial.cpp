// Moddial.cpp: 구현 파일
//

#include "stdafx.h"
#include "Book3.h"
#include "Moddial.h"
#include "afxdialogex.h"
#include "BookData.h"
// Moddial 대화 상자

IMPLEMENT_DYNAMIC(Moddial, CDialogEx)

Moddial::Moddial(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_Writer(_T(""))
	, m_Name(_T(""))
	, m_Publisher(_T(""))
	, CCombo(_T(""))
{
	
}

Moddial::~Moddial()
{
}

void Moddial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Writer);
	DDX_Text(pDX, IDC_EDIT3, m_Name);
	DDX_Text(pDX, IDC_EDIT1, m_Publisher);
	DDX_CBString(pDX, IDC_COMBO1, CCombo);
	DDX_Control(pDX, IDC_COMBO1, Box_Control);
}


BEGIN_MESSAGE_MAP(Moddial, CDialogEx)
	ON_BN_CLICKED(IDOK, &Moddial::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Moddial::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Moddial::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// Moddial 메시지 처리기


void Moddial::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (CCombo==_T("")||m_Name == _T("") || m_Writer == _T("") || m_Publisher == _T(""))
	{

		MessageBox(_T("정보를 모두 입력해 주세요"), NULL, MB_OK);
	}
	else
	{

		CDialogEx::OnOK();
	}
	UpdateData(FALSE);
}


void Moddial::OnBnClickedCancel()
{

	int r;
	r = MessageBox(_T("취소하시겠습니까?"), _T("취소"), MB_OKCANCEL | MB_ICONQUESTION);
	if (r == IDOK)
	{
		CDialogEx::OnCancel();
	}
	
}


void Moddial::OnCbnSelchangeCombo1()
{

}


BOOL Moddial::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	int i;
	for (i = 0;i < 5;i++)
	{
		Box_Control.AddString(List[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
