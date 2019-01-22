/***************************************************************
 * Name:      Test_wxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-01-11
 * Copyright: Allam ()
 * License:
 **************************************************************/

#include "Test_wxMain.h"
#include <wx/msgdlg.h>
#include "Palabras.h"
#include "AList.h"
#include <cstring>

using namespace std;

//(*InternalHeaders(Test_wxFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Test_wxFrame)
const long Test_wxFrame::ID_TEXTCTRL1 = wxNewId();
const long Test_wxFrame::ID_BUTTON1 = wxNewId();
const long Test_wxFrame::ID_LISTBOX2 = wxNewId();
const long Test_wxFrame::ID_PANEL2 = wxNewId();
const long Test_wxFrame::ID_LISTBOX1 = wxNewId();
const long Test_wxFrame::ID_TEXTCTRL2 = wxNewId();
const long Test_wxFrame::ID_STATICTEXT1 = wxNewId();
const long Test_wxFrame::ID_STATICTEXT2 = wxNewId();
const long Test_wxFrame::ID_PANEL3 = wxNewId();
const long Test_wxFrame::ID_PANEL1 = wxNewId();
const long Test_wxFrame::idMenuQuit = wxNewId();
const long Test_wxFrame::idMenuAbout = wxNewId();
const long Test_wxFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Test_wxFrame,wxFrame)
    //(*EventTable(Test_wxFrame)
    //*)
END_EVENT_TABLE()

Test_wxFrame::Test_wxFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Test_wxFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(929,314));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,136), wxSize(572,183), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(8,8), wxSize(200,304), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    txtToken = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,272), wxSize(144,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    btnAnadir = new wxButton(Panel2, ID_BUTTON1, _("Add"), wxPoint(160,272), wxSize(32,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    list_tokens = new wxListBox(Panel2, ID_LISTBOX2, wxPoint(8,32), wxSize(180,232), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxPoint(216,8), wxSize(704,304), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    list_tokens_econtrados = new wxListBox(Panel3, ID_LISTBOX1, wxPoint(520,32), wxSize(176,264), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    txt_codigo = new wxTextCtrl(Panel3, ID_TEXTCTRL2, wxEmptyString, wxPoint(8,32), wxSize(504,264), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT1, _("Tokens encontrados"), wxPoint(520,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT2, _("Código"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_wxFrame::OnbtnAnadirClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Test_wxFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Test_wxFrame::OnAbout);
    //*)

    this->token = new Palabras();
    string error = "";
    if(token->get_message_error(error)){
        wxMessageBox(error,_("Error fatal"));
    }

    this->refrescar_list_tokens();

}

Test_wxFrame::~Test_wxFrame()
{
    //(*Destroy(Test_wxFrame)
    //*)
}

void Test_wxFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Test_wxFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Test_wxFrame::OnbtnAnadirClick(wxCommandEvent& event)
{
    if(this->txtToken->GetValue().empty()){
        wxMessageBox("Escriba el token para continuar...",_("Registro de Tokens"));
    }
    else
    if(token->insertar_token(this->txtToken->GetValue())){
        wxMessageBox("Token registrado exitosamente...",_("Registro de Tokens"));
        this->refrescar_list_tokens();
        this->txtToken->ChangeValue("");
    }
    else{
        wxMessageBox(token->get_message_error(),_("Error fatal"));
    }
}

void Test_wxFrame::refrescar_list_tokens(){
    AList<string> tokens = token->getListaTokens();
    string error = "";
    if(token->get_message_error(error)){
        wxMessageBox(error,"Error fatal");
        return;
    }
    this->list_tokens->Clear();

    if(tokens.get_tamano() > 0){
        for(unsigned int i = 0; i < tokens.get_tamano(); i++){
            this->list_tokens->AppendAndEnsureVisible(wxString(tokens.obtener_at(i)));
        }
    }
}
