#pragma once

#include "wx/wx.h"
#include "usbMain.h"

class usbApp : public wxApp {
public:
	usbApp();
	~usbApp();

private:
	usbMain* frame_top = nullptr;

public:
	virtual bool OnInit();
};
