#ifndef GTKMM_ENTRY_ICON_WINDOW
#define GTKMM_ENTRY_ICON_WINDOW

#include <gtkmm.h>

class EntryIconWindow : public Gtk::Window {
  protected:
    Gtk::Box m_VBox;
    Gtk::Entry m_Entry;
    Gtk::Button m_Button_Close;

  public:
    EntryIconWindow();
    virtual ~EntryIconWindow();

  protected:
    void on_icon_pressed(Gtk::EntryIconPosition icon_pos, const GdkEventButton* event);
    void on_button_close();
};

#endif //GTKMM_ENTRY_ICON_WINDOW