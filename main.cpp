#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <string.h> 
#include <stdio.h>

using namespace std;

void gotoxy(int x, int y){
	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),k);
}

int jumlah_data, ketemu = 0;
string ganti, hapus, cari;
char lagi;

struct buku
{
	string id_buku;
	string kategori_buku;
	string judu_buku;
	string penerbit_buku;
	int harga;
};

//objact
buku idb[100];


void lihatdatabuku()
{
	int n=0;
	
	for (int i = 0; i<jumlah_data; i++)
	{
		n++;
		cout << idb[i].id_buku << endl;
		cout << idb[i].kategori_buku << endl;
		cout << idb[i].judu_buku << endl;
		cout << idb[i].penerbit_buku << endl;
		cout << idb[i].harga << endl;
	}
}



void data_baru()
{
	
	system("cls");
	cout << "Berapa Data";
	cin >> jumlah_data;
	if (jumlah_data > 100)
	{
		cout << "maaf jumlah maksimal";
	}
	for (int i = 0;i < jumlah_data; i++ )
	{
		system("cls");
		cout << "Input data baru" ;
		
		cout << "id buku";
		cin >> idb[i].id_buku;
		cout << "Kategori Buku";
		cin.ignore();
		getline(cin, idb[i].kategori_buku);
		cout << "Judul Buku";
		getline(cin, idb[i].judu_buku);
		cout << "Penerbit Buku";
		getline(cin, idb[i].penerbit_buku);
		cout << "Harga Buku";
		cin >> idb[i].harga;
	}
}

void tambahdata()
{
	system("cls");
	int ke1;
	jumlah_data++;
	ke1 = jumlah_data - 1;
	
	cout << "Tambah data" << endl;
	cout << "ID Buku";
	cin >> idb[ke1].id_buku;
	cout << "Kategori Buku";
	cin.ignore();
	getline(cin, idb[ke1].kategori_buku);
	cout << "Judul Buku";
	getline(cin, idb[ke1].judu_buku);
	cout << "Penerbit Buku";
	getline(cin, idb[ke1].penerbit_buku);
	cout << "Harga Buku";
	cin >> idb[ke1].harga;
	
}

void caridata()
{
	system("cls");
	
	cout << "masukan id buku ";
	cin >> cari;
	
	for (int n = 0; n < jumlah_data; n++)
	{
		if (cari == idb[n].id_buku)
		{
			ketemu = 1;
			
			cout << "view data" << endl;
			cout << idb[n].id_buku << endl;
			cout << idb[n].kategori_buku << endl;
			cout << idb[n].judu_buku << endl;
			cout << idb[n].penerbit_buku << endl;
			cout << idb[n].harga << endl;
			cout << "data ke";
			cout << n + 1;
			break;
		}
	}
	if (ketemu == 0)
	{
		cout << "data yang anda cari tidak ada";
	}
}

void editdata()
{
	system("cls");
	
	cout << "masukan id buku yang akan di edit";
	cin >> ganti;
	
	for (int g = 0; g < jumlah_data; g++)
	{
		if (idb[g].id_buku == ganti)
		{
			ketemu = 1;
			cout << "edit data" << endl;
			cout << idb[g].id_buku << endl;
			cout << idb[g].kategori_buku << endl;
			cout << idb[g].judu_buku << endl;
			cout << idb[g].penerbit_buku << endl;
			cout << idb[g].harga << endl;
			cout << "\n yakin di edit [Y/T] :";
			cin >> lagi;
			
			if (lagi == 'y' || lagi == 'Y')
			{
				cout << "data pengganti" << endl;
				cout << "id buku";
				cin >> idb[g].id_buku;
			}
			else 
			{
				break;
			}
		}
	}
	if (ketemu == 0)
	{
		cout << "data tidak ada";
	}
}

void hapusdata()
{
	system("cls");
	
	cout << "Masukan ID Buku Yang Akan Dihapus";
	cin >> hapus;
	
	for (int k = 0; k < jumlah_data; k++)
	{
		if(hapus == idb[k].id_buku)
		{
			ketemu = 1;
			
			cout << "HAPUS DATA BUKU" << endl;
			
			cout << idb[k].id_buku;
			cout << idb[k].kategori_buku << endl;
			cout << idb[k].judu_buku << endl;
			cout << idb[k].penerbit_buku << endl;
			cout << idb[k].harga << endl;
			
			cout << "Yakin dihapus [Y/T]";
			cin >> lagi;
			
			if (lagi == 'y'|| lagi == 'Y')
			{
				for (int l = k; l < jumlah_data; l++)
				{
					idb[l].id_buku = idb[l + 1].id_buku;
					idb[l].kategori_buku = idb[l + 1].kategori_buku;
					idb[l].judu_buku = idb[l + 1].judu_buku;
					idb[l].penerbit_buku = idb[l + 1].penerbit_buku;
					idb[l].harga = idb[l + 1].harga;
				}
				jumlah_data -= 1;
				break;
			}
		}
	}
}

int main()
{
	
	login:
	string username;
	string password = "";
	char ch_password;
	int i = 0;
			
		system("cls");
		cout << "|---------------------------------------|" << endl;
		cout << "|                                       |" << endl;
		cout << "|            PERPUSTAKAAN               |" << endl;
		cout << "|                 IDB                   |" << endl;
		cout << "|              INDONESIA                |" << endl;
		cout << "|                                       |" << endl;
		cout << "|---------------------------------------|" << endl;
		cout << "|                                       |" << endl;
		cout << "|     Masukan Username\t:               |" << endl;
		cout << "|     Masukan Password\t:               |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|                                       |" << endl;
		cout << "|---------------------------------------|" << endl;
		gotoxy(25,7);cin >> username;
		gotoxy(25,8);ch_password = _getch(); //kita menginputkan ketikkan kita ke variabel password.
		while(ch_password != 13 && i < 6) //password != 13   ? 13 merupakan kode karakter enter, dengan ini pengimputan akan terhenti ketika unser menekan enter. 
		{
			password.push_back(ch_password); //berfungsi untuk memindahkan karakter untuk diinputkan ke variabel ch. Hal ini disebabkan karena variabel pasword merupakan variabel char yang mana hanya bisa menginput satu huruf saja. Sementara ch adalah string sehingga nilai yang tadinya disimpan didalam password akan tersimpan ke ch dan akan terkirim hingga kita menekan enter.
			cout << '*'; //ketika kita ketik selain enter, maka output yang muncul adalah bintang bukan password itu sendiri
			ch_password = _getch();
			i++;
		}
		
		if (username == "admin")
		{
			if (password == "123456")
			{
				int pilihan;
				do 
				{
					cout << "\n\n\n ini admin\n\n\n";
					cout << "[1] Data Buku Baru" << endl;
					cout << "[2] Tambah Data Buku " << endl;
					cout << "[3] Cari Data Buku " << endl;
					cout << "[4] Edit Data Buku" << endl;
					cout << "[5] Hapus Data Buku" << endl;
					cout << "[6] List Data Buku" << endl;
					cout << "[7] Exit" << endl;
					cout << "masukan pilihan \t:";
					cin >> pilihan;	
					
					if (pilihan == 1)
					{
						data_baru();
					}
					else if (pilihan == 2)
					{
						tambahdata();
					}
					else if (pilihan == 3)
					{
						caridata();
					}
					else if (pilihan == 4)
					{
						editdata();
					}
					else if (pilihan == 5)
					{
						hapusdata();
					}
					else if (pilihan == 6)
					{
						lihatdatabuku();	
					}
					else
					exit(0);
					
				}
				while (pilihan != 0);
			}
			
			else
			{
				if (password != "111114")
				{
					string loglagi;
					gotoxy(4,14);cout << "Paswword Salah!!!!!!" << endl;
					gotoxy(4,15);cout << "Silahkan Masukan Password Yg benar" << endl;
				
					gotoxy(4,16);cout << "Log In Kembali Y/T\t\t:";
					cin >> loglagi;
				
					if (loglagi == "Y")
					{
						goto login;
					}
					else if (loglagi == "y")
					{
						goto login;
					}
					else
					exit(0);
				}
			}
			
		}
		else
		{
			if (username != "admin")
			{
				gotoxy(4,10);cout << "Username Salah!!!!!!" << endl;
				gotoxy(4,11);cout << "Silahkan Masukan Username Yg benar" << endl;
			
				string lagi;
				gotoxy(4,12);cout << "Log In Kembali Y/T\t:";
				cin >> lagi;
			
				if (lagi == "Y")
				{
					goto login;
				}
				else if (lagi == "y")
				{
					goto login;
				}
				else
				{
					exit(0);
				}
			}
		}
	return 0;
}
