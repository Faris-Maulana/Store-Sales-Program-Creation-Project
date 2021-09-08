#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iomanip>
using namespace std;

struct data_barang{
	string nama_barang;
	int kode_barang;
	int no,jumlah_stock,harga_barang;
	int *a,*b;
}data[50];

struct NAA{
	int RII;
	struct NAA *LINK;};
	typedef struct NAA Simpul;
	Simpul *p, *FIRST, *LAST, *Q;
	int X;

void FAR(int X){
	p=(Simpul*) malloc(sizeof(Simpul));
	if(p != NULL){
		p -> RII = X;
	}else{
		cout << "Pembelian tidak valid"<<endl;
		cin.get();
		exit(1);
	}
}

void RIS(){
	FIRST = p;
	LAST = p;
	p -> LINK = NULL;
}

void LAN(){
	LAST -> LINK = p;
	LAST = p;
	p -> LINK = NULL;
}

void MAU (){
	int X;
	Q = FIRST;
	while(Q != NULL){
		X =Q -> RII;
		cout <<" "<<X;
		Q = Q -> LINK;
	}
}
void print_data_barang (data_barang dat){
	cout << "	" << dat.kode_barang << "		" << dat.nama_barang <<"				"<< dat.jumlah_stock << "				"<< dat.harga_barang << endl;
}


void print_edit_barang(data_barang & edit){
	cout << " Masukkan Kode Barang  : "; cin >> edit.kode_barang;
	cout << " Masukkan Nama Barang  : "; cin >> edit.nama_barang;
	cout << " Masukkan Jumlah Stock : "; cin >> edit.jumlah_stock;
	cout << " Harga Barang          : Rp."; cin >> edit.harga_barang;
}




void print_input_data_barang (data_barang & input){
	cout << "Masukkan Kode Barang   : "; cin >> input.kode_barang;
	cout << "Masukkan Nama Barang   : "; cin >> input.nama_barang;
	cout << "Masukkan Jumlah stock  : "; cin >> input.jumlah_stock;
	cout << "Harga Barang           : Rp."; cin >> input.harga_barang;
}

void print_pembelian_barang (data_barang & pembelian, int &bayar, int &jumlahbeli){
	cout << "Nama Barang : " << pembelian.nama_barang << endl;
	cout << "Jumlah Stok : " << pembelian.jumlah_stock << endl;
	cout << "Harga : " << pembelian.harga_barang << endl;
	cout << "jumlah yang dibeli? : ";
	cin >> jumlahbeli;
	bayar=jumlahbeli*pembelian.harga_barang;
	cout << "Harga yang harus dibayar : " << jumlahbeli << " x " << pembelian.harga_barang << " = Rp. " << bayar << endl;
	cout << "Jumlah Stock : " << pembelian.jumlah_stock << " - " << jumlahbeli << " = Tersisa " << pembelian.jumlah_stock-jumlahbeli << " Stock "<< endl;
	pembelian.jumlah_stock=pembelian.jumlah_stock-jumlahbeli;
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
   
void quickSort()  
{  
    int i, j,n,arr[20];  
    for (i = 0; i < n-1; i++)      
       
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
    
int main (){
	int pilih, n=0, kode_Barang, nomor_barang=1;
	char back;int temp;
	up:
		system("cls");
		system("color B");
		cout << "====== Toko Apa Saja Ada ====" << endl;
		cout << "===============================" << endl;
		cout << endl;
		cout << " 1. Lihat Data dan Stock Barang " << endl;
		cout << " 2. input Data Barang     " << endl;
		cout << " 3. Hapus Data Barang     " << endl;
		cout << " 4. Edit Stock Barang     " << endl;
		cout << " 5. Pembelian Barang      " << endl;
		cout << " 6. Pengurutan Harga Barang" << endl;
		cout << " 7. keluar program        " << endl;
		cout << endl;
		cout << "===============================" << endl;
		cout << " Masukkan Pilihan Anda : "; cin >> pilih;
		switch(pilih){
			case 1 :
				
				system("cls");
				cout << "=========================================================\n			DATA BARANG\n=========================================================" << endl;
				cout << "========================================================================================================================" << endl;
				cout << "No |  Kode Barang  |    Nama Barang      |        Jumlah Stock       |                Harga " << endl;
				cout << "========================================================================================================================" << endl;
				for(int i=0;i<n;i=i+1){
					cout << i+1;
					print_data_barang(data[i]);
				}
				cout << "=========================================================" << endl;
				pilihlagi1 :
					cout << " Tekan K untuk Kembali Ke Menu Utama : "; cin >> back;
					if(back=='K'|| back=='k'){
						goto up;
					}
					else{
						cout << "\n--TAK ADA PILIHAN--"<< endl;
						goto pilihlagi1;}
						break;
			case 2 :
				system("cls");
				cout << "=======================================================\n				INPUT DATA BARANG\n=========================" << endl;
				tambah:
					cout << " Nomor Barang : " << nomor_barang << endl;
					nomor_barang=nomor_barang+1;
					print_input_data_barang(data[n]);
					n++;
					cout << " \n================================ " << endl;
					cout << " Data Barang Berhasil ditambah. " << endl;
					pilih :
					cout << "Tekan [Y] untuk menginput barang lagi & Tekan [K] untuk kembali ke Menu Utama : "; cin >> back;
					cout << "\n" << endl;
					if(back=='K' || back=='k'){
						goto up;
					} 
					else if (back=='Y' || back=='y'){
						goto tambah;
					}
					else {
						cout << " !! masukkan kode Y/K !!" << endl;
						goto pilih;
					}
					break;
			case 3 :
					system ("cls");
					int y;
					cout << "========================================= Data dan Stock Barang ======================================================" << endl;
					cout << "========================================================================================================================" << endl;
 		  			cout << "No |  Kode Barang  |    Nama Barang      |        Jumlah Stock       |                Harga " << endl;
 		  			cout << "========================================================================================================================" << endl;
				for(int i=0;i<n;i=i+1){
					cout << i+1;
					print_data_barang(data[i]);
				}
					   cout << "===================================================================================================================" << endl;
					   cout << "=======================================================\n	         HAPUS DATA BARANG\n======================================================="<<endl;
					   cout << " Masukkan Kode Barang yang ingin dihapus : ";
					   cin>>kode_Barang;
					   y=kode_Barang-1;
					   for(int i=0;i<n;i++){
					   	if(data[i].kode_barang==kode_Barang){
					   		for(int j=y;j<n;j=j+1){
					   			data[j].nama_barang=data[j+1].nama_barang;
					   			data[j].no=data[j+1].no;
					   			data[j].harga_barang=data[j+1].harga_barang;
					   			data[j].kode_barang=data[j+1].kode_barang;
							   }
						   }
					   }
					   cout << " ============================= " << endl;
					   cout << " Data Kode Barang - " << kode_Barang << " - berhasil dihapus. " << endl;
					   n=n-1;
					   pilihlagi2:
					   	cout << " Tekan k untuk kembali ke Menu Utama : "; cin>>back;
					   	if(back=='K'|| back=='k'){
					   		goto up;
						   }
						   else {
						   	cout << "\n--TAK ADA PILIHAN--" << endl;
						   	goto pilihlagi2;
						   }break;
			case 4 :
				system("cls");
				cout << "========================================================================================================================" << endl;
				cout << "No |  Kode Barang  |    Nama Barang      |        Jumlah Stock       |                Harga " << endl;
				cout << "========================================================================================================================" << endl;
				for(int i=0;i<n;i=i+1){
					cout << i+1;
					print_data_barang(data[i]);
				}
				cout << "=====================================================================================================" << endl;
				cout << "=======================================================\n               EDIT DATA BARANG\n======================================================="<<endl;
				cout << "Pilih kode barang untuk data barang yang akan diedit : ";
				cin>>kode_Barang;
				for(int i=0;i<=n;i++){
					if(data[i].kode_barang==kode_Barang){
						print_edit_barang(data[i]);
						cout << " -------------------------------- " << endl;
						cout << " Data Barang berhasil diedit. " << endl;
						break;
					}
				}
				pilihlagi3 :
					cout << " Tekan k untuk kembali ke Menu Utama : "; cin >> back;
					if(back=='K' || back=='k'){
						goto up;
					}
					else{
						cout <<"\n--TAK ADA PILIHAN--" << endl;
						goto pilihlagi3;
					}
					break;
			case 5 :
			system("cls");
			int kodebrgg, jumlahbeli, bayar;
			cout << "========================================================================================================================" << endl;
			cout << "No |  Kode Barang  |    Nama Barang      |        Jumlah Stock       |                Harga " << endl;
			cout << "========================================================================================================================" << endl;
				for(int i=0;i<n;i=i+1){
					cout << i+1;
					print_data_barang(data[i]);
				}
			cout << "=======================================================\n		PEMBELIAN BARANG\n=======================================================" << endl;
			cout << "Masukkan kode barang yang ingin dibeli : ";
			cin>>kodebrgg;
			for(int i=0;i<=n;i++){
				if(data[i].kode_barang==kodebrgg){
					print_pembelian_barang(data[i], bayar, jumlahbeli);
				}
				else {
					cout << " ";
				}
			}
			pilihlagi5 :
			cout << " Tekan K untuk kembali ke Menu Utama : "; cin>>back;
			if(back=='K' || back=='k'){
				goto up;
			}
			else{
				cout << "\n--TAK ADA PILIHAN--"<<endl;
				goto pilihlagi5;
			}
			break;
			case 6 :
				int temp;
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if(data[i].harga_barang<data[j].harga_barang){
							temp=data[i].harga_barang;
							data[i].harga_barang=data[j].harga_barang;
							data[j].harga_barang=temp;
						}
					}
				}
				cout << " Pengurutan Range Harga dari Harga Terendah hingga Harga Tertinggi " << endl;
				cout << "===================================================================" << endl;
				cout << "|                           Harga Barang                          |" << endl;
				for(int i=0;i<n;i++){
					cout << "				"<<data[i].harga_barang;
					cout << endl;
				}
				pilihlagi6 :
			cout << " Tekan K untuk kembali ke Menu Utama : "; cin>>back;
			if(back=='K' || back=='k'){
				goto up;
			}
			else{
				cout << "\n--TAK ADA PILIHAN--"<<endl;
				goto pilihlagi5;}
				break;
			case 7 :
				cout << " 							    Terima Kasih!!" << endl;
				cout << "							Silahkan Kembali lagi" << endl;
			exit(0);
			default :
			cout << "Pilihan tidak ditemukan. " << endl;		
		 }
		 system("pause");
		 return 0;
}
