#ifndef GTKMM_ENTRY_COMPLETION_WINDOW_H
#define GTKMM_ENTRY_COMPLETION_WINDOW_H

#include <gtkmm.h>
#include "model_columns.hpp"

class EntryCompletionWindow : public Gtk::Window {
  protected:
    typedef std::map<int, Glib::ustring> type_actions_map;
    type_actions_map m_CompletionActions;

    ModelColumns m_Columns;
    Gtk::Box m_HBox;
    Gtk::Box m_VBox;
    Gtk::Entry m_Entry;
    Gtk::Label m_Label;
    Gtk::Button m_Button_Close;


public:
  EntryCompletionWindow();
  Glib::RefPtr<Gtk::EntryCompletion> SetOptions(std::vector<Glib::ustring> options);
  virtual ~EntryCompletionWindow();

protected:
  //Signal handlers:
  void on_button_close();
  void on_completion_action_activated(int index);
  
};

#endif //GTKMM_ENTRY_COMPLETION_WINDOW_H