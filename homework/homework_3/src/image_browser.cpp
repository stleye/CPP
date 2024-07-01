#include "image_browser.hpp"
#include "html_writer.hpp"

namespace image_browser {

void AddFullRow(const ImageRow &row, bool first_row) {
  html_writer::OpenRow();
  html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), first_row);
  html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
  html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);
  html_writer::CloseRow();
}

void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {
  html_writer::OpenDocument();
  html_writer::AddCSSStyle(stylesheet);
  html_writer::AddTitle(title);
  html_writer::OpenBody();

  if (rows.size() > 0) {
    AddFullRow(rows[0], true);
    for (auto it = rows.cbegin() + 1; it != rows.cend(); ++it) {
      const ImageRow &row = *it;
      AddFullRow(row, false);
    }
  }

  html_writer::CloseBody();
  html_writer::CloseDocument();
}

} // namespace image_browser