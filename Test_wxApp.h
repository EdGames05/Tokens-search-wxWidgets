/***************************************************************
 * Name:      Test_wxApp.h
 * Purpose:   Defines Application Class
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-01-11
 * Copyright: Allam ()
 * License:
 **************************************************************/

#ifndef TEST_WXAPP_H
#define TEST_WXAPP_H

#include <wx/app.h>

class Test_wxApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TEST_WXAPP_H
