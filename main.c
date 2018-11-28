/*//Muhammet Metin
//15010011029
#include <stdio.h>
#include <stdlib.h>

typedef struct agac {
    int eleman;
    struct agac *sag,*sol;
}Agaclar;

void Deger_Al(int eklenecek);
void ekle(Agaclar *agackok, Agaclar *yeni);
void inlistele(Agaclar *agackok);
Agaclar *arama(Agaclar *agackok, int aranan);
int enbuyuk(Agaclar *agackok);
int enkucuk(Agaclar *agackok);
Agaclar *silme(Agaclar *agackok, int silinecek);

Agaclar *kok=NULL;

int main()
{
    int eklenecek,aranacak,silinecek,donen_deger;
    char secim;
    printf("eklemek e\nlisteleme l\narama a\nenbuyuk b\nenkucuk k\nsilme s\n");
    while(1==1){
        secim=getchar();
        Agaclar *temp;
        switch (secim){
            case 'e':
                printf("eklencek degeri giriniz");
                scanf("%d",&eklenecek);
                Deger_Al(eklenecek);
                break;
            case 'l':
                if(kok==NULL)
                    printf("AGAC BOS\nBaska bir islem deneyiniz");
                else
                    inlistele(kok);
                break;

            case 'a':
                printf("aranacak degeri giriniz:");
                scanf("%d",&aranacak);
                temp=arama(kok,aranacak);
                if(temp!=NULL)
                    printf("aradiginiz deger %d dir",temp->eleman);
                else
                    printf("aradiginiz eleman mevcut degildir.");
                break;
            case 'b':
                donen_deger=enbuyuk(kok);
                printf("en buyuk eleman %d dir",donen_deger);
                break;
            case 'k':
                donen_deger=enkucuk(kok);
                printf("en kucuk eleman %d dir",donen_deger);
                break;
            case 's':
                if(kok==NULL){
                    printf("AGAC BOS\nBaska bir islem deneyiniz");
                    break;
                }
                printf("silmek istediginiz elemani giriniz:");
                scanf("%d",&silinecek);
                kok=silme(kok,silinecek);
                inlistele(kok);
        }
    }
    return 0;
}

void Deger_Al(int eklenecek){
    Agaclar *yeni;
    yeni = (Agaclar*)malloc(sizeof(Agaclar));
    yeni->eleman=eklenecek;
    yeni->sag=NULL;
    yeni->sol=NULL;

    ekle(kok,yeni);
}

void ekle(Agaclar *agackok, Agaclar *yeni){
    if(agackok==NULL){
        kok=yeni;
    }
    else{
        if(yeni->eleman<agackok->eleman){
            if(agackok->sol==NULL)
                agackok->sol=yeni;
            else
                ekle(agackok->sol,yeni);
        }
        else{
            if(agackok->sag==NULL)
                agackok->sag=yeni;
            else
                ekle(agackok->sag,yeni);
        }
    }
}

void inlistele(Agaclar *agackok){
    if(agackok!=NULL){
        inlistele(agackok->sol);
        printf("%d ",agackok->eleman);
        inlistele(agackok->sag);
    }
}

Agaclar *arama(Agaclar *agackok, int aranan){
    if(agackok==NULL)
        return NULL;
    else{
        if(aranan<agackok->eleman)
            return arama(agackok->sol,aranan);
        else if(aranan>agackok->eleman)
            return arama(agackok->sag,aranan);
        else
            return agackok;
    }
}

int enbuyuk(Agaclar * agackok){
    while(agackok->sag==NULL){
        return agackok->eleman;
    }
    return enbuyuk(agackok->sag);
}


int enkucuk(Agaclar * agackok){
    while(agackok->sol==NULL)
        return agackok->eleman;
    return enkucuk(agackok->sol);
}

Agaclar *silme(Agaclar *agackok, int silinecek){
    int max,min;
    if(agackok==NULL){
        return NULL;
    }
    else if(agackok->eleman==silinecek){
        if(agackok->sol==NULL && agackok->sag==NULL){
            return NULL;
        }
        else if(agackok->sag!=NULL){
            min=enkucuk(agackok->sag);
            agackok->eleman=min;
            agackok->sag=silme(agackok->sag,min);
            return agackok;
        }
        max=enbuyuk(agackok->sol);
        agackok->eleman=max;
        agackok->sol=silme(agackok->sol,max);
        return agackok;
    }
    else if(agackok->eleman<silinecek){
            agackok->sag=silme(agackok->sag,silinecek);
            return agackok;
    }
    else if(agackok->eleman>silinecek){
            agackok->sol=silme(agackok->sol,silinecek);
            return agackok;
    }
}
*/

//Muhammet Metin
//15010011029
#include <stdio.h>
#include <stdlib.h>

typedef struct agac {
    int eleman;
    int yukseklik;
    struct agac *sag,*sol;
}Agaclar;


Agaclar *ekle(Agaclar *agackok, int eklenecek);
void inlistele(Agaclar *agackok);
Agaclar *arama(Agaclar *agackok, int aranan);
int enbuyuk(Agaclar *agackok);
int enkucuk(Agaclar *agackok);
Agaclar *silme(Agaclar *agackok, int silinecek);

Agaclar *kok=NULL;

int main()
{
    int eklenecek,aranacak,silinecek,donen_deger;
    char secim;
    printf("eklemek e\nlisteleme l\narama a\nenbuyuk b\nenkucuk k\nsilme s\n");
    while(1==1){
        secim=getchar();
        Agaclar *temp;
        switch (secim){
            case 'e':
                printf("eklencek degeri giriniz");
                scanf("%d",&eklenecek);
                //Deger_Al(eklenecek);
                ekle(kok,eklenecek);
                break;
            case 'l':
                if(kok==NULL)
                    printf("AGAC BOS\nBaska bir islem deneyiniz");
                else
                    inlistele(kok);
                break;

            case 'a':
                printf("aranacak degeri giriniz:");
                scanf("%d",&aranacak);
                temp=arama(kok,aranacak);
                if(temp!=NULL)
                    printf("aradiginiz deger %d dir",temp->eleman);
                else
                    printf("aradiginiz eleman mevcut degildir.");
                break;
            case 'b':
                donen_deger=enbuyuk(kok);
                printf("en buyuk eleman %d dir",donen_deger);
                break;
            case 'k':
                donen_deger=enkucuk(kok);
                printf("en kucuk eleman %d dir",donen_deger);
                break;
            case 's':
                if(kok==NULL){
                    printf("AGAC BOS\nBaska bir islem deneyiniz");
                    break;
                }
                printf("silmek istediginiz elemani giriniz:");
                scanf("%d",&silinecek);
                kok=silme(kok,silinecek);
                inlistele(kok);
        }
    }
    return 0;
}


Agaclar *ekle(Agaclar *agackok, int eklenecek)
{
    if(agackok==NULL)
    {
        agackok=(Agaclar*)malloc(sizeof(Agaclar));
        agackok->eleman=eklenecek;
        agackok->yukseklik=1;
        agackok->sag=NULL;
        agackok->sol=NULL;
        return agackok;
    }
    else
    {
        if(eklenecek<agackok->eleman)
            agackok->sol=ekle(agackok->sol,eklenecek);
        else
            agackok->sag=ekle(agackok->sag,eklenecek);
        agackok->yukseklik=buyuk(yaprak_yukseklik(agackok->sol),yaprak_yukseklik(agackok->sag))+1;
        if((yaprak_yukseklik(agackok->sol)-yaprak_yukseklik(agackok->sag))>1 && eklenecek<agackok->sol->eleman)
        {//solun solu hatasý
            Agaclar *a=sagaDonus(agackok);

            return a;
        }
        if((yaprak_yukseklik(agackok->sol)-yaprak_yukseklik(agackok->sag))>1 && eklenecek>agackok->sol->eleman)
        {//solun solu hatasý
            Agaclar *b=solsagDonus(agackok);
            return b;
        }
        if((yaprak_yukseklik(agackok->sol)-yaprak_yukseklik(agackok->sag))<-1 && eklenecek<agackok->sag->eleman)
        {//solun solu hatasý
            Agaclar *c=sagsolDonus(agackok);
            return c;
        }
        if((yaprak_yukseklik(agackok->sol)-yaprak_yukseklik(agackok->sag))<-1 && eklenecek>agackok->sag->eleman)
        {//solun solu hatasý
            Agaclar *d=solaDonus(agackok);
            return d;
        }
    }
    return agackok;
}

void inlistele(Agaclar *agackok){
    if(agackok!=NULL){
        inlistele(agackok->sol);
        printf("%d ",agackok->eleman);
        inlistele(agackok->sag);
    }
}

Agaclar *arama(Agaclar *agackok, int aranan){
    if(agackok==NULL)
        return NULL;
    else{
        if(aranan<agackok->eleman)
            return arama(agackok->sol,aranan);
        else if(aranan>agackok->eleman)
            return arama(agackok->sag,aranan);
        else
            return agackok;
    }
}

int enbuyuk(Agaclar * agackok){
    while(agackok->sag==NULL){
        return agackok->eleman;
    }
    return enbuyuk(agackok->sag);
}


int enkucuk(Agaclar * agackok){
    while(agackok->sol==NULL)
        return agackok->eleman;
    return enkucuk(agackok->sol);
}

Agaclar *silme(Agaclar *agackok, int silinecek){
    int max,min;
    if(agackok==NULL){
        return NULL;
    }
    else if(agackok->eleman==silinecek){
        if(agackok->sol==NULL && agackok->sag==NULL){
            return NULL;
        }
        else if(agackok->sag!=NULL){
            min=enkucuk(agackok->sag);
            agackok->eleman=min;
            agackok->sag=silme(agackok->sag,min);
            return agackok;
        }
        max=enbuyuk(agackok->sol);
        agackok->eleman=max;
        agackok->sol=silme(agackok->sol,max);
        return agackok;
    }
    else if(agackok->eleman<silinecek){
            agackok->sag=silme(agackok->sag,silinecek);
            return agackok;
    }
    else if(agackok->eleman>silinecek)
    {
            agackok->sol=silme(agackok->sol,silinecek);
            return agackok;
    }
}


int buyuk(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int yaprak_yukseklik(Agaclar *agackok)
{
        if(agackok==NULL)
        {
            return -1;
        }
        else
            return agackok->yukseklik;
}

Agaclar *solaDonus(Agaclar *agackok)//saðýn saðý hatasý
{
    Agaclar *gecici=agackok->sag;
    agackok->sag=gecici->sol;
    gecici->sol=agackok;
    agackok->yukseklik=buyuk(yaprak_yukseklik(agackok->sol),yaprak_yukseklik(agackok->sag));
    gecici->yukseklik=buyuk(yaprak_yukseklik(gecici->sol),yaprak_yukseklik(gecici->sag));
    return gecici;
}

Agaclar *sagaDonus(Agaclar *agackok)
{
    Agaclar *gecici=agackok->sol;
    agackok->sol=gecici->sag;
    gecici->sag=agackok;
    agackok->yukseklik=buyuk(yaprak_yukseklik(agackok->sol),yaprak_yukseklik(agackok->sag));
    gecici->yukseklik=buyuk(yaprak_yukseklik(gecici->sol),yaprak_yukseklik(gecici->sag));
    return gecici;
}

Agaclar *solsagDonus(Agaclar *agackok)
{
    agackok->sol=solaDonus(agackok->sol);
    return sagaDonus(agackok);
}

Agaclar *sagsolDonus(Agaclar *agackok)
{
    agackok->sag=sagaDonus(agackok->sag);
    return solaDonus(agackok);
}
