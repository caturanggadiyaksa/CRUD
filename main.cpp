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

int jumlah_data;
bool ketemu = true;
string ganti;
string hapus;
string cari;
char lagi;

struct buku
{
	string id_buku;
	string kategori_buku;
	string judul_buku;
	string penerbit_buku;
	int harga;
};

//object
buku idb[100];

void databuku()
{
	gotoxy(10,4);cout<<"+===========================================+"<<endl;
	gotoxy(10,5);cout<<"|ID Buku          :                         |"<<endl;
	gotoxy(10,6);cout<<"+===========================================+"<<endl;
	gotoxy(10,7);cout<<"|Kategori Buku    :                         |"<<endl;
	gotoxy(10,8);cout<<"+===========================================+"<<endl;
	gotoxy(10,9);cout<<"+===========================================+"<<endl;
	gotoxy(10,10);cout<<"|Judul Buku      :                          |"<<endl;
	gotoxy(10,11);cout<<"+===========================================+"<<endl;
	gotoxy(10,12);cout<<"+===========================================+"<<endl;
	gotoxy(10,13);cout<<"|Penerbit Buku  :                           |"<<endl;
	gotoxy(10,14);cout<<"+===========================================+"<<endl;
	gotoxy(10,15);cout<<"+===========================================+"<<endl;
	gotoxy(10,16);cout<<"| Harga Buku     :                          |"<<endl;
	gotoxy(10,17);cout<<"+===========================================+"<<endl;
	
}

void header()
{
	gotoxy(2,2);cout << "| ID BUKU\t|\t Kategori Buku \t\t|\t judul Buku \t\t|\t Penerbit Buku \t\t|\t Harga Buku |";
}

void data_baru()
{
	tambahlagi:
	system("cls");
		gotoxy(10,2);cout<<"+============================================+"<<endl;
		gotoxy(10,3);cout <<"|Berapa Data yang ingin ditambahkan :       |";
		gotoxy(10,4);cout<<"+============================================+"<<endl;
		gotoxy(47,3);cin >> jumlah_data;
		
	if (jumlah_data >= 100)
	{
		gotoxy(10,2);cout<<"+==========================================================+"<<endl;
		gotoxy(10,3);cout <<"|Maaf Jumlah Data yang bisa ditambahkan hanya 100         |";
		gotoxy(10,4);cout<<"+==========================================================+"<<endl;
		_getch();
		goto tambahlagi;
	}
	for (int i = 0;i < jumlah_data; i++ )
	{
		system("cls");//Bagian input data baru
		gotoxy(10,2);cout<<"+===========================================+"<<endl;
		gotoxy(10,3);cout<<"|            Input Data Baru                |"<<endl;
		gotoxy(10,4);cout<<"+===========================================+"<<endl;
		databuku();
		gotoxy(31,5);cin>>idb[i].id_buku;
		cin.ignore();
		gotoxy(31,7);getline(cin, idb[i].kategori_buku);
		gotoxy(31,10);getline(cin, idb[i].judul_buku);
		gotoxy(31,13);getline(cin, idb[i].penerbit_buku);
		gotoxy(31,16);cin>>idb[i].harga;
	}
}

void tambahdata()
{
	system("cls");
	int ke1;
	jumlah_data++;
	ke1 = jumlah_data - 1;
	
	//tambah data
	gotoxy(10,2);cout<<"+===========================================+"<<endl;
	gotoxy(10,3);cout<<"|                Tambah Data                |"<<endl;
	gotoxy(10,4);cout<<"+===========================================+"<<endl;
	databuku();
	gotoxy(31,5);cout<<""; cin>>idb[ke1].id_buku;
	cin.ignore();
	gotoxy(31,7);getline(cin, idb[ke1].kategori_buku);	
	gotoxy(31,10);getline(cin, idb[ke1].judul_buku);	
	gotoxy(31,13);getline(cin, idb[ke1].penerbit_buku);	
	gotoxy(31,16);cin>>idb[ke1].harga;	
	
}

void caridata()
{
	system("cls");
	
	gotoxy(10,1);cout<<"+===========================================+"<<endl;
	gotoxy(10,2);cout<<"|Masukan ID Buku :                          |"<<endl;
	gotoxy(10,3);cout<<"+===========================================+"<<endl;
	gotoxy(30,2);cout<<""; cin>>cari;
	
	for (int n = 0; n < jumlah_data; n++)
	{
		if (cari == idb[n].id_buku)
		{
			ketemu = true;
			
			gotoxy(10,5);cout<<"view data"<< endl;
			databuku();;
			gotoxy(31,5);cout << idb[n].id_buku << endl;
			gotoxy(31,7);cout << idb[n].kategori_buku << endl;
			gotoxy(31,10);cout << idb[n].judul_buku << endl;
			gotoxy(31,13);cout << idb[n].penerbit_buku << endl;
			gotoxy(31,16);cout << idb[n].harga << endl;
			gotoxy(10,19);cout<<"data ke";
			gotoxy(20,19);cout << n + 1;
			_getch();
			break;
		}
	}
	if (ketemu == false)
	{
		gotoxy(10,7);cout <<"Data yang anda cari tidak ada";
		_getch();
	}
}

void editdata()
{
	system("cls");
	
	gotoxy(10,1);cout<<"+================================================+"<<endl;
	gotoxy(10,2);cout<<"|Masukan ID Buku yang akan di Edit :             |"<<endl;
	gotoxy(10,3);cout<<"+================================================++"<<endl;
	gotoxy(48,2);cout<<""; cin>>ganti;
		
	for (int g = 0; g < jumlah_data; g++)
	{
		if (idb[g].id_buku == ganti)
		{
			system("cls");
			ketemu = true;
			gotoxy(10,1);cout<<"+===========================================+"<<endl;
			gotoxy(10,2);cout<<"|                    Edit Data              |"<<endl;
			gotoxy(10,3);cout<<"+===========================================+"<<endl;
			databuku();
			gotoxy(31,5);cout << idb[g].id_buku << endl;
			gotoxy(31,7);cout << idb[g].kategori_buku << endl;
			gotoxy(31,10);cout << idb[g].judul_buku << endl;
			gotoxy(31,13);cout << idb[g].penerbit_buku << endl;
			gotoxy(31,16);cout << idb[g].harga << endl;
			gotoxy(10,20);cout<<"+==========================================+"<<endl;
			gotoxy(10,22);cout<<"|Yakin akan di Edit [ Y / T ] :            |"<<endl;
			gotoxy(10,23);cout<<"+==========================================+"<<endl;
			gotoxy(41,22);cout<<""; cin>>lagi;
			
			if (lagi == 'y' || lagi == 'Y')
			{
				system("cls");
				gotoxy(10,1);cout<<"+===========================================+"<<endl;
				gotoxy(10,2);  cout<<"|                Data Pengganti             |"<<endl;
				gotoxy(10,3);cout<<"+===========================================+"<<endl;
				databuku();
				cin.ignore();
				gotoxy(31,5);cin >> idb[g].id_buku;
				gotoxy(31,7);getline(cin, idb[g].kategori_buku);	
				gotoxy(31,10);getline(cin, idb[g].judul_buku);	
				gotoxy(31,13);getline(cin, idb[g].penerbit_buku);	
				gotoxy(31,16);cin>>idb[g].harga;
			}
			else 
			{
				break;
			}
		}
	}
	if (ketemu == false)
	{
		gotoxy(10,10);cout<<"+===========================================+"<<endl;
		gotoxy(10,11);cout<<"|               Data Tidak Ada              |"<<endl;
		gotoxy(10,12);cout<<"+===========================================+"<<endl;
	}
}

void hapusdata()
{
	system("cls");
		gotoxy(10,1);cout<<"+===========================================+"<<endl;
		gotoxy(10,2);cout<<"|Masukan ID Buku yang akan di Hapus :       |"<<endl;
		gotoxy(10,3);cout<<"+===========================================+"<<endl;
		gotoxy(47,2);cout<<""; cin>>hapus;
		
	for (int k = 0; k < jumlah_data; k++)
	{
		if(hapus == idb[k].id_buku)
		{
			ketemu = 1;
			
			gotoxy(10,4);cout << "HAPUS DATA BUKU" << endl;
			
			databuku();
			gotoxy(31,5);cout << idb[k].id_buku << endl;
			gotoxy(31,7);cout << idb[k].kategori_buku << endl;
			gotoxy(31,10);cout << idb[k].judul_buku << endl;
			gotoxy(31,13);cout << idb[k].penerbit_buku << endl;
			gotoxy(31,16);cout << idb[k].harga << endl;
			
			gotoxy(10,20);cout << "Yakin dihapus [Y/T]";
			cin >> lagi;
			
			if (lagi == 'y'|| lagi == 'Y')
			{
				for (int l = k; l < jumlah_data; l++)
				{
					idb[l].id_buku = idb[l + 1].id_buku;
					idb[l].kategori_buku = idb[l + 1].kategori_buku;
					idb[l].judul_buku = idb[l + 1].judul_buku;
					idb[l].penerbit_buku = idb[l + 1].penerbit_buku;
					idb[l].harga = idb[l + 1].harga;
				}
				jumlah_data -= 1;
				break;
			}
		}
	}
}

void lihatdatabuku()
{
	int n=0;
	system("cls");
	header();
	
	for (int i = 0; i<jumlah_data; i++)
	{
		n++;
		gotoxy(7,4+i);cout << idb[i].id_buku << endl;
		gotoxy(25,4+i);cout << idb[i].kategori_buku << endl;
		gotoxy(58,4+i);cout << idb[i].judul_buku << endl;
		gotoxy(85,4+i);cout << idb[i].penerbit_buku << endl;
		gotoxy(118,4+i);cout << idb[i].harga << endl;
	}
	_getch();
}


int main()
{
	
	login:
	string username;
	string password = "";
	char ch_password;
	int i = 0;
			
		system("cls");
		gotoxy(10,2);cout << "+---------------------------------------+" << endl;
		gotoxy(10,3);cout << "|                                       |" << endl;
		gotoxy(10,4);cout << "|            PERPUSTAKAAN               |" << endl;
		gotoxy(10,5);cout << "|                 IDB                   |" << endl;
		gotoxy(10,6);cout << "|              INDONESIA                |" << endl;
		gotoxy(10,7);cout << "|                                       |" << endl;
		gotoxy(10,8);cout << "|---------------------------------------|" << endl;
		gotoxy(10,9);cout << "|                                       |" << endl;
		gotoxy(10,10);cout << "| Masukan Username\t:                 |" << endl;
		gotoxy(10,11);cout << "| Masukan Password\t:                 |" << endl;
		gotoxy(10,12);cout << "|                                       |" << endl;
		gotoxy(10,13);cout << "|                                       |" << endl;
		gotoxy(10,14);cout << "|                                       |" << endl;
		gotoxy(10,15);cout << "|                                       |" << endl;
		gotoxy(10,16);cout << "|                                       |" << endl;
		gotoxy(10,17);cout << "|                                       |" << endl;
		gotoxy(10,18);cout << "|                                       |" << endl;
		gotoxy(10,19);cout << "|                                       |" << endl;
		gotoxy(10,20);cout << "|                                       |" << endl;
		gotoxy(10,21);cout << "+---------------------------------------+" << endl;
		gotoxy(34,10);cin >> username;
		gotoxy(34,11);ch_password = _getch(); 
		while(ch_password != 13 && i < 6) 
		{
			password.push_back(ch_password); 
			cout << "*"; 
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
				system("cls");
					gotoxy(10,2);cout<<"+=============================+"<<endl;				
					gotoxy(10,3);cout<< "|      SELAMAT DATANG         |"<<endl;
					gotoxy(10,4);cout<<"+=============================+"<<endl;
					gotoxy(10,5);cout<< "|[1] Data Buku Baru           |" << endl;
					gotoxy(10,6);cout<< "|[2] Tambah Data Buku         |" << endl;
					gotoxy(10,7);cout<< "|[3] Cari Data Buku           |" << endl;
					gotoxy(10,8);cout<< "|[4] Edit Data Buku           |" << endl;
					gotoxy(10,9);cout<< "|[5] Hapus Data Buku          |" << endl;
					gotoxy(10,10);cout<< "|[6] List Data Buku           |" << endl;
					gotoxy(10,11);cout<< "|[7] Exit                     |" << endl;
					gotoxy(10,12);cout<<"+=============================+"<<endl;
					gotoxy(10,13);cout<< "|Masukan Pilihan :            |";
					gotoxy(10,14);cout<<"+=============================+"<<endl;
					gotoxy(29,13);cin >> pilihan;
					
					switch(pilihan)
					{
						case 1:
							data_baru();
							break;
						case 2:
							tambahdata();
							break;
						case 3:
							caridata();
							break;
						case 4:
							editdata();
							break;
						case 5:
							hapusdata();
							break;
						case 6:
							lihatdatabuku();
							break;
						default:
							exit(0);
					}
					
				}
				while (pilihan != 0);
			}
			
			else
			{
				if (password != "111114")
				{
					string loglagi;
					gotoxy(12,14);cout << "Paswword Salah!!!!!!" << endl;
					gotoxy(12,15);cout << "Silahkan Masukan Password Yg benar" << endl;
				
					gotoxy(12,16);cout << "Log In Kembali Y/T\t\t:";
					cin >> loglagi;
				
					if (loglagi == "Y" || loglagi == "y")
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
				gotoxy(12,14);cout << "Username Salah!!!!!!" << endl;
				gotoxy(12,15);cout << "Silahkan Masukan Username Yg benar" << endl;
			
				string lagi;
				gotoxy(12,16);cout << "Log In Kembali Y/T\t:";
				cin >> lagi;
			
				if (lagi == "Y" || lagi == "y")
				{
					goto login;
				}
				else
					exit(0);
				
			}
		}
	return 0;
}
