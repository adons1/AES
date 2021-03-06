#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int Sbox[16][16] = {
	{ 1100011, 1111100, 1110111, 1111011, 11110010, 1101011, 1101111 ,11000101 ,110000 ,1, 1100111 ,101011 ,11111110, 11010111, 10101011, 1110110 } ,
{ 11001010, 10000010, 11001001 ,1111101, 11111010, 1011001 ,1000111 ,11110000 ,10101101 ,11010100 ,10100010 ,10101111, 10011100 ,10100100, 1110010, 11000000 } ,
{ 10110111 ,11111101, 10010011, 100110 ,110110, 111111, 11110111, 11001100, 110100, 10100101, 11100101, 11110001, 1110001, 11011000, 110001 ,10101 } ,
{ 100, 11000111, 100011, 11000011 ,11000 ,10010110 ,101 ,10011010, 111 ,10010, 10000000, 11100010, 11101011, 100111, 10110010 ,1110101 } ,
{ 1001, 10000011, 101100, 11010, 11011, 1101110 ,1011010, 10100000, 1010010, 111011, 11010110, 10110011, 101001 ,11100011, 101111 ,10000100 } ,
{ 1010011, 11010001, 0 ,11101101, 100000, 11111100 ,10110001, 1011011, 1101010, 11001011, 10111110, 111001, 1001010 ,1001100, 1011000 ,11001111 } ,
{ 11010000, 11101111, 10101010, 11111011, 1000011, 1001101 ,110011, 10000101, 1000101, 11111001, 10, 1111111, 1010000, 111100, 10011111, 10101000 } ,
{ 1010001, 10100011, 1000000, 10001111, 10010010, 10011101 ,111000, 11110101, 10111100 ,10110110, 11011010, 100001, 10000, 11111111, 11110011, 11010010 } ,
{ 11001101, 1100, 10011, 11101100 ,1011111, 10010111, 1000100, 10111, 11000100 ,10100111, 1111110, 111101, 1100100, 1011101, 11001, 1110011 } ,
{ 1100000 ,10000001, 1001111, 11011100, 100010, 101010, 10010000, 10001000, 1000110, 11101110, 10111000, 10100, 11011110, 1011110, 1011 ,11011011 } ,
{ 11100000, 110010, 111010, 1010, 1001001, 110, 100100, 1011100, 11000010, 11010011 ,10101100, 1100010, 10010001, 10010101, 11100100, 1111001 } ,
{ 11100111, 11001000, 110111, 1101101, 10001101, 11010101, 1001110, 10101001, 1101100, 1010110, 11110100, 11101010 ,1100101, 1111010 ,10101110 ,1000 } ,
{ 10111010, 1111000, 100101 ,101110, 11100, 10100110, 10110100, 11000110, 11101000, 11011101, 1110100, 11111, 1001011, 10111101 ,10001011, 10001010 } ,
{ 1110000 ,111110, 10110101 ,1100110 ,1001000, 11, 11110110, 1110, 1100001, 110101, 1010111 ,10111001, 10000110, 11000001 ,11101 ,10011110 } ,
{ 11100001, 11111000 ,10011000 ,10001 ,1101001, 11011001, 10001110 ,10010100, 10011011, 11110, 10000111, 11101001, 11001110, 1010101, 101000 ,11011111 } ,
{ 10001100 ,10100001 ,10001001 ,1101, 10111111, 11100110 ,1000010, 1101000, 1000001, 10011001, 101101 ,1111, 10110000, 1010100, 10111011, 10110 } ,

};
int InvSbox[16][16] = {
	{ 1010010, 1001, 1101010, 11010101, 110000, 110110, 10100101, 111000, 10111111, 1000000, 10100011, 10011110, 10000001, 11110011, 11010111, 11111011 },
{ 1111100, 11100011, 111001, 10000010, 10011011, 101111, 11111111, 10000111, 110100, 10001110, 1000011, 1000100, 11000100, 11011110, 11101001, 11001011 },
{ 1010100, 1111011, 10010100, 110010, 10100110, 11000010, 100011, 111101, 11101110, 1001100, 10010101, 1011, 1000010, 11111010, 11000011, 1001110 },
{ 1000, 101110, 10100001, 1100110, 101000, 11011001, 100100, 10110010, 1110110, 1011011, 10100010, 1001001, 1101101, 10001011, 11010001, 100101 },
{ 1110010, 11111000, 11110110, 1100100, 10000110, 1101000, 10011000, 10110, 11010100, 10100100, 1011100, 11001100, 1011101, 1100101, 10110110, 10010010 },
{ 1101100, 1110000, 1001000, 1010000, 11111101, 11101101, 10111001, 11011010, 1011110, 10101, 1000110, 1010111, 10100111, 10001101, 10011101, 10000100 },
{ 10010000, 11011000, 10101011, 0, 10001100, 10111100, 11010011, 1010, 11110111, 11100100, 1011000, 101, 10111000, 10110011, 1000101, 110 },
{ 11010000, 101100, 11110, 10001111, 11001010, 111111, 1111, 10, 11000001, 10101111, 10111101, 11, 1, 10011, 10001010, 1101011 },
{ 111010, 10010001, 10001, 1000001, 1001111, 1100111, 11011100, 11101010, 10010111, 11110010, 11001111, 11001110, 11110000, 10110100, 11100110, 1110011 },
{ 10010110, 10101100, 1110100, 100010, 11100111, 10101101, 110101, 10000101, 11100010, 11111001, 110111, 11101000, 11100, 1110101, 11011111, 1101110 },
{ 1000111, 11110001, 11010, 1110001, 11101, 101001, 11000101, 10001001, 1101111, 10110111, 1100010, 1110, 10101010, 11000, 10111110, 11011 },
{ 11111100, 1010110, 111110, 1001011, 11000110, 11010010, 1111001, 100000, 10011010, 11011011, 11000000, 11111110, 1111000, 11001101, 1011010, 11110100 },
{ 11111, 11011101, 10101000, 110011, 10001000, 111, 11000111, 110001, 10110001, 10010, 10000, 1011001, 100111, 10000000, 11101100, 1011111 },
{ 1100000, 1010001, 1111111, 10101001, 11001, 10110101, 1001010, 1101, 101101, 11100101, 1111010, 10011111, 10010011, 11001001, 10011100, 11101111 },
{ 10100000, 11100000, 111011, 1001101, 10101110, 101010, 11110101, 10110000, 11001000, 11101011, 10111011, 111100, 10000011, 1010011, 10011001, 1100001 },
{ 10111, 101011, 100, 1111110, 10111010, 1110111, 11010110, 100110, 11100001, 1101001, 10100, 1100011, 1010101, 100001, 1100, 1111101 },
};
int Rcon[10][4] = {
	{ 1, 0, 0, 0 },
{ 10, 0, 0, 0 },
{ 100, 0, 0, 0 },
{ 1000, 0, 0, 0 },
{ 10000, 0, 0, 0 },
{ 100000, 0, 0, 0 },
{ 1000000, 0, 0, 0 },
{ 10000000, 0, 0, 0 },
{ 11011, 0, 0, 0 },
{ 110110, 0, 0, 0 }
};
void ASCII_print() {
	for (int i = 0; i < 256; i++) {
		cout << char(i) << "\t";
		if (i % 16 == 0) {
			cout << endl;
		}
	}
}
int decimal_to_binary(int x) {
	int binary = 0;
	double i = 0;
	double k = 10;
	while (x > 0) {
		binary = binary + (int)pow(k, i)*(x % 2);
		x = x / 2;
		++i;
	}
	return binary;
}
int binary_to_decimal(int binary) {
	int x = 0;
	double i = 0;
	double k = 2;
	while (binary > 0) {
		x = x + (int)pow(k, i)*(binary % 10);
		binary = binary / 10;
		++i;
	}
	return x;
}
int gf_sum(int a, int b) {
	return a ^ b;
}
int gf_multiply(int a, int b) {
	int binary_a = decimal_to_binary(a);
	int binary_b = decimal_to_binary(b);

	int B[8];
	double k = 10;
	for (int i = 0; i < 8; i++) {
		B[i] = binary_b / (int)pow(k, 7 - i);
		binary_b = binary_b % (int)pow(k, 7 - i);
	}
	/*for (int i = 0; i < 8; i++) {
	cout << B[i]<<"\n \n \n";

	}*/
	int m = binary_to_decimal(100011011);
	int a_c = a;
	int res = 0;
	for (int i = 0; i < 8; i++) {
		if (B[7 - i] == 1) {
			for (int j = 0; j < i; j++) {
				//cout << decimal_to_binary(a_c) << endl;
				a_c = a_c << 1;
				if (decimal_to_binary(a_c) / 100000000 == 1) {
					a_c = a_c ^ m;

				}
			}
			//cout << decimal_to_binary(a_c) << "---------------------\n";
			res = a_c ^ res;
			a_c = a;
		}

	}
	return decimal_to_binary(res);
}
int gf_multiply_a(int a, int b) {
	int binary_a = decimal_to_binary(a);
	int binary_b = decimal_to_binary(b);

	int a_c = a;
	double k = 10;
	int res = 0;
	int y;
	int m = binary_to_decimal(100011011);
	for (int i = 0; i < 8; i++) {
		y = binary_b % (int)pow(k, i);
		if (y == 1) {
			for (int j = 0; j < i; j++) {
				cout << decimal_to_binary(a_c) << endl;
				a_c = a_c << 1;
				if (decimal_to_binary(a_c) / 100000000 == 1) {
					a_c = a_c ^ m;
				}
			}
			cout << decimal_to_binary(a_c) << "---------------------\n";
			res = a_c ^ res;
			a_c = a;

		}

		binary_b = binary_b / (int)pow(k, i);
	}



	return decimal_to_binary(res);
}
void print_array_2d(int **p) {
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			cout << *(*(p + i) + j) << "\t";
		}
		cout << endl;
	}
}
void print_array_2d(char **p) {

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			cout << *(*(p + i) + j) << "\t";
		}
		cout << endl;
	}
}
int char_to_binary(char ch) {
	int  x = decimal_to_binary(int(ch));
	if (int(ch)<0) {
		x = decimal_to_binary(int(ch) + 256);
	}

	return x;
}
char binary_to_char(int  x) {
	char  ch = char(binary_to_decimal(x));
	return ch;
}
int SubBytes(int p) {
	int collumn = binary_to_decimal(p / 10000);
	int row = binary_to_decimal(p % 10000);
	//cout << collumn <<"\t"<< row << endl;
	return (Sbox[collumn][row]);
}
char SubBytes(char p) {
	int collumn = char_to_binary(p) / 10000;
	int row = char_to_binary(p) % 10000;
	//cout << collumn <<"\t"<< row << endl;
	return binary_to_char(Sbox[binary_to_decimal(collumn)][binary_to_decimal(row)]);
}
void SubBytes(char **buffer) {
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int collumn = char_to_binary(buffer[i][j]) / 10000;
			int row = char_to_binary(buffer[i][j]) % 10000;
			//cout << collumn <<"\t"<< row << endl;
			buffer[i][j] = binary_to_char(Sbox[binary_to_decimal(collumn)][binary_to_decimal(row)]);
		}
	}
}
void InvSubBytes(char **buffer) {
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int collumn = char_to_binary(buffer[i][j]) / 10000;
			int row = char_to_binary(buffer[i][j]) % 10000;
			//cout << collumn <<"\t"<< row << endl;
			buffer[i][j] = binary_to_char(InvSbox[binary_to_decimal(collumn)][binary_to_decimal(row)]);
		}
	}
}
void ShiftRows(char **buffer) {
	int state[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 10111111,10110100,1000001,100111 },
		{ 1011101,1010010,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = char_to_binary(buffer[i][j]);
		}
	}
	int a = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < i; j++) {
			a = state[i][0];
			for (int k = 0; k < 3; k++) {
				state[i][k] = state[i][k + 1];
			}
			state[i][3] = a;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[i][j] = binary_to_char(state[i][j]);
		}
	}
}
void InvShiftRows(char **buffer) {
	int state[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 10111111,10110100,1000001,100111 },
		{ 1011101,1010010,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = char_to_binary(buffer[i][j]);
		}
	}
	int a = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < i; j++) {
			a = state[i][3];
			for (int k = 3; k > 0; k--) {
				state[i][k] = state[i][k - 1];
			}
			state[i][0] = a;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[i][j] = binary_to_char(state[i][j]);
		}
	}
}
void MixColumns(char **buffer) {

	int mixer[4][4] = {
		{ 10,11,1,1 },
		{ 1,10,11,1 },
		{ 1,1,10,11 },
		{ 11,1,1,10 },
	};

	int state[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 10111111,10110100,1000001,100111 },
		{ 1011101,1010010,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};

	int mixed[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 1011111,10110100,1000001,1000111 },
		{ 1011101,1010100,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = char_to_binary(buffer[i][j]);
		}
	}


	int l = 0;
	int res = 0;
	int k = 0;
	int m = 0;
	int n = 0;

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 4; j++) {
			l = binary_to_decimal(gf_multiply(binary_to_decimal(*(*(mixer + (i % 4)) + j)), binary_to_decimal(*(*(state + j) + m))));
			res = l ^ res;	
		}
		*(*(mixed + (i % 4)) + m) = decimal_to_binary(res);
		res = 0;
		++k;
		if (k > 3) {
			k = 0;
			++m;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[i][j] = binary_to_char(mixed[i][j]);
		}
	}

}
void InvMixColumns(char **buffer) {



	int mixer[4][4] = {
		{ 1110,1011,1101,1001 },
		{ 1001,1110,1011,1101 },
		{ 1101,1001,1110,1011 },
		{ 1011,1101,1001,1110 },
	};

	int state[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 10111111,10110100,1000001,100111 },
		{ 1011101,1010010,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};

	int mixed[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 1011111,10110100,1000001,1000111 },
		{ 1011101,1010100,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = char_to_binary(buffer[i][j]);
		}
	}


	int l = 0;
	int res = 0;
	int k = 0;
	int m = 0;
	int n = 0;

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 4; j++) {
			l = binary_to_decimal(gf_multiply(binary_to_decimal(*(*(mixer + (i % 4)) + j)), binary_to_decimal(*(*(state + j) + m))));
			res = l ^ res;
		}
		*(*(mixed + (i % 4)) + m) = decimal_to_binary(res);
		res = 0;
		++k;
		if (k > 3) {
			k = 0;
			++m;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[i][j] = binary_to_char(mixed[i][j]);
		}
	}
}
void KeyExpansion(int(*key)[4][11]) {

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < 4; j++) {
			//cout <<"---------------"<< SubBytes(key[1][3][i - 1]) <<"\t"<< binary_to_decimal(key[0][0][i - 1]) <<"\t"<< binary_to_decimal(Rcon[i - 1][0]) << endl;

			if (j == 0) {
				key[0][0][i] = decimal_to_binary(binary_to_decimal(SubBytes(key[1][3][i - 1])) ^ binary_to_decimal(key[0][0][i - 1]) ^ binary_to_decimal(Rcon[i - 1][0]));
				key[1][0][i] = decimal_to_binary(binary_to_decimal(SubBytes(key[2][3][i - 1])) ^ binary_to_decimal(key[1][0][i - 1]) ^ binary_to_decimal(Rcon[i - 1][1]));
				key[2][0][i] = decimal_to_binary(binary_to_decimal(SubBytes(key[3][3][i - 1])) ^ binary_to_decimal(key[2][0][i - 1]) ^ binary_to_decimal(Rcon[i - 1][2]));
				key[3][0][i] = decimal_to_binary((binary_to_decimal(SubBytes(key[0][3][i - 1]))) ^ binary_to_decimal(key[3][0][i - 1]) ^ binary_to_decimal(Rcon[i - 1][3]));

			}
			if (j != 0) {
				key[0][j][i] = decimal_to_binary(binary_to_decimal(key[0][j - 1][i]) ^ binary_to_decimal(key[0][j][i - 1]));
				key[1][j][i] = decimal_to_binary(binary_to_decimal(key[1][j - 1][i]) ^ binary_to_decimal(key[1][j][i - 1]));
				key[2][j][i] = decimal_to_binary(binary_to_decimal(key[2][j - 1][i]) ^ binary_to_decimal(key[2][j][i - 1]));
				key[3][j][i] = decimal_to_binary(binary_to_decimal(key[3][j - 1][i]) ^ binary_to_decimal(key[3][j][i - 1]));
			}
		}
	}

}
void AddRoundKey(char **buffer, int key[4][4][11], int k) {
	int state[4][4] = {
		{ 11010100,11100000,10111000,11110 },
		{ 10111111,10110100,1000001,100111 },
		{ 1011101,1010010,10001,10011000 },
		{ 110000,10101110,11110001,11100101 },
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = char_to_binary(buffer[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] = decimal_to_binary(binary_to_decimal(state[i][j]) ^ binary_to_decimal(key[i][j][k]));
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[i][j] = binary_to_char(state[i][j]);
		}
	}
}
void Encode(char **buffer, int key[4][4][11]) {
	AddRoundKey(buffer, key, 0);
	for (int i = 1; i <= 9; i++) {
		SubBytes(buffer);
		ShiftRows(buffer);
		MixColumns(buffer);
		AddRoundKey(buffer, key, i);
	}
	SubBytes(buffer);
	ShiftRows(buffer);
	AddRoundKey(buffer, key, 10);
}
void Decode(char **buffer, int key[4][4][11]) {
	AddRoundKey(buffer, key, 10);
	InvShiftRows(buffer);
	InvSubBytes(buffer);

	for (int i = 9; i >= 1; i--) {
		AddRoundKey(buffer, key, i);
		InvMixColumns(buffer);
		InvShiftRows(buffer);
		InvSubBytes(buffer);
	}
	AddRoundKey(buffer, key, 0);

}
int main()
{
	setlocale(LC_ALL, "Russian");
	//Инициализация с примера
	int state[4][4] = {
		{ 110010,10001000,110001,11100000 },
	{ 1000011,1011010,110001,110111 },
	{ 11110110,110000,10011000,111 },
	{ 10101000,10001101,10100010,110100 },
	};
	int key[4][4][11];
	key[0][0][0] = 101011;
	key[0][1][0] = 101000;
	key[0][2][0] = 10101011;
	key[0][3][0] = 1001;
	key[1][0][0] = 1111110;
	key[1][1][0] = 10101110;
	key[1][2][0] = 11110111;
	key[1][3][0] = 11001111;
	key[2][0][0] = 10101;
	key[2][1][0] = 11010010;
	key[2][2][0] = 10101;
	key[2][3][0] = 1001111;
	key[3][0][0] = 10110;
	key[3][1][0] = 10100110;
	key[3][2][0] = 10001000;
	key[3][3][0] = 111100;
	//Инициализация в общем случае
	string message = "";
	string key_word = "";
	int u = 0;
	while (u != 16) {
		cout << "Key word:		" << endl;
		getline(cin, key_word);
		u = key_word.length();
		if (u != 16) {
			cout << "The length of key_word is "<<u<<", but it should be 16, try again" << endl;
		}
	}
	cout << "Message:		" << endl;
	getline(cin, message);

	string message_encoded = "";
	string message_decoded = "";
	//НАЧАЛО------KeyExpansion----для-----ПРИМЕРА---------------------------------------------------------------------------------
	/*key_word = "";
	for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
	key_word = key_word+ binary_to_char(key[i][j][0]);
	}
	}*/
	//КОНЕЦ------KeyExpansion----для-----ПРИМЕРА-----------------------------------------------------------------------------------
	int yy = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			key[i][j][0] = (char_to_binary(key_word[yy]));
			++yy;
		}
	}
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << key[i][j][0] << "\t";
		}
		cout << endl;
	}
	cout << endl;*/
	KeyExpansion(key);


	char** buffer = new char*[4];
	for (int i = 0; i < 4; i++) {
		*(buffer + i) = new char[4];
	}
	int len = message.length();
	//cout << len << endl;
	int k = 0;
	if (len % 16 != 0) {

		for (int i = 0; i < 15 - len % 16; i++) {
			message = message + "0";
		}
		//cout << message << endl;
	}
	while (k<len) {

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {
				*(*(buffer + i) + j) = message[k];
				++k;
			}
		}
		Encode(buffer, key);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				message_encoded = message_encoded + binary_to_char(char_to_binary(*(*(buffer + i) + j)));
			}
		}
		Decode(buffer, key);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				message_decoded = message_decoded + binary_to_char(char_to_binary(*(*(buffer + i) + j)));
			}
		}
	}
	cout << "Message: \t" << message << "\t" << message_decoded.length() << endl << endl;
	cout <<"Encrypted message: \t"<< message_encoded << "\t" << message_encoded.length() << endl;
	cout << "Decrypted message: \t" << message_decoded << "\t" << message_decoded.length() << endl;
	//----gf_multiply(binary_to_decimal(10), binary_to_decimal(10110100))---------
	cout << endl;
	cout << binary_to_char(decimal_to_binary(238));

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if ((i != binary_to_decimal(InvSbox[binary_to_decimal(Sbox[i][j] / 10000)][binary_to_decimal(Sbox[i][j] % 10000)] / 10000)) || (j != binary_to_decimal(InvSbox[binary_to_decimal(Sbox[i][j] / 10000)][binary_to_decimal(Sbox[i][j] % 10000)] % 10000))) {
				cout << endl << i << "\t" << j << endl;
			}

		}
	}

	for (int i = 0; i < 4; i++) {
		delete[] * (buffer + i);
	}
	delete[] buffer;
	system("pause");
	return 0;
}


