#include "usbMain.h"

wxBEGIN_EVENT_TABLE(usbMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()


usbMain::usbMain() : wxFrame(nullptr, wxID_ANY, "USB Headphone Amp Config", wxPoint(30, 30), wxSize(WINDOW_WIDTH, WINDOW_HEIGHT)) {
	m_button1 = new wxButton(this, 10001, "Click Me", wxPoint(10, 10), wxSize(150, 50));
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

usbMain::~usbMain() {

}

void usbMain::OnButtonClicked(wxCommandEvent& evt) {
	m_list1->AppendString(m_text1->GetValue());

	evt.Skip();
}