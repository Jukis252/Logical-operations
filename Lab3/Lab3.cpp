#include <iostream>
#include <fstream>
using namespace std;

int XOR1(unsigned char A, unsigned char B)
{
    /*cout << A << " " << B << endl;*/
    unsigned char C =((~A & B) | (~B & A));
    return C;
}
int XOR2(unsigned char A, unsigned char B)
{
    unsigned char C = A^B;
    return C;
}
int XOR3(unsigned char A, unsigned char B)
{
    unsigned char C = ((A | B) & (~(A & B)));
    return C;
}
int XOR4(unsigned char A, unsigned char B)
{
    unsigned char C = ((A|B)&(~A|~B));
    return C;
}
int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        cout << "No arguments" << endl;
        return 0;
    }
    int A1 = strtol(argv[1], NULL, 10);
    int B1 = strtol(argv[2], NULL, 10);
    unsigned char A = (unsigned char) A1;
    unsigned char B = (unsigned char) B1;
    XOR1(A, B);
    XOR2(A, B);
    XOR3(A, B);
    XOR4(A, B);
    ofstream fr("example.csv");
    fr << "Justinas, Plauska" << endl;
    fr << "Pradiniai argumentai," << (int) A << "," << (int) B  <<endl;
    fr << "XOR1, XOR2, XOR3, XOR4" << endl;
    fr << "((~A&B)|(~B&A)),(A^B),((A|B)&(~(A&B))),(A|B)&(~A|!B)" << endl;
    fr << XOR1(A, B) << "," << XOR2(A, B) << "," << XOR3(A, B) << "," << XOR4(A, B) << "," << endl;
    fr.close();
    //cout << XOR1(A, B);
    //cout << XOR2(A, B);
    //cout << XOR3(A, B);
    //cout << XOR4(A, B);
    return 0;
}   
