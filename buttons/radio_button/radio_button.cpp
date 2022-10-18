#include "radio_button.hpp"

RadioButtons::RadioButtons() :
  m_Box_Top(Gtk::ORIENTATION_VERTICAL),
  m_Box1(Gtk::ORIENTATION_VERTICAL, 10),
  m_Box2(Gtk::ORIENTATION_VERTICAL, 10),
  m_RadioButton1("Drabon Ball Z"),
  m_RadioButton2("One Piece"),
  m_RadioButton3("Naruto"),
  m_Button_Close("close") {

  // Set size, title and border of the window
  set_default_size(500, 300);
  set_title("radio buttons");
  set_border_width(0);

  Gtk::RadioButton("Bla bla bla");

  // Put radio buttons 2 and 3 in the same group as 1:
  m_RadioButton2.join_group(m_RadioButton1);
  m_RadioButton3.join_group(m_RadioButton1);

  // Set the second button active
  m_RadioButton2.set_active();

  // Add outer box to the window (because the window
  // can only contain a single widget)
  add(m_Box_Top);

  //Put the inner boxes and the separator in the outer box:
  m_Box_Top.pack_start(m_Box1);
  m_Box_Top.pack_start(m_Separator);
  m_Box_Top.pack_start(m_Box2);

  // Set the inner boxes' borders
  m_Box1.set_border_width(10);
  m_Box2.set_border_width(10);

  // Put the radio buttons in Box1:
  m_Box1.pack_start(m_RadioButton1);
  m_Box1.pack_start(m_RadioButton2);
  m_Box1.pack_start(m_RadioButton3);

  // Put Close button in Box2:
  m_Box2.pack_start(m_Button_Close);

  // Make the button the default widget
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  // Connect the clicked signal of the buttons to their functions
  m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this,
              &RadioButtons::close_clicked) );
  m_RadioButton1.signal_clicked().connect(sigc::mem_fun(*this,
              &RadioButtons::btn1_clicked) );
  m_RadioButton2.signal_clicked().connect(sigc::mem_fun(*this,
              &RadioButtons::btn2_clicked) );
  m_RadioButton3.signal_clicked().connect(sigc::mem_fun(*this,
              &RadioButtons::btn3_clicked) );

  // Show all children of the window
  show_all_children();
}

RadioButtons::~RadioButtons() {}

void RadioButtons::close_clicked() {
  hide(); //to close the application.
}

void RadioButtons::btn1_clicked() {
  std::cout << "Dargon Ball Z activated" << std::endl;
}

void RadioButtons::btn2_clicked() {
  std::cout << "One piece activated" << std::endl;
}

void RadioButtons::btn3_clicked() {
  std::cout << "Naruto activated" << std::endl;
}