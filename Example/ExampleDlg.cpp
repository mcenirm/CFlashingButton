
// ExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Example.h"
#include "CFlashingButton.h"
#include "ExampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExampleDlg dialog



CExampleDlg::CExampleDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_EXAMPLE_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExampleDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON1, m_button1);
}

BEGIN_MESSAGE_MAP(CExampleDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_START, &CExampleDlg::OnBnClickedButtonStart)
    ON_BN_CLICKED(IDC_BUTTON_STOP, &CExampleDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CExampleDlg message handlers

BOOL CExampleDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(false);

    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExampleDlg::OnPaint()
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
HCURSOR CExampleDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CExampleDlg::OnBnClickedButtonStart()
{
    GetDlgItem(IDC_BUTTON_START)->EnableWindow(false);
    GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(true);
    m_button1.StartFlashing();
}


void CExampleDlg::OnBnClickedButtonStop()
{
    GetDlgItem(IDC_BUTTON_START)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(false);
    m_button1.StopFlashing();
}
