#include <string>

struct FileColumns {
  std::string col_path;
  std::string col_extension;
  std::string col_status;
  int col_lines_added = 0;
  int col_lines_removed = 0;
};
