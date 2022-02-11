#pragma once

#include "wx/wx.h"

class usbMain : public wxFrame {
public:
	usbMain();
	~usbMain();

public:
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;

public:
	wxButton* m_button1 = nullptr;
	wxTextCtrl* m_text1 = nullptr;
	wxListBox* m_list1 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

