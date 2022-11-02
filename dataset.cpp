#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#include "dataset.h"
using namespace std;

vector<uint8_t> train_labels;
vector<array<uint8_t, 28 * 28>> train_images;
vector<uint8_t> test_labels;
vector<array<uint8_t, 28 * 28>> test_images;

void load_dataset() {
	ifstream fin;
	uint32_t MN, N, A, B;

	/*---------------------*\
	\*---------------------*/

	fin = ifstream("./Resources/train-labels-idx1-ubyte", ios::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	//N = __builtin_bswap32(N);
	//MN = _byteswap_ulong(MN);
	N =  _byteswap_ulong(N);
	//cout << "MN is " << MN;
	if (MN != 0x01080000) {
		cerr << "Invalid database 1" << endl;
		exit(1);
	}

	train_labels.resize(N);
	fin.read((char*)train_labels.data(), N * sizeof(uint8_t));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream("./Resources/train-images-idx3-ubyte", ios::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	fin.read((char*)&A, sizeof(A));
	fin.read((char*)&B, sizeof(B));

	//N = __builtin_bswap32(N);
	N = _byteswap_ulong(N);
	//A = __builtin_bswap32(A);
	A = _byteswap_ulong(A);
	//B = __builtin_bswap32(B);
	B = _byteswap_ulong(B);
	if (MN != 0x03080000 || A != 28 || B != 28) {
		cerr << "invalid database" << endl;
		exit(1);
	}

	train_images.resize(N);
	fin.read((char*)train_images.data(), N * sizeof(array<uint8_t, 28 * 28>));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream("./Resources/t10k-labels-idx1-ubyte", ios::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	//N = __builtin_bswap32(N);
	N = _byteswap_ulong(N);

	if (MN != 0x01080000) {
		cerr << "Invalid database" << endl;
		exit(1);
	}

	test_labels.resize(N);
	fin.read((char*)test_labels.data(), N * sizeof(uint8_t));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream("./Resources/t10k-images-idx3-ubyte", ios::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	fin.read((char*)&A, sizeof(A));
	fin.read((char*)&B, sizeof(B));

	//N = __builtin_bswap32(N);
	N = _byteswap_ulong(N);
	//A = __builtin_bswap32(A);
	A = _byteswap_ulong(A);
	//B = __builtin_bswap32(B);
	B = _byteswap_ulong(B);
	if (MN != 0x03080000 || A != 28 || B != 28) {
		cerr << "invalid database" << endl;
		exit(1);
	}
	//cout << "\n" << "value of N is " << N << "\n";
	test_images.resize(N);
	fin.read((char*)test_images.data(), N * sizeof(array<uint8_t, 28 * 28>));
	//cout << "test image is " << (uint32_t)test_images[55][300];
}