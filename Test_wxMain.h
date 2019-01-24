/***************************************************************
 * Name:      Test_wxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-01-11
 * Copyright: Allam ()
 * License:
 **************************************************************/
/*--------------------- Ed Company ---------------------*/
#ifndef TEST_WXMAIN_H
#define TEST_WXMAIN_H

//(*Headers(Test_wxFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class Palabras;

class Test_wxFrame: public wxFrame
{
    public:

        Test_wxFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Test_wxFrame();

    private:
        Palabras *token;

        //------------------------- Funciones agregadas -----------------------------//
        void refrescar_list_tokens();
        void refrescar_list_tokens_encontrados();
        //---------------------------------------------------------------------------//

        //(*Handlers(Test_wxFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnAnadirClick(wxCommandEvent& event);
        void txt_codigo_TextChanged(wxCommandEvent& event);
        void Onbtn_borrarSeleccionClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Test_wxFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_LISTBOX2;
        static const long ID_BUTTON2;
        static const long ID_PANEL2;
        static const long ID_LISTBOX1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_PANEL3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Test_wxFrame)
        wxButton* btnAnadir;
        wxButton* btn_borrarSeleccion;
        wxListBox* list_tokens;
        wxListBox* list_tokens_econtrados;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* txtToken;
        wxTextCtrl* txt_codigo;
        //*)
        DECLARE_EVENT_TABLE()

};

#endif // TEST_WXMAIN_H
