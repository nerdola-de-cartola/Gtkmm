#include "label.hpp"
#include <iostream>

ExampleWindow::ExampleWindow():
  // Set ox
  m_HBox(Gtk::ORIENTATION_HORIZONTAL, 20),
  m_VBox(Gtk::ORIENTATION_VERTICAL, 10),
  m_VBox2(Gtk::ORIENTATION_VERTICAL, 10),

  // Set frames
  m_Frame_Normal("Normal Label"),
  m_Frame_Multi("Multi-line Label"),
  m_Frame_Left("Left Justified Label"),
  m_Frame_Right("Right Justified Label"),
  m_Frame_LineWrapped("Line wrapped label"),
  m_Frame_FilledWrapped("Filled, wrapped label"),
  m_Frame_Underlined("Underlined label"),
  
  // Set labels
  m_Label_Normal("_This is a Normal label", true),
  m_Label_Multi(
   "This is a Multi-line label.\n"
   "Second line\n"
   "Third line"
  ),
  m_Label_Left(
   "This is a Left-Justified\n"
   "Multi-line label.\n"
   "Third line"
  ),
  m_Label_Right(
   "This is a Right-Justified\n"
   "Multi-line label.\n"
   "Third line"
  ) {
  set_title("Label");
  set_border_width(5);
  set_default_size(600, 400);

  // Add the big box to the window
  add(m_HBox);

  // Add the two box frames to the big box
  m_HBox.pack_start(m_VBox, Gtk::PACK_SHRINK);
  m_HBox.pack_start(m_VBox2, Gtk::PACK_SHRINK);

  // Add frames to the left box
  m_VBox.pack_start(m_Frame_Normal, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Frame_Multi, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Frame_Left, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Frame_Right, Gtk::PACK_SHRINK);

  // Add frames to the right box
  m_VBox2.pack_start(m_Frame_LineWrapped, Gtk::PACK_SHRINK);
  m_VBox2.pack_start(m_Frame_FilledWrapped, Gtk::PACK_SHRINK);
  m_VBox2.pack_start(m_Frame_Underlined, Gtk::PACK_SHRINK);

  // Add labels to frames in the left box
  m_Frame_Normal.add(m_Label_Normal);
  m_Frame_Multi.add(m_Label_Multi);
  m_Frame_Left.add(m_Label_Left);
  m_Frame_Right.add(m_Label_Right);

  // Add labels to frames in the right box
  m_Frame_LineWrapped.add(m_Label_LineWrapped);
  m_Frame_FilledWrapped.add(m_Label_FilledWrapped);
  m_Frame_Underlined.add(m_Label_Underlined);

  // Justify labels in the left box
  m_Label_Left.set_justify(Gtk::JUSTIFY_LEFT);
  m_Label_Right.set_justify(Gtk::JUSTIFY_RIGHT);

  // Justify labels in the right box
  m_Label_FilledWrapped.set_justify(Gtk::JUSTIFY_FILL);
  m_Label_Underlined.set_justify(Gtk::JUSTIFY_LEFT);

  // Set line wrap
  m_Label_LineWrapped.set_line_wrap();
  m_Label_FilledWrapped.set_line_wrap();

  // Set underlined pattern
  m_Label_Underlined.set_pattern(
    "_________________________ _ _________ _ ______"
    "     __ _______ ___"
  );
  
  // Set text
  m_Label_LineWrapped.set_text(
    "This is an example of a line-wrapped label.  It "
    "should not be taking up the entire             "
    "width allocated to it, but automatically "
    "wraps the words to fit. "
    "The time has come, for all good men, to come to "
    "the aid of their party. "
    "The sixth sheik's six sheep's sick.\n"
    "   It supports multiple paragraphs correctly, "
    "and correctly adds "
    "many extra spaces."
  );
  m_Label_FilledWrapped.set_text(
    "This is an example of a line-wrapped, filled label.  "
    "It should be taking "
    "up the entire              width allocated to it.  "
    "Here is a sentence to prove "
    "my point.  Here is another sentence. "
    "Here comes the sun, do de do de do.\n"
    "    This is a new paragraph.\n"
    "    This is another newer, longer, better "
    "paragraph.  It is coming to an end, "
    "unfortunately."
  );
  m_Label_Underlined.set_text(
   "This label is underlined!\n"
   "This one is underlined in quite a funky fashion"
  );

  show_all_children();
}

ExampleWindow::~ExampleWindow() {}