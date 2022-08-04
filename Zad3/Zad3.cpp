// 3. Napisz funkcjê, która przyjmuje dwa stringi a nastêpnie zwraca vector ich wspólnych liter(powtarzajcych sie w obu stringach).

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector <char> bothStringsIncludes(const std::string& str1, const std::string& str2) {
	std::vector<char>letters;
	for (int i = 0; i < str1.size(); ++i) {
		for (int j = 0; j < str2.size(); ++j) {
			if (str1[i] == str2[j] && (str1[i] > 64 && str1[i] < 91 || str1[i]> 96 && str1[i] < 123)) {
				letters.push_back(str1[i]);
			}
		}
	}
	std::sort(letters.begin(), letters.end());
	letters.erase(std::unique(letters.begin(), letters.end()), letters.end()); // unique return ForwardIt to the new end of the range // erase(it first, it second)
	std::for_each(letters.begin(), letters.end(), [](char c) { std::cout << c << " "; });
	return letters;
}

int main()
{
	std::string str1 = "pajaczek, pajaczek";
	std::string str2 = "ma chyba ze sto raczek";
	bothStringsIncludes(str1, str2);

}


