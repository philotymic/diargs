#include <kvan/vector-io.h>

string to_json_string(const JKV& j)
{
  ostringstream out;
  out << "{";
  for (auto it = j.begin(); it != j.end(); ++it) {
    const auto& [k, v] = *it;
    out << "\"";
    for (auto kit = k.begin(); kit != k.end(); ++kit) {
      out << (*kit);
      if (next(kit) != k.end()) {
	out << ".";
      }
    }
    out << "\"";
    out << ": " << v;
    if (next(it) != j.end()) {
      out << ", ";
    }
  }
  out << "}";
  return out.str();
}

string to_csv_string(const JKV& j)
{
  ostringstream out;
  for (auto it = j.begin(); it != j.end(); ++it) {
    const auto& [k, v] = *it;
    out << v;
    if (next(it) != j.end()) {
      out << ",";
    }
  }
  return out.str();
}

