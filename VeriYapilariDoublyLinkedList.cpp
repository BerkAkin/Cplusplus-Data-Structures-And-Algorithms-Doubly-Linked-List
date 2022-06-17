//BERK AKIN 191307012
#include <iostream>
#include <locale>
using namespace std;
struct düğüm
{
	int veri;
	düğüm* önceki;
	düğüm* sonraki;
};
düğüm* baş = NULL;
void BasaEkle(int değer)
{
    düğüm* geçici = new düğüm;
    geçici->veri = değer;
    if (baş == NULL)
    {
        baş = geçici;
        baş->sonraki = NULL;
        baş->önceki = NULL;
        cout << "İlk Eleman Oluşturuldu: " << geçici->veri<<endl;
    }
    else
    {
        geçici->sonraki = baş;
        baş->önceki = geçici;
        baş = geçici;
        cout<<"Başa Bir Eleman Eklendi: " << geçici->veri << endl;
    }
}
void BastanSil()
{
    if (baş == NULL)
    {
        cout << "Liste boş";
    }
    else
    {
        if (baş->sonraki == NULL)
        {
            delete baş;
            baş = NULL;
            cout << "Liste Temizlendi";
        }
        else
        {
            düğüm* geçici = baş->sonraki;
            cout << "Listenin Başından Bir Eleman Silindi: " << baş->veri << endl;
            delete baş;
            baş = geçici;
            baş->önceki = NULL;
            
        }
    }
}
void SonaEkle(int değer)
{
    düğüm* geçici = new düğüm;
    geçici->veri = değer;
    if (baş == NULL)
    {
        baş = geçici;
        baş->sonraki = NULL;
        baş->önceki = NULL;
        cout << "İlk Düğüm Oluşturuldu: "<<geçici->veri << endl;
    }
    else
    {
        düğüm* geçici2 = baş;
        while (geçici2->sonraki != NULL)
        {
            geçici2 = geçici2->sonraki;
        }
        geçici2->sonraki = geçici;
        geçici->önceki = geçici2;
        geçici->sonraki = NULL;
        cout << "Sona Bir Eleman Eklendi: " << geçici->veri<< endl;
    }
}
void SondanSil()
{
    if (baş == NULL)
    {
        cout << "Liste boş";
    }
    else
    {
        if (baş->sonraki == NULL)
        {
            delete baş;
            baş = NULL;
            cout << "Liste Temizlendi";
        }
        else
        {
            düğüm* geçici = baş;
            while (geçici->sonraki != NULL)
            {
                geçici = geçici->sonraki;
            }
            düğüm* geçiciA = geçici->önceki;
            cout << "Listenin Sonundan Bir Eleman Silindi: " << geçici->veri << endl;
            delete geçici;
            geçiciA->sonraki = NULL;
           
        }
    }
}
void ArayaEkle(int değer, int sıra)
{
    düğüm* geçici4 = new düğüm();
    geçici4->veri = değer;
    if (baş == NULL)
    {
        baş = geçici4;
        baş->sonraki = NULL;
        baş->önceki = NULL;
        cout << "İlk Eleman Oluşturuldu: " << geçici4->veri<< endl;
    }
    else
    {
        düğüm* geçici = baş;
        while (geçici->sonraki != NULL)
        {       
            if (geçici->veri == sıra)
            {
                düğüm* geçici2 = geçici->önceki;
                düğüm* geçici3 = geçici;
                geçici2->sonraki = geçici4;
                geçici4->önceki = geçici2;
                geçici4->sonraki = geçici;
                geçici->önceki = geçici4;
                cout << "Araya Bir Eleman Eklendi: " << geçici4->veri<< endl;
                break;
            }
            geçici = geçici->sonraki;
        }
    }
}
void AradanSil(int değer)
{
    if (baş == NULL)
    {
        cout << "Liste Boş";
    }
    else
    {
        if (baş->sonraki == NULL && baş->veri == değer)
        {
            delete baş;
            baş = NULL;
            cout << "Liste Temizlendi";
        }
        else
        {
            düğüm* geçici = baş;
            while (geçici->sonraki != NULL)
            {
                if (geçici->veri == değer)
                {
                    düğüm* geçici2 = geçici->önceki;
                    düğüm* geçici3 = geçici->sonraki;
                    cout << "Aradan Bir Eleman Silindi. " << geçici->veri << endl;
                    delete geçici;
                    geçici2->sonraki = geçici3;
                    geçici3->önceki = geçici2;        
                    break;
                }
                geçici = geçici->sonraki;
            }

        }
    }
}
void Yazdır()
{
    if (baş == NULL)
    {
        cout << "Listede Eleman Yok" << endl;
    }
    else
    {
        cout << "Liste: ";
        düğüm* geçici = new düğüm;
        geçici = baş;
        while (geçici->sonraki != NULL)
        {
            cout << geçici->veri << "\t";
            geçici = geçici->sonraki;
        }
        cout << geçici->veri << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    BasaEkle(12);
    BasaEkle(25);
    Yazdır();
    SonaEkle(1);
    SonaEkle(2);
    Yazdır();
    ArayaEkle(44,1);
    ArayaEkle(56, 12);
    Yazdır();
    BastanSil();
    Yazdır();
    SondanSil();
    Yazdır();
    AradanSil(12);
    Yazdır();
    return 41;
}
