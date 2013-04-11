// upd.cpp : implementation file
//

#include "stdafx.h"
#include "sto.h"
#include "upd.h"
#include "afxdialogex.h"


// upd dialog

IMPLEMENT_DYNAMIC(upd, CDialogEx)

upd::upd(CWnd* pParent /*=NULL*/)
	: CDialogEx(upd::IDD, pParent)
{

	m_fio = _T("");
	m_avt = _T("");
	m_num = _T("");
	m_rik = _T("");
	m_prob = _T("");
	m_zakl = _T("");
	m_price = _T("");
}

upd::~upd()
{
}

void upd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_fio);
	DDX_Text(pDX, IDC_EDIT2, m_avt);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_rik);
	DDX_Text(pDX, IDC_EDIT5, m_prob);
	DDX_Text(pDX, IDC_EDIT6, m_zakl);
	DDX_Text(pDX, IDC_EDIT7, m_price);
}


BEGIN_MESSAGE_MAP(upd, CDialogEx)
END_MESSAGE_MAP()


// upd message handlers
