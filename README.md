# CFlashingButton
MFC custom button that flashes

1. Add button to window, and enable "owner draw".
2. Add custom buttom member
    ```c++
    // header

    class CExampleDlg : public CDialogEx
    {
        // ...
    protected:
        CFlashingButton m_button1;
        // ...
    }
    ```

    ```c++
    // implementation

    #include "stdafx.h"
    // ...
    #include "CFlashingButton.h"
    #include "ExampleDlg.h"
    // ...

    void CExampleDlg::DoDataExchange(CDataExchange* pDX)
    {
        CDialogEx::DoDataExchange(pDX);
        // ...
        DDX_Control(pDX, IDC_BUTTON1, m_button1);
        // ...
    }

    void CExampleDlg::OnSomeStartAction()
    {
        // ...
        m_button1.StartFlashing();
        // ...
    }

    void CExampleDlg::OnSomeStopAction()
    {
        // ...
        m_button1.StopFlashing();
        // ...
    }
    ```
