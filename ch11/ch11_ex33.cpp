/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.33:
Implement your own version of the word-transformation program.
******************************************************************************/

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
  std::map<std::string, std::string> trans_map;  // holds the transformation
  std::string key;                               // a word to transform
  std::string value;                             // phrase to use instead
  // read the first word int key and the rest of the line into value
  while (map_file >> key && getline(map_file, value))
    if (value.size() > 1)                // check that there is a transformation
      trans_map[key] = value.substr(1);  // skip leading space
    else
      throw std::runtime_error("no rule for " + key);
  return trans_map;
}

const std::string &transform(const std::string &s,
                             const std::map<std::string, std::string> &m) {
  // the actual map work; this part is the heart of the program
  auto map_it = m.find(s);
  // if this word is in the transformation map
  if (map_it != m.cend())
    return map_it->second;  // use the replacement word
  else
    return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
  auto trans_map = buildMap(map_file);  // strore the transformations
  std::string text;                     // hold each line fron the input
  while (getline(input, text)) {        // read a line of input
    std::istringstream stream(text);    // read each word
    std::string word;
    bool firstword = true;  // control whether as space is printed
    while (stream >> word) {
      if (firstword)
        firstword = false;
      else
        std::cout << " ";                       // print a space between words
      std::cout << transform(word, trans_map);  // print output
    }
    std::cout << std::endl;  // done with this line input
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << *argv << " <rules file> <input file>\n";
    return -1;
  }
  auto pm = *++argv;  // pointer to map (rule) file name
  auto pi = *++argv;  // pointer to input ile name
  std::ifstream mapFile((pm)), inFile(pi);
  if (!mapFile || !inFile) {
    std::cerr << "Couldn't open " << ((!mapFile) ? pm : pi) << '\n';
    return -1;
  }
  word_transform(mapFile, inFile);
  return 0;
}
