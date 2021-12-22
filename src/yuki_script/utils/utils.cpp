#include "utils.hpp"

#include <iostream>

#include <algorithm>
#include <sstream>
#include <vector>

#include <boost/algorithm/string/replace.hpp>

#include "token_utils.hpp"

void yuki::utils::process_whitespaces(std::string &code) {
  static auto ctrl_check = [](unsigned char x) { return std::iscntrl(x); };

  static auto double_space_check = [](char lhs, char rhs) {
    return (lhs == rhs) && (lhs == ' ');
  };

  auto new_end = std::remove_if(code.begin(), code.end(), ctrl_check);
  code.erase(new_end, code.end());

  new_end = std::unique(code.begin(), code.end(), double_space_check);
  code.erase(new_end, code.end());

  boost::replace_all(code, "( ", "(");
  boost::replace_all(code, " )", ")");

  boost::replace_all(code, ") )", "))");
  boost::replace_all(code, "( (", "((");
  boost::replace_all(code, ") (", ")(");
}

namespace {
void print_tree_impl(const std::string &code, std::ostream &os,
                     std::size_t level) {
  auto tokens = yuki::utils::separate_tokens(code);
  if (tokens.size() > 1 || (tokens.size() == 1 && tokens[0][0] == '(')) {
    for (const auto &tok : tokens) {
      for (auto i = 0u; i < level; ++i) {
        os << "|\t";
      }

      std::cout << tok << std::endl;
      print_tree_impl(tok, os, level + 1);
    }
  }
}
} // namespace

void yuki::utils::print_tree(const std::string &code, std::ostream &os) {
  std::string processed_code = code;
  process_whitespaces(processed_code);
  return print_tree_impl(processed_code, os, 0);
}
