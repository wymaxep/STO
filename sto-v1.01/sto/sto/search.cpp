// search.cpp : implementation file
//

#include "stdafx.h"
#include "sto.h"
#include "search.h"
#include "afxdialogex.h"
#include "stoDlg.h"


// search dialog

IMPLEMENT_DYNAMIC(search, CDialogEx)

search::search(CWnd* pParent /*=NULL*/)
	: CDialogEx(search::IDD, pParent)
{

	m_search = _T("Рябенко Олег Валентинович");

	m_kriterij = 0;
}

search::~search()
{
}

void search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_search);
	//  DDX_Control(pDX, IDC_LIST1, m_list);
	//  DDX_Control(pDX, IDC_COMBO1, m_kriterij);
	//  DDX_Control(pDX, IDC_LIST2, m_kriterij);
	DDX_Radio(pDX, IDC_RADIO1, m_kriterij);
}


BEGIN_MESSAGE_MAP(search, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &search::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &search::OnBnClickedOk)
END_MESSAGE_MAP()


// search message handlers


void search::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void search::OnBnClickedButton1()
{
	
}


void search::OnBnClickedOk()
{
	
	if(m_kriterij==0)
	{
		zapros.Format(L"select * from sto where FIO='%s'",m_search);
	}
	if(m_kriterij==1)
	{
		zapros.Format(L"select * from sto where num_avto='%s'",m_search);
	}
	if(m_kriterij==2)
	{
		zapros.Format(L"select * from sto where marka_avto='%s'",m_search);
	}
	CDialogEx::OnOK();
}
