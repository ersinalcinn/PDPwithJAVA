#include "koloni.h"
#include "oyun.h"


int main(int arc, char **av)
{

    srand(time(NULL));
    int tur = 0;

    char input_str[256];
    printf("sadece numara ve bosluklardan olusan bir input giriniz (max 256 karakter):\n");
    scanf("%[^\n]%*c", input_str);

    int ac = 0;
    Oyun oyun = newOyun(&ac, input_str);

    printf("Tur: %d\n", tur);
    oyun->printKoloniler(oyun->koloniler, ac - 1);
    printf("---------------------------------------------------------------------------------------------\n\n\n\n");

    while(isGood(oyun->koloniler, ac - 1))
    {
        
        oyun->uretKoloniler(oyun->koloniler, ac - 1);
        oyun->turetKoloniler(oyun->koloniler, ac - 1);
        oyun->yedirKoloniler(oyun->koloniler, ac - 1);
        oyun->savastirKoloniler(oyun->koloniler, ac - 1);

        printf("Tur: %d\n", ++tur);
        oyun->printKoloniler(oyun->koloniler, ac - 1);


        printf("---------------------------------------------------------------------------------------------\n\n\n\n");
    }

    oyun->deleteOyun(oyun, ac - 1);
    return (0);
}