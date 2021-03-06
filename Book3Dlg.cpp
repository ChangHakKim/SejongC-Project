
// Book3Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Book3.h"
#include "Book3Dlg.h"
#include "afxdialogex.h"
#include "Childial.h"
# include "Moddial.h"
#include "BookData.h"

Childial add_List;
Moddial mod_List;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

list<BookData> myBookList;//책 데이터를 모아놓는 곳
list<BookData>::iterator it;//탐색하기 위한 노드.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CBook3Dlg 대화 상자



CBook3Dlg::CBook3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOOK3_DIALOG, pParent)
	, search(_T("책 제목을 입력하세요"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBook3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_Control);
	DDX_Control(pDX, IDC_BUTTON3, DelBook);
	DDX_Control(pDX, IDC_BUTTON4, ModBook);
	DDX_Control(pDX, IDC_BUTTON5, TakBook);
	DDX_Control(pDX, IDC_BUTTON6, Rebook);
	DDX_Control(pDX, IDC_EDIT1, Editor);
	DDX_Control(pDX, IDCANCEL, Title);
	DDX_Text(pDX, IDC_EDIT1, search);
}

BEGIN_MESSAGE_MAP(CBook3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CBook3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBook3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBook3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBook3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CBook3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CBook3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CBook3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDCANCEL, &CBook3Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_SEARCH, &CBook3Dlg::OnBnClickedSearch)
END_MESSAGE_MAP()


// CBook3Dlg 메시지 처리기

BOOL CBook3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// Control_Box 초기화
	m_Control.InsertColumn(0,TEXT("분류"),LVCFMT_LEFT,100);
	m_Control.InsertColumn(1, TEXT("제목"), LVCFMT_LEFT, 250);
	m_Control.InsertColumn(2, TEXT("지은이"), LVCFMT_LEFT, 100);
	m_Control.InsertColumn(3, TEXT("출판사"), LVCFMT_LEFT, 100);
	m_Control.InsertColumn(4, TEXT("상태"), LVCFMT_LEFT, 100);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBook3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBook3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBook3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 도서 추가
void CBook3Dlg::OnBnClickedButton2()
{
	/*Childial childl;
	childl.DoModal();
	childl.DestroyWindow();*/
	if (add_List.DoModal()==IDOK)
	{
		BookData tmpBook;
		int index = m_Control.GetItemCount();
		this->m_Control.InsertItem(index, add_List.Ccombo);
		this->m_Control.SetItemText(index,1,add_List.m_strName);
		this->m_Control.SetItemText(index, 2, add_List.m_Writer);
		this->m_Control.SetItemText(index, 3, add_List.m_Publisher);
		this->m_Control.SetItemText(index, 4, _T("비치중"));
		add_List.m_strName = _T("");
		add_List.m_Writer = _T("");
		add_List.m_Publisher = _T("");
		//리스트에 노드 추가
		tmpBook.getBookData(add_List.Ccombo, add_List.m_strName, add_List.m_Writer, add_List.m_Publisher,0);//노드 생성
		myBookList.push_back(tmpBook);//리스트에 노드 추가(추가된 순서대로.)
	}
	
}

// 도서 삭제
void CBook3Dlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	POSITION pos = m_Control.GetFirstSelectedItemPosition();
	int index = m_Control.GetNextSelectedItem(pos);
	if (index > -1)
	{
		int r;
		r = MessageBox(_T("삭제하시겠습니까?"), _T("삭제"), MB_OKCANCEL | MB_ICONQUESTION);
		if (r == IDOK)
		{
			m_Control.DeleteItem(index);
		}
	}
	else
	{
		MessageBox(_T("삭제할 도서를 선택해 주세요."),_T("Error"), MB_OK);
	}
	//리스트에서 노드 제거
	for (it = myBookList.begin(); it != myBookList.end(); it++) {
		if (it->compare(m_Control.GetItemText(index, 1)) == 1) {//여기서 삭제되는 데이터의 제목을 입력해야됨. 비교 이후 삭제 
			myBookList.erase(it);//노드에서 삭제
			break;
		}
	}

	UpdateData(FALSE);
}

//도서 수정
void CBook3Dlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	POSITION pos = m_Control.GetFirstSelectedItemPosition();
	int index = m_Control.GetNextSelectedItem(pos);
	int r;
	if (index > -1)
	{
			mod_List.CCombo = m_Control.GetItemText(index, 0);
			mod_List.m_Name = m_Control.GetItemText(index, 1);
			mod_List.m_Writer = m_Control.GetItemText(index, 2);
			mod_List.m_Publisher = m_Control.GetItemText(index, 3);
			r = mod_List.DoModal();
			if(r==IDOK)
			{
				this->m_Control.SetItemText(index, 0,mod_List.CCombo);
				this->m_Control.SetItemText(index, 1, mod_List.m_Name);
				this->m_Control.SetItemText(index, 2, mod_List.m_Writer);
				this->m_Control.SetItemText(index, 3, mod_List.m_Publisher);
				//리스트에 있는 노드 수정
				for (it = myBookList.begin(); it != myBookList.end(); it++) {
					if (it->compare(mod_List.m_Name) == 1) {//여기서 삭제되는 데이터의 제목을 입력해야됨. 비교 이후 삭제 
						it->getBookData(mod_List.CCombo, mod_List.m_Name, mod_List.m_Writer, mod_List.m_Publisher, 0);//노드 내용 다시 set
						break;
					}
				}

			}	
	}
	else
	{
		MessageBox(_T("수정할 도서를 선택해 주세요."), _T("Error"), MB_OK);
	}
	UpdateData(FALSE);
}

//도서 대출
void CBook3Dlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	POSITION pos = m_Control.GetFirstSelectedItemPosition();
	int index = m_Control.GetNextSelectedItem(pos);
	if (index > -1)
	{
		if (m_Control.GetItemText(index, 4) == _T("대출중"))
		{
			MessageBox(_T("이미 대출중입니다."), _T("Error"), MB_OK);
		}
		else
		{
			int r;
			r = MessageBox(_T("대출하시겠습니까?"), _T("대출"), MB_OKCANCEL | MB_ICONQUESTION);
			if (r == IDOK)
			{
				this->m_Control.SetItemText(index, 4, _T("대출중"));
			}
		}	
	}
	else
	{
		MessageBox(_T("대출할 도서를 선택해 주세요."), _T("Error"), MB_OK);
	}
	//리스트 도서 변경
	for (it = myBookList.begin(); it != myBookList.end(); it++) {
		if (it->compare(mod_List.m_Name) == 1) {//여기서 삭제되는 데이터의 제목을 입력해야됨. 비교 이후 삭제 
			it->borrowBook();
			break;
		}
	}
	UpdateData(FALSE);
}

// 도서 반납
void CBook3Dlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	POSITION pos = m_Control.GetFirstSelectedItemPosition();
	int index = m_Control.GetNextSelectedItem(pos);
	if (index > -1)
	{
		if (m_Control.GetItemText(index, 4) == _T("비치중"))
		{
			MessageBox(_T("이미 비치중입니다."), _T("Error"), MB_OK);
		}
		else
		{
			int r;
			r = MessageBox(_T("반납하시겠습니까?"), _T("반납"), MB_OKCANCEL | MB_ICONQUESTION);
			if (r == IDOK)
			{
				this->m_Control.SetItemText(index, 4, _T("비치중"));
			}
		}
		//리스트 도서 반납
		for (it = myBookList.begin(); it != myBookList.end(); it++) {
			if (it->compare(mod_List.m_Name) == 1) {//여기서 삭제되는 데이터의 제목을 입력해야됨. 비교 이후 삭제 
				it->borrowBook();
				break;
			}
		}
	}
	else
	{
		MessageBox(_T("반납할 도서를 선택해 주세요."), _T("Error"), MB_OK);
	}
	UpdateData(FALSE);
}

//저장
void CBook3Dlg::OnBnClickedButton7()
{

}

//로드
void CBook3Dlg::OnBnClickedButton8()
{

}

//프로그램 종료
void CBook3Dlg::OnBnClickedCancel()
{
	int r;
	r = MessageBox(_T("종료하시겠습니까?"), _T("종료"), MB_OKCANCEL | MB_ICONQUESTION);
	if (r == IDOK)
	{
		CDialogEx::OnCancel();
	}
	
}

//검색
void CBook3Dlg::OnBnClickedSearch()
{
	UpdateData(TRUE);
	m_Control.DeleteAllItems();
	if (search == _T(""))
	{

		for (it = myBookList.begin(); it != myBookList.end(); it++) {
			int index = m_Control.GetItemCount();
			this->m_Control.InsertItem(index, it->getGenre());
			this->m_Control.SetItemText(index, 1, it->getTitle());
			this->m_Control.SetItemText(index, 2, it->getAuthor());
			this->m_Control.SetItemText(index, 3, it->getPublisher());
			this->m_Control.SetItemText(index, 4, it->getBorrow());
		}
	}
	else
	{
		for (it = myBookList.begin(); it != myBookList.end(); it++) {
			if (it->compare(mod_List.m_Name) == 1) {//여기서 삭제되는 데이터의 제목을 입력해야됨. 비교 이후 삭제 
				int index = m_Control.GetItemCount();
				this->m_Control.InsertItem(index, it->getGenre());
				this->m_Control.SetItemText(index, 1, it->getTitle());
				this->m_Control.SetItemText(index, 2, it->getAuthor());
				this->m_Control.SetItemText(index, 3, it->getPublisher());
				this->m_Control.SetItemText(index, 4, it->getBorrow());
				break;
			}
		}
	}
	UpdateData(FALSE);
}
