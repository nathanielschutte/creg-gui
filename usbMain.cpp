#include "usbMain.h"

wxBEGIN_EVENT_TABLE(usbMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()


usbMain::usbMain() : wxFrame(nullptr, wxID_ANY, "USB Headphone Amp Config", wxPoint(30, 30), wxSize(WINDOW_WIDTH, WINDOW_HEIGHT)) {

	// Starter console interface to speak with microcontroller
	m_button_send = new wxButton(
		this, 
		BUTTON_SEND_ID, 
		"Send", 
		wxPoint(TEXT_CMD_WIDTH + GENERAL_PADDING * 2, LIST_LOG_HEIGHT + GENERAL_PADDING * 2), 
		wxSize(BUTTON_SEND_WIDTH, BUTTON_SEND_HEIGHT)
	);

	m_text_cmd = new wxTextCtrl(
		this,
		TEXT_CMD_ID,
		"", 
		wxPoint(GENERAL_PADDING, LIST_LOG_HEIGHT + GENERAL_PADDING * 2),
		wxSize(TEXT_CMD_WIDTH, TEXT_CMD_HEIGHT)
	);

	m_list_log = new wxListBox(
		this,
		LIST_LOG_ID,
		wxPoint(GENERAL_PADDING, GENERAL_PADDING),
		wxSize(LIST_LOG_WIDTH, LIST_LOG_HEIGHT)
	);

	// Create controller
	m_control = new Controller(m_list_log);
}

usbMain::~usbMain() {

	delete m_control;
}

void usbMain::OnButtonClicked(wxCommandEvent& evt) {

	wxString cmd = m_text_cmd->GetValue();
	std::string msg = std::string(cmd.mb_str());
	m_control->process_msg_str(msg);

	evt.Skip();
}