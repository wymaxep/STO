#pragma once


// search dialog

class search : public CDialogEx
{
	DECLARE_DYNAMIC(search)

public:
	search(CWnd* pParent = NULL);   // standard constructor
	virtual ~search();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CString m_search;
	CString zapros;
	CString ed;
//	CListCtrl m_list;
//	CComboBox m_kriterij;
	afx_msg void OnCbnSelchangeCombo1();
//	CListBox m_kriterij;
//	int m_kriterij;
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedOk();
	CString m_name;
	CString m_num;
	CString m_mark;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
};
