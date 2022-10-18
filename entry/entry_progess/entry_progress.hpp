#ifndef GTKMM_ENTRY_PROGRESS_WINDOW_H
#define GTKMM_ENTRY_PROGRESS_WINDOW_H

#include <gtkmm.h>

class EntryProgressWindow : public Gtk::Window {
  protected:
    Gtk::Box m_VBox;
    Gtk::Entry m_Entry;
    Gtk::Button m_Button_Close;

  public:
    EntryProgressWindow();
    virtual ~EntryProgressWindow();

  protected:
    bool on_timeout();
    void on_button_close();
    
};

#endif //GTKMM_ENTRY_PROGRESS_WINDOW_H