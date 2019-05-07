#pragma once


// CFlashingButton

class AFX_EXT_CLASS CFlashingButton : public CButton
{
    DECLARE_DYNAMIC(CFlashingButton)

public:
    CFlashingButton();
    virtual ~CFlashingButton();

protected:
    bool m_shouldIFlash;
    UINT_PTR m_timerID;
    UINT m_elapse;
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    void StartFlashing();
    void StopFlashing();
};


