#include "StdAfx.h"
#include "MouseInfoProvider.h"

#include <stdio.h>
#include <stddef.h>

namespace MouseInfo
{
	struct icon_info
	{
		LPWSTR id;
		enum CursorIconType type;
		HCURSOR cur;
	};

	static struct icon_info icons[] =
	{
	  { IDC_APPSTARTING, IDC_APPSTARTING_TYPE, NULL },
	  { IDC_ARROW, IDC_ARROW_TYPE, NULL },
	  { IDC_CROSS, IDC_CROSS_TYPE, NULL },
	  { IDC_HAND, IDC_HAND_TYPE, NULL },
	  { IDC_HELP, IDC_HELP_TYPE, NULL },
	  { IDC_IBEAM, IDC_IBEAM_TYPE, NULL },
	  { IDC_NO, IDC_NO_TYPE, NULL },
	  { IDC_SIZEALL, IDC_SIZEALL_TYPE, NULL },
	  { IDC_SIZENESW, IDC_SIZENESW_TYPE, NULL },
	  { IDC_SIZENS, IDC_SIZENS_TYPE, NULL },
	  { IDC_SIZENWSE, IDC_SIZENWSE_TYPE, NULL },
	  { IDC_SIZEWE, IDC_SIZEWE_TYPE, NULL },
	  { IDC_UPARROW, IDC_UPARROW_TYPE, NULL },
	  { IDC_WAIT, IDC_WAIT_TYPE, NULL },
	  { IDI_APPLICATION, IDI_APPLICATION_TYPE, NULL },
	  { IDI_ASTERISK, IDI_ASTERISK_TYPE, NULL },
	  { IDI_EXCLAMATION, IDI_EXCLAMATION_TYPE, NULL },
	  { IDI_HAND, IDI_HAND_TYPE, NULL },
	  { IDI_QUESTION, IDI_QUESTION_TYPE, NULL },
	  { IDI_WINLOGO, IDI_WINLOGO_TYPE, NULL },
	};

	MouseInfoProvider::MouseInfoProvider(void)
	{
		info = (PCURSORINFO)malloc(sizeof(CURSORINFO));

		for (int i = 0; i < sizeof(icons)/sizeof(icons[0]); i++) 
		{
			icons[i].cur = LoadCursor(NULL,icons[i].id);
		}
	}

	enum CursorIconType MouseInfoProvider::GetCursorIconType(void)
	{
		HCURSOR hcur;
		ICONINFO iconInfo;

		info->cbSize = sizeof(CURSORINFO);

		if (!GetCursorInfo(info))
		{
			return CURSOR_UNKNOWN_TYPE;
		}

		hcur = info->hCursor;

		if (!GetIconInfo(hcur, &iconInfo))
		{
			return CURSOR_UNKNOWN_TYPE;
		}

		for (int i = 0; i < sizeof(icons) / sizeof(icons[0]); i++)
		{
			if (hcur == icons[i].cur)
			{
				return icons[i].type;
			}
		}

		return CURSOR_UNKNOWN_TYPE;
	}

	void MouseInfoProvider::GetCursorPosition(POINT * point)
	{
		info->cbSize = sizeof(CURSORINFO);

		if (!GetCursorInfo(info))
		{
			return; // TODO: This needs to be handled better.
		}

		memcpy(point, &info->ptScreenPos, sizeof(*point));
	}

	MouseInfoProvider::~MouseInfoProvider(void)
	{
		free(info);
	}
}