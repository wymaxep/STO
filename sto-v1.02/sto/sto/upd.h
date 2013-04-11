#pragma once


// upd dialog

class upd : public CDialogEx
{
	DECLARE_DYNAMIC(upd)

public:
	upd(CWnd* pParent = NULL);   // standard constructor
	virtual ~upd();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_fio;
	CString m_avt;
	CString m_num;
	CString m_rik;
	CString m_prob;
	CString m_zakl;
	CString m_price;
};
