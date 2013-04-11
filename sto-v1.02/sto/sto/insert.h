#pragma once


// insert dialog

class insert : public CDialogEx
{
	DECLARE_DYNAMIC(insert)

public:
	insert(CWnd* pParent = NULL);   // standard constructor
	virtual ~insert();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_marka;
	CString m_num;
	CString m_rik;
	CString m_problem;
	CString m_zakl;
	CString m_price;
};
