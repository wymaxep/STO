
// stoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sto.h"
#include "stoDlg.h"
#include "afxdialogex.h"
#include <afxdb.h>
#include "search.h"
#include "insert.h"
#include "upd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CDatabase db;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CstoDlg dialog




CstoDlg::CstoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CstoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_list);
	//  DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_LIST4, m_list);
}

BEGIN_MESSAGE_MAP(CstoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CstoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CstoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CstoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CstoDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CstoDlg message handlers

BOOL CstoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CstoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CstoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CstoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CstoDlg::OnBnClickedButton1()
{
	   CFileDialog dlg(true,NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"MS Access File (.mdb)|*.mdb||");
	CString ConnStr;
	if(dlg.DoModal() == IDOK)
	{
		CString ConnStr;
		CString FilePath = dlg.GetPathName();
		ConnStr.Format(_T("ODBC;DRIVER={MICROSOFT ACCESS DRIVER (*.mdb)};DSN='';DBQ=%s"),FilePath);
		db.Open(NULL, FALSE, FALSE, ConnStr);
	}
	CString str1,ss;
	str1 = "select * from sto";
	Fiil_list(str1);
}

	void CstoDlg::Fiil_list(CString zapros)
{
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	int i;
	m_list.DeleteAllItems();
	for (int i=0;i<8;i++)
		m_list.DeleteColumn(0);
	//n=m_list.GetHeaderCtrl()->GetItemCount();
	CRecordset rec(&db);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	CODBCFieldInfo info;
	for (i=0;i<count;i++)
	{
		rec.GetODBCFieldInfo(i,info);
		m_list.InsertColumn(i,info.m_strName);
		m_list.SetColumnWidth(i,80);
	}
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list.InsertItem(i, buff);
			else
				m_list.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}


	void CstoDlg::OnBnClickedButton2()
	{
		search win;
		if(win.DoModal()==IDOK)
		{
			Fiil_list(win.zapros);
		}
	}


	void CstoDlg::OnBnClickedButton3()
	{
		insert win;
		CString zapros;
		if (win.DoModal()==IDOK)
		{
			UpdateData();
			zapros.Format(_T("Insert into sto values ('%s', '%s', '%s', '%s', '%s', '%s', '%s')"),win.m_name,win.m_marka,win.m_num,win.m_rik,win.m_problem,win.m_zakl,win.m_price );
			db.ExecuteSQL(zapros);
			zapros=L"Select * from sto";
			Fiil_list(zapros);
		}
	}


	void CstoDlg::OnBnClickedButton4()
	{
		upd win;
		POSITION pos=m_list.GetFirstSelectedItemPosition();
		int npos=m_list.GetNextSelectedItem(pos);
		win.m_fio=m_list.GetItemText(npos,0);
		CString fio=m_list.GetItemText(npos,0);
		win.m_avt=m_list.GetItemText(npos,1);
		win.m_num=m_list.GetItemText(npos,2);
		win.m_rik=m_list.GetItemText(npos,3);
		win.m_prob=m_list.GetItemText(npos,4);
		win.m_zakl=m_list.GetItemText(npos,5);
		win.m_price=m_list.GetItemText(npos,6);
		CString zapros;
	if(win.DoModal()==IDOK)
	{
		CString str,zapros;
		POSITION pos=m_list.GetFirstSelectedItemPosition();
		int npos;
		while(pos)
		{
			npos=m_list.GetNextSelectedItem(pos);	
			zapros.Format(_T("update sto SET FIO='%s',marka_avto='%s',num_avto='%s',rik_vipusku='%s',problem='%s',zakluchenie='%s',cost='%s' WHERE FIO = '%s'"),win.m_fio,win.m_avt,win.m_num,win.m_rik,win.m_prob,win.m_zakl,win.m_price,fio);
			db.ExecuteSQL(zapros);
			zapros = "select * from sto";
			Fiil_list( zapros);
		}
	}
	}
