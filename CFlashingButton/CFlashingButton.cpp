// CFlashingButton.cpp : implementation file
//

#include "stdafx.h"
#include "CFlashingButton.h"


// CFlashingButton

IMPLEMENT_DYNAMIC(CFlashingButton, CButton)

CFlashingButton::CFlashingButton()
{
    m_shouldIFlash = false;
    m_timerID = 0;
    m_elapse = 500;
}

CFlashingButton::~CFlashingButton()
{
}


BEGIN_MESSAGE_MAP(CFlashingButton, CButton)
    ON_WM_TIMER()
END_MESSAGE_MAP()



// CFlashingButton message handlers




void CFlashingButton::OnTimer(UINT_PTR nIDEvent)
{
    if (m_timerID && m_timerID == nIDEvent)
    {
        Invalidate();
    }
    else
    {
        CButton::OnTimer(nIDEvent);
    }
}


void CFlashingButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    // This code only works with buttons.
    ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

    CDC context;
    context.Attach(lpDrawItemStruct->hDC);

    CRect rect;
    rect = lpDrawItemStruct->rcItem;
    int smudge = 3;
    CRect focus = CRect(
        rect.left + smudge,
        rect.top + smudge,
        rect.right - smudge,
        rect.bottom - smudge
    );

    // Draw the button frame.
    UINT style = DFCS_BUTTONPUSH;
    if (lpDrawItemStruct->itemState & ODS_SELECTED)
    {
        style |= DFCS_PUSHED;
    }
    context.DrawFrameControl(rect, DFC_BUTTON, style);

    // Draw button text
    CString caption;
    GetWindowText(caption);
    context.DrawText(caption, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // Draw focus
    if (lpDrawItemStruct->itemState & ODS_FOCUS)
    {
        context.DrawFocusRect(focus);
    }

    // Invert for flash effect
    if (m_shouldIFlash && (GetTickCount() / 1000) & 1)
    {
        context.InvertRect(focus);
    }

    context.Detach();
}


void CFlashingButton::StartFlashing()
{
    m_shouldIFlash = true;
    if (!m_timerID)
    {
        m_timerID = (UINT_PTR)GetSafeHwnd();
        UINT_PTR newTimerID = SetTimer(m_timerID, m_elapse, nullptr);
        if (!newTimerID)
        {
            // TODO throw exception?
        }
        else
        {
            m_timerID = newTimerID;
        }
    }
}


void CFlashingButton::StopFlashing()
{
    m_shouldIFlash = false;
    if (m_timerID)
    {
        KillTimer(m_timerID);
    }
    m_timerID = 0;
}
