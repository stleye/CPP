#include "html_writer.hpp"
#include "image_browser.hpp"
#include <cstdlib>

int main() {
  image_browser::ScoredImage image1("data/000000.png", 9.51);
  image_browser::ScoredImage image2("data/000100.png", 7.54);
  image_browser::ScoredImage image3("data/000200.png", 4.52);
  image_browser::ImageRow row1 = {image1, image2, image3};

  image_browser::ScoredImage image4("data/000300.png", 3.1);
  image_browser::ScoredImage image5("data/000400.png", 5.2);
  image_browser::ScoredImage image6("data/000500.png", 9);
  image_browser::ImageRow row2 = {image4, image5, image6};

  image_browser::ScoredImage image7("data/000600.png", 4.44);
  image_browser::ScoredImage image8("data/000700.png", 4.12);
  image_browser::ScoredImage image9("data/000800.png", 10);
  image_browser::ImageRow row3 = {image7, image8, image9};

  std::vector<image_browser::ImageRow> rows;

  rows.push_back(row1);
  rows.push_back(row2);
  rows.push_back(row3);

  image_browser::CreateImageBrowser("Test HTML Writer", "styles.css", rows);

  return EXIT_SUCCESS;
}
