#include "entry.hpp"
#include <iostream>

ExampleWindow::ExampleWindow():
  m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
  m_HBox(Gtk::ORIENTATION_HORIZONTAL, 5),
  m_HBox2(Gtk::ORIENTATION_HORIZONTAL, 5),
  m_Label("Name"),
  m_Button_Close("Close"),
  m_CheckButton_Editable("Editable"),
  m_CheckButton_Visible("Visible") {

  set_size_request(225, 100);
  set_title("Entry");
  set_border_width(6);

  // Note that add() can also be used instead of pack_xxx()
  add(m_VBox);
  m_VBox.add(m_HBox); // Entry
  m_VBox.add(m_HBox2); // Check buttons
  m_VBox.add(m_Button_Close); // Close button

  // Add entry
  m_HBox.add(m_Label);
  m_HBox.add(m_Entry);

  // Add check buttons
  m_HBox2.add(m_CheckButton_Editable);
  m_HBox2.add(m_CheckButton_Visible);

  // Entry
  m_Entry.set_max_length(50);
  m_Entry.set_text("hello");
  m_Entry.set_text(m_Entry.get_text() + " world");
  m_Entry.select_region(0, m_Entry.get_text_length());

  // Check buttons
  m_CheckButton_Editable.set_active(true);
  m_CheckButton_Visible.set_active(true);

  // Close button
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  // Set signals
  m_Entry.signal_changed().connect(
     sigc::mem_fun(
       *this,
       &ExampleWindow::on_entry_changed
     )
  );
  m_CheckButton_Editable.signal_toggled().connect(
     sigc::mem_fun(
       *this,
       &ExampleWindow::on_checkbox_editable_toggled
     )
  );
  m_CheckButton_Visible.signal_toggled().connect(
    sigc::mem_fun(
      *this,
      &ExampleWindow::on_checkbox_visibility_toggled
    )
  );
  m_Button_Close.signal_clicked().connect(
   sigc::mem_fun(
     *this,
     &ExampleWindow::on_button_close
   )
  );

  show_all_children();
}

ExampleWindow::~ExampleWindow() {}

void ExampleWindow::on_checkbox_editable_toggled() {
  m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void ExampleWindow::on_checkbox_visibility_toggled() {
  m_Label.set_text("Password");
  m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}

void ExampleWindow::on_button_close() {
  hide();
}

void ExampleWindow::on_entry_changed() {
  std::cout << m_Entry.get_text() << std::endl;
}