#pragma once

#include <Windows.h>

namespace MouseInfo
{
    public enum CursorIconType
    {
        CURSOR_UNKNOWN_TYPE = 0,
        IDC_APPSTARTING_TYPE = 1,
        IDC_ARROW_TYPE = 2,
        IDC_CROSS_TYPE = 3,
        IDC_HAND_TYPE = 4,
        IDC_HELP_TYPE = 5,
        IDC_IBEAM_TYPE = 6,
        IDC_NO_TYPE = 7,
        IDC_SIZEALL_TYPE = 8,
        IDC_SIZENESW_TYPE = 9,
        IDC_SIZENS_TYPE = 10,
        IDC_SIZENWSE_TYPE = 11,
        IDC_SIZEWE_TYPE = 12,
        IDC_UPARROW_TYPE = 13,
        IDC_WAIT_TYPE = 14,
        IDI_APPLICATION_TYPE = 15,
        IDI_ASTERISK_TYPE = 16,
        IDI_EXCLAMATION_TYPE = 17,
        IDI_HAND_TYPE = 18,
        IDI_QUESTION_TYPE = 19,
        IDI_WINLOGO_TYPE = 20,
    };

    public ref class MouseInfoProvider
    {
    public:
        MouseInfoProvider(void);
        ~MouseInfoProvider(void);

        enum CursorIconType GetCursorIconType(void);
        void GetCursorPosition(POINT * point);
    private:
        PCURSORINFO info;
    };
}
