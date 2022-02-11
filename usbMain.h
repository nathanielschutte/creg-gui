#pragma once

#include "wx/wx.h"
#include "Controller.h"

#define GENERAL_PADDING 10

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FRAME_DIV_X WINDOW_WIDTH * 4 / 6

#define BUTTON_SEND_ID 10001
#define BUTTON_SEND_WIDTH 100
#define BUTTON_SEND_HEIGHT 20

#define LIST_LOG_ID 30001
#define LIST_LOG_WIDTH FRAME_DIV_X - GENERAL_PADDING * 2
#define LIST_LOG_HEIGHT 300

#define TEXT_CMD_ID 20001
#define TEXT_CMD_WIDTH FRAME_DIV_X - BUTTON_SEND_WIDTH - GENERAL_PADDING * 3
#define TEXT_CMD_HEIGHT 20


class usbMain : public wxFrame {
public:
	usbMain();
	~usbMain();

private:
	Controller* m_control;

public:
	wxButton* m_button_send = nullptr;
	wxTextCtrl* m_text_cmd = nullptr;
	wxListBox* m_list_log = nullptr;

public:
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

