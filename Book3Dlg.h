
// Book3Dlg.h: 헤더 파일
//

#pragma once


// CBook3Dlg 대화 상자
class CBook3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CBook3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOK3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_Control;
	afx_msg void OnBnClickedButton2(); //도서 추가 이벤트
	//버튼 변수
	CButton DelBook;
	CButton ModBook;
	CButton TakBook;
	CButton Rebook;
	CEdit Editor; //list control에 저장할 내용
	CButton Title;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedCancel();
	CString search;
	afx_msg void OnBnClickedSearch();
};
