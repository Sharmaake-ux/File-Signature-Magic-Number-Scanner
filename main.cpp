#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void checkSignature(const vector<unsigned char>& header) {
    if (header.size() < 4) {
        cout << "File is too small to determine signature." << endl;
        return;
    }

    // PDF: 25 50 44 46 (%PDF)
    if (header[0] == 0x25 && header[1] == 0x50 && header[2] == 0x44 && header[3] == 0x46) {
        cout << "Result: This is a PDF file." << endl;
    }
    // JPEG: FF D8 FF
    else if (header[0] == 0xFF && header[1] == 0xD8 && header[2] == 0xFF) {
        cout << "Result: This is a JPEG image file." << endl;
    }
    // PNG: 89 50 4E 47
    else if (header[0] == 0x89 && header[1] == 0x50 && header[2] == 0x4E && header[3] == 0x47) {
        cout << "Result: This is a PNG image file." << endl;
    }
    else {
        cout << "Result: Unknown file type." << endl;
    }
}

int main() {
    string filename;
    cout << "--- File Signature Scanner ---" << endl;
    cout << "Enter the path to the file: ";
    cin >> filename;

    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<unsigned char> header(4);
    file.read(reinterpret_cast<char*>(header.data()), 4);
    
    cout << "Header Hex: ";
    for(int i = 0; i < 4; i++) {
        cout << hex << uppercase << setw(2) << setfill('0') << (int)header[i] << " ";
    }
    cout << dec << endl;

    checkSignature(header);
    file.close();

    return 0;
}
