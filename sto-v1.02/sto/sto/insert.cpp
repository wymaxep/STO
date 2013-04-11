// insert.cpp : implementation file
//

#include "stdafx.h"
#include "sto.h"
#include "insert.h"
#include "afxdialogex.h"


// insert dialog

IMPLEMENT_DYNAMIC(insert, CDialogEx)

insert::insert(CWnd* pParent /*=NULL*/)
	: CDialogEx(insert::IDD, pParent)
{

	m_name = _T("");
	m_marka = _T("");
	m_num = _T("");
	m_rik = _T("");
	m_problem = _T("");
	m_zakl = _T("");
	m_price = _T("");
}

insert::~insert()
{
}

void insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_marka);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_rik);
	DDX_Text(pDX, IDC_EDIT5, m_problem);
	DDX_Text(pDX, IDC_EDIT6, m_zakl);
	DDX_Text(pDX, IDC_EDIT7, m_price);
}


BEGIN_MESSAGE_MAP(insert, CDialogEx)
END_MESSAGE_MAP()


// insert message handlers
