#include "Shannon_Fano.h"
#include "Huffman.h"
#include "LZW.h"

#define brKaraktera 52

char* freqq(char* simboli, int* freq, int* brRaz) {
	
	(*brRaz) = 0;
	char* karakteri = nizKaraktera();

	for (int i = 0; i < brKaraktera; i++) {

		if (simboli[i] >= 'a' && simboli[i] <= 'z') {
			if (freq[(simboli[i] - 'a')] == 0)
				(*brRaz)++;

			freq[(simboli[i] - 'a')]++;

		}
		else {
			if (freq[(simboli[i] - 'A' + 26)] == 0)
				(*brRaz)++;
			freq[(simboli[i] - 'A') + 26]++;
		}
	}



	return karakteri;
}
void generateArray(char* array1, char* array2, char* array3, int n) {

	string alphabet = "LoremIpsumissimplydummytextoftheprintingandtypesettingindustryLoremIpsumhasbeentheindustrysstandardd";
	while (alphabet.size() < n) {
		alphabet += alphabet;
	}
	cout << alphabet << endl;
	for (int i = 0; i < n; i++) {
		array2[i] = array3[i] = array1[i] = alphabet[i];
		//cout << array1[i] << " ";
	}
	//cout << endl;
}

int main() {

	int* niz = new int[brKaraktera];

	for (int i = 0; i < brKaraktera; i++)
		niz[i] = 0;

	//num of elements
	int n;

	n = 10000;
	char* array1 = new char[n];
	char* array2 = new char[n];
	char* array3 = new char[n];

	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;



	cout << "Shannon_Fano: " << endl;

	identifikujRazliciteSimbole(niz, array1, n);

	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	int brRazlic = 0;
	int* freq = new int[brKaraktera];
	for (int i = 0; i < brKaraktera; i++)
		freq[i] = 0;

	char* karakteri=freqq(array2, freq, &brRazlic);

	sortiraj(freq, karakteri);

	int* frekvencija = new int[brRazlic];
	char* karakteri2 = new char[brRazlic];

	for (int i = 0; i < brRazlic; i++) {
		frekvencija[i] = freq[i];
		karakteri2[i] = karakteri[i];
	}

	delete[] freq;
	delete[] karakteri;

	freq = new int[brRazlic];
	karakteri = new char[brRazlic];

	for (int i = 0; i < brRazlic; i++) {
		freq[i] = frekvencija[i];
		karakteri[i] = karakteri2[i];
	}

	delete[] frekvencija;
	delete[] karakteri2;
	cout << endl;

	cout << "Huffman: " << endl;
	int size = (brRazlic*sizeof(char)) / sizeof(karakteri[0]);
	HuffmanCodes(karakteri,freq,size);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "LZW: " << endl;
	
	vector<int> lzw = encoding(array3, n);
	for (int i = 0; i < lzw.size(); i++)
		cout << lzw[i] << " ";
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	decoding(lzw);
	return 0;

}




