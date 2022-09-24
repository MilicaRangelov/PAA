#include "LZW.h"

vector<int> encoding(char* karakteri,int n) {

	string kk = "";
	for (int i = 0; i < n; i++)
		kk += karakteri[i];

	unordered_map<string, int> table;
	auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

	for (int i = 0; i < 256; i++) {
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string p = "", c = "";
	p += kk[0];
	int code = 256;

	vector<int> output;
	cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < kk.length(); i++) {
		if (i != kk.length() - 1) {

			c += kk[i + 1];
		}
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << endl;
			output.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}

	auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";
	
	return output;
}

void decoding(vector<int> op)
{
    cout << "\nDecoding\n";
    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = op[0], n;
    string s = table[old];
    string c = "";
    c += s[0];
    cout << s;
    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        }
        else {
            s = table[n];
        }
        cout << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
}
