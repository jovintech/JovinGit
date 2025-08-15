#include "FileColumns.hpp"
#include <gtkmm.h>

class GridFiles : public Gtk::TreeView {
public:
  GridFiles() {
    set_size_request(-1, 500);
    set_margin_top(10);
    // Cria o modelo de colunas (definido logo abaixo)
    m_liststore = Gtk::ListStore::create(m_columns);
    set_model(m_liststore);

    auto toggle_renderer = Gtk::make_managed<Gtk::CellRendererToggle>();
    toggle_renderer->signal_toggled().connect(
        sigc::mem_fun(*this, &GridFiles::on_checkbox_toggled));

    auto col_toggle =
        Gtk::make_managed<Gtk::TreeViewColumn>("#", *toggle_renderer);
    col_toggle->add_attribute(toggle_renderer->property_active(),
                              m_columns.m_col_checked);
    col_toggle->set_fixed_width(40);
    append_column(*col_toggle);

    auto col_path = Gtk::make_managed<Gtk::TreeViewColumn>("Path");
    col_path->pack_start(m_columns.m_col_path);
    col_path->set_resizable(true);
    col_path->set_fixed_width(300);
    append_column(*col_path);

    auto col_extension = Gtk::make_managed<Gtk::TreeViewColumn>("Extension");
    col_extension->pack_start(m_columns.m_col_extension);
    col_extension->set_fixed_width(100 + 50);
    col_extension->set_resizable(true);
    append_column(*col_extension);

    auto col_status = Gtk::make_managed<Gtk::TreeViewColumn>("Status");
    col_status->pack_start(m_columns.m_col_status);
    col_status->set_fixed_width(100 + 50);
    col_status->set_resizable(true);
    append_column(*col_status);

    auto col_lines_add = Gtk::make_managed<Gtk::TreeViewColumn>("Lines Added");
    col_lines_add->pack_start(m_columns.m_col_lines_add);
    col_lines_add->set_fixed_width(100 + 50);
    col_lines_add->set_resizable(true);
    append_column(*col_lines_add);

    auto col_lines_removed =
        Gtk::make_managed<Gtk::TreeViewColumn>("Lines Removed");
    col_lines_removed->pack_start(m_columns.m_col_lines_removed);
    col_lines_removed->set_fixed_width(100 + 50);
    col_lines_removed->set_resizable(true);
    append_column(*col_lines_removed);
  }

  void addLine(const FileColumns &file) {
    auto row = *(m_liststore->append());
    row[m_columns.m_col_checked] = false;
    row[m_columns.m_col_path] = file.col_path;
    row[m_columns.m_col_extension] = file.col_extension;
    row[m_columns.m_col_status] = file.col_status;
    row[m_columns.m_col_lines_add] = file.col_lines_added;
    row[m_columns.m_col_lines_removed] = file.col_lines_removed;
  }

private:
  // Definição das colunas do modelo
  class ModelColumns : public Gtk::TreeModel::ColumnRecord {
  public:
    ModelColumns() {
      add(m_col_checked);
      add(m_col_path);
      add(m_col_extension);
      add(m_col_status);
      add(m_col_lines_add);
      add(m_col_lines_removed);
    }

    Gtk::TreeModelColumn<bool> m_col_checked;
    Gtk::TreeModelColumn<Glib::ustring> m_col_path;
    Gtk::TreeModelColumn<Glib::ustring> m_col_extension;
    Gtk::TreeModelColumn<Glib::ustring> m_col_status;
    Gtk::TreeModelColumn<int> m_col_lines_add;
    Gtk::TreeModelColumn<int> m_col_lines_removed;
  };

  ModelColumns m_columns;
  Glib::RefPtr<Gtk::ListStore> m_liststore;
  void on_checkbox_toggled(const Glib::ustring &path_string) {
    Gtk::TreeModel::Path path(path_string);
    auto iter = m_liststore->get_iter(path);
    if (iter) {
      auto row = *iter;
      row[m_columns.m_col_checked] = !row[m_columns.m_col_checked];
    }
  }
};
