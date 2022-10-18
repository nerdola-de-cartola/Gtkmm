#include "entry_completion.hpp"
#include <iostream>

EntryCompletionWindow::EntryCompletionWindow():
  m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_HBox(Gtk::ORIENTATION_HORIZONTAL),
  m_Label("Press a or b to see a list of possible completions and actions."),
  m_Button_Close("Close") {
  set_size_request(200, 100);
  set_title("Gtk::EntryCompletion");
  add(m_VBox);

  m_VBox.pack_start(m_Entry, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Label, Gtk::PACK_EXPAND_WIDGET);
  m_VBox.pack_start(m_Button_Close, Gtk::PACK_SHRINK);

  m_Button_Close.signal_clicked().connect(
    sigc::mem_fun(
      *this,
      &EntryCompletionWindow::on_button_close
    )
  );
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  std::vector<Glib::ustring> options;
  options.push_back("Alan Zebedee");
  options.push_back("Adrian Boo");
  options.push_back("Bob McRoberts");
  options.push_back("Bob McBob");
  auto completion = SetOptions(options);
  
  // display text in the entry when a match is found.
  completion->set_text_column(m_Columns.m_col_name);

  //Add actions to the completion:
  //These are just extra items shown at the bottom of the list of possible
  //completions.

  //Remember them for later.
  m_CompletionActions[0] = "Use Wizard";
  m_CompletionActions[1] = "Browse for Filename";

  for(const auto& the_pair : m_CompletionActions) {
    auto position = the_pair.first;
    auto title = the_pair.second;
    completion->insert_action_text(title, position);
  }

  completion->signal_action_activated().connect(
    sigc::mem_fun(
      *this,
      &EntryCompletionWindow::on_completion_action_activated
   )
  );

  show_all_children();
}

EntryCompletionWindow::~EntryCompletionWindow() {}

void EntryCompletionWindow::on_button_close() {
  hide();
}

void EntryCompletionWindow::on_completion_action_activated(int index) {
  type_actions_map::iterator iter = m_CompletionActions.find(index);

  //If it's in the map
  if(iter != m_CompletionActions.end()) {
    Glib::ustring title = iter->second;
    std::cout << "Action selected: " << title << std::endl;
  }
}

Glib::RefPtr<Gtk::EntryCompletion> EntryCompletionWindow::SetOptions(std::vector<Glib::ustring> options) {
  //Add an EntryCompletion:
  auto completion = Gtk::EntryCompletion::create();
  m_Entry.set_completion(completion);

  //Create and fill the completion's filter model
  auto refCompletionModel = Gtk::ListStore::create(m_Columns);
  completion->set_model(refCompletionModel);

  Gtk::TreeModel::Row row;
  for(int i = 1; i <= options.size(); i++) {
    row = *(refCompletionModel->append());
    row[m_Columns.m_col_id] = i;
    row[m_Columns.m_col_name] = options[i-1];
  }

  return completion;
}