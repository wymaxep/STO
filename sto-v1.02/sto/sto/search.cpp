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


	m_name = _T("");
	m_num = _T("");
	m_mark = _T("");
}

search::~search()
{
}

void search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_search);
	//  DDX_Control(pDX, IDC_LIST1, m_list);
	//  DDX_Control(pDX, IDC_COMBO1, m_kriterij);
	//  DDX_Control(pDX, IDC_LIST2, m_kriterij);
	//  DDX_Radio(pDX, IDC_RADIO1, m_kriterij);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT3, m_mark);
}


BEGIN_MESSAGE_MAP(search, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &search::OnBnClickedButton1)
	ON_BN_CLICKED(ID1, &search::OnBnClicked1)
	ON_BN_CLICKED(ID2, &search::OnBnClicked2)
	ON_BN_CLICKED(ID3, &search::OnBnClicked3)
END_MESSAGE_MAP()


// search message handlers


void search::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void search::OnBnClickedButton1()
{
	
}


//void search::OnBnClickedOk()
//{
//	CDialogEx::OnOK();
//}


void search::OnBnClicked1()
{
	UpdateData();
	zapros.Format(L"select * from sto where FIO='%s'",m_name);
}


void search::OnBnClicked2()
{
	UpdateData();
	zapros.Format(L"select * from sto where num_avto='%s'",m_num);
}


void search::OnBnClicked3()
{
	UpdateData();
	zapros.Format(L"select * from sto where marka_avto='%s'",m_mark);
}
