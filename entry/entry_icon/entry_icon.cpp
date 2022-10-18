#include "entry_icon.hpp"
#include <iostream>

EntryIconWindow::EntryIconWindow():
  m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Close("Close") {

  set_title("Gtk::Entry");
  add(m_VBox);

  m_VBox.pack_start(m_Entry, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Button_Close, Gtk::PACK_SHRINK);

  m_Entry.set_max_length(50);
  m_Entry.set_text("Hello world");
  m_Entry.set_icon_from_icon_name("edit-find");
  m_Entry.signal_icon_press().connect(sigc::mem_fun(*this, &EntryIconWindow::on_icon_pressed));


  m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this, &EntryIconWindow::on_button_close));
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  show_all_children();
}

EntryIconWindow::~EntryIconWindow() {}

void EntryIconWindow::on_icon_pressed(Gtk::EntryIconPosition icon_pos, const GdkEventButton* event) {
  std::cout << "Icon pressed." << std::endl;
}

void EntryIconWindow::on_button_close() {
  std::cout << "Close button pressed" << std::endl;
  hide();
}
