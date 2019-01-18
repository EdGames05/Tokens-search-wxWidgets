/***************************************************************
 * Name:      Test_wxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-01-11
 * Copyright: Allam ()
 * License:
 **************************************************************/

#include "Test_wxApp.h"

//(*AppHeaders
#include "Test_wxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Test_wxApp);

bool Test_wxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Test_wxFrame* Frame = new Test_wxFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
