// Childial.cpp: 구현 파일
//

#include "stdafx.h"
#include "Book3.h"
#include "Childial.h"
#include "afxdialogex.h"
# include "Book3Dlg.h"
#include "BookData.h"

// Childial 대화 상자

IMPLEMENT_DYNAMIC(Childial, CDialogEx)

Childial::Childial(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_Writer(_T(""))
	, m_Publisher(_T(""))
	, Ccombo(_T(""))
{
	
}

Childial::~Childial()
{
}

void Childial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_Writer);
	DDX_Text(pDX, IDC_EDIT1, m_Publisher);
	DDX_Control(pDX, IDOK, Add);
	DDX_CBString(pDX, IDC_COMBO1, Ccombo);
	DDX_Control(pDX, IDC_COMBO1, Box_Control);

}


BEGIN_MESSAGE_MAP(Childial, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Childial::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Childial::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Childial::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// Childial 메시지 처리기


void Childial::OnBnClickedCancel()
{
	int r;
	r = MessageBox(_T("취소하시겠습니까?"), _T("취소"), MB_OKCANCEL | MB_ICONQUESTION);
	if (r == IDOK)
	{

		CDialogEx::OnCancel();
	}
}


void Childial::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (Ccombo==_T("")||m_strName == _T("") || m_Writer == _T("") || m_Publisher == _T(""))
	{

		MessageBox(_T("정보를 모두 입력해 주세요"),NULL,MB_OK);
	}
	else
	{
		
		CDialogEx::OnOK();
	}
	UpdateData(FALSE);

}


void Childial::OnCbnSelchangeCombo1()
{
	
}


BOOL Childial::OnInitDialog()
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
