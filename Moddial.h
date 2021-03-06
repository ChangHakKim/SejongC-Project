#pragma once


// Moddial 대화 상자

class Moddial : public CDialogEx
{
	DECLARE_DYNAMIC(Moddial)

public:
	Moddial(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Moddial();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_Writer;
	CString m_Name;
	CString m_Publisher;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString CCombo;
	CComboBox Box_Control;
	CString List[5] = { _T("소설"),_T("수필"),_T("논문"),_T("만화"),_T("사전") };
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
};
