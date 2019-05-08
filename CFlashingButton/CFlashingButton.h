/*

CFlashingButton - MFC custom button that flashes
Copyright (C) 2019  Michael Francis McEniry

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/


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


