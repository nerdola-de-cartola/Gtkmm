#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window {
  protected:
    //Child widgets:
    Gtk::Box m_HBox, m_HBox2;
    Gtk::Box m_VBox;
    Gtk::Label m_Label;
    Gtk::Entry m_Entry;
    Gtk::Button m_Button_Close;
    Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
    
  public:
    ExampleWindow();
    virtual ~ExampleWindow();

  protected:
    //Signal handlers:
    void on_entry_changed();
    void on_checkbox_editable_toggled();
    void on_checkbox_visibility_toggled();
    void on_button_close();

};

#endif //GTKMM_EXAMPLEWINDOW_H