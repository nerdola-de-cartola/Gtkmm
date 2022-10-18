#include "entry_progress.hpp"
#include <iostream>

EntryProgressWindow::EntryProgressWindow():
  m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Close("Close") {

  set_title("Gtk::Entry");
  add(m_VBox);

  m_VBox.pack_start(m_Entry, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Button_Close, Gtk::PACK_SHRINK);

  m_Entry.set_max_length(50);
  m_Entry.set_text("Hello world");

  //Change the progress fraction every 0.1 second:
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &EntryProgressWindow::on_timeout), 100);

  m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this, &EntryProgressWindow::on_button_close));
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  show_all_children();
}

EntryProgressWindow::~EntryProgressWindow() {}

bool EntryProgressWindow::on_timeout() {
  static double fraction = 0;
  m_Entry.set_progress_fraction(fraction);
  std::cout << fraction << std::endl;

  fraction += 0.01;
  if(fraction > 1) fraction = 0;

  return true;
}

void EntryProgressWindow::on_button_close() {
  hide();
}
