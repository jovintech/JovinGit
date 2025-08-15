#include "MainWindow.hpp"
#include "../service/git/Git.hpp"
#include "../tools/Utils.hpp"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include <gtkmm.h>

MainWindow::MainWindow() {
  set_title("JovinGit");
  set_default_size(800, 800);
  set_position(Gtk::WIN_POS_CENTER);

  css();

  commit.get_style_context()->add_class("commit-button");
  commit.set_label("Commit");
  commit.set_size_request(60);

  cancel.get_style_context()->add_class("cancel-button");
  cancel.set_label("Cancel");
  cancel.set_size_request(60);
  cancel.signal_clicked().connect(
      sigc::mem_fun(*this, &MainWindow::on_cancel_clicked));

  branch.set_label("Commit to: " + Git::getBranchCurrent());
  branch.set_halign(Gtk::Align::ALIGN_START);

  message.set_editable(true);
  message.set_can_focus(true);
  message.set_size_request(-1, 140);

  archivesLbl.set_label(Utils::getPathCurrent());
  archivesLbl.set_halign(Gtk::Align::ALIGN_START);

  vbottomBox.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  vbottomBox.set_spacing(10);
  vbottomBox.set_margin_top(10);
  vbottomBox.pack_end(commit, Gtk::PackOptions::PACK_SHRINK);
  vbottomBox.pack_end(cancel, Gtk::PackOptions::PACK_SHRINK);

  vgeneralbox.set_spacing(10);
  vgeneralbox.set_margin_right(20);
  vgeneralbox.set_margin_left(20);
  vgeneralbox.set_margin_bottom(20);
  vgeneralbox.set_margin_top(20);

  vgeneralbox.pack_start(branch, Gtk::PackOptions::PACK_SHRINK);
  vgeneralbox.pack_start(message, Gtk::PackOptions::PACK_SHRINK);
  vgeneralbox.pack_start(archivesLbl, Gtk::PackOptions::PACK_SHRINK);
  vgeneralbox.pack_start(grid, Gtk::PackOptions::PACK_SHRINK);
  vgeneralbox.pack_start(vbottomBox, Gtk::PackOptions::PACK_SHRINK);

  vgeneralbox.set_orientation(Gtk::ORIENTATION_VERTICAL);

  set_resizable(false);

  add(vgeneralbox);
  show_all_children();
}

void MainWindow::css() {
  auto css_provider = Gtk::CssProvider::create();
  css_provider->load_from_data(R"(
            .commit-button {
                background-image: none;
                background-color: #4CAF50;
                color: white;
                font-weight: bold;
                border-radius: 8px;
                padding: 8px;
            }
            .commit-button {
                background-color: #45a049;
            }

            .cancel-button {
                background-image: none;
                background-color: #f44336;
                color: white;
                font-weight: bold;
                border-radius: 8px;
                padding: 8px;
            }
            .cancel-button:hover {
                background-color: #d32f2f;
            }
        )");

  auto screen = Gdk::Screen::get_default();
  Gtk::StyleContext::add_provider_for_screen(screen, css_provider,
                                             GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void MainWindow::on_cancel_clicked() { hide(); }
