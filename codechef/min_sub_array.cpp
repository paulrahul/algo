#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(int argc, char** argv) {
	int l, s;
	cout << "Enter the size of the large array: ";
	cin >> l;

	int arr1[l];
	for (int i = 0; i < l; ++i) {
		cout << "\nEnter next element of large array:";
		cin >> arr1[i];
	}

	cout << "Enter the size of the small array: ";
	cin >> s;
	set<int> small_elements;
	int tmp;
	for (int i = 0; i < s; ++i) {
		cout << "\nEnter next element of small array:";
		cin >> tmp;
		small_elements.insert(tmp);
	}
	
	int count = 0;
	int start = -1;
	int end = -1;
	map<int, int> index_map;
	int min_size = -1;
	
	int ans_start_index = -1;
	int ans_end_index = -1;
	
	int i = 0;
	while (i < l) {
		if (small_elements.find(arr1[i]) == small_elements.end()) {
			i++;
			count = 0;
			start = -1;
			end = -1;
			continue;
		}
		
		if (start == -1) start = i;
	
		if (index_map.find(arr1[i]) == index_map.end() ||
			index_map[arr1[i]] < start) {
			count++;
		}
		index_map[arr1[i]] = i;
		end = i;
		
		if (count == s) {
			// move start point ahead.
			while (index_map[arr1[start]] > start) {
				start++;
			}
			
			if (min_size == -1 || (end - start + 1) < min_size) {
				ans_start_index = start;
				ans_end_index = end;
				min_size = ans_end_index - ans_start_index + 1;
			}
			
			start = start + 1;
			end = end;
			count -= 1; // the last end element is the starting of the new sub array.
		}
		
		i++;
	}
	
	
	cout << "The min sub array lies between indices " << ans_start_index << " and " << ans_end_index << endl;

	return 0;
}