#pragma once


// Childial 대화 상자

class Childial : public CDialogEx
{
	DECLARE_DYNAMIC(Childial)

public:
	Childial(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Childial();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	CString m_strName;
	CString m_Writer;
	afx_msg void OnBnClickedOk();
	CString m_Publisher;
	CButton Add;
	afx_msg void OnCbnSelchangeCombo1();
	CString Ccombo;
	CComboBox Box_Control;
	CString List[5] = { _T("소설"),_T("수필"),_T("논문"),_T("만화"),_T("사전") };
	virtual BOOL OnInitDialog();
};
