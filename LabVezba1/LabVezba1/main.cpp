#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;




void RobinKapSearch(string T, string P, int d, int q) {

	int n = T.length();
	int m = P.length() ;
	int h = 1;
	ofstream f;
	string file = "rk.txt";
	f.open(file.c_str(), ios::out | ios::app);
	auto mStart = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	
	for (int i = 0; i < m - 1; i++)
		h = (h * d) % q;

	int p = 0;
	int ts = 0;

	for (int i = 0; i < m; i++) {
		p = (d * p + P[i]) % q;
		ts = (d * ts + T[i]) % q;
	}

	for (int s = 0; s <= n - m; s++) {
		if (p == ts) {

			bool flag = true;

			for (int j = 0; j < m; j++) {

				if (T[s + j] != P[j]) {
					flag = false;
					break;
				}
			}

			if (flag == true) {
				std::cout << "Poklapanje! Pozicija: " + s << endl;
				f << "Poklapanje na poziciji: " << s << endl;
				f << "Pronadjena rec: " << P << endl;
				auto ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - mStart;
				f << "Potrebno vreme : " << ms << "ms" << endl;
				f << endl;
			}


		}

		if (s < n - m) {
			ts = (d * (ts - T[s] * h) + T[s + m]) % q;

			if (ts < 0)
				ts = (ts + q);
		}
	}
	
	
	f.close();

}

void computePrefix(string P, int m, int* pi) {

	int len = 0;
	pi[0] = 0;


	for (int i = 1; i < m; i++) {

		while (len > 0 && P[len] != P[i])
			len = pi[len];
		if (P[len] == P[i]) {
			len++;
		}
		pi[i] = len;
	}
}

void KMPSearch(string T, string P) {


	int n = T.length();
	int m = P.length();

	int* pi = new int[m];
	ofstream f;
	string file = "kmp.txt";
	f.open(file.c_str(), ios::out | ios::app);
	auto mStart = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	computePrefix(P, m, pi);

	int q = 0; // broj karaktera koji se poklapaju

	for (int i = 0; i < n; i++) {

		while (q > 0 && P[q] != T[i]) {
			q = pi[q - 1]; // ne poklapa se sledeci karakter
		}
		if (P[q] == T[i]) { //sledeci karakter se poklapa
			q++; 
		}

		if (q == m) { // da li se u potpunosti poklapaju

			std::cout << "Poklapanje! Pozicija: " + i << endl;
			f << "Poklapanje na poziciji: " << i << endl;
			f << "Pronadjena rec: " << P << endl;
			auto mss = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - mStart;
			f << "Potrebno vreme:  " << mss << "ms" << endl;
			f << endl;
			q = pi[q -1]; //sledece poklapanje
		}
	

	}
	


	f.close();

}

string soundEx(string input) {

	string code = input;
	code[0] = toupper(input[0]);

	int matchCount = 1;
	int codeCount = 1;
	auto mStart = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	
	while ((matchCount < input.length()) /* && (codeCount < 4)*/) {

		if (((input[matchCount] == 'b') || (input[matchCount] == 'p') || (input[matchCount] == 'v') || (input[matchCount] == 'f')))
		{
			code[matchCount] = '1';
			
		}
		else if (((input[matchCount] == 'c') || (input[matchCount] == 'g') || (input[matchCount] == 'j') || (input[matchCount] == 'k') || (input[matchCount] == 'q') || (input[matchCount] == 's') || (input[matchCount] == 'x') || (input[matchCount] == 'z')))
		{
			code[matchCount] = '2';
		}
		else if (((input[matchCount] == 'd') || (input[matchCount] == 't')) )
		{
			code[matchCount] = '3';
		}
		else if ((input[matchCount] == 'l'))
		{
			code[matchCount] = '4';
		}
		else if (((input[matchCount] == 'm') || (input[matchCount] == 'n')))
		{
			code[matchCount] = '5';

		}
		else if ((input[matchCount] == 'r'))
		{
			code[matchCount] = '6';
		}
		matchCount++;
	}

	string rez = "";
	codeCount = 1;
	rez += code[0];

	while (codeCount < code.length()) {
		
		if (code[codeCount] >= '0' && code[codeCount] <= '9') {
			if (code[codeCount - 1] != code[codeCount]) {
				rez += code[codeCount];
			}
		}
		else {
			if (code[codeCount] == 'a' || code[codeCount] == 'e' || code[codeCount] == 'i' || code[codeCount] == 'o' || code[codeCount] == 'u') {
				if ((codeCount + 1) < code.length() && code[codeCount - 1] == code[codeCount + 1]) {
					rez += code[codeCount + 1];
					codeCount++;
				}
			}
			else if (code[codeCount] == 'h' || code[codeCount] == 'w') {
				if ((codeCount + 1) < code.length() && code[codeCount - 1] == code[codeCount + 1]) {
					codeCount++;
				}
			}
		}
		codeCount++;
	}

	while (rez.length() < 4) {

		rez += '0';
	}
	if (rez.length() > 4) {

		string novi = "";
		novi += rez[0];
		novi+=rez[rez.length() - 3];
		novi += rez[rez.length() - 2];
		novi+=rez[rez.length() - 1];
		rez = novi;
	}
	return rez;
}

void LevenshteinDistance(string s, string t) {

	int d[100][100];
	int m = s.length();
	int n = t.length();
	int j, i;
	int cost;
	int min;

	ofstream f;
	string file = "lDistance.txt";
	f.open(file.c_str(), ios::out | ios::app);
	auto mStart = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	for ( i = 0; i <= m; i++) {
		d[i][0] = i;
	}

	for (j = 0; j <= n; j++) {
		d[0][j] = j;
	}

	for (j = 1; j <= n; j++) {
		for (i = 1; i <= m; i++) {

			if (s[i - 1] == t[j - 1]) {
				cost = 0;
			}
			else {
				cost = 1;
			}

			min = ((d[i - 1][j] + 1) < d[i][j - 1] + 1) ? (d[i - 1][j] + 1) : (d[i][j - 1] + 1);
			d[i][j] = (min < (d[i - 1][j - 1] + cost)) ? min : (d[i - 1][j - 1] + cost);

		}
	}

	if (d[m][n] <= 3) {
		std::cout << "Potrebno najvise izmeniti tri karaktera reci " << s << " da bi se dobila rec " << t << endl;
		f << "Potrebno najvise izmeniti tri karaktera reci " << s << " da bi se dobila rec " << t << endl;
		auto ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - mStart;
		f << "Algoritam zavrsen nakon: " << ms << "ms" << endl;
		f << endl;
	}
	

	f.close();
}



int main() {

	fstream file;
	string word, filename;

	std::cout << "Unesite ime fajla (100[h].txt, 1000[h].txt, 10000[h].txt, 100000[h].txt): " << endl;
	cin >> filename;
	string trazi;

	string tcode;
	int q = 101;
	int d = 256;
	size_t found =  filename.find("h");
	if (found != string::npos) {
		d = 16;
		trazi = "af1f3";
		file.open(filename.c_str());
		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
				}
				k++;
			}
		}

		file.close();
		file.open(filename.c_str());
		trazi = "a84cdd0000";
		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
				}
				k++;
			}
		}

		file.close();
		file.open(filename.c_str());
		trazi = "8e0a7a84cdd0000";
		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
				}
				k++;
			}
		}

		file.close();


		file.open(filename.c_str());
		trazi = "f4c05c3e13f87a6de539";
		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
				}
				k++;
			}
		}

		file.close();
	}
	else {
		trazi = "level";
		tcode = soundEx(trazi);
		std::cout << "Kod trazene reci je: " << tcode << endl;
		file.open(filename.c_str());

		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				std::cout << rec<<endl;
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
					
						std::cout << "Kod reci je: ";
						code = soundEx(rec);
						std::cout << code << endl;
						if (code._Equal(tcode)) {

							ofstream f;
							string file = "soundEx.txt";
							f.open(file.c_str(), ios::out | ios::app);
							f << "Originalna rec: " << rec << endl;
							f << "Kod reci: " << code << endl;
							f << endl;
							f.close();

						}
					
				}
				k++;
			}
		}
		file.close();


		file.open(filename.c_str());

		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}
		trazi = "essentiall";
		tcode = soundEx(trazi);
		std::cout << "Kod trazene reci je: " << tcode << endl;

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
						std::cout << "Kod reci je: ";
						code = soundEx(rec);
						std::cout << code << endl;
						if (code._Equal(tcode)) {

							ofstream f;
							string file = "soundEx.txt";
							f.open(file.c_str(), ios::out | ios::app);
							f << "Originalna rec: " << rec << endl;
							f << "Kod reci: " << code << endl;
							f << endl;
							f.close();

						}
					
				}
				k++;
			}
		}

		file.close();


		file.open(filename.c_str());

		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}
		trazi = "essentiallylost";
		tcode = soundEx(trazi);
		std::cout << "Kod trazene reci je: " << tcode << endl;

		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
				
						std::cout << "Kod reci je: ";
						code = soundEx(rec);
						std::cout << code << endl;
						if (code._Equal(tcode)) {

							ofstream f;
							string file = "soundEx.txt";
							f.open(file.c_str(), ios::out | ios::app);
							f << "Originalna rec: " << rec << endl;
							f << "Kod reci: " << code << endl;
							f << endl;
							f.close();

						}
					
				}
				k++;
			}
		}

		file.close();


		file.open(filename.c_str());

		if (!file.is_open()) {
			std::cout << "Doslo je do greske pri otvaranju fajla!" << endl;
			return 0;
		}
		trazi = "essentiallylostempty";
		tcode = soundEx(trazi);
		std::cout << "Kod trazene reci je: " << tcode << endl;


		while (getline(file, word))
		{
			std::cout << "Procitana linija fajla je: " << word << endl;
			std::cout << "RobinKap algoritam: " << endl;
			RobinKapSearch(word, trazi, d, q);

			std::cout << "KMP algoritam: " << endl;
			KMPSearch(word, trazi);
			string rec;
			string code;
			int k = 0;

			while (k < word.length()) {
				rec = "";
				code = "";
				while (k < word.length() && word[k] != ' ' && word[k] != '.' && word[k] != ',') {
					rec += word[k++];
				}
				if (rec != "") {
					std::cout << "LevenshteinDistance algoritam" << endl;
					LevenshteinDistance(rec, trazi);
						std::cout << "Kod reci je: ";
						code = soundEx(rec);
						std::cout << code << endl;
						if (code._Equal(tcode)) {

							ofstream f;
							string file = "soundEx.txt";
							f.open(file.c_str(), ios::out | ios::app);
							f << "Originalna rec: " << rec << endl;
							f << "Kod reci: " << code << endl;
							f << endl;
							f.close();

						}
					
				}
				k++;
			}
		}

		file.close();
	}
	
	return 0;
}