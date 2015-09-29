#include <algorithm>
#include <iostream>
#include <set>


using namespace std;

int main() {
  set<string> names;
  names.insert("rahul");
  names.insert("rocky");

  set<string> fullnames;
  fullnames.insert("rahulpaul");
  fullnames.insert("rahulsingh");

  bool found =
    all_of(names.begin(), names.end(),
           [](string name) {
             return any_of(fullnames.begin(), fullnames.end(),
                    [](string fullname) { return fullname.substr(name) != string::npos)};
           });

   cout << found << endl;

  return 0;
}
