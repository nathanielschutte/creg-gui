#include "usbApp.h"

wxIMPLEMENT_APP(usbApp);

usbApp::usbApp() {

}

usbApp::~usbApp() {

}

bool usbApp::OnInit() {
	frame_top = new usbMain();
	frame_top->Show();

	return true;
}
